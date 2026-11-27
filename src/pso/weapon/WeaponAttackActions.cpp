#include "pso/player/TEquippedWeaponDrawTask.h"
#include "pso/system/MatrixStack.h"
#include "types.h"
#include "clib/fp_convert.h"
#include "pso/render/GinjaDrawUtil.h"
#include "pso/object/TActorLight.h"
#include "pso/item/item_pmt.h"

struct NJS_OBJECT;
#include <string.h>
#include "pso/item/WeaponAttribute.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponTsumikiri.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/weapon/TItemWeaponWindmill.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TItemData.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/weapon/WeaponAttackActions.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/weapon/TItemWeaponPartisan.h"
#include "pso/system/PadRumble.h"
#include "pso/item/TItemEquipBase.h"
#include <stddef.h>
#include "pso/map/FloorArea.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/item/item_param.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/effect/item/TItemEffEquip.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/MatrixStack.h"
#include "pso/camera/TCameraCtrl.h"
#include <stdlib.h>


#include "pso/system/task/TObject.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"


extern "C" {
extern const f32 weapon_float_tenth;
extern Vec weapon_light_direction[];
extern NJS_ARGB weapon_light_color[];


TObjChara *resolve_hittable_target(s32, s32);


void TItemWeapon::set_weapon_category_flags() {
    s32 r = this->get_attack_flags();
    u32 flags = 0x10000;
    if (r & 1) {
        flags = 0x20000;
    }
    set_weapon_flags(flags);
}

void TItemWeapon::drain_owner_hp_fraction(f32 fraction) {
    if (owner != NULL) {
        subtract_actor_hp(owner, (fraction * (f32) ((TObjChara *)owner)->get_hpmax()));
    }
}

s32 TItemWeapon::is_mode_two_and_ready() {
    if ((owner->is_status_subsystem_ready() == 2) &&
        (is_identified() == 1)) {
        return 1;
    }
    return 0;
}

void TItemWeapon::spawn_light_task() {
    Vec direction = weapon_light_direction[0];
    NJS_ARGB color = weapon_light_color[0];
    new TActorLight(0.2f, &color, &direction, 1, owner, tl_07);
}

void TItemWeapon::restore_action_type() {
    if (test_weapon_flags(0x04000000) != 0U) {
        owner->attack_state.set_attack_kind(2);
        clear_weapon_flags(0x04000000);
    }
}

void TItemWeapon::remap_extra_attack_type() {
    if ((this->test_weapon_flags(0x20) != 0U) && (owner->attack_state.get_validated_attack_kind() == 2)) {
        if (this->test_weapon_flags(0x100000) != 0U) {
            owner->attack_state.set_attack_kind(0);
        } else {
            owner->attack_state.set_attack_kind(1);
        }
        set_weapon_flags(0x04000000);
    }
}

CsnHit *TItemWeapon::trace_from_owner(Vec *point) {
    Vec from;
    VecCopy(&from, &owner->body_center);
    from.y = point->y;
    return csnVector(&from, point, 0x8100);
}

void TItemWeapon::transform_model_node() {  }

void TItemWeapon::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {}

void TItemWeapon::on_unequipped() {  }

void TItemWeapon::on_equipped() {  }

void TItemWeapon::update_weapon() {  }

void TItemWeapon::draw_held_model() {  }

void TItemWeapon::update_idle() {  }

void TItemWeapon::update_attack() {  }

void TItemWeapon::emit_marker_effects() {  }

void TItemWeapon::carry_over_stats(TItemData *data, TItem *item) { memcpy(data->data1.data_u8 + 6, ((TItemWeapon *)item)->attributes, 6); }
}

void TItemWeapon::activate_effect(s32 effect) {
    technique_roll = effect;
}

void TItemWeapon::roll_technique() {
    previous_technique_roll = technique_roll;
    send_activate_effect((s32) ((f32) technique_roll_range * (3.0517578e-05f * (f32) rand())));
}

void TItemWeapon::set_flag_8_unless_on_ground() {
    u8 *self;
    if (this != NULL) {
        self = (u8 *)this;
        if (((TItem *)(this))->get_mode() != 0) {
            ((TItemWeapon *)self)->set_flag_8();
        }
    }
}

