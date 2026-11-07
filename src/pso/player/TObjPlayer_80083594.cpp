#pragma readonly_strings on
#include "types.h"
#include "pso/system/vector.h"

struct GXColor_80083B8C { u8 r, g, b, a; };

struct C_800845F8 { u8 pad[0x20]; s32 x20; };

struct B_800845F8 { u8 pad[0xc]; C_800845F8 *c; };

struct A_800845F8 { u8 pad[0x8]; B_800845F8 *b; };

struct G_800845F8 { A_800845F8 *a; u8 pad[0x1c]; };

extern "C" {
void GXPixModeSync(void);
void GXSetTexCopySrc(u16, u16, u16, u16);
void GXSetTexCopyDst(u16, u16, s32, u8);
void GXSetCopyClear(GXColor_80083B8C, u32);
void GXCopyTex(void *, u8);
void GXSetViewport(f32, f32, f32, f32, f32, f32);
void GXSetScissor(u32, u32, u32, u32);
void TObjPlayer__sub_80084744(void);
void TObjPlayer__sub_80084754(void);
extern G_800845F8 shared_capture_texture_list;
}

#include "pso/effect/TEffect.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

#include "types.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
struct Stack_80082C30 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
};

struct V2_80082CDC { f32 x, y; };


static GinjaTextureEntry effect_textures[54] = {
    {"f008_white_npr01", 0, NULL},
    {"f032_awa_apn01", 0, NULL},
    {"f032_chun_npn01", 0, NULL},
    {"f032_flash_apr01", 0, NULL},
    {"f032_fog_npn01", 0, NULL},
    {"f032_gunbullet_apr01", 0, NULL},
    {"f032_kisekigreen_apn01", 0, NULL},
    {"f032_kisekired_apn01", 0, NULL},
    {"f032_kisekiviolet_apn01", 0, NULL},
    {"f032_lens01_apn01", 0, NULL},
    {"f032_lens02_apn01", 0, NULL},
    {"f032_lens03_apn01", 0, NULL},
    {"f032_lens04_apn01", 0, NULL},
    {"f032_lens05_apn01", 0, NULL},
    {"f032_lens06_apn01", 0, NULL},
    {"f032_lens07_apn01", 0, NULL},
    {"f032_mshield01_apn01", 0, NULL},
    {"f032_mshield02_apn01", 0, NULL},
    {"f032_netload_apr01", 0, NULL},
    {"f032_redgray_apn01", 0, NULL},
    {"f032_senkou_apr01", 0, NULL},
    {"f032_sennkou_apr01", 0, NULL},
    {"f032_shield01_apn01", 0, NULL},
    {"f032_slow_apn01", 0, NULL},
    {"f032_tama_apn01", 0, NULL},
    {"f064_hane_apr01", 0, NULL},
    {"f064_hitfirec_apr01", 0, NULL},
    {"f064_hitfirered_apr01", 0, NULL},
    {"f064_hitmark_apr01", 0, NULL},
    {"f064_hitmarkblue_apr01", 0, NULL},
    {"f064_impacte_apn01", 0, NULL},
    {"f064_lens01resize_apn01", 0, NULL},
    {"f064_megido_apr01", 0, NULL},
    {"f064_monshou_apr01", 0, NULL},
    {"f064_questloadapn16", 0, NULL},
    {"f064_senblue_apn01", 0, NULL},
    {"f064_shield02_apn01", 0, NULL},
    {"f064_shield03_apn01", 0, NULL},
    {"f064_shield04_apn01", 0, NULL},
    {"f064_shield05_apn01", 0, NULL},
    {"f128_bakuhatu_apn16", 0, NULL},
    {"f128_blackfog_nln16", 0, NULL},
    {"f128_feio_aln16", 0, NULL},
    {"f128_fog_aln16", 0, NULL},
    {"f128_granz_aln16", 0, NULL},
    {"f128_hibana_aln16", 0, NULL},
    {"f128_houden_apr16", 0, NULL},
    {"f128_lightning_alr16", 0, NULL},
    {"f128_smoke_apn16", 0, NULL},
    {"f128_worm_alr16", 0, NULL},
    {"f256_zonde_alr16", 0, NULL},
    {"k016_happa_npr01", 0, NULL},
    {"t032_heart_apn01", 0, NULL},
    {"u064_glasshahen_npr01", 0, NULL},
};

GinjaTextureList shared_effect_texture_list = {effect_textures, 54};

