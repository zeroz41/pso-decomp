#ifndef _DOLPHIN_TYPES_H_
#define _DOLPHIN_TYPES_H_

typedef signed   char          s8;
typedef unsigned char          u8;
typedef signed   short int     s16;
typedef unsigned short int     u16;
typedef signed   long          s32;
typedef unsigned long          u32;
typedef signed   long long int s64;
typedef unsigned long long int u64;

typedef float  f32;
typedef double f64;

typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

typedef char *Ptr;
typedef unsigned int uintptr_t;
typedef unsigned int uint;
#if !defined(__cplusplus) && !defined(nullptr)
#define nullptr 0
#endif

typedef int BOOL;

#define FALSE 0
#define TRUE 1

#define AT_ADDRESS(addr) : (addr)

#define ATTRIBUTE_ALIGN(num) __attribute__((aligned(num)))

#define __REGISTER register

#define INT_MIN -2147483648
#define INT_MAX 2147483647

#ifndef NULL
#ifndef __cplusplus
#define NULL ((void*)0)
#else
#define NULL 0
#endif
#endif

#include "libc/stdio.h"
#include "libc/stdarg.h"
#include "libc/string.h"
#include "libc/ctype.h"

#include "libc/math.h"

#endif
