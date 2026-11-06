#ifndef PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H
#define PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"

struct TObjEneDf2Bringer : public TObjEneDD_ST {
    TObjEneDf2Bringer(TObject *arg1, void *arg2);
    virtual ~TObjEneDf2Bringer();
    virtual s32 vfunc_104(f32);
    virtual void vfunc_88();
    virtual void vfunc_83();
    virtual void vfunc_105();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_effect_pos_above_self();
    void sub_80098DEC();
    void sub_800994F8();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 unk_374[0x30];
    u32 m_3c0;
    void* m_3c4;
    u8 _pad3C8[0x10];
    u32 m_3d8;
    u8 _pad3DC[0x4];
    void* m_3e0;
    u8 _pad3E4[0x6C];
    void* m_450;
    u8 _pad454[0x2C];
    u32 m_480;
    u8 _pad484[0x4];
    u32 m_488;
    u8 _pad48C[0x8];
    u32 m_494;
    u8 _pad498[0x10];
    u32 m_4a8;
    void exec(s32 arg1);
    void handle_state(s32 arg1);
    s32 check_stage_advance();
    void init_enemy();
    static void set_entry_value_clamped(s32 arg0, f32 farg0);
    static void free_resources();
    void *create();
    static void load_resources();
    u8 unk_490[0x38];
};

typedef char TObjEneDf2Bringer_size[sizeof(TObjEneDf2Bringer) == 0x4C8 ? 1 : -1];
#endif
