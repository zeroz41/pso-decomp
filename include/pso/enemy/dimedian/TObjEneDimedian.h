#ifndef PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H
#define PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"

class TObject;

struct TObjEneDimedian : public TUnk_80493450 {
    TObjEneDimedian(TObject *parent, void *set_data);
    virtual ~TObjEneDimedian();
    virtual void render();
    void load_dimedian_param_entry(s32);
    void sub_800A7B54();
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
    TUnk_80490470 m_3a8;
    TObject *m_3c4[2];
    RenderFadeState m_3cc[4];
    static void *create(void *arg0);
    static void free_boss_objects();
};

LAYOUT_ASSERT(TObjEneDimedian_size, sizeof(TObjEneDimedian) == 0x43C);


#endif
