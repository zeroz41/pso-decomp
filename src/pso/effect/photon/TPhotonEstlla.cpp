#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/photon/TPhotonEstlla.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/player/TObjPlayer_801AA664.h"

#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/object/base/TObjMotion.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/text_801AAB74.h"
#include "pso/system/vector.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/photon/TPhotonLine.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/CollisionActorLookup.h"

u16 TObjPlayer::get_entity_type() { return *(u16*)((char*)this + 0x0); }
void* TObjPlayer__sub_801AA66C(void* p, void* a1) { *(short*)(p) = *(unsigned short*)(a1); *(short*)((char*)p + 0x2) = *(short*)((char*)a1 + 0x2); *(void**)((char*)p + 0x4) = *(void**)((char*)a1 + 0x4); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0x8), (u8 *)((char*)a1 + 0x8)); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0xc), (u8 *)((char*)a1 + 0xc)); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0x10), (u8 *)((char*)a1 + 0x10)); TObjPlayer__sub_801AA6E4((u8 *)((char*)p + 0x14), (u8 *)((char*)a1 + 0x14)); return p; }

void TObjPlayer__sub_801AA6E4(u8 *arg0, u8 *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

void TPhotonEstlla::sub_801AA6F8() { *(float *)&this->m_180 = 0.0f; *(float*)((char*)this + 0x184) = 0.0f; this->m_188 = 0.0f; *(float *)&this->unk_18C = 0.0f; }

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


struct Self_801AA710 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad1[0x150 - 0x44];
    f32 f150;
    u8 pad2[0x17C - 0x154];
    u16 id;
};

struct Owner_801AA710 { u8 pad[0x60]; s32 f60; };

struct Self_801AA818 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x180 - 0x14E];
    NJS_ARGB color;
    u8 pad5[0x19C - 0x190];
    s32 started;
};

const char *TPhotonEstlla__class_name = "TPhotonEstlla";
extern const PhotonLineParams photon_estlla_line_packet_init = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f
};
extern u8 identity_matrix[];
extern "C" {

s32 scroll_strip_uvs(void *, s16, int);
}
extern NJS_ARGB saved_model_draw_color;
extern NJS_ARGB model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
void *estlla_photon_blast_model;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void TPhotonEstlla::spawn_line() {
    Self_801AA710 *self = (Self_801AA710 *)this;
    Owner_801AA710 *owner;
    Vec forward;
    Vec direction;
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
        PhotonLineParams packet = photon_estlla_line_packet_init;
        packet.pos = self->pos;
        packet.dir = direction;
        packet.power = this->power;
        new TPhotonLine(&packet, (TObject *)self, this->m_17c);
    }
}

void TPhotonEstlla::render() {
    Self_801AA818 *self = (Self_801AA818 *)this;
    if (*(s32 *)&this->m_19c != 0) {
        scroll_strip_uvs(estlla_photon_blast_model, self->f14C, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
        push_matrix();
        translate_matrix(0, self->pos.x, self->pos.y, self->pos.z);
        rotate_matrix_y(0, this->rotation_y);
        ((TPhotonBlastSummon *)self)->set_photon_blast_joint_callback();
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x200820;
        set_motion_packed_rotation();
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((f32 *)&self->color)));
        ((TObjMotion *)self)->draw();
        clear_motion_packed_rotation();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        ((TPhotonBlastSummon *)self)->clear_photon_blast_joint_callback();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TPhotonEstlla::run_task() {
    u8 *arg0 = (u8 *)this;
    Vec stack;
    f32 temp_f1;
    u8 *entity;
    *(s32 *)&this->m_1a0 = (s32) (*(s32 *)&this->m_1a0 + 1);
    if (((s32) *(s32 *)&this->m_1a0 == 0x32) && ((s32) *(s32 *)&this->m_19c == 0)) {
        *(s32 *)&this->m_19c = 1;
        entity = (u8 *)(find_entity_by_id(this->m_17c));
        if (entity != NULL) {
            stack.x = *(f32 *)((s8 *)entity + 0x38);
            stack.y = 3e+01f + *(f32 *)((s8 *)entity + 0x3C);
            stack.z = *(f32 *)((s8 *)entity + 0x40);
        }
        new TPhotonMagicSquare((TObject *)arg0, 1, (Vec *)&stack.x, 0x78);
    }
    if (((s32) *(s32 *)&this->m_1a0 == 0x64) && ((s16) this->requested_action == 1)) {
        ((TPhotonBlastSummon *)arg0)->begin_photon_summon_camera(0);
        *(s32 *)&this->m_1a0 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        ((TPhotonBlastSummon *)arg0)->spawn_photon_blast_attachment_effects(1);
    }
    *(s16 *)&this->m_190 = (s16) this->requested_action;
    ((TPhotonBlastSummon *)arg0)->update_state();
    ((TObjMotion *)arg0)->advance_animation();
    ((TPhotonBlastSummon *)arg0)->update_photon_blast_attachments();
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
        play_persistent_sound(0x4002462F, (saddr)arg0, 0, 0, 0);
    }
}

