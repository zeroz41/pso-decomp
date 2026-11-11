#include "types.h"
#include "pso/unk/TUnk_804C3248.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/player/TObjPlayer_800D8A2C.h"
#include "pso/system/vector.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TUnk_804C3248.h"
#include "pso/map/FloorArea.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
extern "C" { void setup_photon_blast_camera__13TUnk_804C3248Fv(u8 *); }
#pragma push

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
struct Stack_801A7310 {
    s8 sp8;
    s8 sp9;
    s16 spA;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_801A7310_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s32 set_scripted_camera_pose(int, int, void *);
extern RecoveredGlobal_801A7310_TCameraCtrl__data_804FF628 TCameraCtrl__view_state;
extern u32 lbl_805D5D20;
const f32 *get_photon_blast_entry__10TObjPlayerFi(s32);
}
extern u32 lbl_805D5D18;

void clear_deferred_photon_blast_hits(void) {
    s32 i;
    deferred_photon_blast_hit_count = 0;
    for (i = 0; i < 32; i++) {
        deferred_photon_blast_hit_queue[i].identity = 0xFFFF;
        deferred_photon_blast_hit_queue[i].value = 0.0f;
        deferred_photon_blast_hit_queue[i].kind = -1;
    }
}

void clear_photon_blast_hits(void) {
    s32 i;
    photon_blast_hit_count = 0;
    for (i = 0; i < 32; i++) {
        photon_blast_hit_queue[i].identity = 0xFFFF;
        photon_blast_hit_queue[i].value = 0.0f;
        photon_blast_hit_queue[i].kind = -1;
    }
}

void queue_deferred_photon_blast_hit(u32 arg0, s32 arg1, s32 arg2) {
    s32 found = 0;
    if (deferred_photon_blast_hit_count < 0x20) {
        const f32 *e = get_photon_blast_entry__10TObjPlayerFi(arg1);
        if (arg2 == 0) {
            s32 i;
            for (i = 0; i < deferred_photon_blast_hit_count; i++) {
                if (arg0 == deferred_photon_blast_hit_queue[i].identity) {
                    found = 1;
                }
            }
        }
        if (found == 0) {
            deferred_photon_blast_hit_queue[deferred_photon_blast_hit_count].kind = arg1;
            deferred_photon_blast_hit_queue[deferred_photon_blast_hit_count].value = e[0];
            deferred_photon_blast_hit_queue[deferred_photon_blast_hit_count].identity = arg0;
            lbl_805D5D20 = arg0;
            deferred_photon_blast_hit_count++;
        }
    }
}

void queue_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale) {
    const f32 *entry;
    s32 duplicate = 0;
    s32 i;
    if (photon_blast_hit_count >= 32) {
        return;
    }
    entry = get_photon_blast_entry__10TObjPlayerFi(kind);
    if (allow_duplicate == 0) {
        for (i = 0; i < photon_blast_hit_count; i++) {
            if (photon_blast_hit_queue[i].identity == identity) {
                duplicate = 1;
            }
        }
    }
    if (duplicate == 0) {
        photon_blast_hit_queue[photon_blast_hit_count].kind = kind;
        photon_blast_hit_queue[photon_blast_hit_count].value = *entry;
        photon_blast_hit_queue[photon_blast_hit_count].identity = identity;
        lbl_805D5D18 = identity;
        photon_blast_hit_count = photon_blast_hit_count + 1;
    }
}

void queue_deferred_photon_blast_support(u32 identity, s32 kind, s32 allow_duplicate) {
    ((void (*)(u32, s32, s32, f32))queue_deferred_photon_blast_hit)(identity, kind, allow_duplicate, 1.0f);
}

void queue_photon_blast_support(void) {
    ((s32 (*)(f32))queue_photon_blast_hit)(1.0f);
}
typedef char RecoveredGlobal_801A7310_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_801A7310_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

