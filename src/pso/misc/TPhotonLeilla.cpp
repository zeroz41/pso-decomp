#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/TPhotonLeilla.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include <stddef.h>
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/misc/obj_band.h"
#include "pso/misc/TOKeyMachine01.h"

extern "C" {
void TObjPlayer__sub_801AC43C(void) {  }
void TObjPlayer__sub_801AC440(void) {  }
}

void TPhotonLeilla::sub_801AC444() { *(float *)&this->m_180 = 0.0f; *(float*)((char*)this + 0x184) = 0.0f; this->m_188 = 0.0f; *(float *)&this->unk_18C = 0.0f; }

struct Stack_801AC574 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct Color_801AC45C { f32 a, r, g, b; };

struct Vec_801AC45C { f32 x, y, z; };

struct Self_801AC45C {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec_801AC45C pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x180 - 0x14E];
    Color_801AC45C color;
    u8 pad5[0x19C - 0x190];
    s32 started;
};

extern "C" {
u16 obj_getField1c(void *);
void *find_entity_by_id(u16 id);
}
u8 *construct_photon_magic_square_normal(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" {
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 advance_animation_playback(void *);
s32 spawn_photon_blast_attachment_effects(void *, int);
u8 *__nw__7TObjectFUl(s32, f32);
extern const f64 lbl_80446DE8;

s32 scroll_strip_uvs(void *, s16, int);
s32 clear_render_context__10TObjPlayerFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
extern Color_801AC45C saved_model_draw_color;
extern Color_801AC45C model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern void *leilla_photon_buffer_pair;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void TPhotonLeilla::render() {
    Self_801AC45C *self = (Self_801AC45C *)this;
    if (*(s32 *)&this->m_19c != 0) {
        scroll_strip_uvs(leilla_photon_buffer_pair, self->f14C, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texture_id);
        push_matrix();
        translate_matrix(0, self->pos.x, self->pos.y, self->pos.z);
        rotate_matrix_y(0, this->rotation_y);
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        TObjPlayer::set_global_flag();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TUnk_804C3248 *)self)->set_photon_blast_joint_callback();
        ((TObjMotion *)self)->draw();
        TObjPlayer::clear_global_state();
        clear_render_context__10TObjPlayerFv(self);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonLeilla::run_task() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_801AC574, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801AC574, spC) == 0x4) ? 1 : -1];
    Stack_801AC574 stack;
    f32 temp_f1;
    f32 temp_f1_2;
    u8 *entity;
    u8 *photon_magic_square;
    u8 *temp_r3_3;
    *(s32 *)&this->m_1ac = (s32) (*(s32 *)&this->m_1ac + 1);
    if (((s32) *(s32 *)&this->m_1ac == 0x32) && ((s32) *(s32 *)&this->m_19c == 0)) {
        *(s32 *)&this->m_19c = 1;
        *(s32 *)&this->m_1ac = 0;
        entity = (u8 *)(find_entity_by_id(this->m_17c));
        if (entity != NULL) {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(entity + 0x38));
        }
        temp_f1 = stack.spC;
        stack.spC += 3e+01f;
        photon_magic_square = (u8 *)(__nw__7TObjectFUl(0xD0, temp_f1));
        if (photon_magic_square != NULL) {
            construct_photon_magic_square_normal((u8 *)photon_magic_square, (s32)arg0, 4, (s32)&stack.sp8, 0x78);
        }
    }
    if ((5e+01f == (f32) *(s32 *)&this->m_1ac) && ((s16) this->m_b8 == 1)) {
        ((TUnk_804C3248 *)arg0)->begin_photon_summon_camera(2);
        *(s32 *)&this->m_1ac = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        spawn_photon_blast_attachment_effects(arg0, 4);
    }
    *(s16 *)&this->m_190 = (s16) this->m_b8;
    ((TUnk_804C3248 *)arg0)->update_state();
    advance_animation_playback(arg0);
    ((TUnk_804C3248 *)arg0)->update_photon_blast_attachments();
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (*(s16 *)((s8 *)arg0 + 0x14C) + 0xF);
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (u8) *(s16 *)((s8 *)arg0 + 0x14C);
    if (1.3e+02f == (f32) *(s32 *)&this->m_1ac) {
        temp_r3_3 = (u8 *)(find_entity_by_id(this->m_17c));
        if (temp_r3_3 != NULL) {
            queue_photon_blast_hit((int) (obj_getField1c(temp_r3_3)), 4, 0, this->m_150);
        }
    }
    if ((f32) *(s32 *)&this->m_1ac > 109.0f) {
        temp_f1_2 = *(f32 *)&this->m_180;
        if (temp_f1_2 > (-1.0f)) {
            *(f32 *)&this->m_180 = (f32) ((f64) temp_f1_2 - lbl_80446DE8);
        }
    }
    if ((s32) *(s32 *)&this->m_19c != 0) {
        play_persistent_sound(0x4002462F, (s32)arg0, (u32)(0U), 0, 0);
    }
}
}

extern "C" {

s32 __dl__7TObjectFPv(void *);

extern s32 __vt__13TPhotonLeilla[];

struct Base_801AC794 { char pad[0x18]; };
struct VObj_801AC794 : Base_801AC794 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13();
};

