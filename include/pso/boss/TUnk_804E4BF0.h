#ifndef PSO_BOSS_TUNK_804E4BF0_H
#define PSO_BOSS_TUNK_804E4BF0_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

// The 0x40-byte enemy set entry the Gol Dragon parts are made from; copy_set_entry copies it whole.
struct TUnk_804E4BF0SetEntry {
    s16 set_index;  // the parts' set indices count up from the leader's
    s16 kind;
    u8 pad_04[0x2];
    u16 entity_id;  // the parts' entity ids (get_enemy_entity) count up from the leader's
    u8 pad_08[0x8];
    Vec position;
    u8 pad_1C[0x4];
    s32 angle;
    u8 pad_24[0x1C];
};
LAYOUT_ASSERT(TUnk_804E4BF0SetEntry_size, sizeof(TUnk_804E4BF0SetEntry) == 0x40);

// The first Gol Dragon part made (boss8_dragon_leader_part); the other parts are numbered from its set entry.
class TUnk_804E4BF0 : public TObject {
public:
    TUnk_804E4BF0(TObject *object, void *arg1p);
    virtual ~TUnk_804E4BF0();
    virtual void render();
    virtual void run_task();
    s32 spawn_attack_object(Vec *pos, s32 angle, s32 hp, s32 index);
    s32 setup_attack_slot(Vec *pos, s32 angle, s32 index, TUnk_804E4BF0SetEntry *dst);
    u16 get_part_entity_id(s32 index);
    s32 get_part_set_index(s32 index);
    TUnk_804E4BF0SetEntry set_entry;
};
LAYOUT_ASSERT(TUnk_804E4BF0_size, sizeof(TUnk_804E4BF0) == 0x5C);

#endif
