#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "computer.h"
#include "utils.h"

void getcommand(char* buffer, int maxsize)
{
  // NOTE: \033[32m and \033[0m are special terminal sequences
  // for setting the color of the prompt to green
  char* line = readline("\033[32mhdb> \033[0m");
  strncpy(buffer, line, maxsize);
  add_history(line);
  free(line);
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    printf("usage: %s <hack_program_file>\n", argv[0]);
    exit(0);
  }
  
  const char* filename = argv[1];
  hack::Computer computer;
  computer.load(filename);

  char line[1024];
  while (1)
  {
    getcommand(line, 1024);
    if (strncmp(line, "exit", 4) == 0) 
    {
      break;
    }
    else
    {
      printf("Unknown command: %s\n", line);
    }
  }
  return 0;
}
