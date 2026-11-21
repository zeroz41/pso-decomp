#ifndef _STDDEF_H_
#define _STDDEF_H_

#include "types.h"

#define offsetof(type, member) ((size_t) & (((type*)0)->member))

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

typedef long ptrdiff_t;

#endif
