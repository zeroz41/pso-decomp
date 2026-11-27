#ifndef PSO_EFFECT_PARTICLE_TPLYFOLLOWPARTICLECTRL_H
#define PSO_EFFECT_PARTICLE_TPLYFOLLOWPARTICLECTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/player/PlayerFollowParticles.h"

struct TPlyFollowParticleCtrl : public TObjCollidable {
    // owner: the actor it follows (its id goes to owner_id, its center is the
    // starting position).
    TPlyFollowParticleCtrl(TObjBase *owner);
    virtual ~TPlyFollowParticleCtrl();
    virtual void run_task();
    virtual Vec *get_center();
    u16 owner_id; // entity id of the actor followed, looked up as a player client id
    u16 pad_AE;
    u16 get_owner_id();

    static const char *class_name;
};

LAYOUT_ASSERT(TPlyFollowParticleCtrl_size, sizeof(TPlyFollowParticleCtrl) == 0xB0);

class TParticleCtrl;

TParticleCtrl *create_attached_oneshot_emitter(void *owner, u16 target_id, s32 id);
void emit_idle_water_splash(PlayerHandParticles *owner, const Vec *position);
TParticleCtrl *emit_player_model_particle(PlayerHandParticles *owner, const Vec *position, s32 id, s32 model);
TParticleCtrl *emit_player_particle(void *owner, const Vec *position, s32 id);
void emit_player_sprite_particle(PlayerHandParticles *owner, const Vec *position, s32 id);
void emit_sand_step_particles(PlayerHandParticles *owner, const Vec *position);
void emit_water_step_particles(PlayerHandParticles *owner, const Vec *position);

#endif