void *TItemWeapon::get_center() {
    TObjPlayer *player = owner;
    if (player != NULL) {
        player->get_anim_node_position(0x30, &held_position);
    }
    return &held_position;
}

void TItemWeapon::call_impact_callback(saddr start, saddr end) {
    if (impact_callback != NULL) {
        ((s32 (*)(s32, void *, s32, s32))impact_callback)((saddr)tl_05, this, start, end);
    }
}

void TItemWeapon::apply_model_params() {
    s16 model_id;
    s16 model_param;

    get_weapon_special_type_amount(special_selector & 0x3F, &model_id, &model_param);
    owner->set_model_id(model_id);
    owner->set_model_param(model_param);
    owner->recalc_stats();
}

s32 TItemWeapon::is_identified() {
    TItemData data;

    data.init();
    copy_to_item_data(&data);
    return data.check_item_flags();
}

void TItemWeapon::refresh_special() {
    if (is_identified() == 0) {
        special_selector = special_selector & 0x7F;
    }
    apply_model_params();
}

void TItemWeapon::update_trail_slot(s32 slot) {
    Vec a;
    Vec b;
    if (is_default_camera() != 0 && has_no_defer_render() == 0 &&
        owner->test_action_mask(0xE0) != 0 &&
        owner->is_flag_b0_4() == 0 &&
        !((s32)main_task.get_task_flags() & 0x78)) {
        if (trails[slot] != NULL) {
            get_joint_position(trail_start_joints[slot], &a);
            get_joint_position(trail_end_joints[slot], &b);
            trails[slot]->push_trail_interpolated(&a.x, &b.x);
        }
    }
}

void TItemWeapon::create_weapon_trail_effects() {
    u32 flags;
    s32 i;
    flags = pack_weapon_trail_color(this) & 0x8FFFFFFF;
    if (effect_objects != NULL) {
        for (i = 0; i != 4; i++) {
            if (trail_start_joints[i] != -1) {
                trails[i] = new TItemEffectWeapon(effect_objects, flags);
            }
            if (trails[i] != NULL && test_actor_flags(0x2000) != 0) {
                trails[i]->set_flags(1);
            }
        }
    }
}

u32 pack_weapon_trail_color(TItemWeapon *weapon) {
    NJS_ARGB w = weapon->get_weapon_color();
    return (__cvt_fp2unsigned(255.0f * w.a) << 24 | __cvt_fp2unsigned(255.0f * w.r) << 16 | __cvt_fp2unsigned(255.0f * w.g) << 8) | __cvt_fp2unsigned(255.0f * w.b);
}

void TItemWeaponTsumikiri::spawn_pg_effect(const Vec *origin, saddr item, f32 radius) {
    ItemEffPGParams prm;
    if (item < 0 || item >= 200) {
        return;
    }
    if (is_active_in_game() == 0) {
        return;
    }
    remap_extra_attack_type();
    prm.init_params();
    fill_status_info(&prm);
    VecCopy(&prm.position, origin);
    prm.max_radius = radius;
    prm.model = this->second_model;
    prm.texture_list = (NJS_TEXLIST *)this->texlist;
    if (owner->is_locally_controlled() != 0) {
        TItemEffPG::create(tl_05, &prm);
    } else {
        TItemEffPG::create(tl_05, &prm, item);
    }
    this->restore_action_type();
}

void TItemWeapon::fire_shot_at_target(Vec *origin, NJS_OBJECT *model, s32 angle) {
    Vec v;
    WeaponEffectDescriptor atk;
    WeaponRangeRecord *range;
    CapturedTargetList *state;
    CapturedTarget *item;
    TObjCollidable *ph;
    CsnHit *hit;
    s32 off;
    if (is_active_in_game() != 0) {
        range = get_weapon_range_record(this, owner->is_status_subsystem_ready());
        reset_weapon_effect_descriptor(&atk);
        fill_status_info(&atk);
        VecCopy(&atk.position, origin);
        atk.rotation_y = owner->rotation_y + angle;
        atk.range = range->reach;
        atk.speed = shot_speed;
        atk.model = model;
        atk.texlist = this->texlist;
        init_weapon_effect_descriptor(&atk);
        remap_extra_attack_type();
        hit = trace_from_owner(origin);
        if (hit != NULL) {
            VecCopy(&atk.position, &hit->contact->point);
            atk.flags |= 0x800;
        } else if ((state = owner->get_extended_state()) != 0 && state->get_captured_target_count() > 0) {
            if ((item = state->get_captured_target_entry(0)) != 0) {
                if ((ph = (TObjCollidable *)find_entity_by_id(item->get_uid())) != NULL && ph->bodies != NULL) {
                    VecCopy(&v, &ph->bodies[item->get_captured_target_collider_index()].center);
                    subtract_vector(&v, origin);
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, angle);
                    transform_point_by_current_matrix(&v.x, &atk.direction);
                    atk.flags |= 1;
                    pop_matrix();
                }
            }
        }
        if (atk.attack_kind == 2 && this->is_identified() == 0) {
            atk.accuracy *= weapon_float_tenth;
        }
        TItemAttackCol::create(tl_05, &atk);
        this->restore_action_type();
    }
}

