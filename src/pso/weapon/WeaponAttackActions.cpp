#include "pso/system/MatrixStack.h"
#include "types.h"
#include "pso/object/TActorLight.h"

struct NJS_OBJECT;
#include <string.h>
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804F1320.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/weapon/TUnk_804A69DC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TItemData.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/weapon/WeaponAttackActions.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/weapon/TUnk_804A4D70.h"
#include "pso/system/PadRumble.h"
#include "pso/item/TItemEquipBase.h"
#include <stddef.h>
#include "pso/map/FloorArea.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/unk/text_80120908.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/item/item_param.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/player/TObjPlayer_801211F0.h"
#include "pso/unk/text_80120150.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/effect/item/TItemEffEquip.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include <stdlib.h>


#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/CapturedTargetList.h"


// ---- pso/item/WeaponAttackActions

struct Node_8011EB84 { u8 b[0x2C]; };

struct Skel_8011EB84 { u8 pad[0x1C]; Node_8011EB84 n[1]; };

typedef struct A12_8011E3E8 { s32 a; s32 b; s32 c; } A12_8011E3E8;

typedef struct A16_8011E3E8 { s32 a; s32 b; s32 c; s32 d; } A16_8011E3E8;



struct WeaponArgb { f32 alpha, red, green, blue; };

extern "C" {
WeaponArgb get_weapon_color__11TItemWeaponFPv(TItemWeapon *weapon);
f32 * get_weapon_range_record(void *, s16);
s16 is_status_subsystem_ready__10TObjPlayerFv(s32);
s32 rotate_matrix_y(int, void *);
s32 subtract_vector(void *, void *);
extern s32 identity_matrix[];
extern const f32 lbl_805DAC94;
extern A12_8011E3E8 lbl_8043E838[];
extern A16_8011E3E8 lbl_8043E844[];
struct Stack_8011E56C {
    s32 sp8;
    f32 spC;
};

struct Pl_8011E950 {
    u8 pad0[0x174];
    u32 x174;
    u8 pad178[0x18C - 0x178];
    void *eff[4];
    s8 kind[4];
};


struct ShotVector { f32 x,y,z; };

struct Rec_8011F108 { u8 pad0[0xC]; f32 c; u8 pad1[0xC]; ShotVector pos; u8 pad2[4]; };

struct Part_8011EDFC { u8 pad0[0x1C]; Vec pos; u8 pad28[4]; };

struct Obj_8011EDFC { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0xA4 - 0x44]; Part_8011EDFC *parts; };

struct Hit_8011EDFC { u8 pad0[4]; void *pos; };

struct Self_8011EDFC;

typedef void (*Cb_8011EDFC)(Self_8011EDFC *, void *, Vec *, f32);

struct Owner_8011EDFC { u8 pad0[0x60]; void *rot; };

struct Self_8011EDFC {
    u8 pad0[0xF0];
    u8 *owner;
    u8 padF4[0x1E4 - 0xF4];
    f32 speed;
    u8 pad1E8[0x1F0 - 0x1E8];
    Cb_8011EDFC cb;
};

s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
u8 * csnVector(void *, void *, s32);
f32 horizontal_distance_squared(void *, void *);
TObjChara *resolve_hittable_target(s32, s32);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
void * __ct__17TItemEffectWeaponFll(void *, u32, u32);
u32 __cvt_fp2unsigned(f32);
s32 vec3_add_to(void *, void *);
f32 xyz_distance(void *, void *);

extern const f32 lbl_805DAC98;

void TItemWeapon::set_weapon_category_flags() {
    s32 r = this->get_attack_flags();
    u32 flags = 0x10000;
    if (r & 1) {
        flags = 0x20000;
    }
    set_weapon_flags(flags);
}

void TItemWeapon::drain_owner_hp_fraction(f32 farg0) {
    if (*(u32 *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1] != 0U) {
        TObjectV8047c128_subtract_hp((u8 *)(*(uaddr *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1]), (farg0 * (f32) ((TObjChara *)(*(uaddr *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1]))->get_hpmax()));
    }
}

s32 TItemWeapon::is_mode_two_and_ready() {
    if ((((TObjPlayer *)(*(saddr *)&owner))->is_status_subsystem_ready() == 2) &&
        (is_identified() == 1)) {
        return 1;
    }
    return 0;
}

void TItemWeapon::spawn_light_task() {
    A12_8011E3E8 a = lbl_8043E838[0];
    A16_8011E3E8 b = lbl_8043E844[0];
    new TActorLight(0.2f, (NJS_ARGB *)&b, (Vec *)&a, 1, owner, tl_07);
}

void TItemWeapon::restore_action_type() {
    u8 *arg0 = (u8 *)this;
    if (((TItemWeapon *)arg0)->test_weapon_flags(0x04000000) != 0U) {
        ((TObjPlayer *)(*(saddr *)&this->owner + 0x7CC))->set_action_type((s16)2);
        ((TItemWeapon *)arg0)->clear_weapon_flags(0x04000000);
    }
}