void *__dt__13TPhotonLeillaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        struct VObj_801AC794 *o = (struct VObj_801AC794 *)arg0;
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TPhotonLeilla;
        o->m13();
        ((TUnk_804C3248 *)arg0)->free_photon();
        destroy_photon_motion_object(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

#define NEW_801AC808(n) (((u8 *(*)(int))__nw__7TObjectFUl)(n))
#define F_801AC808(o, t, off) (*(t *)((u8 *)(o) + (off)))
struct Vec_801AC808 { f32 x, y, z; };
struct Pkt_801AC808 {
    Vec_801AC808 pos;
    u16 owner;
    s32 first;
    s32 more;
    u8 pad18[0x1C - 0x18];
    u8 count;
    f32 f20;
};
struct VBase_801AC808 { u8 pad[0x18]; };
struct Leilla_801AC808 : VBase_801AC808 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12();
    u8 pad1C[0x38 - 0x1C];
    Vec_801AC808 pos;
};
struct Res_801AC808 { u8 pad[0x18]; s32 f18; s32 f1C; };
struct Game_801AC808 { u8 pad[0x42C]; Res_801AC808 *res; s32 f430; };

extern "C" {
void *find_entity_by_id(u16 id);
s32 spawn_photon_blast_attachment_effects(void *, int);
void sub_801AC444__13TPhotonLeillaFv(void *, u8);
}
u8 *construct_photon_magic_square_normal(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" {
void TPhotonRainbow__ct(void *, void *, void *, s32);
u8 *__nw__7TObjectFUl(s32, f32);
extern u8 lbl_80446DF8[];
extern u8 lbl_80446E04[];
extern u8 photon_blast_leilla_params[];
extern s32 __vt__13TPhotonLeilla[];
extern s32 lbl_805D34F8;
extern Game_801AC808 *photon_blast_shared_resource;

void *TPhotonLeilla__ct(Leilla_801AC808 *self, Pkt_801AC808 *pkt) {
    Vec_801AC808 v;
    u8 *o;
    u8 *owner;
    photon_base_ct(self);
    *(void **)((u8 *)self + 0x18) = __vt__13TPhotonLeilla;
    F_801AC808(self, s32, 0) = lbl_805D34F8;
    F_801AC808(self, s32, 0x138) = 4;
    VecCopy((Vec *)&self->pos, (const Vec *)pkt);
    F_801AC808(self, u16, 0x17C) = pkt->owner;
    owner = (u8 *)find_entity_by_id(F_801AC808(self, u16, 0x17C));
    if (owner != NULL) {
        F_801AC808(self, s32, 0x60) = F_801AC808(owner, s32, 0x60);
    }
    F_801AC808(self, s32, 0x34) = photon_blast_shared_resource->res->f18;
    F_801AC808(self, s32, 0x24) = photon_blast_shared_resource->res->f1C;
    ((TObjMotion *)self)->set_field_d8((s32)photon_blast_leilla_params);
    ((TObjMotion *)self)->set_field_dc(photon_blast_shared_resource->f430);
    F_801AC808(self, s16, 0xB8) = 1;
    ((TObjMotion *)self)->set_animation(F_801AC808(self, s16, 0xB8));
    ((TObjMotion *)self)->set_field_b8(F_801AC808(self, s16, 0xB8));
    F_801AC808(self, s16, 0x190) = 1;
    F_801AC808(self, s32, 0x194) = pkt->first;
    F_801AC808(self, s32, 0x198) = pkt->more;
    F_801AC808(self, s32, 0x19C) = 0;
    F_801AC808(self, s32, 0x134) = 2;
    self->m12();
    F_801AC808(self, s32, 0x1AC) = 0;
    switch (TOKeyMachine01::get_global_state()) {
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
        o = NEW_801AC808(0xAC);
        if (o != NULL) {
            TPhotonRainbow__ct(o, self, &self->pos, 1);
        }
        break;
    default:
        o = NEW_801AC808(0xAC);
        if (o != NULL) {
            TPhotonRainbow__ct(o, self, &self->pos, 0);
        }
        break;
    }
    sub_801AC444__13TPhotonLeillaFv(self, pkt->count);
    if (F_801AC808(self, s32, 0x198) == 1) {
        F_801AC808(self, u32, 0x154) |= 1;
    }
    F_801AC808(self, f32, 0x150) = pkt->f20;
    if (F_801AC808(self, s32, 0x194) == 0) {
        ((TObjMotion *)self)->set_field_b8(0);
        ((TUnk_804C3248 *)self)->begin_photon_summon_camera(2);
        F_801AC808(self, s32, 0x194) = 1;
        F_801AC808(self, s16, 0x190) = 0;
        F_801AC808(self, s32, 0x19C) = 1;
        owner = (u8 *)find_entity_by_id(F_801AC808(self, u16, 0x17C));
        if (owner != NULL) {
            VecCopy((Vec *)&v, (const Vec *)(owner + 0x38));
        }
        v.y += 3e+01f;
        o = NEW_801AC808(0xD0);
        if (o != NULL) {
            construct_photon_magic_square_normal((u8 *)o, (s32)self, 4, (s32)&v, 0x78);
        }
        spawn_photon_blast_attachment_effects(self, 4);
        play_cue_stream_file((s32)lbl_80446DF8);
    } else {
        spawn_photon_blast_opening_effects(4, F_801AC808(self, u16, 0x17C));
        play_cue_stream_file((s32)lbl_80446E04);
    }
    return self;
}
}
