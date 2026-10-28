#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TPhotonMagicSquare.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/misc/TPhotonMagicSquare_801ACE1C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/misc/TPhotonMagicSquare.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
struct Color_801ACE1C { f32 a, r, g, b; };

struct Vec_801ACE1C { f32 x, y, z; };

struct Self_801ACE1C {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x34 - 0x28];
    s32 f34;
    u8 pad2[0x60 - 0x38];
    s32 f60;
    u8 pad3[0x68 - 0x64];
    Vec_801ACE1C v68;
    u8 pad4[0x90 - 0x74];
    s32 f90;
    u8 pad5[0x9C - 0x94];
    f32 f9C;
    Color_801ACE1C color;
    u32 fB0;
    u8 pad6[0xB8 - 0xB4];
    Vec_801ACE1C vB8;
    u8 pad7[0xCC - 0xC4];
    u32 fCC;
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern Color_801ACE1C chunk_material_color_half_alpha_f32;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void TPhotonMagicSquare::render() {
    Self_801ACE1C *self = (Self_801ACE1C *)this;
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&self->vB8);
    rotate_matrix_y(0, this->rotation_y);
    TObjFish::set_global_param(this->texlist);
    scale_current_matrix(&self->v68);
    Color_801ACE1C saved = self->color;
    if ((this->m_b0 % this->m_cc) == 0) {
        self->color.r = (0.5f);
        self->color.g = (0.5f);
        self->color.b = (0.5f);
    }
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    if (self->color.a > 1.0f) {
        self->color.a = 1.0f;
    }
    set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
    TObjPlayer::set_global_flag();
    draw_model_motion((void *)self->f34, (void *)this->m_90, self->f9C);
    TObjPlayer::clear_global_state();
    set_constant_material((const NJS_ARGB *)(((f32 *)&chunk_material_color_half_alpha_f32)));
    model_render_flags = saved_model_render_flags;
    copy_argb((NJS_ARGB *)&self->color, (NJS_ARGB *)&saved);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

struct Self_801ACF24 {
    u8 pad0[0x68];
    f32 f68;
    u8 pad6c[4];
    f32 f70;
    u8 pad74[0x94 - 0x74];
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    u8 padA4[0xb0 - 0xa4];
    u32 fB0;
    s32 fB4;
    u8 padB8[0xc4 - 0xb8];
    u32 fC4;
    f32 fC8;
};

#pragma push
#pragma fp_contract on
void TPhotonMagicSquare::run_task() {
    Self_801ACF24 *self = (Self_801ACF24 *)this;
    if (this->m_b0 > this->m_c4) {
        this->m_b4 = 1;
    }
    switch (this->m_b4) {
    case 0:
        if (self->fA0 < (1.0f)) {
            self->fA0 = (2.0f) * self->fC8 + self->fA0;
        }
        if (this->scale.x < (1.0f)) {
            this->scale.x = (2.0f) * self->fC8 + this->scale.x;
            self->f70 = (2.0f) * self->fC8 + self->f70;
        }
        break;
    case 1:
        if (self->fA0 > (0.0f)) {
            self->fA0 = self->fA0 - self->fC8;
        }
        if (this->scale.x > (0.0f)) {
            this->scale.x = this->scale.x - self->fC8;
            self->f70 = self->f70 - self->fC8;
        }
        if ((f32)this->m_b0 > (f32)this->m_c4 + (1.0f) / self->fC8) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        break;
    }
    this->m_b0++;
    if (self->f9C < self->f94) {
        self->f9C = self->f9C + this->m_98;
    } else {
        self->f9C = (0.0f);
    }
}
#pragma pop

}

struct RecoveredGlobal_801AD0F0_TPhotonMagicSquare__data_804C3940 { s32 value; u8 remaining[0x5C]; };

struct RecoveredGlobal_801AD0F0___vt__18TPhotonMagicSquare { s32 value; u8 remaining[0x34]; };

struct RecoveredGlobal_801AD218_TPhotonMagicSquare__data_804C3940 { s32 value; u8 remaining[0x5C]; };

struct RecoveredGlobal_801AD218___vt__18TPhotonMagicSquare { s32 value; u8 remaining[0x34]; };

struct RecoveredGlobal_801AD330_TPhotonMagicSquare__data_804C3940 { s32 value; u8 remaining[0x5C]; };

struct RecoveredGlobal_801AD330___vt__18TPhotonMagicSquare { s32 value; u8 remaining[0x34]; };

