#include "types.h"
#include "pso/unk/text_8020A6B0.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_80207644.h"
#include "pso/unk/text_8020A768.h"

/* Per-area map set table: area -> terrain variants -> map set entries. */
struct MapSetEntry {
    s32 data;
};

struct MapSetVariant {
    MapSetEntry *entries;
    s32 count;
};

struct MapSetArea {
    MapSetVariant *variants;
    s32 count;
};


extern MapSetArea *TLobby__data_805D6068;

void TLobby__sub_8020A6B0(s32 player) {
    s32 area = get_floor_area(player);
    s32 terrain = get_floor_map_terrain(player);
    MapSetVariant *variants;
    MapSetEntry *entries;

    variants = TLobby__data_805D6068[area].variants;
    if (variants == NULL || TLobby__data_805D6068[area].count - 1 < terrain) {
        return;
    }
    entries = variants[terrain].entries;
    if (entries == NULL || variants[terrain].count - 1 < 0) {
        return;
    }
    load_map_set_data(player, entries[0].data);
}
