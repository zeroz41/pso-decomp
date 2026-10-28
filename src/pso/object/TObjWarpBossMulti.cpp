#include "types.h"
#include "pso/object/TObjWarpBase.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjAreaWarp.h"
#include "pso/object/TObjMotion.h"
#include "pso/TObject.h"
#include <stddef.h>
#include "pso/object/TObjFish.h"
#include "pso/object/TObjWarpBoss.h"
#include "pso/object/TObjWarpBossMulti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/TAdChrSelASlotGC.h"

struct VWarp_8019DD34 { char pad[0x18]; };
struct TObjWarpBossMulti_8019DD34 : VWarp_8019DD34 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};
#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
struct P_A_8019DD34 { char pad[0x18]; };
struct P_V_8019DD34 : P_A_8019DD34 {
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual void CAT(pv, __LINE__)();
    virtual s32 m31();
};
#undef CAT
#undef CAT2

struct RecoveredGlobal_8019E418_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Wb_8019DE74 { u8 pad0[0xF4]; s32 fF4; };

struct Tbl_8019DFE8 { u8 pad[4]; u32 count; };
struct Obj_8019DFE8 {
    u8 pad0[0x38];
    u8 f38[0xAC - 0x38];
    f32 fAC;
    u8 padB0[0xC4 - 0xB0];
    s32 fC4[4];
    u8 padD4[0xE0 - 0xD4];
    Tbl_8019DFE8 *fE0;
    Tbl_8019DFE8 *fE4;
    u8 padE8[0xF0 - 0xE8];
    s32 fF0;
    s32 fF4;
    f32 fF8;
    f32 fFC;
};

struct Obj_8019E238 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x38 - 0x1C];
    u8 f38[0xA4 - 0x38];
    s32 fA4;
    u8 padA8[0xAC - 0xA8];
    f32 fAC;
    u8 padB0[0xBC - 0xB0];
    s32 fBC;
    void *fC0;
    s32 fC4[4];
};

struct Pl_8019E4E8 { u8 pad0[0x38]; f32 pos[3]; };
struct Wb_8019E4E8 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x68]; f32 fAC; };
struct Pkt_8019E6C0 { u8 cmd; u8 size; u16 id; u16 value; u16 pad; };

struct Obj_8019E6C0 { u8 pad[0x1c]; u16 id; };

struct Warp_8019EE14 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    f32 radius;
    u8 padb0[0xBC - 0xB0];
    s32 fbc;
    u8 padc0[0xE4 - 0xC0];
    char names[4][0x18];
    s32 inside[4];
    s32 count;
    s32 n_inside;
    s32 f15c;
    u8 pad160[4];
    u32 window;
    u8 pad168[0x180 - 0x168];
    s32 warping;
};

struct Player_8019EE14 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x85C - 0x44];
    char name[0x18];
};

struct Wb_8019F2C0 { u8 pad0[0x88]; s32 f88; u8 pad8C[0xE0]; s32 f16C; };

struct Warp_8019EFF0
{
  u8 pad0[0xDE];
  s16 mode;
  u8 pade0[0xE4 - 0xE0];
  char names[4][0x18];
  s32 inside[4];
  s32 count;
  s32 n_inside;
  s32 f15c;
  u8 pad160[4];
  void *list;
  void *dialog;
};

struct Pos_8019EFF0
{
  f32 x;
  f32 y;
};

struct Wb_8019E4E8;
struct Obj_8019E6C0;

struct Obj_8019F578 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x88 - 0x1C];
    s32 f88;
    u8 pad8C[0xA4 - 0x8C];
    s32 fA4;
    u8 padA8[0xAC - 0xA8];
    f32 fAC;
    u8 padB0[0xB4 - 0xB0];
    void *fB4;
    u8 padB8[0xBC - 0xB8];
    s32 fBC;
    u8 padC0[0xC4 - 0xC0];
    f32 fC4;
    u8 padC8[0xD0 - 0xC8];
    s32 fD0;
    s32 fD4;
    u8 padD8[0xDC - 0xD8];
    s16 fDC;
    s16 fDE;
    s16 fE0;
    s16 fE2;
    u8 padE4[0x144 - 0xE4];
    s32 f144[4];
    u8 pad154[0x164 - 0x154];
    s32 f164;
    s32 f168;
    s32 f16C;
    u8 pad170[0x180 - 0x170];
    s32 f180;
};

