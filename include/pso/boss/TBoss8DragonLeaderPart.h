#ifndef PSO_BOSS_TBOSS8DRAGONLEADERPART_H
#define PSO_BOSS_TBOSS8DRAGONLEADERPART_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/enemy/EnemyPlacement.h"

// The first Gol Dragon part made (boss8_dragon_leader_part); the other parts are numbered from its set entry.
class TBoss8DragonLeaderPart : public TObject {
public:
    TBoss8DragonLeaderPart(TObject *object, EnemyPlacement *set_data);
    virtual ~TBoss8DragonLeaderPart();
    virtual void render();
    virtual void run_task();
    s32 spawn_attack_object(Vec *pos, s32 angle, s32 hp, s32 index);
    s32 setup_attack_slot(Vec *pos, s32 angle, s32 index, EnemyPlacement *dst);
    u16 get_part_entity_id(s32 index);
    s32 get_part_set_index(s32 index);
    // The placement the Gol Dragon parts are made from: their enemy indices and ids count up
    // from its own.
    EnemyPlacement set_entry;
};
LAYOUT_ASSERT(TBoss8DragonLeaderPart_size, sizeof(TBoss8DragonLeaderPart) == 0x5C);

class TObject;
class TBoss8DragonLeaderPart;
struct EnemyPlacement;

// The leader's constructor makes boss8_dragon_leader_part; TLobby's floor callbacks clear and release it.
TBoss8DragonLeaderPart *create_boss8_dragon_leader_part(TObject *parent, EnemyPlacement *set_data);
void release_boss8_dragon_leader_part(void);
void clear_boss8_dragon_leader_part(void);

#endif
