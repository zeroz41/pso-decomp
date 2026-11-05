#include "types.h"
#include <string.h>
#include "pso/items/TItemWeapon.h"
#include "pso/player/TUnk_804F1320.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TUnk_804A69DC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemAttackCol.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemEffectWeapon.h"
#include "pso/item/TItemEffPG.h"
#include "pso/item/TItemProShield.h"
#include "pso/item/WeaponAttackActions.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_804A4D70.h"
#include "pso/system/PadRumble.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/unk/text_80121180.h"
#include <stddef.h>
#include "pso/map/FloorArea.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/item/TItemMag.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TObjChara.h"
#include "pso/system/NinjaTypes.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/item_param.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/player/TObjPlayer_801211F0.h"
#include "pso/unk/text_80120150.h"
#include "pso/TItemAttacker.h"
#include "pso/TItemEffEquip.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TCameraCtrl.h"

// ---- pso/item/WeaponAttackActions

typedef struct { f32 x, y, z; } Vec_8011EB84;
struct Atk_8011EB84 {
    Vec_8011EB84 pos;
    u8 pad0C[0x10];
    f32 scale;
    u8 pad20[4];
    s32 type;
    s32 angle;
    Vec_8011EB84 dir;
    f32 f38;
    f32 f3C;
    u32 flags;
    void *owner;
    s32 id;
    u8 pad4C[0x78 - 0x4C];
};

struct Base_8011EB84 { u8 pad[0x18]; };

struct Wpn_8011EB84 : Base_8011EB84 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual s32 m33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void m57(Atk_8011EB84 *);
};

struct Node_8011EB84 { u8 b[0x2C]; };

struct Skel_8011EB84 { u8 pad[0x1C]; Node_8011EB84 n[1]; };

typedef struct A12_8011E3E8 { s32 a; s32 b; s32 c; } A12_8011E3E8;

typedef struct A16_8011E3E8 { s32 a; s32 b; s32 c; s32 d; } A16_8011E3E8;

typedef struct Obj_8011E3E8 { u8 pad[0xF0]; s32 f0; } Obj_8011E3E8;

struct Vec_8011EAB8 { f32 x, y, z; };

struct Params_8011EAB8 {
    Vec_8011EAB8 pos;
    u8 pad0C[0x28 - 0x0C];
    f32 f28;
    u8 pad2C[0x34 - 0x2C];
    s32 f34;
    s32 f38;
};

struct WeaponArgb { f32 alpha, red, green, blue; };

extern "C" {
WeaponArgb get_weapon_color__11TItemWeaponFPv(TItemWeapon *weapon);
void * get_captured_target_entry(void *, s32);
f32 * get_weapon_range_record(void *, s16);
s16 is_status_subsystem_ready__10TObjPlayerFv(s32);
s16 get_captured_target_collider_index(void *);
u16 get_uid__10TObjPlayerFv(void *);
s32 get_captured_target_count(s32 *arg0);
u8 *find_entity_by_id(s32);
void *TObjPlayer__sub_802E449C(void *a0);
s32 rotate_matrix_y(int, void *);
s32 subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 transform_point_by_current_matrix(void *, void *);
s32 pop_matrix();
extern s32 identity_matrix[];
extern const f32 lbl_805DAC94;
u32 __nw__7TObjectFUl(u32);
void construct_actor_light_task(u32, void *, void *, s32, s32, s32, f32);
extern A12_8011E3E8 lbl_8043E838[];
extern A16_8011E3E8 lbl_8043E844[];
s32 is_locally_controlled__10TObjPlayerFPv(s32);
void create__10TItemEffPGFPvPvPv(void *arg0, void *parent, void *item);
void create__10TItemEffPGFPvPv(s32, Params_8011EAB8 *);
struct VBase_8011E2AC { char pad[0x18]; };

struct VObj_8011E2AC : VBase_8011E2AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual s32 m30();
};

struct Stack_8011E56C {
    s32 sp8;
    f32 spC;
};

struct VBase18c_8011e6e8 { char pad[0x18]; };

struct VObj18c_8011e6e8 : VBase18c_8011e6e8 {
    virtual s32 m0();  virtual s32 m1();  virtual s32 m2();
    virtual s32 m3();  virtual s32 m4();  virtual s32 m5();
    virtual s32 m6();  virtual s32 m7();  virtual s32 m8();
    virtual s32 m9();  virtual s32 m10(); virtual s32 m11();
    virtual s32 m12(); virtual s32 m13(); virtual s32 m14();
    virtual s32 m15(); virtual s32 m16(); virtual s32 m17();
    virtual s32 m18(); virtual s32 m19(); virtual s32 m20();
    virtual s32 m21(); virtual s32 m22(); virtual s32 m23();
    virtual s32 m24(); virtual s32 m25(); virtual s32 m26();
    virtual s32 m27(); virtual s32 m28(); virtual s32 m29();
    virtual s32 m30(); virtual s32 m31(); virtual s32 m32();
    virtual s32 m33(); virtual s32 m34(); virtual s32 m35();
    virtual s32 m36(); virtual s32 m37(); virtual s32 m38();
    virtual s32 m39(); virtual s32 m40(); virtual s32 m41();
    virtual s32 m42(); virtual s32 m43(); virtual s32 m44();
    virtual s32 m45(); virtual s32 m46(); virtual s32 m47();
    virtual s32 m48(); virtual s32 m49(); virtual s32 m50();
    virtual s32 m51(); virtual s32 m52(); virtual s32 m53();
    virtual s32 m54(); virtual s32 m55(); virtual s32 m56();
    virtual s32 m57(); virtual s32 m58(); virtual s32 m59();
    virtual s32 m60(); virtual s32 m61(); virtual s32 m62();
    virtual s32 m63(s32, void *);
};

struct Base_8011E828 { char pad[0x18]; };

struct VObj_8011E828 : Base_8011E828 {
    virtual void m0();   virtual void m1();   virtual void m2();   virtual void m3();
    virtual void m4();   virtual void m5();   virtual void m6();   virtual void m7();
    virtual void m8();   virtual void m9();   virtual void m10();  virtual void m11();
    virtual void m12();  virtual void m13();  virtual void m14();  virtual void m15();
    virtual void m16();  virtual void m17();  virtual void m18();  virtual void m19();
    virtual void m20();  virtual void m21();  virtual void m22();  virtual void m23();
    virtual void m24();  virtual void m25();  virtual void m26();  virtual void m27();
    virtual void m28();  virtual void m29();  virtual void m30();  virtual void m31();
    virtual void m32();  virtual s32 m33();
};