extern "C" {
s32 __ct__13TUnk_804B9870FP7TObject(void *);
extern RecoveredGlobal_801AD0F0_TPhotonMagicSquare__data_804C3940 TPhotonMagicSquare__color_palette;
extern RecoveredGlobal_801AD0F0___vt__18TPhotonMagicSquare __vt__18TPhotonMagicSquare;
extern s32 TPhotonMagicSquare__data_805D3508;
extern u8 *photon_blast_shared_resource;
s32 find_entity_by_id(void *);
s32 play_sound_effect(int, int, int, int);
void __dl__7TObjectFPv(void *);

}
TPhotonMagicSquare::~TPhotonMagicSquare() {

}
extern "C" {

u8 *TPhotonMagicSquare__ct(u8 *photon_magic_square, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    __ct__13TUnk_804B9870FP7TObject(photon_magic_square);
    *(s32 **)((s8 *)photon_magic_square + 0x18) = &__vt__18TPhotonMagicSquare.value;
    *(s32 *)((s8 *)photon_magic_square + 0) = (s32) TPhotonMagicSquare__data_805D3508;
    *(s32 *)((s8 *)photon_magic_square + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x28);
    *(u8 **)((s8 *)photon_magic_square + 0x90) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x430)) + 0x14));
    *(f32 *)((s8 *)photon_magic_square + 0x9C) = (f32) (0.0f);
    *(f32 *)((s8 *)photon_magic_square + 0x94) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)photon_magic_square + 0x90)) + 4) - (1.0f));
    ((TPhotonMagicSquare *)photon_magic_square)->m_98 = (f32) (0.1f);
    ((TPhotonMagicSquare *)photon_magic_square)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x2C);
    ((TPhotonMagicSquare *)photon_magic_square)->scale.x = (f32) (0.0f);
    ((TPhotonMagicSquare *)photon_magic_square)->scale.y = (f32) (0.0f);
    *(f32 *)((s8 *)photon_magic_square + 0x70) = (f32) (0.0f);
    copy_argb((NJS_ARGB *)(photon_magic_square + 0xA0), (NJS_ARGB *)((u8 *)&TPhotonMagicSquare__color_palette.value + (arg2 * 0x10)));
    VecCopy((Vec *)(photon_magic_square + 0xB8), (const Vec *)(arg3));
    ((TPhotonMagicSquare *)photon_magic_square)->m_b0 = 0;
    ((TPhotonMagicSquare *)photon_magic_square)->m_b4 = 0;
    ((TPhotonMagicSquare *)photon_magic_square)->m_c4 = arg4;
    *(f32 *)((s8 *)photon_magic_square + 0xC8) = farg0;
    ((TPhotonMagicSquare *)photon_magic_square)->m_cc = 0xFFFFFF;
    return photon_magic_square;
}
}
u8 *construct_photon_magic_square_normal(u8 *photon_magic_square, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    __ct__13TUnk_804B9870FP7TObject(photon_magic_square);
    *(s32 **)((s8 *)photon_magic_square + 0x18) = &(*(RecoveredGlobal_801AD218___vt__18TPhotonMagicSquare *)&__vt__18TPhotonMagicSquare).value;
    *(s32 *)((s8 *)photon_magic_square + 0) = (s32) TPhotonMagicSquare__data_805D3508;
    *(s32 *)((s8 *)photon_magic_square + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x28);
    *(u8 **)((s8 *)photon_magic_square + 0x90) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x430)) + 0x14));
    *(f32 *)((s8 *)photon_magic_square + 0x9C) = (f32) (0.0f);
    *(f32 *)((s8 *)photon_magic_square + 0x94) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)photon_magic_square + 0x90)) + 4) - (1.0f));
    ((TPhotonMagicSquare *)photon_magic_square)->m_98 = (f32) (0.1f);
    ((TPhotonMagicSquare *)photon_magic_square)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x2C);
    ((TPhotonMagicSquare *)photon_magic_square)->scale.x = (f32) (0.0f);
    ((TPhotonMagicSquare *)photon_magic_square)->scale.y = (f32) (0.0f);
    *(f32 *)((s8 *)photon_magic_square + 0x70) = (f32) (0.0f);
    copy_argb((NJS_ARGB *)(photon_magic_square + 0xA0), (NJS_ARGB *)((u8 *)&(*(RecoveredGlobal_801AD218_TPhotonMagicSquare__data_804C3940 *)&TPhotonMagicSquare__color_palette).value + (arg2 * 0x10)));
    VecCopy((Vec *)(photon_magic_square + 0xB8), (const Vec *)(arg3));
    ((TPhotonMagicSquare *)photon_magic_square)->m_b0 = 0;
    ((TPhotonMagicSquare *)photon_magic_square)->m_b4 = 0;
    ((TPhotonMagicSquare *)photon_magic_square)->m_c4 = arg4;
    *(f32 *)((s8 *)photon_magic_square + 0xC8) = (f32) (0.04f);
    ((TPhotonMagicSquare *)photon_magic_square)->m_cc = 0xFFFFFF;
    return photon_magic_square;
}

u8 *TPhotonMagicSquare::construct_at_owner(s32 arg1, s32 arg2, s32 arg3) {
    s32 entity;
    __ct__13TUnk_804B9870FP7TObject(this);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_801AD330___vt__18TPhotonMagicSquare *)&__vt__18TPhotonMagicSquare).value;
    *(s32 *)&this->m_name = (s32) TPhotonMagicSquare__data_805D3508;
    *(s32 *)&this->model = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x28);
    *(u8 * *)&this->m_90 = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x430)) + 0x14));
    *(f32 *)&this->unk_9C = (f32) (0.0f);
    *(f32 *)((s8 *)((u8 *)this) + 0x94) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 * *)&this->m_90) + 4) - (1.0f));
    this->m_98 = (f32) (0.1f);
    this->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x2C);
    this->scale.x = (f32) (0.0f);
    this->scale.y = (f32) (0.0f);
    this->scale.z = (f32) (0.0f);
    copy_argb((NJS_ARGB *)(((u8 *)this) + 0xA0), (NJS_ARGB *)((u8 *)&(*(RecoveredGlobal_801AD330_TPhotonMagicSquare__data_804C3940 *)&TPhotonMagicSquare__color_palette).value + (arg2 * 0x10)));
    entity = find_entity_by_id((void *)arg3);
    if (entity != 0) {
        VecCopy((Vec *)(((u8 *)this) + 0xB8), (const Vec *)(entity + 0x38));
    }
    *(f32 *)((s8 *)((u8 *)this) + 0xBC) += (2.0f);
    *(s32 *)&this->m_b0 = 0;
    *(s32 *)&this->m_b4 = 0;
    *(s32 *)&this->m_c4 = 0x37;
    *(f32 *)&this->_padC8 = (f32) (0.1f);
    *(s32 *)&this->m_cc = 2;
    play_sound_effect(0x4002AD2E, 0, 0, 0);
    return ((u8 *)this);
}