void TItemWeapon::fill_status_info(AttackColParams *params) {
    remap_extra_attack_type();
    params->client_id = static_cast<s16>(owner->get_entity_id());
    params->room = owner->get_room();
    params->item_id = ((TItem *)this)->get_item_id();
    params->accuracy = owner->attack_state.get_attack_accuracy_scale();
    params->attack_kind = (s32) owner->is_status_subsystem_ready();
    params->damage_scale = owner->query_extended_state();
    restore_action_type();
}

void TItemWeapon::launch_rare_weapon_special(Vec *origin, s32 enable, f32 scale) {
    CapturedTargetList *ext;
    Vec pos;
    f32 dist;
    s32 found;

    if (is_active_in_game() == 0) {
        return;
    }
    ext = owner->get_extended_state();
    if (ext == NULL) {
        return;
    }
    if (origin == NULL) {
        origin = &owner->body_center;
    }
    found = 0;
    if (ext->get_captured_target_count() != 0) {
        CapturedTarget *e = ext->get_captured_target_entry(ext->get_captured_target_count() - 1);
        TObjChara *t = ((TObjChara *(*)(u16, s16))resolve_hittable_target)(e->get_uid(), e->get_captured_target_collider_index());
        if (t != NULL) {
            CollisionBody *part = &t->bodies[e->get_captured_target_collider_index()];
            VecCopy(&pos, &part->center);
            found = 1;
        }
    }
    if (found == 0) {
        Vec v;
        WeaponRangeRecord *range;
        push_matrix_from(identity_matrix);
        range = get_weapon_range_record(this, 2);
        v.x = v.y = weapon_float_zero;
        v.z = range->reach;
        rotate_matrix_y(0, owner->rotation_y);
        transform_point_by_current_matrix(&v.x, &pos);
        pop_matrix();
        vec3_add_to(&pos, origin);
    }
    {
        CsnHit *hit = csnVector(origin, &pos, 0x8100);
        if (hit != NULL) {
            dist = xyz_distance(origin, &hit->contact->point);
        } else {
            dist = xyz_distance(origin, &pos);
        }
    }
    if (enable != 0) {
        for (s32 i = 0; i != ext->get_captured_target_count(); i++) {
            CapturedTarget *e = ext->get_captured_target_entry(i);
            TObjChara *t = ((TObjChara *(*)(u16, s16))resolve_hittable_target)(e->get_uid(), e->get_captured_target_collider_index());
            if (t != NULL) {
                CollisionBody *part = &t->bodies[e->get_captured_target_collider_index()];
                CapturedTarget *e2 = ext->get_captured_target_entry(i);
                DelayedWeaponHit sp;
                sp.reserved = 0;
                sp.kind = 1;
                sp.source = owner->get_entity_id();
                sp.target = t->get_entity_id();
                sp.weapon = ((TItem *)this)->get_item_id();
                sp.collider = e2->get_captured_target_collider_index();
                sp.damage = scale * owner->query_extended_state();
                spawn_item_attacker(tl_05, &owner->position, (s32)(xyz_distance(origin, &part->center) / shot_speed), &sp);
            }
        }
    }
    s32 n = (s32)(dist / shot_speed);
    if (n < 0) {
        n = 0;
    }
    if (shot_callback != NULL && is_model_shown() == 1) {
        shot_callback(this, origin, &pos, (f32)n);
    }
}

