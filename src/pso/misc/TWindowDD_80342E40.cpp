#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDD_80342E40.h"
#include "pso/misc/TWindowDD_80348D0C.h"
#include "pso/misc/TWindowDD.h"
#include "pso/TObject.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/ui/TWindowInputNumber.h"

struct W_80342ED0 {
    u8 pad0[0x20];
    s32 idx;
    s32 ids[(0xB4 - 0x24) / 4];
    s32 fb4;
    u8 padb8[0xC6 - 0xB8];
    s16 fc6;
    u8 padc8[0x104 - 0xC8];
    s32 f104;
};

extern "C" {
void TWindowDD__sub_80341AF8(u8 *arg0);
s32 open_numeric_parameter_input__9TWindowDDFPviii(void *, int, void *, void *);
s32 classify_id__9TWindowDDFs();
s32 TWindowDD__sub_80347CC8(void *, void *);
s32 get_current_child_index__9TWindowDDFv();
extern void *word_select_numeric_limits[];
s32 TWindowDD__sub_80342158(s32);
s32 TWindowDD__sub_803435A0(void *);
s32 TWindowDD__sub_80347C50();
s32 TWindowDD__sub_803482B0(void *);
s32 TWindowDD__sub_80348424(void *, s16);
s16 TWindowDD__sub_80348448(void *, s32);
s32 push_recent_id(s32);
s32 apply_entry_layout__9TWindowDDFPv(void *);
s32 update_selection_state__9TWindowDDFv();
s32 TWindowDD__sub_803484C4(void *);

void TWindowDD::update() {
    update_selection_state__9TWindowDDFv();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if ((s32) *(s32 *)((s8 *)this + 0xB0) == 1) {
            *(s32 *)((s8 *)this + 0xB4) = 0x14;
            this->m_a8 = -0x3C;
            TWindowDD__sub_803435A0(this);
            return;
        }
        TWindowDD__sub_803484C4(this);
        return;
    }
    if (TWindowDD__sub_803482B0(this) != 0) {
        TWindowDD::play_se();
        apply_entry_layout__9TWindowDDFPv(this);
    }
}

void TWindowDD::handle_confirm_input() {
    s32 id;
    W_80342ED0 *arg0 = (W_80342ED0 *)this;
    TWindowDD__sub_80347C50();
    if (((TWindowDD *)arg0)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        id = TWindowDD__sub_80342158(arg0->ids[arg0->idx]);
        arg0->fc6 = TWindowDD__sub_80348448(arg0, id);
        arg0->fb4 = TWindowDD__sub_80348424(arg0, id);
        push_recent_id(id);
        arg0->f104 = 0;
        TWindowDD__sub_803435A0(arg0);
        return;
    }
    if (TWindowDD__sub_803482B0(arg0) != 0) {
        TWindowDD::play_se();
        ((TWindowDD *)arg0)->set_state();
    }
}

u8 update_numeric_parameter_input__9TWindowDDFPv(u8 *arg0) {
    s32 temp_r3;
    s32 var_r31;
    u8 *var_r3;
    var_r31 = 0;
    if ((u32) ((TWindowDD *)arg0)->m_a0 == 0U) {
        get_current_child_index__9TWindowDDFv();
        temp_r3 = classify_id__9TWindowDDFs();
        if (temp_r3 != 7) {
            open_numeric_parameter_input__9TWindowDDFPviii(arg0, 0, word_select_numeric_limits[temp_r3], (void *) (TWindowDD__sub_80348D88(arg0 + 0xC4)));
            return 0U;
        }
        return 1U;
    }
    TWindowDD__sub_80347CC8(arg0, arg0 + 0xC4);
    if (((u32) ((TWindowDD *)arg0)->m_a0 != 0U) || (((TObject *)(*(void **)((s8 *)arg0 + 0x84)))->all_parents_unqueued_for_destruction() != 0)) {
        ((TWindowDD *)(arg0 + 0xC4))->set_field14((int) (((TShopEquipmentSellWindow *)(((TWindowDD *)arg0)->m_a0))->get_result()));
        if (((TShopEquipmentSellWindow *)(((TWindowDD *)arg0)->m_a0))->is_confirmed() != 0) {
            var_r31 = 2;
            ((TWindowDD *)(arg0 + 0xC4))->reset_index();
            ((TWindowBase *)(((TWindowDD *)arg0)->m_a0))->close();
        } else if (((TWindowInputNumber *)(((TWindowDD *)arg0)->m_a0))->is_confirmed() != 0) {
            var_r31 = 1;
            ((TWindowBase *)(((TWindowDD *)arg0)->m_a0))->close();
        }
    } else {
        var_r31 = 2;
    }
    if (var_r31 != 0) {
        var_r3 = (u8 *)(arg0 + (*(s32 *)((s8 *)arg0 + 0x20) * 4));
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
        TWindowDD__sub_80341AF8((var_r3));
        ((TWindowDD *)arg0)->m_a0 = 0U;
        *(s32 *)((s8 *)arg0 + 0xB8) = 0;
    }
    return (u8) (var_r31 == 1);
}

}
