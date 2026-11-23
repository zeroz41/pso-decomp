#ifndef PSO_ENEMY_SHARK_TOBJENESHARK_H
#define PSO_ENEMY_SHARK_TOBJENESHARK_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/render/RenderFadeState.h"

class TAttackTraceStrip;

class TObjEneShark : public TUnk_80493450 {
public:
    TObjEneShark(TObject *parent, void *setData);
    virtual ~TObjEneShark();
    static void *create(void *setData);
    static void free_resources();
    virtual void render();
    virtual void beast_update_appear();
    virtual void update_attack_trail();
    virtual void spawn_death_effect();
    virtual void play_alert_sound();
    virtual void play_attack_sound();
    virtual void play_hurt_sound();
    virtual void play_death_sound();
    virtual void run_demo_task();
    void sub_800AC9DC(s32);
    void apply_clamped_mode_param();

    TUnk_80494938 fade;
    TAttackTraceStrip *attack_trails[2];  // fed the sampled attack-motion points by update_attack_trail
    RenderFadeState camera_fades[4];
};

#include <stddef.h>
LAYOUT_ASSERT(Shark_fade_offset, offsetof(TObjEneShark, fade) == 0x3A8);
LAYOUT_ASSERT(Shark_attack_trails_offset, offsetof(TObjEneShark, attack_trails) == 0x3C4);
LAYOUT_ASSERT(Shark_camera_fades_offset, offsetof(TObjEneShark, camera_fades) == 0x3CC);
LAYOUT_ASSERT(SharkFadeStride, sizeof(RenderFadeState) == 0x1C);
LAYOUT_ASSERT(SharkSize, sizeof(TObjEneShark) == 0x43C);

extern "C" {
void TObjPlayer__sub_800ACA0C(void);
}

#endif
