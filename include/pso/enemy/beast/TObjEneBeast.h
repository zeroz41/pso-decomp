#ifndef PSO_ENEMY_BEAST_TOBJENEBEAST_H
#define PSO_ENEMY_BEAST_TOBJENEBEAST_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/RenderFadeState.h"

class TObject;
class TAttackTraceStrip;

struct TObjEneBeast : public TUnk_80493450 {
    TObjEneBeast(TObject *parent, void *set_data);
    virtual ~TObjEneBeast();
    virtual void render();
    void beast_update_appear();
    void run_demo_task();
    void play_group_chase_sound();
    void play_death_sound();
    void play_hurt_sound();
    void play_attack_sound();
    void play_alert_sound();
    void spawn_death_effect();
    void update_attack_trail();
    TAttackTraceStrip *attack_trails[2];  // fed by update_attack_trail from the claw samples
    RenderFadeState camera_fades[4];  // one per camera (render indexes it by camera mode)
    void select_subtype();
    static void *create(void *set_data);
    static void load_resources();
    void select_model_record(s32 i);
};

#include <stddef.h>
LAYOUT_ASSERT(BeastSize, sizeof(TObjEneBeast) == 0x420);
LAYOUT_ASSERT(BeastEmbeddedObjects, offsetof(TObjEneBeast, camera_fades) == 0x3B0);

void free_boss4_rock_pool(void);

#endif