s32 TItemWeapon::launch_shot(Vec *origin, s32 i, s32 angle, s32 apply) {
    s32 launched;
    DelayedWeaponHit hit;
    WeaponRangeRecord *range_record;
    f32 distance_scale;
    f32 flight_frames;
    s32 has_aim_target;
    CapturedTarget *aim_entry;
    CapturedTarget *last_entry;
    CapturedTargetList *targets;
    CollisionBody *target_body;
    CsnHit *wall_hit;
    TObjChara *aim_target;
    launched = 0;
    if (is_active_in_game() != 0) {
        targets = owner->get_extended_state();
        if (targets != 0) {
            has_aim_target = 0;
            aim_target = NULL;
            Vec endpoint = *origin;
            if (i < targets->get_captured_target_count()) {
                aim_entry = targets->get_captured_target_entry(i);
                aim_target = ((TObjChara *(*)(u16, s16))resolve_hittable_target)(aim_entry->get_uid(), aim_entry->get_captured_target_collider_index());
                if (aim_target != NULL) {
                    target_body = &aim_target->bodies[aim_entry->get_captured_target_collider_index()];
                    VecCopy(&endpoint, &target_body->center);
                    subtract_vector(&endpoint, origin);
                    distance_scale = normalize_vector(&endpoint) - target_body->radius;
                    endpoint.x *= distance_scale;
                    endpoint.y *= distance_scale;
                    endpoint.z *= distance_scale;
                    vec3_add_to(&endpoint, origin);
                    has_aim_target = 1;
                }
            }
            if (has_aim_target == 0) {
                Vec fallback;
                push_matrix_from(identity_matrix);
                range_record = get_weapon_range_record(this, owner->is_status_subsystem_ready());
                fallback.y = weapon_float_zero;
                fallback.x = weapon_float_zero;
                fallback.z = range_record->reach;
                rotate_matrix_y(0, owner->rotation_y + angle);
                transform_point_by_current_matrix(&fallback.x, &endpoint);
                pop_matrix();
                vec3_add_to(&endpoint, origin);
            }
            Vec rayOrigin = owner->body_center;
            rayOrigin.y = origin->y;
            wall_hit = csnVector(&rayOrigin, &endpoint, 0x8100);
            if (wall_hit == NULL) {
                if (aim_target != NULL) {
                    last_entry = targets->get_captured_target_entry(i);
                    target_body = &aim_target->bodies[last_entry->get_captured_target_collider_index()];
                    flight_frames = xyz_distance(origin, &target_body->center) / shot_speed;
                    if (apply != 0) {
                        remap_extra_attack_type();
                        hit.reserved = 0;
                        hit.kind = (s32) owner->is_status_subsystem_ready();
                        hit.source = owner->get_entity_id();
                        hit.target = aim_target->get_entity_id();
                        hit.weapon = this->get_item_id();
                        hit.collider = last_entry->get_captured_target_collider_index();
                        hit.damage = owner->query_extended_state();
                        spawn_item_attacker(tl_05, origin, ((s32) flight_frames), &hit);
                        launched = 1;
                        this->restore_action_type();
                    }
                } else {
                    flight_frames = xyz_distance(origin, &endpoint) / shot_speed;
                }
            } else {
                VecCopy(&endpoint, &wall_hit->contact->point);
                flight_frames = xyz_distance(origin, &endpoint) / shot_speed;
                if ((wall_hit->contact->flags & 0x100) && (impact_callback != NULL)) {
                    spawn_land_hit_effect(tl_05, this, origin, &endpoint, (s32)flight_frames);
                }
            }
            this->spawn_light_task();
            if ((shot_callback != NULL) && (is_model_shown() == 1)) {
                shot_callback(this, origin, &endpoint, flight_frames);
            }
        }
    }
    return launched;
}

