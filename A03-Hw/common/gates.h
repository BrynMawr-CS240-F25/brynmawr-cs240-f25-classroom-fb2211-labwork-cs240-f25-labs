#ifndef _gates_H_
#define _gates_H_

typedef unsigned char uchar;

namespace hack
{
  void Nand(uchar a, uchar* out);

  void Not(uchar a, uchar* out); 
  void Not16(uchar a[16], uchar out[16]) ;

  void And(uchar a, uchar b, uchar* out) ;
  void And16(uchar a[16], uchar b[16], uchar out[16]) ;

  void Or(uchar a, uchar b, uchar* out) ;
  void Or16(uchar a[16], uchar b[16], uchar out[16]) ;
  void Or16way(uchar a[16], uchar* out) ;

  void Xor(uchar a, uchar b, uchar* out) ;
  void Xor16(uchar a[16], uchar b[16], uchar out[16]) ;

  void Ones(uchar* out);
  void Ones16(uchar out[16]);

  void Zero(uchar* out);
  void Zero16(uchar out[16]);

  void Set16(uchar* in, uchar* out);

  void Equals(uchar a, uchar b, uchar* out) ;
  void Equals16(uchar a[16], uchar b[16], uchar* out) ;

  void Dmux(uchar in, uchar s, uchar* a, uchar* b) ;
  void Dmux4way(uchar in, uchar s[2], 
                uchar* a, uchar* b, uchar* c, uchar* d);
  void Dmux8way(uchar in, uchar sel[3], 
                uchar* a, uchar* b, uchar* c, uchar* d, 
                uchar* e, uchar* f, uchar* g, uchar* h) ;

  void Mux(uchar a, uchar b, uchar s, uchar* out) ;
  void Mux8way(uchar a, uchar b, uchar c, uchar d, 
                  uchar e, uchar f, uchar g, uchar h, 
                  uchar sel[3], uchar* out) ;
  void Mux16(uchar a[16], uchar b[16], uchar sel, uchar out[16]);
  void Mux4way16(uchar a[16], uchar b[16], uchar c[16], uchar d[16], 
                  uchar sel[2], uchar out[16]) ;
  void Mux8way16(uchar a[16], uchar b[16], uchar c[16], uchar d[16], 
                  uchar e[16], uchar f[16], uchar g[16], uchar h[16], 
                  uchar sel[3], uchar out[16]) ;

  typedef void (*const_gatefn)(uchar* out);
  typedef void (*unary_gatefn)(uchar a, uchar* out);
  typedef void (*binary_gatefn)(uchar a, uchar b, uchar* out);
  typedef void (*trinary_gatefn)(uchar a, uchar b, uchar c, uchar* out);

  void Truth_table(const char* title, trinary_gatefn fn);
  void Truth_table(const char* title, binary_gatefn fn);
  void Truth_table(const char* title, unary_gatefn fn);
}

#endif