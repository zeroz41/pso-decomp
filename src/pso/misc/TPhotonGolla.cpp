#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/player/TObjPlayer_801AB608.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TPhotonGolla.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct Stack_801ABBAC {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct Color_801ABAA0 { f32 a, r, g, b; };

struct Vec_801ABAA0 { f32 x, y, z; };

struct Self_801ABAA0 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x38 - 0x28];
    Vec_801ABAA0 pos;
    u8 pad2[0x60 - 0x44];
    s32 f60;
    u8 pad3[0x14C - 0x64];
    s16 f14C;
    u8 pad4[0x15C - 0x14E];
    Color_801ABAA0 color;
    u8 pad5[0x1C4 - 0x16C];
    s32 started;
};

typedef struct Vec_801AB6A0 {
    f32 x, y, z;
} Vec_801AB6A0;

typedef struct Packet_801AB6A0 {
    Vec_801AB6A0 origin;
    Vec_801AB6A0 target;
    Vec_801AB6A0 direction;
    u8 pad24[0xC];
    void *owner;
    u32 angle;
} Packet_801AB6A0;

typedef struct Golla_801AB6A0 {
    u8 pad0[0x38];
    Vec_801AB6A0 pos;
    u8 pad44[0x158 - 0x44];
    u16 owner_id;
    u8 pad15A[0x19C - 0x15A];
    void *f19c;
    u8 pad1A0[8];
    u8 *f1a8;
    Vec_801AB6A0 f1ac;
} Golla_801AB6A0;

typedef struct Owner_801AB6A0 {
    u8 pad0[0x3C];
    f32 y;
    u8 pad40[0x20];
    s32 rot;
} Owner_801AB6A0;

typedef struct Vec_801AB868 {
    f32 x, y, z;
} Vec_801AB868;

typedef struct Target_801AB868 {
    u8 pad0[0x2FC];
    Vec_801AB868 pos;
} Target_801AB868;

typedef struct Owner_801AB868 {
    u8 pad0[0x38];
    Vec_801AB868 pos;
    u8 pad44[0x60 - 0x44];
    s32 rot;
} Owner_801AB868;

typedef struct Flags_801AB868 {
    u8 pad0[0x18];
    u32 flags;
} Flags_801AB868;

typedef struct Golla_801AB868 {
    u8 pad0[0x38];
    Vec_801AB868 pos;
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
extern u32 farlla_photon_blast_model_buffers;
extern "C" {
void *spawn_particle_effect(void *pos, s32 id);
s32 advance_animation_playback(void *);
void *find_entity_by_id(u16 id);
s32 spawn_photon_blast_attachment_effects(void *, int);
u8 *TPhotonMagicSquare__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u32 __nw__7TObjectFUl(int);

s32 scroll_strip_uvs(void *, s16, int);
s32 clear_render_context__10TObjPlayerFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
extern Color_801ABAA0 saved_model_draw_color;
extern Color_801ABAA0 model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern void *golla_photon_blast_buffer_pair;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
u8 *__ct__18TPhotonConcentrateFPUcll(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
u32 __cvt_fp2unsigned(f32);
int rand(void);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
void subtract_vector(void *, void *);
void normalize_vector(void *);
s32 push_matrix_from(void *src);
s32 pop_matrices(s32 arg0);
extern const Packet_801AB6A0 photon_golla_concentrate_packet;
extern u8 identity_matrix[];

Target_801AB868 *get_battle_param__10TObjPlayerFi(s32);
f32 vec_squared_length(u8 *arg0);
f32 vec3_dot(void *, void *);
u16 get_entity_id(void *);
}

void *destroy_buffer_pair(void *arg0, s16 arg1);

void TObjPlayer::destroy_buffers() {
    if ((u32) farlla_photon_blast_model_buffers != 0U) {
        destroy_buffer_pair((void *)farlla_photon_blast_model_buffers, 1);
    }
    farlla_photon_blast_model_buffers = 0U;
}

void create_farlla_photon_blast_model(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x14);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TLobby *)temp_r3)->alloc_tables(*(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 8), 0));
    }
    (*(s32 *)&farlla_photon_blast_model_buffers) = var_r0;
}

