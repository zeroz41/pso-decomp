#include "pso/TShopWindowBase.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby_80222D24.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TShopSequence.h"

#include "types.h"
#include "pso/misc/TRaderMapCore.h"

struct RecoveredGlobal_802239EC_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80223A48_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 get_entity_id(void *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
extern RecoveredGlobal_802239EC_lbl_8050E208 controller_input_state;
void __ct__7TObjectFP7TObject(void *);

void TShopWindowBase::vfunc_11() {  }

extern f32 lbl_805DC728;
extern f32 lbl_805DC72C;

f32 TShopWindowBase::get_scale() {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (TCameraCtrl::get_instance() > 2)) {
        return lbl_805DC728;
    }
    return lbl_805DC72C;
}

u16 TShopWindowBase::sub_8022397C() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    temp_r3 = *(u32 *)((s8 *)arg0 + 0x24);
    if (temp_r3 != 0U) {
        return TShopGenerator__sub_80222DAC((get_entity_id((void *)temp_r3)));
    }
    return 0U;
}

s32 TShopSequence::get_child_field1c() {
    void *temp_r3 = *(void **)((s8 *)this + 0x24);
    if (temp_r3 != NULL) {
        return get_entity_id(temp_r3);
    }
    return 0;
}

extern s32 lbl_805D55C0;

typedef char RecoveredGlobal_802239EC_lbl_8050E208_size[sizeof(RecoveredGlobal_802239EC_lbl_8050E208) == 0x1B0 ? 1 : -1];
bool TShopSequence::sub_802239EC() {
    if (*(s32 *)((s8 *)((u8 *)&controller_input_state.value + (((TRaderMapCore *)(*(s32 *)((s8 *)((u8 *)this) + 0x24)))->get_map_id() * 0x50)) + 0x28) & 2) {
        return 1;
    }
    return test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0;
}

typedef char RecoveredGlobal_80223A48_lbl_8050E208_size[sizeof(RecoveredGlobal_80223A48_lbl_8050E208) == 0x1B0 ? 1 : -1];
s32 TShopWindowBase::sub_80223A48() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)((u8 *)&(*(RecoveredGlobal_80223A48_lbl_8050E208 *)&controller_input_state).value + (((TRaderMapCore *)(*(s32 *)((s8 *)arg0 + 0x24)))->get_map_id() * 0x50)) + 0x28) & 4) {
        return 1;
    }
    if (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&(*(RecoveredGlobal_80223A48_lbl_8050E208 *)&controller_input_state).value + 0x160), 4) != 0) {
        return 1;
    }
    return 0;
}

void TShopWindowBase::run_task() {
    if ((s32) lbl_805D55C0 == 0) {
        this->vfunc_11();
    }
}

extern s32 __vt__15TShopWindowBase[];
extern void *TShopWindowBase__class_name;

}
TShopWindowBase::~TShopWindowBase() {

}


void *__ct__15TShopWindowBaseFv(void *shop_window_base) {
    __ct__7TObjectFP7TObject(shop_window_base);
    *(s32 **)((s8 *)shop_window_base + 0x18) = __vt__15TShopWindowBase;
    *(void * *)&((TShopWindowBase *)shop_window_base)->m_name = TShopWindowBase__class_name;
    *(u32 *)((s8 *)shop_window_base + 0x1C) = 0;
    *(u32 *)((s8 *)shop_window_base + 0x20) = 0;
    *(u32 *)((s8 *)shop_window_base + 0x24) = 0;
    return shop_window_base;
}

