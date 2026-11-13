#ifndef PSO_ENEMY_SORCERER_TOBJENERE4BIT_H
#define PSO_ENEMY_SORCERER_TOBJENERE4BIT_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80490470.h"
#include <stddef.h>

struct TObjEneRe4Sorcerer;

struct TObjEneRe4InitParams {
    f32 max_distance;
    f32 min_distance;
    s32 turn_speed;
    u32 unk_c[4];
};

struct TObjEneRe4Bit : public TObjEneDD_ST {
    TObjEneRe4Bit(TObject *parent, TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index);
    virtual ~TObjEneRe4Bit();
    virtual void vfunc_88();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_flag3cc_bit2000();
    void call_vt_90_91();
    void invoke_state_callbacks();
    void set_state_flags();
    void clear_state_flag_0x10();
    void set_hold_flags();
    void set_flag_and_notify();
    void sub_800ED408();
    void set_attack_flag();
    void set_state_flag_and_mode(s32 kind);
    void sub_800ED47C();
    Vec *get_spell_data();
    s32 get_state();
    s32 sub_800ED498();
    void clear_state_flags_when_done();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void apply_defense_stat_status(void *);
    void apply_attack_stat_status(void *);
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void vfunc_28();
    void render();
    void run_task();
    s32 handle_event(s32 arg1);
    void handle_state_message(s32 msg);
    void reset_transform();
    void update_homing_velocity();
    void update_position_flag();
    void copy_pos();
    void init();
    static TObjEneRe4Bit *create(TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index);

    u8 unk_374[0x8];
    f32 m_37c;
    u8 unk_380[0x40];
    Vec *m_3c0;
    s16 m_3c4;
    u8 unk_3C6[0x2];
    s32 m_3c8;
    u32 m_3cc;
    s32 m_3d0;
    s32 m_3d4;
    f32 m_3d8;
    TUnk_80490470 fade;
    Vec m_3f8;
    s32 m_404;
    s32 m_408;
    s32 m_40c;
};

typedef char TObjEneRe4Bit_fade_offset[offsetof(TObjEneRe4Bit, fade) == 0x3DC ? 1 : -1];
typedef char TObjEneRe4Bit_size[sizeof(TObjEneRe4Bit) == 0x410 ? 1 : -1];

extern "C" {
void TObjEneRe4Bit__sub_800ECC14(TObjEneRe4Bit *arg0, s32 arg1);
void TObjEneRe4Bit__sub_800ECD28(TObjEneRe4Bit *arg0, s32 arg1);
void TObjEneRe4Bit__sub_800ECE04(TObjEneRe4Bit *arg0, s32 arg1);
void TObjEneRe4Bit__sub_800ECED0(TObjEneRe4Bit *arg0, s32 arg1);
void TObjEneRe4Bit__sub_800EDAB0(void);
void TObjEneRe4Bit__sub_800EDAB4(void);
}

#endif