extern "C" {
extern s32 lbl_805D63F0;
extern const f32 lbl_805D93C0;
extern const f32 lbl_805D93C4;
extern const f32 lbl_805D93C8;
extern const f32 lbl_805D93CC;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93D4;
extern const f32 lbl_805D93D8;
extern const f32 lbl_805D93DC;
void TObjPlayer__sub_80082C30(void);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
extern u8 controller_physical_port_bank[];
extern const f32 lbl_805D93E0;
extern const f32 lbl_805D93E4;
extern const f32 lbl_805D93E8;
extern GXColor_80083B8C lbl_805E1214;
extern GXColor_80083B8C lbl_805E1218;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjPlayer__sub_80082C30(void) {
    typedef char sp8_offset[(offsetof(Stack_80082C30, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80082C30, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80082C30, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80082C30, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80082C30, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_80082C30, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80082C30, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_80082C30, sp24) == 0x1C) ? 1 : -1];
    Stack_80082C30 stack;
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0, -1);
    begin_screen_draw(1);
    stack.sp8 = lbl_805D93C0;
    stack.spC = lbl_805D93C4;
    stack.sp10 = lbl_805D93C8 + lbl_805D93C0;
    stack.sp14 = lbl_805D93CC + lbl_805D93C4;
    stack.sp18 = lbl_805D93D0;
    stack.sp1C = lbl_805D93D4;
    stack.sp20 = lbl_805D93D8;
    stack.sp24 = lbl_805D93D8;
    draw_textured_quad_at_depth((&stack.sp8), lbl_805D93DC);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

extern "C" void TObjPlayer__sub_80082CBC(void* effect) {
    *(reinterpret_cast<u8*>(effect) + 0x1C) |= 0x4;
}

extern "C" void TObjPlayer__sub_80082CCC(void* effect) {
    *(reinterpret_cast<u8*>(effect) + 0x1C) &= ~0x4;
}
void TObjPlayer::copy_screen_to_texture(s32 mode, void *src) {
    V2_80082CDC a;
    V2_80082CDC b;
    V2_80082CDC v;
    void *cam;
    GXSetCopyClear(lbl_805E1214, 0xFFFFFF);
    switch (mode) {
    case 0:
        if (src != NULL) {
            ((TWindowSubSymbolChatPartsSet *)(&v))->copy_vec2(src);
            v.x -= lbl_805D93E0;
            v.y -= lbl_805D93E4;
        } else {
            v.x = lbl_805D93C0;
            v.y = lbl_805D93E8;
        }
        GXSetTexCopySrc(v.x, v.y, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex((void *)shared_capture_texture_list.a->b->c->x20, 1);
        GXPixModeSync();
        cam = controller_physical_port_bank + 0x110;
        a.x = lbl_805D93C0;
        a.y = lbl_805D93E8;
        b.x = lbl_805D93C8;
        b.y = lbl_805D93C0;
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        TObjPlayer::draw_textured_screen_quad((u32)(-1), (f32 *)&a, (f32 *)&b, 1);
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            init_tev_swap();
        }
        TObjPlayer__sub_80082C30();
        GXSetTexCopySrc(0xC0, 0x90, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex((void *)shared_capture_texture_list.a->b->c->x20, 1);
        GXPixModeSync();
        break;
    case 1:
        GXSetCopyClear(lbl_805E1218, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
        GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
        GXCopyTex((void *)shared_capture_texture_list.a->b->c->x20, 1);
        GXPixModeSync();
        cam = controller_physical_port_bank + 0x110;
        a.x = lbl_805D93C0;
        a.y = lbl_805D93E8;
        b.x = lbl_805D93C8;
        b.y = lbl_805D93C0;
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            set_tev_swap_mode(0);
        }
        TObjPlayer::draw_textured_screen_quad((u32)(-1), (f32 *)&a, (f32 *)&b, 0);
        if (is_on_current_screen__11TCameraCtrlFv(cam, 0x100) != 0) {
            init_tev_swap();
        }
        TObjPlayer__sub_80082C30();
        GXSetTexCopySrc(0xC0, 0x90, 0x100, 0xC0);
        GXSetTexCopyDst(0x100, 0xC0, 4, 0);
        GXCopyTex((void *)shared_capture_texture_list.a->b->c->x20, 1);
        GXPixModeSync();
        break;
    }
}

// ---- pso/misc/TCameraCtrl_80082FCC
#include "pso/camera/TCameraCtrl_80082FCC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_8048E5DC.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"

struct RecoveredGlobal_800830B0_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct G_80082FCC { s32 value; s32 v4; f32 f8; f32 fC; };

extern "C" {
s32 is_split_screen();
s32 TCameraCtrl__sub_80068EF0();
s32 direction_to_pitch_yaw(void *, void *, void *);
s32 GXSetZMode(int, int, int);
s32 set_perspective_projection_from_fov(int, f32, f32, f32);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern u8 *camera_ctrl_instance;
extern u32 camera_render_target_singleton;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93D8;
extern const f32 lbl_805D9404;
extern const f32 lbl_805D9408;
extern const f32 lbl_805D940C;
extern const f32 lbl_805D9410;
extern GXColor_80083B8C lbl_805E1210;
extern G_80082FCC TCameraCtrl__data_804FF634;
extern const f32 lbl_805D93EC;
extern const f32 lbl_805D93F0;
extern const f32 lbl_805D93F4;
extern const f32 lbl_805D93F8;
extern const f32 lbl_805D93FC;
extern const f32 lbl_805D9400;
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);
void calc_projection_screen_offset(f32 *arg0, f32 *arg1) {
    f32 dx = TCameraCtrl__data_804FF634.f8;
    f32 y = TCameraCtrl__data_804FF634.fC;
    f32 dy;
    dx -= lbl_805D93EC;
    dy = y - lbl_805D93F0;
    *arg0 = (lbl_805D93F4 * dx) / lbl_805D93F8;
    *arg1 = (lbl_805D93FC * dy) / lbl_805D9400;
}

void TCameraCtrl::copy_position_vectors(void *first, void *second) {
    VecCopy((Vec *)((char *)this + 32), (const Vec *)first);
    VecCopy((Vec *)((char *)this + 44), (const Vec *)second);
}

void TCameraCtrl::update_single_screen() {
    if ((is_split_screen() == 0) && ((u32) camera_render_target_singleton != 0U)) {
        TObjFish::set_global_param(camera_render_target_singleton + 0x1C);
        load_list_texture(0, 0, 0, 0);
    }
}

void TUnk_8048E5DC::render() {  }
void TUnk_8048E5DC::run_task() {  }

extern s32 __vt__13TUnk_8048E5DC[];

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_800830B0_main_task_size[sizeof(RecoveredGlobal_800830B0_main_task) == 0x34 ? 1 : -1];
void TUnk_8048E5DC::render_shadows() {
    u8 *arg0 = (u8 *)this;
    if (is_split_screen() == 0) {
        TCameraCtrl::restore_full_screen_view();
        GXSetViewport(lbl_805D93D0, lbl_805D93D0, lbl_805D9404, lbl_805D9408, lbl_805D93D0, lbl_805D93D8);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        Vec up = {0.0f, 1.0f, 0.0f};
        set_perspective_projection_from_fov((int) (((TCameraCtrl *)camera_ctrl_instance)->fov), lbl_805D940C, lbl_805D93D8, lbl_805D9410);
        set_camera_look_at((u8 *)&this->m_20, (u8 *)&this->unk_2C, (u8 *)&up);
        if ((void *) camera_ctrl_instance != NULL) {
            Vec dir;
            s32 pitch;
            s32 yaw;
            dir.x = *(f32 *)&this->unk_2C - this->m_20;
            dir.y = this->m_30 - *(f32 *)&this->unk_24;
            dir.z = *(f32 *)((s8 *)arg0 + 0x34) - this->m_28;
            direction_to_pitch_yaw(&dir, &pitch, &yaw);
            TCameraCtrl::calc_axes_from_angles((s32)camera_ctrl_instance, pitch, yaw);
        }
        TObjPlayer__sub_80084754();
        ((TMainTask *)(&(*(RecoveredGlobal_800830B0_main_task *)&main_task).value))->render_scene_passes();
        TObjPlayer__sub_80084744();
        if ((void *) (*(u8 * *)&camera_render_target_singleton) != NULL) {
            GXSetCopyClear(lbl_805E1210, 0xFFFFFF);
            GXSetZMode((int) (1U), 7, 1);
            GXSetTexCopySrc((int) (0U), 0, (int) (0x280U), (int) (0x1E0U));
            GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
            GXCopyTex((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&camera_render_target_singleton) + 0x1C)) + 8)) + 0xC)) + 0x20)), (int) (1U));
            GXPixModeSync();
        }
        GXSetViewport(lbl_805D93D0, lbl_805D93D0, lbl_805D9404, lbl_805D9408, lbl_805D93D0, lbl_805D93D8);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        TCameraCtrl__sub_80068EF0();
        ((TCameraCtrl *)camera_ctrl_instance)->calc_rotated_axes();
        ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
    }
}
#pragma pop

