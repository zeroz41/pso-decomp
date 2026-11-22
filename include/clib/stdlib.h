#ifndef _STDLIB_H_
#define _STDLIB_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

int atoi(const char *str);
void srand(unsigned int seed);
int rand(void);

#ifdef __cplusplus
}
#endif

#endif
