#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/unk/text_803D96A8.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/player/TObjPlayer_802E6CA8.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/boss/barbaray/TBoss7BreakUp.h"
#include "pso/boss/barbaray/TBoss7JointBreakUp.h"
#include "pso/boss/barbaray/TBoss7BodyBreakUp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"

struct Col_802E6CB0 { f32 a; f32 b; f32 c; f32 d; };

struct Part_802E6CB0 { u8 pad0[0x18]; s32 f18; u8 pad1c[4]; s32 f20; f32 f24; s32 type; };

struct Node_802E6CB0 { u8 pad0[4]; void *model; u8 pad8[0x28]; Node_802E6CB0 *next; };

struct Part_802E6F10 {
    Vec pos;
    Vec rot;
    s32 f18;
    s32 f1C;
    s32 f20;
    f32 f24;
    s32 f28;
};

struct Col_802E708C { f32 a; f32 b; f32 c; f32 d; };

struct Part_802E708C { u8 pad0[0x18]; u8 rot[0xC]; f32 f24; s32 type; };

struct Node_802E708C { u8 pad0[4]; void *model; u8 pad8[0x24]; Node_802E708C *child; Node_802E708C *next; };

typedef struct Piece_802E72DC {
    Vec pos;
    Vec rot;
    s32 x18;
    s32 x1C;
    s32 x20;
    f32 x24;
    s32 x28;
} Piece_802E72DC;

extern "C" {
extern const f32 lbl_805DE9CC;
extern const f32 lbl_805DE9D0;
extern const f32 lbl_805DE9E8;
extern const f32 lbl_805DE9EC;
extern const float lbl_805DE9F0;
extern const f32 lbl_805DE9FC;
extern const f32 lbl_805DEA00;
extern const f32 lbl_805DEA04;
f32 lerp__9TDeadSpotFff(f32, f32);
f32 rand_signed_unit();
s32 matrix_mult_vec(int, void *, void *);
extern const f32 lbl_805DE9C8;
extern const f32 lbl_805DE9D4;
extern const f32 lbl_805DE9D8;
extern const f32 lbl_805DE9DC;
extern const f32 lbl_805DE9E0;
extern Col_802E708C lbl_80472C80;
extern Vec lbl_80472C90;
extern const f32 lbl_805DE9F8;
extern s32 lbl_80472C68[6];
extern const f32 lbl_805DE9E4;

}
void set_chunk_blend(u32 x);
extern Col_802E6CB0 lbl_80472C9C;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
s32 TObjPlayer__sub_802E76C8(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_r0;
    s32 temp_r31;
    s32 var_r30;
    var_r30 = 0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x28);
    temp_r31 = *(s32 *)((s8 *)arg0 + 0x1C);
    switch (temp_r0) {
    case 0:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - lbl_805DE9E8);
        vec3_add_to(&((BreakUpPiece *)arg0)->pos, &((BreakUpPiece *)arg0)->velocity);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x10);
        if (temp_f1 < lbl_805DE9CC) {
            temp_f2 = *(f32 *)((s8 *)arg0 + 4);
            if (temp_f2 < lbl_805DE9FC) {
                temp_f3 = *(f32 *)((s8 *)arg0 + 0);
                temp_f4 = *(f32 *)((s8 *)arg0 + 8);
                if ((temp_f3 <= lbl_805DEA00) && (temp_f3 >= lbl_805DEA04) && (temp_f4 <= 76.0f) && (temp_f4 >= (-75.0f))) {
                    *(f32 *)((s8 *)arg0 + 0x10) = (f32) (temp_f1 * lbl_805DE9D0);
                    *(s32 *)((s8 *)arg0 + 0x28) = 2;
                } else if (temp_f2 < (*(const f32 *)&lbl_805DE9F0)) {
                    var_r30 = 1;
                    *(s32 *)((s8 *)arg0 + 0x28) = 1;
                }
            }
        }
        *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + temp_r31);
        *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) + (temp_r31 * 2));
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - lbl_805DE9E8);
        vec3_add_to(&((BreakUpPiece *)arg0)->pos, &((BreakUpPiece *)arg0)->velocity);
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) (*(f32 *)((s8 *)arg0 + 0x24) - lbl_805DE9EC);
        if (*(f32 *)((s8 *)arg0 + 0x24) < lbl_805DE9CC) {
            *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805DE9CC;
            *(s32 *)((s8 *)arg0 + 0x28) = 3;
        }
        *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) + temp_r31);
        *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) + (temp_r31 * 2));
        break;
    case 1:
        *(f32 *)((s8 *)arg0 + 4) = (f32) ((lbl_805DE9E8 * *(f32 *)((s8 *)arg0 + 0x10)) + *(f32 *)((s8 *)arg0 + 4));
        *(f32 *)((s8 *)arg0 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) + *(f32 *)((s8 *)arg0 + 0x14));
        break;
    }
    return var_r30;
}
#pragma pop