void *TUnk_8048E5DC::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_8048E5DC;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

// ---- pso/player/TObjPlayer_80083594
#include "types.h"
#include "pso/unk/text_800832EC.h"
#include "pso/unk/TUnk_8048E5DC.h"
#include "pso/system/vector.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80083360.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/player/TObjPlayer_800847A8.h"
#include "pso/system/memory.h"
#include "pso/player/TUnk_8048E5F4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/unk/text_803D96A8.h"
#include <stddef.h>
#include "pso/object/trap/TOTrapAncient02.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/scene/TScene_800838C4.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/main_loop.h"


extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
u8 *create_camera_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_8048E5DC;
    ((TUnk_8048E5DC *)arg0)->m_38 = farg0;
    VecCopy((Vec *)(arg0 + 0x20), (const Vec *)(arg3));
    VecCopy((Vec *)(arg0 + 0x2C), (const Vec *)(arg4));
    *(s8 *)((s8 *)arg0 + 0x1C) = 0;
    return arg0;
}

}


extern "C" {
s32 init_render_target__10TObjPlayerFv();
extern u32 camera_render_target_singleton;
s32 TCameraCtrl__sub_80068EF0();
extern u8 camera_capture_overlay_alpha;
extern const f32 lbl_805D93D0;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
extern s32 __vt__13TUnk_8048E5F4[];

void TObjPlayer::free_singleton() {
    if ((u32) camera_render_target_singleton != 0U) {
        ((TObjPlayer *)camera_render_target_singleton)->reset_lobby_subobject();
    }
    if ((u32) camera_render_target_singleton != 0U) {
        ::operator delete((void *)camera_render_target_singleton);
        camera_render_target_singleton = 0U;
    }
}
void TObjPlayer::init_render_target_singleton() {
    u32 temp_r3;
    camera_render_target_singleton = 0U;
    if (get_current_floor_area() == AREA_GOL_DRAGON) {
        temp_r3 = (int)::operator new(0x28);
        camera_render_target_singleton = temp_r3;
        if (temp_r3 != 0U) {
            init_render_target__10TObjPlayerFv();
        }
    }
}
void TUnk_8048E5F4::render() {
    if (!(TObjPlayer__sub_800847CC() & 4)) {
        if (*(s32 *)&this->unk_1C & 1) {
            if (TObjPlayer__sub_800847A8() == 1) {
                TCameraCtrl::restore_full_screen_view();
                TParticleCtrl::begin_effect_render();
                TObjPlayer::draw_screen_quad(camera_capture_overlay_alpha << 0x18, 0, lbl_805D93D0);
                TParticleCtrl::end_effect_render();
                TCameraCtrl__sub_80068EF0();
                disable_camera_capture_overlay();
            }
        } else {
            TObjPlayer__sub_80084780();
            capture_viewport_texture();
        }
        if (TObjPlayer::get_camera_flag() != 0) {
            TObjPlayer__sub_80084764();
            init_tev_swap();
        }
    }
}
void TUnk_8048E5F4::render_shadows() { if (TObjPlayer::get_camera_flag() != 0) { set_tev_swap_mode((u8)((void*)0)); } }
void TUnk_8048E5F4::run_task() {  }
void *__dt__13TUnk_8048E5F4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_8048E5F4;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}


