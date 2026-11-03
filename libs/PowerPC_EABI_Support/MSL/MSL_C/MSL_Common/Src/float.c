#include "MSL_C/MSL_Common/float.h"

/* Only the objects the link kept: __float_max/__float_epsilon, __double_min, __double_epsilon, __double_tiny and
   __double_nan were dead-stripped (their slots are absent between these). */
unsigned long __float_nan[] = {0x7FFFFFFF};
unsigned long __float_huge[] = {0x7F800000};
unsigned long __double_max[] = {0x7FEFFFFF, 0xFFFFFFFF};
unsigned long __double_huge[] = {0x7FF00000, 0x00000000};
unsigned long __extended_min[] = {0x00100000, 0x00000000};
unsigned long __extended_max[] = {0x7FEFFFFF, 0xFFFFFFFF};