void TItemWeaponWindmill::for_each_target_in_range(f32 range) {
    TObjChara *target;
    u16 uid;
    CapturedTargetList *state;
    s32 i;
    CapturedTarget *entry;
    s32 body;
    s32 attack_kind;
    if (is_active_in_game() != 0) {
        remap_extra_attack_type();
        state = owner->get_extended_state();
        if (state != NULL) {
            for (i = 0; i != state->get_captured_target_count(); i++) {
                entry = state->get_captured_target_entry(i);
                uid = entry->get_uid();
                body = entry->get_captured_target_collider_index();
                target = resolve_hittable_target(uid, body);
                if (target != NULL && horizontal_distance_squared(&owner->position, &target->position) < range) {
                    attack_kind = owner->is_status_subsystem_ready();
                    deliver_hit(owner, target, attack_kind, owner->query_extended_state(), body);
                }
            }
        }
        restore_action_type();
    }
}

void TItemWeaponPartisan::apply_scale_if_active(f32 damage_scale) {

    if (this->is_active_in_game() != 0) {
        this->remap_extra_attack_type();
        owner->deliver_attack_hits(damage_scale);
        this->restore_action_type();
    }
}

extern const f32 weapon_float_one;

void TItemWeapon::update_active_game_effect() {

    if (is_active_in_game() != 0) {
        remap_extra_attack_type();
        owner->deliver_attack_hits(weapon_float_one);
        restore_action_type();
    }
}

s32 TItemWeapon::get_attack_stage() {
    if (owner != NULL) {
        if (owner->test_action_mask(0x20) != 0) {
            return 0;
        }
        if (owner->test_action_mask(0x40) != 0) {
            return 1;
        }
        if (owner->test_action_mask(0x80) != 0) {
            return 2;
        }
    }
    return -1;
}


s32 TItemWeapon::is_active_in_game() {
    u8 active = 0;
    if (owner != NULL && get_mode() == ITEM_MODE_EQUIPPED) {
        active = 1;
    }
    return active;
}


extern "C" {
s32 add_weapon_grind(TItemWeapon *weapon, s32 amount);

s32 add_weapon_grind(TItemWeapon *weapon, s32 amount) {
    if ((s32)(weapon->parameters->max_grind - (u8)amount) < weapon->grind) {
        weapon->grind = weapon->parameters->max_grind;
    } else {
        weapon->grind += amount;
    }
    weapon->refresh_owner_stats();
    return 1;
}

u32 TItemWeapon::get_attack_flags() {
    u32 flags = 0;
    WeaponRangeRecord *range;
    if (this->get_icon_index() == 3) {
        flags |= 2;
    } else {
        flags |= 1;
    }
    range = get_weapon_range_record(this, 0);
    if (range != 0 && range->max_targets > 1) {
        flags |= 4;
    }
    return flags;
}

void TItemWeapon::deliver_hit(TObjPlayer *attacker, TObjChara *target, s32 attack_kind, f32 scale, s32 body) {
    ItemSoundRequest sound;
    f32 accuracy;
    f32 damage_dealt;
    s32 damage;
    TObjPlayer *player;
    if (get_mode() == 2) {
        player = owner;
        if ((player != NULL) && (target != NULL)) {
            accuracy = player->attack_state.get_attack_accuracy_scale();
            if ((attack_kind == 2) && (is_identified() == 0)) {
                accuracy *= weapon_float_tenth;
            }
            if (target->calc_distance_accuracy_penalty(owner, &target->bodies[body], NULL, accuracy) != 0) {
                damage_dealt = weapon_float_zero;
                switch (attack_kind) {
                case 0:
                    damage_dealt = target->receive_physical_attack(owner, scale);
                    break;
                case 1:
                    damage_dealt = target->receive_physical_attack(owner, scale);
                    target->apply_knockback_from_attacker(owner, weapon_float_tenth * damage_dealt);
                    break;
                case 2:
                    target->receive_weapon_special_attack(owner, &target->bodies[body]);
                    break;
                }
                if (hit_callback != NULL) {
                    hit_callback((saddr)tl_05, this, target->get_entity_id(), body);
                }
                damage = (s32)damage_dealt;
                owner->gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(owner, damage));
                owner->apply_camera_shake(target, damage);
                sound.clear();
                sound.group = get_item_group();
                sound.index = get_item_index();
                sound.player = owner;
                sound.target = target;
                sound.collider = body;
                play_weapon_hit_sound(&sound);
            }
        }
    }
}
}
void TItemWeapon::perform_action() {
    ItemSoundRequest sound;
    Vec gun_point;
    Vec fallback_point;
    if (is_active_in_game() && !is_hidden() && is_current_area_item_enabled()) {
        rotation_y=owner->rotation_y;
        stage=get_attack_stage();
        sound.clear();
        sound.group=get_item_group();
        sound.index=get_item_index();
        sound.player=owner;
        play_weapon_owner_sounds(&sound);
        if(test_weapon_flags(0x40000)) {
            start_pad_rumble_client(0x80, 5, (s16)owner->get_entity_id());
        } else if(test_weapon_flags(0x80000) && is_mode_two_and_ready()) {
            start_pad_rumble_client(0x80, 5, (s16)owner->get_entity_id());
        }
        emit_marker_effects();
        set_weapon_flags(0x1000000);
        if(!test_weapon_flags(2)) {
            if(test_weapon_flags(0x8000)) {
                get_gun_point(&gun_point);
                fire_shot_at_target(&gun_point, second_model, 0);
                return;
            }
            if(test_weapon_flags(0x20000)) {
                update_active_game_effect();
                return;
            }
            get_gun_point(&fallback_point);
            launch_shot(&fallback_point,0,0,1);
        }
    }
}