extern "C" {


extern s32 __vt__13TUnk_8048E5F4[];

void *TUnk_8048E5F4::init_subobject(void *parent, void *flags) {
    __ct__7TObjectFP7TObject(this, parent);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_8048E5F4;
    *(void * *)&this->unk_1C = flags;
    return this;
}

}


void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
extern "C" {
s32 is_split_screen();

extern s32 model_render_flags;
}

void reset_particle_tev() {
    if (is_split_screen() == 0) {
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
        model_render_flags &= 0xFFF7FFFF;
    }
}



struct RecoveredGlobal_80083CEC_lbl_8048E5D0 {
    s32 value;
    u8 remaining[0x8];
};


struct Rect_80083F38 { u8 data[0x20]; };

struct Rect_800846C8 { u8 data[0x20]; };

struct G_800846C8 { void *a; u8 pad[0x1c]; };

struct A_80084694 { u8 pad[0x8]; u32 f8; };

struct G_80084694 { A_80084694 *a; u8 pad[0x1c]; };

struct Vec_80083D54 { f32 x, y, z; };

struct View_80083D54 {
    u8 pad0[0x178];
    Vec_80083D54 pos;
    Vec_80083D54 target;
};

struct Mtx44_80083D54 { f32 m[4][4]; };

struct C_800842A4 { u8 pad[0x20]; s32 x20; };

struct B_800842A4 { u8 pad[0xc]; C_800842A4 *c; };

struct A_800842A4 { u8 pad[0x8]; B_800842A4 *b; };

struct G_800842A4 { A_800842A4 *a; u8 pad[0x1c]; };

extern "C" {
extern RecoveredGlobal_80083CEC_lbl_8048E5D0 shadow_light_position;
void translate_current_matrix_ps(f32, f32, f32);
void rotate_current_matrix_x_ps(s32);
void push_identity_matrix_ps();
}

struct Stack_800836E8 {
    f32 sp8;
    f32 spC;
    GC_Mtx sp10;
};

extern "C" {
s32 is_split_screen();
s32 TCameraCtrl__sub_800689F4();
s32 rotate_matrix_y(int, void *);
s32 push_matrix();
s32 GXSetTevOp(s32, s32);
s32 GXSetTevOrder(s32, s32, s32, s32);
}
void calc_projection_screen_offset(f32 *arg0, f32 *arg1);
f32 calc_camera_fov_degrees(void);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
extern GC_Mtx *current_matrix;
extern const f32 lbl_805D93DC;
extern const f32 lbl_805D940C;
extern const f32 lbl_805D9414;
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);

extern s32 model_render_flags;

