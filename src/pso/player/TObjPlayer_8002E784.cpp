#include "pso/system/MatrixStack.h"
// The De Rol Le breakup effects: TUnk_80482090 (the pieces TBoss2DeRolLe spawns), TUnk_804820A8 (the pieces
// TBoss2Joint spawns), their base TUnk_804820C0 and the breakup models they start from.
// Built -inline off,deferred: the functions below are written last to first (the vtables at 0x80482090-0x804820D8
// and TUnk_804820A8::render's .rodata templates before TUnk_80482090::render's only come out in that order).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TUnk_804820A8.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/player/TUnk_804820C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/TUnk_80482090.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"

extern "C" {
s32 rotate_matrix_z(int, int);
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
void set_chunk_material_override_pair(s32 first, s32 second);
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *matrix);
void rotate_vector_by_matrix(int, void *, void *);
void scale_matrix(int, f32, f32, f32);
f32 vec3_add_to(void *, void *);
extern u32 model_render_flags;
extern u32 saved_model_render_flags;
extern const f32 breakup_unit;
extern const f32 breakup_zero;
extern const f32 breakup_bounce_factor;
extern const f32 breakup_rise_speed_min;
extern const f32 breakup_rise_speed_max;
extern const f32 breakup_back_speed_max;
extern const f32 breakup_spin_max;
extern const f32 breakup_spread_scale;
extern const f32 breakup_gravity;
extern const f32 breakup_fade_step;
extern const f32 breakup_floor_height;
void TObjPlayer__sub_8002ECC4(TBreakUpMdlData *model, s32 n);
void TObjPlayer__sub_8002ED48(TBreakUpMdlData *model, s32 n);

TBreakUpMdlData *shared_breakup_model;
TBreakUpMdlData *lbl_805D4B8C;
f32 boss2_breakup_water_level = boss2_water_level;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
s32 TObjPlayer__sub_8002EDCC(BreakupPiece *piece) {
    f32 temp_f1;
    f32 temp_f2;
    f32 x;
    f32 z;
    s32 state;
    s32 spin;
    s32 var_r30;
    var_r30 = 0;
    state = piece->state;
    spin = piece->spin;
    switch (state) {
    case 0:
        piece->vel.y = (piece->vel.y - breakup_gravity);
        vec3_add_to(&piece->pos, &piece->vel);
        temp_f1 = piece->vel.y;
        if (temp_f1 < breakup_zero) {
            temp_f2 = piece->pos.y;
            if (temp_f2 < breakup_floor_height) {
                x = piece->pos.x;
                z = piece->pos.z;
                if ((x <= boss2_platform_max) && (x >= boss2_platform_min) && (z <= 76.0f) && (z >= (-75.0f))) {
                    piece->vel.y = (temp_f1 * breakup_bounce_factor);
                    piece->state = 2;
                } else if (temp_f2 < boss2_water_level) {
                    var_r30 = 1;
                    piece->state = 1;
                }
            }
        }
        piece->ang_x = (piece->ang_x + spin);
        piece->ang_z = (piece->ang_z + (spin * 2));
        break;
    case 2:
        piece->vel.y = (piece->vel.y - breakup_gravity);
        vec3_add_to(&piece->pos, &piece->vel);
        piece->alpha = (piece->alpha - breakup_fade_step);
        if (piece->alpha < breakup_zero) {
            piece->alpha = breakup_zero;
            piece->state = 3;
        }
        piece->ang_x = (piece->ang_x + spin);
        piece->ang_z = (piece->ang_z + (spin * 2));
        break;
    case 1:
        piece->pos.y = ((breakup_gravity * piece->vel.y) + piece->pos.y);
        piece->pos.z = (piece->pos.z + piece->vel.z);
        break;
    }
    return var_r30;
}
#pragma pop

void TObjPlayer__sub_8002ED48(TBreakUpMdlData *model, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, boss2_model_scale, boss2_model_scale, boss2_model_scale);
    for (i = 0; i < n; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].pos, &model->m_records[i].pos);
    }
    pop_matrix();
}

void TObjPlayer__sub_8002ECC4(TBreakUpMdlData *model, s32 n) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    scale_matrix(0, breakup_spread_scale, breakup_zero, breakup_spread_scale);
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
    TBreakUpMdlData *model = new TBreakUpMdlData(boss2_derolle_resource->models[6].model);
    shared_breakup_model = model;
    TObjPlayer__sub_8002ED48(model, 0x13);
    TObjPlayer__sub_8002ECC4(shared_breakup_model, 0x13);
}

void TObjPlayer::free_breakup_model() {
    delete shared_breakup_model;
    shared_breakup_model = NULL;
}

TUnk_804820A8::TUnk_804820A8(TObject *parent, const Vec *pos) : TUnk_804820C0(parent) {
    f32 alpha;
    f32 spin_max;
    BreakupPiece *p;
    Vec *v;
    s32 i;
    spin_max = breakup_spin_max;
    alpha = breakup_unit;
    for (i = 0, p = m_pieces; i < 19; i++, p++) {
        VecCopy(&p->pos, pos);
        vec3_add_to(&p->pos, &shared_breakup_model->m_records[i].pos);
        v = &p->vel;
        VecCopy(v, &shared_breakup_model->m_records[i].vel);
        v->y = lerp__9TDeadSpotFff(breakup_rise_speed_min, breakup_rise_speed_max);
        v->z -= lerp__9TDeadSpotFff(breakup_unit, breakup_back_speed_max);
        p->ang_x = TObjPlayer::calc_random_scaled();
        p->spin = (s32)(spin_max * rand_signed_unit());
        p->ang_z = TObjPlayer::calc_random_scaled();
        p->state = 0;
        p->alpha = alpha;
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
                TObjBoss2CeilJunk::create_particle(&piece->pos, 0x171);
            }
        }
        i += 1;
    } while (i < 0x13);
}

