#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "types.h"
#include <stdlib.h>
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_801AB608.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/photon/TPhotonGolla.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/player/TObjPlayer_801AC0D8.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/effect/photon/TPhotonConcentrate.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/base/CollisionActorLookup.h"

struct Stack_801ABBAC {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct Self_801ABAA0 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x15C - 0x14E];
    NJS_ARGB color;
    u8 pad5[0x1C4 - 0x16C];
    s32 started;
};

typedef struct Packet_801AB6A0 {
    Vec origin;
    Vec target;
    Vec direction;
    f32 pad_24[3];
    void *owner;
    u32 angle;
} Packet_801AB6A0;

typedef struct Golla_801AB6A0 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x158 - 0x44];
    u16 owner_id;
    u8 pad15A[0x19C - 0x15A];
    void *f19c;
    u8 pad1A0[8];
    u8 *f1a8;
    Vec f1ac;
} Golla_801AB6A0;

typedef struct Owner_801AB6A0 {
    u8 pad0[0x3C];
    f32 y;
    u8 pad40[0x20];
    s32 rot;
} Owner_801AB6A0;

typedef struct Target_801AB868 {
    u8 pad0[0x2FC];
    Vec pos;
} Target_801AB868;

typedef struct Owner_801AB868 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 rot;
} Owner_801AB868;

typedef struct Flags_801AB868 {
    u8 pad0[0x18];
    u32 flags;
} Flags_801AB868;

typedef struct Golla_801AB868 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0xA4 - 0x44];
    Flags_801AB868 *fa4;
    u8 padA8[0x150 - 0xA8];
    f32 f150;
    u8 pad154[4];
    u16 owner_id;
    u8 pad15A[0x19C - 0x15A];
    Target_801AB868 *f19c;
    u8 pad1A0[8];
    Target_801AB868 *f1a8;
} Golla_801AB868;

extern u8 *photon_blast_shared_resource;
extern "C" {

s32 scroll_strip_uvs(void *, s16, int);
s32 post_translate_matrix(void *);
extern NJS_ARGB saved_model_draw_color;
extern NJS_ARGB model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
void *golla_photon_blast_buffer_pair;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
u32 __cvt_fp2unsigned(f32);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
}
const char *TPhotonGolla__class_name = "TPhotonGolla";
extern const Packet_801AB6A0 photon_golla_concentrate_packet = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 500.0f, 5.0f, 30.0f }, NULL, 0
};
extern u8 identity_matrix[];
extern "C" {

f32 vec_squared_length(u8 *arg0);
u16 get_entity_id(void *);
}


void TPhotonGolla::sub_801AB688() { this->m_15c = 0.0f; *(float*)((char*)this + 0x160) = 0.0f; this->m_164 = 0.0f; *(float*)((char*)this + 0x168) = 0.0f; }

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((Golla_801AB6A0 *)arg0)
void TPhotonGolla::spawn_concentrate(void *arg0) {
    Vec target;
    Vec local;
    Vec rotated;
    Owner_801AB6A0 *owner;
    u32 angle;
    uaddr beam;
    if (self->f19c == NULL) {
        owner = (Owner_801AB6A0 *)find_entity_by_id(self->owner_id);
        local.x = 0.0f;
        if (owner != NULL) {
            local.y = owner->y;
        }
        local.z = 1e+02f;
        push_matrix_from(identity_matrix);
        if (owner != NULL) {
            rotate_matrix_y(0, owner->rot);
        }
        rotate_vector_by_matrix(0, &local, &rotated);
        pop_matrices(1);
        VecCopy((Vec *)&target, (const Vec *)&self->pos);
        vec3_add_to(&target, &rotated);
    } else {
        VecCopy((Vec *)&target, (const Vec *)(self->f1a8 + 0x2FC));
    }
    Vec direction = target;
    subtract_vector(&direction, &self->f1ac);
    normalize_vector(&direction);

    angle = __cvt_fp2unsigned(3.6e+02f * (3.0517578e-05f * (f32)rand()) + 1.0f);
    Packet_801AB6A0 packet = photon_golla_concentrate_packet;
    packet.origin.x = self->f1ac.x;
    packet.origin.y = self->f1ac.y;
    packet.origin.z = self->f1ac.z;
    packet.target.x = target.x;
    packet.target.y = target.y;
    packet.target.z = target.z;
    packet.direction.x = direction.x;
    packet.direction.y = direction.y;
    packet.direction.z = direction.z;
    packet.owner = self->f1a8;
    packet.angle = angle;
    beam = (uaddr)TObject::operator new(0x10C);
    if (beam != 0) {
        __ct__18TPhotonConcentrateFPUcll((u8 *)beam, (u8 *)&packet, (saddr)self, (s32)self->owner_id);
    }
}
#undef self
#pragma pop

