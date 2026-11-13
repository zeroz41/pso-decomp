#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H

#include "types.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaReal;

struct TObjEneMe3ShinowaMirage : public TObjEneMe3Shinowa {
    TObjEneMe3ShinowaMirage(TObject *parent, TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index);
    virtual ~TObjEneMe3ShinowaMirage();
    virtual void vfunc_105();
    virtual s32 can_hit_same_target();
    virtual void vfunc_107();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void apply_effect_pair();
    virtual void vfunc_115(s32);
    void vfunc_63();
    void vfunc_62();
    static void advance_camera_ctrl_step();
    void state_break_apart(s32 arg1);
    void state_cast_support(s32 arg1);
    void state_chase_target(s32 arg1);
    void update_by_distance();
    void render();
    void clear_mirage();
    void set_flag_0x100();
    void init_mirage();
    void activate_mirage(s32 arg1);
    void run_task();
    TObjEneMe3ShinowaMirage *create(void *arg1, void *arg2);
    static void set_slot_min_clamped_value(s32 arg0, f32 farg0);
    static void free_shared_resources();
    u16 m_42c;
    NJS_ARGB m_430;
};

typedef char TObjEneMe3ShinowaMirage_size[sizeof(TObjEneMe3ShinowaMirage) == 0x440 ? 1 : -1];
#endif
