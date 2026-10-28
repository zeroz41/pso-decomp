#include "types.h"
#include "pso/player/TObjPlayer_8033E910.h"
#include "pso/ui/TAdMcCheckGC.h"
#include "pso/misc/TUnk_804EFA88.h"
#include "pso/render/depth_buffer.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TParticleCtrl_80327D30.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct Item_8033EC40 { u8 b[0x24]; };

struct O_8033EC40 { u8 pad[0x1C]; Item_8033EC40 *items; s32 n; };

struct Item_8033EB4C {
    u8 a[0xC];
    u8 b[0xC];
    s32 p18;
    s32 p1C;
    u16 scene;
    u8 effect_kind;  // indirect effect kind
    u8 pad23;
};

struct O_8033EB4C { u8 pad[0x1C]; Item_8033EB4C *items; s32 n; };

extern "C" {
s32 TCameraCtrl__sub_800689F4();
s32 PSMTXConcat(void *, void *, void *);
s32 C_MTXLightPerspective(void *, f32, f32, f32, f32, f32, f32);
s32 GXSetTevOp(int, int);
s32 GXSetTevOrder(int, int, int, int);
s32 push_matrix();
s32 pop_matrix();
void queue_destruction__7TObjectFv(void *);
s32 rotate_matrix_by_node_angles(void *, int);
s32 post_translate_matrix(void *);
int set_global_param__8TObjFishFl(void);
void draw_ginja_object(void *child);
void set_material_alpha_compare_reference(s32 reference);
}
void calc_projection_screen_offset(f32 *arg0, f32 *arg1);
f32 calc_camera_fov_degrees(void);
void set_tex_coord_gen2(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
extern const f64 lbl_804783B0;
extern u32 camera_ctrl_instance;
extern s32 current_matrix;
extern const f32 lbl_805DFAC8;
extern const f32 lbl_805DFACC;
extern const f32 lbl_805DFAD0;
void play_indirect_effect_recipe(u8 arg0, u16 sampler, s32 second);
char *get_shared_capture_texture_list(void);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);

void init_particle_effect__10TObjPlayerFv(void) { get_shared_capture_texture_list(); set_global_param__8TObjFishFl(); load_list_texture(0, 0, 0, 2); }

    extern int model_render_flags;
void reset_effects__10TObjPlayerFv(void) { set_ginja_post_tev_stage_count((s32)((void*)0)); set_ginja_post_texgen_count((s32)((void*)0)); TObjPlayer::set_global_effect_state((s32)((void*)0)); model_render_flags = (model_render_flags & 0xfff7ffff); }

void setup_projection_tex_matrix__10TObjPlayerFv(void) {
    u8 sp10[0x30];
    f32 spC;
    f32 sp8;
    f32 temp_f31;
    if ((u32) camera_ctrl_instance != 0U) {
        push_matrix();
        calc_projection_screen_offset(&spC, &sp8);
        temp_f31 = (f32) (lbl_804783B0 * calc_camera_fov_degrees());
        if (TCameraCtrl__sub_800689F4() != 0) {
            C_MTXLightPerspective(&sp10, temp_f31, lbl_805DFAC8, lbl_805DFACC, lbl_805DFAD0, (f32) (lbl_805DFACC - spC), (f32) (lbl_805DFACC - sp8));
        } else {
            C_MTXLightPerspective(&sp10, temp_f31, lbl_805DFAC8, lbl_805DFACC, lbl_805DFAD0, lbl_805DFACC, lbl_805DFACC);
        }
        PSMTXConcat(&sp10, (void *)current_matrix, (void *)current_matrix);
        load_current_tex_matrix(2);
        pop_matrix();
        load_current_pos_matrix(2);
        GXSetTevOrder(1, 1, 2, 4);
        GXSetTevOp(1, 1);
        set_tex_coord_gen2(1, 0, 0, 0x24);
        (*(s32 *)&model_render_flags) |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
        TObjPlayer::set_global_effect_state((s32)((void*)(1)));
    }
}

void TObjPlayer::free_indexed_entry(s32 _w1) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)&this->m_20);
    if (temp_r0 < 0x10) {
        ((TObjPlayer *)(*(s32 *)((s8 *)this + 0x1C) + (temp_r0 * 0x24)))->copy_node_record(_w1);
    }
}
void TObjPlayer::copy_node_record(s32 arg1) {
    s32 arg0 = (s32)this;
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    *(ByteBlock_C *)(arg0 + 0xC) = *(const ByteBlock_C *)(arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
    *(u16 *)((s8 *)arg0 + 0x20) = (u16) *(u16 *)((s8 *)arg1 + 0x20);
    *(u8 *)((s8 *)arg0 + 0x22) = (u8) *(u8 *)((s8 *)arg1 + 0x22);
    *(u8 *)((s8 *)arg0 + 0x23) = (u8) *(u8 *)((s8 *)arg1 + 0x23);
}

void TUnk_804EFA88::render() {
    s32 i;
    for (i = 0; i < ((O_8033EB4C *)this)->n; i++) {
        request_indirect_effect(((O_8033EB4C *)this)->items[i].effect_kind);
        set_material_alpha_compare_reference(((O_8033EB4C *)this)->items[i].scene);
        set_depth_buffer_settings_1();
        set_depth_buffer_settings_id(3);
        push_matrix();
        post_translate_matrix(((O_8033EB4C *)this)->items[i].a);
        rotate_matrix_by_node_angles(((O_8033EB4C *)this)->items[i].b, 1);
        play_indirect_effect_recipe(((O_8033EB4C *)this)->items[i].effect_kind, 1, 1);
        ((void (*)(void *))init_particle_effect__10TObjPlayerFv)(this);
        ((void (*)(void *))setup_projection_tex_matrix__10TObjPlayerFv)(this);
        ((void (*)(s32))set_global_param__8TObjFishFl)(((O_8033EB4C *)this)->items[i].p18);
        draw_ginja_object((void *)(((O_8033EB4C *)this)->items[i].p1C));
        pop_matrix();
        reset_indirect_tev(1);
        ((void (*)(void *))reset_effects__10TObjPlayerFv)(this);
    }
}

void TUnk_804EFA88::run_task() {
    O_8033EC40 *arg0 = (O_8033EC40 *)this;
    s32 i;
    if (arg0->items == 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    for (i = 0; i < this->m_20; i++) {
        TLobby__sub_8033EE38(&arg0->items[i]);
    }
    this->m_20 = 0;
}
