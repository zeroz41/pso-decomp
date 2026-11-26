#ifndef PSO_SYSTEM_TASK_DESTRUCTORCHAIN_H
#define PSO_SYSTEM_TASK_DESTRUCTORCHAIN_H

#include "types.h"

// The record __register_global_object fills in for a global object with a destructor.
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};

#endif
