#include "pso/items/TItemWeapon.h"
#include "pso/player/TUnk_804F1320.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TUnk_804A69DC.h"

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemAttackCol.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemEffectWeapon.h"
#include "pso/item/TItemEffPG.h"
#include "pso/item/TItemProShield.h"

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

extern "C" {
f32 * get_weapon_range_record(void *, s16);
void remap_extra_attack_type__11TItemWeaponFv(TItemWeapon *arg0);
void sub_8011E56C__11TItemWeaponFPUc(u8 *arg0, u8 *arg1);
s32 is_active_in_game__11TItemWeaponFv(void *);
s16 is_status_subsystem_ready__10TObjPlayerFv(s32);
s16 get_captured_target_collider_index(void *);
u16 get_uid__10TObjPlayerFv(void *);
void * get_captured_target_entry(void *, s32);
s32 get_captured_target_count(s32 *arg0);
u8 *find_entity_by_id(s32);
void *TObjPlayer__sub_802E449C(void *a0);
s32 rotate_matrix_y(int, void *);
s32 subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 transform_point_by_current_matrix(void *, void *);
s32 pop_matrix();
extern s32 identity_matrix[];
extern s32 tl_05;
extern const f32 lbl_805DAC94;
u32 __nw__7TObjectFUl(u32);
void construct_actor_light_task(u32, void *, void *, s32, s32, s32, f32);
extern A12_8011E3E8 lbl_8043E838[];
extern A16_8011E3E8 lbl_8043E844[];
extern s32 tl_07;
extern const f32 lbl_805DAC88;
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

typedef struct V4_8011EA10 { f32 a; f32 b; f32 c; f32 d; } V4_8011EA10;

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

int memcpy(void*, void*, void*);
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
s16 get_entity_id(void *);
s32 get_mode__11TCameraCtrlFPv(void *);
u8 * csnVector(void *, void *, s32);
s32 test_action_mask__10TObjPlayerFl(void *, s32);
s32 is_model_shown__5TItemFv(void *);
void send_activate_effect__5TItemFl(void *, s32);
s32 init__9TItemDataFv(s32 *);
void get_weapon_special_type_amount(u32 x, s16 *a, s16 *b);
V4_8011EA10 get_weapon_color__11TItemWeaponFPv(void *);
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

extern const f32 lbl_805DAC8C;
extern const f32 lbl_805DAC90;
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
    if (*(u32 *)&this->unk_F0 != 0U) {
        TObjectV8047c128_subtract_hp((u8 *)(*(u32 *)&this->unk_F0), (farg0 * (f32) ((TItemProShield *)(*(u32 *)&this->unk_F0))->get_field_2b8()));
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
        ((void (*)(f32, u32, void *, void *, s32, s32, s32))construct_actor_light_task)(lbl_805DAC88, p, &b, &a, 1, arg0->f0, tl_07);
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

void TItemWeapon::sub_8011E56C(u8 *arg1) {
    Stack_8011E56C stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(*(s32 *)((s8 *)((u8 *)this) + 0xF0) + 0x2FC));
    stack.spC = *(f32 *)((s8 *)arg1 + 4);
    ((s32 (*)(void *, void *, int))csnVector)(&stack.sp8, arg1, 0x8100);
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

void TItemWeapon::carry_over_stats(TItemData *data, TItem *item) { memcpy((char*)data + 0x6, (char*)item + 0x1a4, (void*)6); }
}
void spawn_item_attacker(s32 arg0, u32 arg1, s32 arg2, u8 *arg3);
void spawn_land_hit_effect(s32 arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4);
u32 pack_weapon_trail_color(void *arg0);

void TItemWeapon::activate_effect(s32 effect) {
    technique_roll = effect;
}

void TItemWeapon::roll_technique() {
    previous_technique_roll = technique_roll;
    send_activate_effect__5TItemFl(this, (s32) ((f32) technique_roll_range * (lbl_805DAC8C * (f32) rand())));
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
        temp_r12(tl_05, this, arg1, arg2);
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
    V4_8011EA10 w = get_weapon_color__11TItemWeaponFPv(weapon);
    return (__cvt_fp2unsigned(lbl_805DAC90 * w.a) << 24 | __cvt_fp2unsigned(lbl_805DAC90 * w.b) << 16 | __cvt_fp2unsigned(lbl_805DAC90 * w.c) << 8) | __cvt_fp2unsigned(lbl_805DAC90 * w.d);
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
        create__10TItemEffPGFPvPv(tl_05, &prm);
    } else {
        create__10TItemEffPGFPvPvPv((void *)tl_05, &prm, (void *)item);
    }
    this->restore_action_type();
}

