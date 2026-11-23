#include "types.h"
#include "pso/unk/text_8011085C.h"
#include "pso/item/TItemLockCountCtrl_80119238.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

struct Base_801193D8 { char pad[0x18]; };

struct VObj_801193D8 : Base_801193D8 {
    virtual void m0(s32);
};

// The lock-counted item effects (TItemLockCountCtrl objects), one per effect.
VObj_801193D8 *item_effect_object_table[7];

// Releases client's hold on item effect `effect`; the last release stops it.
void TItemLockCountCtrl::unlock_effect(u16 client, u32 effect) {
    VObj_801193D8 *ctrl;
    if ((client < 12) && (effect < 7)) {
        ctrl = item_effect_object_table[effect];
        if (ctrl != NULL) {
            fn_8011085C((u8 *)ctrl, client);
        }
    }
}

// Takes a hold on item effect `effect` for client; the first hold starts it.
void TItemLockCountCtrl::lock_effect(u16 client, u32 effect) {
    VObj_801193D8 *ctrl;
    if ((client < 12) && (effect < 7)) {
        ctrl = item_effect_object_table[effect];
        if (ctrl != NULL) {
            fn_801108C8((u8 *)ctrl, client);
        }
    }
}


void remove_freeze_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(0x20);
    }
}

void remove_confusion_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(0x10);
    }
}


void remove_slow_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(8);
    }
}

void remove_shock_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(4);
    }
}

void remove_paralysis_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(2);
    }
}

void remove_poison_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(1);
    }
}

void remove_status_cleanse(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjBase *)temp)->clear_actor_flags(0x40);
    }
}

void add_freeze_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(0x20);
    }
}

void add_confusion_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(0x10);
    }
}

void add_slow_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(8);
    }
}

void add_shock_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(4);
    }
}

void add_paralysis_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(2);
    }
}

void TItemLockCountCtrl::add_poison_immunity(int client) {
    uaddr temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(1);
    }
}

void TItemLockCountCtrl::add_status_cleanse(int client) {
    u32 temp = (uaddr)get_player_by_client_id((u16)client);
    if (temp != 0U) {
        ((TObjBase *)(saddr)temp)->set_actor_flags(0x40);
    }
}
void TItemLockCountCtrl::free_all() {
    s32 i;
    for (i = 0; i != 7; i++) {
        if (item_effect_object_table[i] != 0) {
            item_effect_object_table[i]->m0(1);
        }
        item_effect_object_table[i] = 0;
    }
}
#define MK_80119444(idx, a, b)                                   \
    item_effect_object_table[idx] = (VObj_801193D8 *)new TItemLockCountCtrl(0, 0xC, a, b);
void TItemLockCountCtrl::init_effect_table() {
    MK_80119444(0, TItemLockCountCtrl::add_status_cleanse, remove_status_cleanse)
    MK_80119444(1, TItemLockCountCtrl::add_poison_immunity, remove_poison_immunity)
    MK_80119444(2, add_paralysis_immunity, remove_paralysis_immunity)
    MK_80119444(3, add_shock_immunity, remove_shock_immunity)
    MK_80119444(4, add_slow_immunity, remove_slow_immunity)
    MK_80119444(5, add_confusion_immunity, remove_confusion_immunity)
    MK_80119444(6, add_freeze_immunity, remove_freeze_immunity)
}