void TObjPlayer::setup_tev_stage() {
    if (is_split_screen() == 0) {
        GXSetTevOrder(1, 1, 1, 4);
        GXSetTevOp(1, 2);
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        TObjFish::set_global_param((s32)&shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void setup_particle_tev(s32 arg0) {
    if (is_split_screen() == 0) {
        GXSetTevOrder(1, 1, 1, 4);
        if (arg0 != 0) {
            GXSetTevOp(1, 0);
        } else {
            GXSetTevOp(1, 1);
        }
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        TObjFish::set_global_param((s32)&shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void load_projected_texture_matrix(f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_800836E8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800836E8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800836E8, sp10) == 0x8) ? 1 : -1];
    Stack_800836E8 stack;
    f32 temp_f31;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&stack.spC, &stack.sp8);
        push_matrix();
        temp_f31 = (f32) (0.0054931640625 * calc_camera_fov_degrees());
        if (TCameraCtrl__sub_800689F4() != 0) {
            C_MTXLightPerspective(stack.sp10, temp_f31, farg0, lbl_805D93DC, lbl_805D9414, (f32) (lbl_805D93DC - stack.spC), (f32) (lbl_805D93DC - stack.sp8));
        } else {
            C_MTXLightPerspective(stack.sp10, temp_f31, farg0, lbl_805D93DC, lbl_805D9414, lbl_805D93DC, lbl_805D93DC);
        }
        PSMTXConcat(stack.sp10, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}

void load_projection_tex_matrix(s32 rotation_y) {
    GC_Mtx sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&spC, &sp8);
        push_matrix();
        rotate_matrix_y(0, (void *)rotation_y);
        temp_f31 = (f32) (0.0054931640625 * calc_camera_fov_degrees());
        if (TCameraCtrl__sub_800689F4() != 0) {
            C_MTXLightPerspective(sp10, temp_f31, lbl_805D940C, lbl_805D93DC, lbl_805D9414, (f32) (lbl_805D93DC - spC), (f32) (lbl_805D93DC - sp8));
        } else {
            C_MTXLightPerspective(sp10, temp_f31, lbl_805D940C, lbl_805D93DC, lbl_805D9414, lbl_805D93DC, lbl_805D93DC);
        }
        PSMTXConcat(sp10, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}


struct Stack_80083914 {
    f32 sp8;
    u8 pad_C[0x4];
    GC_Mtx sp10;
};


extern "C" {
s32 is_split_screen();
s32 C_MTXLightFrustum(void *, f32, f32, f32, f32, f32, f32, f32, f32);
f32 rotate_matrix_by_node_angles(void *, int);
}
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
extern "C" {
extern s32 model_render_flags;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93DC;
extern const f32 lbl_805D9418;
extern const f32 lbl_805D941C;
extern const f32 lbl_805D9420;
extern const f32 lbl_805D9424;
f64 get_end_text_value__10TObjPlayerFv(f32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805D940C;
void TScene::apply_single_screen_state() {
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        model_render_flags &= 0xFFF7FFFF;
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
    }
}
#pragma push
#pragma opt_common_subs off
void render_projected_shadow_receiver(u8 *arg0, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_80083914, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80083914, sp10) == 0x8) ? 1 : -1];
    Stack_80083914 stack;
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        push_identity_matrix_ps();
        translate_current_matrix_ps(lbl_805D93D0, lbl_805D93D0, lbl_805D9418);
        rotate_current_matrix_x_ps(0x3800);
        translate_current_matrix_ps(-*(f32 *)((s8 *)&shadow_light_position.value + 0), -*(f32 *)((s8 *)&shadow_light_position.value + 4), -*(f32 *)((s8 *)&shadow_light_position.value + 8));
        translate_current_matrix_ps(*(f32 *)((s8 *)arg0 + 0), *(f32 *)((s8 *)arg0 + 4), *(f32 *)((s8 *)arg0 + 8));
        rotate_matrix_by_node_angles((void *)arg1, 1);
        stack.sp8 = lbl_805D93DC;
        C_MTXLightFrustum(stack.sp10, (f32) (-lbl_805D941C), lbl_805D941C, lbl_805D9420, (f32) (-lbl_805D9420), lbl_805D9424, lbl_805D93DC, lbl_805D93DC, lbl_805D93DC);
        PSMTXConcat(stack.sp10, *current_matrix, *current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
        GXSetTevOrder(1, 1, 1, 4);
        GXSetTevOp(1, 1);
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(((int) (1U)));
        set_ginja_post_texgen_count(((int) (1U)));
    }
}
}
#pragma pop

f32 calc_camera_fov_degrees(void) {
    f32 temp_f2;
    f32 temp_f31;
    f32 var_f1;
    s32 temp_r31;
    var_f1 = 11832.0f;
    if ((void *) camera_ctrl_instance != NULL) {
        temp_f2 = (f32) (*(s32 *)((s8 *)camera_ctrl_instance + 0x19C));
        temp_f2 *= 0.85f;
        temp_r31 = (s32) (temp_f2 * lbl_805D93DC);
        temp_f31 = cos_table_lookup(temp_r31);
        var_f1 = (f32) ((s32) (10430.38043493439 * get_end_text_value__10TObjPlayerFv((f32) ((sin_table_lookup(temp_r31) / temp_f31) / lbl_805D940C))) * 2);
    }
    return var_f1;
}


int lbl_805D4EE0;
extern "C" {
void TObjPlayer__sub_80083FB0(void);
int TObjPlayer__sub_80083F9C(void);
void *get_player_by_client_id(s32 i);
s32 get_main_phase();
s32 is_inactive__10TObjPlayerFv();
    extern unsigned char camera_capture_flags;
void TObjPlayer__sub_80084614(void);
void TObjPlayer__sub_8008463C(void);
void TObjPlayer__sub_80084764(void);
void TObjPlayer__sub_80084780(void);
void **release_texture_list();
extern s32 lbl_8048E5C8[];
void **TObjPlayer__sub_80083F04(void);
extern const f32 lbl_805D9434;
s32 is_in_shadow_range(u8 *arg0, f32 farg0);
s32 TObjPlayer__sub_800845F8(void);
void TObjPlayer__sub_80084500(void);
void set_texture_name(void *, void *, int, int);
s32 load_texture_list(void *);
void TObjPlayer__sub_80083F38(void);
void **TObjPlayer__sub_80084694(void);
s32 is_split_screen();
s32 TCameraCtrl__sub_80068EF0();
u8 get_display_copy_filter();
s32 Dolphin_GXSetCopyFilter(int, void *, int, void *);
s32 GXSetProjection(void *, int);
s32 pop_matrix();
void TObjPlayer__sub_80083FA4(void);
void C_MTXFrustum(void *, f32, f32, f32, f32, f32, f32);
f32 vec_squared_length(void *);
void normalize_vector(void *);
s32 push_matrix();
void TObjPlayer__sub_800847FC(void);
void TObjPlayer__sub_80084824(f32 farg0, f32 farg1);
void TObjPlayer__sub_80084834(s32 arg0);
void TObjPlayer__sub_80084840(f32 farg0, f32 farg1, f32 farg2);
s32 Dolphin_GXSetVtxDesc(s32, s32);
s32 GXClearVtxDesc();
s32 GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
s32 GXSetNumTexGens(s32);
s32 GXBegin(s32, s32, s32);
s32 GXSetNumChans(s32);
s32 GXSetTevOp(s32, s32);
s32 GXSetTevOrder(s32, s32, s32, s32);
}
extern u8 camera_capture_overlay_alpha;
void disable_camera_capture_overlay(void);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);
void init_capture_texture(s32 wide);
void set_ginja_draw_flags(s32 arg0);
void set_light_ambient_color(f32 r, f32 g, f32 b);
void submit_light0(s32 arg0, s32 arg1);
void load_gx_light_slot(s32 arg0);
extern s32 scene_projection_state[];
extern u8 *active_gx_render_mode;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93D8;
extern const f32 lbl_805D9404;
extern const f32 lbl_805D9408;
extern const f32 lbl_805D9430;
extern GXColor_80083B8C lbl_805E120C;
extern const f32 lbl_805D93C8;
extern const f32 lbl_805D9418;
extern const f32 lbl_805D941C;
extern const f32 lbl_805D9420;
extern const f32 lbl_805D9424;
extern const f32 lbl_805D9438;
extern const f32 lbl_805D943C;
extern GXColor_80083B8C lbl_805E1208;
void capture_viewport_texture(void);
void setup_blended_textured_draw(void);
extern const f32 lbl_805D9440;
extern const f32 lbl_805D9444;

