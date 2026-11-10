#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/byteswap.h"

// Saved set-flag row of a floor's object or enemy list.
struct SetFlagRow_8020B47C {
    u16 id;
    s16 flags;
    s16 room;
    s16 wave;
};

// One floor of TLobby__floor_enemy_group_table (owned by text_8020E08C).
struct FloorSetFlags_8020B47C {
    s32 object_count;
    s32 enemy_count;
    u32 object_placement;
    u32 enemy_placement;
    SetFlagRow_8020B47C *object_rows;
    SetFlagRow_8020B47C *enemy_rows;
};

// Entity set-flag block of the 6x6E game-state sync: four big-endian words, the first and third the offsets
// of the per-floor object and enemy flag arrays from the block's start.
struct SyncSetFlagBlock_8020B47C {
    u32 object_flags_offset;
    u32 unk_4;
    u32 enemy_flags_offset;
    u32 unk_c;
};

extern "C" {
extern FloorSetFlags_8020B47C TLobby__floor_enemy_group_table[18];

// Copies the received object and enemy set flags of every floor into the floor tables.
void TLobby__sub_8020B47C(SyncSetFlagBlock_8020B47C *block) {
    s32 j;
    SetFlagRow_8020B47C *row;
    s32 i;
    s16 *src;
    s32 count;

    ((TLobby *)block)->bswap_4_words();
    src = (s16 *)((u8 *)block + block->object_flags_offset);
    for (i = 0; i < 18; i++) {
        if (TLobby__floor_enemy_group_table[i].object_count > 0) {
            count = TLobby__floor_enemy_group_table[i].object_count;
            row = TLobby__floor_enemy_group_table[i].object_rows;
            for (j = 0; j < count; j++) {
                s16 flags = *src;
                bswap_16((u16 *)&flags);
                row->flags = flags;
                src++;
                row++;
            }
        }
    }
    src = (s16 *)((u8 *)block + block->enemy_flags_offset);
    for (j = 0; j < 18; j++) {
        if (TLobby__floor_enemy_group_table[j].enemy_count > 0) {
            row = TLobby__floor_enemy_group_table[j].enemy_rows;
            count = TLobby__floor_enemy_group_table[j].enemy_count;
            for (i = 0; i < count; i++) {
                s16 flags = *src;
                bswap_16((u16 *)&flags);
                row->flags = flags;
                src++;
                row++;
            }
        }
    }
}
}