extern "C" {
s32 check_player_flag1__6TLobbyFv(void);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
void *get_player_by_client_id(s32 i);
s32 fn_80248994(void *, u32, int);
void *refresh_with_default_list__20TWindowSubStatusDispFll(s32, void *);
void request_active_window_close(void);
void begin_player_keyboard_hold(s32 arg0);
s32 get_window_layout_position(s32);
s32 free_member__17TWindowSubComCardFv(void *, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(void *, s32, s32, f32);
extern s32 local_client_id;
extern const f32 lbl_805DC020;
extern const f32 lbl_805DC024;
extern const f32 lbl_805DC028;
s32 get_main_phase();
s32 is_local_client_floor_leader();
s32 TObjWarpBossMulti__sub_8019E570(s32 arg0, f32 farg0);
void close_windows__12TObjWarpBossFv(void *arg0);
s32 TWindow__close(void *);
extern s32 boss_warp_confirmation_model;
extern s32 warp_boss_motion;
extern s32 __vt__12TObjWarpBoss[];
extern "C" {
extern u8 lbl_80446480[];
void queue_destruction__7TObjectFv(void *);
u16 register_entity_by_id(void *ov);
void *TObjAreaWarp__ct(void *arg0);
s32 get_boss_warp_destination(void);
extern s32 TObjWarpBoss__name;
extern const f32 lbl_805DC000;
extern const f32 lbl_805DC018;
extern "C" {
void *__nw__7TObjectFUl(int);
extern void *tl_05;
Obj_8019F578 *TObjWarpBoss__ct(Obj_8019F578 *self, int _w1, void * _w2);
extern "C" {
extern u32 boss_warp_resource_bundle;
extern "C" {
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 load_resource_from_descriptor(s32, void *, s32, s32, s32);
void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
extern s32 boss_warp_base_model;
extern s32 warp_boss_model;
extern s32 warp_boss_bml_motion;
extern s32 warp_boss_model_handle;
extern s32 lbl_805D5CA4;
extern "C" {
extern "C" {
extern "C" {
extern "C" {
extern "C" {
extern "C" {
extern "C" {
extern "C" u8 lbl_80446480[];
extern "C" u8 lbl_80446494[];
extern "C" u8 lbl_804464AC[];
extern "C" u8 lbl_804464C8[];
extern "C" u8 lbl_804464E4[];
extern "C" u8 lbl_80446500[];
extern "C" u8 lbl_80446514[];
extern "C" u8 lbl_8044652C[];
extern "C" u8 lbl_80446544[];
extern "C" u8 lbl_8044655C[];
extern "C" u8 lbl_80446574[];
extern "C" u8 lbl_80446590[];
extern "C" u8 lbl_804465AC[];
extern "C" u8 lbl_804465C4[];
extern "C" u8 lbl_804465E0[];
extern "C" u8 lbl_804465FC[];
extern void *boss_warp_model_names[4];
extern void *boss_warp_motion_names[3];
extern void *lbl_804B94BC[4];
extern void *ancient_boss_warp_resource_block[3];
extern void *lbl_804B94E8[3];
extern __declspec(section ".data") void *jungle_boss_warp_resource_block[2];
int get_boss_warp_base_model(void);
}
extern "C" {
extern u8 lbl_80446494[];
}
extern "C" {
extern u8 lbl_804464AC[];
}
extern "C" {
extern u8 lbl_804464C8[];
}
extern "C" {
extern u8 lbl_804464E4[];
}
extern "C" {
extern u8 lbl_80446500[];
}
extern "C" {
extern u8 lbl_80446514[];
}
extern "C" {
extern u8 lbl_8044652C[];
}
extern "C" {
extern u8 lbl_80446544[];
}
extern "C" {
extern u8 lbl_8044655C[];
}
extern "C" {
extern u8 lbl_80446574[];
}
extern "C" {
extern u8 lbl_80446590[];
}
extern "C" {
extern u8 lbl_804465AC[];
}
extern "C" {
extern u8 lbl_804465C4[];
}
extern "C" {
extern u8 lbl_804465E0[];
}
extern "C" {
extern u8 lbl_804465FC[];
}
int get_boss_warp_confirmation_model(void);
}
int get_boss_warp_model(void);
}
int get_boss_warp_motion(void);
}
int get_boss_warp_bml_motion(void);
}
int get_boss_warp_model_handle(void);
}
int fn_8019F9AC(void);
}
}
void TLobby__sub_8001FE7C(void*, int);
void TObjFish__sub_8019F72C(void);
}
s32 TObjWarpBossMulti__create(s32 arg0);
}
}
void __dl__7TObjectFPv(void *);
u8 *__dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);
void *__dt__12TObjWarpBossFv(void *arg0, s16 arg1);
struct Base2_8019f358_8019F22C { char pad[0x18]; };
struct VObj2_8019f358_8019F22C : Base2_8019f358_8019F22C { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

extern u8 lbl_8044663C[];
extern u8 lbl_80446650[];
extern RecoveredGlobal_8019E418_lbl_8050E208 controller_input_state;
extern u32 player_slot_table[];
extern s32 TObjWarpBossMulti__name;
extern s32 camera_ctrl_instance;
extern s32 lbl_805D55C0;
extern s32 __vt__17TObjWarpBossMulti[];
extern const f32 lbl_805DC004;
extern const f32 lbl_805DC008;
extern const f32 lbl_805DC00C;
extern const f32 lbl_805DC010;
extern const f32 lbl_805DC014;
extern const f32 lbl_805DC01C;
extern const f32 lbl_805DC02C;

void debug_printf_at(int, void *, ...);
void *init__13TAdVIConfigGCFf(void *, void *, f32);
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
void allow_rendering__7TObjectFv(TObject *arg0);
int check_flag_100__10TObjPlayerFPv(void *p);
void disallow_rendering__7TObjectFv(TObject *arg0);
f32 xz_distance_squared(s32, void *);
s32 get_current_floor();
u8 is_current_floor_switch_set(int);
void *find_entity_by_id(u16);
void end_player_keyboard_hold(s32 arg0);
s32 bswap_6x6A_packet__19TWindowSubTradeMainFv();
s32 align_menu_entry_positions(u32);
u32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
void obj_clear_flag30_20000(void *arg0);
void obj_set_flag_20000(void *arg0);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 send_code_45_1__10TObjPlayerFl();
s32 play_sound_effect(s32, void *, s32, s32);
char *strcpy(char *, const char *);
s32 is_locally_controlled__10TObjPlayerFPv(u32);

void debug_print_area_num__17TObjWarpBossMultiFv(Wb_8019DE74 *arg0);
void render__17TObjWarpBossMultiFv(u8 *arg0);
void run_task__17TObjWarpBossMultiFv(Obj_8019DFE8 *self);
void *__dt__17TObjWarpBossMultiFv(void *arg0, s16 arg1);
Obj_8019E238 *TObjWarpBossMulti__ct(Obj_8019E238 *self, void * _w1, void * _w2);
void update_warp_boss_visibility__12TObjWarpBossFv(void *arg0);
void render_shadows__7TObjectFv();
void vfunc_6__13TUnk_804B9870FPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804AF8A0Fv();
void vfunc_9__13TUnk_804B9870Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void get_name__13TUnk_804B9870Fv();
void interact__13TUnk_804AF8A0Fl();
void vfunc_14__12TObjWarpBaseFv();
void open_confirm_window__12TObjAreaWarpFUs();
void vfunc_17__12TObjWarpBaseFv();
void vfunc_18__12TObjWarpBaseFl(s32 arg0, s32 arg1);
void confirm_area_transfer__12TObjAreaWarpFPvi(u8 *arg0, s32 arg1);
void *boss_warp_model_names[4] = {
    (void *)&lbl_80446480, (void *)&lbl_80446494, (void *)&lbl_804464AC, (void *)0x0,
};

void *boss_warp_motion_names[3] = {
    (void *)&lbl_804464C8, (void *)&lbl_804464E4, (void *)0x0,
};

void *lbl_804B94AC[4] = {
    (void *)&lbl_80446500, (void *)&boss_warp_model_names, (void *)&boss_warp_motion_names, (void *)0x30002,
};

void *lbl_804B94BC[4] = {
    (void *)&lbl_80446514, (void *)&lbl_8044652C, (void *)&lbl_80446544, (void *)0x0,
};

void *ancient_boss_warp_resource_block[3] = {
    (void *)&lbl_8044655C, (void *)&lbl_80446574, (void *)0x0,
};

void *lbl_804B94D8[4] = {
    (void *)&lbl_80446590, (void *)&lbl_804B94BC, (void *)&ancient_boss_warp_resource_block, (void *)0x30002,
};

void *lbl_804B94E8[3] = {
    (void *)&lbl_804465AC, (void *)&lbl_804465C4, (void *)0x0,
};

__declspec(section ".data") void *jungle_boss_warp_resource_block[2] = {
    (void *)&lbl_804465E0, (void *)0x0,
};

void *lbl_804B94FC[4] = {
    (void *)&lbl_804465FC, (void *)&lbl_804B94E8, (void *)&jungle_boss_warp_resource_block, (void *)0x20001,
};

s32 __vt__17TObjWarpBossMulti[21] = {
    0,
    0,
    (s32)&__dt__17TObjWarpBossMultiFv,
    (s32)&run_task__17TObjWarpBossMultiFv,
    (s32)&render__17TObjWarpBossMultiFv,
    (s32)&render_shadows__7TObjectFv,
    (s32)&vfunc_6__13TUnk_804B9870FPsl,
    (s32)&apply_object_set_data__13TUnk_804B9870FPv,
    (s32)&reset_motion_fields__13TUnk_804AF8A0Fv,
    (s32)&vfunc_9__13TUnk_804B9870Fv,
    (s32)&update_object_view_visibility__13TUnk_804B9870Fff,
    (s32)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (s32)&get_name__13TUnk_804B9870Fv,
    (s32)&interact__13TUnk_804AF8A0Fl,
    (s32)&vfunc_14__12TObjWarpBaseFv,
    (s32)&open_confirm_window__12TObjAreaWarpFUs,
    (s32)&TObjAreaWarp::is_warp_enabled,
    (s32)&vfunc_17__12TObjWarpBaseFv,
    (s32)&vfunc_18__12TObjWarpBaseFl,
    (s32)&confirm_area_transfer__12TObjAreaWarpFPvi,
    (s32)&debug_print_area_num__17TObjWarpBossMultiFv
};
void *TObjWarpBossMulti::create() {
    void *o = __nw__7TObjectFUl(0x100);
    if (o != NULL) {
        o = TObjWarpBossMulti__ct((Obj_8019E238 *)(o), tl_05, this);
    }
    return o;
}

void TObjWarpBossMulti::init_warp_params() { this->m_f0 = get_boss_warp_base_model(); this->m_f4 = get_boss_warp_confirmation_model(); *(int*)((char*)this + 0xdc) = get_boss_warp_model(); *(int*)((char*)this + 0xe0) = get_boss_warp_motion(); *(int*)((char*)this + 0xe4) = get_boss_warp_bml_motion(); *(int*)((char*)this + 0xe8) = get_boss_warp_model_handle(); *(int*)((char*)this + 0xec) = fn_8019F9AC(); this->m_f8 = lbl_805DC000; *(float*)((char*)this + 0xfc) = lbl_805DC004; }

void TObjWarpBossMulti::update() {
    s32 temp_r0;

    if (TOKeyMachine01::get_global_state() == 0) {
        *(s32 *)((s8 *)this + 0xF4) = -1;
    } else {
        temp_r0 = *(s32 *)((s8 *)this + 0x88);
        if ((temp_r0 < 0) || (temp_r0 > 0xFF)) {
            *(s32 *)((s8 *)this + 0xF4) = -1;
        } else {
            *(s32 *)((s8 *)this + 0xF4) = temp_r0;
        }
    }
    if ((s32) *(s32 *)((s8 *)this + 0xF4) >= 0) {
        *(s32 *)((s8 *)this + 0xF0) = 0;
        return;
    }
    *(s32 *)((s8 *)this + 0xF0) = 1;
}

void TObjWarpBossMulti::debug_print_area_num() {
    Wb_8019DE74 *arg0 = (Wb_8019DE74 *)this;
    ((TObjWarpBossMulti *)arg0)->update();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (TOKeyMachine01::get_global_state() == 0) {
        debug_printf_at(0x130020, lbl_8044663C);
    }
    debug_printf_at(0x130021, lbl_80446650, arg0->fF4);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void render__17TObjWarpBossMultiFv(u8 *warp_boss_multi) {

    if ((s32) ((TObjWarpBossMulti *)warp_boss_multi)->m_d8 == 0xE) {
        if (xz_distance_squared(camera_ctrl_instance + 0x178, warp_boss_multi + 0x38) > lbl_805DC008) {
            return;
        }
        goto block_4;
    }
    if (((TObjWarpBossMulti_8019DD34*)warp_boss_multi)->m8(lbl_805DC00C, lbl_805DC010) != 0) {
block_4:
        push_matrix();
        post_translate_matrix(warp_boss_multi + 0x38);
        rotate_matrix_y(0, ((TObjWarpBossMulti *)warp_boss_multi)->rotation_y);
        TObjFish::set_global_param(*(s32 *)((s8 *)warp_boss_multi + 0xE8));
        draw_ginja_object((void *)(((TObjWarpBossMulti *)warp_boss_multi)->m_f0));
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(*(s32 *)((s8 *)warp_boss_multi + 0xEC));
        switch (*(s32 *)((s8 *)warp_boss_multi + 0xF0)) {
        case 0:
            draw_ginja_model_with_motion(((TObjWarpBossMulti *)warp_boss_multi)->m_f4, *(s32 *)((s8 *)warp_boss_multi + 0xE0), ((TObjWarpBossMulti *)warp_boss_multi)->m_f8);
            break;
        case 1:
            draw_ginja_model_with_motion(*(s32 *)((s8 *)warp_boss_multi + 0xDC), *(s32 *)((s8 *)warp_boss_multi + 0xE4), ((TObjWarpBossMulti *)warp_boss_multi)->m_f8);
            break;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void run_task__17TObjWarpBossMultiFv(Obj_8019DFE8 *self) {
    s32 i;
    u32 pl;
    f32 r;

    for (i = 0; i < 4; i++) {
        pl = player_slot_table[i];
        if (pl != 0U && is_locally_controlled__10TObjPlayerFPv(pl) != 0) {
            if (((TObjPlayer *)pl)->get_field_3e4() == get_current_floor()) {
                if (xz_distance_squared(pl + 0x38, self->f38) <= (r = lbl_805DC014 + self->fAC) * r) {
                    if (TObjWarpBossMulti::is_flag_clear((void*)pl) != 0) {
                        self->fC4[i] = 1;
                        ((TObjPlayer *)pl)->check_technique_flag();
                    }
                } else if (TObjWarpBossMulti::is_flag_clear((void*)pl) == 0) {
                    if (self->fC4[i] != 0) {
                        self->fC4[i] = 0;
                        ((TObjPlayer *)pl)->has_item_flag_4096();
                    }
                }
            }
        }
    }
    if (self->fF4 >= 0) {
        if (((u8 (*)(u16))is_current_floor_switch_set)(self->fF4) == 1) {
            self->fF0 = 1;
        } else {
            self->fF0 = 0;
        }
    }
    switch (self->fF0) {
    case 0:
        self->fF8 += self->fFC;
        if (self->fF8 > (self->fE0->count - 1)) {
            self->fF8 = lbl_805DC000;
        }
        break;
    case 1:
        self->fF8 += self->fFC;
        if (self->fF8 > (self->fE4->count - 1)) {
            self->fF8 = lbl_805DC000;
        }
        ((TObjAreaWarp *)self)->handle_area_selection();
        break;
    }
}

void *__dt__17TObjWarpBossMultiFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjWarpBossMulti;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        __dt__12TObjAreaWarpFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_8019E238 *TObjWarpBossMulti__ct(Obj_8019E238 *self, void * _w1, void * _w2) {
    int i;
    TObjAreaWarp__ct(self);
    self->vt18 = ((s32 *)&__vt__17TObjWarpBossMulti);
    self->f0 = TObjWarpBossMulti__name;
    self->fBC = get_boss_warp_destination();
    self->fA4 = 0;
    register_entity_by_id(self);
    ((TObjWarpBossMulti *)self)->update();
    ((TObjWarpBossMulti *)self)->init_warp_params();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = alloc__23TAdSinglePlyChrSelectGCFv(0x88);
        if (p != NULL) {
            p = init__13TAdVIConfigGCFf(p, self->f38, lbl_805DC018);
        }
        self->fC0 = p;
    } else {
        self->fC0 = NULL;
    }
    self->fAC = lbl_805DC018;
    for (i = 0; i < 4; i++) {
        self->fC4[i] = 0;
    }
    return self;
}

void TObjWarpBoss::update_warp_boss_visibility() {
    void *player;
    s32 var_r30;

    player = get_player_by_client_id(local_client_id);
    var_r30 = 1;
    if ((player != NULL) && (((P_V_8019DD34 *) player)->m31() != 0)) {
        var_r30 = 0;
    }
    if ((player != NULL) && (check_flag_100__10TObjPlayerFPv(player) != 0)) {
        var_r30 = 0;
    }
    if (var_r30 == 0) {
        if ((u32) *(u32 *)((s8 *)this + 0x168) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x168)))->suspend_update();
            disallow_rendering__7TObjectFv((TObject *)((void *)(*(u32 *)((s8 *)this + 0x168))));
        }
        if ((u32) this->m_b0 != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0xB0)))->suspend_update();
            disallow_rendering__7TObjectFv((TObject *)(this->m_b0));
        }
        if ((u32) this->m_180 != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x164)))->suspend_update();
            disallow_rendering__7TObjectFv((TObject *)(this->m_180));
        }
    } else {
        if ((u32) *(u32 *)((s8 *)this + 0x168) != 0U) {
            ((TQuestVmDownLoadServer *)(*(void **)((s8 *)this + 0x168)))->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)((void *)(*(u32 *)((s8 *)this + 0x168))));
        }
        if ((u32) this->m_b0 != 0U) {
            ((TQuestVmDownLoadServer *)(*(void **)((s8 *)this + 0xB0)))->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)(this->m_b0));
        }
        if ((u32) this->m_180 != 0U) {
            ((TQuestVmDownLoadServer *)(*(void **)((s8 *)this + 0x164)))->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)(this->m_180));
        }
    }
}