void TUnk_804C3248::begin_photon_summon_camera(s8 arg1) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_801A7310, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_801A7310, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_801A7310, spA) == 0x2) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801A7310, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_801A7310, sp10) == 0x8) ? 1 : -1];
    Stack_801A7310 stack;
    s32 temp_r3;
    stack.sp9 = arg1;
    stack.sp8 = get_current_floor_area() == AREA_DARK_FALZ;
    stack.spA = 0;
    stack.spC = 0.0f;
    stack.sp10 = 1.0f;
    if ((*(s32 *)((s8 *)&TCameraCtrl__view_state.value + 8) & 4) || (*(s32 *)((s8 *)&TCameraCtrl__view_state.value + 8) & 8)) {
        TCameraCtrl::select_active_controller(5);
    }
    ((TCameraCtrl *)(&stack.sp8))->cache_target_and_forward(0x4222);
    temp_r3 = (long) (arg0 + 0x38);
    set_scripted_camera_pose(temp_r3, temp_r3, (u8 *)&this->rotation_x);
    *(s32 *)((s8 *)arg0 + 0xFC) = 1;
}

#pragma pop

#pragma push

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

typedef Vec Vec_801A73B0;

struct PbCamera_801A73B0 {
    u8 pad0[0x104];
    Vec_801A73B0 target;
    Vec_801A73B0 position;
    Vec_801A73B0 destination_target;
    Vec_801A73B0 destination_position;
};

struct PbCameraParams_801A73B0 {
    u8 pad0[0x14];
    s32 projection;
    s32 pad18;
    Vec_801A73B0 position;
    Vec_801A73B0 target;
    u8 pad34[0x50 - 0x34];
};

typedef struct Vec_801A7578 { f32 x, y, z; } Vec_801A7578;

struct Node_801A7578 {
    u8 pad0[4];
    Vec_801A7578 pos;
    s32 id;
    u8 pad1[0x20 - 0x14];
};

struct Reg_801A7578 {
    struct Node_801A7578 *list;
    s32 count;
};

typedef struct Vec_801A7428 { f32 x, y, z; } Vec_801A7428;

struct Rec_801A7428 { s32 a, b, c; Vec_801A7428 v; s32 d; };

struct PhotonAttachmentDef_801A7748 { s32 unk0, unk4, unk8, unkC; s32 unk10[3]; s32 unk1C; };

struct Group_801A7428 {
    PhotonAttachmentDef_801A7748 *attachments;
    s32 attachment_count;
    Rec_801A7428 *entries;
    s32 count;
};

struct Obj_801A7428 {
    u8 pad0[0x38];
    Vec_801A7428 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
};

