#ifndef PSO_MISC_TOBIWAMUSHI_H
#define PSO_MISC_TOBIWAMUSHI_H

#include "types.h"
#include "pso/misc/TODragonfly.h"

struct BmlResource;

// The jungle's biwa bug. A TODragonfly with its own model.
struct TOBiwaMushi : public TODragonfly {
    TOBiwaMushi(void *set_data);
    virtual ~TOBiwaMushi();
    static void *create(void *set_data);
    static void free_shared_data();
    static void load_resource_instance();

    static const char *class_name;
    static BmlResource *model_resource;
};

typedef char TOBiwaMushi_size[sizeof(TOBiwaMushi) == 0x100 ? 1 : -1];
#endif