void TPhotonGolla::sub_801AB688() { this->m_15c = 0.0f; *(float*)((char*)this + 0x160) = 0.0f; this->m_164 = 0.0f; *(float*)((char*)this + 0x168) = 0.0f; }

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((Golla_801AB6A0 *)arg0)
s32 TPhotonGolla::spawn_concentrate(void *arg0) {
    Vec_801AB6A0 target;
    Vec_801AB6A0 local;
    Vec_801AB6A0 rotated;
    Owner_801AB6A0 *owner;
    u32 angle;
    u32 beam;
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
    Vec_801AB6A0 direction = target;
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
    beam = __nw__7TObjectFUl(0x10C);
    if (beam != 0) {
        __ct__18TPhotonConcentrateFPUcll((u8 *)beam, (u8 *)&packet, (s32)self, (s32)self->owner_id);
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
    ((TUnk_804AF8A0 *)self)->mark_enemy_body_contacts();
    if (self->fa4->flags & 0x100000) {
        for (i = 0; i < 16; i++) {
            candidate = get_battle_param__10TObjPlayerFi(i);
            if (candidate != NULL) {
                if (self->f1a8 != NULL) {
                    Vec_801AB868 selected_delta = self->f1a8->pos;
                    Owner_801AB868 *owner;
                    f32 selected_distance;
                    subtract_vector(&selected_delta, &self->pos);
                    Vec_801AB868 candidate_delta = candidate->pos;
                    subtract_vector(&candidate_delta, &self->pos);
                    selected_distance = vec_squared_length((u8 *)&selected_delta);
                    if (vec_squared_length((u8 *)&candidate_delta) < selected_distance) {
                        self->f1a8 = candidate;
                    }
                    owner = (Owner_801AB868 *)find_entity_by_id(self->owner_id);
                    Vec_801AB868 direction = self->f1a8->pos;
                    Vec_801AB868 forward;
                    Vec_801AB868 left;
                    Vec_801AB868 right;
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
        TObjFish::set_global_param(this->texture_id);
        push_matrix();
        post_translate_matrix(&self->pos);
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

void TPhotonGolla::run_task() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_801ABBAC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801ABBAC, spC) == 0x4) ? 1 : -1];
    Stack_801ABBAC stack;
    s32 temp_r0;
    s32 entity;
    u32 photon_magic_square;
    *(s32 *)&this->unk_1C8 = (s32) (*(s32 *)&this->unk_1C8 + 1);
    if (((s32) *(s32 *)&this->unk_1C8 == 0x32) && ((s32) this->m_1c4 == 0)) {
        this->m_1c4 = 1;
        *(s32 *)&this->unk_1C8 = 0;
        entity = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x158)));
        if (entity != 0) {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(entity + 0x38));
        }
        stack.spC += 3e+01f;
        photon_magic_square = __nw__7TObjectFUl(0xD0);
        if (photon_magic_square != 0U) {
            TPhotonMagicSquare__ct((u8 *)photon_magic_square, (s32)arg0, 3, (s32)&stack.sp8, 0xFA, (f32)0.5f);
        }
    }
    if ((5e+01f == (f32) *(s32 *)&this->unk_1C8) && ((s16) this->m_b8 == 1)) {
        ((TUnk_804C3248 *)arg0)->begin_photon_summon_camera(5);
        *(s32 *)&this->unk_1C8 = 0;
        ((TObjMotion *)arg0)->set_field_b8(0);
        spawn_photon_blast_attachment_effects(arg0, 2);
    }
    this->m_1b8 = (s16) this->m_b8;
    ((TUnk_804C3248 *)arg0)->update_state();
    advance_animation_playback(arg0);
    ((TUnk_804C3248 *)arg0)->update_photon_blast_attachments();
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (*(s16 *)((s8 *)arg0 + 0x14C) + 0xF);
    *(s16 *)((s8 *)arg0 + 0x14C) = (s16) (u8) *(s16 *)((s8 *)arg0 + 0x14C);
    if ((s32) *(s32 *)&this->unk_1C8 == 0x50) {
        VecCopy((Vec *)(arg0 + 0x1AC), (const Vec *)(this->m_148 + 0x44));
        spawn_particle_effect((arg0 + 0x1AC), 0x133);
        TPhotonGolla::spawn_concentrate(arg0);
    }
    temp_r0 = *(s32 *)&this->unk_1C8;
    if ((temp_r0 == 0x56) || (temp_r0 == 0x5C) || (temp_r0 == 0x62) || (temp_r0 == 0x68) || (temp_r0 == 0x6E) || (temp_r0 == 0x74)) {
        TPhotonGolla::spawn_concentrate(arg0);
    }
    if ((s32) this->m_1c4 != 0) {
        play_persistent_sound(0x4002462F, (s32)arg0, 0, 0, 0);
    }
}

#include "types.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TPhotonGolla.h"

