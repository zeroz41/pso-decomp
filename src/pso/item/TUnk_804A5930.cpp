#include "pso/item/TItemData.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A5930.h"
#include "types.h"
#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_8012D4C0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012D5C8.h"
#include "pso/unk/text_8012D65C.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/item/TUnk_804A5A28.h"
#include "pso/TItemAttacker.h"

void TUnk_804A5930::use() {
    s32 arg0 = (s32)this;
    TItemData item_data;
    if (((TItem *)arg0)->get_kill_count() >= 0x59D8U) {
        item_data.data1.data_u8[0] = 0;
        item_data.data1.data_u8[1] = 0x32;
        item_data.data1.data_u8[2] = 0;
        replace_item_with_new_code(&item_data, (TItem *)arg0);
    }
}

extern "C" {

s32 get_owner_client__5TItemFv(void *);
u16 get_kill_count__5TItemFv(void *);
s32 set_kill_count__5TItemFUs(void *, u16);
s32 slow_curse_timer_ct(s32 arg0, u32 arg1, s32 arg2, s32 duration, f32 farg0);
s32 __nw__15TItemHeapObjectFUl(s32);

void TObjPlayer::update_weapon_kill_count() {
    if ((s16) *(s16 *)&this->unk_1F8 < ((TObjPlayer *)(*(s32 *)&this->blend.frame[1]))->get_kill_count()) {
        set_kill_count__5TItemFUs(this, (u16) (get_kill_count__5TItemFv(this) + 1));
        *(s16 *)&this->unk_1F8 = ((TObjPlayer *)(*(s32 *)&this->blend.frame[1]))->get_kill_count();
    }
    if ((get_kill_count__5TItemFv(this) >= 0x59D8U) && (((TItem *)this)->test_item_flags(0x200) == 0U)) {
        ((TItem *)this)->add_item_flags(0x200);
    }
}
}


void sealed_j_sword_start_timers(void *item_pro_armor) {
    s32 temp_r3;

    if ((u32) ((TItemProArmor *)item_pro_armor)->effect_objects != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3 != 0) {
            slow_curse_timer_ct(temp_r3, (u32)((TItemProArmor *)item_pro_armor)->effect_objects, get_owner_client__5TItemFv(item_pro_armor), 0xE10, 0.25f);
        }
    }
    *(s16 *)((s8 *)item_pro_armor + 0x1F8) = ((TItemProArmor *)item_pro_armor)->owner->get_kill_count();
}

extern s32 lbl_804A5930[];

void *__dt__13TUnk_804A5930Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5930;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *, s32, u8 *);

extern s32 lbl_804A5930[];

void *TObjPlayer__sub_8012D620(void *arg0, s32 parent, u8 *item) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, parent, item);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5930;
    return arg0;
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *sealed_j_sword_create(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_8012D620(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

s16 TObjPlayer::get_kill_count() { return this->m_11a; }

struct RecoveredGlobal_8012D6BC_lbl_804A05A8 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * TItemTimerEvent__ct(s32, u32, s32, s32);
extern RecoveredGlobal_8012D6BC_lbl_804A05A8 lbl_804A05A8;

s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
void init_slicer_launch_state(void *arg0);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
}
void enlarge_flight_cutter_slicer(void *arg0);
typedef char RecoveredGlobal_8012D6BC_lbl_804A05A8_size[sizeof(RecoveredGlobal_8012D6BC_lbl_804A05A8) == 0x20 ? 1 : -1];

s32 slow_curse_timer_ct(s32 arg0, u32 arg1, s32 arg2, s32 duration, f32 farg0) {
    TItemTimerEvent__ct(arg0, arg1, arg2, duration);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A05A8.value;
    *(f32 *)((s8 *)arg0 + 0x2C) = farg0;
    return arg0;
}