#define self ((Golla_801AB868 *)arg0)
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
void TPhotonGolla::collect_hit_targets(void *arg0) {
    s32 i;
    Target_801AB868 *candidate;
    TObjPlayer::init_all_slots();
    ((TObjCollidable *)self)->mark_enemy_body_contacts();
    if (self->fa4->flags & 0x100000) {
        for (i = 0; i < 16; i++) {
            candidate = (Target_801AB868 *)TObjPlayer::get_battle_param(i);
            if (candidate != NULL) {
                if (self->f1a8 != NULL) {
                    Vec selected_delta = self->f1a8->pos;
                    Owner_801AB868 *owner;
                    f32 selected_distance;
                    subtract_vector(&selected_delta, &self->pos);
                    Vec candidate_delta = candidate->pos;
                    subtract_vector(&candidate_delta, &self->pos);
                    selected_distance = vec_squared_length((u8 *)&selected_delta);
                    if (vec_squared_length((u8 *)&candidate_delta) < selected_distance) {
                        self->f1a8 = candidate;
                    }
                    owner = (Owner_801AB868 *)find_entity_by_id(self->owner_id);
                    Vec direction = self->f1a8->pos;
                    Vec forward;
                    Vec left;
                    Vec right;
                    if (owner != NULL) {
                        subtract_vector(&direction, &owner->pos);
                    }
                    normalize_vector(&direction);
                    forward.y = forward.x = 0.0f;
                    forward.z = 1.0f;
                    push_matrix_from(identity_matrix);
                    if (owner != NULL) {
                        rotate_matrix_y(0, owner->rot + 0x1555);
                    }
                    rotate_vector_by_matrix(0, &forward, &left);
                    pop_matrices(1);
                    push_matrix_from(identity_matrix);
                    if (owner != NULL) {
                        rotate_matrix_y(0, owner->rot - 0x1555);
                    }
                    rotate_vector_by_matrix(0, &forward, &right);
                    pop_matrices(1);
                    vec3_dot(&direction, &left);
                    vec3_dot(&direction, &right);
                    if (!(vec3_dot(&direction, &left) > 0.65f) ||
                        !(vec3_dot(&direction, &right) > 0.65f)) {
                        self->f1a8 = NULL;
                    }
                } else {
                    self->f1a8 = candidate;
                }
            }
        }
    }
    if (self->f1a8 != NULL) {
        queue_photon_blast_hit(get_entity_id(self->f1a8), 2, 0, self->f150);
    }
    self->f19c = self->f1a8;
}
#pragma pop
#undef self

