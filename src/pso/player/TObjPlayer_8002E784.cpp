// The De Rol Le breakup effects: TUnk_80482090 (the pieces TBoss2DeRolLe spawns), TUnk_804820A8 (the pieces
// TBoss2Joint spawns), their base TUnk_804820C0 and the breakup models they start from.
// Built -inline off,deferred: the functions below are written last to first (the vtables at 0x80482090-0x804820D8
// and TUnk_804820A8::render's .rodata templates before TUnk_80482090::render's only come out in that order).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TUnk_804820A8.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/player/TUnk_804820C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/TUnk_80482090.h"
#include "pso/player/TObjPlayer_8002E784.h"

struct BreakupNode_8002E818 {
    u8 pad0[4];
    void *model;
    u8 pad8[0x28];
    BreakupNode_8002E818 *next;
};

struct Node_8002E3D4 { u8 pad[4]; s32 f4; u8 pad8[0x30 - 8]; Node_8002E3D4 *next; };

struct Mesh_8002E3D4 { u8 pad[0x2C]; Node_8002E3D4 *nodes; };

struct Model_8002E3D4 { u8 pad[0x2C]; s32 f2C; u8 pad30[0x58 - 0x30]; Mesh_8002E3D4 *mesh; };

struct Holder_8002E3D4 { u8 pad[0x42C]; Model_8002E3D4 *model; };

extern "C" {
s32 create_particle__17TObjBoss2CeilJunkFv(void *, s32);
void TObjLight__sub_801337F8(s32);
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
void push_matrix(void);
s32 pop_matrix();
void post_translate_matrix(void *);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
void rotate_vector_by_matrix(int, void *, void *);
void scale_matrix(int, f32, f32, f32);
void rotate_matrix_by_node_angles(void *angles, s32 mode);
void scale_current_matrix(Vec *scale);
f32 vec3_add_to(void *, void *);
extern s32 current_scene_light;
extern u32 model_render_flags;
extern u32 saved_model_render_flags;
extern Holder_8002E3D4 *lbl_805D4BA4;
extern const f32 lbl_805D8228;
extern const f32 lbl_805D822C;
extern const f32 lbl_805D8230;
extern const f32 lbl_805D8234;
extern const f32 lbl_805D8238;
extern const f32 lbl_805D823C;
extern const f32 lbl_805D8240;
extern const f32 lbl_805D824C;
extern const f32 lbl_805D8250;
extern const f32 lbl_805D8254;
extern const f32 lbl_805D8258;
extern const f32 lbl_805D8260;
extern const f32 lbl_805D8264;
extern const f32 lbl_805D8268;
extern const f32 lbl_805D826C;
void TObjPlayer__sub_8002ECC4(TUnk_8048FA00 *model, s32 n);
void TObjPlayer__sub_8002ED48(TUnk_8048FA00 *model, s32 n);

TUnk_8048FA00 *shared_breakup_model;
TUnk_8048FA00 *lbl_805D4B8C;
f32 lbl_805D4B90 = lbl_805D8258;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
s32 TObjPlayer__sub_8002EDCC(BreakupPiece *piece) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_r0;
    s32 temp_r31;
    s32 var_r30;
    var_r30 = 0;
    temp_r0 = piece->state;
    temp_r31 = piece->spin;
    switch (temp_r0) {
    case 0:
        piece->vel.y = (piece->vel.y - lbl_805D8250);
        vec3_add_to(&piece->pos, &piece->vel);
        temp_f1 = piece->vel.y;
        if (temp_f1 < lbl_805D822C) {
            temp_f2 = piece->pos.y;
            if (temp_f2 < lbl_805D8264) {
                temp_f3 = piece->pos.x;
                temp_f4 = piece->pos.z;
                if ((temp_f3 <= lbl_805D8268) && (temp_f3 >= lbl_805D826C) && (temp_f4 <= 76.0f) && (temp_f4 >= (-75.0f))) {
                    piece->vel.y = (temp_f1 * lbl_805D8230);
                    piece->state = 2;
                } else if (temp_f2 < lbl_805D8258) {
                    var_r30 = 1;
                    piece->state = 1;
                }
            }
        }
        piece->ang_x = (piece->ang_x + temp_r31);
        piece->ang_z = (piece->ang_z + (temp_r31 * 2));
        break;
    case 2:
        piece->vel.y = (piece->vel.y - lbl_805D8250);
        vec3_add_to(&piece->pos, &piece->vel);
        piece->alpha = (piece->alpha - lbl_805D8254);
        if (piece->alpha < lbl_805D822C) {
            piece->alpha = lbl_805D822C;
            piece->state = 3;
        }
        piece->ang_x = (piece->ang_x + temp_r31);
        piece->ang_z = (piece->ang_z + (temp_r31 * 2));
        break;
    case 1:
        piece->pos.y = ((lbl_805D8250 * piece->vel.y) + piece->pos.y);
        piece->pos.z = (piece->pos.z + piece->vel.z);
        break;
    }
    return var_r30;
}
#pragma pop