typedef char RecoveredGlobal_8019E418_lbl_8050E208_size[sizeof(RecoveredGlobal_8019E418_lbl_8050E208) == 0x1B0 ? 1 : -1];
s32 TObjWarpBoss::sub_8019E418() {
    u8 *arg0 = (u8 *)this;
    if (TObjWarpBossMulti::is_lobby_active() == 0) {
        return 0;
    }
    if ((*(f32 *)((s8 *)&controller_input_state.value + 0x44) > lbl_805DC01C) || (TObjWarpBossMulti__sub_8019E570((s32) arg0, *(f32 *)((s8 *)arg0 + 0xAC)) == 0U)) {
        return 1;
    }
    return 0;
}

s32 TObjWarpBossMulti::is_lobby_active() {
    return TLobby::get_state() ? 1 : 0;
}

s32 TObjWarpBossMulti::get_boss_warp_flag() {
    return ((get_main_phase() - 0xF) == 0) ? lbl_805D55C0 : 0;
}

s32 TObjWarpBoss::are_all_players_in_range() {
    Wb_8019E4E8 *arg0 = (Wb_8019E4E8 *)this;
    s32 ok = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        Pl_8019E4E8 *p = (Pl_8019E4E8 *)get_player_by_client_id(i);
        if (p != 0) {
            if (((TObjPlayer *)p)->get_field_3e4() != get_current_floor() || ((f32 (*)(void *, void *))xz_distance_squared)(p->pos, arg0->pos) > arg0->fAC * arg0->fAC) {
                ok = 0;
            }
        }
    }
    return ok;
}

