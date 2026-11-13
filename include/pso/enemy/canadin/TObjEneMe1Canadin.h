#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLight.h"
#include "pso/system/NinjaTypes.h"

struct TObjEneMe1CanadinMovement {
    f32 m_0;
    f32 m_4;
    s32 m_8;
    s32 m_C;
    s32 m_10;
    s32 m_14;
    s32 m_18;
};

struct TObjEneMe1CanadinParams {
    f32 m_0;
    f32 m_4;
    f32 m_8;
    u8 unk_C[0xC];
    s32 m_18;
    s32 m_1C;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 m_2C;
};

struct TObjEneMe1Canadin : public TObjEneDD_ST {
    TObjEneMe1Canadin(TObject *parent, void *set_data, s32 kind);
    TObjEneMe1Canadin(TObject *parent, TObjEneMe1Canadin *leader, Vec *pos, s32 id, s32 sub_id);
    virtual ~TObjEneMe1Canadin();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual s32 vfunc_104(f32);
    virtual void vfunc_88();
    virtual u8 *vfunc_101(u8 *);
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_107();
    virtual s32 vfunc_108();
    virtual int vfunc_109();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void vfunc_112(s32);
    virtual void vfunc_113();
    virtual void update_if_ready();
    virtual void render_canadin_model_with_debug_type();
    virtual int vfunc_116();
    virtual void vfunc_117(u32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37C;
    u8 unk_380[0x10];
    TObjChara *m_390;
    Vec m_394;
    Vec m_3A0;
    f32 m_3AC;
    u8 unk_3B0[0x10];
    TObjEneMe1Canadin *m_3C0;
    s32 m_3C4;
    u32 m_3C8;
    TUnk_80494938 fade;
    f32 m_3E8;
    f32 m_3EC;
    f32 m_3F0;
    f32 m_3F4;
    f32 m_3F8;
    s32 m_3FC;
    s32 m_400;
    s32 m_404;
    TObjEneMe1Canadin_EffLight *eff_light;  // created in setup_enemy, queued in the dtor
    s32 m_40C;
    s32 m_410;
    Vec m_414[7];
    TObjEneMe1CanadinParams *m_468;
    s32 m_46C;
    s32 m_470;
    s32 m_474;
    s32 m_478;
    s32 m_47C;
    s32 m_480;
    f32 m_484;
    f32 m_488;
    f32 m_48C;
    Vec m_490;
    TObject *m_49C;
    TObject *unk_4A0;  // queued for destruction in the dtor
    NJS_ARGB m_4A4;
    s32 m_4B4;
    s32 m_4B8;
    s32 m_4BC;
    s32 m_4C0;
    s32 m_4C4;
    u16 m_4C8;
    u8 unk_4CA[0x2];
    void update_by_state(s32 arg1);
    void update_walk_animation(s32 arg1);
    void run_task(s32 arg1);
    void move(s32 arg1);
    void action(s32 arg1);
    void handle_state(s32 arg1);
    void pack_color_rgba();
    void reset_map_core(void *color);
    s32 try_trigger_action();
    void advance_state_4_to_5();
    s32 check_target();
    static void update_move(void* p);
    static void advance_state_5_to_4(void *self);
    static void calc_move_vector(int leader, void *out);
    void noop();
    // Adds a point to an EffLight trail (a TObjEneMe1Canadin_EffLight).
    static void push_history_entry(void *trail, f32 width, void *pos, int color);
    void update_angle();
    void update_hover_height();
    void set_target_speed_z();
    void update_position_with_offset();
    void update_by_field_0x354();
    void copy_pos();
    void run_task();
    void setup_enemy();
    static void *create(void *arg0);
    static void load_resources();
    static void free_resources();
};

typedef char TObjEneMe1Canadin_size[sizeof(TObjEneMe1Canadin) == 0x4CC ? 1 : -1];

extern "C" {
void TObjEneMe1CanadinLeader__sub_8009E258(TObjEneMe1Canadin *self);
void TObjEneMe1CanadinLeader__sub_8009E27C(TObjEneMe1Canadin *self);
s32 TObjEneMe1CanadinLeader__sub_8009E31C(TObjEneMe1Canadin *self, s32 mask);
void TObjEneMe1CanadinLeader__sub_8009E334(TObjEneMe1Canadin *self);
void TObjEneMe1CanadinLeader__sub_8009E350(TObjEneMe1Canadin *self);
int TObjEneMe1CanadinLeader__sub_8009E36C(TObjEneMe1Canadin *self);
void TObjEneMe1CanadinLeader__sub_8009E4AC(TObjEneMe1Canadin *self, s32 sequence);
void TObjEneMe1Canadin__sub_8009BFF8(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009C178(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009C2EC(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009C510(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009C91C(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009CC74(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009D320(TObjEneMe1Canadin *self, s32 arg1);
void TObjEneMe1Canadin__sub_8009DE90(TObjEneMe1Canadin *self, s32 arg1);
s32 TObjEneMe1Canadin__sub_8009E76C(TObjEneMe1Canadin *self);
void TObjEneMe1Canadin__sub_8009E930(TObjEneMe1Canadin *self);
void TObjEneMe1Canadin__sub_8009E948(TObjEneMe1Canadin *self);
void TObjEneMe1Canadin__sub_8009EB14(TObjEneMe1Canadin *self, f32 height);
void TObjEneMe1Canadin__sub_8009EB98(TObjEneMe1Canadin *self, f32 height);
void fn_8009BD00(void);
void fn_8009E1D4(TObjEneMe1Canadin *canadin, Vec *pos);
void fn_8009E2DC(TObjEneMe1Canadin *self);
s32 fn_8009E300(TObjEneMe1Canadin *self);
void fn_8009E378(TObjEneMe1Canadin *self);
}

#endif
