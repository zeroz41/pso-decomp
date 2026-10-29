#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/misc/obj_band.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/MaterialAlphaCompare.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TPhotonYoulla.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3528 = "TPhotonYoulla";
int lbl_805D5D60;
}


struct Color_801AE744 { f32 a, r, g, b; };

struct Vec_801AE744 { f32 x, y, z; };

struct Self_801AE744 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec_801AE744 pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x184 - 0x64];
    Color_801AE744 color;
    u8 pad4[0x1A0 - 0x194];
    s32 started;
};

extern "C" {
s32 clear_render_context__10TObjPlayerFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern Color_801AE744 saved_model_draw_color;
extern Color_801AE744 model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void *find_entity_by_id(u16 id);
void sub_801AE72C__13TPhotonYoullaFv(void *, u8);
s32 spawn_photon_blast_attachment_effects(void *, s32);
extern u8 photon_blast_youlla_params[];
extern s32 __vt__13TPhotonYoulla[];
extern const char *lbl_805D3528;
extern u8 *photon_blast_shared_resource;
s32 advance_animation_playback(void *);
void __dl__7TObjectFPv(void *);

extern const f32 lbl_805DC264;
extern const f32 lbl_805DC268;
extern const f32 lbl_805DC26C;
extern const f32 lbl_805DC270;
extern const f32 lbl_805DC274;

void TPhotonYoulla::render() {
    Self_801AE744 *self = (Self_801AE744 *)this;
    if (*(s32 *)&this->m_1a0 != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix(&self->pos);
        rotate_matrix_y(0, this->rotation_y);
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        TObjPlayer::set_global_flag();
        set_material_alpha_compare_reference(0);
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TUnk_804C3248 *)self)->set_photon_blast_joint_callback();
        ((TObjMotion *)self)->draw();
        TObjPlayer::clear_global_state();
        set_material_alpha_compare_reference(0xBF);
        clear_render_context__10TObjPlayerFv(self);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonYoulla::run_task() {
    f32 temp_f1;

    if (((s32) *(s32 *)&this->m_1a4 == 0x32) && ((s32) *(s32 *)&this->m_1a0 == 0)) {
        *(s32 *)&this->m_1a0 = 1;
    }
    if ((lbl_805DC264 == (f32) *(s32 *)&this->m_1a4) && ((s16) this->requested_action == 1)) {
        spawn_photon_blast_attachment_effects(this, 6);
        *(s32 *)&this->m_1a4 = 0;
        set_field_b8(0);
    }
    *(s16 *)&this->m_194 = (s16) this->requested_action;
    advance_animation_playback(this);
    update_photon_blast_attachments();
    *(s16 *)((s8 *)this + 0x14C) = (s16) (*(s16 *)((s8 *)this + 0x14C) + 0xF);
    *(s16 *)((s8 *)this + 0x14C) = (s16) (u8) *(s16 *)((s8 *)this + 0x14C);
    *(s32 *)&this->m_1a4 = (s32) (*(s32 *)&this->m_1a4 + 1);
    if ((f32) *(s32 *)&this->m_1a4 > lbl_805DC268) {
        temp_f1 = *(f32 *)&this->m_184;
        if (temp_f1 > lbl_805DC26C) {
            *(f32 *)&this->m_184 = (f32) (temp_f1 - lbl_805DC270);
        }
    }
    if (lbl_805DC274 == (f32) *(s32 *)&this->m_1a4) {
        queue_destruction__7TObjectFv(this);
    }
}

void *__dt__13TPhotonYoullaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TPhotonYoulla;
        ((TUnk_804C3248 *)arg0)->free_photon();
        destroy_photon_motion_object(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

    extern int lbl_805D5D60;

u8 *TPhotonYoulla__ct(TPhotonYoulla *photon_youlla, u8 *arg1) {
    u8 *temp_r3;
    photon_base_ct(photon_youlla);
    *(s32 **)((s8 *)photon_youlla + 0x18) = __vt__13TPhotonYoulla;
    *(s32 *)((s8 *)photon_youlla + 0) = (s32) ((s32)lbl_805D3528);
    *(s32 *)((s8 *)photon_youlla + 0x138) = 5;
    VecCopy((Vec *)((u8 *)photon_youlla + 0x38), (const Vec *)(arg1));
    photon_youlla->m_17c = (u16) *(u16 *)((s8 *)arg1 + 0xC);
    *(u8 **)((s8 *)photon_youlla + 0x180) = (u8 *)find_entity_by_id(photon_youlla->m_17c);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)photon_youlla + 0x180));
    if (temp_r3 != NULL) {
        photon_youlla->rotation_y = (s32) *(s32 *)((s8 *)temp_r3 + 0x60);
    }
    *(s32 *)((s8 *)photon_youlla + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0xB8);
    photon_youlla->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0xBC);
    ((TObjMotion *)photon_youlla)->set_field_d8((s32) photon_blast_youlla_params);
    ((TObjMotion *)photon_youlla)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    photon_youlla->requested_action = 1;
    ((TObjMotion *)photon_youlla)->set_animation(photon_youlla->requested_action);
    ((TObjMotion *)photon_youlla)->set_field_b8(photon_youlla->requested_action);
    photon_youlla->m_194 = 1;
    photon_youlla->m_198 = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    photon_youlla->m_19c = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    photon_youlla->m_1a0 = 0;
    sub_801AE72C__13TPhotonYoullaFv(photon_youlla, *(u8 *)((s8 *)arg1 + 0x1C));
    photon_youlla->m_1a4 = 0;
    if ((s32) photon_youlla->m_198 == 0) {
        ((TObjMotion *)photon_youlla)->set_field_b8(0);
        photon_youlla->m_198 = 1;
        photon_youlla->m_194 = 0;
        photon_youlla->m_1a0 = 1;
        spawn_photon_blast_attachment_effects(photon_youlla, 6);
    } else {
        spawn_photon_blast_opening_effects(6, (photon_youlla->m_17c));
    }
    return (u8 *)photon_youlla;
}

void TObjPlayer__sub_801AEB74(void) { lbl_805D5D60 = 0; }

void TObjPlayer__sub_801AEB80(void) {  }

}