#pragma push
#pragma fp_contract on
s32 TObjWarpBossMulti__sub_8019E570(s32 arg0, f32 farg0) {
    s32 current_floor;
    s32 temp_r3b;
    s32 player;
    player = (s32)get_player_by_client_id(local_client_id);
    if (player != 0) {
        current_floor = get_current_floor();
        temp_r3b = ((TObjPlayer *)player)->get_field_3e4();
        if ((temp_r3b == current_floor) && (((f32 (*)(s32, s32))xz_distance_squared)(arg0 + 0x38, player + 0x38) < (farg0 * farg0))) {
            return player;
        }
    }
    return 0;
}
#pragma pop

void TObjWarpBoss::close_windows() {
    if ((u32) *(u32 *)((s8 *)this + 0x168) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x168)))->close();
        *(u32 *)((s8 *)this + 0x168) = 0U;
    }
    if ((u32) this->m_b0 != 0U) {
        TWindow__close(*(void **)((s8 *)this + 0xB0));
        this->m_b0 = 0U;
    }
    if ((u32) this->m_180 != 0U) {
        TWindow__close(*(void **)((s8 *)this + 0x164));
        this->m_180 = 0U;
    }
    end_player_keyboard_hold(local_client_id);
    TWindowCtrl::clear_flag();
    ((TWindowCtrl *)local_client_id)->unsuppress_slot();
}
}
void initialize_option_dialog(void *arg0, s32 arg1, s32 arg2, f32 farg0);
void handle_6x6A_set_boss_warp_flags(void *arg0);
void handle_6x6A_set_boss_warp_flags(void *arg0) {
    void *entity;

    bswap_6x6A_packet__19TWindowSubTradeMainFv();
    entity = find_entity_by_id(*(u16 *)((s8 *)arg0 + 2));
    if (entity != NULL) {
        *(s16 *)((s8 *)entity + 0xDC) = (s16) *(s16 *)((s8 *)arg0 + 4);
    }
}
extern "C" {

void TObjWarpBoss::send_cmd_6A(u16 value) {
    TObjWarpBoss *self = this;
    Pkt_8019E6C0 pkt;
    ((TWindowSubTradeMain *)(&pkt))->init_pkt_cmd_6A();
    pkt.id = self->m_1c;
    pkt.value = value;
    ((TWindowSubTradeMain *)(&pkt))->send_60_update();
}

void TObjWarpBossMulti::notify_player(void *arg0, s32 arg1) {
    s32 player;

    player = (s32)get_player_by_client_id(arg1);
    if (player != 0) {
        send_code_45_1__10TObjPlayerFl();
        obj_clear_flag30_20000((void *)player);
    }
}

void TObjWarpBoss::warp_player(s32 arg1) {
    s32 player;

    player = (s32)get_player_by_client_id(arg1);
    if (player != 0) {
        play_effect_default__10TObjPlayerFii(player, -1);
        obj_set_flag_20000((void *)player);
        *(s32 *)((s8 *)this + 0x174) = 0x12C;
    }
}

void TObjWarpBoss::update_floor_switch_state() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;
    switch (*(s16 *)((s8 *)arg0 + 0xE0)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0xD0) = 0;
        *(s16 *)((s8 *)arg0 + 0xE0) = 1;
        return;
    case 1:
        temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x16C);
        if ((temp_r0_2 >= 0) && (is_current_floor_switch_set((int) ((u16) temp_r0_2)) == 1)) {
            *(s16 *)((s8 *)arg0 + 0xDC) = 0;
        }
        return;
    case -1:
        break;
    }
}

