#include "pso/system/NinjaTypes.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemMagSub.h"
#include <string.h>
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMag.h"
#include "pso/item/TItemMagGrowEff.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/model_render_state.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DC86C.h"
// The mag data files TItemMag::load_data_files reads.
extern const char item_mag_motion_path[20] = "itemmagmotion.dat";
extern const char item_mag_edit_path[20] = "ItemMagEdit.prs";
// MagStats::photon_blasts holds slot 0 in bits 0-2, slot 1 in bits 3-5 and
// slot 2's rank in bits 6-7; photon_blast_flags has one bit per slot.
extern const u8 photon_blast_masks[3] = {0x07, 0x38, 0xC0};
extern const u8 photon_blast_slots[3] = {1, 2, 4};
f32 mag_sub_transition_frames = 10.0f;
f32 item_mag_follow_scale = 0.6f;
const char *TItemMagSub_name = "TItemMagSub";
static const Vec mag_sub_special_pose_offset = {0.0f, 0.0f, 5.0f};
static const Vec mag_sub_local_origin = {0.0f, 0.0f, 0.0f};
const char *TItemMagGrowEff_name = "TItemMagGrowEff";
// The sub being drawn, and the index of the model node its draw callback
// is at.
TItemMagSub *TItemMagSub::drawing;
s32 TItemMagSub::drawn_node;
// The owner's current current_motion (TObjMotion::motion): the heading its root
// node adds to the owner's.
struct MagOwnerPoseNode {
    u8 pad_0[0x4];
    s16 heading;
};
struct MagOwnerPose {
    u8 pad_0[0x4];
    MagOwnerPoseNode *node;
};
// The follow motion's steps (update_follow).
void accumulate_mag_axis_oscillation(f32 *out, s32 *phase, MagAxisOscillationParameters *axis);
void lerp_follow_anchor(Vec *target, Vec *anchor, f32 *t);
void mag_accumulate_drift(f32 *out, s32 *phase, f32 *amplitude, s32 *velocity, s8 *offset);

// Degrees to the game's 16-bit angle units.
#define MAG_SUB_ANGLE_UNITS (65536.0f / 360.0f)
// Inline in the original: the one kept copy follows its first caller,
// ~TItemMagSub, and the class vtable comes out with it.

// The functions below run from the last one in the object back to the
// first (deferred code generation, see configure.py).

u32 TItemMag::is_inactive() { return state & MAG_INACTIVE; }

int MagNodeOscillationState::node_index() { return flags & 7; }

int MagNodeOscillationState::uses_x() { return ((u8)flags >> 5) & 1; }

s32 MagNodeOscillationState::get_angle() { return MAG_SUB_ANGLE_UNITS * (f32)value; }

int MagNodeOscillationState::uses_y() { return ((u8)flags >> 6) & 1; }

int MagNodeOscillationState::uses_z() { return ((u8)flags >> 7) & 1; }

void TItemMagSub::set_growth_flag() { set_flags(0x40); }

void TItemMagSub::clear_flags(u32 mask) { flags &= ~mask; }

void TItemMagSub::clear_growth_flag() { clear_flags(0x40); }

void TObject::disallow_rendering_shadows() { m_flags = (u16)(m_flags | 0x100); }

#pragma push
#pragma fp_contract on
TItemMagSub::TItemMagSub(TObjPlayer *player, TItemMag *mag) : TItemHeapObject(mag) {
    s32 i;
    m_name = TItemMagSub_name;
    owner = player;
    model = NULL;
    textures = 0;
    animation = NULL;
    reset();
    flags = 0;
    item = mag;
    animation_frame = 0.0f;
    transition_frame = 0.0f;
    for (i = 0; i < 3; i++) {
        node_ids[i] = -1;
    }
    if (0.5 < player->height) {
        owner_height_scale = 1.1f - 0.2f * player->height;
    } else {
        owner_height_scale = 1.0f;
    }
    disallow_rendering();
    disallow_rendering_shadows();
}
#pragma pop

void TItemMagSub::reset() {
    VecCopy((Vec *)translation_offset, (Vec *)&owner->m_2fc);
    rotation_phase[2] = 0;
    rotation_phase[1] = 0;
    rotation_phase[0] = 0;
    drift_phase[2] = 0;
    drift_phase[1] = 0;
    drift_phase[0] = 0;
    translation_phase[2] = 0;
    translation_phase[1] = 0;
    translation_phase[0] = 0;
    drift_offset[2] = 0.0f;
    drift_offset[1] = 0.0f;
    drift_offset[0] = 0.0f;
    rotation_delta[2] = 0;
    rotation_delta[1] = 0;
    rotation_delta[0] = 0;
    motion = NULL;
}

