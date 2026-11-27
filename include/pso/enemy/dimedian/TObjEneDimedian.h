#ifndef PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H
#define PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H

#include "types.h"
#include "pso/enemy/TObjEneBeastBase.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/MaterialShadeFade.h"
#include <dolphin/mtx.h>

class TObject;
class TAttackTraceStrip;

struct TObjEneDimedian : public TObjEneBeastBase {
    TObjEneDimedian(TObject *parent, void *set_data);
    virtual ~TObjEneDimedian();
    virtual void render();
    void load_dimedian_param_entry(s32);
    void apply_subtype();
    virtual void beast_update_appear();
    virtual void run_demo_task();
    virtual void play_group_chase_sound();
    virtual void play_death_sound();
    virtual void play_hurt_sound();
    virtual void play_attack_sound();
    virtual void play_alert_sound();
    virtual void spawn_death_effect();
    virtual void update_attack_trail();
    virtual void beast_retire_corpse();
    MaterialShadeFade body_fade;  // raised while appearing, decayed by beast_retire_corpse
    TAttackTraceStrip *attack_trails[2];  // fed by update_attack_trail from the claw samples
    RenderFadeState camera_fades[4];  // one per camera (render indexes it by camera mode)
    static void *create(void *set_data);
    static void load_resources();
    static void free_boss_objects();
};

LAYOUT_ASSERT(TObjEneDimedian_size, sizeof(TObjEneDimedian) == 0x43C);

class TObjBase;

struct SampledMotionPoints;
struct BmlResource;
extern BmlResource *dimedian_resource_ptr;                  // the Dimedian BML (TLobby::load_dimedian_resources)
extern SampledMotionPoints *dimedian_attack_left_trail;  // left attack trail samples
extern SampledMotionPoints *dimedian_attack_right_trail; // right attack trail samples
extern saddr dimedian_resource_handles[];
extern s32 dimedian_last_draw_tick[];

// Copies position into object's TObjBase position.
void set_object_position(TObjBase *object, const Vec *position);

#endif