extern "C" {

s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

extern void *lbl_804C35F4[];

void *destroy__12TPhotonGollaFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)lbl_804C35F4;
        ((TPhotonGolla *)arg0)->update_if_active();
        ((TUnk_804C3248 *)arg0)->free_photon();
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        destroy_photon_motion_object(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/misc/TPhotonRainbow_801AE640.h"
#include "pso/misc/obj_band.h"
#include "pso/player/TObjPlayer_801AB608.h"
#include "pso/unk/text_801ABE14.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804C3248.h"
#include "pso/misc/TPhotonGolla.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"

struct Stack_801ABE14 { f32 x, y, z; };

extern "C" {
void *find_entity_by_id(u16 id);
s32 init_collision_body_parts(void *, void *, int);
void sub_801AB688__12TPhotonGollaFv(void *);
u8 *TPhotonMagicSquare__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
extern u8 lbl_80446DA8[];
extern u8 lbl_80446DB4[];
extern s32 lbl_805D34E8;
extern u8 *photon_blast_shared_resource;

extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void interact__13TUnk_804AF8A0Fl();
extern "C" void get_name__13TUnk_804B9870Fv();
extern "C" void vfunc_9__13TUnk_804B9870Fv();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void enter_scene__13TUnk_804C3248Fv();
extern "C" void render__12TPhotonGollaFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__10TObjMotionFv();
extern "C" void run_task__12TPhotonGollaFv();
extern "C" void update_if_active__13TUnk_804C3248Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
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
    (void *)&render__12TPhotonGollaFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&vfunc_9__13TUnk_804B9870Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__13TUnk_804B9870Fv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&enter_scene__13TUnk_804C3248Fv, (void *)&update_if_active__13TUnk_804C3248Fv,
    (void *)0x0,
};
u8 *TPhotonGolla__ct(u8 *arg0, u8 *arg1) {
    Stack_801ABE14 pos;
    u8 *e;
    void *p;
    photon_base_ct(arg0);
    *(u8 **)((s8 *)arg0 + 0x18) = (u8 *)lbl_804C35F4;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D34E8;
    *(s32 *)((s8 *)arg0 + 0x138) = 2;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)arg1);
    *(u16 *)((s8 *)arg0 + 0x158) = *(u16 *)((s8 *)arg1 + 0xC);
    init_collision_body_parts(arg0, (u8 *)lbl_804C35C8, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    *(s32 *)((s8 *)arg0 + 0x1A8) = 0;
    ((TPhotonGolla *)arg0)->m_1a4 = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x158));
    e = ((TPhotonGolla *)arg0)->m_1a4;
    if (e != NULL) {
        ((TPhotonGolla *)arg0)->rotation_y = *(s32 *)((s8 *)e + 0x60);
    } else {
        ((TPhotonGolla *)arg0)->rotation_y = 0;
    }
    *(s32 *)((s8 *)arg0 + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x48);
    ((TPhotonGolla *)arg0)->texture_id = *(s32 *)((s8 *)(*(u8 **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x4C);
    ((TObjMotion *)arg0)->set_field_d8((s32) photon_blast_golla_params);
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)photon_blast_shared_resource + 0x430));
    ((TPhotonGolla *)arg0)->m_b8 = 1;
    ((TObjMotion *)arg0)->set_animation(((TPhotonGolla *)arg0)->m_b8);
    ((TObjMotion *)arg0)->set_field_b8(((TPhotonGolla *)arg0)->m_b8);
    ((TPhotonGolla *)arg0)->m_1b8 = 1;
    ((TPhotonGolla *)arg0)->m_1bc = *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x1C0) = *(s32 *)((s8 *)arg1 + 0x14);
    ((TPhotonGolla *)arg0)->m_1c4 = 0;
    ((TPhotonGolla *)arg0)->m_134 = 5;
    ((TPhotonGolla *)arg0)->enter_scene();
    *(s32 *)((s8 *)arg0 + 0x1C8) = 0;
    switch (TOKeyMachine01::get_global_state()) {
    case 11: case 12: case 13: case 14:
    case 30: case 31: case 32: case 33:
        p = (void *)__nw__7TObjectFUl(0xAC);
        if (p != NULL) {
            ((u8 *(*)(void *, void *, void *, int)) TPhotonRainbow__ct)(p, arg0, arg0 + 0x38, 1);
        }
        break;
    default:
        p = (void *)__nw__7TObjectFUl(0xAC);
        if (p != NULL) {
            ((u8 *(*)(void *, void *, void *, int)) TPhotonRainbow__ct)(p, arg0, arg0 + 0x38, 0);
        }
        break;
    }
    ((TPhotonGolla *)arg0)->m_19c = 0;
    TPhotonGolla::collect_hit_targets(arg0);
    ((void (*)(void *, int)) sub_801AB688__12TPhotonGollaFv)(arg0, *(u8 *)((s8 *)arg1 + 0x1C));
    if (*(s32 *)((s8 *)arg0 + 0x1C0) == 1) {
        *(s32 *)((s8 *)arg0 + 0x154) |= 1;
    }
    ((TPhotonGolla *)arg0)->m_150 = *(f32 *)((s8 *)arg1 + 0x20);
    if (((TPhotonGolla *)arg0)->m_1bc == 0) {
        ((TObjMotion *)arg0)->set_field_b8(0);
        ((TUnk_804C3248 *)arg0)->begin_photon_summon_camera(5);
        ((TPhotonGolla *)arg0)->m_1bc = 1;
        ((TPhotonGolla *)arg0)->m_1b8 = 0;
        ((TPhotonGolla *)arg0)->m_1c4 = 1;
        e = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x158));
        if (e != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)(e + 0x38));
        }
        pos.y += 3e+01f;
        p = (void *)__nw__7TObjectFUl(0xD0);
        if (p != NULL) {
            TPhotonMagicSquare__ct((u8 *)p, (s32)arg0, 3, (s32)&pos, 0x96, (f32)0.5f);
        }
        spawn_photon_blast_attachment_effects(arg0, 2);
        play_cue_stream_file((s32)lbl_80446DA8);
    } else {
        spawn_photon_blast_opening_effects(2, *(u16 *)((s8 *)arg0 + 0x158));
        play_cue_stream_file((s32)lbl_80446DB4);
    }
    return arg0;
}
#pragma pop

}
