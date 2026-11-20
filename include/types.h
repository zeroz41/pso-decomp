#ifndef TYPES_H
#define TYPES_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;

/* An integer that holds an address: 32 bits on the console, a pointer's width in a port. */
typedef u32 uaddr;
typedef s32 saddr;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifndef __SIZE_TYPE__
typedef unsigned long size_t;
#else
typedef __SIZE_TYPE__ size_t;
#endif
#endif

#if !defined(__cplusplus) || __cplusplus < 201103L
#ifndef nullptr
#define nullptr NULL
#endif
#ifndef override
#define override
#endif
#endif

#define AT_ADDRESS(addr) : (addr)
#define ATTRIBUTE_ALIGN(num) __attribute__((aligned(num)))
/* An aligned parameter, which the console's compiler gives an aligned home in the frame. A port defines it empty. */
#define ATTRIBUTE_ALIGN_PARAM(num) __attribute__((aligned(num)))
#define DECL_WEAK __declspec(weak)
#define __REGISTER register

/* Checks the console's layout at compile time. A port, whose layouts differ, defines it empty. */
#define LAYOUT_ASSERT(name, cond) typedef char name[(cond) ? 1 : -1]

#endif