void TItemWeapon::remap_extra_attack_type() {
    if ((this->test_weapon_flags(0x20) != 0U) && (TObjPlayer__sub_801D2F4C((s16 *)(*(saddr *)((s8 *)this + 0xF0) + 0x7CC)) == 2)) {
        if (this->test_weapon_flags(0x100000) != 0U) {
            ((TObjPlayer *)(*(saddr *)((s8 *)this + 0xF0) + 0x7CC))->set_action_type((s16)0);
        } else {
            ((TObjPlayer *)(*(saddr *)((s8 *)this + 0xF0) + 0x7CC))->set_action_type((s16)1);
        }
        set_weapon_flags(0x04000000);
    }
}

u8 *TItemWeapon::trace_from_owner(u8 *point) {
    Stack_8011E56C stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(*(saddr *)((s8 *)((u8 *)this) + 0xF0) + 0x2FC));
    stack.spC = *(f32 *)((s8 *)point + 4);
    return csnVector(&stack.sp8, point, 0x8100);
}

void TItemWeapon::vfunc_60() {  }

void TItemWeapon::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {}

void TItemWeapon::on_unequipped() {  }

void TItemWeapon::on_equipped() {  }

void TItemWeapon::update_weapon() {  }

void TItemWeapon::reserved_53() {  }

void TItemWeapon::update_idle() {  }

void TItemWeapon::update_attack() {  }

void TItemWeapon::emit_marker_effects() {  }

void TItemWeapon::carry_over_stats(TItemData *data, TItem *item) { memcpy((char*)data + 0x6, (char*)item + 0x1a4, 6); }
}
u32 pack_weapon_trail_color(void *weapon);

void TItemWeapon::activate_effect(s32 effect) {
    technique_roll = effect;
}

void TItemWeapon::roll_technique() {
    previous_technique_roll = technique_roll;
    send_activate_effect((s32) ((f32) technique_roll_range * (3.0517578e-05f * (f32) rand())));
}

