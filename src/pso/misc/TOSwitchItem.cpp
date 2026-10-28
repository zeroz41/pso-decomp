#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/player/TObjPlayer.h"

struct Stack_80177DC0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

struct RecoveredGlobal_801780E0___vt__12TOSwitchItem {
    s32 value;
    u8 remaining[0x6C];
};

struct Pos_80177E24 { f32 x, y, z; };

struct Obj_80177E24 { u8 pad[0x38]; Pos_80177E24 pos; };

extern "C" {
f32 newton_sqrtf(f32 x);
s32 TObjRoomId__sub_80141CF4(void *, void *);
extern const f32 lbl_805DBA10;
extern const f32 lbl_805DBA14;
void *TOKey__ct(TOKey *arg0);
extern s32 __vt__12TOSwitchItem[];
extern s32 lbl_805D3180;
u8 *TOSwitchItem__ct(u8 *arg0, s32 arg1, s32 arg2);
}
extern "C" {
f32 horizontal_distance_squared(Pos_80177E24 *, Pos_80177E24 *);
s32 is_state_ec1_ed3__10TObjPlayerFv(int);
void run_task__12TOSwitchItemFv(u8 *arg0);
void TOSwitchItem__sub_80178080(void);
void TOSwitchItem__sub_80178084(void);
void *__dt__12TOSwitchItemFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 init_switch_id__5TOKeyFv();

void TOSwitchItem::update_anim() {
    f32 temp_f0;

    init_switch_id__5TOKeyFv();
    temp_f0 = this->scale.x;
    this->m_e8 = (f32) (temp_f0 * temp_f0);
    this->m_f0 = (s32) this->set_params[1];
    if ((s32) this->m_f0 >= 8) {
        this->m_f0 = 0;
    }
    *(s32 *)&this->unk_F4 = (s32) (*(s32 *)&this->set_params[2] + 1);
}

void TOSwitchItem::render() {
    Stack_80177DC0 stack;
    if (TObjPlayer::check_demo_mode() == 1) {
        stack.sp8 = lbl_805DBA10;
        stack.spC = lbl_805DBA10;
        stack.sp10 = lbl_805DBA10;
        stack.sp14 = lbl_805DBA14;
        newton_sqrtf(this->m_e8);
        TObjRoomId__sub_80141CF4((u8 *)&this->position, &stack.sp8);
    }
}

void TOSwitchItem::debug_draw_key_id() {  }

extern void *tl_05;

#pragma opt_loop_invariants off
void run_task__12TOSwitchItemFv(u8 *switch_item) {
    s32 temp_r31;
    s32 var_r30;
    s32 var_r29;
    u8 *sorted_item_registry_entry;
    ((TOSwitchItem *)(switch_item))->update_armed_switch();
    var_r30 = 0;
    temp_r31 = get_item_registry_count();
    var_r29 = 0;
    while (var_r29 != temp_r31) {
        sorted_item_registry_entry = (u8 *)(get_sorted_item_registry_entry(var_r29));
        if ((((TItem *)sorted_item_registry_entry)->get_mode() == 0) && (horizontal_distance_squared(&((Obj_80177E24 *)sorted_item_registry_entry)->pos, &((Obj_80177E24 *)switch_item)->pos) < ((TOSwitchItem *)switch_item)->m_e8)) {
            switch (((TOSwitchItem *)switch_item)->m_f0) {
            case 0:
                var_r30 += 1;
                break;
            case 1:
                if (((TItem *)sorted_item_registry_entry)->get_item_type() == 0) {
                    var_r30 += 1;
                }
                break;
            case 2:
                if ((((TItem *)sorted_item_registry_entry)->get_item_type() == 1) && (((TItem *)sorted_item_registry_entry)->get_item_group() == 1)) {
                    var_r30 += 1;
                }
                break;
            case 3:
                if ((((TItem *)sorted_item_registry_entry)->get_item_type() == 1) && (((TItem *)sorted_item_registry_entry)->get_item_group() == 2)) {
                    var_r30 += 1;
                }
                break;
            case 4:
                if (is_state_ec1_ed3__10TObjPlayerFv((int)sorted_item_registry_entry) == 1) {
                    var_r30 += 1;
                }
                break;
            case 5:
                if (((TItem *)sorted_item_registry_entry)->get_item_type() == 2) {
                    var_r30 += 1;
                }
                break;
            case 6:
                if (((TItem *)sorted_item_registry_entry)->get_item_type() == 3) {
                    var_r30 += ((TItem *)(sorted_item_registry_entry))->get_amount();
                }
                break;
            case 7:
                if (((TItem *)sorted_item_registry_entry)->get_item_type() == 4) {
                    var_r30 += ((TItem *)sorted_item_registry_entry)->calc_price();
                }
                break;
            }
        }
        var_r29 += 1;
    }
    if ((s32) *(s32 *)((s8 *)switch_item + 0xF4) <= var_r30) {
        if ((s32) *(s32 *)((s8 *)switch_item + 0xEC) == 0) {
            *(s32 *)((s8 *)switch_item + 0xEC) = 1;
            ((TOSwitchItem *)(switch_item))->send_switch_on();
        }
    } else if ((s32) *(s32 *)((s8 *)switch_item + 0xEC) != 0) {
        *(s32 *)((s8 *)switch_item + 0xEC) = 0;
        ((TOSwitchItem *)(switch_item))->send_switch_on();
    }
}

void *TOSwitchItem::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xF8);
    if (o != NULL) {
        o = TOSwitchItem__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOSwitchItem__sub_80178080(void) {  }
void TOSwitchItem__sub_80178084(void) {  }

void *__dt__12TOSwitchItemFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOSwitchItem;
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_801780E0___vt__12TOSwitchItem_size[sizeof(RecoveredGlobal_801780E0___vt__12TOSwitchItem) == 0x70 ? 1 : -1];
u8 *TOSwitchItem__ct(u8 *switch_item, s32 arg1, s32 arg2) {
    TOKey__ct((TOKey *)(switch_item));
    *(s32 **)((s8 *)switch_item + 0x18) = &(*(RecoveredGlobal_801780E0___vt__12TOSwitchItem *)&__vt__12TOSwitchItem).value;
    *(s32 *)((s8 *)switch_item + 0) = (s32) lbl_805D3180;
    ((TOSwitchItem *)(switch_item))->apply_object_set_data((void *)arg2);
    ((TOSwitchItem *)switch_item)->update_anim();
    *(s32 *)((s8 *)switch_item + 0xEC) = 0;
    return switch_item;
}
}
