#ifndef PSO_EFFECT_ITEM_TITEMEFFHEAVEN_H
#define PSO_EFFECT_ITEM_TITEMEFFHEAVEN_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;
class TObjChara;
struct TObjPlayer;

// Heaven Punisher's strike on one locked target: a glow on the target's
// body, then (frame 15) a rising pillar with a sound, the hit at frame 25,
// and the last particles cleared at frame 40.
class TItemEffHeaven : public TObject {
public:
    TItemEffHeaven(TObject *parent, TObjPlayer *attacker, u16 target_id, s32 body_index);
    virtual ~TItemEffHeaven();
    virtual void run_task();

    u16 target_id;
    TObjChara *target;  // looked up again each frame
    s32 body_index;
    s32 frame;
    TParticleCtrl *emitters[3];
    f32 rise_speed;
    TObjPlayer *attacker;
    Vec position;
};

typedef char TItemEffHeavenSize[(sizeof(TItemEffHeaven) == 0x4C) ? 1 : -1];

void spawn_heaven_effect(TObject *parent, TObjPlayer *attacker, u16 target_id, s32 body_index);

#endif
