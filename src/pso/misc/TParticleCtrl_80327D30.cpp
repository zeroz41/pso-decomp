#include "types.h"
#include "pso/misc/TUnk_804ED5B0.h"
#include "pso/unk/text_802A8210.h"
#include "pso/unk/text_803281B8.h"
#include "pso/misc/TParticleCtrl_80327D30.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/unk/text_80141A30.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804ED598.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80327F88_lbl_804ED598 {
    s32 value;
    u8 remaining[0x14];
};

struct Vtx_80327D30 { f32 x, y, z, u, v; u32 color; };

struct Obj_80327D30 { u8 pad0[0x1C]; f32 w; f32 h; u8 pos[0xC]; u8 pad30; u8 f31; u8 pad32[2]; s32 f34; s32 f38; u8 pad3c[4]; void *f40; };

extern "C" {
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
extern s32 lbl_804ED598[];
int GXSetNumIndStages(int);
int GXSetTevDirect(int);
extern s32 lbl_804ED5B0[];
s32 __nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 tl_05;
s32 GXSetNumTexGens(int);
s32 GXSetNumTevStages(int);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 TParticleCtrl__sub_803E2A1C(void *, int);
extern u8 lbl_804C5820[];
extern u8 *camera_ctrl_instance;
void TUnk_804ED598::render() {
    Obj_80327D30 *o = (Obj_80327D30 *)this;
    Vtx_80327D30 v[4];
    if (o->f40 != NULL && o->f38 != 0) {
        v[0].x = 10.0f * o->w;
        v[0].y = 10.0f * this->m_20;
        v[0].z = 0.0f;
        v[0].u = 0.0f;
        v[0].v = 0.0f;
        v[0].color = 0xFFFF0000;
        v[1].x = 10.0f * o->w;
        v[1].y = -10.0f * this->m_20;
        v[1].z = 0.0f;
        v[1].u = 0.0f;
        v[1].v = 1.0f;
        v[1].color = 0xFFFF0000;
        v[2].x = -10.0f * o->w;
        v[2].y = 10.0f * this->m_20;
        v[2].z = 0.0f;
        v[2].u = 1.0f;
        v[2].v = 0.0f;
        v[2].color = 0xFFFF0000;
        v[3].x = -10.0f * o->w;
        v[3].y = -10.0f * this->m_20;
        v[3].z = 0.0f;
        v[3].u = 1.0f;
        v[3].v = 1.0f;
        v[3].color = 0xFFFF0000;
        TParticleCtrl::begin_effect_render();
        push_matrix();
        post_translate_matrix(o->pos);
        rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x194));
        rotate_matrix_x(0, *(s32 *)(camera_ctrl_instance + 0x190));
        load_projected_texture_matrix(1.1333334f);
        TObjFish::set_global_param(*(s32 *)(lbl_804C5820 + 0x16C));
        set_texture_num(o->f31);
        TParticleCtrl::setup_particle_draw(1);
        GXSetNumTevStages(2);
        GXSetNumTexGens(2);
        ((TParticleCtrl *)(o->f40))->play_particle(0, (s16)(-1));
        setup_particle_tev(0);
        if (this->m_34 != 0) {
            set_depth_buffer_settings_2();
        }
        TParticleCtrl__sub_803E2A1C(v, 4);
        if (this->m_34 != 0) {
            restore_saved_depth_alpha_state();
        }
        TParticleCtrl::reset_particles();
        TParticleCtrl::disable_if_single_screen();
        TParticleCtrl::reset_ind_tev_stages(o->f40);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TUnk_804ED598::run_task() {
    s32 temp_r0;
    s32 temp_r4;

    if ((u32) *(u32 *)&this->unk_40 == 0U) {
        queue_destruction__7TObjectFv((this));
        return;
    }
    temp_r4 = this->m_3c;
    if (temp_r4 != 0) {
        temp_r0 = temp_r4 - 1;
        this->m_3c = temp_r0;
        if (temp_r0 == 0) {
            queue_destruction__7TObjectFv((this));
        }
    }
}
void *__dt__13TUnk_804ED598Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED598;
        if (*(void **)((s8 *)arg0 + 0x40) != NULL) { queue_destruction__7TObjectFv((*(void **)((s8 *)arg0 + 0x40))); *(s32 *)((s8 *)arg0 + 0x40) = 0; }
        *(s32 *)((s8 *)arg0 + 0x40) = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}

typedef char RecoveredGlobal_80327F88_lbl_804ED598_size[sizeof(RecoveredGlobal_80327F88_lbl_804ED598) == 0x18 ? 1 : -1];
u8 *create_telepipe_marker(u8 *arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, f32 farg0, f32 farg1) {
    s32 temp_r3;
    s32 var_r0;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80327F88_lbl_804ED598 *)&lbl_804ED598).value;
    *(f32 *)((s8 *)arg0 + 0x1C) = farg0;
    ((TUnk_804ED598 *)arg0)->m_20 = farg1;
    VecCopy((Vec *)(arg0 + 0x24), (const Vec *)(arg1));
    ((TUnk_804ED598 *)arg0)->m_30 = arg2;
    *(s8 *)((s8 *)arg0 + 0x31) = arg3;
    ((TUnk_804ED598 *)arg0)->m_34 = arg5;
    temp_r3 = __nw__7TObjectFUl(0x20);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (s32)construct_indirect_effect_task((u8 *)temp_r3, 0x1F, 0, (u8 *)tl_05);
    }
    *(s32 *)((s8 *)arg0 + 0x40) = var_r0;
    *(s32 *)((s8 *)arg0 + 0x38) = 1;
    ((TUnk_804ED598 *)arg0)->m_3c = arg6;
    return arg0;
}

void TParticleCtrl::set_tev_direct(s32 arg0) {
    if (arg0 != 0) {
        GXSetTevDirect(1);
    } else {
        GXSetTevDirect(0);
    }
    GXSetNumIndStages(0);
    set_ginja_post_texgen_count(0);
}

void play_indirect_effect_recipe(u8 arg0, u16 sampler, s32 second) {
    TObjPlayer::play_particle_at_active_slot((s32) arg0, (s32) sampler, 0, 0, 0, second);
}

void request_indirect_effect(s32 kind) { register_indirect_effect_ctrl(kind); }
void TParticleCtrl::reset_ind_tev_stages(void * _w0) { GXSetTevDirect(1); GXSetNumIndStages(0); set_ginja_post_texgen_count(0); }
void TParticleCtrl::play_particle(s32 arg1, s16 arg2) {
    if (arg2 < 0) {
        arg2 = (s16) *(u8 *)((s8 *)this + 0x1C);
    }
    TObjPlayer::play_particle_at_active_slot((u8)((u8) arg2), (u8)(*(u8 *)((s8 *)this + 0x1D)), 0, 0, 0, 1);
}
void *__dt__13TUnk_804ED5B0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED5B0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