void TItemWeapon::sample_dual_muzzles(Vec *primary, Vec *secondary) {
    draw_weapon_model();
    get_gun_point(primary);
    draw_weapon_at_joint(0x23);
    get_gun_point(secondary);
}

void TItemWeapon::update_trails() {
    if (test_weapon_flags(0x400U) != 0U) {
        draw_weapon_at_joint(0x30);
        update_trail_slot(0);
        draw_weapon_at_joint(0x23);
        update_trail_slot(1);
        return;
    }
    if (test_weapon_flags(1U) == 0U) {
        draw_weapon_model();
        update_trail_slot(0);
        update_trail_slot(1);
    }
}

void TItemWeapon::render_equipped_deferred() {
    if (((uaddr) this->owner != 0U) && (test_weapon_flags(0xCU) == 0xCU) && (test_weapon_flags(0x80U) == 0U)) {
        this->draw_held_model();
        update_trails();
    }
}
void TItemWeapon::render_equipped_shadow() {
    if (((uaddr) this->owner != 0U) && (test_weapon_flags(0xCU) == 0xCU) && (test_weapon_flags(0x80U) == 0U) && (test_weapon_flags(0x1000U) == 0U)) {
        this->draw_held_model();
        if (test_weapon_flags(0x400U) != 0U) {
            draw_weapon_at_joint(0x30);
            draw_weapon_at_joint(0x23);
            return;
        }
        if (test_weapon_flags(1U) == 0U) {
            draw_weapon_model();
        }
    }
}
void TItemWeapon::render_equipped() {
    s32 count;
    if (((uaddr) this->owner != 0U) && (test_weapon_flags(0xCU) == 0xCU) && (test_weapon_flags(0x80U) == 0U)) {
        if (test_weapon_flags(0x800U) != 0U) {
            TEquippedWeaponDrawTask::queue_weapon(get_item_id());
            return;
        }
        this->draw_held_model();
        this->update_trails();
        count = 0;
        do {
            TItemEffectWeapon *trail = this->trails[count];
            if (trail) {
                trail->render_trail();
            }
            count++;
        } while (count != 4);
    }
}
void TItemWeapon::update_equipped() {
    TItemWeapon* self=this;
    s32 stage;
    u32 frames;
    s32 count;
    s32 idle_count;
    if(self->test_weapon_flags(0x100)==0) {
        if(self->test_weapon_flags(0x4000)!=0) self->request_particle_indirect_effect();
        ((TItemEquipBase *)self)->bind_loaded_resources();
        stage=self->get_attack_stage();
        if(stage!=self->stage) {
            self->clear_weapon_flags(0x1000000);
            self->stage=stage;
        }
        if(stage>=0) self->set_weapon_flags(0x10);
        else clear_weapon_flags(0x10);
        if(stage>=0 || self->owner->is_lock_on_flag_set()) self->update_attack();
        else self->update_idle();
        if(self->model_motion) {
            self->motion_frame+=weapon_float_one;
            frames=self->model_motion->nbFrame;
            if((f32)frames<=self->motion_frame) self->motion_frame-=(f32)frames;
        }
        register_technique_boosts(technique_boosts);
        self->update_weapon();
        if(!((TObjChara *)self->owner)->is_in_fixed_pose()) self->advance_weapon_photon_phase();
        if(self->is_hidden()) {
            count=0;
            do {
                TItemEffectWeapon* trail=self->trails[count];
                if(trail) trail->update_hidden();
                count++;
            } while(count!=4);
            return;
        }
        idle_count=0;
        do {
            TItemEffectWeapon* trail=self->trails[idle_count];
            if(trail) trail->update_shown();
            idle_count++;
        } while(idle_count!=4);
    }
}

void TItemWeapon::update_owned() {
    s32 i;
    u8 *p;
    if (this->parameters->max_grind < this->grind) {
        this->grind = 0;
    }
    if (this->parameters->flags & 8) {
        p = this->attributes;
        for (i = 0; i < 3; i++) {
            u8 a = p[0];
            s8 b = p[1];
            if (a <= 5 && b != 0) {
                p[0] = 0;
                p[1] = 0;
            }
            p += 2;
        }
    }
}

void TItemWeapon::on_model_loaded() { set_weapon_flags(4); }


extern const f32 weapon_photon_phase_step;
s16 weapon_node_material_index;
__declspec(section ".data") s16 weapon_node_ids[4];
TItemWeapon *weapon_render_callback_object;

void apply_weapon_node_material(NJS_OBJECT *) {
    const s32 node = get_model_node_counter();
    TItem::end_material_color();
    TItem::end_effect_render();
    weapon_render_callback_object->end_particle_tev();
    weapon_render_callback_object->end_shield_tev();
    weapon_render_callback_object->transform_model_node();
    if(node == weapon_node_material_index) {
        NJS_ARGB color = weapon_render_callback_object->get_weapon_color();
        TItem::begin_constant_material_color(&color);
    }
    if(node == weapon_node_ids[0] || node == weapon_node_ids[1] || node == weapon_node_ids[2]) {
        TItem::begin_effect_render();
        if(item_render_state.test_flags_any(4)) {
            NJS_ARGB color = weapon_render_callback_object->get_weapon_color();
            TItem::begin_constant_material_color(&color);
        }
    }
    increment_model_node_counter();
}

#pragma push
#pragma opt_common_subs off