extern "C" {
void set_active_camera_pose_from_params(u8 *arg0);
void update_photon_blast_camera_pose(struct PbCamera_801A73B0 *self);
void get_camera_ctrl__9TObjEneDDFv(Vec_801A7578 *, Vec_801A7578 *);
extern Vec_801A7578 lbl_80446A44;
extern struct Reg_801A7578 photon_blast_joint_origins[];
extern s32 photon_blast_joint_index;
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void *find_entity_by_id(u16 id);
void matrix_mult_vec(s32, Vec_801A7428 *, Vec_801A7428 *);
void rotate_matrix_y(s32, s32);
s32 push_matrix_from(void *src);
s32 pop_matrices(s32 arg0);
extern Group_801A7428 photon_blast_attachment_table[];
void update_photon_blast_camera_pose(struct PbCamera_801A73B0 *self) {
    struct PbCameraParams_801A73B0 parameters;
    approach_vector_fixed_distance(&self->position, &self->destination_position, &self->position, 0.48f);
    approach_vector_fixed_distance(&self->target, &self->destination_target, &self->target, 0.55f);
    VecCopy((Vec *)&parameters.position, (const Vec *)&self->position);
    VecCopy((Vec *)&parameters.target, (const Vec *)&self->target);
    parameters.projection = 0x4222;
    set_active_camera_pose_from_params((u8 *)&parameters);
}

void spawn_photon_blast_opening_effects(s32 arg0, s32 arg1) {
    Rec_801A7428 rec;
    Vec_801A7428 pos;
    Obj_801A7428 *obj;
    Group_801A7428 *g;
    Rec_801A7428 *entries;
    s32 count;
    s32 i;
    obj = (Obj_801A7428 *)find_entity_by_id(arg1);
    if (obj == NULL) {
        return;
    }
    g = &photon_blast_attachment_table[arg0];
    count = g->count;
    if (count <= 0) {
        return;
    }
    entries = g->entries;
    for (i = 0; i < count; i++) {
        copy_effect_params((u8 *)&rec, (u8 *)&entries[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, obj->f60);
        matrix_mult_vec(0, &rec.v, &pos);
        pop_matrices(1);
        pos.x += obj->pos.x;
        pos.y += 30.0f + obj->pos.y;
        pos.z += obj->pos.z;
        create_timed_particle_emitter(&pos, rec.a, rec.b, rec.c);
    }
}
}

void copy_effect_params(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)arg0 + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(ByteBlock_C *)((s32) arg0 + 0xC) = *(const ByteBlock_C *)((s32) arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
}
void publish_photon_blast_joint_origins(void) {
    s32 i;
    for (i = 0; i < photon_blast_joint_origins->count; i++) {
        struct Node_801A7578 *node = &photon_blast_joint_origins->list[i];
        if (photon_blast_joint_index == node->id) {
            Vec_801A7578 origin = lbl_80446A44;
            get_camera_ctrl__9TObjEneDDFv(&origin, &node->pos);
        }
    }
    photon_blast_joint_index += 1;
}

#pragma pop

#pragma push

struct PhotonAttachment_801A7638;
struct PhotonDrawOwner_801A7638 {
    u8 unknown00[0x100];
    s32 binding_count;
    u8 unknown104[0x44];
    PhotonAttachment_801A7638 *bindings;
};

typedef struct Vec_801A7680 { f32 x, y, z; } Vec_801A7680;

struct Eff_801A7680 {
    void *obj;
    Vec_801A7680 pos;
    s32 flag;
    s32 angles[3];
};

struct Self_801A7680 {
    u8 pad0[0x38];
    Vec_801A7680 pos;
    u8 pad1[0x60 - 0x44];
    s32 rotation_y;
    u8 pad2[0x100 - 0x64];
    u32 count;
    u8 pad3[0x148 - 0x104];
    struct Eff_801A7680 *effects;
};

extern "C" {

int update_all__8TFogCtrlFl(void*);
// Unit direction rotated into each attachment's heading.
extern Vec_801A7428 lbl_80446A38;

void TObjPlayer::clear_render_context() { set_chunk_model_node_callback(0); }

void TUnk_804C3248::set_photon_blast_joint_callback() {
    PhotonDrawOwner_801A7638 *self = (PhotonDrawOwner_801A7638 *)this;
    photon_blast_joint_index=0;
    photon_blast_joint_origins[0].list=(Node_801A7578 *)self->bindings;
    photon_blast_joint_origins[0].count=self->binding_count;
    set_chunk_model_node_callback((s32)publish_photon_blast_joint_origins);
}

void TUnk_804C3248::update_photon_blast_attachments() {
    struct Self_801A7680 *self = (struct Self_801A7680 *)this;
    u32 i;
    struct Eff_801A7680 *e;
    for (i = 0; i < self->count; i++) {
        if (((TObject *)(self->effects[i].obj))->all_parents_unqueued_for_destruction() == 0) {
            self->effects[i].obj = NULL;
        }
        e = &self->effects[i];
        if (e->obj != NULL) {
            if (e->flag >= 0) {
                ((TParticleCtrl *)e->obj)->set_position(&e->pos);
            } else {
                ((TParticleCtrl *)e->obj)->set_position(&self->pos);
            }
        }
    }
}

void TUnk_804C3248::free_photon() { void* m = *(void* *)&this->m_148; if (m) mem_free(m); }

void spawn_photon_blast_attachment_effects(struct Self_801A7680 *self, s32 kind) {
    s32 b;
    s32 id;
    s32 a;
    PhotonAttachmentDef_801A7748 *def;
    PhotonAttachmentDef_801A7748 *defs;
    u32 i;
    s32 flags;
    Group_801A7428 *group;

    group = &photon_blast_attachment_table[kind];
    self->count = group->attachment_count;
    if (self->count != 0) {
        self->effects = (struct Eff_801A7680 *)mem_alloc(self->count * sizeof(struct Eff_801A7680));
        defs = group->attachments;
        for (i = 0; i < self->count; i++) {
            s32 angles[3];
            s32 rot[3];
            def = &defs[i];
            a = def->unk4;
            b = def->unk8;
            id = def->unk0;
            copy_xyz(angles, def->unk10);
            flags = def->unk1C;
            Vec_801A7428 dir = lbl_80446A38;
            if (angles[2] != 0 || angles[0] != 0 || angles[1] != 0) {
                push_matrix_from(identity_matrix);
                rotate_matrix_z(0, angles[2]);
                rotate_matrix_x(0, angles[0]);
                rotate_matrix_y(0, angles[1]);
                matrix_mult_vec(0, &dir, &dir);
                pop_matrices(1);
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, self->rotation_y);
                matrix_mult_vec(0, &dir, &dir);
                pop_matrices(1);
                direction_to_rotation_xz((u8 *)&dir, &rot[0], &rot[2]);
                rot[1] = 0;
            } else {
                rot[0] = 0;
                rot[1] = 0;
                rot[2] = 0;
            }
            self->effects[i].obj = create_timed_particle_emitter_with_angles(&self->pos, rot, id, a, b, flags & 0xFFFF);
            self->effects[i].flag = def->unkC;
            copy_xyz(self->effects[i].angles, angles);
        }
    }
}


int update_all_default__8TFogCtrlFv(void) { return update_all__8TFogCtrlFl((void*)(0)); }
void apply_all_default__8TFogCtrlFv(void) { TFogCtrl::apply_all((s32)((void*)63), (s32)((void*)0)); }

#pragma pop

#pragma push
extern s32 TSceneSora__sky_active_flag;
extern u32 TSceneSora__instance;
u16 TCameraCtrl__sub_8006A5DC();
void *get_scripted_camera_playback();

s32 queue_destruction__7TObjectFv(void *);
void allow_rendering__7TObjectFv(TObject *arg0);

void disallow_rendering__7TObjectFv(TObject *arg0);

extern void *tl_05;

void TUnk_804C3248::update_if_active() {
    if (!(*(s32 *)&this->unk_154 & 1)) {
        TCameraCtrl::update();
        TSceneSora::update((s32)this);
        ((s32 (*)(void *))update_all_default__8TFogCtrlFv)(this);
        TObjPlayer__sub_800D8A6C();
    }
    if (tl_05 != 0) {
        allow_rendering__7TObjectFv((TObject *)tl_05);
    }
}

void TUnk_804C3248::enter_scene() {
    s32 arg0 = (s32)this;
    ((s32 (*)(void))setup_photon_blast_camera__13TUnk_804C3248Fv)();
    reset_state__10TSceneSoraFv(arg0);
    ((s32 (*)(s32))apply_all_default__8TFogCtrlFv)(arg0);
    TObjPlayer__sub_800D8A60();
    if (tl_05 != NULL) {
        disallow_rendering__7TObjectFv((TObject *)tl_05);
    }
}
void TSceneSora::update(s32 _w0) {
    TScene::set_ready();
    if ((u32) TSceneSora__instance != 0U) {
        TSceneSora__sky_active_flag = 1;
    }
}
void reset_state__10TSceneSoraFv(s32 _w0) {
    TScene::reset_counter();
    if ((u32) TSceneSora__instance != 0U) {
        TSceneSora__sky_active_flag = 0;
    }
}
void TUnk_804C3248::update_state() {
    switch (*(s32 *)((s8 *)this + 0xFC)) {
    case 0:
        ((s32 (*)(f32))update_photon_blast_camera_pose)(1.0f);
        return;
    case 1:
        if ((*(u16 *)((s8 *)(get_scripted_camera_playback()) + 2) & 1) || (TCameraCtrl__sub_8006A5DC() != 5)) {
            queue_destruction__7TObjectFv(this);
        }
        return;
    }
}

#pragma pop

#pragma push
s32 restore_player_cameras(void);
void __ct__10TObjMotionFP7TObject(void *, void *);
void __dl__7TObjectFPv(void *);
void *__dt__10TObjMotionFv(void *arg0, s16 arg1);

void TCameraCtrl::update() { restore_player_cameras(); TCameraCtrl::release_photon_blast_camera(); }

extern s32 __vt__13TUnk_804C3248[];

struct Vec_801A7B14
{
  f32 x;
  f32 y;
  f32 z;
};

s32 activate_camera_mode(s32 arg0);
void *get_player_by_client_id(s32 i);

extern s32 local_client_id;
void TUnk_804C3248::setup_photon_blast_camera() {
    u8 *arg0 = (u8 *)this;
  Vec_801A7B14 a = {-3.0f, 6.7f, 11.0f};
  Vec_801A7B14 b = {-9.0f, 58.0f, 32.0f};
  Vec_801A7B14 c = {0.0f, 8.0f, 0.0f};
  Vec_801A7B14 d = {0.0f, 56.0f, 0.0f};
  u8 *p;
  if ((*((s32 *)(arg0 + 0x138))) == 0)
  {
    b.x = -8.75f;
    b.y = 43.92f;
    b.x = 28.79f;
    d.x = 0.0f;
    d.y = 39.0f;
    d.x = 0.0f;
  }
  p = (u8 *)get_player_by_client_id(local_client_id);
  if (p != 0)
  {
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, *((s32 *)(p + 0x60)));
    ((void (*)(s32, void *, void *))matrix_mult_vec)(0, &a, &a);
    ((void (*)(s32, void *, void *))matrix_mult_vec)(0, &b, &b);
    ((void (*)(s32, void *, void *))matrix_mult_vec)(0, &c, &c);
    ((void (*)(s32, void *, void *))matrix_mult_vec)(0, &d, &d);
    pop_matrices(1);
    a.x += *((f32 *)(p + 0x38));
    a.y += *((f32 *)(p + 0x3C));
    a.z += *((f32 *)(p + 0x40));
    b.x += *((f32 *)(p + 0x38));
    b.y += *((f32 *)(p + 0x3C));
    b.z += *((f32 *)(p + 0x40));
    c.x += *((f32 *)(p + 0x38));
    c.y += *((f32 *)(p + 0x3C));
    c.z += *((f32 *)(p + 0x40));
    d.x += *((f32 *) (p - -0x38));
    d.y += *((f32 *)(p + 0x3C));
    d.z += *((f32 *)(p + 0x40));
    VecCopy((Vec *)(arg0 + 0x110), (const Vec *)&a);
    VecCopy((Vec *)(arg0 + 0x128), (const Vec *)&b);
    VecCopy((Vec *)(arg0 + 0x104), (const Vec *)&c);
    VecCopy((Vec *)(arg0 + 0x11C), (const Vec *)&d);
    activate_camera_mode(9);
  }
}

