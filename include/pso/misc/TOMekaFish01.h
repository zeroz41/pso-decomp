#ifndef PSO_MISC_TOMEKAFISH01_H
#define PSO_MISC_TOMEKAFISH01_H

#include "types.h"
#include "pso/misc/TODragonfly.h"

struct BmlResource;

// A mechanical fish (second model). A TODragonfly with its own model.
struct TOMekaFish01 : public TODragonfly {
    TOMekaFish01(void *set_data);
    virtual ~TOMekaFish01();
    static void *create(void *set_data);
    static void free_static_data();
    static void load_shared_resource();

    static const char *class_name;
    static BmlResource *model_resource;
};

typedef char TOMekaFish01_size[sizeof(TOMekaFish01) == 0x100 ? 1 : -1];
#endif
