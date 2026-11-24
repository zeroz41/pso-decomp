#include "types.h"
#include <string.h>
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801211F0.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/unk/text_80120150.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/ItemCreateFunction.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/unk/text_8011B620.h"
#include "pso/item/TItemData.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80120FC4.h"
#include "pso/player/TObjPlayer_80121010.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/CapturedTargetList.h"


// ---- pso/unk/text_80120908

extern "C" {
void draw_weapon_at_joint(saddr arg0, s8 arg1);
}
void set_shadow_material_state(void);

extern s16 TObjPlayer__weapon_node_ids[];
extern s16 weapon_node_material_index;
extern u8 *weapon_render_callback_object;
extern s32 model_render_flags;

void TItemWeapon::draw_weapon_model() {
    s32 var_r30;
    WeaponParams *parameters;
    if ((void *) this->owner == NULL || (u32) *(u32 *)((s8 *)this + 0xF4) == 0U) {
        return;
    }
    {
        reset_model_node_counter();
        if (this->has_no_defer_render() != 0) {
            var_r30 = 1;
        } else {
            var_r30 = this->update_object_view_visibility(400.0f, 20.0f);
        }
        set_texlist((this->texlist));
        push_matrix_from((void *)((TObjMotion *)(this->owner))->get_joint_matrix((s8)get_attach_joint()));
        if ((var_r30 != 0) && (this->is_hidden() == 0)) {
            weapon_render_callback_object = (u8 *)this;
            weapon_node_material_index = color_node;
            parameters = this->parameters;
            TObjPlayer__weapon_node_ids[0] = parameters->effect_nodes[0];
            TObjPlayer__weapon_node_ids[1] = parameters->effect_nodes[1];
            TObjPlayer__weapon_node_ids[2] = parameters->effect_nodes[2];
            if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                this->sub_80121208((saddr)apply_weapon_node_material);
            } else {
                set_chunk_model_node_callback(apply_weapon_node_material);
            }
            TObjPlayer::save_model_render_state();
            model_render_flags &= 0xFFFFFFEF;
            TObjPlayer::set_model_fade_alpha((f32)this->get_owner_alpha());
            if (this->has_no_defer_render() != 0) {
                model_render_flags |= 0x8011;
                set_color_blend_mode(1, 4, 5, 0);
                set_shadow_material_state();
                if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                    if (this->test_weapon_flags(0x800000) != 0U) {
                        draw_chunk_object((void *)(*(uaddr *)((s8 *)this + 0xF4)));
                    } else {
                        this->draw_model_nodes(NULL);
                    }
                } else {
                    set_motion_packed_rotation();
                    draw_model_motion((void *)(*(uaddr *)((s8 *)this + 0xF4)), (void *)(*(uaddr *)((s8 *)this + 0x17C)), (f32)this->motion_frame);
                    clear_motion_packed_rotation();
                }
                model_render_flags &= 0xFFFF7FEE;
            } else if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                if (this->test_weapon_flags(0x40) != 0U) {
                    this->apply_sign_effect(this->owner->item_node_matrices);
                } else if (this->test_weapon_flags(0x800000) != 0U) {
                    draw_chunk_object((void *)(*(uaddr *)((s8 *)this + 0xF4)));
                } else {
                    this->draw_model_nodes(this->owner->item_node_matrices);
                }
            } else {
                set_motion_packed_rotation();
                draw_model_motion((void *)(*(uaddr *)((s8 *)this + 0xF4)), (void *)(*(uaddr *)((s8 *)this + 0x17C)), (f32)this->motion_frame);
                clear_motion_packed_rotation();
            }
            TItem::end_material_color();
            TItem::end_effect_render();
            this->end_particle_tev();
            this->end_shield_tev();
            TObjPlayer::warn_if_gauge_low();
            TObjPlayer::restore_model_render_state();
            if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                this->sub_80121208(NULL);
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

void draw_weapon_at_joint(saddr arg0, s8 joint) {
    s8 temp_r31;
    temp_r31 = (s32)((TItemEquipBase *)arg0)->get_attach_joint();
    ((TItemEquipBase *)arg0)->set_attach_joint(joint);
    ((TItemWeapon *)arg0)->draw_weapon_model();
    ((TItemEquipBase *)arg0)->set_attach_joint(temp_r31);
}
// ---- pso/unk/text_80120C5C
void TItemWeapon::release_model() { memset((char*)this + 0x18c, 0, 16); clear_weapon_flags((uaddr)((void*)12)); TItemEquipBase::release_model(); }


struct PlB_80120C5C { char pad[0x18]; };

struct Pl_80120C5C : PlB_80120C5C {
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
    virtual u8 m41();
};

struct T_80120C5C { s32 a; s32 b; s32 c; u16 d; u8 e; };