void TUnk_804820A8::render() {
    BmlModelEntry *models = boss2_derolle_resource->models;
    NJS_OBJECT *mdl = models[6].model;
    NJS_ARGB color = {1.0f, 1.0f, 1.0f, 1.0f};
    NJS_OBJECT *node = mdl->child;
    Vec scale = {0.0f, 0.0f, 0.0f};
    BreakupPiece *p = m_pieces;
    s32 i;

    scale.x = boss2_model_scale;
    scale.y = boss2_model_scale;
    scale.z = boss2_model_scale;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(models[2].texlist));
    for (i = 0; i < 19; i++) {
        push_matrix();
        post_translate_matrix(&p->pos.x);
        rotate_matrix_by_node_angles(&p->ang_x, 0);
        scale_current_matrix(&scale.x);
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
        node = node->sibling;
        p++;
    }
    current_scene_light->sub_801337F8();
}

void TObjPlayer::create_derolle_breakup_model() {
    TBreakUpMdlData *model = new TBreakUpMdlData(boss2_derolle_resource->models[5].model);
    lbl_805D4B8C = model;
    TObjPlayer__sub_8002ECC4(model, 0x1C);
}

void TObjPlayer::clear_target_ref() {
    delete lbl_805D4B8C;
    lbl_805D4B8C = NULL;
}

TUnk_80482090::TUnk_80482090(TObject *parent, const f32 (*matrix)[4]) : TUnk_804820C0(parent) {
    BreakupPiece *p;
    s32 i;
    Vec *v;
    p = m_pieces;
    m_matrix = matrix;
    push_matrix();
    set_matrix_identity(0);
    ::concat_matrix(NULL, m_matrix);
    v = &m_origin;
    v->x = breakup_zero;
    v->y = breakup_zero;
    v->z = breakup_zero;
    matrix_mult_vec(0, v, v);
    for (i = 0; i < 0x1C; i++, p++) {
        matrix_mult_vec(0, &lbl_805D4B8C->m_records[i].pos, &p->pos);
        rotate_vector_by_matrix(0, &lbl_805D4B8C->m_records[i].vel, &p->vel);
        p->vel.y = lerp__9TDeadSpotFff(breakup_rise_speed_min, breakup_rise_speed_max);
        p->vel.z -= lerp__9TDeadSpotFff(breakup_unit, breakup_back_speed_max);
        p->ang_x = 0;
        p->spin = (s32)(breakup_spin_max * rand_signed_unit());
        p->ang_z = 0;
        p->state = 0;
        p->alpha = breakup_unit;
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
                TObjBoss2CeilJunk::create_particle(&piece->pos, 0x170);
            }
        }
        i += 1;
    } while (i < 0x1C);
}

void TUnk_80482090::render() {
    NJS_OBJECT *n;
    BreakupPiece *p;
    s32 i;
    BmlModelEntry *models;
    NJS_OBJECT *mesh;
    p = m_pieces;
    models = boss2_derolle_resource->models;
    mesh = models[5].model;
    {
        NJS_ARGB c = {1.0f, 1.0f, 1.0f, 1.0f};
        n = mesh->child;
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(models[2].texlist));
        push_matrix();
        for (i = 0; i < 0x1C; i++, n = n->sibling, p++) {
            push_matrix();
            post_translate_matrix(&p->pos.x);
            rotate_matrix_z(0, p->ang_z);
            rotate_matrix_x(0, p->ang_x);
            translate_matrix(0, -m_origin.x, -m_origin.y, -m_origin.z);
            ::concat_matrix(NULL, m_matrix);
            switch (p->state) {
            case 0:
            case 1:
                draw_chunk_model(n->model);
                break;
            case 2:
                saved_model_render_flags = model_render_flags;
                model_render_flags = saved_model_render_flags | 0x8810;
                c.a = p->alpha;
                set_constant_material(&c);
                set_chunk_material_override_pair(0xFF00, 0x800);
                set_chunk_blend(0x2500);
                draw_chunk_model(n->model);
                set_chunk_material_override_pair(0xFF00, 0);
                model_render_flags = saved_model_render_flags;
                break;
            }
            pop_matrix();
        }
    }
    pop_matrix();
    current_scene_light->sub_801337F8();
}

}

extern const f32 breakup_unit = 1.0f;
extern const f32 breakup_zero = 0.0f;
extern const f32 breakup_bounce_factor = -0.8f;
extern const f32 breakup_rise_speed_min = 2.0f;
extern const f32 breakup_rise_speed_max = 6.0f;
extern const f32 breakup_back_speed_max = 5.0f;
extern const f32 breakup_spin_max = 3400.0f;
extern const f32 random_unit_scale = 3.0517578e-05f;
extern const f32 random_angle_range = 65536.0f;
extern const f32 breakup_spread_scale = 1.1f;
extern const f32 breakup_gravity = 0.2f;
extern const f32 breakup_fade_step = 0.05f;
extern const f32 boss2_water_level = -10.0f;
extern const f32 boss2_tunnel_splash_y = -5.0f;
extern const f32 boss2_model_scale = 2.0f;
extern const f32 breakup_floor_height = 1.15f;
extern const f32 boss2_platform_max = 76.0f;
extern const f32 boss2_platform_min = -75.0f;
