#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01_H

#include "types.h"

struct ObjectSetData;

struct TOHangceilingCave01
{
    static void destroy_instance();
    static void *create(ObjectSetData *set_data);
};

void load_turiten_singo_resources(void);

#endif