TPhotonEstlla::~TPhotonEstlla() {
    update_if_active();
    free_photon();
}

extern "C" {

s32 sub_801AA6F8__13TPhotonEstllaFv(void *, int);
}
extern u8 *photon_blast_shared_resource;

TObjMotionAction photon_estlla_param_table[2] = {
    {MOTION_MODE_ONCE, 0, 5, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 0xC, 1.0f, 0},
};

TPhotonEstlla::TPhotonEstlla(u8 *arg1) : TPhotonBlastSummon() {
    Vec pos;
    u8 *e;
    m_name = TPhotonEstlla__class_name;
    *(s32 *)((s8 *)this + 0x138) = 1;
    VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)arg1);
    this->m_17c = *(u16 *)((s8 *)arg1 + 0xC);
    e = (u8 *)find_entity_by_id(this->m_17c);
    if (e != NULL) {
        this->rotation_y = *(s32 *)((s8 *)e + 0x60);
    }
    *(s32 *)((s8 *)this + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x98);
    this->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x9C);
    this->set_field_d8((saddr) photon_estlla_param_table);
    this->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    this->requested_action = 1;
    this->set_animation(this->requested_action);
    this->set_field_b8(this->requested_action);
    *(s16 *)&this->m_190 = 1;
    *(s32 *)&this->m_194 = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)&this->m_198 = *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)&this->m_19c = 0;
    this->camera_script = 0;
    this->enter_scene();
    *(s32 *)&this->m_1a0 = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        new TPhotonRainbow(this, (const Vec *)(((u8 *)this) + 0x38), 1);
        break;
    default:
        new TPhotonRainbow(this, (const Vec *)(((u8 *)this) + 0x38), 0);
        break;
    }
    sub_801AA6F8__13TPhotonEstllaFv(this, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)&this->m_198 == 1) {
        *(s32 *)((s8 *)this + 0x154) |= 1;
    }
    this->power = *(f32 *)((s8 *)arg1 + 0x20);
    if (*(s32 *)&this->m_194 == 0) {
        this->set_field_b8(0);
        this->begin_photon_summon_camera(0);
        *(s32 *)&this->m_194 = 1;
        *(s16 *)&this->m_190 = 0;
        *(s32 *)&this->m_19c = 1;
        e = (u8 *)find_entity_by_id(this->m_17c);
        if (e != NULL) {
            pos.x = *(f32 *)((s8 *)e + 0x38);
            pos.y = 3e+01f + *(f32 *)((s8 *)e + 0x3C);
            pos.z = *(f32 *)((s8 *)e + 0x40);
        }
        new TPhotonMagicSquare(this, 1, &pos, 0x78);
        spawn_photon_blast_attachment_effects(1);
        play_cue_stream_file((saddr)"estla2.adx");
    } else {
        spawn_photon_blast_opening_effects(1, this->m_17c);
        play_cue_stream_file((saddr)"estla.adx");
    }
}

void TObjPlayer::destroy_global_buffer() {
    if (estlla_photon_blast_model != NULL) {
        destroy_buffer_pair(estlla_photon_blast_model, 1);
    }
    estlla_photon_blast_model = NULL;
}

void create_estlla_photon_blast_model(void) {
    saddr temp_r3;
    saddr var_r0;
    temp_r3 = (saddr)::operator new(0x14);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TLobby *)temp_r3)->alloc_tables(*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x98)) + 0x2C), 0));
    }
    estlla_photon_blast_model = (void *)var_r0;
}
