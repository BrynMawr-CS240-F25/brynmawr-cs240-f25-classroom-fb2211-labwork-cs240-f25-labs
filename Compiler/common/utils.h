#ifndef _utils_H_
#define _utils_H_

#include <string.h>
#include <stdio.h>

typedef unsigned char uchar;

extern void check(bool expr, const char* message); 
extern void check(unsigned char v[16], unsigned char u[16], const char* msg);

extern void dec2bin(int val, unsigned char binary[16]);
extern int bin2dec(unsigned char binary[16], bool isSigned = false);

extern void remove_whitespace(char* buffer, int len);
extern void change_extension(const char* filename, const char* newext, 
    char* output, int maxsize);
#endif
