#ifndef _RUNTIME_MWCPLUSLIB_H
#define _RUNTIME_MWCPLUSLIB_H

#include "stddef.h"

#define CTORARG_TYPE int
#define CTORARG_PARTIAL (0)
#define CTORARG_COMPLETE (1)

#define CTORCALL_COMPLETE(ctor, objptr) (((void (*)(void*, CTORARG_TYPE))ctor)(objptr, CTORARG_COMPLETE))

#define DTORARG_TYPE int

#define DTORCALL_COMPLETE(dtor, objptr) (((void (*)(void*, DTORARG_TYPE))dtor)(objptr, -1))
#define DTORCALL_PARTIAL(dtor, objptr) (((void (*)(void*, DTORARG_TYPE))dtor)(objptr, 0))

typedef void* ConstructorDestructor;

#ifdef __cplusplus
extern "C" {
#endif

extern char* __copy(char* to, char* from, size_t size);

extern void __construct_array(void* ptr, ConstructorDestructor ctor, ConstructorDestructor dtor, size_t size, size_t n);
extern void __destroy_arr(void* block, ConstructorDestructor* dtor, size_t size, size_t n);
extern void* __construct_new_array(void* block, ConstructorDestructor ctor, ConstructorDestructor dtor_arg, size_t size,
                                   size_t n);
extern void __destroy_new_array(void* block, ConstructorDestructor dtor);
extern void __destroy_new_array2();
extern void __destroy_new_array3();

#ifdef __cplusplus
}

class __partial_array_destructor {
  private:
    void* p;
    size_t size;
    size_t n;
    ConstructorDestructor dtor;

  public:
    size_t i;

    __partial_array_destructor(void* array, size_t elementsize, size_t nelements, ConstructorDestructor destructor) {
        p = array;
        size = elementsize;
        n = nelements;
        dtor = destructor;
        i = n;
    }

    ~__partial_array_destructor() {
        char* ptr;

        if (i < n && dtor) {
            for (ptr = (char*)p + size * i; i > 0; i--) {
                ptr -= size;
                DTORCALL_COMPLETE(dtor, ptr);
            }
        }
    }
};
#endif

#endif
