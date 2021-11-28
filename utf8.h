#ifndef UTF8_H
#define UTF8_H

#define UTF8_MAX 0x10FFFF
#include <string.h>

int unicode2UTF8(unsigned int unicode, unsigned char *UTF8);


#endif
