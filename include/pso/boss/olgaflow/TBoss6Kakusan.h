#ifndef PSO_BOSS_OLGAFLOW_TBOSS6KAKUSAN_H
#define PSO_BOSS_OLGAFLOW_TBOSS6KAKUSAN_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

// Olga Flow's homing spread shot.
struct TBoss6Kakusan : public TObject {
    TBoss6Kakusan(TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 radius);
    virtual ~TBoss6Kakusan();
    s32 damage;               // boss parameter 0x2B, sent to every player the shot touches
    u16 target_client;        // the player it homes on
    u8 pad_22[0x2];
    f32 radius;               // step and reach of the hit test
    f32 homing_weight;        // boss parameter 0x2F: pull towards the target per frame
    s32 frame;
    Vec position;
    Vec velocity;
    Vec prev_position;        // position at the start of the frame
    TParticleCtrl *particle;  // emitter 0x214
    void check_beam_player_hits();
    s32 sub_8032263C();
    s32 is_out_of_range();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss6Kakusan_size, sizeof(TBoss6Kakusan) == 0x58);
#endif
