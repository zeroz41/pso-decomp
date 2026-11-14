#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ECFB0.h"
#include "pso/weapon/TUnk_804A2960.h"
#include "pso/unk/text_80127EE8.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
u8 *TItemTimerEvent__ct(void *, s32, u16, s32);
extern void *lbl_804A0568[8];
}

void TUnk_804ECFB0::update_weapon() {
    s16 lost;
    s16 tp;
    s32 half;

    if (is_current_area_item_enabled() != 0) {
        tp = get_actor_tp(owner);
        lost = owner_tp - tp;
        if (lost != 0) {
            owner_tp = tp;
        }
        if (lost > 0) {
            half = lost / 2;
            TObjectV8047c128_subtract_hp((u8 *)owner, (s16)half);
            add_actor_tp((u8 *)owner, (s16)half);
        }
    }
    pad_1f8 = pad_1f8 + 1;
}

void TUnk_804ECFB0::vfunc_58() {
    owner_tp = -1;
    pad_1f8 = 0;
}

// Starts the freeze, confusion and paralysis curse timers (was dark_bridge_start_timers).
void TUnk_804ECFB0::vfunc_57() {
    u8 *event;

    owner_tp = get_actor_tp(owner);
    pad_1f8 = 0;
    if (effect_objects != NULL) {
        event = (u8 *)TItemHeapObject::operator new(0x30);
        if (event != NULL) {
            freeze_curse_timer_ct(event, (s32)effect_objects, get_owner_client(), 9000, 0.5f);
        }
        event = (u8 *)TItemHeapObject::operator new(0x30);
        if (event != NULL) {
            confusion_curse_timer_ct(event, (s32)effect_objects, get_owner_client(), 9000, 0.5f);
        }
        event = (u8 *)TItemHeapObject::operator new(0x30);
        if (event != NULL) {
            paralysis_curse_timer_ct(event, (s32)effect_objects, get_owner_client(), 9000, 0.5f);
        }
    }
}

TUnk_804ECFB0::~TUnk_804ECFB0() {}

TUnk_804ECFB0::TUnk_804ECFB0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    owner_tp = -1;
    pad_1f8 = 0;
}

u8 *dark_bridge_create(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804ECFB0(tl_05, arg0);
    }
    return NULL;
}

u8 *paralysis_curse_timer_ct(u8 *event, s32 effect_objects, u16 owner_client, s32 frames, f32 rate) {
    TItemTimerEvent__ct(event, effect_objects, owner_client, frames);
    *(void ***)((s8 *)event + 0x18) = lbl_804A0568;
    *(f32 *)((s8 *)event + 0x2C) = rate;
    return event;
}
