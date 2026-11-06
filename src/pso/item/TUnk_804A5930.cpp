#include "pso/item/TItemData.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A5930.h"
#include "types.h"
#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProArmor.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/item/TUnk_804A5A28.h"
#include "pso/item/TItemAttacker.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/TMainTask.h"

void TUnk_804A5930::use() {
    TItemData item_data;
    if (get_kill_count() >= 0x59D8U) {
        item_data.data1.data_u8[0] = 0;
        item_data.data1.data_u8[1] = 0x32;
        item_data.data1.data_u8[2] = 0;
        replace_item_with_new_code(&item_data, this);
    }
}

void TUnk_804A5930::update_weapon() {
    if (kill_count_seen < owner->get_kill_count()) {
        set_kill_count(get_kill_count() + 1);
        kill_count_seen = owner->get_kill_count();
    }
    if (get_kill_count() >= 0x59D8U && test_item_flags(0x200) == 0) {
        add_item_flags(0x200);
    }
}

void TUnk_804A5930::vfunc_57() {
    void *event;

    if (effect_objects != NULL) {
        event = TItemHeapObject::operator new(0x30);
        if (event != NULL) {
            slow_curse_timer_ct((s32)event, (u32)effect_objects, get_owner_client(), 0xE10, 0.25f);
        }
    }
    kill_count_seen = owner->get_kill_count();
}

TUnk_804A5930::~TUnk_804A5930() {}

TUnk_804A5930::TUnk_804A5930(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *sealed_j_sword_create(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5930(tl_05, item);
    }
    return NULL;
}

s16 TObjPlayer::get_kill_count() { return this->m_11a; }

struct RecoveredGlobal_8012D6BC_lbl_804A05A8 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * TItemTimerEvent__ct(s32, u32, u16, s32);
extern RecoveredGlobal_8012D6BC_lbl_804A05A8 lbl_804A05A8;
}
typedef char RecoveredGlobal_8012D6BC_lbl_804A05A8_size[sizeof(RecoveredGlobal_8012D6BC_lbl_804A05A8) == 0x20 ? 1 : -1];

s32 slow_curse_timer_ct(s32 event, u32 effect_objects, u16 owner_client, s32 duration, f32 rate) {
    TItemTimerEvent__ct(event, effect_objects, owner_client, duration);
    *(s32 **)((s8 *)event + 0x18) = &lbl_804A05A8.value;
    *(f32 *)((s8 *)event + 0x2C) = rate;
    return event;
}