void TObjPlayer::set_flag_8_if_check_passes() {
    u8 *var_r31;
    if (this != NULL) {
        var_r31 = (u8 *)this;
        if (((TItem *)(this))->get_mode() != 0) {
            ((TItemWeapon *)var_r31)->set_flag_8();
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

void TObjPlayer::call_callback_1ec(saddr arg1, saddr arg2) {
    s32 (*temp_r12)(s32, void *, s32, s32);

    temp_r12 = *(s32 (**)(s32, void *, s32, s32))((s8 *)this + 0x1EC);
    if (temp_r12 != NULL) {
        temp_r12((saddr)tl_05, this, arg1, arg2);
    }
}

void TItemWeapon::apply_model_params() {
    s16 spA;
    s16 sp8;

    get_weapon_special_type_amount((this->special_selector) & 0x3F, &spA, &sp8);
    ((TObjPlayer *)(this->owner))->set_model_id(spA);
    ((TObjPlayer *)(this->owner))->set_model_param(sp8);
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
    if (((Pl_8011E950 *)this)->x174 != 0U) {
        for (i = 0; i != 4; i++) {
            if (((Pl_8011E950 *)this)->kind[i] != -1) {
                void *p = TItemHeapObject::operator new(0x2C);
                if (p != NULL) {
                    p = __ct__17TItemEffectWeaponFll(p, ((Pl_8011E950 *)this)->x174, flags);
                }
                ((Pl_8011E950 *)this)->eff[i] = p;
            }
            if (((Pl_8011E950 *)this)->eff[i] != NULL && ((TObjCollidable *)((Pl_8011E950 *)this))->test_actor_flags(0x2000) != 0) {
                TObjPlayer__sub_80121228(((Pl_8011E950 *)this)->eff[i], 1);
            }
        }
    }
}

u32 pack_weapon_trail_color(void *weapon) {
    WeaponArgb w = get_weapon_color__11TItemWeaponFPv((TItemWeapon *)weapon);
    return (__cvt_fp2unsigned(255.0f * w.alpha) << 24 | __cvt_fp2unsigned(255.0f * w.red) << 16 | __cvt_fp2unsigned(255.0f * w.green) << 8) | __cvt_fp2unsigned(255.0f * w.blue);
}

void TUnk_804F1320::spawn_pg_effect(const Vec *origin, saddr item, f32 radius) {
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
    if (TObjPlayer::is_locally_controlled(owner) != 0) {
        TItemEffPG::create(tl_05, &prm);
    } else {
        TItemEffPG::create(tl_05, &prm, item);
    }
    this->restore_action_type();
}

void TItemWeapon::fire_shot_at_target(void *origin, void *model, s32 angle) {
    Vec v;
    Desc_8011E5C4 atk;
    f32 *scale;
    CapturedTargetList *state;
    CapturedTarget *item;
    u8 *ph;
    u8 *hit;
    s32 off;
    if (is_active_in_game() != 0) {
        scale = ((f32 *(*)(void *, s32))get_weapon_range_record)(this, ((s32 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)(this->owner));
        TObjPlayer__sub_802E449C(&atk);
        fill_status_info(&atk);
        VecCopy(&atk.position, (const Vec *)origin);
        atk.rotation_y = *(s32 *)((s8 *)this->owner + 0x60) + angle;
        atk.range = *scale;
        atk.speed = shot_speed;
        atk.model = (NJS_OBJECT *)model;
        atk.texlist = this->texlist;
        init_weapon_effect_descriptor(&atk);
        remap_extra_attack_type();
        hit = trace_from_owner((u8 *)origin);
        if (hit != NULL) {
            VecCopy(&atk.position, (const Vec *)(*(void **)((s8 *)hit + 4)));
            atk.flags |= 0x800;
        } else if ((state = ((TObjPlayer *)(this->owner))->get_extended_state()) != 0 && state->get_captured_target_count() > 0) {
            if ((item = state->get_captured_target_entry(0)) != 0) {
                if ((ph = (u8 *)find_entity_by_id(item->get_uid())) != NULL && *(u8 **)((s8 *)ph + 0xA4) != NULL) {
                    VecCopy((Vec *)&v, (const Vec *)(&(*(Skel_8011EB84 **)((s8 *)ph + 0xA4))->n[item->get_captured_target_collider_index()]));
                    subtract_vector(&v, ((Vec *)origin));
                    push_matrix_from(((s32 *)&identity_matrix));
                    ((void (*)(s32, s32))rotate_matrix_y)(0, angle);
                    transform_point_by_current_matrix(&v.x, &atk.direction);
                    atk.flags |= 1;
                    pop_matrix();
                }
            }
        }
        if (atk.pad_24 == 2 && this->is_identified() == 0) {
            atk.pad_1C *= lbl_805DAC94;
        }
        TItemAttackCol::create((TObject *)tl_05, &atk);
        this->restore_action_type();
    }
}

void TItemWeapon::fill_status_info(S_802E451C *params) {
    ((TItemWeapon *)this)->remap_extra_attack_type();
    params->client_id = static_cast<s16>(owner->get_entity_id());
    params->room = owner->get_room();
    params->item_id = ((TItem *)this)->get_item_id();
    params->pad_1C = owner->attack_state.get_attack_accuracy_scale();
    params->pad_24 = (s32) owner->is_status_subsystem_ready();
    params->pad_20 = owner->query_extended_state();
    ((TItemWeapon *)this)->restore_action_type();
}

void TItemWeapon::launch_rare_weapon_special(void *origin, s32 enable, f32 scale) {
    CapturedTargetList *ext;
    Vec pos;
    f32 dist;
    s32 found;

    if (((TItemWeapon *)this)->is_active_in_game() == 0) {
        return;
    }
    ext = ((TObjPlayer *)(((Self_8011EDFC *)this)->owner))->get_extended_state();
    if (ext == NULL) {
        return;
    }
    if (origin == NULL) {
        origin = ((Self_8011EDFC *)this)->owner + 0x2FC;
    }
    found = 0;
    if (ext->get_captured_target_count() != 0) {
        CapturedTarget *e = ext->get_captured_target_entry(ext->get_captured_target_count() - 1);
        Obj_8011EDFC *t = ((Obj_8011EDFC *(*)(u16, s16))resolve_hittable_target)(e->get_uid(), e->get_captured_target_collider_index());
        if (t != NULL) {
            Part_8011EDFC *part = &t->parts[e->get_captured_target_collider_index()];
            VecCopy((Vec *)&pos, (const Vec *)&part->pos);
            found = 1;
        }
    }
    if (found == 0) {
        Vec v;
        f32 *rec;
        push_matrix_from(identity_matrix);
        rec = get_weapon_range_record(this, 2);
        v.x = v.y = lbl_805DAC98;
        v.z = rec[0];
        rotate_matrix_y(0, ((Owner_8011EDFC *)((Self_8011EDFC *)this)->owner)->rot);
        transform_point_by_current_matrix(&v.x, &pos);
        pop_matrix();
        vec3_add_to(&pos, origin);
    }
    {
        Hit_8011EDFC *hit = (Hit_8011EDFC *)csnVector(origin, &pos, 0x8100);
        if (hit != NULL) {
            dist = xyz_distance(origin, hit->pos);
        } else {
            dist = xyz_distance(origin, &pos);
        }
    }
    if (enable != 0) {
        for (s32 i = 0; i != ext->get_captured_target_count(); i++) {
            CapturedTarget *e = ext->get_captured_target_entry(i);
            Obj_8011EDFC *t = ((Obj_8011EDFC *(*)(u16, s16))resolve_hittable_target)(e->get_uid(), e->get_captured_target_collider_index());
            if (t != NULL) {
                Part_8011EDFC *part = &t->parts[e->get_captured_target_collider_index()];
                CapturedTarget *e2 = ext->get_captured_target_entry(i);
                DelayedWeaponHit sp;
                sp.reserved = 0;
                sp.kind = 1;
                sp.source = ((TObjBase *)(((Self_8011EDFC *)this)->owner))->get_entity_id();
                sp.target = ((TObjBase *)(t))->get_entity_id();
                sp.weapon = ((TItem *)this)->get_item_id();
                sp.collider = e2->get_captured_target_collider_index();
                sp.damage = scale * ((TObjPlayer *)(((Self_8011EDFC *)this)->owner))->query_extended_state();
                spawn_item_attacker(tl_05, (const Vec *)(((Self_8011EDFC *)this)->owner + 0x38), (s32)(xyz_distance(origin, &part->pos) / ((Self_8011EDFC *)this)->speed), &sp);
            }
        }
    }
    s32 n = (s32)(dist / ((Self_8011EDFC *)this)->speed);
    if (n < 0) {
        n = 0;
    }
    if (((Self_8011EDFC *)this)->cb != NULL && ((TItem *)((Self_8011EDFC *)this))->is_model_shown() == 1) {
        ((Self_8011EDFC *)this)->cb(((Self_8011EDFC *)this), origin, &pos, (f32)n);
    }
}

s32 TItemWeapon::launch_shot(u8 *origin, s32 i, s32 angle, s32 apply) {
    s32 var_r31;
    DelayedWeaponHit hit;
    f32 *weapon_range_record;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_r4;
    f32 var_f31;
    s16 temp_r29;
    s32 var_r23;
    CapturedTarget *temp_r22;
    CapturedTarget *temp_r22_3;
    CapturedTargetList *extended_state;
    s32 temp_r6;
    u8 *temp_r22_2;
    u8 *temp_r3_3;
    u8 *var_r29;
    var_r31 = 0;
    if (is_active_in_game() != 0) {
        extended_state = ((TObjPlayer *)(this->owner))->get_extended_state();
        if (extended_state != 0) {
            var_r23 = 0;
            var_r29 = NULL;
            Vec endpoint = *reinterpret_cast<const Vec *>(origin);
            if (i < extended_state->get_captured_target_count()) {
                temp_r22 = extended_state->get_captured_target_entry(i);
                var_r29 = (u8 *)(((TObjChara *(*)(u16, s16))resolve_hittable_target)(temp_r22->get_uid(),temp_r22->get_captured_target_collider_index()));
                if (var_r29 != NULL) {
                    temp_r22_2 = (u8 *)&(*(Rec_8011F108 **)((s8 *)var_r29 + 0xA4))[temp_r22->get_captured_target_collider_index()];
                    VecCopy((Vec *)(&endpoint.x), (const Vec *)((void *) &((Rec_8011F108 *)temp_r22_2)->pos));
                    subtract_vector(&endpoint.x, origin);
                    temp_f3 = normalize_vector((Vec *)&endpoint.x) - *(f32 *)((s8 *)temp_r22_2 + 0xC);
                    endpoint.x *= temp_f3;
                    endpoint.y *= temp_f3;
                    endpoint.z *= temp_f3;
                    vec3_add_to(&endpoint.x, origin);
                    var_r23 = 1;
                }
            }
            if (var_r23 == 0) {
                ShotVector fallback;
                push_matrix_from(identity_matrix);
                weapon_range_record = (f32 *)(get_weapon_range_record(this, this->owner->is_status_subsystem_ready()));
                fallback.y = lbl_805DAC98;
                fallback.x = lbl_805DAC98;
                fallback.z = *(f32 *)((s8 *)weapon_range_record + 0);
                rotate_matrix_y(0, (void *) (*(saddr *)((s8 *)this->owner + 0x60) + angle));
                transform_point_by_current_matrix(&fallback.x, &endpoint);
                pop_matrix();
                vec3_add_to(&endpoint.x, origin);
            }
            ShotVector rayOrigin = *(ShotVector *)(((u8 *)this->owner) + 0x2FC);
            rayOrigin.y = *(f32 *)((s8 *)origin + 4);
            temp_r3_3 = (u8 *)(csnVector(&rayOrigin.x, &endpoint.x, 0x8100));
            if (temp_r3_3 == NULL) {
                if (var_r29 != NULL) {
                    temp_r22_3 = extended_state->get_captured_target_entry(i);
                    temp_r22_2 = (u8 *)&(*(Rec_8011F108 **)((s8 *)var_r29 + 0xA4))[temp_r22_3->get_captured_target_collider_index()];
                    var_f31 = xyz_distance(origin, (void *) &((Rec_8011F108 *)temp_r22_2)->pos) / shot_speed;
                    if (apply != 0) {
                        remap_extra_attack_type();
                        hit.reserved = 0;
                        hit.kind = (s32) this->owner->is_status_subsystem_ready();
                        hit.source = ((TObjBase *)this->owner)->get_entity_id();
                        hit.target = ((TObjBase *)(var_r29))->get_entity_id();
                        hit.weapon = this->get_item_id();
                        hit.collider = temp_r22_3->get_captured_target_collider_index();
                        hit.damage = ((TObjPlayer *)((void *)this->owner))->query_extended_state();
                        spawn_item_attacker(tl_05, (const Vec *)origin, ((s32) var_f31), &hit);
                        var_r31 = 1;
                        this->restore_action_type();
                    }
                } else {
                    var_f31 = xyz_distance(origin, &endpoint.x) / shot_speed;
                }
            } else {
                VecCopy((Vec *)(&endpoint.x), (const Vec *)(*(u8 **)((s8 *)temp_r3_3 + 4)));
                var_f31 = xyz_distance(origin, &endpoint.x) / shot_speed;
                if ((*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3_3 + 4)) + 0x18) & 0x100) && (impact_callback != NULL)) {
                    spawn_land_hit_effect(tl_05, this, (Vec *)origin, (Vec *)&endpoint.x, (s32)var_f31);
                }
            }
            this->spawn_light_task();
            if ((shot_callback != NULL) && (is_model_shown() == 1)) {
                shot_callback(this, origin, &endpoint.x, var_f31);
            }
        }
    }
    return var_r31;
}

void TUnk_804A69DC::for_each_target_in_range(f32 range) {
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

// ---- pso/player/TObjPlayer_8011F578

void TUnk_804A4D70::apply_scale_if_active(f32 damage_scale) {

    if (this->is_active_in_game() != 0) {
        this->remap_extra_attack_type();
        owner->deliver_attack_hits(damage_scale);
        this->restore_action_type();
    }
}

extern const f32 lbl_805DAC9C;

void TItemWeapon::update_active_game_effect() {

    if (is_active_in_game() != 0) {
        remap_extra_attack_type();
        owner->deliver_attack_hits(lbl_805DAC9C);
        restore_action_type();
    }
}

// ---- pso/unk/text_8011F63C
s32 TItemWeapon::get_attack_stage() {
    uaddr temp_r3;
    temp_r3 = *(u32 *)&this->owner;
    if (temp_r3 != 0U) {
        if (((TObjPlayer *)temp_r3)->test_action_mask(0x20) != 0) {
            return 0;
        }
        if (this->owner->test_action_mask(0x40) != 0) {
            return 1;
        }
        if (this->owner->test_action_mask(0x80) != 0) {
            return 2;
        }
        goto block_7;
    }
block_7:
    return -1;
}


// ---- pso/player/TObjPlayer_8011F6C4

s32 TItemWeapon::is_active_in_game() {
    u8 active = 0;
    if (owner != NULL && get_mode() == ITEM_MODE_EQUIPPED) {
        active = 1;
    }
    return active;
}

// ---- pso/unk/text_8011F710

struct Stack_8011F7CC {
    s8 sp8;
    s8 sp9;
    u8 pad_A[0x2];
    u8 * spC;
    u8 pad_10[0x4];
    u8 * sp14;
    s32 sp18;
};

struct Item_8011F760 { u8 pad[0x10]; s32 count; };

struct Stats_8011F710 { u8 pad[0x16]; u8 max; };

struct Obj_8011F710 { u8 pad[0x1D1]; u8 cur; u8 pad2[0x1DC - 0x1D2]; Stats_8011F710 *stats; };

extern "C" {
s32 play_weapon_hit_sound(void *);
void apply_camera_shake__10TObjPlayerFiii(s32 player, saddr target, s32 damage);
void play_weapon_owner_sounds(void*);

s32 add_weapon_grind(Obj_8011F710 *weapon, s32 amount);

s32 add_weapon_grind(Obj_8011F710 *weapon, s32 amount) {
    if ((s32)(weapon->stats->max - (u8)amount) < weapon->cur) {
        weapon->cur = weapon->stats->max;
    } else {
        weapon->cur += amount;
    }
    ((TItemEquipBase *)weapon)->refresh_owner_stats();
    return 1;
}

u32 TItemWeapon::get_attack_flags() {
    u32 flags = 0;
    Item_8011F760 *it;
    if (this->get_icon_index() == 3) {
        flags |= 2;
    } else {
        flags |= 1;
    }
    it = (Item_8011F760 *)get_weapon_range_record(this, 0);
    if (it != 0 && it->count > 1) {
        flags |= 4;
    }
    return flags;
}

void TItemWeapon::deliver_hit(TObjPlayer *attacker, TObjChara *target, s32 attack_kind, f32 scale, s32 body) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8011F7CC, sp8) == 0x0);
    LAYOUT_ASSERT(sp9_offset, offsetof(Stack_8011F7CC, sp9) == 0x1);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8011F7CC, spC) == 0x4);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_8011F7CC, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_8011F7CC, sp18) == 0x10);
    Stack_8011F7CC stack;
    f32 accuracy;
    f32 damage_dealt;
    s32 damage;
    TObjPlayer *player;
    if (get_mode() == 2) {
        player = owner;
        if ((player != NULL) && (target != NULL)) {
            accuracy = player->attack_state.get_attack_accuracy_scale();
            if ((attack_kind == 2) && (is_identified() == 0)) {
                accuracy *= lbl_805DAC94;
            }
            if (target->calc_distance_accuracy_penalty(owner, &target->bodies[body], NULL, accuracy) != 0) {
                damage_dealt = lbl_805DAC98;
                switch (attack_kind) {
                case 0:
                    damage_dealt = target->receive_physical_attack(owner, scale);
                    break;
                case 1:
                    damage_dealt = target->receive_physical_attack(owner, scale);
                    target->apply_knockback_from_attacker((u8 *)owner, lbl_805DAC94 * damage_dealt);
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
                apply_camera_shake__10TObjPlayerFiii((saddr)owner, (saddr)target, damage);
                ((TObjPlayer *)(&stack.sp8))->reset_status_block();
                stack.sp8 = get_item_group();
                stack.sp9 = get_item_index();
                stack.spC = (u8 *)owner;
                stack.sp14 = (u8 *)target;
                stack.sp18 = body;
                play_weapon_hit_sound(&stack.sp8);
            }
        }
    }
}
}
void TItemWeapon::perform_action() {
    TItemWeapon* self=this;
    WeaponMarkerPacket packet;
    Vec gun_point;
    Vec fallback_point;
    if (((TItemWeapon *)self)->is_active_in_game() && !((TItem *)self)->is_hidden() && is_current_area_item_enabled()) {
        self->rotation_y=self->owner->rotation_y;
        self->stage=((TItemWeapon *)self)->get_attack_stage();
        ((TObjPlayer *)(&packet))->reset_status_block();
        packet.kind=((TItem *)self)->get_item_group();
        packet.variant=((TItem *)self)->get_item_index();
        packet.player=self->owner;
        play_weapon_owner_sounds(&packet);
        if(((TItemWeapon *)self)->test_weapon_flags(0x40000)) {
            start_pad_rumble_client(0x80, 5, (s16)self->owner->get_entity_id());
        } else if(((TItemWeapon *)self)->test_weapon_flags(0x80000) && ((TItemWeapon *)self)->is_mode_two_and_ready()) {
            start_pad_rumble_client(0x80, 5, (s16)self->owner->get_entity_id());
        }
        self->emit_marker_effects();
        ((TItemWeapon *)self)->set_weapon_flags(0x1000000);
        if(!((TItemWeapon *)self)->test_weapon_flags(2)) {
            if(((TItemWeapon *)self)->test_weapon_flags(0x8000)) {
                ((TItemWeapon *)self)->get_gun_point(&gun_point);
                ((TItemWeapon *)self)->fire_shot_at_target(&gun_point, self->second_model, 0);
                return;
            }
            if(((TItemWeapon *)self)->test_weapon_flags(0x20000)) {
                ((TItemWeapon *)self)->update_active_game_effect();
                return;
            }
            ((TItemWeapon *)self)->get_gun_point(&fallback_point);
            self->launch_shot((u8 *)&fallback_point,0,0,1);
        }
    }
}

