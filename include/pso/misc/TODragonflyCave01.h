#ifndef PSO_MISC_TODRAGONFLYCAVE01_H
#define PSO_MISC_TODRAGONFLYCAVE01_H

#include "types.h"
#include "pso/misc/TODragonfly.h"

struct BmlResource;

// The cave dragonfly (the VR spaceships and battle stage use its ex model).
struct TODragonflyCave01 : public TODragonfly {
    TODragonflyCave01(void *set_data);
    virtual ~TODragonflyCave01();
    static void *create(void *set_data);
    static void release_static_instance();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;
};

typedef char TODragonflyCave01_size[sizeof(TODragonflyCave01) == 0x100 ? 1 : -1];

#endif
