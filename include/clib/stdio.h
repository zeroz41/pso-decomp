#ifndef _STDIO_H_
#define _STDIO_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

int sprintf(char *str, const char *format, ...);
int printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
