#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/item/TItem.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/technique/TSlicerHistory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/render_util.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/system/task/TObject.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/unk/text_801036CC.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/SlicerLaunchState.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/player/PlayerSlots.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/CapturedTargetList.h"

extern "C" {
f32 *get_weapon_range_record(TItem *item, s16 mode);
}

// The z rotation init_launch_angles gives a slicer, by remaining count + 3 * has_valid_handle.
static const s32 launch_angle_table[18] = {
    -0x1555, 0x4000, 0x7555, 0x2000, -0x6000, -0x1555, 0x0AAA, 0x4000, -0x0AAA,
    -0x1555, 0x4000, 0x7555, 0x2000, -0x6000, -0x1555, 0x2000, -0x6000, -0x1555,
};

const char *TTecSlicer::class_name = "TTecSlicer";
const char *TSlicerHistory::class_name = "TSlicerHistory";

void TSlicerHistory::render() {
    if (all_parents_unqueued_for_destruction() == 0 || find_equipped_item(weapon_handle) == NULL) {
        return;
    }
    {
        saved_model_render_flags = model_render_flags;
        NJS_ARGB col = color;
        if (has_color != 0) {
            model_render_flags |= 0x10;
        } else {
            model_render_flags |= 0x20;
            col.a -= 1.0f;
        }
        if (texlist != 0 && model != NULL) {
            set_texlist(texlist);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix((f32 *)&position);
            rotate_matrix_y(0, rotation_y);
            rotate_matrix_z(0, rotation_z);
            rotate_matrix_x(0, rotation_x);
            scale_current_matrix((f32 *)&scale);
            set_constant_material(&col);
            draw_ginja_object(model);
            set_constant_material(&chunk_material_color_half_alpha_f32);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
        model_render_flags = saved_model_render_flags;
    }
}

void TSlicerHistory::run_task() {
    color.a = color.a - 0.2f;
    if (color.a < 0.0f) {
        color.a = 0.0f;
        queue_destruction();
    }
}

TSlicerHistory::TSlicerHistory(TTecSlicer *slicer, NJS_TEXLIST *texlist, NJS_ARGB *color, u32 weapon_handle) : TObject(slicer) {
    m_name = class_name;
    copy_xyz(&rotation_x, &slicer->rotation_x);
    VecCopy(&position, &slicer->position);
    this->texlist = texlist;
    if (color != NULL) {
        has_color = 1;
        copy_argb(&this->color, color);
    } else {
        has_color = 0;
        this->color.a = 1.0f;
        this->color.r = 0.0f;
        this->color.g = 0.0f;
        this->color.b = 0.0f;
    }
    model = slicer->get_model();
    VecCopy(&scale, &slicer->scale);
    this->weapon_handle = weapon_handle;
}

s32 SlicerTargetList::get_next_captured_target(Vec *out_pos, u16 *out_id, s8 *out_part, f32 *out_radius) {
    TObjChara *hit;
    s32 found;
    if (out_pos != NULL) {
        while (idx < count && idx < 10) {
            found = 0;
            hit = resolve_hittable_target(ids[idx], parts[idx]);
            if (hit != NULL) {
                *out_id = ids[idx];
                *out_part = parts[idx];
                VecCopy(out_pos, &hit->bodies[parts[idx]].center);
                found = 1;
                *out_radius = hit->bodies[parts[idx]].radius;
            }
            idx++;
            if (found != 0) {
                return 1;
            }
        }
    }
    *out_id = 0xFFFF;
    *out_part = 0;
    return 0;
}

void SlicerTargetList::add_target(u16 id, s8 part) {
    if (count < 10) {
        ids[count] = id;
        parts[count] = part;
        count++;
    }
}

SlicerTargetList::SlicerTargetList() { count = 0; idx = 0; }

void TTecSlicer::deliver_target_hit() {
    TObjChara *target;
    if (targetId != 0xFFFF) {
        f32 dist = horizontal_distance_squared(&origin, &position);
        f32 reach = range + radius;
        if (dist < reach * reach) {
            target = resolve_hittable_target(targetId, targetPart);
            if (target != NULL) {
                currentWeapon->deliver_hit(currentPlayer, target, attackKind, damageMultiplier, targetPart);
            }
        }
    }
}

// Ends the slicer when its last step crossed a wall.
void TTecSlicer::destroy_on_collision() {
    if (csnVector(&prev_position, &position, 0x8100) != NULL) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TTecSlicer::advance_position() {
    VecCopy(&prev_position, &position);
    position.x = direction.x * speed + position.x;
    position.y = direction.y * speed + position.y;
    position.z = direction.z * speed + position.z;
}
#pragma pop

// Starts the slicer halfway between the two joints it was thrown from.
void TTecSlicer::set_launch_midpoint(TObjPlayer *player, Vec *first, Vec *second) {
    f32 t;
    t = first->x + second->x;
    t *= 0.5f;
    position.x = t;
    t = first->y + second->y;
    t *= 0.5f;
    position.y = t;
    t = first->z + second->z;
    t *= 0.5f;
    position.z = t;
}

void TTecSlicer::init_launch_angles(TObjPlayer *player, s32 angle) {
    push_matrix();
    rotation_y = angle;
    rotation_x = -0x4000;
    s32 remaining = get_remain_count();
    rotation_z = launch_angle_table[remaining + player->has_valid_handle() * 3];
    pop_matrix();
}

// Hits the target once it is reached and turns to the next captured one.
void TTecSlicer::update() {
    if (horizontal_distance_squared(&position, &destination) < 100.0f) {
        deliver_target_hit();
        if (capturedTargets.get_next_captured_target(&destination, &targetId, &targetPart, &radius) == 0) {
            flags.set(1);
        } else {
            VecCopy(&direction, &destination);
            subtract_vector(&direction, &position);
        }
        normalize_vector(&direction);
    }
}

TTecSlicer *TTecSlicer::create(SlicerLaunchState *launch) {
    TTecSlicer *object = NULL;
    if (launch != NULL) {
        TObjPlayer *player = get_player_by_client_id(launch->player_id);
        if (player != NULL) {
            object = new TTecSlicer(launch, player, &player->position, player->rotation_y);
            TItemAttacker::spawn_item_timer(object, destroy_if_set, 0x5A);
        }
    }
    return object;
}

void TTecSlicer::render() {
    if (all_parents_unqueued_for_destruction() == 0 ||
        update_object_view_visibility(400.0f, 20.0f) == 0 ||
        find_equipped_item(weaponHandle) == NULL) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (useColorOverride != 0) {
        model_render_flags |= 0x10;
        set_constant_material(&argb);
    }
    if (texlist != 0U && model != NULL) {
        set_texlist(texlist);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        post_translate_matrix((f32 *)&position);
        rotate_matrix_y(0, rotation_y);
        rotate_matrix_z(0, rotation_z);
        rotate_matrix_x(0, rotation_x);
        scale_current_matrix((f32 *)&scale);
        draw_ginja_object(model);
        set_constant_material(&chunk_material_color_half_alpha_f32);
        TParticleCtrl::end_effect_render();
    }
    pop_matrix();
    model_render_flags = saved_model_render_flags;
}

#pragma push
#pragma opt_common_subs off
void TTecSlicer::run_task() {
    NJS_ARGB *color;
    currentPlayer = get_player_by_client_id(playerId);
    currentWeapon = (TItemWeapon *)find_equipped_item(weaponHandle);
    if (currentWeapon == NULL || currentPlayer == NULL) {
        queue_destruction();
        return;
    }
    allow_rendering();
    if (useColorOverride != 0) {
        color = &argb;
    } else {
        color = NULL;
    }
    new TSlicerHistory(this, texlist, color, weaponHandle);
    if (test_flags_any(&flags.bits, 1) == 0) {
        update();
    }
    advance_position();
    if (star != NULL) {
        star->copy_position(&position);
    }
    if (test_flags_any(&flags.bits, 2) != 0) {
        queue_destruction();
        return;
    }
    rotation_x += spinVelocity;
    destroy_on_collision();
    currentWeapon = NULL;
    currentPlayer = NULL;
}
#pragma pop

TTecSlicer::~TTecSlicer() {
    if (star != NULL) {
        star->queue_destruction();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TTecSlicer::TTecSlicer(SlicerLaunchState *launch, TObjPlayer *player, Vec *position, int angle) : TObjBase(tl_05) {
    s8 part;
    CapturedTargetList *captured;
    s32 i;
    CapturedTarget *entry;
    m_name = class_name;
    disallow_rendering();
    set_entity_id(pop_free_entity_id());
    model = launch->model;
    texlist = launch->texlist;
    playerId = launch->player_id;
    weaponHandle = launch->item_id;
    attackKind = launch->attack_kind;
    comboStage = launch->combo_stage;
    damageMultiplier = launch->damage_multiplier;
    copy_argb(&argb, &launch->color);
    spinVelocity = launch->spin_velocity;
    useColorOverride = 1;
    direction.x = sin_table_lookup(angle);
    direction.y = 0.0f;
    direction.z = cos_table_lookup(angle);
    if (0.0f != vector_length(&direction)) {
        normalize_vector(&direction);
    }
    currentPlayer = player;
    currentWeapon = (TItemWeapon *)find_item_by_id(weaponHandle);
    init_launch_angles(currentPlayer, launch->facing);
    set_launch_midpoint(currentPlayer, &launch->first_joint, &launch->second_joint);
    range = *get_weapon_range_record(currentWeapon, 0);
    speed = 6.0f;
    VecCopy(&origin, &this->position);
    VecCopy(&destination, &this->position);
    radius = 0.0f;
    captured = currentPlayer->get_extended_state();
    if (captured != NULL) {
        if (captured->get_captured_target_count() == 0) {
            flags.set(1);
        } else {
            for (i = 0; i != captured->get_captured_target_count(); i++) {
                entry = captured->get_captured_target_entry(i);
                part = entry->get_captured_target_collider_index();
                capturedTargets.add_target(entry->get_uid(), part);
            }
        }
    }
    star = NULL;
    currentPlayer = NULL;
    currentWeapon = NULL;
    targetId = 0xFFFF;
    targetPart = 0;
}
#pragma pop

TSlicerHistory::~TSlicerHistory() {}

NJS_OBJECT *TTecSlicer::get_model() { return model; }
s16 TTecSlicer::get_remain_count() { return comboStage; }
void TTecSlicer::destroy_if_set(TObject *object) {
    if (object != NULL) {
        object->queue_destruction();
    }
}
SlicerTargetList::~SlicerTargetList() {}