extern T_80120C5C lbl_8043E828[];
void TItemWeapon::request_equipped_model() {
    Pl_80120C5C *arg0 = (Pl_80120C5C *)this;
    u8 v = this->get_item_group();
    if (v >= 0xAA) {
        T_80120C5C t;
        t.a = lbl_8043E828[0].a;
        t.b = lbl_8043E828[0].b;
        t.c = lbl_8043E828[0].c;
        t.d = lbl_8043E828[0].d;
        t.e = lbl_8043E828[0].e;
        v = ((u8 *)&t)[arg0->m41()];
    }
    ((TItemEquipBase *)arg0)->request_model_load(v);
    ((TItemWeapon *)arg0)->create_weapon_trail_effects();
}


// ---- pso/item/TItemWeapon

TItemWeapon::~TItemWeapon() {}


void *lookup_item_pmt_record(u8 *item);
extern const f32 lbl_805DAC98;
extern const u8 lbl_805DACA4;

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
        special_selector = (u8) (special_selector | lbl_805DACA4);
    }
    memcpy(attributes, item + 6, 6);
    impact_callback = 0;
    hit_callback = 0;
    shot_callback = (WeaponShotCallback)create_gun_shot;
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
    motion_frame = lbl_805DAC98;
    if (get_item_group() == 0) {
        photon_color_id = -1;
    } else {
        item_render_state.reset();
        photon_phase = lbl_805DAC98;
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

// ---- pso/player/TObjPlayer_80120FC4

// weapon_factory_table's entry for weapons without a class of their own.
TItem *create_common_weapon(u8 *item) {
    return new TItemWeapon(tl_05, item);
}

// ---- pso/player/TObjPlayer_80121010

extern "C" {

TItem *create_weapon_for_item(u8 *item) {
    if (item != NULL) {
        ItemCreateFunction factory = get_weapon_factory_for_item(item);
        return factory(item);
    }
    return NULL;
}

// ---- pso/player/TObjPlayer_8012105C
s16 TObjPlayer__sub_801D2F4C(s16 *);

void TObjPlayer__sub_8012105C(void) {  }
void TObjPlayer__sub_80121060(void) {  }
u8 TItemWeapon::get_motion_type() { return motion_type; }
void TItemWeapon::set_weapon_flags(u32 mask) { weapon_flags |= mask; }
void TItemWeapon::clear_weapon_flags(u32 mask) { weapon_flags &= ~mask; }
void TItemWeapon::set_flag_8() { set_weapon_flags(8); }

void set_weapon_trail_joints(TItemWeapon *weapon, s32 trail, s32 start_joint, s32 end_joint) {
    weapon->trail_start_joints[trail] = start_joint;
    weapon->trail_end_joints[trail] = end_joint;
}

void TObjPlayer::set_model_param(s16 v) { *(s16 *)&this->unk_118 = v; }
void TObjPlayer::set_model_id(s16 v) { this->m_116 = v; }
s16 TObjPlayer::is_status_subsystem_ready() { return TObjPlayer__sub_801D2F4C((s16 *)((char*)this + 0x7cc)); }
CapturedTargetList *TObjPlayer::get_extended_state() { return (CapturedTargetList *)((TObjPlayer *)((char*)this + 0x7cc))->get_state_ptr(); }
f32 TObjPlayer::query_extended_state() { return attack_state.get_attack_damage_scale(); }
int TObjPlayer::test_flag30_bit0x100000() { return test_actor_flags((uaddr)((void*)1048576)); }
}
MtxP get_model_joint_matrix(TObjPlayer *player, int joint) { return player->item_node_matrices[joint]; }
void TObjPlayer::set_action_type(s16 v) { *(s16*)((char*)this + 0x0) = v; }

// ---- pso/player/TObjPlayer_80121178

void*TObjPlayer::get_state_ptr() { return (char*)this + 0x30; }

// ---- pso/unk/text_80121180

f32 PlayerAttackController::get_attack_damage_scale() { return attack_damage_scale_table[attack_kind]; }

f32 PlayerAttackController::get_attack_accuracy_scale() {
    return attack_type_accuracy_scales[attack_kind] * attack_combo_accuracy_multipliers[get_validated_attack_stage()];
}

// ---- pso/player/TObjPlayer_801211F0

void increment_model_node_counter(void) {
    int temp_r3 = model_node_counter;
    model_node_counter = temp_r3 + 1;
}

int TObjPlayer::get_player_list() {  return model_node_counter; }

void TItemWeapon::sub_80121208(s32 v) { *(s32*)((char*)this + 0xe0) = v; }

void reset_model_node_counter(void) { model_node_counter = 0; }

// ---- pso/player/TObjPlayer_8012121C

int TObjPlayer::is_flag_b0_4() { return this->motion_flags & 0x4; }
void TObjPlayer__sub_80121228(void* p, u32 v) { *(u32*)((char*)p + 0x28) |= v; }
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
