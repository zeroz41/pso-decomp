#ifndef PSO_EFFECT_ENEMY_TOBJENEHOLDEFFECT_H
#define PSO_EFFECT_ENEMY_TOBJENEHOLDEFFECT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

// A particle effect held on a player for a number of frames (one of three
// kinds), kept in front of the player as seen from the camera.
class TObjEneHoldEffect : public TObjBase {
public:
    TObjEneHoldEffect(TObjBase *target, s32 type, s32 frames);
    virtual ~TObjEneHoldEffect();
    virtual void run_task();
    virtual void render();
    static void create(void *target, s32 type, s32 frames);

    static const char *class_name;

    TParticleCtrl *particle;
    u16 target_id;   // get_entity_id of the target; looked up with get_player_by_client_id
    u8 pad_96[0x2];
    s32 effect;      // the particle effect: 0x12F, 0x20F or 0x223 for types 1 to 3
    s32 frames_left;
};

LAYOUT_ASSERT(TObjEneHoldEffect_size, sizeof(TObjEneHoldEffect) == 0xA0);
#endif