void TObjWarpBoss::warp_boss_handle_window() {

    switch (*(s16 *)((s8 *)this + 0xE0)) {
    case 0:
        *(s16 *)((s8 *)this + 0xE0) = 1;
        *(s32 *)((s8 *)this + 0xD0) = 0;
        return;
    case 1:
        if (((u32 (*)(f32))TObjWarpBossMulti__sub_8019E570)(*(f32 *)((s8 *)this + 0xAC)) != 0U) {
            if ((u32) *(u32 *)((s8 *)this + 0xB0) == 0U) {
                *(u32 *)((s8 *)this + 0xB0) = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x35), 7);
                if ((u32) *(u32 *)((s8 *)this + 0xB0) != 0U) {
                    ((TWindowSubTradeMain *)(*(u32 *)((s8 *)this + 0xB0)))->add_text_entry(get_message_10__20TWindowSubStatusDispFl(0x40), 0, 0, -1);
                    ((TAdChrSelASlotGC *)(*(u32 *)((s8 *)this + 0xB0)))->set_flag_40();
                    ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0xB0)))->calc_window_size();
                    align_menu_entry_positions(*(u32 *)((s8 *)this + 0xB0));
                }
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                ((TWindowCtrl *)local_client_id)->suppress_slot();
            }
        } else {
            if ((u32) *(u32 *)((s8 *)this + 0xB0) != 0U) {
                TWindow__close(*(void **)((s8 *)this + 0xB0));
                *(u32 *)((s8 *)this + 0xB0) = 0U;
            }
            end_player_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            ((TWindowCtrl *)local_client_id)->unsuppress_slot();
        }
        if ((s32) *(s32 *)((s8 *)this + 0x15C) == 0) {
            *(s16 *)((s8 *)this + 0xDC) = 0;
        }
        return;
    case -1:
        if ((u32) *(u32 *)((s8 *)this + 0xB0) != 0U) {
            TWindow__close(*(void **)((s8 *)this + 0xB0));
            *(u32 *)((s8 *)this + 0xB0) = 0U;
        }
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        ((TWindowCtrl *)local_client_id)->unsuppress_slot();
        break;
    }
}

void TObjWarpBoss::update_state() {
    s32 temp_r0_2;
    s32 temp_r3;

    switch (*(s16 *)((s8 *)this + 0xE0)) {
    case 0:
        *(s32 *)((s8 *)this + 0x17C) = 0x96;
        *(s16 *)((s8 *)this + 0xE0) = 1;
        *(s16 *)((s8 *)this + 0xE2) = (s16) (*(s16 *)((s8 *)this + 0xE2) | 1);
        *(s32 *)((s8 *)this + 0xD0) = (s32) warp_boss_model;
        *(s32 *)((s8 *)this + 0xD4) = (s32) warp_boss_bml_motion;
        return;
    case 1:
        if (TObjWarpBossMulti::get_boss_warp_flag() == 0) {
            temp_r3 = ((s32 (*)(void *, f32))TObjWarpBossMulti__sub_8019E570)(this, *(f32 *)((s8 *)this + 0xAC));
            if (temp_r3 != 0) {
                TObjWarpBossMulti::notify_player(this, local_client_id);
                this->confirm_area_transfer(temp_r3);
                *(s16 *)((s8 *)this + 0xE0) = 2;
            }
        }
        temp_r0_2 = *(s32 *)((s8 *)this + 0x17C) - 1;
        *(s32 *)((s8 *)this + 0x17C) = temp_r0_2;
        if (temp_r0_2 <= 0) {
            *(s16 *)((s8 *)this + 0xE0) = 2;
        }
        break;
    case -1:
        break;
    case 2:
        *(s16 *)((s8 *)this + 0xE2) = (s16) (*(s16 *)((s8 *)this + 0xE2) & 0xFFFFFFFE);
        *(s16 *)((s8 *)this + 0xDC) = 3;
        break;
    }
}

void TObjWarpBoss::update_warp_state() {
    u8 *arg0 = (u8 *)this;
    s32 var_r3;

    switch (*(s16 *)((s8 *)arg0 + 0xE0)) {
    case 2:
        break;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x160) = 0x12C;
        play_sound_effect(0x40003205, arg0 + 0x38, 0, 0);
        *(s16 *)((s8 *)arg0 + 0xE0) = 1;
        *(s32 *)((s8 *)arg0 + 0xD0) = (s32) warp_boss_model;
        *(s32 *)((s8 *)arg0 + 0xD4) = (s32) warp_boss_bml_motion;
        return;
    case 1:
        if (((u32 (*)(f32))TObjWarpBossMulti__sub_8019E570)(*(f32 *)((s8 *)arg0 + 0xAC)) != 0U) {
            update_warp_dialogs();
            if ((s32) *(s32 *)((s8 *)arg0 + 0x170) == 0) {
                warp_player(local_client_id);
                *(s32 *)((s8 *)arg0 + 0x170) = 1;
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0) {
            *(s32 *)((s8 *)arg0 + 0x160) = (s32) (*(s32 *)((s8 *)arg0 + 0x160) - 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x160) <= 0) {
                var_r3 = 1;
            } else {
                var_r3 = are_all_players_in_range();
            }
            if (var_r3 != 0) {
                send_cmd_6A(2);
                *(s16 *)((s8 *)arg0 + 0xE0) = 2;
            }
        }
        break;
    case -1:
        ((s32 (*)())close_windows__12TObjWarpBossFv)();
        break;
    }
}