void TBoss7JointBreakUp::scale_node_positions() {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805DE9F8, lbl_805DE9F8, lbl_805DE9F8);
    for (i = 0; i < model->m_count; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].pos, &model->m_records[i].pos);
    }
    pop_matrix();
}

void TBoss7BreakUp::scale_node_velocities_xz() {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805DE9E4, lbl_805DE9CC, lbl_805DE9E4);
    for (i = 0; i < model->m_count; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].vel, &model->m_records[i].vel);
    }
    pop_matrix();
}

TBoss7BreakUp::TBoss7BreakUp(TObject *parent) : TObject(parent) {
    age = 0;
    model = NULL;
    count = 0;
    pieces = NULL;
}

TBoss7BreakUp::~TBoss7BreakUp() {
    mem_free(pieces);
    delete model;
}


void TBoss7BreakUp::alloc_breakup_model(s32 model) {
    this->model = new TBreakUpMdlData(model);
    count = this->model->m_count;
    scale_node_velocities_xz();
    pieces = (u8 *)mem_alloc(count * 0x2C);
}

void TObjPlayer__sub_802E7470(void) {  }
void TObjPlayer__sub_802E746C(void) {  }

TBoss7JointBreakUp::TBoss7JointBreakUp(TObject *parent, Vec *position, s32 index) : TBoss7BreakUp(parent) {
    s32 n;
    Piece_802E72DC *p;
    Vec *q;
    s32 i;
    if (index >= 0 && (u32)index < 6) {
        n = lbl_80472C68[index];
    } else {
        n = -1;
    }
    if (n > 0) {
        alloc_breakup_model((s32)find_model_node(static_cast<NJS_OBJECT *>(TBoss7DeRolLeC::get_archive_model(3)), n));
        scale_node_positions();
        p = (Piece_802E72DC *)pieces;
        for (i = 0; i < count; i++, p++) {
            VecCopy(&p->pos, position);
            vec3_add_to(&p->pos, &model->m_records[i].pos);
            q = &p->rot;
            VecCopy(q, &model->m_records[i].vel);
            q->y = lerp__9TDeadSpotFff(lbl_805DE9D4, lbl_805DE9D8);
            q->z -= lerp__9TDeadSpotFff(lbl_805DE9C8, lbl_805DE9DC);
            p->x18 = TObjPlayer::calc_random_scaled();
            p->x1C = lbl_805DE9E0 * rand_signed_unit();
            p->x20 = TObjPlayer::calc_random_scaled();
            p->x28 = 0;
            p->x24 = lbl_805DE9C8;
        }
    } else {
        queue_destruction();
    }
}

TBoss7JointBreakUp::~TBoss7JointBreakUp() {
}

void TBoss7JointBreakUp::run_task() {
    s32 off;
    s32 i;
    age++;
    if (age >= 0xA0) {
        queue_destruction();
        return;
    }
    for (i = 0, off = 0; i < count; i++, off += 0x2C) {
        if (TObjPlayer__sub_802E76C8(pieces + off) != 0 && i % 2 == 0) {
            spawn_particle_effect((const Vec *)(pieces + off), 0x200);
        }
    }
}

