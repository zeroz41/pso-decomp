#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_8049FED0.h"
#include "pso/item/TUnk_8049FE00.h"
#include "pso/item/TUnk_8049FEB8.h"
#include "pso/item/TItemProArmor.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TItem.h"

struct RecoveredGlobal_8011751C_lbl_8049FEB8 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern int tl_05;
u16 obj_getField1c(void *);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_8049FEB8[];
u8 *TItemProArmor__sub_8011751C(u8 *arg0, u8 *arg1, u8 *arg2);
void *__dt__13TUnk_8049FED0Fv(void *arg0, s16 arg1);
void create__13TItemProArmorFiUi(s32 arg0, u32 arg1);
void TItemObject__ct(void *);
void *get_player_by_client_id(s32 i);
s32 __dl__7TObjectFPv(void *);
void *__dt__11TItemObjectFv(void *arg0, s16 arg1);
s32 __dt__7TObjectFv(void *, s32);
void *__nw__7TObjectFUl(s32);
void queue_destruction__7TObjectFv(void *arg0);

extern s32 lbl_8049FE00[];

void *TUnk_8049FE00::construct(void *_w1, void *_w2) {
    TItemObject__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_8049FE00;
    return this;
}

u8 *TItemProArmor::create() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x104));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_8049FE00 *)temp_r3)->construct((void *)((void *)((*(s32 *)&tl_05))), arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_8049FEB8::run_task() {
    s32 temp_r3;

    if (get_player_by_client_id(*(u16 *)&this->unk_1C) == 0U) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    temp_r3 = this->m_1e;
    if (temp_r3 == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    this->m_1e = (temp_r3 - 1);
}

void *TUnk_8049FEB8::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_8049FEB8;
        TItemTimerEvent::clear_timer_slot(*(u16 *)&(this->unk_1C));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

typedef char RecoveredGlobal_8011751C_lbl_8049FEB8_size[sizeof(RecoveredGlobal_8011751C_lbl_8049FEB8) == 0x18 ? 1 : -1];
u8 *TItemProArmor__sub_8011751C(u8 *arg0, u8 *arg1, u8 *arg2) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8011751C_lbl_8049FEB8 *)&lbl_8049FEB8).value;
    *(u16 *)((s8 *)arg0 + 0x1C) = obj_getField1c(arg2);
    TItemTimerEvent::start_event_by_index(*(u16 *)((s8 *)arg0 + 0x1C));
    ((TUnk_8049FEB8 *)arg0)->m_1e = 3;
    return arg0;
}

void create__13TItemProArmorFiUi(s32 arg0, u32 arg1) {
    void *temp_r3;
    if ((arg0 != 0) && (arg1 != 0U)) {
        temp_r3 = __nw__7TObjectFUl(0x20);
        if (temp_r3 != NULL) {
            TItemProArmor__sub_8011751C((u8 *)temp_r3, (u8 *)arg0, (u8 *)arg1);
        }
    }
}

void TUnk_8049FED0::vfunc_44() { create__13TItemProArmorFiUi(tl_05, (u32)this->owner); }

extern s32 lbl_8049FED0[];

void *__dt__13TUnk_8049FED0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8049FED0;
        __dt__11TItemObjectFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