void TObjPlayer::draw_if_all_ready() {
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        TObjFish::set_global_param((s32)lbl_8048E5C8);
        load_list_texture(0, 0, 0, 1);
    }
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_80083CEC_lbl_8048E5D0_size[sizeof(RecoveredGlobal_80083CEC_lbl_8048E5D0) == 0xC ? 1 : -1];

void end_shadow_map_pass() {
    u8 *temp_r31;
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0) && ((u32) camera_ctrl_instance != 0U)) {
        pop_matrix();
        pop_matrix();
        GXColor_80083B8C c = lbl_805E120C;
        Dolphin_GXSetCopyFilter((int) (0U), NULL, (int) (0U), NULL);
        set_cull_none();
        GXSetCopyClear(c, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x100, 0x100);
        GXSetTexCopyDst(0x100, 0x100, 2, 0);
        GXCopyTex((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)(((u8 **)lbl_8048E5C8)[0]) + 8)) + 0xC)) + 0x20)), 1);
        GXPixModeSync();
        temp_r31 = active_gx_render_mode;
        Dolphin_GXSetCopyFilter((int) (*(u8 *)((s8 *)temp_r31 + 0x19)), temp_r31 + 0x1A, (int) (get_display_copy_filter()), temp_r31 + 0x32);
        GXSetViewport(lbl_805D93D0, lbl_805D93D0, lbl_805D9404, lbl_805D9408, lbl_805D93D0, lbl_805D93D8);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        GXSetProjection(scene_projection_state, 0);
        set_light_ambient_color(lbl_805D9430, lbl_805D9430, lbl_805D9430);
        submit_light0(0, 1);
        load_gx_light_slot(0);
        set_ginja_draw_flags(0);
        TCameraCtrl__sub_80068EF0();
    }
}

