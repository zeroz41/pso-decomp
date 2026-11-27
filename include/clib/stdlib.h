#ifndef _STDLIB_H_
#define _STDLIB_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

int atoi(const char *str);
unsigned long strtoul(const char *str, char **end, int base);
void srand(unsigned int seed);
int rand(void);

#ifdef __cplusplus
}
#endif

#endif