// ---- pso/player/TObjPlayer_8011FBCC

void TItemWeapon::sample_dual_muzzles(Vec *primary, Vec *secondary) {
    draw_weapon_model();
    get_gun_point(primary);
    draw_weapon_at_joint((saddr)this, 0x23);
    get_gun_point(secondary);
}

// ---- pso/unk/text_8011FC24

void TItemWeapon::update_trails() {
    u8 *arg0 = (u8 *)this;
    if (((TItemWeapon *)arg0)->test_weapon_flags(0x400U) != 0U) {
        draw_weapon_at_joint((saddr)arg0, 0x30);
        ((TItemWeapon *)arg0)->update_trail_slot(0);
        draw_weapon_at_joint((saddr)arg0, 0x23);
        ((TItemWeapon *)arg0)->update_trail_slot(1);
        return;
    }
    if (((TItemWeapon *)arg0)->test_weapon_flags(1U) == 0U) {
        ((TItemWeapon *)arg0)->draw_weapon_model();
        ((TItemWeapon *)arg0)->update_trail_slot(0);
        ((TItemWeapon *)arg0)->update_trail_slot(1);
    }
}

void TItemWeapon::render_equipped_deferred() {
    u8 *arg0 = (u8 *)this;
    if (((uaddr) this->owner != 0U) && (((TItemWeapon *)arg0)->test_weapon_flags(0xCU) == 0xCU) && (((TItemWeapon *)arg0)->test_weapon_flags(0x80U) == 0U)) {
        this->reserved_53();
        update_trails();
    }
}
void TItemWeapon::render_equipped_shadow() {
    u8 *arg0 = (u8 *)this;
    if (((uaddr) this->owner != 0U) && (((TItemWeapon *)arg0)->test_weapon_flags(0xCU) == 0xCU) && (((TItemWeapon *)arg0)->test_weapon_flags(0x80U) == 0U) && (((TItemWeapon *)arg0)->test_weapon_flags(0x1000U) == 0U)) {
        this->reserved_53();
        if (((TItemWeapon *)arg0)->test_weapon_flags(0x400U) != 0U) {
            draw_weapon_at_joint((saddr)arg0, 0x30);
            draw_weapon_at_joint((saddr)arg0, 0x23);
            return;
        }
        if (((TItemWeapon *)arg0)->test_weapon_flags(1U) == 0U) {
            ((TItemWeapon *)arg0)->draw_weapon_model();
        }
    }
}
void TItemWeapon::render_equipped() {
    s32 count;
    if (((uaddr) this->owner != 0U) && (test_weapon_flags(0xCU) == 0xCU) && (test_weapon_flags(0x80U) == 0U)) {
        if (test_weapon_flags(0x800U) != 0U) {
            TObjPlayer::push_id_to_list(get_item_id());
            return;
        }
        this->reserved_53();
        this->update_trails();
        count = 0;
        do {
            void *trail = this->trails[count];
            if (trail) {
                ((TItemEffectWeapon *)trail)->render_trail();
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
        if(self->test_weapon_flags(0x4000)!=0) ((TItem *)self)->request_particle_indirect_effect();
        ((TItemEquipBase *)self)->bind_loaded_resources();
        stage=self->get_attack_stage();
        if(stage!=self->stage) {
            self->clear_weapon_flags(0x1000000);
            self->stage=stage;
        }
        if(stage>=0) ((TItemWeapon *)self)->set_weapon_flags(0x10);
        else clear_weapon_flags(0x10);
        if(stage>=0 || ((TObjPlayer *)self->owner)->test_flag30_bit0x100000()) self->update_attack();
        else self->update_idle();
        if(self->model_motion) {
            self->motion_frame+=lbl_805DAC9C;
            frames=self->model_motion->nbFrame;
            if((f32)frames<=self->motion_frame) self->motion_frame-=(f32)frames;
        }
        register_technique_boosts(technique_boosts);
        self->update_weapon();
        if(!((TObjChara *)self->owner)->is_in_fixed_pose()) self->advance_weapon_photon_phase();
        if(((TItem *)self)->is_hidden()) {
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

struct Pair_801200C0 { u8 a; u8 b; };

struct Data_801200C0 { u8 pad[0x16]; u8 max; u8 pad17[0x27 - 0x17]; u8 flags; };

struct Self_801200C0 { u8 pad[0x1a4]; Pair_801200C0 pairs[3]; u8 pad1aa[0x1d1 - 0x1aa]; u8 cur; u8 pad1d2[0x1dc - 0x1d2]; Data_801200C0 *data; };

void TItemWeapon::update_owned() {
    Self_801200C0 *self = (Self_801200C0 *)this;
    s32 i;
    Pair_801200C0 *p;
    if (self->data->max < this->grind) {
        this->grind = 0;
    }
    if (self->data->flags & 8) {
        p = self->pairs;
        for (i = 0; i < 3; i++) {
            u8 a = p->a;
            s8 b = p->b;
            if (a <= 5 && b != 0) {
                p->a = 0;
                p->b = 0;
            }
            p++;
        }
    }
}

void TItemWeapon::on_model_loaded() { set_weapon_flags(4); }

// ---- pso/unk/text_80120150

struct WeaponColorDescriptor_80120304 { s32 mode; WeaponArgb first, second; };

extern const f32 lbl_805DACA0;
s16 weapon_node_material_index;
__declspec(section ".data") s16 TObjPlayer__weapon_node_ids[4];
u8* weapon_render_callback_object;
extern "C" {
extern const u8 lbl_805DACA4;
}

void apply_weapon_node_material(NJS_OBJECT *) {
    const s32 node = TObjPlayer::get_player_list();
    TItem::end_material_color();
    TItem::end_effect_render();
    ((TItem *)weapon_render_callback_object)->end_particle_tev();
    ((TItem *)weapon_render_callback_object)->end_shield_tev();
    ((TItemWeapon *)weapon_render_callback_object)->vfunc_60();
    if(node == weapon_node_material_index) {
        WeaponArgb color = get_weapon_color__11TItemWeaponFPv((TItemWeapon *)weapon_render_callback_object);
        TItem::begin_constant_material_color((const NJS_ARGB *)&color);
    }
    if(node == TObjPlayer__weapon_node_ids[0] || node == TObjPlayer__weapon_node_ids[1] || node == TObjPlayer__weapon_node_ids[2]) {
        TItem::begin_effect_render();
        if(test_flags_any((s32 *)&item_render_state, 4)) {
            WeaponArgb color = get_weapon_color__11TItemWeaponFPv((TItemWeapon *)weapon_render_callback_object);
            TItem::begin_constant_material_color((const NJS_ARGB *)&color);
        }
    }
    increment_model_node_counter();
}

#pragma push
#pragma opt_common_subs off

void TItemWeapon::advance_weapon_photon_phase() {
    if (test_weapon_flags(0x02000000U) == 0U) {
        photon_phase = photon_phase + lbl_805DACA0;
    } else {
        photon_phase = photon_phase - lbl_805DACA0;
    }
    if (lbl_805DAC9C <= photon_phase) {
        photon_phase = lbl_805DAC9C;
        set_weapon_flags(0x02000000U);
    }
    if (photon_phase <= lbl_805DAC98) {
        photon_phase = lbl_805DAC98;
        clear_weapon_flags(0x02000000U);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
WeaponArgb get_weapon_color__11TItemWeaponFPv(TItemWeapon *weapon) {
    WeaponArgb first, second;
    WeaponColorDescriptor_80120304 *descriptor;
    f32 override_alpha;
    if (weapon->photon_color_id != -1) {
        descriptor = (WeaponColorDescriptor_80120304 *)get_photon_color_record(weapon->photon_color_id);
        if (descriptor->mode == 1) {
            copy_argb((NJS_ARGB *)&first, (NJS_ARGB *)&descriptor->first);
            copy_argb((NJS_ARGB *)&second, (NJS_ARGB *)&descriptor->second);
            first.alpha = weapon->photon_phase * (second.alpha - first.alpha) + first.alpha;
            first.red = weapon->photon_phase * (second.red - first.red) + first.red;
            first.green = weapon->photon_phase * (second.green - first.green) + first.green;
            first.blue = weapon->photon_phase * (second.blue - first.blue) + first.blue;
            override_alpha = weapon->get_owner_alpha();
            if (lbl_805DAC9C != override_alpha) {
                first.alpha = override_alpha;
            }
            return first;
        } else {
            return descriptor->first;
        }
    } else {
        WeaponArgb fallback;
        fallback.alpha = lbl_805DAC9C;
        fallback.blue = fallback.green = fallback.red = lbl_805DAC98;
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
        ((TObjPlayer *)(data->data1.data_u8 + 6 + off))->copy_entry_bytes(&attributes[off]);
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
        data->data1.data_u8[4] = data->data1.data_u8[4] | lbl_805DACA4;
    }
}

// ---- pso/player/TObjPlayer_80120500

void TItemWeapon::remove_owner_bonuses() {
    s32 i;
    void *attribute_entry;

    ((TObjPlayer *)(this->owner))->set_model_id(0);
    ((TObjPlayer *)(this->owner))->set_model_param(0);
    i = 0;
    do {
        attribute_entry = ((TObjPlayer *)(this->owner))->get_attribute_entry(i);
        *(s8 *)((s8 *)attribute_entry + 0) = 0;
        i += 1;
        *(s8 *)((s8 *)attribute_entry + 1) = 0;
    } while (i != 3);
}

// ---- pso/unk/text_80120568
struct Pair_801205F4 { u8 a; s8 b; };

struct Data_801205F4 { u8 pad[0x27]; u8 flags; };

struct Self_801205F4 { u8 pad[0xf0]; void *f0; u8 padf4[0x1a4 - 0xf4]; Pair_801205F4 pairs[3]; u8 pad1aa[0x1dc - 0x1aa]; Data_801205F4 *data; };

struct Ctl_80120568B { char pad[0x18]; };

struct Ctl_80120568 : Ctl_80120568B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual u32 m64(s32);
};


extern "C" {
void set_flag_8_if_check_passes__10TObjPlayerFv();

void TItemWeapon::on_unequip() {
    if (((Ctl_80120568 *)owner)->m64(get_attach_slot()) == 0) {
        owner->set_action_provider_variant(0);
    }
    on_unequipped();
    clear_technique_boosts();
    clear_weapon_flags(0x03000000);
}

void TItemWeapon::apply_owner_bonuses() {
    Self_801205F4 *self = (Self_801205F4 *)this;
    s32 i;
    ((TItemWeapon *)self)->apply_model_params();
    if (!(self->data->flags & 8)) {
        for (i = 0; i != 3; i++) {
            ((TObjPlayer *)(self->f0))->set_attribute_entry(i, &self->pairs[i]);
        }
    }
}
void TItemWeapon::on_equip() {
    if (test_flags_any((s32 *)&effect_flags, 1) != 0) {
        if (!(get_item_flags() & 0x20) && is_current_area_item_enabled() != 0) {
            owner->set_action_provider_variant(get_motion_type());
        }
        clear_weapon_flags(0x100);
        if (is_hidden() != 0 || owner->is_in_fixed_pose() != 0) {
            set_weapon_flags(8);
        } else {
            TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)set_flag_8_if_check_passes__10TObjPlayerFv, 0x14);
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

// ---- pso/player/TObjPlayer_801207E8
typedef struct { f32 sp8; f32 spC; f32 sp10; } FloatTriplet;


s32 TItemWeapon::get_joint_position(s32 joint, void *out) {
    FloatTriplet floats;
    TObjPlayer *player;

    player = owner;
    if (player == NULL) {
        return 0;
    }
    if (joint == -1) {
        player->get_anim_node_position(0x30, (Vec *)out);
    } else if (joint == -2) {
        player->get_anim_node_position(0x23, (Vec *)out);
    } else if (item_model != NULL) {
        floats.sp10 = lbl_805DAC98;
        floats.spC = lbl_805DAC98;
        floats.sp8 = lbl_805DAC98;
        push_matrix();
        ::copy_matrix(NULL, get_model_joint_matrix(owner, joint));
        premultiply_matrix(NULL, TCameraCtrl::get_view_matrix());
        transform_point_by_current_matrix(&floats.sp8, static_cast<Vec *>(out));
        pop_matrix();
    } else {
        player->get_anim_node_position(0x30, (Vec *)out);
    }
    return 1;
}

void TItemWeapon::get_gun_point(Vec *out) {
    get_joint_position(gun_point_joint, out);
}

}

__declspec(section ".sdata2") extern const f32 lbl_805DAC94 = 0.1f;
__declspec(section ".sdata2") extern const f32 lbl_805DAC98 = 0.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DAC9C = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DACA0 = 0.03f;
__declspec(section ".sdata2") extern const u8 lbl_805DACA4 = 0x80;
