#ifndef PSO_BOSS_TBOSS8DRAGONLEADERPART_H
#define PSO_BOSS_TBOSS8DRAGONLEADERPART_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

// The 0x40-byte enemy set entry the Gol Dragon parts are made from; copy_set_entry copies it whole.
struct TBoss8DragonLeaderPartSetEntry {
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
LAYOUT_ASSERT(TBoss8DragonLeaderPartSetEntry_size, sizeof(TBoss8DragonLeaderPartSetEntry) == 0x40);

// The first Gol Dragon part made (boss8_dragon_leader_part); the other parts are numbered from its set entry.
class TBoss8DragonLeaderPart : public TObject {
public:
    TBoss8DragonLeaderPart(TObject *object, void *arg1p);
    virtual ~TBoss8DragonLeaderPart();
    virtual void render();
    virtual void run_task();
    s32 spawn_attack_object(Vec *pos, s32 angle, s32 hp, s32 index);
    s32 setup_attack_slot(Vec *pos, s32 angle, s32 index, TBoss8DragonLeaderPartSetEntry *dst);
    u16 get_part_entity_id(s32 index);
    s32 get_part_set_index(s32 index);
    TBoss8DragonLeaderPartSetEntry set_entry;
};
LAYOUT_ASSERT(TBoss8DragonLeaderPart_size, sizeof(TBoss8DragonLeaderPart) == 0x5C);

// The leader's constructor makes boss8_dragon_leader_part; TLobby's floor callbacks clear and release it.
TBoss8DragonLeaderPart *create_boss8_dragon_leader_part(TObject *parent, void *set_data);
void release_boss8_dragon_leader_part(void);
void clear_boss8_dragon_leader_part(void);

#endif
