#include "pso/player/TEquippedWeaponDrawTask.h"
#include "types.h"
#include <string.h>
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItem.h"
#include "pso/weapon/WeaponAttackActions.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/ItemCreateFunction.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/MatrixStack.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/item/item_pmt.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/item/TItemData.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/ProjectedStripDraw.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/render/GinjaTextureMatrices.h"


void set_shadow_material_state(void);

extern s16 weapon_node_ids[];
extern s16 weapon_node_material_index;
extern u8 *weapon_render_callback_object;

void TItemWeapon::draw_weapon_model() {
    s32 visible;
    WeaponParams *parameters;
    if ((void *) this->owner == NULL || this->item_model == NULL) {
        return;
    }
    {
        reset_model_node_counter();
        if (this->has_no_defer_render() != 0) {
            visible = 1;
        } else {
            visible = this->update_object_view_visibility(400.0f, 20.0f);
        }
        set_texlist((this->texlist));
        push_matrix_from((void *)((TObjMotion *)(this->owner))->get_joint_matrix((s8)get_attach_joint()));
        if ((visible != 0) && (this->is_hidden() == 0)) {
            weapon_render_callback_object = (u8 *)this;
            weapon_node_material_index = color_node;
            parameters = this->parameters;
            weapon_node_ids[0] = parameters->effect_nodes[0];
            weapon_node_ids[1] = parameters->effect_nodes[1];
            weapon_node_ids[2] = parameters->effect_nodes[2];
            if (this->model_motion == NULL) {
                this->set_model_node_callback(apply_weapon_node_material);
            } else {
                set_chunk_model_node_callback(apply_weapon_node_material);
            }
            TEquippedWeaponDrawTask::save_model_render_state();
            model_render_flags &= 0xFFFFFFEF;
            TEquippedWeaponDrawTask::set_fade_alpha((f32)this->get_owner_alpha());
            if (this->has_no_defer_render() != 0) {
                model_render_flags |= 0x8011;
                set_color_blend_mode(1, 4, 5, 0);
                set_shadow_material_state();
                if (this->model_motion == NULL) {
                    if (this->test_weapon_flags(0x800000) != 0U) {
                        draw_chunk_object(this->item_model);
                    } else {
                        this->draw_model_nodes(NULL);
                    }
                } else {
                    set_motion_packed_rotation();
                    draw_model_motion(this->item_model, this->model_motion, (f32)this->motion_frame);
                    clear_motion_packed_rotation();
                }
                model_render_flags &= 0xFFFF7FEE;
            } else if (this->model_motion == NULL) {
                if (this->test_weapon_flags(0x40) != 0U) {
                    this->apply_sign_effect(this->owner->item_node_matrices);
                } else if (this->test_weapon_flags(0x800000) != 0U) {
                    draw_chunk_object(this->item_model);
                } else {
                    this->draw_model_nodes(this->owner->item_node_matrices);
                }
            } else {
                set_motion_packed_rotation();
                draw_model_motion(this->item_model, this->model_motion, (f32)this->motion_frame);
                clear_motion_packed_rotation();
            }
            TItem::end_material_color();
            TItem::end_effect_render();
            this->end_particle_tev();
            this->end_shield_tev();
            TEquippedWeaponDrawTask::end_fade();
            TEquippedWeaponDrawTask::restore_model_render_state();
            if (this->model_motion == NULL) {
                this->set_model_node_callback(NULL);
            } else {
                set_chunk_model_node_callback(NULL);
            }
            item_render_state.reset();
        } else {
            this->visit_model_nodes(this->owner->item_node_matrices);
        }
        pop_matrix();
        reset_model_node_counter();
    }
}

void TItemWeapon::draw_weapon_at_joint(s8 joint) {
    s32 saved_joint = get_attach_joint();
    set_attach_joint(joint);
    draw_weapon_model();
    set_attach_joint(saved_joint);
}
void TItemWeapon::release_model() { memset(trails, 0, 16); clear_weapon_flags((uaddr)((void*)12)); TItemEquipBase::release_model(); }


struct SRankModelIds { s32 a; s32 b; s32 c; u16 d; u8 e; };


extern SRankModelIds srank_weapon_model_ids[];
void TItemWeapon::request_equipped_model() {
    u8 v = this->get_item_group();
    if (v >= 0xAA) {
        SRankModelIds t;
        t.a = srank_weapon_model_ids[0].a;
        t.b = srank_weapon_model_ids[0].b;
        t.c = srank_weapon_model_ids[0].c;
        t.d = srank_weapon_model_ids[0].d;
        t.e = srank_weapon_model_ids[0].e;
        v = ((u8 *)&t)[get_motion_type()];
    }
    this->request_model_load(v);
    this->create_weapon_trail_effects();
}


TItemWeapon::~TItemWeapon() {}


extern const f32 weapon_float_zero;
extern const u8 weapon_unidentified_flag;