void *destroy_photon_motion_object(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804C3248;
        ((TUnk_804C3248 *)arg0)->m_148 = 0;
        __dt__10TObjMotionFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_06;

}
TUnk_804C3248::TUnk_804C3248() : TObjMotion((TObject *)tl_06) {
    this->m_134 = 0;
    this->m_100 = 0;
    *(u32 *)((s8 *)this + 0x138) = 0;
    this->m_150 = 1.0f;
    *(u32 *)((s8 *)this + 0x154) = 0;
    this->m_13c = 0.0f;
    *(f32 *)((s8 *)this + 0x140) = 0.0f;
    this->m_144 = 0.0f;
    this->m_148 = 0;
    *(u16 *)((s8 *)this + 0x14C) = 0;
    *(u32 *)((s8 *)this + 0xFC) = 0;
    *(f32 *)((s8 *)this + 0x104) = 0.0f;
    this->m_108 = 0.0f;
    *(f32 *)((s8 *)this + 0x10C) = 0.0f;
    this->m_110 = 0.0f;
    *(f32 *)((s8 *)this + 0x114) = 0.0f;
    this->m_118 = 0.0f;
    *(f32 *)((s8 *)this + 0x11C) = 0.0f;
    this->m_120 = 0.0f;
    *(f32 *)((s8 *)this + 0x124) = 1.0f;
    this->m_128 = 0.0f;
    *(f32 *)((s8 *)this + 0x12C) = 0.0f;
    this->m_130 = 1.0f;
}

