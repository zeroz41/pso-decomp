#include "types.h"

// sqrt_double's constants (render_util.cpp), which the original keeps apart from that unit's other data.

__declspec(section ".rodata") extern const f64 sqrt_double_zero[1] = {0.0};

__declspec(section ".rodata") extern const f64 sqrt_double_half[1] = {0.5};

__declspec(section ".rodata") extern const f64 sqrt_double_three[1] = {3.0};
