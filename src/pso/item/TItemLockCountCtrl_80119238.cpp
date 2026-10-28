#include "types.h"
#include "pso/unk/text_8011085C.h"
#include "pso/item/TItemLockCountCtrl_80119238.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/TItemLockCountCtrl.h"

struct Base_801193D8 { char pad[0x18]; };

struct VObj_801193D8 : Base_801193D8 {
    virtual void m0(s32);
};

// The lock-counted item effects (TItemLockCountCtrl objects), one per effect.
extern VObj_801193D8 *item_effect_object_table[7];
extern "C" {
void *TItemLockCountCtrl__ct(void *, s32, s32, void (*)(int), void (*)(int));
void *__nw__7TObjectFUl(u32);
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

extern "C" {
void TItemEquipBase__sub_80119100(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(0x20);
    }
}
}

void notify_stealth_enemies_10(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(0x10);
    }
}

extern "C" {
void TItemEquipBase__sub_80119168(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(8);
    }
}

void TItemEquipBase__sub_8011919C(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(4);
    }
}

void TItemEquipBase__sub_801191D0(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(2);
    }
}

void fn_80119204(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5864(1);
    }
}

void TItemLockCountCtrl__sub_80119238(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TUnk_804B9870 *)temp)->obj_clearFlags30(0x40);
    }
}

void TItemLockCountCtrl__sub_8011926C(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(0x20);
    }
}

void TItemLockCountCtrl__sub_801192A0(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(0x10);
    }
}
}

void notify_stealth_enemies_08(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(8);
    }
}

void apply_battle_ctrl_effect(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(4);
    }
}

void TItemLockCountCtrl__sub_8011933C(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        ((TObjEneDD_ST *)temp)->sub_800F5874(2);
    }
}

void TItemLockCountCtrl::apply_unit_immunity(int arg0) {
    u32 temp = get_player_by_client_id(arg0);
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
    p = __nw__7TObjectFUl(0x2C);                                 \
    if (p != 0) {                                                \
        p = TItemLockCountCtrl__ct(p, 0, 0xC, a, b);             \
    }                                                            \
    item_effect_object_table[idx] = (VObj_801193D8 *)p;
void TItemLockCountCtrl::init_effect_table() {
    void *p;
    MK_80119444(0, TItemLockCountCtrl::set_battle_ctrl_flag30, TItemLockCountCtrl__sub_80119238)
    MK_80119444(1, TItemLockCountCtrl::apply_unit_immunity, fn_80119204)
    MK_80119444(2, TItemLockCountCtrl__sub_8011933C, TItemEquipBase__sub_801191D0)
    MK_80119444(3, apply_battle_ctrl_effect, TItemEquipBase__sub_8011919C)
    MK_80119444(4, notify_stealth_enemies_08, TItemEquipBase__sub_80119168)
    MK_80119444(5, TItemLockCountCtrl__sub_801192A0, notify_stealth_enemies_10)
    MK_80119444(6, TItemLockCountCtrl__sub_8011926C, TItemEquipBase__sub_80119100)
}
