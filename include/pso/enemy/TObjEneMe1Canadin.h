#ifndef PSO_ENEMY_TOBJENEME1CANADIN_H
#define PSO_ENEMY_TOBJENEME1CANADIN_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneMe1Canadin : public TObjEneDD_ST {
    virtual ~TObjEneMe1Canadin();
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
    virtual void vfunc_117();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    u8 unk_374[0x30];
    u32 m_3c0;
    u32 m_3c4;
    u32 m_3c8;
    void* m_3cc;

    u8 _padBeforeFade[0x18];
    MaterialOpacityFade fade;

    u32 m_404;
    u8 _pad408[0x4];
    u32 m_40c;
    u8 _pad410[0x5C];
    u32 m_46c;
    u32 m_470;
    u8 _pad474[0x40];
    u32 m_4b4;
    u32 m_4b8;
    u8 _pad4BC[0xC];
    u16 m_4c8;
    void update_by_state(s32 arg1);
    void update_walk_animation(s32 arg1);
    void run_task(s32 arg1);
    void move(s32 arg1);
    void action(s32 arg1);
    void handle_state(s32 arg1);
    void pack_color_rgba();
    void reset_map_core(void * _w1);
    s32 try_trigger_action();
    void advance_state_4_to_5();
    s32 check_target();
    static void update_move(void* p);
    void update_angle();
    void update_hover_height();
    void set_target_speed_z();
    void update_position_with_offset();
    void update_by_field_0x354();
    void copy_pos();
    void run_task();
    void setup_enemy();
    void *init(void *arg1, void *arg2, void *arg3);
    static void *create(void *arg0);
    u8 unk_4AE[0x1E];
};

typedef char TObjEneMe1CanadinFadeOffset[offsetof(TObjEneMe1Canadin, fade) == 0x3CC ? 1 : -1];

typedef char TObjEneMe1Canadin_size[sizeof(TObjEneMe1Canadin) == 0x4CC ? 1 : -1];

extern "C" {
void *TObjEneMe1CanadinLeader__ct(void *arg0, void *a, void *b);
void TObjEneMe1CanadinLeader__sub_8009E258(u8 *arg0);
void TObjEneMe1CanadinLeader__sub_8009E27C(void *p);
u8 TObjEneMe1CanadinLeader__sub_8009E31C(u8 *arg0, s32 arg1);
void TObjEneMe1CanadinLeader__sub_8009E334(u8 *arg0);
void TObjEneMe1CanadinLeader__sub_8009E350(u8 *arg0);
int TObjEneMe1CanadinLeader__sub_8009E36C(void *p);
void TObjEneMe1CanadinLeader__sub_8009E4AC(u8 *arg0, s32 arg1);
void TObjEneMe1CanadinLeader__vt104(void *arg0);
u8 TObjEneMe1CanadinLeader__vt107(void *arg0);
void TObjEneMe1CanadinLeader__vt108(u8 *arg0, s32 arg1);
void TObjEneMe1CanadinLeader__vt111(void *arg0);
u8 *TObjEneMe1Canadin__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s16 arg4, s16 arg5);
void TObjEneMe1Canadin__sub_8009BFF8(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C178(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C2EC(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C510(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C91C(void *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009D320(void *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009DE90(void *argv0, s32 arg1);
s32 TObjEneMe1Canadin__sub_8009E76C(u8 *arg0);
void TObjEneMe1Canadin__sub_8009E930(u8 *arg0);
void TObjEneMe1Canadin__sub_8009E948(u8 *arg0);
void TObjEneMe1Canadin__sub_8009EB14(u8 *arg0, f32 height);
void TObjEneMe1Canadin__sub_8009EB98(u8 *arg0, f32 farg0);
void *__dt__17TObjEneMe1CanadinFv(void *arg0, s16 arg1);
void *__dt__23TObjEneMe1CanadinLeaderFv(void *arg0, s16 arg1);
void advance_state_5_to_4__17TObjEneMe1CanadinFPv(void *arg0);
void calc_move_vector__17TObjEneMe1CanadinFiPv(s32 actor, void *arg1);
void fn_8009BD00(void);
void fn_8009E1D4(u8 *arg0, s32 arg1);
void fn_8009E2DC(u8 *arg0);
s32 fn_8009E300(u8 *arg0);
void fn_8009E378(void *arg0);
void noop__17TObjEneMe1CanadinFv(void);
void run_task__23TObjEneMe1CanadinLeaderFv(u8 *pv);
int select_and_apply_target__17TObjEneMe1CanadinFPv(void *p);
}

#endif