TItemWeapon::TItemWeapon(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    s32 identified;
    u8 special;
    set_attach_slot(6);
    parameters = (WeaponParams *)lookup_item_pmt_record(item);
    technique_boosts = (const TechniqueBoostParam *)TObjPlayer::get_shield_pmt_entry(parameters->technique_boost);
    photon_color_id = (s16) (s8) parameters->photon_color;
    grind = item[3];
    identified = ((TItemData *)item)->check_item_flags();
    special = parameters->special;
    if (special == 0) {
        special_selector = (u8) (item[4] & 0xFFFFFFBF);
    } else {
        special_selector = special;
    }
    if (identified == 0) {
        special_selector = (u8) (special_selector | weapon_unidentified_flag);
    }
    memcpy(attributes, item + 6, 6);
    impact_callback = 0;
    hit_callback = 0;
    shot_callback = create_gun_shot;
    this->gun_point_joint = parameters->gun_point_joint;
    set_weapon_trail_joints(this, 0, parameters->trail_joints[0], parameters->trail_joints[1]);
    set_weapon_trail_joints(this, 1, parameters->trail_joints[2], parameters->trail_joints[3]);
    set_weapon_trail_joints(this, 2, -1, -1);
    set_weapon_trail_joints(this, 3, -1, -1);
    memset(trails, 0, 0x10);
    weapon_flags = 0;
    shot_speed = 19.0f;
    technique_roll = 0;
    previous_technique_roll = 0;
    technique_roll_range = 0;
    u32 group = get_item_group();
    if (group < 0xAA) {
        motion_type = get_weapon_class_motion_type(group);
        if (photon_color_id != -1) {
            color_node = parameters->color_node;
        } else {
            color_node = -1;
        }
    } else {
        motion_type = 1;
        color_node = -1;
    }
    stage = -1;
    motion_frame = weapon_float_zero;
    if (get_item_group() == 0) {
        photon_color_id = -1;
    } else {
        item_render_state.reset();
        photon_phase = weapon_float_zero;
    }
    set_weapon_category_flags();
    if (parameters->flags & 1) {
        effect_flags.set(0x20);
    }
    if (parameters->flags & 2) {
        this->set_weapon_flags(0x40000);
    }
    if (parameters->flags & 4) {
        this->set_weapon_flags(0x80000);
    }
}

// weapon_factory_table's entry for weapons without a class of their own.
TItem *create_common_weapon(u8 *item) {
    return new TItemWeapon(tl_05, item);
}

TItem *create_weapon_for_item(u8 *item) {
    if (item != NULL) {
        ItemCreateFunction factory = get_weapon_factory_for_item(item);
        return factory(item);
    }
    return NULL;
}

void TItemWeapon::free() {}
void TItemWeapon::load_data() {}
u8 TItemWeapon::get_motion_type() { return motion_type; }
void TItemWeapon::set_weapon_flags(u32 mask) { weapon_flags |= mask; }
void TItemWeapon::clear_weapon_flags(u32 mask) { weapon_flags &= ~mask; }
void TItemWeapon::set_flag_8() { set_weapon_flags(8); }

void set_weapon_trail_joints(TItemWeapon *weapon, s32 trail, s32 start_joint, s32 end_joint) {
    weapon->trail_start_joints[trail] = start_joint;
    weapon->trail_end_joints[trail] = end_joint;
}

void TObjChara::set_model_param(s16 v) { this->special_power = v; }
void TObjChara::set_model_id(s16 v) { this->special_kind = v; }
s16 TObjPlayer::is_status_subsystem_ready() { return attack_state.get_validated_attack_kind(); }
CapturedTargetList *TObjPlayer::get_extended_state() { return attack_state.get_lockon_targets(); }
f32 TObjPlayer::query_extended_state() { return attack_state.get_attack_damage_scale(); }
int TObjPlayer::test_flag30_bit0x100000() { return test_actor_flags((uaddr)((void*)1048576)); }
MtxP get_model_joint_matrix(TObjPlayer *player, int joint) { return player->item_node_matrices[joint]; }
void PlayerAttackController::set_attack_kind(s16 kind) { attack_kind = kind; }

CapturedTargetList *PlayerAttackController::get_lockon_targets() { return &lockon_targets; }

f32 PlayerAttackController::get_attack_damage_scale() { return attack_damage_scale_table[attack_kind]; }

f32 PlayerAttackController::get_attack_accuracy_scale() {
    return attack_type_accuracy_scales[attack_kind] * attack_combo_accuracy_multipliers[get_validated_attack_stage()];
}

void increment_model_node_counter(void) {
    int count = model_node_counter;
    model_node_counter = count + 1;
}

int get_model_node_counter() {  return model_node_counter; }

void TItemWeapon::set_model_node_callback(void (*callback)(NJS_OBJECT *)) { model_node_callback = callback; }

void reset_model_node_counter(void) { model_node_counter = 0; }

int TObjPlayer::is_flag_b0_4() { return this->motion_flags & 0x4; }
void TItemEffectWeapon::set_flags(u32 mask) { flags |= mask; }
s16 CapturedTarget::get_captured_target_collider_index() { return collider_index; }
u16 CapturedTarget::get_uid() { return uid; }


CapturedTarget *CapturedTargetList::get_captured_target_entry(s32 i) {
    return &entries[i];
}

s32 CapturedTargetList::get_captured_target_count() {
    s32 n;
    n = count;
    if ((n < 0) || (n > 0xA)) {
        return 0;
    }
    return n;
}
