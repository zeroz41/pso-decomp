#ifndef _FP_CONVERT_H_
#define _FP_CONVERT_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Runtime helper the compiler calls for float to unsigned conversions.
u32 __cvt_fp2unsigned(f32 x);

#ifdef __cplusplus
}
#endif

#endif
