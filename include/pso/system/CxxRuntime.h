#ifndef PSO_SYSTEM_CXXRUNTIME_H
#define PSO_SYSTEM_CXXRUNTIME_H

#include "types.h"

// CodeWarrior's C++ runtime entry points (Runtime.PPCEABI.H/MWCPlusLib.h and NMWException.h) that the game's
// hand-written static initializers and array allocations call. The runtime's own prototypes take the
// constructor and destructor as void *; here they take the function types the runtime calls them through.

// The runtime calls a constructor with the object, and a destructor with the object and -1 (destroy, do not
// free).
typedef void *(*ObjectConstructor)(void *object);
typedef void (*ObjectDestructor)(void *object, s16 flags);

// The record __register_global_object links into the global destructor chain, which runs at exit.
struct DestructorChain {
    DestructorChain *next;
    ObjectDestructor destructor;
    void *object;
};

extern "C" {
// Links registration into the global destructor chain so destructor runs on object at exit; returns object.
void *__register_global_object(void *object, ObjectDestructor destructor, DestructorChain *registration);
// Constructs n objects of size bytes from block (a global array).
void __construct_array(void *block, ObjectConstructor ctor, ObjectDestructor dtor, size_t size, size_t n);
// Destroys the n objects of a global array, last first.
void __destroy_arr(void *block, ObjectDestructor dtor, size_t size, size_t n);
// new[]: stores the array header in the first 0x10 bytes of block and constructs the n objects after it;
// returns the first object.
void *__construct_new_array(void *block, ObjectConstructor ctor, ObjectDestructor dtor, size_t size, size_t n);
// delete[]: destroys the objects of a __construct_new_array block, last first, and frees the block.
void __destroy_new_array(void *array, ObjectDestructor dtor);
// Copies size bytes from from to to (the copy the compiler emits for array members); returns to.
void *__copy(void *to, void *from, size_t size);
}

#endif
