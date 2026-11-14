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
#include "pso/unk/text_80121180.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/item/TItemEquipBase.h"

// ---- pso/unk/text_80120908

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 get_attach_joint__14TItemEquipBaseFv(void *);
void draw_weapon_at_joint(s32 arg0, s8 arg1);
}
void set_shadow_material_state(void);
extern "C" {
s32 set_model_fade_alpha__10TObjPlayerFf();
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern s16 TObjPlayer__weapon_node_ids[];
extern s16 weapon_node_material_index;
extern u8 *weapon_render_callback_object;
extern s32 model_render_flags;

s32 TItemWeapon::draw_weapon_model() {
    s32 var_r30;
    u8 *temp_r4;
    if ((void *) this->owner == NULL || (u32) *(u32 *)((s8 *)this + 0xF4) == 0U) {
        return;
    }
    {
        reset_model_node_counter();
        if (((TItem *)this)->has_no_defer_render() != 0) {
            var_r30 = 1;
        } else {
            var_r30 = ((VObj_18_26a62c *)(this))->m8(400.0f, 20.0f);
        }
        set_texlist((int) (*(s32 *)((s8 *)this + 0x24)));
        push_matrix_from((void *)((TObjMotion *)(this->owner))->get_item_ptr((s32)((void *) ((s8)get_attach_joint()))));
        if ((var_r30 != 0) && (((TItem *)this)->is_hidden() == 0)) {
            weapon_render_callback_object = (u8 *)this;
            weapon_node_material_index = *(s16 *)((s8 *)this + 0x1CC);
            temp_r4 = (u8 *)this->parameters;
            TObjPlayer__weapon_node_ids[0] = (s16) *(u8 *)((s8 *)temp_r4 + 0x21);
            TObjPlayer__weapon_node_ids[1] = (s16) *(u8 *)((s8 *)temp_r4 + 0x22);
            TObjPlayer__weapon_node_ids[2] = (s16) *(u8 *)((s8 *)temp_r4 + 0x23);
            if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                this->sub_80121208((s32)apply_weapon_node_material);
            } else {
                set_chunk_model_node_callback((s32)apply_weapon_node_material);
            }
            TObjPlayer__sub_80364198();
            model_render_flags &= 0xFFFFFFEF;
            ((TItem *)this)->get_owner_alpha();
            set_model_fade_alpha__10TObjPlayerFf();
            if (((TItem *)this)->has_no_defer_render() != 0) {
                model_render_flags |= 0x8011;
                set_color_blend_mode(1, 4, 5, 0);
                set_shadow_material_state();
                if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                    if (this->test_weapon_flags(0x800000) != 0U) {
                        draw_chunk_object((void *)(*(u32 *)((s8 *)this + 0xF4)));
                    } else {
                        ((TItem *)this)->draw_model_nodes(NULL);
                    }
                } else {
                    set_motion_packed_rotation();
                    draw_model_motion((void *)(*(u32 *)((s8 *)this + 0xF4)), (void *)(*(u32 *)((s8 *)this + 0x17C)), (f32)this->motion_frame);
                    clear_motion_packed_rotation();
                }
                model_render_flags &= 0xFFFF7FEE;
            } else if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                if (this->test_weapon_flags(0x40) != 0U) {
                    ((TItem *)this)->apply_sign_effect((u8 *)(*(s32 *)((s8 *)this->owner + 0xDB4)));
                } else if (this->test_weapon_flags(0x800000) != 0U) {
                    draw_chunk_object((void *)(*(u32 *)((s8 *)this + 0xF4)));
                } else {
                    ((TItem *)this)->draw_model_nodes((u8 *)(*(s32 *)((s8 *)this->owner + 0xDB4)));
                }
            } else {
                set_motion_packed_rotation();
                draw_model_motion((void *)(*(u32 *)((s8 *)this + 0xF4)), (void *)(*(u32 *)((s8 *)this + 0x17C)), (f32)this->motion_frame);
                clear_motion_packed_rotation();
            }
            TItem::end_material_color();
            TItem::end_effect_render();
            ((TItem *)this)->end_particle_tev();
            ((TItem *)this)->end_shield_tev();
            TObjPlayer::warn_if_gauge_low();
            TObjPlayer__sub_8036414C();
            if ((u32) *(u32 *)((s8 *)this + 0x17C) == 0U) {
                this->sub_80121208(NULL);
            } else {
                set_chunk_model_node_callback(NULL);
            }
            item_render_state.reset();
        } else {
            ((TItem *)this)->visit_model_nodes((u8 *)(*(s32 *)((s8 *)this->owner + 0xDB4)));
        }
        pop_matrix();
        reset_model_node_counter();
    }
}

