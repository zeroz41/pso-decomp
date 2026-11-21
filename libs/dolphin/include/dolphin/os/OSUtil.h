#ifndef OS_UTIL_H
#define OS_UTIL_H

#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define OSRoundUp32B(x) (((uaddr)(x) + 0x1F) & ~(0x1F))
#define OSRoundDown32B(x) (((uaddr)(x)) & ~(0x1F))

#ifdef __cplusplus
};
#endif

#endif
