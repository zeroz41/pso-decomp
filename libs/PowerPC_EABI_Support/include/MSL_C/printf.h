#ifndef MSL_PRINTF_H
#define MSL_PRINTF_H

#include "stddef.h"
#include "libc/stdarg.h"
#include "MSL_C/ansi_files.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int vprintf(const char*, va_list);
extern int vsprintf(char*, const char*, va_list);
int sprintf(char* s, const char* format, ...);
extern int vsnprintf(char*, size_t, const char*, va_list);
extern int printf(const char*, ...);
int snprintf(char* s, size_t n, const char* format, ...);
int fprintf(FILE* stream, const char* format, ...);
int vswprintf(wchar_t* s, size_t n, const wchar_t* format, va_list arg);

#ifdef __cplusplus
}
#endif

#endif