void draw_weapon_at_joint(s32 arg0, s8 arg1) {
    s8 temp_r31;
    temp_r31 = get_attach_joint__14TItemEquipBaseFv((void *)arg0);
    ((TItemEquipBase *)arg0)->set_attach_joint(arg1);
    ((TItemWeapon *)arg0)->draw_weapon_model();
    ((TItemEquipBase *)arg0)->set_attach_joint(temp_r31);
}
}

// ---- pso/unk/text_80120C5C

extern "C" {

void TItemWeapon::release_model() { memset((char*)this + 0x18c, 0, 16); clear_weapon_flags((u32)((void*)12)); TItemEquipBase::release_model(); }

}

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

extern "C" {
u8 get_item_group__5TItemFv();
extern T_80120C5C lbl_8043E828[];
void TItemWeapon::request_equipped_model() {
    Pl_80120C5C *arg0 = (Pl_80120C5C *)this;
    u8 v = get_item_group__5TItemFv();
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

}

// ---- pso/item/TItemWeapon

TItemWeapon::~TItemWeapon() {}

extern "C" {
void *lookup_item_pmt_record(u8 *item);
extern const f32 lbl_805DAC98;
extern u8 lbl_805DACA4;
}

TItemWeapon::TItemWeapon(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    s32 identified;
    u8 special;
    set_attach_slot(6);
    parameters = (WeaponParams *)lookup_item_pmt_record(item);
    technique_boosts = (const TechniqueBoostParam *)TObjPlayer::get_shield_pmt_entry(*(u8 *)((s8 *)parameters + 0x26));
    photon_color_id = (s16) (s8) *(u8 *)((s8 *)parameters + 0x17);
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
    *(s16 *)((s8 *)this + 0x1CE) = (s16) *(u8 *)((s8 *)parameters + 0x1B);
    set_weapon_trail_joints((s32)this, 0, parameters->trail_joints[0], parameters->trail_joints[1]);
    set_weapon_trail_joints((s32)this, 1, parameters->trail_joints[2], parameters->trail_joints[3]);
    set_weapon_trail_joints((s32)this, 2, -1, -1);
    set_weapon_trail_joints((s32)this, 3, -1, -1);
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
            *(s16 *)((s8 *)this + 0x1CC) = (s16) *(u8 *)((s8 *)parameters + 0x20);
        } else {
            *(s16 *)((s8 *)this + 0x1CC) = -1;
        }
    } else {
        motion_type = 1;
        *(s16 *)((s8 *)this + 0x1CC) = -1;
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
    if (*(u8 *)((s8 *)parameters + 0x27) & 1) {
        effect_flags.set(0x20);
    }
    if (*(u8 *)((s8 *)parameters + 0x27) & 2) {
        ((TItemWeapon *)this)->set_weapon_flags(0x40000);
    }
    if (*(u8 *)((s8 *)parameters + 0x27) & 4) {
        ((TItemWeapon *)this)->set_weapon_flags(0x80000);
    }
}

// ---- pso/player/TObjPlayer_80120FC4

// weapon_factory_table's entry for weapons without a class of their own.
TItemWeapon *create_common_weapon(u8 *item) {
    return new TItemWeapon(tl_05, item);
}

// ---- pso/player/TObjPlayer_80121010

extern "C" {

s32 (*get_weapon_factory_for_item())(s32);

s32 create_weapon_for_item(s32 arg0) {
    if (arg0 != 0) {
        s32 (*fp)(s32) = get_weapon_factory_for_item();
        return fp(arg0);
    }
    return 0;
}

}

// ---- pso/player/TObjPlayer_8012105C