struct Base_8011E77C { char pad[0x18]; };

struct VObj_8011E77C : Base_8011E77C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
};

struct Vec_8011E87C { f32 x, y, z; };

struct Pl_8011E950 {
    u8 pad0[0x174];
    u32 x174;
    u8 pad178[0x18C - 0x178];
    void *eff[4];
    s8 kind[4];
};


struct Obj_8011F474 { u8 pad0[0x38]; f32 pos[3]; };

struct Base_8011F474 { u8 pad0[0x18]; };

struct Pl_8011F474 : Base_8011F474 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void on_near(Obj_8011F474 *, Obj_8011F474 *, s16, s16);
};

struct PlSelf_8011F474 : Pl_8011F474 {
    u8 pad1C[0xF0 - 0x1C];
    Obj_8011F474 *owner;
};

struct ShotVector { f32 x,y,z; };

struct ShotPayload { s32 reserved,kind,weapon; s16 source,target,collider,pad; f32 damage; };

struct Rec_8011F108 { u8 pad0[0xC]; f32 c; u8 pad1[0xC]; ShotVector pos; u8 pad2[4]; };

struct Obj_8011F474;

struct Vec_8011EDFC { f32 x; f32 y; f32 z; };

struct Part_8011EDFC { u8 pad0[0x1C]; Vec_8011EDFC pos; u8 pad28[4]; };

struct Obj_8011EDFC { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0xA4 - 0x44]; Part_8011EDFC *parts; };

struct Hit_8011EDFC { u8 pad0[4]; void *pos; };

struct Spawn_8011EDFC { s32 a; s32 b; s32 c; s16 d; s16 e; s16 f; f32 g; };

struct Self_8011EDFC;

typedef void (*Cb_8011EDFC)(Self_8011EDFC *, void *, Vec_8011EDFC *, f32);

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
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
s32 get_entity_id(void *);
s32 get_mode__11TCameraCtrlFPv(void *);
u8 * csnVector(void *, void *, s32);
s32 test_action_mask__10TObjPlayerFl(void *, s32);
s32 is_model_shown__5TItemFv(void *);
void send_activate_effect__5TItemFl(void *, s32);
s32 init__9TItemDataFv(s32 *);
void get_weapon_special_type_amount(u32 x, s16 *a, s16 *b);
void query_extended_state__10TObjPlayerFv(void *);
s32 set_action_type__10TObjPlayerFs(int, int);
f32 get_attack_accuracy_scale(s16 *arg0);
void TObjPlayer__sub_80121228(void *p, u32 v);
f32 horizontal_distance_squared(void *, void *);
Obj_8011F474 * resolve_hittable_target(s32, s32);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
void * __ct__17TItemEffectWeaponFll(void *, u32, u32);
void * __nw__15TItemHeapObjectFUl(s32);
u32 __cvt_fp2unsigned(f32);
s32 rand(void);
s32 vec3_add_to(void *, void *);
f32 normalize_vector(void *);
f32 xyz_distance(void *, void *);

extern const f32 lbl_805DAC98;

void TItemWeapon::set_weapon_category_flags() {
    s32 r = ((VObj_8011E2AC *)((u8 *)this))->m30();
    u32 flags = 0x10000;
    if (r & 1) {
        flags = 0x20000;
    }
    set_weapon_flags(flags);
}

void TObjPlayer::drain_owner_hp_fraction(f32 farg0) {
    if (*(u32 *)&this->blend.frame[1] != 0U) {
        TObjectV8047c128_subtract_hp((u8 *)(*(u32 *)&this->blend.frame[1]), (farg0 * (f32) ((TItemProShield *)(*(u32 *)&this->blend.frame[1]))->get_field_2b8()));
    }
}

s32 TItemWeapon::is_mode_two_and_ready() {
    if ((is_status_subsystem_ready__10TObjPlayerFv(*(s32 *)&owner) == 2) &&
        (is_identified() == 1)) {
        return 1;
    }
    return 0;
}

void TItemWeapon::spawn_light_task() {
    Obj_8011E3E8 *arg0 = (Obj_8011E3E8 *)this;
    A12_8011E3E8 a = lbl_8043E838[0];
    A16_8011E3E8 b = lbl_8043E844[0];
    u32 p = __nw__7TObjectFUl(0x64);
    if (p != 0) {
        ((void (*)(f32, u32, void *, void *, s32, s32, s32))construct_actor_light_task)(0.2f, p, &b, &a, 1, arg0->f0, (s32)tl_07);
    }
}

void TItemWeapon::restore_action_type() {
    u8 *arg0 = (u8 *)this;
    if (((TItemWeapon *)arg0)->test_weapon_flags(0x04000000) != 0U) {
        set_action_type__10TObjPlayerFs((int) (*(s32 *)&this->owner + 0x7CC), 2);
        ((TItemWeapon *)arg0)->clear_weapon_flags(0x04000000);
    }
}

void TItemWeapon::remap_extra_attack_type() {
    if ((this->test_weapon_flags(0x20) != 0U) && (TObjPlayer__sub_801D2F4C((s16 *)(*(s32 *)((s8 *)this + 0xF0) + 0x7CC)) == 2)) {
        if (this->test_weapon_flags(0x100000) != 0U) {
            set_action_type__10TObjPlayerFs((int) (*(s32 *)((s8 *)this + 0xF0) + 0x7CC), 0);
        } else {
            set_action_type__10TObjPlayerFs((int) (*(s32 *)((s8 *)this + 0xF0) + 0x7CC), 1);
        }
        set_weapon_flags(0x04000000);
    }
}

u8 *TItemWeapon::trace_from_owner(u8 *point) {
    Stack_8011E56C stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(*(s32 *)((s8 *)((u8 *)this) + 0xF0) + 0x2FC));
    stack.spC = *(f32 *)((s8 *)point + 4);
    return csnVector(&stack.sp8, point, 0x8100);
}

void TItemWeapon::vfunc_60() {  }

void TItemWeapon::vfunc_59() {  }

void TItemWeapon::vfunc_58() {  }

void TItemWeapon::vfunc_57() {  }

void TItemWeapon::update_weapon() {  }

