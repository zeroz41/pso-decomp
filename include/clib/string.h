#ifndef _STRING_H_
#define _STRING_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *dst, int val, size_t n);
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t num);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strncat(char *dest, const char *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

#ifdef __cplusplus
}
#endif

#endif