inline TItemHeapObject::~TItemHeapObject() {}

TItemMagSub::~TItemMagSub() {}

void TItemMagSub::run_task() {
    if (test_flags(0x80) != 0) {
        queue_destruction();
        return;
    }
    if (item->is_owner_frozen() != 0 || item->is_inactive() != 0) {
        return;
    }
    if (owner->is_in_fixed_pose() != 0) {
        update_special_pose();
        return;
    }
    material_parameters[0] = owner->render_material_state.get_alpha();
    if (test_flags(8) != 0) {
        update_transition();
    } else {
        update_follow();
    }
    if (animation != NULL) {
        animation_frame += 1.0f;
        if (animation_length <= animation_frame) {
            animation_frame = 0.0f;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TItemMagSub::update_follow() {
    Vec target;
    s32 i;

    if (motion != NULL) {
        if (motion->joint_index == -1) {
            VecCopy(&target, (Vec *)&owner->m_2fc);
        } else {
            owner->get_anim_node_position(motion->joint_index, &target);
        }
        if (test_flags(2) != 0) {
            VecCopy(&follow_anchor, &target);
        } else if (test_flags(0x10) != 0) {
            lerp_follow_anchor(&target, &follow_anchor, &item_mag_follow_scale);
        } else {
            lerp_follow_anchor(&target, &follow_anchor, &motion->follow_scale);
        }
        accumulate_mag_axis_oscillation(&translation_offset[0], &translation_phase[0], &motion->translation[0]);
        accumulate_mag_axis_oscillation(&translation_offset[1], &translation_phase[1], &motion->translation[1]);
        accumulate_mag_axis_oscillation(&translation_offset[2], &translation_phase[2], &motion->translation[2]);
        mag_accumulate_drift(&drift_offset[0], &drift_phase[0], &motion->drift_amplitude[0], &motion->drift_velocity[0],
                             &motion->drift_angle_offset[0]);
        mag_accumulate_drift(&drift_offset[1], &drift_phase[1], &motion->drift_amplitude[1], &motion->drift_velocity[1],
                             &motion->drift_angle_offset[1]);
        mag_accumulate_drift(&drift_offset[2], &drift_phase[2], &motion->drift_amplitude[2], &motion->drift_velocity[2],
                             &motion->drift_angle_offset[2]);
        vec3_add_to((Vec *)translation_offset, (Vec *)drift_offset);
        if (item->is_owner_acting()) {
            rotation_delta[0] = MAG_SUB_ANGLE_UNITS * (f32)motion->moving_pitch;
        } else {
            rotation_delta[0] = 0;
        }
        rotation_delta[0] += (s32)(MAG_SUB_ANGLE_UNITS * (f32)motion->rotation_offset[0]);
        rotation_delta[1] += (s32)(MAG_SUB_ANGLE_UNITS * (f32)motion->rotation_offset[1]);
        rotation_delta[2] += (s32)(MAG_SUB_ANGLE_UNITS * (f32)motion->rotation_offset[2]);
    }
    for (i = 0; i != 2; i++) {
        oscillations[i].update();
    }
}
#pragma pop

void TItemMagSub::update_transition() {
    transition_frame += 1.0f;
    if (mag_sub_transition_frames == transition_frame) {
        clear_flags(0x18);
        memset(rotation_delta, 0, 0xC);
        memset(drift_phase, 0, 0xC);
        drift_offset[2] = 0.0f;
        drift_offset[1] = 0.0f;
        drift_offset[0] = 0.0f;
    }
    update_follow();
}

void TItemMagSub::update_special_pose() {
    if (motion != NULL) {
        if (motion->joint_index == -1) {
            VecCopy(&follow_anchor, (Vec *)&owner->m_2fc);
        } else {
            owner->get_anim_node_position(motion->joint_index, &follow_anchor);
        }
    }
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(NULL, resolve_owner_heading() + 0x8000);
    Vec in = mag_sub_special_pose_offset;
    Vec out;
    transform_point_by_current_matrix(&in.x, &out);
    vec3_add_to(&follow_anchor, &out);
    pop_matrix();
}

s32 TItemMagSub::resolve_owner_heading() {
    TObjPlayer *player;
    MagOwnerPose **pose;
    s32 heading;
    MagOwnerPose *current;
    MagOwnerPoseNode *node;

    player = owner;
    pose = (MagOwnerPose **)player->current_motion;
    heading = player->rotation_y;
    if (pose != NULL) {
        current = *pose;
        if (current != NULL) {
            node = current->node;
            if (node != NULL) {
                return heading + node->heading;
            }
        }
    }
    return heading;
}

void TItemMagSub::render() {
    if (is_point_on_screen(&owner->m_2fc, 400.0f, 20.0f) && model != NULL) {
        drawing = this;
        set_texlist(textures);
        push_matrix();
        apply_placement_matrix();
        drawn_node = 0;
        selected_node = 0;
        if (animation != NULL) {
            TObjEneRe7Berura::set_global_state((s32)TItemMagSub::update_node_oscillation);
            TObjPlayer::set_global_flag();
            draw_model_motion(model, animation, animation_frame);
            TObjPlayer::clear_global_state();
            TObjEneRe7Berura::set_global_state(0);
        } else {
            draw_node_tree_with_callback((NJS_OBJECT *)model, (void (*)(NJS_OBJECT *))TItemMagSub::update_node_oscillation);
        }
        drawn_node = 0;
        pop_matrix();
        drawing = NULL;
        if (test_flags(0x20)) {
            TParticleCtrl::end_effect_render();
            copy_argb(&model_material_color, &saved_model_draw_color);
            model_render_flags = saved_model_render_flags;
            clear_flags(0x20);
        }
    }
}

void TItemMagSub::render_shadows() {
    set_default_alpha_blend();
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    copy_argb(&saved_model_draw_color, &model_material_color);
    if (model != NULL) {
        drawing = this;
        set_texlist(textures);
        push_matrix();
        apply_placement_matrix();
        drawn_node = 0;
        selected_node = 0;
        if (animation != NULL) {
            TObjEneRe7Berura::set_global_state((s32)TItemMagSub::update_node_oscillation);
            TObjPlayer::set_global_flag();
            draw_model_motion(model, animation, animation_frame);
            TObjPlayer::clear_global_state();
            TObjEneRe7Berura::set_global_state(0);
        } else {
            model_render_flags |= 0x8011;
            set_color_blend_mode(1, 4, 5, 0);
            set_shadow_material_state();
            draw_ginja_object(model);
            model_render_flags &= ~0x8011;
        }
        drawn_node = 0;
        pop_matrix();
        drawing = NULL;
        if (test_flags(0x20)) {
            TParticleCtrl::end_effect_render();
            copy_argb(&model_material_color, &saved_model_draw_color);
            model_render_flags = saved_model_render_flags;
            clear_flags(0x20);
        }
    }
    set_default_alpha_blend();
    copy_argb(&model_material_color, &saved_model_draw_color);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}

void TItemMagSub::apply_placement_matrix() {
    MagFollowParameters *follow;
    s32 heading;

    post_translate_matrix(&follow_anchor.x);
    if (owner->is_in_fixed_pose() != 0) {
        heading = resolve_owner_heading();
        rotate_matrix_y(NULL, heading);
    } else {
        rotate_matrix_y(NULL, owner->rotation_y);
    }
    post_translate_matrix(translation_offset);
    follow = motion;
    if (follow != NULL) {
        rotate_matrix_zyx(NULL, follow->base_rotation[0] + rotation_delta[0],
                          follow->base_rotation[1] + rotation_delta[1],
                          follow->base_rotation[2] + rotation_delta[2]);
    }
    scale_matrix(NULL, owner_height_scale, owner_height_scale, owner_height_scale);
}

s32 TItemMagSub::get_world_position(Vec *output) {
    if (item->is_owner_frozen() == 0 && output != NULL) {
        push_matrix_from(&identity_matrix);
        apply_placement_matrix();
        Vec origin = mag_sub_local_origin;
        transform_point_by_current_matrix(&origin.x, output);
        pop_matrix();
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void mag_accumulate_drift(f32 *out, s32 *phase, f32 *amplitude, s32 *velocity, s8 *offset) {
    *phase += *velocity;
    *out += *amplitude * sin_table_lookup(*phase + (s32)(MAG_SUB_ANGLE_UNITS * (f32)*offset));
}
#pragma pop

#pragma push
#pragma fp_contract on
void lerp_follow_anchor(Vec *target, Vec *anchor, f32 *t) {
    anchor->x += *t * (target->x - anchor->x);
    anchor->y += *t * (target->y - anchor->y);
    anchor->z += *t * (target->z - anchor->z);
}
#pragma pop

void accumulate_mag_axis_oscillation(f32 *out, s32 *phase, MagAxisOscillationParameters *axis) {
    *phase = *phase + axis->phase_velocity;
    *out = axis->amplitude * sin_table_lookup(*phase + axis->phase_offset);
}

void TItemMagSub::update_node_oscillation(void *node) {
    if (drawing != NULL) {
        drawing->apply_node_oscillation(node);
        drawn_node++;
    }
}

void TItemMagSub::apply_node_oscillation(void *node) {
    s32 i;
    MagNodeOscillationState *state;

    for (i = 0; i != 2; i++) {
        state = &oscillations[i];
        if (state->is_disabled() == 0 && drawn_node == state->node_index()) {
            if (state->uses_x() != 0) {
                rotate_matrix_x(NULL, state->get_angle());
            } else if (state->uses_y() != 0) {
                rotate_matrix_y(NULL, state->get_angle());
            } else if (state->uses_z() != 0) {
                rotate_matrix_z(NULL, state->get_angle());
            }
        }
    }
    if (drawn_node == node_ids[selected_node]) {
        if (test_flags(0x20) == 0) {
            model_render_flags |= 0x10;
            set_constant_material((const NJS_ARGB *)material_parameters);
            TParticleCtrl::begin_effect_render();
            set_flags(0x20);
        }
        if (selected_node != 2) {
            selected_node++;
        }
    } else if (test_flags(0x20) != 0) {
        TParticleCtrl::end_effect_render();
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        clear_flags(0x20);
    }
}

void TItemMagSub::reset_oscillation(s32 from, s32 to) {
    memset(rotation_delta, 0, 0xC);
    memset(drift_phase, 0, 0xC);
    drift_offset[2] = 0.0f;
    drift_offset[1] = 0.0f;
    drift_offset[0] = 0.0f;
}

void TItemMagSub::clear_optional_oscillation_flag(void *sub) {
    if ((u32)sub != 0) {
        ((TItemMagSub *)sub)->clear_flags(2);
    }
}

void TItemMagSub::transition_motion_type(s32 type) {
    set_flags(0x18);
    reset_oscillation(motion_type, type);
    motion_type = type;
    motion = &item_mag_motions[type];
}

void TItemMagSub::set_motion_type(s32 type) {
    TObjPlayer *player;

    reset();
    motion_type = type;
    motion = &item_mag_motions[type];
    player = owner;
    if (player != NULL) {
        s32 joint = motion->joint_index;
        if (joint == -1) {
            VecCopy(&follow_anchor, (Vec *)&player->m_2fc);
            return;
        }
        player->get_anim_node_position(joint, &follow_anchor);
    }
}

void TItemMagSub::release_model_and_destroy() {
    model = NULL;
    animation = NULL;
    textures = 0;
    set_flags(0x80);
}

TItemMagGrowEff::TItemMagGrowEff(TObject *parent, TItemMagSub *sub) : TObject(parent) {
    m_name = TItemMagGrowEff_name;
    if (sub != NULL) {
        mag = sub;
        progress_ticks = 0;
        effect = create_particle_emitter(&mag->cached_position, 0x9D);
        mag->set_growth_flag();
    } else {
        mag = NULL;
        effect = NULL;
        queue_destruction();
    }
}

TItemMagGrowEff::~TItemMagGrowEff() {
    TParticleCtrl::release(effect);
    if (mag != NULL) {
        mag->clear_growth_flag();
    }
}

void TItemMagGrowEff::run_task() {
    Vec position;
    s32 ticks;
    TParticleCtrl *particle;
    TItemMagSub *sub;
    TItemMagSub *active;

    particle = effect;
    if (particle != NULL && particle->all_parents_unqueued_for_destruction() == 0) {
        effect = NULL;
    }
    sub = mag;
    if (sub != NULL && sub->all_parents_unqueued_for_destruction() == 0) {
        mag = NULL;
    }
    if (effect != NULL && (active = mag, active != NULL)) {
        if (active->get_world_position(&position) != 0) {
            if (progress_ticks == 10) {
                TParticleCtrl::release(effect);
                effect = create_particle_emitter(&position, 0x9E);
            }
            effect->set_position(&position);
            ticks = progress_ticks;
            if (ticks == 20) {
                queue_destruction();
                return;
            }
            progress_ticks = ticks + 1;
        }
    } else {
        queue_destruction();
    }
}
