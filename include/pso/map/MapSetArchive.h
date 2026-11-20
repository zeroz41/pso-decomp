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

typedef char MapSetEntrySize[sizeof(MapSetEntry) == 0xC ? 1 : -1];
typedef char MapSetEntryEnemyOffset[offsetof(MapSetEntry, enemy_set_name) == 4 ? 1 : -1];
typedef char MapSetVariantSize[sizeof(MapSetVariant) == 8 ? 1 : -1];
typedef char MapSetAreaSize[sizeof(MapSetArea) == 8 ? 1 : -1];
typedef char MapSetModuleAreasOffset[offsetof(MapSetModule, areas) == 0 ? 1 : -1];

extern "C" MapSetArea *TLobby__data_805D6068;

#endif