void TPhotonGolla::render() {
    Self_801ABAA0 *self = (Self_801ABAA0 *)this;
    if (this->m_1c4 != 0) {
        scroll_strip_uvs(golla_photon_blast_buffer_pair, self->f14C, 0);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
        push_matrix();
        post_translate_matrix(&self->pos);
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

void TPhotonGolla::run_task() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801ABBAC, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_801ABBAC, spC) == 0x4);
    Stack_801ABBAC stack;
    s32 temp_r0;
    saddr entity;
    *(s32 *)&this->unk_1C8 = (s32) (*(s32 *)&this->unk_1C8 + 1);
    if (((s32) *(s32 *)&this->unk_1C8 == 0x32) && ((s32) this->m_1c4 == 0)) {
        this->m_1c4 = 1;
        *(s32 *)&this->unk_1C8 = 0;
        entity = (saddr)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x158)));
        if (entity != 0) {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(entity + 0x38));
        }
        stack.spC += 3e+01f;
        new TPhotonMagicSquare((TObject *)arg0, 3, (Vec *)&stack.sp8, 0xFA, 0.5f);
    }
    if ((5e+01f == (f32) *(s32 *)&this->unk_1C8) && ((s16) this->requested_action == 1)) {
        ((TPhotonBlastSummon *)arg0)->begin_photon_summon_camera(5);
        *(s32 *)&this->unk_1C8 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        ((TPhotonBlastSummon *)arg0)->spawn_photon_blast_attachment_effects(2);
    }
    this->m_1b8 = (s16) this->requested_action;
    ((TPhotonBlastSummon *)arg0)->update_state();
    ((TObjMotion *)arg0)->advance_animation();
    ((TPhotonBlastSummon *)arg0)->update_photon_blast_attachments();
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (*(s16 *)((s8 *)arg0 + 0x14C) + 0xF);
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (u8) *(s16 *)((s8 *)arg0 + 0x14C);
    if ((s32) *(s32 *)&this->unk_1C8 == 0x50) {
        VecCopy((Vec *)(arg0 + 0x1AC), &this->attachments[2].pos);
        spawn_particle_effect((const Vec *)(arg0 + 0x1AC), 0x133);
        TPhotonGolla::spawn_concentrate(arg0);
    }
    temp_r0 = *(s32 *)&this->unk_1C8;
    if ((temp_r0 == 0x56) || (temp_r0 == 0x5C) || (temp_r0 == 0x62) || (temp_r0 == 0x68) || (temp_r0 == 0x6E) || (temp_r0 == 0x74)) {
        TPhotonGolla::spawn_concentrate(arg0);
    }
    if ((s32) this->m_1c4 != 0) {
        play_persistent_sound(0x4002462F, (saddr)arg0, 0, 0, 0);
    }
}


extern "C" {

s32 free_collision_body_parts(void *);

extern void *lbl_804C35F4[];

void *destroy__12TPhotonGollaFPvs(void *photon_golla, s16 arg1) {
    if (photon_golla != NULL) {
        *(s32 **)((s8 *)photon_golla + 0x18) = (s32 *)lbl_804C35F4;
        ((TPhotonGolla *)photon_golla)->update_if_active();
        ((TPhotonBlastSummon *)photon_golla)->free_photon();
        ((TObjCollidable *)photon_golla)->unregister_object_by_id();
        free_collision_body_parts(photon_golla);
        __dt__18TPhotonBlastSummonFv(photon_golla, 0);
        if (arg1 > 0) {
            TObject::operator delete(photon_golla);
        }
    }
    return photon_golla;
}

}


#include "pso/unk/TLobby_802268F4.h"

#include "pso/unk/text_801ABE14.h"


extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void sub_801AB688__12TPhotonGollaFv(void *);

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void enter_scene__18TPhotonBlastSummonFv();
extern "C" void render__12TPhotonGollaFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__10TObjMotionFv();
extern "C" void run_task__12TPhotonGollaFv();
extern "C" void update_if_active__18TPhotonBlastSummonFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
#pragma push
#pragma opt_propagation off
void *photon_blast_golla_params[8] = {
    (void *)0x30000, (void *)0x4, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0xb, (void *)0x3f800000, (void *)0x0,
};
void *lbl_804C35C8[11] = {
    (void *)0x0, (void *)0xc1f00000, (void *)0x0, (void *)0x43fa0000,
    (void *)0x43fa0000, (void *)0x0, (void *)0x18007, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804C35F4[17] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__12TPhotonGollaFPvs, (void *)&run_task__12TPhotonGollaFv,
    (void *)&render__12TPhotonGollaFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&enter_scene__18TPhotonBlastSummonFv, (void *)&update_if_active__18TPhotonBlastSummonFv,
    (void *)0x0,
};
u8 *TPhotonGolla__ct(u8 *summon, u8 *arg1) {
    Vec pos;
    u8 *e;
    __ct__18TPhotonBlastSummonFv(summon);
    *(u8 **)((s8 *)summon + 0x18) = (u8 *)lbl_804C35F4;
    ((TPhotonGolla *)summon)->m_name = TPhotonGolla__class_name;
    *(s32 *)((s8 *)summon + 0x138) = 2;
    VecCopy((Vec *)(summon + 0x38), (const Vec *)arg1);
    *(u16 *)((s8 *)summon + 0x158) = *(u16 *)((s8 *)arg1 + 0xC);
    init_collision_body_parts(summon, (u8 *)lbl_804C35C8, 1);
    ((TObjCollidable *)summon)->refresh_collision_body_centers();
    ((TObjPlayer *)summon)->register_object_by_id();
    *(s32 *)((s8 *)summon + 0x1A8) = 0;
    ((TPhotonGolla *)summon)->m_1a4 = (u8 *)find_entity_by_id(*(u16 *)((s8 *)summon + 0x158));
    e = ((TPhotonGolla *)summon)->m_1a4;
    if (e != NULL) {
        ((TPhotonGolla *)summon)->rotation_y = *(s32 *)((s8 *)e + 0x60);
    } else {
        ((TPhotonGolla *)summon)->rotation_y = 0;
    }
    *(s32 *)((s8 *)summon + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x48);
    ((TPhotonGolla *)summon)->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x4C);
    ((TObjMotion *)summon)->set_field_d8((saddr) photon_blast_golla_params);
    ((TObjMotion *)summon)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    ((TPhotonGolla *)summon)->requested_action = 1;
    ((TObjMotion *)summon)->set_animation(((TPhotonGolla *)summon)->requested_action);
    ((TObjMotion *)summon)->set_field_b8(((TPhotonGolla *)summon)->requested_action);
    ((TPhotonGolla *)summon)->m_1b8 = 1;
    ((TPhotonGolla *)summon)->m_1bc = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)summon + 0x1C0) = *(s32 *)((s8 *)arg1 + 0x14);
    ((TPhotonGolla *)summon)->m_1c4 = 0;
    ((TPhotonGolla *)summon)->camera_script = 5;
    ((TPhotonGolla *)summon)->enter_scene();
    *(s32 *)((s8 *)summon + 0x1C8) = 0;
    switch (get_current_floor_area()) {
    case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        new TPhotonRainbow((TObject *)summon, &((TObjBase *)summon)->position, 1);
        break;
    default:
        new TPhotonRainbow((TObject *)summon, &((TObjBase *)summon)->position, 0);
        break;
    }
    ((TPhotonGolla *)summon)->m_19c = 0;
    TPhotonGolla::collect_hit_targets(summon);
    ((void (*)(void *, int)) sub_801AB688__12TPhotonGollaFv)(summon, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)((s8 *)summon + 0x1C0) == 1) {
        *(s32 *)((s8 *)summon + 0x154) |= 1;
    }
    ((TPhotonGolla *)summon)->power = *(f32 *)((s8 *)arg1 + 0x20);
    if (((TPhotonGolla *)summon)->m_1bc == 0) {
        ((TObjMotion *)summon)->set_field_b8(0);
        ((TPhotonBlastSummon *)summon)->begin_photon_summon_camera(5);
        ((TPhotonGolla *)summon)->m_1bc = 1;
        ((TPhotonGolla *)summon)->m_1b8 = 0;
        ((TPhotonGolla *)summon)->m_1c4 = 1;
        e = (u8 *)find_entity_by_id(*(u16 *)((s8 *)summon + 0x158));
        if (e != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)(e + 0x38));
        }
        pos.y += 3e+01f;
        new TPhotonMagicSquare((TObject *)summon, 3, &pos, 0x96, 0.5f);
        ((TPhotonBlastSummon *)summon)->spawn_photon_blast_attachment_effects(2);
        play_cue_stream_file((saddr)"goula2.adx");
    } else {
        spawn_photon_blast_opening_effects(2, *(u16 *)((s8 *)summon + 0x158));
        play_cue_stream_file((saddr)"goula.adx");
    }
    return summon;
}
#pragma pop

}

void TObjPlayer::destroy_static_buffer_pair() {
    if (golla_photon_blast_buffer_pair != NULL) {
        destroy_buffer_pair(golla_photon_blast_buffer_pair, 1);
    }
    golla_photon_blast_buffer_pair = NULL;
}

void create_golla_photon_blast_model(void) {
    saddr temp_r3;
    saddr var_r0;
    temp_r3 = (saddr)::operator new(0x14);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TLobby *)temp_r3)->alloc_tables(*(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x48), 0));
    }
    golla_photon_blast_buffer_pair = (void *)var_r0;
}
