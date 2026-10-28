#ifndef PSO_BOSS_TUNK_80484A94_H
#define PSO_BOSS_TUNK_80484A94_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include <dolphin/mtx.h>

struct TObjEnemy;
struct TObjEnemyCustom;

// A homing shot of Vol Opt: it steers towards a player, and the first actor it
// hits is caught in a cage (TBoss3Volopt::create_cage).
class TUnk_80484A94 : public TObjCollidable {
public:
    u8 pad_ac[0x8];
    Vec velocity;
    u8 pad_c0[0xC];
    s32 target_id;
    s32 lifetime;
    void *trail;
    void *glow;
    s16 entity_id;

    TUnk_80484A94(TObjEnemy *owner, Vec *pos, s32 target);
    virtual ~TUnk_80484A94();
    virtual void run_task();
    virtual void render();

    s32 try_capture_target();
};

typedef char TUnk_80484A94_size[sizeof(TUnk_80484A94) == 0xE0 ? 1 : -1];

extern "C" {
f32 fn_800499FC(s32 index);
void fn_80049A0C(TObjEnemyCustom *boss);
}

#endif