#define arg0 ((u8 *)arg0_)

#undef arg0

void TObjWarpBoss::update_warp_confirmation() {
    u8 *arg0 = (u8 *)this;
    s32 r;
    if (*(s32 *)((s8 *)arg0 + 0x15C) == 1) {
        *(s16 *)((s8 *)arg0 + 0xDC) = 3;
        return;
    }
    switch (*(s16 *)((s8 *)arg0 + 0xE0)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x170) = 0;
        *(s32 *)((s8 *)arg0 + 0x174) = 0;
        *(s16 *)((s8 *)arg0 + 0xE0) = 1;
        *(s32 *)((s8 *)arg0 + 0xD0) = boss_warp_confirmation_model;
        *(s32 *)((s8 *)arg0 + 0xD4) = warp_boss_motion;
        break;
    case 1:
        if (((TObjWarpBoss *)arg0)->sub_8019E418() == 0 && (u32) TObjWarpBossMulti__sub_8019E570((s32) arg0, *(f32 *)((s8 *)arg0 + 0xAC)) != 0) {
            ((TObjWarpBoss *)arg0)->update_warp_dialogs();
            ((TObjWarpBoss *)arg0)->warp_player(local_client_id);
            *(s16 *)((s8 *)arg0 + 0xE0) = 2;
            break;
        }
        if (*(void **)((s8 *)arg0 + 0xB0) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0xB0));
            *(void **)((s8 *)arg0 + 0xB0) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x164) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x164));
            *(void **)((s8 *)arg0 + 0x164) = NULL;
        }
        break;
    case 2:
        ((TObjWarpBoss *)arg0)->update_warp_dialogs();
        if (*(void **)((s8 *)arg0 + 0x168) != NULL) {
            if (((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x168)))->get_card_data() != 0) {
                *(s16 *)((s8 *)arg0 + 0xE0) = 3;
            } else if (((TWindowMessageYesNo *)(*(void **)((s8 *)arg0 + 0x168)))->is_child_visible() != 0) {
                r = ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x168)))->get_slot_or_neg1();
                if (r == 0) {
                    ((TObjWarpBoss *)arg0)->warp_player(local_client_id);
                    *(s32 *)((s8 *)arg0 + 0x170) = 1;
                    ((TObjWarpBoss *)arg0)->send_cmd_6A(1);
                    *(s16 *)((s8 *)arg0 + 0xE0) = 5;
                } else if (r == 1) {
                    *(s16 *)((s8 *)arg0 + 0xE0) = 3;
                }
            }
        }
        if (((TObjWarpBoss *)arg0)->sub_8019E418() != 0) {
            *(s16 *)((s8 *)arg0 + 0xE0) = 3;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF && is_local_client_floor_leader() != 0 && ((TObjWarpBoss *)arg0)->are_all_players_in_range() != 0) {
            ((TObjWarpBoss *)arg0)->send_cmd_6A(2);
            *(s16 *)((s8 *)arg0 + 0xE0) = 5;
        }
        if (*(s16 *)((s8 *)arg0 + 0xE0) != 2) {
            close_windows__12TObjWarpBossFv(arg0);
        }
        break;
    case 3:
        TObjWarpBossMulti::notify_player(arg0, local_client_id);
        *(s16 *)((s8 *)arg0 + 0xE0) = 4;
        break;
    case 4:
        if ((u32) TObjWarpBossMulti__sub_8019E570((s32) arg0, *(f32 *)((s8 *)arg0 + 0xAC)) == 0) {
            *(s16 *)((s8 *)arg0 + 0xE0) = 1;
            break;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF && is_local_client_floor_leader() != 0 && ((TObjWarpBoss *)arg0)->are_all_players_in_range() != 0) {
            ((TObjWarpBoss *)arg0)->send_cmd_6A(2);
            *(s16 *)((s8 *)arg0 + 0xE0) = 5;
        }
        break;
    case -1:
        close_windows__12TObjWarpBossFv(arg0);
        break;
    case 5:
        break;
    }
}

void TObjWarpBoss::update_warp_occupants() {
    u8 *arg0 = (u8 *)this;
    Warp_8019EE14 *self = (Warp_8019EE14 *)arg0;
    s32 i;
    s32 inside;
    Player_8019EE14 *pl;
    s32 room;
    s32 old;
    Player_8019EE14 *pl2;
    old = self->count;
    self->count = 0;
    self->n_inside = 0;
    self->f15c = 0;
    for (i = 0; i < 4; i++) {
        pl = (Player_8019EE14 *)get_player_by_client_id(i);
        if (pl != NULL) {
            room = ((TObjPlayer *)pl)->get_field_3e4();
            if (room == self->fbc) {
                self->f15c = 1;
            }
            inside = 0;
            if (room == get_current_floor()) {
                if (((f32 (*)(void *, void *))xz_distance_squared)(pl->pos, self->pos) <= self->radius * self->radius) {
                    inside = 1;
                    self->n_inside++;
                }
            }
            self->inside[self->count] = inside;
            strcpy(self->names[self->count], pl->name);
            self->count++;
        }
    }
    for (i = self->count; i < 4; i++) {
        self->names[i][0] = 0;
    }
    if (old != self->count && self->window != 0) {
        ((s32 (*)(u32))TWindow__close)(self->window);
        self->window = 0;
    }
    pl2 = (Player_8019EE14 *)get_player_by_client_id(local_client_id);
    if (pl2 != NULL && ((TObjPlayer *)pl2)->get_field_3e4() == get_current_floor()) {
        if (((f32 (*)(void *, void *))xz_distance_squared)(pl2->pos, self->pos) <= (lbl_805DC014 + self->radius) * (lbl_805DC014 + self->radius)) {
            if (TObjWarpBossMulti::is_flag_clear((void*)pl2) != 0) {
                self->warping = 1;
                ((TObjPlayer *)pl2)->check_technique_flag();
            }
        } else if (TObjWarpBossMulti::is_flag_clear((void*)pl2) == 0 && self->warping != 0) {
            self->warping = 0;
            ((TObjPlayer *)pl2)->has_item_flag_4096();
        }
    }
}

