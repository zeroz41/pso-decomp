#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTCAGESHOT_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTCAGESHOT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx.h>

struct TObjEnemy;
struct TObjEnemyCustom;

// A homing shot of Vol Opt: it steers towards a player, and the first actor it
// hits is caught in a cage (TBoss3Volopt::create_cage).
class TParticleCtrl;
class TBoss3VoloptCageShot : public TObjCollidable {
public:
    u8 pad_ac[0x8];
    Vec velocity;
    u8 pad_c0[0xC];
    s32 target_id;
    s32 lifetime;
    TParticleCtrl *trail;
    TParticleCtrl *glow;
    s16 entity_id;

    TBoss3VoloptCageShot(TObjEnemy *owner, Vec *pos, s32 target);
    virtual ~TBoss3VoloptCageShot();
    virtual void run_task();
    virtual void render();

    s32 try_capture_target();
};

LAYOUT_ASSERT(TBoss3VoloptCageShot_size, sizeof(TBoss3VoloptCageShot) == 0xE0);

// Clears the owner's "cage shot in flight" flag (0x100000, set by
// TBoss3VoloptP02 when it fires this shot; its state 3 waits for the clear).
void clear_cage_shot_in_flight(TObjEnemyCustom *boss);

#endif
