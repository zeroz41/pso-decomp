#include "types.h"
#include "pso/unk/text_8011085C.h"
#include "pso/item/TItemLockCountCtrl_80119238.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/system/task/TObject.h"

struct Base_801193D8 { char pad[0x18]; };

struct VObj_801193D8 : Base_801193D8 {
    virtual void m0(s32);
};

// The lock-counted item effects (TItemLockCountCtrl objects), one per effect.
VObj_801193D8 *item_effect_object_table[7];
extern "C" {
u32 get_player_by_client_id(u16);
s32 obj_setFlags30(u32, s32);
}

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


void clear_stealth_enemies_flag_20(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(0x20);
    }
}

void notify_stealth_enemies_10(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(0x10);
    }
}


void clear_stealth_enemies_flag_08(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(8);
    }
}

void remove_battle_ctrl_effect(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(4);
    }
}

void clear_stealth_enemies_flag_02(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(2);
    }
}

void remove_unit_immunity(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(1);
    }
}

void clear_battle_ctrl_flag30(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjBase *)temp)->obj_clearFlags30(0x40);
    }
}

void set_stealth_enemies_flag_20(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(0x20);
    }
}

void set_stealth_enemies_flag_10(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(0x10);
    }
}

void notify_stealth_enemies_08(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(8);
    }
}

void apply_battle_ctrl_effect(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(4);
    }
}

void set_stealth_enemies_flag_02(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(2);
    }
}

void TItemLockCountCtrl::apply_unit_immunity(int arg0) {
    uaddr temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(1);
    }
}

void TItemLockCountCtrl::set_battle_ctrl_flag30(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        obj_setFlags30(temp, 0x40);
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
    MK_80119444(0, TItemLockCountCtrl::set_battle_ctrl_flag30, clear_battle_ctrl_flag30)
    MK_80119444(1, TItemLockCountCtrl::apply_unit_immunity, remove_unit_immunity)
    MK_80119444(2, set_stealth_enemies_flag_02, clear_stealth_enemies_flag_02)
    MK_80119444(3, apply_battle_ctrl_effect, remove_battle_ctrl_effect)
    MK_80119444(4, notify_stealth_enemies_08, clear_stealth_enemies_flag_08)
    MK_80119444(5, set_stealth_enemies_flag_10, notify_stealth_enemies_10)
    MK_80119444(6, set_stealth_enemies_flag_20, clear_stealth_enemies_flag_20)
}
