#ifndef PSO_NPC_TOBJNPCBASE_H
#define PSO_NPC_TOBJNPCBASE_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjNpcBase : public TObjEnemy {
    virtual ~TObjNpcBase();
    virtual void run_task();
    virtual void render();
    virtual void interact(s32 client);
    virtual void vfunc_83();
    virtual void update_standing();
    virtual void update_wandering();
    virtual void update_conversation();
    virtual void apply_set_params(s32, s32);
    virtual void request_action(s32 action);
    virtual void debug_draw_talk();
    virtual void play_voice();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void draw_debug_info();
    void sub_80149360(s32);
    void sub_80149358(s32);
    virtual void vfunc_59();
    virtual void vfunc_58();
    virtual s32 is_target_in_attack_range();
    virtual void vfunc_28();
    u8 unk_374[0x10];
    s32 m_384;
    u32 m_388;
    u32 m_38c;
    u32 m_390;
    u32 m_394;
    f32 m_398;
    f32 m_39c;
    u32 m_3a0;
    u32 m_3a4;
    u32 m_3a8;
    u32 m_3ac;
    u32 m_3b0;
    u32 m_3b4;
    static void free_static();
    void setup_common();
};

typedef char NpcBaseSize[(sizeof(TObjNpcBase) == 0x3B8) ? 1 : -1];

#endif
