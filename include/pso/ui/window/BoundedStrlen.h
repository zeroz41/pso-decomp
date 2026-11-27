#ifndef PSO_UI_WINDOW_BOUNDEDSTRLEN_H
#define PSO_UI_WINDOW_BOUNDEDSTRLEN_H

#include "types.h"

// The length of str, at most max; 0 for a null string.
s32 bounded_strlen(const char *str, u32 max);

#endif
