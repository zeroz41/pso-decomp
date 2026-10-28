#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/player/TObjPlayer_801AA664.h"
#include "pso/misc/TPhotonEstlla.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/misc/TPhotonRainbow_801AE640.h"
#include "pso/misc/obj_band.h"
#include "pso/unk/text_801AAB74.h"
#include "pso/system/vector.h"
#include "pso/map/FloorArea.h"

u16 TObjPlayer::get_entity_type() { return *(u16*)((char*)this + 0x0); }
void* TObjPlayer__sub_801AA66C(void* p, void* a1) { *(short*)(p) = *(unsigned short*)(a1); *(short*)((char*)p + 0x2) = *(short*)((char*)a1 + 0x2); *(void**)((char*)p + 0x4) = *(void**)((char*)a1 + 0x4); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0x8), (u8 *)((char*)a1 + 0x8)); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0xc), (u8 *)((char*)a1 + 0xc)); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0x10), (u8 *)((char*)a1 + 0x10)); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0x14), (u8 *)((char*)a1 + 0x14)); return p; }

void TObjPlayer__sub_801AA6E4(u8 *arg0, u8 *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

void TPhotonEstlla::sub_801AA6F8() { *(float *)&this->m_180 = 0.0f; *(float*)((char*)this + 0x184) = 0.0f; this->m_188 = 0.0f; *(float *)&this->unk_18C = 0.0f; }

struct Stack_801AA930 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_801AA710 { f32 x, y, z; };

struct Packet_801AA710 { u32 w[8]; };

struct Self_801AA710 {
    u8 pad0[0x38];
    Vec_801AA710 pos;
    u8 pad1[0x150 - 0x44];
    f32 f150;
    u8 pad2[0x17C - 0x154];
    u16 id;
};

struct Owner_801AA710 { u8 pad[0x60]; s32 f60; };

struct Color_801AA818 { f32 a, r, g, b; };

struct Vec_801AA818 { f32 x, y, z; };

struct Self_801AA818 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec_801AA818 pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x180 - 0x14E];
    Color_801AA818 color;
    u8 pad5[0x19C - 0x190];
    s32 started;
};

