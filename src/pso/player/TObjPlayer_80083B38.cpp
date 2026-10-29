#include "types.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/system/main_loop.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/render/render_util.h"

struct RecoveredGlobal_80083CEC_lbl_8048E5D0 {
    s32 value;
    u8 remaining[0x8];
};

struct C_800845F8 { u8 pad[0x20]; s32 x20; };

struct B_800845F8 { u8 pad[0xc]; C_800845F8 *c; };

struct A_800845F8 { u8 pad[0x8]; B_800845F8 *b; };

struct G_800845F8 { A_800845F8 *a; u8 pad[0x1c]; };

struct Rect_80083F38 { u8 data[0x20]; };

struct Rect_800846C8 { u8 data[0x20]; };

struct G_800846C8 { void *a; u8 pad[0x1c]; };

struct A_80084694 { u8 pad[0x8]; u32 f8; };

struct G_80084694 { A_80084694 *a; u8 pad[0x1c]; };

struct GXColor_80083B8C { u8 r, g, b, a; };

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

extern int lbl_805D4EE0;
extern "C" {
void TObjPlayer__sub_80083FB0(void);
int TObjPlayer__sub_80083F9C(void);
void *get_player_by_client_id(s32 i);
s32 get_main_phase();
s32 is_inactive__10TObjPlayerFv();
    extern unsigned char camera_capture_flags;
void TObjPlayer__sub_80084614(void);
void TObjPlayer__sub_8008463C(void);
void TObjPlayer__sub_80084744(void);
void TObjPlayer__sub_80084754(void);
void TObjPlayer__sub_80084764(void);
void TObjPlayer__sub_80084780(void);
void **release_texture_list();
extern s32 lbl_8048E5C8[];
void **TObjPlayer__sub_80083F04(void);
extern RecoveredGlobal_80083CEC_lbl_8048E5D0 shadow_light_position;
extern u32 camera_ctrl_instance;
extern const f32 lbl_805D9434;
s32 is_in_shadow_range(u8 *arg0, f32 farg0);
extern G_800845F8 shared_capture_texture_list;
s32 TObjPlayer__sub_800845F8(void);
void TObjPlayer__sub_80084500(void);
void set_texture_name(void *, void *, int, int);
s32 load_texture_list(void *);
void TObjPlayer__sub_80083F38(void);
void **TObjPlayer__sub_80084694(void);
s32 is_split_screen();
s32 TCameraCtrl__sub_80068EF0();
u8 TObjBoss2Tunnel__sub_8036EF44();
s32 GXPixModeSync();
s32 GXSetTexCopySrc(int, int, int, int);
s32 GXSetTexCopyDst(int, int, int, int);
void GXSetCopyClear(GXColor_80083B8C, u32);
s32 Dolphin_GXSetCopyFilter(int, void *, int, void *);
s32 GXCopyTex(void *, int);
s32 GXSetProjection(void *, int);
s32 GXSetViewport(f32, f32, f32, f32, f32, f32);
s32 GXSetScissor(int, int, int, int);
s32 pop_matrix();
void TObjPlayer__sub_80083FA4(void);
void C_MTXFrustum(void *, f32, f32, f32, f32, f32, f32);
f32 vec_squared_length(void *);
void normalize_vector(void *);
s32 push_matrix();
void translate_current_matrix_ps(f32, f32, f32);
void rotate_current_matrix_x_ps(s32);
void push_identity_matrix_ps();
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
        Dolphin_GXSetCopyFilter((int) (*(u8 *)((s8 *)temp_r31 + 0x19)), temp_r31 + 0x1A, (int) (TObjBoss2Tunnel__sub_8036EF44()), temp_r31 + 0x32);
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
