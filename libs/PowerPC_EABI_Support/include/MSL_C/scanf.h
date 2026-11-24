#ifndef _MSL_COMMON_SCANF_H
#define _MSL_COMMON_SCANF_H

#include "stddef.h"
#include "MSL_C/wchar_io.h"

#ifdef __cplusplus
extern "C" {
#endif

enum __ReadProcActions { __GetAChar, __UngetAChar, __TestForError };

unsigned long __strtoul(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg,
                       int* chars_scanned, int* negative, int* overflow);
unsigned long long __strtoull(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg,
                             int* chars_scanned, int* negative, int* overflow);
long double __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned,
                     int* overflow);

enum __WReadProcActions { __GetAwChar, __UngetAwChar, __TestForwcsError };

typedef struct {
    char* CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
} __OutStrCtrl;

typedef struct {
    char* NextChar;
    int NullCharDetected;
} __InStrCtrl;

typedef struct {
    wchar_t* wCharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
} __wOutStrCtrl;

typedef struct {
    wchar_t* wNextChar;
    int wNullCharDetected;
} __wInStrCtrl;

int __StringRead(void* str, int ch, int behavior);

#ifdef __cplusplus
}
#endif

#endif
