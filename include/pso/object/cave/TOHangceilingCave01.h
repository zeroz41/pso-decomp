#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01_H

#include "types.h"

struct TOHangceilingCave01
{
    static void destroy_instance();
};

extern "C" {
void *TOHangceilingCave01__create(void *set_data);
}
void load_turiten_singo_resources(void);

#endif
