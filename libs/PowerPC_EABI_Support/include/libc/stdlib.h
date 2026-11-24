#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stddef.h>
#include <wchar.h>

#define RAND_MAX 32767

void srand(unsigned int seed);
int rand(void);
void abort(void);
void exit(int status);
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);

#define abs(x) __abs(x)

#endif