void TObjPlayer__sub_8002ED48(TUnk_8048FA00 *model, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805D8260, lbl_805D8260, lbl_805D8260);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].pos, &model->m_records[i].pos);
    }
    pop_matrix();
}

void TObjPlayer__sub_8002ECC4(TUnk_8048FA00 *model, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, lbl_805D824C, lbl_805D822C, lbl_805D824C);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].vel, &model->m_records[i].vel);
    }
    pop_matrix();
}

TUnk_804820C0::TUnk_804820C0(TObject *parent) : TObject(parent) {
    m_frames = 0;
}

TUnk_804820C0::~TUnk_804820C0() {
}

void TObjPlayer::create_breakup_model() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x10);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TBreakUpMdl *)temp_r3)->init_from_model(*(s32 *)((s8 *)((u8 *)lbl_805D4BA4->model) + 0x68)));
    }
    (*(u8 * *)&shared_breakup_model) = (unsigned char *) ((void *) var_r0);
    TObjPlayer__sub_8002ED48((TUnk_8048FA00 *)var_r0, 0x13);
    TObjPlayer__sub_8002ECC4(shared_breakup_model, 0x13);
}

void TObjPlayer__sub_8002EB88(void) {
    delete shared_breakup_model;
    shared_breakup_model = NULL;
}

TUnk_804820A8::TUnk_804820A8(TObject *parent, const Vec *pos) : TUnk_804820C0(parent) {
    f32 zero;
    f32 scale;
    BreakupPiece *p;
    Vec *v;
    s32 i;
    scale = lbl_805D8240;
    zero = lbl_805D8228;
    for (i = 0, p = m_pieces; i < 19; i++, p++) {
        VecCopy(&p->pos, pos);
        vec3_add_to(&p->pos, &shared_breakup_model->m_records[i].pos);
        v = &p->vel;
        VecCopy(v, &shared_breakup_model->m_records[i].vel);
        v->y = lerp__9TDeadSpotFff(lbl_805D8234, lbl_805D8238);
        v->z -= lerp__9TDeadSpotFff(lbl_805D8228, lbl_805D823C);
        p->ang_x = TObjPlayer::calc_random_scaled();
        p->spin = (s32)(scale * rand_signed_unit());
        p->ang_z = TObjPlayer::calc_random_scaled();
        p->state = 0;
        p->alpha = zero;
    }
}

TUnk_804820A8::~TUnk_804820A8() {
}

void TUnk_804820A8::run_task() {
    BreakupPiece *piece;
    s32 i;
    m_frames += 1;
    if (m_frames >= 0xA0) {
        queue_destruction();
        return;
    }
    i = 0;
    do {
        piece = &m_pieces[i];
        if (TObjPlayer__sub_8002EDCC(piece) != 0) {
            if ((i % 2) == 0) {
                create_particle__17TObjBoss2CeilJunkFv(piece, 0x171);
            }
        }
        i += 1;
    } while (i < 0x13);
}

