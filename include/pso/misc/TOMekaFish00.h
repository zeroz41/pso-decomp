#ifndef PSO_MISC_TOMEKAFISH00_H
#define PSO_MISC_TOMEKAFISH00_H

#include "types.h"
#include "pso/misc/TODragonfly.h"

struct BmlResource;

// A mechanical fish. A TODragonfly with its own model.
struct TOMekaFish00 : public TODragonfly {
    TOMekaFish00(void *set_data);
    virtual ~TOMekaFish00();
    static void *create(void *set_data);
    static void release_static_instance();
    static void load_shared_resource();

    static const char *class_name;
    static BmlResource *model_resource;
};

typedef char TOMekaFish00_size[sizeof(TOMekaFish00) == 0x100 ? 1 : -1];
#endif
