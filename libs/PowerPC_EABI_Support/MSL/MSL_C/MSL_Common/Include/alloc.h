#ifndef _MSL_COMMON_ALLOC_H
#define _MSL_COMMON_ALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

void free(void* ptr);
void __sys_free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif
