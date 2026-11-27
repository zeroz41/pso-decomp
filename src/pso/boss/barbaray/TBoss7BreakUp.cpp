#include "pso/boss/barbaray/TBoss7BreakUp.h"
#include "types.h"
#include "pso/boss/barbaray/TBoss7BodyBreakUp.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/boss/barbaray/TBoss7JointBreakUp.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/SceneLighting.h"
#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/DebugFont.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/boss/derolle/RandomAngle.h"

// The model node each joint index breaks off.
static const s32 joint_breakup_nodes[6] = { 1, 6, 12, 18, 24, 29 };

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
// Returns 1 on the frame the piece falls past the deck into the sea.
s32 BarbaRayBreakupPiece::update() {
    f32 vy;
    f32 y;
    f32 x;
    f32 z;
    s32 cur_state;
    s32 spin;
    s32 sank;
    sank = 0;
    cur_state = state;
    spin = angles[1];
    switch (cur_state) {
    case 0:
        velocity.y = velocity.y - boss7_breakup_gravity;
        vec3_add_to(&position, &velocity);
        vy = velocity.y;
        if (vy < boss7_breakup_zero) {
            y = position.y;
            if (y < boss7_deck_y) {
                x = position.x;
                z = position.z;
                if (x <= boss7_deck_max_x && x >= boss7_deck_min_x && z <= 76.0f && z >= -75.0f) {
                    velocity.y = vy * boss7_breakup_bounce;
                    state = 2;
                } else if (y < boss7_sea_level_y) {
                    sank = 1;
                    state = 1;
                }
            }
        }
        angles[0] = angles[0] + spin;
        angles[2] = angles[2] + spin * 2;
        break;
    case 2:
        velocity.y = velocity.y - boss7_breakup_gravity;
        vec3_add_to(&position, &velocity);
        opacity = opacity - boss7_breakup_fade_step;
        if (opacity < boss7_breakup_zero) {
            opacity = boss7_breakup_zero;
            state = 3;
        }
        angles[0] = angles[0] + spin;
        angles[2] = angles[2] + spin * 2;
        break;
    case 1:
        position.y = boss7_breakup_gravity * velocity.y + position.y;
        position.z = position.z + velocity.z;
        break;
    }
    return sank;
}
#pragma pop

void TBoss7JointBreakUp::scale_node_positions() {
    s32 i;
    push_matrix();
    set_matrix_identity(NULL);
    scale_matrix(NULL, boss7_joint_breakup_scale, boss7_joint_breakup_scale, boss7_joint_breakup_scale);
    for (i = 0; i < model->m_count; i++) {
        rotate_vector_by_matrix(0, &model->m_records[i].pos, &model->m_records[i].pos);
    }
    pop_matrix();
}

void TBoss7BreakUp::scale_node_velocities_xz() {
    s32 i;
    push_matrix();
    set_matrix_identity(NULL);
    scale_matrix(NULL, boss7_breakup_spread_xz, boss7_breakup_zero, boss7_breakup_spread_xz);
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

void TBoss7BreakUp::alloc_breakup_model(NJS_OBJECT *root) {
    this->model = new TBreakUpMdlData(root);
    count = this->model->m_count;
    scale_node_velocities_xz();
    pieces = (BarbaRayBreakupPiece *)mem_alloc(count * sizeof(BarbaRayBreakupPiece));
}

void TBoss7JointBreakUp::load_static_resource() {
}

void TBoss7BodyBreakUp::destroy_instance() {
}

TBoss7JointBreakUp::TBoss7JointBreakUp(TObject *parent, Vec *position, s32 index) : TBoss7BreakUp(parent) {
    s32 node;
    BarbaRayBreakupPiece *piece;
    Vec *vel;
    s32 i;
    if (index >= 0 && (u32)index < 6) {
        node = joint_breakup_nodes[index];
    } else {
        node = -1;
    }
    if (node > 0) {
        alloc_breakup_model(find_model_node(TBoss7DeRolLeC::get_archive_model(3), node));
        scale_node_positions();
        piece = pieces;
        for (i = 0; i < count; i++, piece++) {
            VecCopy(&piece->position, position);
            vec3_add_to(&piece->position, &model->m_records[i].pos);
            vel = &piece->velocity;
            VecCopy(vel, &model->m_records[i].vel);
            vel->y = random_range(boss7_breakup_rise_min, boss7_breakup_rise_max);
            vel->z -= random_range(boss7_breakup_one, boss7_breakup_drift_max);
            piece->angles[0] = random_angle();
            piece->angles[1] = boss7_breakup_spin_scale * rand_signed_unit();
            piece->angles[2] = random_angle();
            piece->state = 0;
            piece->opacity = boss7_breakup_one;
        }
    } else {
        queue_destruction();
    }
}

TBoss7JointBreakUp::~TBoss7JointBreakUp() {
}

void TBoss7JointBreakUp::run_task() {
    s32 i;
    age++;
    if (age >= 0xA0) {
        queue_destruction();
        return;
    }
    for (i = 0; i < count; i++) {
        if (pieces[i].update() != 0 && i % 2 == 0) {
            spawn_particle_effect(&pieces[i].position, 0x200);
        }
    }
}

void TBoss7JointBreakUp::render() {
    NJS_OBJECT *node;
    BarbaRayBreakupPiece *piece;
    NJS_OBJECT *root = TBoss7DeRolLeC::get_archive_model(3);
    NJS_ARGB color = { 1.0f, 1.0f, 1.0f, 1.0f };
    node = root->child;
    Vec scale = { 0.0f, 0.0f, 0.0f };
    scale.z = scale.y = scale.x = boss7_joint_breakup_scale;
    piece = pieces;
    TObjPlayer::draw_effect();
    for (node = node->child; node != NULL; node = node->sibling) {
        push_matrix();
        post_translate_matrix(&piece->position.x);
        rotate_matrix_by_node_angles(piece->angles, 0);
        scale_current_matrix(&scale.x);
        switch (piece->state) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8810;
            color.a = piece->opacity;
            set_constant_material(&color);
            set_chunk_material_override_pair(0xFF00, 0x800);
            set_chunk_blend(0x2500);
            draw_chunk_model(node->model);
            set_chunk_material_override_pair(0xFF00, 0);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
        piece++;
    }
    current_scene_light->debug_scene_light_hook();
}

void TBoss7BodyBreakUp::load_static_resource() {
}

void TBoss7JointBreakUp::destroy_instance() {
}

TBoss7BodyBreakUp::TBoss7BodyBreakUp(TObject *parent, GC_Mtx *matrices) : TBoss7BreakUp(parent) {
    BarbaRayBreakupPiece *piece;
    s32 i;
    alloc_breakup_model(TBoss7DeRolLeC::get_archive_model(2));
    this->matrices = matrices;
    piece = pieces;
    push_matrix();
    set_matrix_identity(NULL);
    concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(this->matrices));
    pivot.z = pivot.y = pivot.x = boss7_breakup_zero;
    matrix_mult_vec(NULL, &pivot, &pivot);
    for (i = 0; i < count; i++) {
        matrix_mult_vec(NULL, &model->m_records[i].pos, &piece->position);
        rotate_vector_by_matrix(0, &model->m_records[i].vel, &piece->velocity);
        piece->velocity.y = random_range(boss7_breakup_rise_min, boss7_breakup_rise_max);
        piece->velocity.z -= random_range(boss7_breakup_one, boss7_breakup_drift_max);
        piece->angles[0] = 0;
        piece->angles[1] = boss7_breakup_spin_scale * rand_signed_unit();
        piece->angles[2] = 0;
        piece->state = 0;
        piece->opacity = boss7_breakup_one;
        piece++;
    }
    pop_matrix();
}

TBoss7BodyBreakUp::~TBoss7BodyBreakUp() {
}

void TBoss7BodyBreakUp::run_task() {
    s32 i;
    age++;
    if (age >= 0xA0) {
        queue_destruction();
        return;
    }
    for (i = 0; i < count; i++) {
        if (pieces[i].update() != 0 && i % 2 == 0) {
            spawn_particle_effect(&pieces[i].position, 0x200);
        }
    }
}

void TBoss7BodyBreakUp::render() {
    NJS_OBJECT *node;
    BarbaRayBreakupPiece *piece;
    s32 i;
    NJS_OBJECT *root = TBoss7DeRolLeC::get_archive_model(2);
    NJS_ARGB color = { 1.0f, 1.0f, 1.0f, 1.0f };
    node = root->child;
    piece = pieces;
    TObjPlayer::draw_effect();
    push_matrix();
    for (i = 0; i < count; i++) {
        push_matrix();
        post_translate_matrix(&piece->position.x);
        rotate_matrix_z(NULL, piece->angles[2]);
        rotate_matrix_x(NULL, piece->angles[0]);
        translate_matrix(0, -pivot.x, -pivot.y, -pivot.z);
        concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(matrices));
        switch (piece->state) {
        case 0:
        case 1:
            draw_chunk_model(node->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8810;
            color.a = piece->opacity;
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
        piece++;
    }
    pop_matrix();
    current_scene_light->debug_scene_light_hook();
}

saddr get_multiplay_texture_list() { return (saddr)multiplay_texture_f512_handle; }

f32 lbl_805D6910 = boss7_sea_level_y;

const f32 boss7_breakup_one = 1.0f;
const f32 boss7_breakup_zero = 0.0f;
const f32 boss7_breakup_bounce = -0.8f;
const f32 boss7_breakup_rise_min = 2.0f;
const f32 boss7_breakup_rise_max = 6.0f;
const f32 boss7_breakup_drift_max = 5.0f;
const f32 boss7_breakup_spin_scale = 3400.0f;
const f32 boss7_breakup_spread_xz = 1.1f;
const f32 boss7_breakup_gravity = 0.2f;
const f32 boss7_breakup_fade_step = 0.05f;
const f32 boss7_sea_level_y = -10.0f;
const f32 boss7_tunnel_splash_y = -5.0f;
const f32 boss7_joint_breakup_scale = 2.5f;
const f32 boss7_deck_y = 1.15f;
const f32 boss7_deck_max_x = 76.0f;
const f32 boss7_deck_min_x = -75.0f;
