#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H

#include "types.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaMirage : public TObjEneMe3Shinowa {
    virtual ~TObjEneMe3ShinowaMirage();
    virtual void vfunc_105();
    virtual u8 can_hit_same_target();
    virtual void vfunc_107();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void apply_effect_pair();
    void vfunc_63();
    void vfunc_62();
    u8 _pad3EC[0x10];
    u32 m_3fc;
    u8 _pad400[0x2C];
    u16 m_42c;
    u8 _pad42E[0x2];
    void* m_430;
    static void advance_camera_ctrl_step();
    void state_break_apart(s32 arg1);
    void state_cast_support(s32 arg1);
    void state_chase_target(s32 arg1);
    void update_by_distance();
    void render();
    void clear_mirage();
    void set_flag_0x100();
    int init_mirage();
    void activate_mirage(s32 arg1);
    void run_task();
    void *create(void *arg1, void *arg2);
    static void set_slot_min_clamped_value(s32 arg0, f32 farg0);
    static void free_shared_resources();
    u8 unk_418[0x1C];
    f32 m_434;
    u8 unk_438[0x4];
    f32 m_43c;
    void draw_model();
};

typedef char TObjEneMe3ShinowaMirage_size[sizeof(TObjEneMe3ShinowaMirage) == 0x440 ? 1 : -1];
#endif