void TItemWeapon::reserved_53() {  }

void TItemWeapon::update_idle() {  }

void TItemWeapon::update_attack() {  }

void TItemWeapon::emit_marker_effects() {  }

void TItemWeapon::carry_over_stats(TItemData *data, TItem *item) { memcpy((char*)data + 0x6, (char*)item + 0x1a4, 6); }
}
void spawn_item_attacker(s32 arg0, u32 arg1, s32 arg2, u8 *arg3);
void spawn_land_hit_effect(s32 arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4);
u32 pack_weapon_trail_color(void *arg0);

void TItemWeapon::activate_effect(s32 effect) {
    technique_roll = effect;
}

void TItemWeapon::roll_technique() {
    previous_technique_roll = technique_roll;
    send_activate_effect__5TItemFl(this, (s32) ((f32) technique_roll_range * (3.0517578e-05f * (f32) rand())));
}

void TObjPlayer::set_flag_8_if_check_passes() {
    u8 *var_r31;
    if (this != NULL) {
        var_r31 = (u8 *)this;
        if (((TItem *)(((u8 *)this)))->get_mode() != 0) {
            ((TItemWeapon *)var_r31)->set_flag_8();
        }
    }
}

void *TItemWeapon::get_center() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = (unsigned char *) (this->owner);
    if (temp_r3 != NULL) {
        ((VObj18c_8011e6e8 *) temp_r3)->m63(0x30, arg0 + 0x1AC);
    }
    return arg0 + 0x1AC;
}

void TObjPlayer::call_callback_1ec(s32 arg1, s32 arg2) {
    s32 (*temp_r12)(s32, void *, s32, s32);

    temp_r12 = *(s32 (**)(s32, void *, s32, s32))((s8 *)this + 0x1EC);
    if (temp_r12 != NULL) {
        temp_r12((s32)tl_05, this, arg1, arg2);
    }
}

void TItemWeapon::apply_model_params() {
    s16 spA;
    s16 sp8;

    get_weapon_special_type_amount((this->special_selector) & 0x3F, &spA, &sp8);
    ((TObjPlayer *)(this->owner))->set_model_id(spA);
    ((TObjPlayer *)(this->owner))->set_model_param(sp8);
    ((VObj_8011E77C *)(this->owner))->m71();
}

s32 TItemWeapon::is_identified() {
    TItemData data;

    data.init();
    copy_to_item_data(&data);
    return data.check_item_flags();
}

void TItemWeapon::refresh_special() {
    struct VObj_8011E828 *o = (struct VObj_8011E828 *)this;
    if (o->m33() == 0) {
        ((TItemWeapon *)o)->special_selector = ((TItemWeapon *)o)->special_selector & 0x7F;
    }
    ((TItemWeapon *)o)->apply_model_params();
}

void TItemWeapon::update_trail_slot(s32 slot) {
    Vec_8011E87C a;
    Vec_8011E87C b;
    if (is_default_camera() != 0 && has_no_defer_render() == 0 &&
        test_action_mask__10TObjPlayerFl(owner, 0xE0) != 0 &&
        owner->is_flag_b0_4() == 0 &&
        !(get_mode__11TCameraCtrlFPv(((u8 *)&main_task)) & 0x78)) {
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
                void *p = __nw__15TItemHeapObjectFUl(0x2C);
                if (p != NULL) {
                    p = __ct__17TItemEffectWeaponFll(p, ((Pl_8011E950 *)this)->x174, flags);
                }
                ((Pl_8011E950 *)this)->eff[i] = p;
            }
            if (((Pl_8011E950 *)this)->eff[i] != NULL && obj_testFlags30__14TObjCollidableFUl(((Pl_8011E950 *)this), 0x2000) != 0) {
                TObjPlayer__sub_80121228(((Pl_8011E950 *)this)->eff[i], 1);
            }
        }
    }
}

u32 pack_weapon_trail_color(void *weapon) {
    WeaponArgb w = get_weapon_color__11TItemWeaponFPv((TItemWeapon *)weapon);
    return (__cvt_fp2unsigned(255.0f * w.alpha) << 24 | __cvt_fp2unsigned(255.0f * w.red) << 16 | __cvt_fp2unsigned(255.0f * w.green) << 8) | __cvt_fp2unsigned(255.0f * w.blue);
}

void TUnk_804F1320::spawn_pg_effect(void *arg1, s32 item, f32 farg0) {
    Params_8011EAB8 prm;
    if (item < 0 || item >= 200) {
        return;
    }
    if (is_active_in_game() == 0) {
        return;
    }
    remap_extra_attack_type();
    ((TItemEffPG *)(&prm))->init_params();
    ((TObjPlayer *)((u8 *)this))->fill_status_info(&prm);
    VecCopy((Vec *)&prm.pos, (const Vec *)((Vec_8011EAB8 *)arg1));
    prm.f28 = farg0;
    prm.f34 = (s32)this->second_model;
    prm.f38 = *(s32 *)(((u8 *)this) + 0x24);
    if (is_locally_controlled__10TObjPlayerFPv(*(s32 *)(((u8 *)this) + 0xF0)) != 0) {
        create__10TItemEffPGFPvPv((s32)tl_05, &prm);
    } else {
        create__10TItemEffPGFPvPvPv((void *)tl_05, &prm, (void *)item);
    }
    this->restore_action_type();
}

