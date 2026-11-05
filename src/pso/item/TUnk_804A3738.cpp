#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_80127DC4.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A3738.h"
#include "pso/unk/text_80127EE8.h"
#include "pso/item/TUnk_804A3830.h"

extern "C" {

s32 get_owner_client__5TItemFv(void *);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 ct__13TUnk_804A0688Fv(s32, u32, s32, s32);
}


void yamigarasu_start_timers(void *item_pro_armor) {
    s32 temp_r3;
    s32 temp_r3_2;

    if ((u32) ((TItemProArmor *)item_pro_armor)->effect_objects != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3 != 0) {
            confusion_curse_timer_ct((u8 *)temp_r3, (s32)((TItemProArmor *)item_pro_armor)->effect_objects, ((TItem *)item_pro_armor)->get_owner_client(), 0xE10, 0.25f);
        }
        temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3_2 != 0) {
            ct__13TUnk_804A0688Fv(temp_r3_2, (u32)((TItemProArmor *)item_pro_armor)->effect_objects, get_owner_client__5TItemFv(item_pro_armor), 0x5A);
        }
    }
}

extern s32 lbl_804A3738[];

void *__dt__13TUnk_804A3738Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3738;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A3738::init_vtable_804A3738() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3738;
    return this;
}

}

struct RecoveredGlobal_80127F40_lbl_804A0588 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * init_vtable_804A3738__13TUnk_804A3738Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TItemTimerEvent__ct(void *, s32, u16, s32);
}
extern RecoveredGlobal_80127F40_lbl_804A0588 lbl_804A0588;

u8 *yamigarasu_create(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_vtable_804A3738__13TUnk_804A3738Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

typedef char RecoveredGlobal_80127F40_lbl_804A0588_size[sizeof(RecoveredGlobal_80127F40_lbl_804A0588) == 0x20 ? 1 : -1];

u8 *confusion_curse_timer_ct(u8 *event, s32 effect_objects, u16 owner_client, s32 frames, f32 rate) {
    TItemTimerEvent__ct(event, effect_objects, owner_client, frames);
    *(s32 **)((s8 *)event + 0x18) = &lbl_804A0588.value;
    *(f32 *)((s8 *)event + 0x2C) = rate;
    return event;
}

