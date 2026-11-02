#ifndef PSO_ENEMY_TOBJENERE7BERURAPUNCH_H
#define PSO_ENEMY_TOBJENERE7BERURAPUNCH_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

struct TObjEneRe7BeruraPunch : public TUnk_804928CC {
    virtual ~TObjEneRe7BeruraPunch();
    virtual void apply_hit_if_active(void *, f32 *);
    s32 sub_80096150();
    void update_flight();
    u16 m_b0;
    u8 _padB2[0x2];
    u32 m_b4;
    u32 m_b8;
    u8 unk_BC[0x4];
    f32 m_c0;
    u8 unk_C4[0x4];
    f32 m_c8;
    u8 unk_CC[0x4];
    u32 m_d0;
    u32 m_d4;
    u8 _padD8[0x4];
    void* m_dc;
    u8 unk_E0[0x4];
    f32 m_e4;
    void* m_e8;
    u8 unk_EC[0x8];
    f32 m_f4;
    void* m_f8;
    u8 _padFC[0x10];
    u32 m_10c;
    void snap_to_ground();
    void reset();
    virtual void run_task();
    void init();
    int is_patrol_active();
    virtual void render();
    void update_velocity_and_snap();
    void launch(s32 arg1, s32 arg2);
    u8 unk_110[0x4];
    f32 m_114;
    u8 unk_118[0x4];
};

typedef char TObjEneRe7BeruraPunch_size[sizeof(TObjEneRe7BeruraPunch) == 0x11C ? 1 : -1];
#endif