s32 is_in_shadow_range(u8 *arg0, f32 farg0) {
    if (((u32) camera_ctrl_instance != 0U) && (((farg0 * farg0) + horizontal_distance_squared((const Vec *)arg0, (const Vec *)&shadow_light_position.value)) <= lbl_805D9434)) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
#define VIEW ((View_80083D54 *)camera_ctrl_instance)
#define LIGHT (*(Vec_80083D54 *)&shadow_light_position)
void begin_shadow_map_pass(void) {
    Mtx44_80083D54 proj;
    Vec_80083D54 d;
    f32 t;
    f32 r;
    if (is_split_screen() != 0) {
        return;
    }
    TObjPlayer__sub_80083FA4();
    if (TObjPlayer::check_all_players_ready() == 0) {
        return;
    }
    TCameraCtrl::restore_full_screen_view();
    if (camera_ctrl_instance == 0) {
        return;
    }
    d.x = VIEW->target.x - VIEW->pos.x;
    d.y = VIEW->target.y - VIEW->pos.y;
    d.z = VIEW->target.z - VIEW->pos.z;
    if (lbl_805D93D0 != vec_squared_length(&d)) {
        normalize_vector(&d);
        LIGHT.x = VIEW->pos.x + lbl_805D9438 * (lbl_805D93C8 * d.x);
        LIGHT.y = VIEW->pos.y;
        LIGHT.z = VIEW->pos.z + lbl_805D9438 * (lbl_805D93C8 * d.z);
    } else {
        LIGHT.x = lbl_805D93D0;
        LIGHT.y = lbl_805D93D0;
        LIGHT.z = lbl_805D93D0;
    }
    push_matrix();
    GXSetViewport(lbl_805D93D0, lbl_805D93D0, lbl_805D93C8, lbl_805D93C8, lbl_805D93D0, lbl_805D93D8);
    GXSetScissor(1, 1, 0xFE, 0xFE);
    t = lbl_805D941C;
    r = lbl_805D9420;
    C_MTXFrustum(&proj, t, -t, r, -r, lbl_805D9424, lbl_805D943C);
    GXSetProjection(&proj, 0);
    set_light_ambient_color(lbl_805D93D8, lbl_805D93D8, lbl_805D93D8);
    submit_light0(0, 0);
    load_gx_light_slot(0);
    push_identity_matrix_ps();
    translate_current_matrix_ps(lbl_805D93D0, lbl_805D93D0, lbl_805D9418);
    rotate_current_matrix_x_ps(0x3800);
    translate_current_matrix_ps(-LIGHT.x, -LIGHT.y, -LIGHT.z);
    set_ginja_draw_flags(2);
}
#pragma pop

void **TObjPlayer__sub_80083F04(void) {
    void **var_r3;
    u8 *var_r4;
    void **phi_r3;
    var_r3 = (void **)(&lbl_8048E5C8);
    var_r4 = (u8 *)((*(u8 * *)&lbl_8048E5C8));
    var_r3 = (void **)(&lbl_8048E5C8);
    phi_r3 = (void **)(&lbl_8048E5C8);
    if ((u32) *(u32 *)((s8 *)var_r4 + 8) != 0U) {
        phi_r3 = (void **)((void **)(release_texture_list()));
    }
    return phi_r3;
}

void TObjPlayer__sub_80083F38(void) {
    Rect_80083F38 r;
    ((TObjPlayer *)(&r))->set_render_rect(0, 2, 0x100, 0x100);
    set_texture_name((void *)((s32 *)&lbl_8048E5C8)[0], &r, 0x2EE1, 0x08800000);
    load_texture_list(((s32 *)&lbl_8048E5C8));
    lbl_805D4EE0 = 0;
}

int TObjPlayer__sub_80083F9C(void) {  return lbl_805D4EE0; }

void TObjPlayer__sub_80083FA4(void) { lbl_805D4EE0 = 1; }
void TObjPlayer__sub_80083FB0(void) { lbl_805D4EE0 = 0; }
s32 TObjPlayer::check_all_players_ready() {
    s32 flag;
    s32 counter;
    flag = 1;
    if (((s32)TObjPlayer__sub_80083F9C()) == 0) {
        return 0;
    }
    if (get_main_phase() == 0xF) {
        counter = 0;
        do {
            if ((get_player_by_client_id(counter) != 0U) && (is_inactive__10TObjPlayerFv() == 0)) {
                flag = 0;
            }
            counter += 1;
        } while (counter < 4);
    }
    return flag;
}

void TObjPlayer::draw_screen_quad(u32 arg0, s32 arg1, f32 farg0) {
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 s0;
    f32 s1;
    u32 temp_r31;
    void *temp_r4;
    void *temp_r4_2;
    TObjFish::set_global_param((s32)((s32 *)&shared_capture_texture_list));
    if (arg1 != 0) {
        temp_r4 = shared_capture_texture_list.a->b->c;
        *(s32 *)((s8 *)temp_r4 + 0x10) = 0x100;
        *(s32 *)((s8 *)temp_r4 + 0x14) = 0xC0;
    }
    load_list_texture(0, 0, 0, 0);
    set_default_alpha_blend();
    TObjPlayer::load_screen_space_matrix();
    setup_blended_textured_draw();
    GXSetNumTexGens(1);
    GXSetNumChans(1);
    TObjPlayer::set_tex_coord_gen(0, 1, 4, 0x3C);
    GXSetTevOp(0, 1);
    GXSetTevOrder(0, 0, 0, 4);
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xB, 1);
    Dolphin_GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(4, 0xD, 1, 4, 0);
    GXBegin(0x80, 4, 4);
    temp_f31 = -farg0 * lbl_805D9440;
    TObjPlayer__sub_80084840(temp_f31, temp_f31, lbl_805D9440);
    temp_r31 = (arg0 << 8) | (arg0 >> 24);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D0, lbl_805D93D0);
    s0 = lbl_805D9404 + farg0;
    temp_f30 = s0 * lbl_805D9440;
    TObjPlayer__sub_80084840(temp_f30, temp_f31, lbl_805D9440);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D8, lbl_805D93D0);
    s1 = lbl_805D9408 + farg0;
    temp_f30_2 = s1 * lbl_805D9440;
    TObjPlayer__sub_80084840(temp_f30, temp_f30_2, lbl_805D9440);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D8, lbl_805D93D8);
    TObjPlayer__sub_80084840(temp_f31, temp_f30_2, lbl_805D9440);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D0, lbl_805D93D8);
    TObjPlayer__sub_800847FC();
    set_default_alpha_blend();
    if (arg1 != 0) {
        temp_r4_2 = shared_capture_texture_list.a->b->c;
        *(s32 *)((s8 *)temp_r4_2 + 0x10) = 0x280;
        *(s32 *)((s8 *)temp_r4_2 + 0x14) = 0x1E0;
    }
}

