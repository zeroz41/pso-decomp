#ifndef _MSL_COMMON_MBSTRING_H
#define _MSL_COMMON_MBSTRING_H

#include "MSL_C/wchar_io.h"

#ifdef __cplusplus
extern "C" {
#endif

int mbtowc(wchar_t* pwc, const char* s, size_t n);
size_t wcstombs(char* dst, const wchar_t* src, size_t n);

#ifdef __cplusplus
}
#endif

#endif
