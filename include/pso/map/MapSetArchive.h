#ifndef PSO_MAP_MAPSETARCHIVE_H
#define PSO_MAP_MAPSETARCHIVE_H

#include "types.h"
#include <stddef.h>

// SetDataTable REL data: one area table, terrain variants, then map set names.
struct MapSetEntry {
    const char *object_set_name;
    const char *enemy_set_name;
    const char *decoration_set_name;
};
struct MapSetVariant {
    MapSetEntry *entries;
    s32 count;
};
struct MapSetArea {
    MapSetVariant *variants;
    s32 count;
};
struct MapSetModule {
    MapSetArea *areas;
};

LAYOUT_ASSERT(MapSetEntrySize, sizeof(MapSetEntry) == 0xC);
LAYOUT_ASSERT(MapSetEntryEnemyOffset, offsetof(MapSetEntry, enemy_set_name) == 4);
LAYOUT_ASSERT(MapSetVariantSize, sizeof(MapSetVariant) == 8);
LAYOUT_ASSERT(MapSetAreaSize, sizeof(MapSetArea) == 8);
LAYOUT_ASSERT(MapSetModuleAreasOffset, offsetof(MapSetModule, areas) == 0);

// Area table of the SetDataTable module in use.
extern MapSetArea *map_set_areas;

#endif