#pragma pop

extern "C" {
PhotonAttachmentDef_801A7748 lbl_804C2438[10] = {
    {0x136, 0x1e, 0x14, 0x27, {0, 0, 0}, 0},
    {0x137, 0x14, 0x28, 0x11, {0, 0, 0}, 0},
    {0x137, 0x14, 0x28, 0x1b, {0, 0, 0}, 0},
    {0x138, 0x2d, 1, 0x27, {0, 0, 0}, 0},
    {0x139, 0xa, 0x32, 0x27, {0, 0, 0}, 0},
    {0x13a, 0x34, 0x14, 0x27, {0, 0, 0}, 0},
    {0x13b, 0x34, 0x14, 0x27, {0, 0, 0}, 0},
    {0x13d, 0x39, 1, 0x27, {0, 0, 0}, 0},
    {0x13c, 0x6b, 1, -2, {0, 0, 0}, 0},
    {0x140, 0x6b, 1, -2, {0, 0, 0}, 0},
};

PhotonAttachmentDef_801A7748 lbl_804C2578[9] = {
    {0x130, 0xa, 0x42, 0x21, {0, 0, 0}, 0},
    {0x131, 0x37, 0xf, 0x21, {0, 0, 0}, 0},
    {0x132, 0x37, 0x14, 0x21, {0, 0, 0}, 0},
    {0x132, 0x55, 3, 0x21, {0x4000, 0, 0}, 0},
    {0x133, 0x39, 1, 0x21, {0, 0, 0}, 0},
    {0x133, 0x4b, 1, 0x21, {0x4000, 0, 0}, 0},
    {0x141, 0x5a, 0x28, 4, {0, 0, 0}, 0},
    {0x141, 0x87, 5, 4, {0, 0, 0}, 0},
    {0x141, 0x91, 2, 4, {0, 0, 0}, 0},
};

PhotonAttachmentDef_801A7748 lbl_804C2698[32] = {
    {0x154, 1, 0x73, 0x15, {0, 0, 0}, 0},
    {0x155, 2, 0x73, 0x15, {0, 0, 0}, 0},
    {0x154, 1, 0x73, 0x1c, {0, 0, 0}, 0},
    {0x155, 2, 0x73, 0x1c, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x22, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x22, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x37, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x37, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x3e, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x3e, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x31, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x31, {0, 0, 0}, 0},
    {0x154, 1, 0x6e, 0x46, {0, 0, 0}, 0},
    {0x155, 2, 0x6e, 0x46, {0, 0, 0}, 0},
    {0x154, 1, 0x73, 0x4e, {0, 0, 0}, 0},
    {0x155, 2, 0x73, 0x4e, {0, 0, 0}, 0},
    {0x158, 1, 1, 2, {0, 0, 0}, 0},
    {0x158, 0x3c, 1, 2, {0, 0, 0}, 0},
    {0x15b, 1, 1, 2, {0, 0, 0}, 0},
    {0x15b, 0x3c, 1, 2, {0, 0, 0}, 0},
    {0x15e, 0x6a, 1, 0xc, {0, 0, 0}, 0},
    {0x15e, 0x6c, 1, 0xc, {0, 0, 0}, 0},
    {0x159, 0x6c, 7, 0xc, {0, 0x8000, 0}, 0},
    {0x156, 0x75, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x157, 0x75, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x156, 0x77, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x157, 0x77, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x156, 0x79, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x157, 0x79, 1, 0x4e, {0, 0x8000, 0}, 0},
    {0x174, 0x6a, 1, 0x4e, {0, 0, 0}, 0},
};

PhotonAttachmentDef_801A7748 lbl_804C2A98[6] = {
    {0x164, 0x4e, 1, 0x21, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x25, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x168, 0x57, 1, 5, {0, 0, 0}, 0},
    {0x168, 0x59, 1, 5, {0, 0, 0}, 0},
    {0x166, 1, 1, 5, {0, 0, 0}, 0},
};

PhotonAttachmentDef_801A7748 lbl_804C2B58[6] = {
    {0x164, 0x58, 1, 0x21, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x25, {0, 0, 0}, 0},
    {0x167, 1, 0x6e, 0x29, {0, 0, 0}, 0},
    {0x168, 0x57, 1, 5, {0, 0, 0}, 0},
    {0x168, 0x59, 1, 5, {0, 0, 0}, 0},
    {0x166, 1, 1, 5, {0, 0, 0}, 0},
};

PhotonAttachmentDef_801A7748 lbl_804C2C18[6] = {
    {0x152, 0x6d, 0xf, 0x11, {0, 0, 0}, 0},
    {0x152, 0x7c, 0xf, 0xc, {0, 0, 0}, 0},
    {0x165, 1, 1, 0x31, {0, 0, 0}, 0},
    {0x15b, 1, 1, 0x31, {0, 0, 0}, 0},
    {0x173, 0x42, 0x36, 0x1e, {0, 0, 0}, 0},
    {0x173, 0x42, 0x36, 0x28, {0, 0, 0}, 0},
};

PhotonAttachmentDef_801A7748 lbl_804C2CD8[19] = {
    {0x15c, 1, 0x6e, 0x22, {0, 0, 0}, 0},
    {0x15c, 1, 0x6e, 0x23, {0, 0, 0}, 0},
    {0x15d, 0x55, 0x16, 0xc, {-0x4000, -0x38e, 0}, 0},
    {0x15d, 0x55, 0x16, 0x11, {-0x4000, 0x38e, 0}, 0},
    {0x159, 0x57, 0xc, 7, {0x4000, 0, 0}, 0},
    {0x175, 0x5f, 1, 7, {0, 0, 0}, 0},
    {0x175, 0x64, 1, 7, {0, 0, 0}, 0},
    {0x175, 0x6e, 1, 7, {0, 0, 0}, 0},
    {0x163, 0x18, 2, 0x1d, {0, 0, 0}, 0},
    {0x163, 0x3a, 2, 7, {0, 0, 0}, 0},
    {0x162, 0x3b, 2, 7, {0, 0, 0}, 0},
    {0x163, 0x55, 2, 0x1d, {0, 0, 0}, 0},
    {0x15a, 5, 1, 7, {0, 0, 0}, 0},
    {0x172, 4, 1, 7, {0, 0, 0}, 0},
    {0x15b, 6, 1, 7, {0, 0, 0}, 0},
    {0x15a, 0x41, 1, 7, {0, 0, 0}, 0},
    {0x172, 0x3f, 1, 7, {0, 0, 0}, 0},
    {0x15b, 0x40, 1, 7, {0, 0, 0}, 0},
    {0x174, 0x6c, 1, 7, {0, 0, 0}, 0},
};

Rec_801A7428 lbl_804C2F38[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

Rec_801A7428 lbl_804C2FA8[4] = {
    {0x13e, 0, 1, {0.0f, 20.0f, 50.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 50.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 20.0f, 50.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 20.0f, 50.0f}, 0},
};

Rec_801A7428 lbl_804C3018[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

Rec_801A7428 lbl_804C3088[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

Rec_801A7428 lbl_804C30F8[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

Rec_801A7428 lbl_804C3168[4] = {
    {0x13e, 0, 1, {0.0f, 40.0f, 0.0f}, 0},
    {0x13f, 0, 0x1e, {0.0f, 0.0f, 0.0f}, 0},
    {0x142, 0xa, 0x14, {0.0f, 40.0f, 0.0f}, 0},
    {0x143, 0x14, 0xa, {0.0f, 40.0f, 0.0f}, 0},
};

Group_801A7428 photon_blast_attachment_table[7] = {
    {lbl_804C2C18, 6, lbl_804C30F8, 4},
    {lbl_804C2CD8, 19, lbl_804C3168, 4},
    {lbl_804C2578, 9, lbl_804C2FA8, 4},
    {lbl_804C2438, 10, lbl_804C2F38, 4},
    {lbl_804C2698, 32, lbl_804C3018, 4},
    {lbl_804C2A98, 6, lbl_804C3088, 4},
    {lbl_804C2B58, 6, lbl_804C3088, 4},
};
}

Reg_801A7578 photon_blast_joint_origins[1];
PhotonBlastHit photon_blast_hit_queue[32];
PhotonBlastHit deferred_photon_blast_hit_queue[32];