void TObjPlayer::draw_textured_screen_quad(u32 arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    u32 temp_r31;
    void *temp_r4;
    void *temp_r4_2;
    TObjFish::set_global_param((s32)((s32 *)&shared_capture_texture_list));
    if (arg3 != 0) {
        temp_r4 = (*(G_800842A4 *)&shared_capture_texture_list).a->b->c;
        *(s32 *)((s8 *)temp_r4 + 0x10) = 0x100;
        *(s32 *)((s8 *)temp_r4 + 0x14) = 0xC0;
    }
    load_list_texture(0, 0, 0, 0);
    set_default_alpha_blend();
    TObjPlayer::load_screen_space_matrix();
    setup_blended_textured_draw();
    GXSetNumTexGens(1);
    GXSetNumChans(1);
    TObjPlayer::set_tex_coord_gen(0, 1, 4, 0x3C);
    GXSetTevOp(0, 1);
    GXSetTevOrder(0, 0, 0, 4);
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xB, 1);
    Dolphin_GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(4, 0xD, 1, 4, 0);
    GXBegin(0x80, 4, 4);
    TObjPlayer__sub_80084840(arg1[0] * lbl_805D9444, arg1[1] * lbl_805D9444, lbl_805D9444);
    temp_r31 = (arg0 << 8) | (arg0 >> 24);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D0, lbl_805D93D0);
    TObjPlayer__sub_80084840(lbl_805D9444 * (arg1[0] + arg2[0]), arg1[1] * lbl_805D9444, lbl_805D9444);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D8, lbl_805D93D0);
    TObjPlayer__sub_80084840(lbl_805D9444 * (arg1[0] + arg2[0]), lbl_805D9444 * (arg1[1] + arg2[1]), lbl_805D9444);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D8, lbl_805D93D8);
    TObjPlayer__sub_80084840(arg1[0] * lbl_805D9444, lbl_805D9444 * (arg1[1] + arg2[1]), lbl_805D9444);
    TObjPlayer__sub_80084834(temp_r31);
    TObjPlayer__sub_80084824(lbl_805D93D0, lbl_805D93D8);
    TObjPlayer__sub_800847FC();
    set_default_alpha_blend();
    if (arg3 != 0) {
        temp_r4_2 = (*(G_800842A4 *)&shared_capture_texture_list).a->b->c;
        *(s32 *)((s8 *)temp_r4_2 + 0x10) = 0x280;
        *(s32 *)((s8 *)temp_r4_2 + 0x14) = 0x1E0;
    }
}

void TObjPlayer__sub_80084500(void) {
    TObjFish::set_global_param((s32)((s32 *)(((u8 *)&shared_capture_texture_list))));
    load_list_texture(0, 0, 0, 0);
}

void capture_viewport_texture(void) {
    if (!(camera_capture_flags & 4)) {
        GXColor_80083B8C c = lbl_805E1208;
        GXSetCopyClear(c, 0xFFFFFF);
        GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
        GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
        if (camera_capture_flags & 8) {
            GXCopyTex((void *)shared_capture_texture_list.a->b->c->x20, 1);
        } else {
            GXCopyTex((void *)shared_capture_texture_list.a->b->c->x20, 0);
        }
        GXPixModeSync();
    }
}

s32 TObjPlayer__sub_800845F8(void) {
    return shared_capture_texture_list.a->b->c->x20;
}

void TObjPlayer__sub_80084614(void) { camera_capture_flags = 0; TObjPlayer__sub_80084694(); }
void TObjPlayer__sub_8008463C(void) { camera_capture_flags = 0; init_capture_texture((s32)((void*)0)); }
void TObjPlayer::reset_movie_state() { camera_capture_flags = 0; init_capture_texture((s32)((void*)1)); }

void **TObjPlayer__sub_80084694(void) {
    void **var_r3;
    var_r3 = (void **)&shared_capture_texture_list;
    if ((*(G_80084694 *)&shared_capture_texture_list).a->f8 != 0) {
        var_r3 = release_texture_list();
    }
    return var_r3;
}

void init_capture_texture(s32 wide) {
    Rect_800846C8 r;
    s32 mode;
    u16 w;
    u16 h;
    if (wide != 0) {
        mode = 6;
        w = 640;
        h = 480;
    } else {
        mode = 4;
        w = 640;
        h = 480;
    }
    ((TObjPlayer *)(&r))->set_render_rect(0, mode, w, h);
    set_texture_name((*(G_800846C8 *)&shared_capture_texture_list).a, &r, 0x2EE0, 0x08800000);
    load_texture_list(&shared_capture_texture_list);
}

void TObjPlayer__sub_80084744(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) & 0xfffffffb); }
void TObjPlayer__sub_80084754(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) | 0x4); }
void TObjPlayer__sub_80084764(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) & 0xffffffef); }
s32 TObjPlayer::get_camera_flag() {
    return ((u8) (*(u8 *)&camera_capture_flags) >> 4U) & 1;
}
void TObjPlayer__sub_80084780(void) { (*(u8 *)&camera_capture_flags) = ((*(u8 *)&camera_capture_flags) | 0x1); }
void disable_camera_capture_overlay(void) {
  int temp = (*(u8 *)&camera_capture_flags);
  (*(u8 *)&camera_capture_flags) = temp & (~2);
  camera_capture_overlay_alpha = 0x8F;
}


extern "C" {
f64 atan();
s32 GXSetTexCoordGen2(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0, s32 a4 = 0, s32 a5 = 0);
    extern unsigned char camera_capture_flags;
extern u8 camera_capture_flags;
s32 TObjPlayer__sub_800847A8(void) {
    if ((camera_capture_flags & 2) && (camera_capture_flags & 1)) {
        return 1;
    }
    return 0;
}
unsigned char TObjPlayer__sub_800847CC(void) {  return camera_capture_flags; }
void TObjPlayer::set_tex_coord_gen(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    GXSetTexCoordGen2(arg0, arg1, arg2, arg3, 0, 0x7D);
}
void TObjPlayer__sub_800847FC(void) {  }
f32 TObjPlayer::get_end_text_value() {
    return (f32) atan();
}
void TObjPlayer__sub_80084824(f32 farg0, f32 farg1) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
}

void TObjPlayer__sub_80084834(s32 arg0) {
    *(s32 *)0xCC008000 = arg0;
}

void TObjPlayer__sub_80084840(f32 farg0, f32 farg1, f32 farg2) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
    *(f32 *)0xCC008000 = farg2;
}

int TObjPlayer::is_inactive() { return this->m_cfc == 0; }

}
