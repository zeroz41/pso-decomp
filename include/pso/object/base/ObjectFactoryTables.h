#ifndef PSO_OBJECT_BASE_OBJECTFACTORYTABLES_H
#define PSO_OBJECT_BASE_OBJECTFACTORYTABLES_H
#include "types.h"

typedef void* (*ObjectFactoryFunction)(void* placement);
struct ObjectFactoryEntry {
    s16 type;
    ObjectFactoryFunction create;
    f32 creation_distance_squared;
    s32 extra_object_ids;
};

extern "C" {
extern ObjectFactoryEntry* floor_object_factory_tables[36];
}
#endif