extern "C" {


s16 TObjPlayer__sub_801D2F4C(s16 *);

void TObjPlayer__sub_8012105C(void) {  }
void TObjPlayer__sub_80121060(void) {  }
u8 TItemWeapon::get_motion_type() { return motion_type; }
void TItemWeapon::set_weapon_flags(u32 mask) { weapon_flags |= mask; }
void TItemWeapon::clear_weapon_flags(u32 mask) { weapon_flags &= ~mask; }
void TItemWeapon::set_flag_8() { set_weapon_flags(8); }

void set_weapon_trail_joints(s32 weapon, s32 trail, s32 start_joint, s32 end_joint) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(weapon + trail);
    *(s8 *)((s8 *)temp_r3 + 0x19C) = start_joint;
    *(s8 *)((s8 *)temp_r3 + 0x1A0) = end_joint;
}

void TObjPlayer::set_model_param(s16 v) { *(s16 *)&this->unk_118 = v; }
void TObjPlayer::set_model_id(s16 v) { this->m_116 = v; }
s16 TObjPlayer::is_status_subsystem_ready() { return TObjPlayer__sub_801D2F4C((s16 *)((char*)this + 0x7cc)); }
void*TObjPlayer::get_extended_state() { return ((TObjPlayer *)((char*)this + 0x7cc))->get_state_ptr(); }
f32 TObjPlayer::query_extended_state() { return get_attack_damage_scale((s16 *)((char*)this + 0x7cc)); }
void TObjPlayer::test_flag30_bit0x100000() { obj_testFlags30((u32)((void*)1048576)); }
}
void* get_model_joint_matrix(void* a0, int a1) {  return (char*)(*(int*)((char*)a0 + 0xdb4)) + a1 * 48; }
void TObjPlayer::set_action_type(s16 v) { *(s16*)((char*)this + 0x0) = v; }

// ---- pso/player/TObjPlayer_80121178

void*TObjPlayer::get_state_ptr() { return (char*)this + 0x30; }

// ---- pso/unk/text_80121180

struct RecoveredGlobal_80121198_lbl_804C43CC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80121198_lbl_804C43D8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80121180_lbl_804C43C0 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s16 get_validated_attack_stage();
extern RecoveredGlobal_80121198_lbl_804C43CC attack_type_accuracy_scales;
extern RecoveredGlobal_80121198_lbl_804C43D8 attack_combo_accuracy_multipliers;
extern RecoveredGlobal_80121180_lbl_804C43C0 attack_damage_scale_table;
typedef char RecoveredGlobal_80121198_lbl_804C43CC_size[sizeof(RecoveredGlobal_80121198_lbl_804C43CC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80121198_lbl_804C43D8_size[sizeof(RecoveredGlobal_80121198_lbl_804C43D8) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_80121180_lbl_804C43C0_size[sizeof(RecoveredGlobal_80121180_lbl_804C43C0) == 0xC ? 1 : -1];
f32 get_attack_damage_scale(s16 *arg0) {
    return *(f32 *)((s8 *)((u8 *)&attack_damage_scale_table.value + (*(s16 *)((s8 *)arg0 + 0) * 4)) + 0);
}

f32 get_attack_accuracy_scale(s16 *arg0) {
    return *(f32 *)((s8 *)((u8 *)&attack_type_accuracy_scales.value + (*(s16 *)((s8 *)arg0 + 0) * 4)) + 0) * *(f32 *)((s8 *)((u8 *)&attack_combo_accuracy_multipliers.value + (get_validated_attack_stage() * 4)) + 0);
}

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
s16 get_captured_target_collider_index(void* p) { return *(s16*)((char*)p + 0x2); }
u16 TObjPlayer::get_uid() { return *(u16*)((char*)this + 0x0); }


extern "C" {
struct Obj_80121248 { u8 pad[0x4]; s32 arr[1]; };

s32 *get_captured_target_entry(Obj_80121248 *self, s32 i) {
    return &self->arr[i];
}

s32 get_captured_target_count(s32 *arg0) {
    s32 temp_r3;
    temp_r3 = *arg0;
    if ((temp_r3 < 0) || (temp_r3 > 0xA)) {
        return 0;
    }
    return temp_r3;
}

}
