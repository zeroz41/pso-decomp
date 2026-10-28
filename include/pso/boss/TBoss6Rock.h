#ifndef PSO_BOSS_TBOSS6ROCK_H
#define PSO_BOSS_TBOSS6ROCK_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"

struct TBoss6Rock : public TObjCollidable {
    virtual ~TBoss6Rock();
    void sub_80353F5C();
    virtual void run_task();
    u32 m_ac;
    u32 m_b0;
    u32 m_b4;
    u32 m_b8;
    u32 m_bc;
    u32 m_c0;
    u32 m_c4;
    u32 m_c8;
    u8 unk_CC[0x4];
    s32 m_d0;
    Vec m_d4;
    s32 m_e0;
    u32 m_e4;
    void set_target(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0);
    static void *create();
    static s32 is_rock_valid(s32 arg0);
    static void reset_rock_state(s32 arg0);
    static void clear_rock_state(s32 i);
    static void set_rock_target(s32 i, s32 a, s32 b);
    void release_object();
    void randomize_motion();
    static u8 *get_rock_entry(s32 arg0);
    void break_and_release();
    void update_fall();
    void init_spin_params();
    void draw_model();
    virtual void render();
    static void *create(void *arg0);
    static u8 is_active();
    static void create_rock_pool(s32 arg0);
    static void free_data();
    static void load_resources();
    void spawn_crush_rocks(s32 kind);
    void break_rocks_in_radius(f32 r);
    s32 push_out_of_rocks(f32 r);
    static s32 get_point(s32 arg0, s32 arg1, f32 *arg2);
};

typedef char TBoss6Rock_size[sizeof(TBoss6Rock) == 0xE8 ? 1 : -1];
#endif
