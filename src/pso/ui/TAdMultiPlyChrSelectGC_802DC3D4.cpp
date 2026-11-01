#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DC3D4.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdChrMoveEffectGC.h"

extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 play_sound_effect(s32, s32, s32, s32);
u32 TAdMultiPlyChrSelectGC__sub_802DBE4C(void *, s32 *);
s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *);
extern s8 lbl_80472880[];
extern s8 lbl_80472888[];
extern s8 controller_physical_port_bank[];
s32 clear_entries__18TAdChrMoveEffectGCFv();

void TAdMultiPlyChrSelectGC::check_cancel_input() {
    if ((((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) || (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0)) {
        TAdPlayerLoadGC::set_state(1);
        *(s32 *)&this->unk_58 = 0;
        this->m_20 = 0x1D;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DC440(void *arg0) {
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x14) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->set_field_1c(0x1B);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x25;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x13) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x80));
            *(u32 *)((s8 *)arg0 + 0x80) = 0U;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->reset_cursor_state();
        *(s32 *)((s8 *)arg0 + 0x20) = 0x24;
    }
}

void TAdMultiPlyChrSelectGC::handle_input() {
    void *temp_r31;

    if ((u32) this->m_94 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
        this->m_94 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_68))->get_player_index() < 0xE) {
            *(s32 *)&this->unk_58 = 0;
        }
        *(s32 *)&this->m_20 = 0x1D;
        return;
    }
    temp_r31 = controller_physical_port_bank + 0x20;
    if ((TWindowShortListCtrl__check_controller_button(temp_r31, 4) != 0) || (TWindowShortListCtrl__check_controller_button(temp_r31, 2) != 0)) {
        *(s32 *)&this->m_20 = 0x1F;
    }
}
void TAdMultiPlyChrSelectGC__sub_802DC5CC(void *arg0) {
    u32 var_r30;
    u32 gs;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x94) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x94)))->close();
        *(u32 *)((s8 *)arg0 + 0x94) = 0U;
    }
    if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    var_r30 = 0U;
loop_9:
    if (swap_characters__23TAdSinglePlyChrSelectGCFii(var_r30, *(s32 *)((s8 *)arg0 + 0x38)) != 0) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x84)))->close();
            *(u32 *)((s8 *)arg0 + 0x84) = 0U;
        }
        gs = TAdMultiPlyChrSelectGC::get_global_state();
        if (gs != 0U) {
            ((TAdChrMoveEffectGC *)gs)->setup_move_effect_params(*(s32 *)((s8 *)arg0 + 0x38) - 4, var_r30 + 3);
        }
        load_tables(*(s32 *)((s8 *)arg0 + 0x38));
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_status_value(var_r30);
        *(s32 *)((s8 *)arg0 + 0x80) = TAdMultiPlyChrSelectGC__sub_802DBEC4(arg0, (s32*)lbl_80472880);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(1);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->set_cursor_index(0x11);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x23;
        return;
    }
    var_r30 += 1;
    if (var_r30 >= 4U) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(1);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x84) == 0U) {
            *(u32 *)((s8 *)arg0 + 0x84) = TAdMultiPlyChrSelectGC__sub_802DBE4C(arg0, (s32*)lbl_80472888);
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x22;
        return;
    }
    goto loop_9;
}

}