void TItemWeapon::fire_shot_at_target(void *origin, void *model, s32 angle) {
    Vec_8011EB84 v;
    Atk_8011EB84 atk;
    f32 *scale;
    s32 state;
    s32 item;
    u8 *ph;
    u8 *hit;
    s32 off;
    if (is_active_in_game() != 0) {
        scale = ((f32 *(*)(void *, s32))get_weapon_range_record)(this, ((s32 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)(this->owner));
        TObjPlayer__sub_802E449C(&atk);
        ((TObjPlayer *)((u8 *)this))->fill_status_info(&atk);
        VecCopy((Vec *)&atk, (const Vec *)((Vec_8011EB84 *)origin));
        atk.angle = *(s32 *)((s8 *)(this->owner) + 0x60) + angle;
        atk.f3C = *scale;
        atk.f38 = shot_speed;
        atk.owner = model;
        atk.id = *(s32 *)((s8 *)((u8 *)this) + 0x24);
        ((Wpn_8011EB84 *)((u8 *)this))->m57(&atk);
        remap_extra_attack_type();
        hit = trace_from_owner((u8 *)origin);
        if (hit != NULL) {
            VecCopy((Vec *)&atk, (const Vec *)(*(void **)((s8 *)hit + 4)));
            atk.flags |= 0x800;
        } else if ((state = (s32)((TObjPlayer *)(this->owner))->get_extended_state()) != 0 && get_captured_target_count((s32 *)state) > 0) {
            if ((item = (s32)get_captured_target_entry((void *)state, 0)) != 0) {
                if ((ph = ((u8 *(*)(s32))find_entity_by_id)(((s32 (*)(s32))get_uid__10TObjPlayerFv)(item))) != NULL && *(u8 **)((s8 *)ph + 0xA4) != NULL) {
                    VecCopy((Vec *)&v, (const Vec *)(&(*(Skel_8011EB84 **)((s8 *)ph + 0xA4))->n[get_captured_target_collider_index((void *)item)]));
                    subtract_vector(&v, ((Vec_8011EB84 *)origin));
                    push_matrix_from(((s32 *)&identity_matrix));
                    ((void (*)(s32, s32))rotate_matrix_y)(0, angle);
                    transform_point_by_current_matrix(&v, &atk.dir);
                    atk.flags |= 1;
                    pop_matrix();
                }
            }
        }
        if (atk.type == 2 && ((Wpn_8011EB84 *)((u8 *)this))->m33() == 0) {
            atk.scale *= lbl_805DAC94;
        }
        TItemAttackCol::create((void *)tl_05, &atk);
        this->restore_action_type();
    }
}

void TObjPlayer::fill_status_info(void *arg1) {
    ((TItemWeapon *)this)->remap_extra_attack_type();
    *(s16 *)((s8 *)arg1 + 0x14) = ((s16 (*)(s32))get_entity_id)(*(s32 *)&this->blend.frame[1]);
    *(s16 *)((s8 *)arg1 + 0x16) = ((TObjBase *)(*(s32 *)&this->blend.frame[1]))->get_room();
    *(s32 *)((s8 *)arg1 + 0x18) = ((TItem *)this)->get_item_id();
    *(f32 *)((s8 *)arg1 + 0x1C) = get_attack_accuracy_scale((s16 *)(*(s32 *)&this->blend.frame[1] + 0x7CC));
    *(s32 *)((s8 *)arg1 + 0x24) = (s32) is_status_subsystem_ready__10TObjPlayerFv(*(s32 *)&this->blend.frame[1]);
    *(f32 *)((s8 *)arg1 + 0x20) = ((f32 (*)(s32))query_extended_state__10TObjPlayerFv)(*(s32 *)&this->blend.frame[1]);
    ((TItemWeapon *)this)->restore_action_type();
}

void TObjPlayer::launch_rare_weapon_special(void *origin, s32 enable, f32 scale) {
    void *ext;
    Vec_8011EDFC pos;
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
    if (get_captured_target_count((s32 *)ext) != 0) {
        void *e = get_captured_target_entry(ext, get_captured_target_count((s32 *)ext) - 1);
        Obj_8011EDFC *t = ((Obj_8011EDFC *(*)(u16, s16))resolve_hittable_target)(get_uid__10TObjPlayerFv(e), get_captured_target_collider_index(e));
        if (t != NULL) {
            Part_8011EDFC *part = &t->parts[get_captured_target_collider_index(e)];
            VecCopy((Vec *)&pos, (const Vec *)&part->pos);
            found = 1;
        }
    }
    if (found == 0) {
        Vec_8011EDFC v;
        f32 *rec;
        push_matrix_from(identity_matrix);
        rec = get_weapon_range_record(this, 2);
        v.x = v.y = lbl_805DAC98;
        v.z = rec[0];
        rotate_matrix_y(0, ((Owner_8011EDFC *)((Self_8011EDFC *)this)->owner)->rot);
        transform_point_by_current_matrix(&v, &pos);
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
        for (s32 i = 0; i != get_captured_target_count((s32 *)ext); i++) {
            void *e = get_captured_target_entry(ext, i);
            Obj_8011EDFC *t = ((Obj_8011EDFC *(*)(u16, s16))resolve_hittable_target)(get_uid__10TObjPlayerFv(e), get_captured_target_collider_index(e));
            if (t != NULL) {
                Part_8011EDFC *part = &t->parts[get_captured_target_collider_index(e)];
                void *e2 = get_captured_target_entry(ext, i);
                Spawn_8011EDFC sp;
                sp.a = 0;
                sp.b = 1;
                sp.d = get_entity_id(((Self_8011EDFC *)this)->owner);
                sp.e = get_entity_id(t);
                sp.c = ((TItem *)this)->get_item_id();
                sp.f = get_captured_target_collider_index(e2);
                sp.g = scale * ((f32 (*)(void *))query_extended_state__10TObjPlayerFv)(((Self_8011EDFC *)this)->owner);
                spawn_item_attacker((s32)tl_05, (u32)(((Self_8011EDFC *)this)->owner + 0x38), (s32)(xyz_distance(origin, &part->pos) / ((Self_8011EDFC *)this)->speed), (u8 *)&sp);
            }
        }
    }
    s32 n = (s32)(dist / ((Self_8011EDFC *)this)->speed);
    if (n < 0) {
        n = 0;
    }
    if (((Self_8011EDFC *)this)->cb != NULL && is_model_shown__5TItemFv(((Self_8011EDFC *)this)) == 1) {
        ((Self_8011EDFC *)this)->cb(((Self_8011EDFC *)this), origin, &pos, (f32)n);
    }
}

s32 TItemWeapon::launch_shot(u8 *arg1, s32 i, s32 arg3, s32 arg4) {
    s32 var_r31;
    ShotPayload hit;
    f32 *weapon_range_record;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_r4;
    f32 var_f31;
    s16 temp_r29;
    s32 var_r23;
    u8* temp_r22;
    u8* temp_r22_3;
    u8* temp_r3;
    s32 temp_r6;
    u8 *temp_r22_2;
    u8 *temp_r3_3;
    u8 *var_r29;
    var_r31 = 0;
    if (is_active_in_game() != 0) {
        temp_r3 = (u8 *)((TObjPlayer *)(this->owner))->get_extended_state();
        if (temp_r3 != 0) {
            var_r23 = 0;
            var_r29 = NULL;
            ShotVector endpoint = *(ShotVector *)arg1;
            if (i < get_captured_target_count((s32 *)temp_r3)) {
                temp_r22 = (u8 *)get_captured_target_entry(temp_r3,i);
                var_r29 = (u8 *)(((Obj_8011F474 *(*)(s32, s16))resolve_hittable_target)(((s32 (*)(void *))get_uid__10TObjPlayerFv)(temp_r22),get_captured_target_collider_index(temp_r22)));
                if (var_r29 != NULL) {
                    temp_r22_2 = (u8 *)&(*(Rec_8011F108 **)((s8 *)var_r29 + 0xA4))[get_captured_target_collider_index(temp_r22)];
                    VecCopy((Vec *)(&endpoint.x), (const Vec *)((void *) &((Rec_8011F108 *)temp_r22_2)->pos));
                    subtract_vector(&endpoint.x, arg1);
                    temp_f3 = normalize_vector(&endpoint.x) - *(f32 *)((s8 *)temp_r22_2 + 0xC);
                    endpoint.x *= temp_f3;
                    endpoint.y *= temp_f3;
                    endpoint.z *= temp_f3;
                    vec3_add_to(&endpoint.x, arg1);
                    var_r23 = 1;
                }
            }
            if (var_r23 == 0) {
                ShotVector fallback;
                push_matrix_from(identity_matrix);
                weapon_range_record = (f32 *)(get_weapon_range_record(this, ((s16 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)((void *)this->owner)));
                fallback.y = lbl_805DAC98;
                fallback.x = lbl_805DAC98;
                fallback.z = *(f32 *)((s8 *)weapon_range_record + 0);
                rotate_matrix_y(0, (void *) (*(s32 *)((s8 *)this->owner + 0x60) + arg3));
                transform_point_by_current_matrix(&fallback.x, &endpoint.x);
                pop_matrix();
                vec3_add_to(&endpoint.x, arg1);
            }
            ShotVector rayOrigin = *(ShotVector *)(((u8 *)this->owner) + 0x2FC);
            rayOrigin.y = *(f32 *)((s8 *)arg1 + 4);
            temp_r3_3 = (u8 *)(csnVector(&rayOrigin.x, &endpoint.x, 0x8100));
            if (temp_r3_3 == NULL) {
                if (var_r29 != NULL) {
                    temp_r22_3 = (u8 *)get_captured_target_entry(temp_r3,i);
                    temp_r22_2 = (u8 *)&(*(Rec_8011F108 **)((s8 *)var_r29 + 0xA4))[get_captured_target_collider_index(temp_r22_3)];
                    var_f31 = xyz_distance(arg1, (void *) &((Rec_8011F108 *)temp_r22_2)->pos) / shot_speed;
                    if (arg4 != 0) {
                        remap_extra_attack_type();
                        hit.reserved = 0;
                        hit.kind = (s32) ((s16 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)((void *)this->owner);
                        hit.source = get_entity_id((void *)this->owner);
                        hit.target = get_entity_id(var_r29);
                        hit.weapon = ((TItem *)((u8 *)this))->get_item_id();
                        hit.collider = get_captured_target_collider_index(temp_r22_3);
                        hit.damage = ((f32 (*)(void *))query_extended_state__10TObjPlayerFv)((void *)this->owner);
                        spawn_item_attacker((s32)tl_05, (u32)arg1, ((s32) var_f31), (u8 *)&hit.reserved);
                        var_r31 = 1;
                        this->restore_action_type();
                    }
                } else {
                    var_f31 = xyz_distance(arg1, &endpoint.x) / shot_speed;
                }
            } else {
                VecCopy((Vec *)(&endpoint.x), (const Vec *)(*(u8 **)((s8 *)temp_r3_3 + 4)));
                var_f31 = xyz_distance(arg1, &endpoint.x) / shot_speed;
                if ((*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3_3 + 4)) + 0x18) & 0x100) && (impact_callback != NULL)) {
                    spawn_land_hit_effect((s32)tl_05, (u32)this, (u32)arg1, (u32)&endpoint.x, (s32)((s32) var_f31));
                }
            }
            this->spawn_light_task();
            if ((shot_callback != NULL) && (is_model_shown() == 1)) {
                shot_callback(this, arg1, &endpoint.x, var_f31);
            }
        }
    }
    return var_r31;
}

