#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaReal;

struct TObjEneMe3ShinowaMirage : public TObjEneMe3Shinowa {
    TObjEneMe3ShinowaMirage(TObject *parent, TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index);
    virtual ~TObjEneMe3ShinowaMirage();
    virtual void apply_sword_hits();
    virtual s32 can_hit_same_target();
    virtual void select_next_attack_state();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void apply_effect_pair();
    virtual void state_fade_out(s32);
    void run_death_reaction();
    void run_hit_reaction();
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void render();
    void clear_mirage();
    void set_flag_0x100();
    void init_mirage();
    void activate_mirage(s32 index);
    void run_task();
    static TObjEneMe3ShinowaMirage *create(TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index);
    static void set_slot_min_clamped_value(s32 slot, f32 speed);
    static void free_shared_resources();
    u16 owner_id;
    NJS_ARGB fade_color;
};

LAYOUT_ASSERT(TObjEneMe3ShinowaMirage_size, sizeof(TObjEneMe3ShinowaMirage) == 0x440);
extern "C" void load_shinowa_mirage_resources();

#endif