void TUnk_804820A8::render() {
    u8 *res = (u8 *)lbl_805D4BA4->model;
    u8 *mdl = *(u8 **)(res + 0x68);
    NJS_ARGB color = {1.0f, 1.0f, 1.0f, 1.0f};
    BreakupNode_8002E818 *node = *(BreakupNode_8002E818 **)(mdl + 0x2C);
    Vec scale = {0.0f, 0.0f, 0.0f};
    BreakupPiece *p = m_pieces;
    s32 i;

    scale.x = lbl_805D8260;
    scale.y = lbl_805D8260;
    scale.z = lbl_805D8260;
    TObjFish::set_global_param(*(s32 *)(res + 0x2C));
    for (i = 0; i < 19; i++) {
        push_matrix();
        post_translate_matrix(&p->pos);
        rotate_matrix_by_node_angles(&p->ang_x, 0);
        scale_current_matrix(&scale);
        switch (p->state) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x8810;
            color.a = p->alpha;
            set_constant_material(&color);
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model(node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        node = node->next;
        p++;
    }
    TObjLight__sub_801337F8(current_scene_light);
}

void TObjPlayer__sub_8002E7C8(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x10);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TBreakUpMdl *)temp_r3)->init_from_model(*(s32 *)((s8 *)((u8 *)lbl_805D4BA4->model) + 0x58)));
    }
    (*(u8 * *)&lbl_805D4B8C) = (unsigned char *) ((void *) var_r0);
    TObjPlayer__sub_8002ECC4((TUnk_8048FA00 *)var_r0, 0x1C);
}

void TObjPlayer::clear_target_ref() {
    delete lbl_805D4B8C;
    lbl_805D4B8C = NULL;
}

TUnk_80482090::TUnk_80482090(TObject *parent, u32 matrix) : TUnk_804820C0(parent) {
    BreakupPiece *p;
    s32 i;
    Vec *v;
    p = m_pieces;
    m_matrix = matrix;
    push_matrix();
    set_matrix_identity(0);
    TObjPlayer::concat_matrix(0, m_matrix);
    v = &m_origin;
    v->x = lbl_805D822C;
    v->y = lbl_805D822C;
    v->z = lbl_805D822C;
    matrix_mult_vec(0, v, v);
    for (i = 0; i < 0x1C; i++, p++) {
        matrix_mult_vec(0, &lbl_805D4B8C->m_records[i].pos, &p->pos);
        rotate_vector_by_matrix(0, &lbl_805D4B8C->m_records[i].vel, &p->vel);
        p->vel.y = lerp__9TDeadSpotFff(lbl_805D8234, lbl_805D8238);
        p->vel.z -= lerp__9TDeadSpotFff(lbl_805D8228, lbl_805D823C);
        p->ang_x = 0;
        p->spin = (s32)(lbl_805D8240 * rand_signed_unit());
        p->ang_z = 0;
        p->state = 0;
        p->alpha = lbl_805D8228;
    }
    pop_matrix();
}

TUnk_80482090::~TUnk_80482090() {
}

void TUnk_80482090::run_task() {
    BreakupPiece *piece;
    s32 i;
    m_frames += 1;
    if (m_frames >= 0xA0) {
        queue_destruction();
        return;
    }
    i = 0;
    do {
        piece = &m_pieces[i];
        if (TObjPlayer__sub_8002EDCC(piece) != 0) {
            if ((i % 2) == 0) {
                create_particle__17TObjBoss2CeilJunkFv(piece, 0x170);
            }
        }
        i += 1;
    } while (i < 0x1C);
}

void TUnk_80482090::render() {
    Node_8002E3D4 *n;
    BreakupPiece *p;
    s32 i;
    Model_8002E3D4 *model;
    Mesh_8002E3D4 *mesh;
    p = m_pieces;
    model = lbl_805D4BA4->model;
    mesh = model->mesh;
    {
        NJS_ARGB c = {1.0f, 1.0f, 1.0f, 1.0f};
        n = mesh->nodes;
        TObjFish::set_global_param(model->f2C);
        push_matrix();
        for (i = 0; i < 0x1C; i++, n = n->next, p++) {
            push_matrix();
            post_translate_matrix(p);
            rotate_matrix_z(0, p->ang_z);
            rotate_matrix_x(0, p->ang_x);
            translate_matrix(0, -m_origin.x, -m_origin.y, -m_origin.z);
            TObjPlayer::concat_matrix(0, m_matrix);
            switch (p->state) {
            case 0:
            case 1:
                draw_chunk_model((void *)n->f4);
                break;
            case 2:
                saved_model_render_flags = model_render_flags;
                model_render_flags = saved_model_render_flags | 0x8810;
                c.a = p->alpha;
                set_constant_material(&c);
                set_chunk_material_override_pair(0xFF00, 0x800);
                set_chunk_blend(0x2500);
                draw_chunk_model((void *)n->f4);
                set_chunk_material_override_pair(0xFF00, 0);
                model_render_flags = saved_model_render_flags;
                break;
            }
            pop_matrix();
        }
    }
    pop_matrix();
    TObjLight__sub_801337F8(current_scene_light);
}

}