void TUnk_804A69DC::for_each_target_in_range(f32 range) {
    Obj_8011F474 *obj;
    u16 uid;
    void *state;
    s32 i;
    void *ent;
    s32 id;
    s32 ready;
    if (is_active_in_game() != 0) {
        remap_extra_attack_type();
        state = ((TObjPlayer *)(((PlSelf_8011F474 *)this)->owner))->get_extended_state();
        if (state != NULL) {
            for (i = 0; i != get_captured_target_count((s32 *)state); i++) {
                ent = get_captured_target_entry(state, i);
                uid = get_uid__10TObjPlayerFv(ent);
                id = get_captured_target_collider_index(ent);
                obj = resolve_hittable_target(uid, id);
                if (obj != NULL && horizontal_distance_squared(((PlSelf_8011F474 *)this)->owner->pos, obj->pos) < range) {
                    ready = ((s16 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)(((PlSelf_8011F474 *)this)->owner);
                    query_extended_state__10TObjPlayerFv(((PlSelf_8011F474 *)this)->owner);
                    ((PlSelf_8011F474 *)this)->on_near(((PlSelf_8011F474 *)this)->owner, obj, ready, id);
                }
            }
        }
        this->restore_action_type();
    }
}

// ---- pso/player/TObjPlayer_8011F578

struct Base_8011F5E0 { char pad[0x18]; };
struct VObj_8011F5E0 : Base_8011F5E0 {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)VV(34)VV(35)VV(36)VV(37)VV(38)VV(39)VV(40)
VV(41)VV(42)VV(43)VV(44)VV(45)VV(46)VV(47)VV(48)VV(49)VV(50)
VV(51)VV(52)VV(53)VV(54)VV(55)VV(56)VV(57)VV(58)VV(59)VV(60)
VV(61)VV(62)VV(63)VV(64)
#undef VV
    virtual void v67(f32);
};

extern "C" {

struct Base_8011F578 { char pad[0x18]; };
struct VObj_8011F578 : Base_8011F578 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(f32);
};