void TItemWeapon::advance_weapon_photon_phase() {
    if (test_weapon_flags(0x02000000U) == 0U) {
        photon_phase = photon_phase + weapon_photon_phase_step;
    } else {
        photon_phase = photon_phase - weapon_photon_phase_step;
    }
    if (weapon_float_one <= photon_phase) {
        photon_phase = weapon_float_one;
        set_weapon_flags(0x02000000U);
    }
    if (photon_phase <= weapon_float_zero) {
        photon_phase = weapon_float_zero;
        clear_weapon_flags(0x02000000U);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
NJS_ARGB TItemWeapon::get_weapon_color() {
    NJS_ARGB first, second;
    WeaponColorDescriptor *descriptor;
    f32 override_alpha;
    if (photon_color_id != -1) {
        descriptor = (WeaponColorDescriptor *)get_photon_color_record(photon_color_id);
        if (descriptor->mode == 1) {
            copy_argb(&first, &descriptor->first);
            copy_argb(&second, &descriptor->second);
            first.a = photon_phase * (second.a - first.a) + first.a;
            first.r = photon_phase * (second.r - first.r) + first.r;
            first.g = photon_phase * (second.g - first.g) + first.g;
            first.b = photon_phase * (second.b - first.b) + first.b;
            override_alpha = get_owner_alpha();
            if (weapon_float_one != override_alpha) {
                first.a = override_alpha;
            }
            return first;
        } else {
            return descriptor->first;
        }
    } else {
        NJS_ARGB fallback;
        fallback.a = weapon_float_one;
        fallback.b = fallback.g = fallback.r = weapon_float_zero;
        return fallback;
    }
}
#pragma pop

void TItemWeapon::write_item_data(TItemData *data) {
    s32 off;
    u32 i;
    u8 t;
    s32 ok;
    for (i = 0, off = 0; i != 3; i++, off += 2) {
        ((WeaponAttribute *)(data->data1.data_u8 + 6 + off))->copy((WeaponAttribute *)&attributes[off]);
    }
    ok = 1;
    data->data1.data_u8[3] = grind;
    t = special_selector;
    if (t & 0x80) {
        ok = 0;
    }
    if (parameters->special == 0) {
        data->data1.data_u8[4] = t;
    } else {
        data->data1.data_u8[4] = 0;
    }
    if (ok == 0) {
        data->data1.data_u8[4] = data->data1.data_u8[4] | weapon_unidentified_flag;
    }
}

void TItemWeapon::remove_owner_bonuses() {
    s32 i;
    WeaponAttribute *attribute_entry;

    ((TObjPlayer *)(this->owner))->set_model_id(0);
    ((TObjPlayer *)(this->owner))->set_model_param(0);
    i = 0;
    do {
        attribute_entry = ((TObjPlayer *)(this->owner))->get_attribute_entry(i);
        attribute_entry->area = 0;
        i += 1;
        attribute_entry->percent = 0;
    } while (i != 3);
}


extern "C" {
void set_flag_8_unless_on_ground__11TItemWeaponFv();

void TItemWeapon::on_unequip() {
    if (owner->vfunc_66(get_attach_slot()) == 0) {
        owner->set_action_provider_variant(0);
    }
    on_unequipped();
    clear_technique_boosts();
    clear_weapon_flags(0x03000000);
}

void TItemWeapon::apply_owner_bonuses() {
    s32 i;
    apply_model_params();
    if (!(this->parameters->flags & 8)) {
        for (i = 0; i != 3; i++) {
            owner->set_attribute_entry(i, (WeaponAttribute *)&this->attributes[i * 2]);
        }
    }
}
void TItemWeapon::on_equip() {
    if (effect_flags.test_flags_any(1) != 0) {
        if (!(get_item_flags() & 0x20) && is_current_area_item_enabled() != 0) {
            owner->set_action_provider_variant(get_motion_type());
        }
        clear_weapon_flags(0x100);
        if (is_hidden() != 0 || owner->is_in_fixed_pose() != 0) {
            set_weapon_flags(8);
        } else {
            TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)set_flag_8_unless_on_ground__11TItemWeaponFv, 0x14);
            TItemEffEquip::create(tl_05, owner->get_entity_id(), 0x30, 0x9D, 0x9E);
            if (test_weapon_flags(0x200) != 0U) {
                TItemEffEquip::create(tl_05, owner->get_entity_id(), 0x23, 0x9D, 0x9E);
            }
            set_sound_pitch_request(play_sound_effect(0x4000B20A, &owner->position, 0, 0), 0x300, 0);
        }
    } else {
        owner->set_action_provider_variant(0);
        set_weapon_flags(0x100);
        set_weapon_flags(8);
    }
    on_equipped();
    clear_weapon_flags(0x03000000);
}


s32 TItemWeapon::get_joint_position(s32 joint, Vec *out) {
    Vec joint_origin;
    TObjPlayer *player;

    player = owner;
    if (player == NULL) {
        return 0;
    }
    if (joint == -1) {
        player->get_anim_node_position(0x30, out);
    } else if (joint == -2) {
        player->get_anim_node_position(0x23, out);
    } else if (item_model != NULL) {
        joint_origin.z = weapon_float_zero;
        joint_origin.y = weapon_float_zero;
        joint_origin.x = weapon_float_zero;
        push_matrix();
        ::copy_matrix(NULL, get_model_joint_matrix(owner, joint));
        premultiply_matrix(NULL, TCameraCtrl::get_view_matrix());
        transform_point_by_current_matrix(&joint_origin.x, out);
        pop_matrix();
    } else {
        player->get_anim_node_position(0x30, out);
    }
    return 1;
}

void TItemWeapon::get_gun_point(Vec *out) {
    get_joint_position(gun_point_joint, out);
}

}

__declspec(section ".sdata2") extern const f32 weapon_float_tenth = 0.1f;
__declspec(section ".sdata2") extern const f32 weapon_float_zero = 0.0f;
__declspec(section ".sdata2") extern const f32 weapon_float_one = 1.0f;
__declspec(section ".sdata2") extern const f32 weapon_photon_phase_step = 0.03f;
__declspec(section ".sdata2") extern const u8 weapon_unidentified_flag = 0x80;
