#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "computer.h"

#define CANVAS_WIDTH  512
#define CANVAS_HEIGHT 256

void DrawScreen(hack::Computer* computer, XImage* image)
{
  int numColValues = CANVAS_WIDTH / 8; // data is in bytes
  for (int row = 0; row < CANVAS_HEIGHT; row++)
  {
    for (int j = 0; j < numColValues; j++)
    {
      int idx = row * numColValues + j;
      image->data[idx] = 0xF0;
    }
  }
}

void ClearKey(hack::Computer* computer)
{
}

void SetKey(hack::Computer* computer, KeySym key)
{
  // See /usr/include/X11/keysymdef.h
  unsigned int code = key; // key is ASCII for alphanumeric characters
  printf("Key: %lu\n", key);
}

int main(int argc, char* argv[]) 
{
  if (argc != 2)
  {
    printf("usage: %s <hack file> [<ticks_per_frame>]\n", argv[0]);
    return 0;
  }

  unsigned int ticks_per_frame = 100000;

  hack::Computer computer;
  computer.load(argv[1]); 

  if (argc == 3)
  {
    ticks_per_frame = atoi(argv[2]);
  }

  Display *display;
  Window window;
  int screen;
  GC gc;
  XEvent event;
  Atom wm_delete_window;

  display = XOpenDisplay(NULL);
  if (display == NULL) {
      fprintf(stderr, "Cannot open X display\n");
      exit(1);
  }

  screen = DefaultScreen(display);

  // Create the window
  window = XCreateSimpleWindow(
      display,
      RootWindow(display, screen),
      100, 100,                      // position
      CANVAS_WIDTH, CANVAS_HEIGHT,   // size
      1,                             // border width
      BlackPixel(display, screen),   // border color
      WhitePixel(display, screen)    // background color
  );

  // Set window title
  XStoreName(display, window, "Hack Hardware Simulator");

  // Handle window close event
  wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(display, window, &wm_delete_window, 1);

  // Select events we care about
  XSelectInput(display, window, ExposureMask | KeyPressMask );

  // Create a graphics context
  gc = XCreateGC(display, window, 0, NULL);
  XSetBackground(display, gc, WhitePixel(display, screen));
  XSetForeground(display, gc, BlackPixel(display, screen));

  // Create an XImage from our raw bitmap
  unsigned int total_bytes = CANVAS_WIDTH * CANVAS_HEIGHT / 8;
  char* image_data = (char*) malloc(sizeof(char) * total_bytes); 
  memset(image_data, 0x00, total_bytes);

  XImage *image = XCreateImage(display,
                                DefaultVisual(display, screen),
                                1,               // depth = 1 bit per pixel
                                XYBitmap,        // bitmap format
                                0,               // offset
                                image_data,
                                CANVAS_WIDTH, CANVAS_HEIGHT,
                                8,               // bitmap_pad
                                CANVAS_WIDTH / 8);

  // Important for monochrome images:
  image->byte_order = LSBFirst;
  image->bitmap_bit_order = LSBFirst;
  image->bitmap_unit = 8;
  image->bitmap_pad = 8;

  // Map (show) the window
  XMapWindow(display, window);

  int running = 1;
  while (running) 
  {
    // Respond to events
    ClearKey(&computer);
    while (XPending(display)) 
    {
      XNextEvent(display, &event);
      if (event.type == Expose) 
      {
        DrawScreen(&computer, image);
        XPutImage(display, window, gc, image,
                      0, 0, 0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
      } 
      else if (event.type == KeyPress) 
      {
        KeySym key = XLookupKeysym(&event.xkey, 0);
        SetKey(&computer, key);
      } 
      else if (event.type == ClientMessage) 
      {
        running = !((Atom)event.xclient.data.l[0] == wm_delete_window);
      }
    }

    for (int i = 0; i < ticks_per_frame && !computer.finished(); i++)
    {
      computer.tick();
    } 
    DrawScreen(&computer, image);
    XPutImage(display, window, gc, image, 0, 0, 0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
    XFlush(display);
  }

  XDestroyImage(image); // also frees bitmap_data
  XFreeGC(display, gc);
  XDestroyWindow(display, window);
  XCloseDisplay(display);

  return 0;
}

