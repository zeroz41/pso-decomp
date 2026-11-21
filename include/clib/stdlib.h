#ifndef _STDLIB_H_
#define _STDLIB_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void srand(unsigned int seed);
int rand(void);

#ifdef __cplusplus
}
#endif

#endif