void TBoss7JointBreakUp::render() {
    Node_802E708C *node;
    Part_802E708C *part;
    u8 *fx = (u8 *)TBoss7DeRolLeC::get_archive_model(3);
    Col_802E708C c = lbl_80472C80;
    node = *(Node_802E708C **)((s8 *)fx + 0x2C);
    Vec s = lbl_80472C90;
    s.z = s.y = s.x = lbl_805DE9F8;
    part = (Part_802E708C *)pieces;
    TObjPlayer::draw_effect();
    for (node = node->child; node != NULL; node = node->next) {
        push_matrix();
        post_translate_matrix((const f32 *)part);
        rotate_matrix_by_node_angles((const s32 *)part->rot, 0);
        scale_current_matrix(&s.x);
        switch (part->type) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8810;
            c.a = part->f24;
            set_constant_material((const NJS_ARGB *)((&c)));
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model(node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        part++;
    }
    current_scene_light->sub_801337F8();
}

void TObjPlayer__sub_802E7088(void) {  }
void TObjPlayer__sub_802E7084(void) {  }

TBoss7BodyBreakUp::TBoss7BodyBreakUp(TObject *parent, GC_Mtx *matrices) : TBoss7BreakUp(parent) {
    Part_802E6F10 *part;
    s32 i;
    alloc_breakup_model((saddr)TBoss7DeRolLeC::get_archive_model(2));
    this->matrices = matrices;
    part = (Part_802E6F10 *)pieces;
    push_matrix();
    set_matrix_identity(0);
    TObjPlayer::concat_matrix(0, (uaddr)this->matrices);
    pivot.z = pivot.y = pivot.x = lbl_805DE9CC;
    matrix_mult_vec(0, &pivot, &pivot);
    for (i = 0; i < count; i++) {
        matrix_mult_vec(0, &model->m_records[i].pos, &part->pos);
        rotate_vector_by_matrix(0, &model->m_records[i].vel, &part->rot);
        part->rot.y = lerp__9TDeadSpotFff(lbl_805DE9D4, lbl_805DE9D8);
        part->rot.z -= lerp__9TDeadSpotFff(lbl_805DE9C8, lbl_805DE9DC);
        part->f18 = 0;
        part->f1C = lbl_805DE9E0 * rand_signed_unit();
        part->f20 = 0;
        part->f28 = 0;
        part->f24 = lbl_805DE9C8;
        part++;
    }
    pop_matrix();
}

TBoss7BodyBreakUp::~TBoss7BodyBreakUp() {
}

void TBoss7BodyBreakUp::run_task() {
    s32 off;
    s32 i;
    age++;
    if (age >= 0xA0) {
        queue_destruction();
        return;
    }
    for (i = 0, off = 0; i < count; i++, off += 0x2C) {
        if (TObjPlayer__sub_802E76C8(pieces + off) != 0 && i % 2 == 0) {
            spawn_particle_effect((const Vec *)(pieces + off), 0x200);
        }
    }
}

void TBoss7BodyBreakUp::render() {
    Node_802E6CB0 *node;
    Part_802E6CB0 *part;
    s32 i;
    u8 *fx = (u8 *)TBoss7DeRolLeC::get_archive_model(2);
    Col_802E6CB0 c = lbl_80472C9C;
    node = *(Node_802E6CB0 **)((s8 *)fx + 0x2C);
    part = (Part_802E6CB0 *)pieces;
    TObjPlayer::draw_effect();
    push_matrix();
    for (i = 0; i < count; i++) {
        push_matrix();
        post_translate_matrix((const f32 *)part);
        rotate_matrix_z(0, part->f20);
        rotate_matrix_x(0, part->f18);
        translate_matrix(0, -pivot.x, -pivot.y, -pivot.z);
        TObjPlayer::concat_matrix(0, (uaddr)matrices);
        switch (part->type) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8810;
            c.a = part->f24;
            set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model(node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        node = node->next;
        part++;
    }
    pop_matrix();
    current_scene_light->sub_801337F8();
}

saddr TObjPlayer::get_instance() { return (saddr)multiplay_texture_f512_handle; }

f32 lbl_805D6910 = lbl_805DE9F0;
const f32 lbl_805DE9C8 = 1.0f;
const f32 lbl_805DE9CC = 0.0f;
const f32 lbl_805DE9D0 = -0.8f;
const f32 lbl_805DE9D4 = 2.0f;
const f32 lbl_805DE9D8 = 6.0f;
const f32 lbl_805DE9DC = 5.0f;
const f32 lbl_805DE9E0 = 3400.0f;
const f32 lbl_805DE9E4 = 1.1f;
const f32 lbl_805DE9E8 = 0.2f;
const f32 lbl_805DE9EC = 0.05f;
const f32 lbl_805DE9F0 = -10.0f;
extern const f32 boss7_tunnel_splash_y;
const f32 boss7_tunnel_splash_y = -5.0f;
const f32 lbl_805DE9F8 = 2.5f;
const f32 lbl_805DE9FC = 1.15f;
const f32 lbl_805DEA00 = 76.0f;
const f32 lbl_805DEA04 = -75.0f;

__declspec(section ".rodata") s32 lbl_80472C68[6] = { 1, 6, 12, 18, 24, 29 };
__declspec(section ".rodata") Col_802E708C lbl_80472C80 = { 1.0f, 1.0f, 1.0f, 1.0f };
__declspec(section ".rodata") Vec lbl_80472C90 = { 0.0f, 0.0f, 0.0f };
__declspec(section ".rodata") Col_802E6CB0 lbl_80472C9C = { 1.0f, 1.0f, 1.0f, 1.0f };

