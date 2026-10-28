#include "types.h"
#include "pso/unk/text_8011892C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A0608.h"
#include "pso/item/TItemProUnit.h"
#include "pso/item/TItem.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void TItemProUnit__sub_80118FB4(void);
void TItemProUnit__sub_80118FB8(void);
f32 TItemProUnit__sub_8011901C(void* p);
void *__dt__12TItemProUnitFv(void *arg0, s16 arg1);
void TItemTimerEvent__ct(void *);

u8 *TItemProUnit::create(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1C0));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TItemProUnit__ct((TItemProUnit *)temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TItemProUnit__sub_80118FB4(void) {  }
void TItemProUnit__sub_80118FB8(void) {  }

extern s32 __vt__12TItemProUnit[];

void *__dt__12TItemProUnitFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TItemProUnit;
        __dt__14TItemEquipBaseFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TItemProUnit::set_evp(f32 v) { *(f32 *)&this->m_prev = v; }
f32 TItemProUnit__sub_8011901C(void* p) { return *(f32*)((char*)p + 0x8); }

extern s32 lbl_804A0608[];

void *TUnk_804A0608::init_timer_event() {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A0608;
    return this;
}

}