void TItemWeapon::fire_shot_at_target(void *origin, void *owner, s32 angle) {
    Vec_8011EB84 v;
    Atk_8011EB84 atk;
    f32 *scale;
    s32 state;
    s32 item;
    u8 *ph;
    u8 *hit;
    s32 off;
    if (((s32 (*)())is_active_in_game__11TItemWeaponFv)() != 0) {
        scale = ((f32 *(*)(void *, s32))get_weapon_range_record)(this, ((s32 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)(this->owner));
        TObjPlayer__sub_802E449C(&atk);
        ((TObjPlayer *)((u8 *)this))->fill_status_info(&atk);
        VecCopy((Vec *)&atk, (const Vec *)((Vec_8011EB84 *)origin));
        atk.angle = *(s32 *)((s8 *)(this->owner) + 0x60) + angle;
        atk.f3C = *scale;
        atk.f38 = *(f32 *)((s8 *)((u8 *)this) + 0x1E4);
        atk.owner = owner;
        atk.id = *(s32 *)((s8 *)((u8 *)this) + 0x24);
        ((Wpn_8011EB84 *)((u8 *)this))->m57(&atk);
        remap_extra_attack_type();
        hit = ((u8 *(*)(void *, void *))sub_8011E56C__11TItemWeaponFPUc)(this, ((Vec_8011EB84 *)origin));
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
    ((s32 (*)(void))remap_extra_attack_type__11TItemWeaponFv)();
    *(s16 *)((s8 *)arg1 + 0x14) = ((s16 (*)(s32))get_entity_id)(*(s32 *)&this->unk_F0);
    *(s16 *)((s8 *)arg1 + 0x16) = ((TObjBase *)(*(s32 *)&this->unk_F0))->get_room();
    *(s32 *)((s8 *)arg1 + 0x18) = ((TItem *)this)->get_item_id();
    *(f32 *)((s8 *)arg1 + 0x1C) = get_attack_accuracy_scale((s16 *)(*(s32 *)&this->unk_F0 + 0x7CC));
    *(s32 *)((s8 *)arg1 + 0x24) = (s32) is_status_subsystem_ready__10TObjPlayerFv(*(s32 *)&this->unk_F0);
    *(f32 *)((s8 *)arg1 + 0x20) = ((f32 (*)(s32))query_extended_state__10TObjPlayerFv)(*(s32 *)&this->unk_F0);
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
                    var_f31 = xyz_distance(arg1, (void *) &((Rec_8011F108 *)temp_r22_2)->pos) / *(f32 *)((s8 *)((u8 *)this) + 0x1E4);
                    if (arg4 != 0) {
                        ((void (*)(void *))remap_extra_attack_type__11TItemWeaponFv)(this);
                        hit.reserved = 0;
                        hit.kind = (s32) ((s16 (*)(void *))is_status_subsystem_ready__10TObjPlayerFv)((void *)this->owner);
                        hit.source = get_entity_id((void *)this->owner);
                        hit.target = get_entity_id(var_r29);
                        hit.weapon = ((TItem *)((u8 *)this))->get_item_id();
                        hit.collider = get_captured_target_collider_index(temp_r22_3);
                        hit.damage = ((f32 (*)(void *))query_extended_state__10TObjPlayerFv)((void *)this->owner);
                        spawn_item_attacker(tl_05, (u32)arg1, ((s32) var_f31), (u8 *)&hit.reserved);
                        var_r31 = 1;
                        this->restore_action_type();
                    }
                } else {
                    var_f31 = xyz_distance(arg1, &endpoint.x) / *(f32 *)((s8 *)((u8 *)this) + 0x1E4);
                }
            } else {
                VecCopy((Vec *)(&endpoint.x), (const Vec *)(*(u8 **)((s8 *)temp_r3_3 + 4)));
                var_f31 = xyz_distance(arg1, &endpoint.x) / *(f32 *)((s8 *)((u8 *)this) + 0x1E4);
                if ((*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3_3 + 4)) + 0x18) & 0x100) && ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x1EC) != 0U)) {
                    spawn_land_hit_effect((s32)tl_05, (u32)this, (u32)arg1, (u32)&endpoint.x, (s32)((s32) var_f31));
                }
            }
            this->spawn_light_task();
            if ((((s32 (*)(void *, void *, f32 *, f32)) *(s32 (**)(void *, void *, f32 *, f32))((s8 *)((u8 *)this) + 0x1F0)) != NULL) && (is_model_shown__5TItemFv(this) == 1)) {
                (*(s32 (**)(void *, void *, f32 *, f32))((s8 *)((u8 *)this) + 0x1F0))(this, arg1, &endpoint.x, var_f31);
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
        ((void (*)(void *))remap_extra_attack_type__11TItemWeaponFv)(this);
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