void TUnk_804A4D70::apply_scale_if_active(f32 farg0) {

    if (((TItemWeapon *)this)->is_active_in_game() != 0) {
        ((TItemWeapon *)this)->remap_extra_attack_type();
        ((VObj_8011F578 *)(this->owner))->m65(farg0);
        ((TItemWeapon *)this)->restore_action_type();
    }
}

extern const f32 lbl_805DAC9C;

void TObjPlayer::update_active_game_effect() {

    if (((TItemWeapon *)this)->is_active_in_game() != 0) {
        ((TItemWeapon *)this)->remap_extra_attack_type();
        ((VObj_8011F5E0 *)(*(void * *)&this->blend.frame[1]))->v67(lbl_805DAC9C);
        ((TItemWeapon *)this)->restore_action_type();
    }
}

}

// ---- pso/unk/text_8011F63C

extern "C" {
s32 TItemWeapon::get_attack_stage() {
    u32 temp_r3;
    temp_r3 = *(u32 *)&this->owner;
    if (temp_r3 != 0U) {
        if (test_action_mask__10TObjPlayerFl((void *)temp_r3, 0x20) != 0) {
            return 0;
        }
        if (test_action_mask__10TObjPlayerFl(this->owner, 0x40) != 0) {
            return 1;
        }
        if (test_action_mask__10TObjPlayerFl(this->owner, 0x80) != 0) {
            return 2;
        }
        goto block_7;
    }
block_7:
    return -1;
}

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

struct VBase_18_f8c4e0 { char pad[0x18]; };

struct VObj_18_f8c4e0 : VBase_18_f8c4e0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual s32 m19(void *, s32, s32, f32);
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual s32 m22(void *, s32);
    virtual s32 m23(void *, f32);
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual s32 m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual s32 m73();
};

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
void apply_camera_shake__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
extern const f32 lbl_805DAC94;
extern const f32 lbl_805DAC98;
void play_weapon_owner_sounds(void*);

s32 add_weapon_grind(Obj_8011F710 *arg0, s32 arg1);

s32 add_weapon_grind(Obj_8011F710 *arg0, s32 arg1) {
    if ((s32)(arg0->stats->max - (u8)arg1) < arg0->cur) {
        arg0->cur = arg0->stats->max;
    } else {
        arg0->cur += arg1;
    }
    ((TItemEquipBase *)arg0)->refresh_owner_stats();
    return 1;
}

u32 TItemWeapon::get_attack_flags() {
    u32 flags = 0;
    Item_8011F760 *it;
    if (((TItem *)this)->get_icon_index() == 3) {
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

void TItemWeapon::deliver_hit(s32 arg1, u8 *arg2, s32 arg3, s32 arg4, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_8011F7CC, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_8011F7CC, sp9) == 0x1) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8011F7CC, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8011F7CC, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8011F7CC, sp18) == 0x10) ? 1 : -1];
    Stack_8011F7CC stack;
    f32 attack_accuracy_scale;
    f32 var_f31_2;
    s32 temp_r31;
    s32 temp_r31_2;
    u8 *temp_r3;
    if (get_mode() == 2) {
        temp_r3 = (u8 *)this->owner;
        if ((temp_r3 != NULL) && (arg2 != NULL)) {
            attack_accuracy_scale = get_attack_accuracy_scale((s16 *)(temp_r3 + 0x7CC));
            if ((arg3 == 2) && (((VObj_18_f8c4e0 *)(this))->m33() == 0)) {
                attack_accuracy_scale *= lbl_805DAC94;
            }
            temp_r31 = arg4 * 0x2C;
            if (((VObj_18_f8c4e0 *)(arg2))->m19(this->owner, *(s32 *)((s8 *)arg2 + 0xA4) + temp_r31, 0, attack_accuracy_scale) != 0) {
                var_f31_2 = lbl_805DAC98;
                switch (arg3) {
                case 0:
                    var_f31_2 = ((VObj_18_f8c4e0 *)(arg2))->m20(this->owner, farg0);
                    break;
                case 1:
                    var_f31_2 = ((VObj_18_f8c4e0 *)(arg2))->m20(this->owner, farg0);
                    ((VObj_18_f8c4e0 *)(arg2))->m23(this->owner, lbl_805DAC94 * var_f31_2);
                    break;
                case 2:
                    ((VObj_18_f8c4e0 *)(arg2))->m22(this->owner, *(s32 *)((s8 *)arg2 + 0xA4) + temp_r31);
                    break;
                }
                if (hit_callback != NULL) {
                    hit_callback((s32)tl_05, this, get_entity_id(arg2), arg4);
                }
                temp_r31_2 = (s32) var_f31_2;
                TObjPlayer::calc_photon_blast_charge(this->owner, temp_r31_2);
                ((VObj_18_f8c4e0 *)(this->owner))->m73();
                apply_camera_shake__10TObjPlayerFiii((s32)this->owner, (s32)arg2, (s32)temp_r31_2);
                ((TObjPlayer *)(&stack.sp8))->reset_status_block();
                stack.sp8 = ((TItem *)((u8 *)this))->get_item_group();
                stack.sp9 = ((TItem *)((u8 *)this))->get_item_index();
                stack.spC = (u8 *)this->owner;
                stack.sp14 = arg2;
                stack.sp18 = arg4;
                play_weapon_hit_sound(&stack.sp8);
            }
        }
    }
}
}
void TItemWeapon::perform_action() {
    TItemWeapon* self=this;
    WeaponMarkerPacket packet;
    WeaponVector gun_point;
    WeaponVector fallback_point;
    if (((TItemWeapon *)self)->is_active_in_game() && !((TItem *)self)->is_hidden() && is_current_area_item_enabled()) {
        self->rotation_y=self->owner->rotation_y;
        self->stage=((TItemWeapon *)self)->get_attack_stage();
        ((TObjPlayer *)(&packet))->reset_status_block();
        packet.kind=((TItem *)self)->get_item_group();
        packet.variant=((TItem *)self)->get_item_index();
        packet.player=self->owner;
        play_weapon_owner_sounds(&packet);
        if(((TItemWeapon *)self)->test_weapon_flags(0x40000)) {
            start_pad_rumble_client(0x80, 5, (s16)get_entity_id(self->owner));
        } else if(((TItemWeapon *)self)->test_weapon_flags(0x80000) && ((TItemWeapon *)self)->is_mode_two_and_ready()) {
            start_pad_rumble_client(0x80, 5, (s16)get_entity_id(self->owner));
        }
        self->emit_marker_effects();
        ((TItemWeapon *)self)->set_weapon_flags(0x1000000);
        if(!((TItemWeapon *)self)->test_weapon_flags(2)) {
            if(((TItemWeapon *)self)->test_weapon_flags(0x8000)) {
                ((TItemWeapon *)self)->get_gun_point(&gun_point);
                ((TItemWeapon *)self)->fire_shot_at_target((void *)(&gun_point), (void *)(self->second_model), 0);
                return;
            }
            if(((TItemWeapon *)self)->test_weapon_flags(0x20000)) {
                ((TObjPlayer *)self)->update_active_game_effect();
                return;
            }
            ((TItemWeapon *)self)->get_gun_point(&fallback_point);
            self->launch_shot((u8 *)&fallback_point,0,0,1);
        }
    }
}

