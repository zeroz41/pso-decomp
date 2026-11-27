#pragma defer_codegen on

#include "Runtime.PPCEABI.H/NMWException.h"
#include "Runtime.PPCEABI.H/MWCPlusLib.h"

#pragma exceptions on

#define ARRAY_HEADER_SIZE 16

extern "C" void* __construct_new_array(void* block, ConstructorDestructor ctor, ConstructorDestructor dtor, size_t size,
                                   size_t n) {
    char* ptr;

    if ((ptr = (char*)block) != 0L) {
        size_t* p = (size_t*)ptr;

        p[0] = size;
        p[1] = n;
        ptr += ARRAY_HEADER_SIZE;

        if (ctor) {
            __partial_array_destructor pad(ptr, size, n, dtor);
            char* p;

            for (pad.i = 0, p = ptr; pad.i < n; pad.i++, p += size) {
                CTORCALL_COMPLETE(ctor, p);
            }
        }
    }
    return ptr;
}

extern "C" void __construct_array(void* ptr, ConstructorDestructor ctor, ConstructorDestructor dtor, size_t size,
                              size_t n) {
    __partial_array_destructor pad(ptr, size, n, dtor);
    char* p;

    for (pad.i = 0, p = (char*)ptr; pad.i < n; pad.i++, p += size) {
        CTORCALL_COMPLETE(ctor, p);
    }
}

extern "C" void __destroy_arr(void* block, ConstructorDestructor* dtor, size_t size, size_t n) {
    char* p;

    for (p = (char*)block + size * n; n > 0; n--) {
        p -= size;
        DTORCALL_COMPLETE(dtor, p);
    }
}

extern "C" void __destroy_new_array(void* block, ConstructorDestructor dtor) {
    if (block) {
        if (dtor) {
            size_t i, objects, objectsize;
            char* p;

            objectsize = *(size_t*)((char*)block - ARRAY_HEADER_SIZE);
            objects = ((size_t*)((char*)block - ARRAY_HEADER_SIZE))[1];
            p = (char*)block + (objectsize * objects);

            for (i = 0; i < objects; i++) {
                p -= objectsize;
                DTORCALL_COMPLETE(dtor, p);
            }
        }

        ::operator delete[]((char*)block - ARRAY_HEADER_SIZE);
    }
}
