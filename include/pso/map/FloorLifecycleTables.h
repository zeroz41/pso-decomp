#ifndef PSO_MAP_FLOOR_LIFECYCLE_TABLES_H
#define PSO_MAP_FLOOR_LIFECYCLE_TABLES_H
#include "types.h"

typedef void (*FloorLifecycleCallback)();
struct FloorLifecycleEntry {
    FloorLifecycleCallback initialize;
    FloorLifecycleCallback cleanup;
};

extern FloorLifecycleEntry* floor_lifecycle_callback_tables[36];
#endif