extern "C" {
s32 advance_animation_playback(void *);
void *find_entity_by_id(u16 id);
s32 spawn_photon_blast_attachment_effects(void *, int);
}
u8 *construct_photon_magic_square_normal(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" {
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u32 __nw__7TObjectFUl(int);

s32 TPhotonLine__ct(void *, void *, void *, u16);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrices(s32 arg0);
extern const Packet_801AA710 photon_estlla_line_packet_init;
extern u8 identity_matrix[];

s32 scroll_strip_uvs(void *, s16, int);
s32 clear_render_context__10TObjPlayerFv(void *);
s32 push_matrix();
s32 pop_matrix();
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
extern Color_801AA818 saved_model_draw_color;
extern Color_801AA818 model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern void *estlla_photon_blast_model;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void TPhotonEstlla::spawn_line() {
    Self_801AA710 *self = (Self_801AA710 *)this;
    Owner_801AA710 *owner;
    Vec_801AA710 forward;
    Vec_801AA710 direction;
    u32 line;
    owner = (Owner_801AA710 *)find_entity_by_id(this->m_17c);
    forward.x = 0.0f;
    forward.y = 0.0f;
    forward.z = 1.0f;
    push_matrix_from(identity_matrix);
    if (owner) {
        rotate_matrix_y(0, owner->f60);
    }
    rotate_vector_by_matrix(0, &forward, &direction);
    pop_matrices(1);
    {
        Packet_801AA710 packet = photon_estlla_line_packet_init;
        *(Vec_801AA710 *)&packet.w[0] = self->pos;
        *(Vec_801AA710 *)&packet.w[3] = direction;
        *(f32 *)&packet.w[7] = this->m_150;
        line = __nw__7TObjectFUl(0x378);
        if (line) {
            TPhotonLine__ct((void *)line, &packet, self, this->m_17c);
        }
    }
}

void TPhotonEstlla::render() {
    Self_801AA818 *self = (Self_801AA818 *)this;
    if (*(s32 *)&this->m_19c != 0) {
        scroll_strip_uvs(estlla_photon_blast_model, self->f14C, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        translate_matrix(0, self->pos.x, self->pos.y, self->pos.z);
        rotate_matrix_y(0, this->rotation_y);
        ((TUnk_804C3248 *)self)->set_photon_blast_joint_callback();
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        TObjPlayer::set_global_flag();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TObjMotion *)self)->draw();
        TObjPlayer::clear_global_state();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        clear_render_context__10TObjPlayerFv(self);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonEstlla::run_task() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_801AA930, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801AA930, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_801AA930, sp10) == 0x8) ? 1 : -1];
    Stack_801AA930 stack;
    f32 temp_f1;
    u32 photon_magic_square;
    u8 *entity;
    *(s32 *)&this->m_1a0 = (s32) (*(s32 *)&this->m_1a0 + 1);
    if (((s32) *(s32 *)&this->m_1a0 == 0x32) && ((s32) *(s32 *)&this->m_19c == 0)) {
        *(s32 *)&this->m_19c = 1;
        entity = (u8 *)(find_entity_by_id(this->m_17c));
        if (entity != NULL) {
            stack.sp8 = *(f32 *)((s8 *)entity + 0x38);
            stack.spC = 3e+01f + *(f32 *)((s8 *)entity + 0x3C);
            stack.sp10 = *(f32 *)((s8 *)entity + 0x40);
        }
        photon_magic_square = __nw__7TObjectFUl(0xD0);
        if (photon_magic_square != 0U) {
            construct_photon_magic_square_normal((u8 *)photon_magic_square, (s32)arg0, 1, (s32)&stack.sp8, 0x78);
        }
    }
    if (((s32) *(s32 *)&this->m_1a0 == 0x64) && ((s16) this->m_b8 == 1)) {
        ((TUnk_804C3248 *)arg0)->begin_photon_summon_camera(0);
        *(s32 *)&this->m_1a0 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        spawn_photon_blast_attachment_effects(arg0, 1);
    }
    *(s16 *)&this->m_190 = (s16) this->m_b8;
    ((TUnk_804C3248 *)arg0)->update_state();
    advance_animation_playback(arg0);
    ((TUnk_804C3248 *)arg0)->update_photon_blast_attachments();
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (*(s16 *)((s8 *)arg0 + 0x14C) + 0xF);
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (u8) *(s16 *)((s8 *)arg0 + 0x14C);
    if (9e+01f == (f32) *(s32 *)&this->m_1a0) {
        spawn_line();
    }
    if ((f32) *(s32 *)&this->m_1a0 > 105.0f) {
        temp_f1 = *(f32 *)&this->m_180;
        if (temp_f1 > (-1.0f)) {
            *(f32 *)&this->m_180 = (f32) (temp_f1 - 0.15f);
        }
    }
    if ((s32) *(s32 *)&this->m_19c != 0) {
        play_persistent_sound(0x4002462F, (s32)arg0, 0, 0, 0);
    }
}
}

extern "C" {

s32 __dl__7TObjectFPv(void *);

extern s32 __vt__13TPhotonEstlla[];

struct Base_801AAB00 { char pad[0x18]; };
struct VObj_801AAB00 : Base_801AAB00 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13();
};

void *__dt__13TPhotonEstllaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        struct VObj_801AAB00 *o = (struct VObj_801AAB00 *)arg0;
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TPhotonEstlla;
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

struct Stack_801AAB74 { f32 x, y, z; };

