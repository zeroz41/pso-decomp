#ifndef _STDIO_H_
#define _STDIO_H_

#include "types.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int sprintf(char *str, const char *format, ...);
int printf(const char *format, ...);
int vsprintf(char *str, const char *format, va_list arg);
int sscanf(const char *str, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
