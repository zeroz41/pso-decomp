#include "types.h"
#include "pso/player/TUnk_804A5E20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012EA50.h"
#include "pso/item/TItem.h"

struct VBase_18_8622c5 { char pad[0x18]; };

struct VObj_18_8622c5 : VBase_18_8622c5 {
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
    virtual s32 m49(s32 *, s32, s32, s32);
};

struct RecoveredGlobal_8012E83C_lbl_8043E9C0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
extern RecoveredGlobal_8012E83C_lbl_8043E9C0 five_joint_shot_angle_table;
typedef char RecoveredGlobal_8012E83C_lbl_8043E9C0_size[sizeof(RecoveredGlobal_8012E83C_lbl_8043E9C0) == 0x18 ? 1 : -1];
void TUnk_804A5E20::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 0, *(s32 *)((s8 *)&five_joint_shot_angle_table.value + 0), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 1, *(s32 *)((s8 *)&five_joint_shot_angle_table.value + 4), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 2, *(s32 *)((s8 *)&five_joint_shot_angle_table.value + 8), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 3, *(s32 *)((s8 *)&five_joint_shot_angle_table.value + 0xC), 1);
    ((TItemWeapon *)arg0)->get_joint_position(1, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 4, *(s32 *)((s8 *)&five_joint_shot_angle_table.value + 0x10), 1);
}

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A5E20[];
extern s32 spawn_target_needle[];
extern s32 spawn_needle_wall_impact[];
extern s32 create_shoot_model__10TObjPlayerFUiiif[];

void *TUnk_804A5E20::init_state_2() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A5E20;
    set_weapon_flags(2);
    (*(s32 * *)((u8 *)this + 0x1F4)) = spawn_target_needle;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_needle_wall_impact;
    *(s32 **)((s8 *)this + 0x1F0) = create_shoot_model__10TObjPlayerFUiiif;
    return this;
}

}

extern "C" {
u8 * init_state_2__13TUnk_804A5E20Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_init_state_2(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_state_2__13TUnk_804A5E20Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 __vt__13TUnk_804A5E20[];

TUnk_804A5E20::~TUnk_804A5E20() {}