// ---- pso/player/TObjPlayer_8011FBCC

void TObjPlayer::draw_status_icons(void* a1, void* a2) { ((TItemWeapon *)this)->draw_weapon_model(); ((TItemWeapon *)this)->get_gun_point(a1); draw_weapon_at_joint((s32)this, (s8)((void*)35)); ((TItemWeapon *)this)->get_gun_point(a2); }

// ---- pso/unk/text_8011FC24

extern "C" {

s32 test_flag30_bit0x100000__10TObjPlayerFv(void*);
void TItemEffectWeapon__sub_8036340C(void*);
void TItemEffectWeapon__sub_80363410(void*);
extern const f32 lbl_805DAC9C;

s32 get_item_id__5TItemFv(void *);

void TItemWeapon::update_trails() {
    u8 *arg0 = (u8 *)this;
    if (((TItemWeapon *)arg0)->test_weapon_flags(0x400U) != 0U) {
        draw_weapon_at_joint((s32)arg0, 0x30);
        ((TItemWeapon *)arg0)->update_trail_slot(0);
        draw_weapon_at_joint((s32)arg0, 0x23);
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
    if (((u32) this->owner != 0U) && (((TItemWeapon *)arg0)->test_weapon_flags(0xCU) == 0xCU) && (((TItemWeapon *)arg0)->test_weapon_flags(0x80U) == 0U)) {
        this->reserved_53();
        update_trails();
    }
}
void TItemWeapon::render_equipped_shadow() {
    u8 *arg0 = (u8 *)this;
    if (((u32) this->owner != 0U) && (((TItemWeapon *)arg0)->test_weapon_flags(0xCU) == 0xCU) && (((TItemWeapon *)arg0)->test_weapon_flags(0x80U) == 0U) && (((TItemWeapon *)arg0)->test_weapon_flags(0x1000U) == 0U)) {
        this->reserved_53();
        if (((TItemWeapon *)arg0)->test_weapon_flags(0x400U) != 0U) {
            draw_weapon_at_joint((s32)arg0, 0x30);
            draw_weapon_at_joint((s32)arg0, 0x23);
            return;
        }
        if (((TItemWeapon *)arg0)->test_weapon_flags(1U) == 0U) {
            ((TItemWeapon *)arg0)->draw_weapon_model();
        }
    }
}
void TItemWeapon::render_equipped() {
    s32 count;
    if (((u32) this->owner != 0U) && (test_weapon_flags(0xCU) == 0xCU) && (test_weapon_flags(0x80U) == 0U)) {
        if (test_weapon_flags(0x800U) != 0U) {
            TObjPlayer::push_id_to_list(get_item_id__5TItemFv(this));
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
        if(stage>=0 || test_flag30_bit0x100000__10TObjPlayerFv(self->owner)) self->update_attack();
        else self->update_idle();
        if(self->model_motion) {
            self->motion_frame+=lbl_805DAC9C;
            frames=((WeaponMotionRecord *)self->model_motion)->frame_count;
            if((f32)frames<=self->motion_frame) self->motion_frame-=(f32)frames;
        }
        register_technique_boosts(technique_boosts);
        self->update_weapon();
        if(!((TObjChara *)self->owner)->is_in_fixed_pose()) self->advance_weapon_photon_phase();
        if(((TItem *)self)->is_hidden()) {
            count=0;
            do {
                void* trail=self->trails[count];
                if(trail) TItemEffectWeapon__sub_8036340C(trail);
                count++;
            } while(count!=4);
            return;
        }
        idle_count=0;
        do {
            void* trail=self->trails[idle_count];
            if(trail) TItemEffectWeapon__sub_80363410(trail);
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
    if (self->data->max < self->cur) {
        self->cur = 0;
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

struct WeaponCallbackBase { u8 padding[0x18]; };

struct WeaponCallbackObject : WeaponCallbackBase {
    virtual void callback0();
    virtual void callback1();
    virtual void callback2();
    virtual void callback3();
    virtual void callback4();
    virtual void callback5();
    virtual void callback6();
    virtual void callback7();
    virtual void callback8();
    virtual void callback9();
    virtual void callback10();
    virtual void callback11();
    virtual void callback12();
    virtual void callback13();
    virtual void callback14();
    virtual void callback15();
    virtual void callback16();
    virtual void callback17();
    virtual void callback18();
    virtual void callback19();
    virtual void callback20();
    virtual void callback21();
    virtual void callback22();
    virtual void callback23();
    virtual void callback24();
    virtual void callback25();
    virtual void callback26();
    virtual void callback27();
    virtual void callback28();
    virtual void callback29();
    virtual void callback30();
    virtual void callback31();
    virtual void callback32();
    virtual void callback33();
    virtual void callback34();
    virtual void callback35();
    virtual void callback36();
    virtual void callback37();
    virtual void callback38();
    virtual void callback39();
    virtual void callback40();
    virtual void callback41();
    virtual void callback42();
    virtual void callback43();
    virtual void callback44();
    virtual void callback45();
    virtual void callback46();
    virtual void callback47();
    virtual void callback48();
    virtual void callback49();
    virtual void callback50();
    virtual void callback51();
    virtual void callback52();
    virtual void callback53();
    virtual void callback54();
    virtual void callback55();
    virtual void callback56();
    virtual void callback57();
    virtual void materialCallback();
};


struct WeaponColorDescriptor_80120304 { s32 mode; WeaponArgb first, second; };

extern const f32 lbl_805DAC98;
extern const f32 lbl_805DAC9C;
extern const f32 lbl_805DACA0;
extern s16 weapon_node_material_index;
extern s16 TObjPlayer__weapon_node_ids[];
extern u8* weapon_render_callback_object;
extern "C" {
s32 test_flags_any(void*,u32);
extern u8 lbl_805DACA4;
}

void apply_weapon_node_material() {
    const s32 node = TObjPlayer::get_player_list();
    TItem::end_material_color();
    TItem::end_effect_render();
    ((TItem *)weapon_render_callback_object)->end_particle_tev();
    ((TItem *)weapon_render_callback_object)->end_shield_tev();
    ((WeaponCallbackObject*)weapon_render_callback_object)->materialCallback();
    if(node == weapon_node_material_index) {
        WeaponArgb color = get_weapon_color__11TItemWeaponFPv((TItemWeapon *)weapon_render_callback_object);
        TItem::begin_constant_material_color((const NJS_ARGB *)&color);
    }
    if(node == TObjPlayer__weapon_node_ids[0] || node == TObjPlayer__weapon_node_ids[1] || node == TObjPlayer__weapon_node_ids[2]) {
        TItem::begin_effect_render();
        if(test_flags_any(&item_render_state,4)) {
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
    void *temp_r3;

    ((TObjPlayer *)(this->owner))->set_model_id(0);
    ((TObjPlayer *)(this->owner))->set_model_param(0);
    i = 0;
    do {
        temp_r3 = ((TObjPlayer *)(this->owner))->get_attribute_entry(i);
        *(s8 *)((s8 *)temp_r3 + 0) = 0;
        i += 1;
        *(s8 *)((s8 *)temp_r3 + 1) = 0;
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

struct Pl_80120568B { char pad[0x18]; };

struct Pl_80120568 : Pl_80120568B {
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
    virtual s8 m31();
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
    virtual void m56();
    u8 pad[0xF0-0x1C+0x0];
    Ctl_80120568 *ctl;
};

struct VBase_8012065C { u8 pad[0x18]; };

struct Player_8012065C : VBase_8012065C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40();
    virtual u8 v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57();
};

extern "C" {
void clear_technique_boosts__14TItemEquipBaseFv(s32 arg0);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
void set_flag_8_if_check_passes__10TObjPlayerFv();

void TItemWeapon::on_unequip() {
    Pl_80120568 *arg0 = (Pl_80120568 *)this;
    if (arg0->ctl->m64(arg0->m31()) == 0) {
        ((TObjPlayer *)(arg0->ctl))->set_action_provider_variant(0);
    }
    arg0->m56();
    clear_technique_boosts__14TItemEquipBaseFv((s32)arg0);
    ((TItemWeapon *)arg0)->clear_weapon_flags(0x03000000);
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
    Player_8012065C *arg0 = (Player_8012065C *)this;
    if (test_flags_any((u8 *)arg0 + 0x178, 1) != 0) {
        if (!(((TItem *)arg0)->get_item_flags() & 0x20) && is_current_area_item_enabled() != 0) {
            ((TObjPlayer *)(*(void **)((s8 *)arg0 + 0xF0)))->set_action_provider_variant(arg0->v41());
        }
        ((TItemWeapon *)arg0)->clear_weapon_flags(0x100);
        if (((TItem *)arg0)->is_hidden() != 0 || ((TObjChara *)*(s32 *)((s8 *)arg0 + 0xF0))->is_in_fixed_pose() != 0) {
            ((TItemWeapon *)arg0)->set_weapon_flags(8);
        } else {
            TItemAttacker::spawn_item_timer((TObject *)arg0, (ItemTimerCallback)set_flag_8_if_check_passes__10TObjPlayerFv, 0x14);
            TItemEffEquip::create((void *)tl_05, (void *)(get_entity_id(*(void **)((s8 *)arg0 + 0xF0))), (void *)0x30, (void *)0x9D, (void *)0x9E);
            if (((TItemWeapon *)arg0)->test_weapon_flags(0x200) != 0U) {
                TItemEffEquip::create((void *)tl_05, (void *)(get_entity_id(*(void **)((s8 *)arg0 + 0xF0))), (void *)0x23, (void *)0x9D, (void *)0x9E);
            }
            update_technique_slot__10TTecRaFoieFl(play_sound_effect(0x4000B20A, *(s32 *)((s8 *)arg0 + 0xF0) + 0x38, 0, 0), 0x300, 0);
        }
    } else {
        ((TObjPlayer *)(*(void **)((s8 *)arg0 + 0xF0)))->set_action_provider_variant(0);
        ((TItemWeapon *)arg0)->set_weapon_flags(0x100);
        ((TItemWeapon *)arg0)->set_weapon_flags(8);
    }
    arg0->v55();
    ((TItemWeapon *)arg0)->clear_weapon_flags(0x03000000);
}

}

// ---- pso/player/TObjPlayer_801207E8

extern "C" {

typedef struct { f32 sp8; f32 spC; f32 sp10; } FloatTriplet;

s32 get_view_matrix__11TCameraCtrlFv();
s32 push_matrix();

extern const f32 lbl_805DAC98;

struct VObj_104_801207e8 { char pad[0x18]; virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(s32); };

s32 TItemWeapon::get_joint_position(s32 joint, void *out) {
    FloatTriplet floats;
    void *temp_r3;

    temp_r3 = owner;
    if (temp_r3 == NULL) {
        return 0;
    }
    if (joint == -1) {
        ((VObj_104_801207e8 *)temp_r3)->m63(0x30);
    } else if (joint == -2) {
        ((VObj_104_801207e8 *)temp_r3)->m63(0x23);
    } else if (item_model != NULL) {
        floats.sp10 = lbl_805DAC98;
        floats.spC = lbl_805DAC98;
        floats.sp8 = lbl_805DAC98;
        push_matrix();
        TObjPlayer::copy_matrix(0, (u32)get_model_joint_matrix(owner, joint));
        TCameraCtrl::concat_matrix(0, get_view_matrix__11TCameraCtrlFv());
        transform_point_by_current_matrix(&floats.sp8, out);
        pop_matrix();
    } else {
        ((VObj_104_801207e8 *)temp_r3)->m63(0x30);
    }
    return 1;
}

void TItemWeapon::get_gun_point(void *out) {
    get_joint_position(gun_point_joint, out);
}

}
