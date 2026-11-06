#include "types.h"
#include "pso/weapon/TUnk_804A3738.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/unk/text_80127EE8.h"
#include "pso/system/task/TMainTask.h"

// The timer event class (0x804A0688) has no real constructor yet.
extern "C" s32 ct__13TUnk_804A0688Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);

void TUnk_804A3738::vfunc_57() {
    void *event;

    if (effect_objects != NULL) {
        event = TItemHeapObject::operator new(0x30);
        if (event != NULL) {
            confusion_curse_timer_ct((u8 *)event, (s32)effect_objects, get_owner_client(), 0xE10, 0.25f);
        }
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 0x5A);
        }
    }
}

TUnk_804A3738::~TUnk_804A3738() {}

TUnk_804A3738::TUnk_804A3738(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *yamigarasu_create(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A3738(tl_05, item);
    }
    return NULL;
}

extern "C" {
u8 *TItemTimerEvent__ct(void *, s32, u16, s32);
}
extern s32 lbl_804A0588[];

u8 *confusion_curse_timer_ct(u8 *event, s32 effect_objects, u16 owner_client, s32 frames, f32 rate) {
    TItemTimerEvent__ct(event, effect_objects, owner_client, frames);
    *(s32 **)((s8 *)event + 0x18) = lbl_804A0588;
    *(f32 *)((s8 *)event + 0x2C) = rate;
    return event;
}
