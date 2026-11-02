#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/item/TUnk_804A5A28.h"
#include "pso/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012D7EC.h"
#include "pso/unk/TUnk_804A5B20.h"
#include "pso/player/TObjPlayer_8012D8E4.h"

struct RecoveredGlobal_8012D6BC_lbl_804A05A8 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * TItemTimerEvent__ct(void *, s16, s32);
extern RecoveredGlobal_8012D6BC_lbl_804A05A8 lbl_804A05A8;
u8 *slow_curse_timer_ct(u8 *arg0, s16 arg1, s32 arg2, f32 farg0);
struct Owner_8012D708 { u8 pad[0x60]; s32 f60; };
struct Self_8012D708 { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_8012D708 *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };
struct Vec_8012D708 { f32 x, y, z; };
struct Tec_8012D708 {
    s16 id;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    Vec_8012D708 pos;
    Vec_8012D708 dir;
};

s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
struct SlicerState_801295FC;
void init_slicer_launch_state(void *arg0);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
}
void enlarge_flight_cutter_slicer(void *arg0);
typedef char RecoveredGlobal_8012D6BC_lbl_804A05A8_size[sizeof(RecoveredGlobal_8012D6BC_lbl_804A05A8) == 0x20 ? 1 : -1];

void TUnk_804A5A28::emit_marker_effects() {
    Tec_8012D708 tec;

    init_slicer_launch_state((SlicerState_801295FC *)&tec);
    tec.id = get_entity_id(((Self_8012D708 *)this)->owner);
    tec.fC = ((TItem *)this)->get_item_id();
    tec.f4 = ((Self_8012D708 *)this)->f24;
    tec.f8 = ((Self_8012D708 *)this)->f188;
    tec.f10 = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)((Self_8012D708 *)this)->owner + 0x7CC));
    tec.f12 = get_validated_attack_stage((u8 *)((Self_8012D708 *)this)->owner + 0x7CC);
    tec.f14 = query_extended_state__10TObjPlayerFv(((Self_8012D708 *)this)->owner);
    tec.f18 = 1.0f;
    tec.f1C = 0.0f;
    tec.f20 = 1.0f;
    tec.f24 = 0.7f;
    tec.f28 = ((Self_8012D708 *)this)->owner->f60;
    get_joint_position(3, &tec.pos);
    get_joint_position(2, &tec.dir);
    TItemAttacker::spawn_item_timer((TObject *)TTecSlicer::create((u16*)&tec), (ItemTimerCallback)enlarge_flight_cutter_slicer, 3);
}

extern s32 lbl_804A5A28[];

void *__dt__13TUnk_804A5A28Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5A28;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A5A28[];

void *TUnk_804A5A28::init_variant_2_5a28() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A5A28;
    set_weapon_flags(2);
    return this;
}

}

extern "C" {
u8 * init_variant_2_5a28__13TUnk_804A5A28Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_variant_2_5a28(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_variant_2_5a28__13TUnk_804A5A28Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern "C" {

s32 scale_current_matrix(void *);
u8 get_item_index__5TItemFv();
s32 post_translate_matrix(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
}

extern const f32 lbl_805DAF34;

void enlarge_flight_cutter_slicer(void *arg0) {
    if (arg0 != NULL) {
        *(f32 *)((s8 *)arg0 + 0x68) = (f32) lbl_805DAF34;
        *(f32 *)((s8 *)arg0 + 0x6C) = (f32) lbl_805DAF34;
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) lbl_805DAF34;
    }
}