extern "C" {
void *find_entity_by_id(u16 id);

s32 sub_801AA6F8__13TPhotonEstllaFv(void *, int);
}
u8 *construct_photon_magic_square_normal(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" {

extern u8 lbl_80446D10[];
extern u8 lbl_80446D1C[];
extern u8 photon_estlla_param_table[];
extern s32 __vt__13TPhotonEstlla[];
extern s32 lbl_805D34D8;
extern u8 *photon_blast_shared_resource;

u8 *TPhotonEstlla__ct(u8 *photon_estlla, u8 *arg1) {
    Stack_801AAB74 pos;
    u8 *e;
    void *p;
    photon_base_ct(photon_estlla);
    *(s32 **)((s8 *)photon_estlla + 0x18) = __vt__13TPhotonEstlla;
    *(s32 *)((s8 *)photon_estlla + 0) = lbl_805D34D8;
    *(s32 *)((s8 *)photon_estlla + 0x138) = 1;
    VecCopy((Vec *)(photon_estlla + 0x38), (const Vec *)arg1);
    ((TPhotonEstlla *)photon_estlla)->m_17c = *(u16 *)((s8 *)arg1 + 0xC);
    e = (u8 *)find_entity_by_id(((TPhotonEstlla *)photon_estlla)->m_17c);
    if (e != NULL) {
        ((TPhotonEstlla *)photon_estlla)->rotation_y = *(s32 *)((s8 *)e + 0x60);
    }
    *(s32 *)((s8 *)photon_estlla + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x98);
    ((TPhotonEstlla *)photon_estlla)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x9C);
    ((TObjMotion *)photon_estlla)->set_field_d8((s32) photon_estlla_param_table);
    ((TObjMotion *)photon_estlla)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    ((TPhotonEstlla *)photon_estlla)->m_b8 = 1;
    ((TObjMotion *)photon_estlla)->set_animation(((TPhotonEstlla *)photon_estlla)->m_b8);
    ((TObjMotion *)photon_estlla)->set_field_b8(((TPhotonEstlla *)photon_estlla)->m_b8);
    *(s16 *)&((TPhotonEstlla *)photon_estlla)->m_190 = 1;
    *(s32 *)&((TPhotonEstlla *)photon_estlla)->m_194 = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)&((TPhotonEstlla *)photon_estlla)->m_198 = *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)&((TPhotonEstlla *)photon_estlla)->m_19c = 0;
    ((TPhotonEstlla *)photon_estlla)->m_134 = 0;
    ((TPhotonEstlla *)photon_estlla)->enter_scene();
    *(s32 *)&((TPhotonEstlla *)photon_estlla)->m_1a0 = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        p = (void *)__nw__7TObjectFUl(0xAC);
        if (p != NULL) {
            ((u8 *(*)(void *, void *, void *, int)) TPhotonRainbow__ct)(p, photon_estlla, photon_estlla + 0x38, 1);
        }
        break;
    default:
        p = (void *)__nw__7TObjectFUl(0xAC);
        if (p != NULL) {
            ((u8 *(*)(void *, void *, void *, int)) TPhotonRainbow__ct)(p, photon_estlla, photon_estlla + 0x38, 0);
        }
        break;
    }
    sub_801AA6F8__13TPhotonEstllaFv(photon_estlla, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)&((TPhotonEstlla *)photon_estlla)->m_198 == 1) {
        *(s32 *)((s8 *)photon_estlla + 0x154) |= 1;
    }
    ((TPhotonEstlla *)photon_estlla)->m_150 = *(f32 *)((s8 *)arg1 + 0x20);
    if (*(s32 *)&((TPhotonEstlla *)photon_estlla)->m_194 == 0) {
        ((TObjMotion *)photon_estlla)->set_field_b8(0);
        ((TUnk_804C3248 *)photon_estlla)->begin_photon_summon_camera(0);
        *(s32 *)&((TPhotonEstlla *)photon_estlla)->m_194 = 1;
        *(s16 *)&((TPhotonEstlla *)photon_estlla)->m_190 = 0;
        *(s32 *)&((TPhotonEstlla *)photon_estlla)->m_19c = 1;
        e = (u8 *)find_entity_by_id(((TPhotonEstlla *)photon_estlla)->m_17c);
        if (e != NULL) {
            pos.x = *(f32 *)((s8 *)e + 0x38);
            pos.y = 3e+01f + *(f32 *)((s8 *)e + 0x3C);
            pos.z = *(f32 *)((s8 *)e + 0x40);
        }
        p = (void *)__nw__7TObjectFUl(0xD0);
        if (p != NULL) {
            construct_photon_magic_square_normal((u8 *)p, (s32)photon_estlla, 1, (s32)&pos, 0x78);
        }
        spawn_photon_blast_attachment_effects(photon_estlla, 1);
        play_cue_stream_file((s32)lbl_80446D10);
    } else {
        spawn_photon_blast_opening_effects(1, ((TPhotonEstlla *)photon_estlla)->m_17c);
        play_cue_stream_file((s32)lbl_80446D1C);
    }
    return photon_estlla;
}
}