typedef struct Pos_8019EFF0 Pos_8019EFF0;
typedef struct Warp_8019EFF0 Warp_8019EFF0;
s32 TObjWarpBoss::update_warp_dialogs() {
    u8 *arg0 = (u8 *)this;
  s32 i;
  int j;
  Warp_8019EFF0 *self = (Warp_8019EFF0 *) arg0;
  u32 color;
  Pos_8019EFF0 pos;
  switch (self->mode)
  {
    case 0:
      if ((TObjWarpBossMulti::is_lobby_active() == 0) && (self->dialog == 0))
    {
      self->dialog = TWindowMessageYesNo::create((void *)self, (void *)local_client_id, (void *)0, (void *)0);
      if (self->dialog != 0)
      {
        forward_slot_selection__16TAdChrSelASlotGCFPvPv(self->dialog, get_message_10__20TWindowSubStatusDispFl(0x41), ((s32)get_window_layout_position(0x36)), lbl_805DC020);
        free_member__17TWindowSubComCardFv(self->dialog, 1);
        ((TWindowSubShortMail *)(self->dialog))->notify_warp_flag70();
        begin_player_keyboard_hold(local_client_id);
        request_active_window_close();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
      }
    }
      break;
    case 1:
      if (self->dialog == 0)
    {
      i = 0x36;
      self->dialog = TWindowMessageYesNo::create((void *)self, (void *)local_client_id, (void *)0, (void *)0);
      if (self->dialog != 0)
      {
        initialize_option_dialog(self->dialog, get_message_10__20TWindowSubStatusDispFl(0x42), ((s32)get_window_layout_position(i)), lbl_805DC020);
      }
    }
      break;
  }
  if (self->list == 0)
  {
    pos.x = lbl_805DC024;
    pos.y = lbl_805DC028;
    self->list = refresh_with_default_list__20TWindowSubStatusDispFll(((s32)get_window_layout_position(0x34)), &pos);
    if (self->list != 0)
    {
      ((TWindowSubTradeMain *)(self->list))->set_visible();
      ((TWindowSubTradeMain *)(self->list))->set_close_flag();
      for (i = 0; i < self->count; i++)
      {
        TWindowSubStatusDisp::dispatch_without_flags((s32)self->list, (s32)self->names[i], (s32)i);
      }
    }
    request_active_window_close();
  }
  if (self->list != 0)
  {
    for (j = 0; j < self->count; j++)
    {
            ((THunterGuildSeqOffline *)(self->list))->advance_matching_entries(self->inside[j] != 0, j);
      color = 0xF0F0F0FF;
      if (((self->mode == 1) && (((u32)get_player_by_client_id((j))) != 0)) && (check_player_flag1__6TLobbyFv() != 0))
      {
        color = 0xFFFF00FF;
      }
      fn_80248994(self->list, color, j);
    }
  }
}

void TObjWarpBoss::update() {

    ((s32 (*)())update_warp_boss_visibility__12TObjWarpBossFv)();
    switch (*(s16 *)((s8 *)this + 0xDE)) {
    case 0:
        this->update_warp_confirmation();
        return;
    case 1:
        this->update_warp_state();
        return;
    case 2:
        this->update_state();
        return;
    case 3:
        warp_boss_handle_window();
        return;
    case 4:
        this->update_floor_switch_state();
        return;
    }
}

void TObjWarpBoss::debug_print_area_num() {
    Wb_8019F2C0 *arg0 = (Wb_8019F2C0 *)this;
    s32 t = arg0->f88;
    if (t < 0 || t > 0xFF) {
        arg0->f16C = -1;
    } else {
        arg0->f16C = t;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (TOKeyMachine01::get_global_state() == 0) {
        debug_printf_at(0x130020, lbl_8044663C);
    }
    debug_printf_at(0x130021, lbl_80446650, arg0->f16C);
}

void TObjWarpBoss::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0xBC) == 0xE) {
        if (xz_distance_squared(camera_ctrl_instance + 0x178, (u8 *)&this->position) > lbl_805DC008) {
            return;
        }
        goto block_4;
    }
    if (((VObj2_8019f358_8019F22C*)arg0)->m8(lbl_805DC00C, lbl_805DC010) != 0) {
block_4:
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(warp_boss_model_handle);
        draw_ginja_object((void *)boss_warp_base_model);
        if (*(void **)((s8 *)arg0 + 0xD0) != 0) {
            TParticleCtrl::begin_effect_render();
            TObjFish::set_global_param(lbl_805D5CA4);
            ((s32 (*)(u32, s32, f32))draw_ginja_model_with_motion)(*(u32 *)((s8 *)arg0 + 0xD0), *(s32 *)((s8 *)arg0 + 0xD4), *(f32 *)((s8 *)arg0 + 0xC4));
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TObjWarpBoss::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 1) {
        if (!(*(s16 *)((s8 *)arg0 + 0xE2) & 1) && ((s16) *(s16 *)((s8 *)arg0 + 0xDE) != (s16) *(s16 *)((s8 *)arg0 + 0xDC))) {
            if ((s16) *(s16 *)((s8 *)arg0 + 0xE0) != -1) {
                *(s16 *)((s8 *)arg0 + 0xE0) = -1;
                ((TObjWarpBoss *)arg0)->update();
            }
            *(s16 *)((s8 *)arg0 + 0xDE) = (s16) *(s16 *)((s8 *)arg0 + 0xDC);
            *(s16 *)((s8 *)arg0 + 0xE0) = 0;
        }
        ((TObjWarpBoss *)arg0)->update_warp_occupants();
        ((TObjWarpBoss *)arg0)->update();
        if ((void *) *(u8 **)((s8 *)arg0 + 0xD4) != NULL) {
            *(f32 *)((s8 *)arg0 + 0xC4) = (f32) (*(f32 *)((s8 *)arg0 + 0xC4) + lbl_805DC004);
            if ((lbl_805DC02C + *(f32 *)((s8 *)arg0 + 0xC4)) >= (f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xD4)) + 4)) {
                *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DC000;
            }
        }
    }
}
void *__dt__12TObjWarpBossFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjWarpBoss;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        close_windows__12TObjWarpBossFv(arg0);
        __dt__12TObjAreaWarpFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
Obj_8019F578 *TObjWarpBoss__ct(Obj_8019F578 *self, int _w1, void * _w2) {
    int i;
    TObjAreaWarp__ct(self);
    self->vt18 = ((s32 *)&__vt__12TObjWarpBoss);
    self->f0 = TObjWarpBoss__name;
    self->fC4 = lbl_805DC000;
    self->fAC = lbl_805DC018;
    self->fBC = get_boss_warp_destination();
    self->fA4 = 0;
    register_entity_by_id(self);
    self->f164 = 0;
    self->f168 = 0;
    self->f180 = 0;
    if (TOKeyMachine01::get_global_state() == 0) {
        self->f16C = -1;
    } else if (self->f88 < 0 || self->f88 > 0xFF) {
        self->f16C = -1;
    } else {
        self->f16C = self->f88;
    }
    if (self->f16C >= 0) {
        self->fDC = 4;
        self->fDE = 4;
    } else {
        self->fDC = 0;
        self->fDE = 0;
    }
    self->fE0 = 0;
    self->fE2 = 0;
    self->fD0 = 0;
    self->fD4 = 0;
    if (self->fB4 != NULL) {
        queue_destruction__7TObjectFv(self->fB4);
        self->fB4 = NULL;
    }
    for (i = 0; i < 4; i++) {
        self->f144[i] = 0;
    }
    return self;
}
s32 TObjWarpBossMulti__create(s32 arg0) {
    s32 temp_r3;
    s32 var_r0;
    if ((TRaderMapCore::is_not_split_screen() == 0) && (get_main_phase() == 0xE)) {
        return ((s32)((TObjWarpBossMulti *)arg0)->create());
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return ((s32)((TObjWarpBossMulti *)arg0)->create());
    }
    temp_r3 = ((s32)__nw__7TObjectFUl(0x184));
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = ((s32)TObjWarpBoss__ct((Obj_8019F578 *)(temp_r3), (int)((int) ((*(s32 *)&tl_05))), (void *)arg0));
    }
    return var_r0;
}
void TObjFish__sub_8019F72C(void) {
    if ((u32) boss_warp_resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)boss_warp_resource_bundle, 1);
        boss_warp_resource_bundle = 0U;
    }
}
void TObjFish::load_models() {
    s32 st;
    s32 r;
    st = TOKeyMachine01::get_global_state();
    if (st >= 8 && st <= 0xA) {
        r = ((s32)alloc__23TAdSinglePlyChrSelectGCFv(0x440));
        if (r != 0) {
            r = ((s32 (*)(s32, s32, void *, s32, s32, s32)) load_resource_from_descriptor)(r, 5, lbl_804B94D8, 0, 0, 0);
        }
        (*(s32 *)&boss_warp_resource_bundle) = r;
        (*(s32 *)&boss_warp_base_model) = get_bml_model(r, 0);
        (*(s32 *)&boss_warp_confirmation_model) = get_bml_model((*(s32 *)&boss_warp_resource_bundle), 2);
        (*(s32 *)&warp_boss_model) = get_bml_model((*(s32 *)&boss_warp_resource_bundle), 1);
        (*(s32 *)&warp_boss_motion) = get_bml_motion((*(s32 *)&boss_warp_resource_bundle), 1);
        (*(s32 *)&warp_boss_bml_motion) = get_bml_motion((*(s32 *)&boss_warp_resource_bundle), 0);
        (*(s32 *)&warp_boss_model_handle) = TObjFish__sub_8001EDB0((*(s32 *)&boss_warp_resource_bundle), 2);
        (*(s32 *)&lbl_805D5CA4) = TObjFish__sub_8001EDB0((*(s32 *)&boss_warp_resource_bundle), 2);
        return;
    }
    if (TContainerAncient01::is_global_state_in_table() != 0 || st == 0x1C || st == 0x1D) {
        r = ((s32)alloc__23TAdSinglePlyChrSelectGCFv(0x440));
        if (r != 0) {
            r = ((s32 (*)(s32, s32, void *, s32, s32, s32)) load_resource_from_descriptor)(r, 5, lbl_804B94FC, 0, 0, 0);
        }
        (*(s32 *)&boss_warp_resource_bundle) = r;
        (*(s32 *)&boss_warp_base_model) = get_bml_model(r, 0);
        (*(s32 *)&boss_warp_confirmation_model) = get_bml_model((*(s32 *)&boss_warp_resource_bundle), 1);
        (*(s32 *)&warp_boss_model) = get_bml_model((*(s32 *)&boss_warp_resource_bundle), 1);
        (*(s32 *)&warp_boss_motion) = get_bml_motion((*(s32 *)&boss_warp_resource_bundle), 0);
        (*(s32 *)&warp_boss_bml_motion) = get_bml_motion((*(s32 *)&boss_warp_resource_bundle), 0);
        (*(s32 *)&warp_boss_model_handle) = TObjFish__sub_8001EDB0((*(s32 *)&boss_warp_resource_bundle), 0);
        (*(s32 *)&lbl_805D5CA4) = TObjFish__sub_8001EDB0((*(s32 *)&boss_warp_resource_bundle), 0);
        return;
    }
    r = ((s32)alloc__23TAdSinglePlyChrSelectGCFv(0x440));
    if (r != 0) {
        r = ((s32 (*)(s32, s32, void *, s32, s32, s32)) load_resource_from_descriptor)(r, 5, lbl_804B94AC, 0, 0, 0);
    }
    (*(s32 *)&boss_warp_resource_bundle) = r;
    (*(s32 *)&boss_warp_base_model) = get_bml_model(r, 0);
    (*(s32 *)&boss_warp_confirmation_model) = get_bml_model((*(s32 *)&boss_warp_resource_bundle), 2);
    (*(s32 *)&warp_boss_model) = get_bml_model((*(s32 *)&boss_warp_resource_bundle), 1);
    (*(s32 *)&warp_boss_motion) = get_bml_motion((*(s32 *)&boss_warp_resource_bundle), 1);
    (*(s32 *)&warp_boss_bml_motion) = get_bml_motion((*(s32 *)&boss_warp_resource_bundle), 0);
    (*(s32 *)&warp_boss_model_handle) = TObjFish__sub_8001EDB0((*(s32 *)&boss_warp_resource_bundle), 2);
    (*(s32 *)&lbl_805D5CA4) = TObjFish__sub_8001EDB0((*(s32 *)&boss_warp_resource_bundle), 2);
}
int fn_8019F9AC(void) {  return (*(int *)&lbl_805D5CA4); }
int get_boss_warp_model_handle(void) {  return (*(int *)&warp_boss_model_handle); }
int get_boss_warp_bml_motion(void) {  return (*(int *)&warp_boss_bml_motion); }
int get_boss_warp_motion(void) {  return (*(int *)&warp_boss_motion); }
int get_boss_warp_model(void) {  return (*(int *)&warp_boss_model); }
int get_boss_warp_confirmation_model(void) {  return (*(int *)&boss_warp_confirmation_model); }
int get_boss_warp_base_model(void) {  return (*(int *)&boss_warp_base_model); }
}

extern char lbl_80446618[];
extern char lbl_80446628[];
s32 TObjWarpBoss__name = (s32)lbl_80446618;
s32 TObjWarpBossMulti__name = (s32)lbl_80446628;
