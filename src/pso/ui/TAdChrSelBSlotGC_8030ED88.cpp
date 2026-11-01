#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdChrSelBSlotGC_8030E354.h"
#include "pso/ui/TAdChrSelBSlotGC_8030ED88.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/TAdChrSelMovePlateGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TAdPlyChrSelPlateGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/ui/TAdChrSelBSlotGC.h"
#include "pso/ui/TAdChrSelSlotGC.h"
#include "pso/ui/TAdMcSelectGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"

extern "C" {
s32 get_state_result__22TAdMultiPlyChrSelectGCFv();
s32 get_global_state__16TAdChrSelBSlotGCFv(void *);
u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *arg0, s32 kind, s32 text);
s32 TAdChrSelASlotGC__sub_8030C4F8(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelASlotGC__sub_8030C5C0(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelASlotGC__sub_8030C688(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelSlotGC__sub_802C7498(s32, s32);
u32 create_draw_line_ctrl__13TAdMcSelectGCFiif(void *, s32, f32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 TAdPlayerLoadGC__sub_801E24F8(s32, s32, s32, s32, s32);
s32 TAdSubPlyItemGC__sub_802D6D88(s32);

void update_slot_state__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = 0U;
    }
    if ((u32) (TAdPlayerLoadGC__sub_801E1B50(1) + 0x10000) != 0xFFFFU) {
        if ((((TAdPlayerLoadGC *)1)->check_card_result_code() != 0) && (TAdPlayerLoadGC__sub_801E1B50(1) == 0)) {
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_74 = TAdChrSelASlotGC__sub_8030C688((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xA;
            return;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c = TAdChrSelASlotGC__sub_8030C4F8((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xB;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
    }
}

void update_card_select__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {

    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x6C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = 0U;
    }
    if (((TWindowMessageYesNo *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->get_slot_or_neg1()) {
        case 1:
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        case 0:
            if (TAdPlayerLoadGC__sub_801E24F8(1, 0, 0, 0, 0) == 0) {
                ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 9;
                return;
            }
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c = TAdChrSelASlotGC__sub_8030C4F8((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xB;
            return;
        }
    } else {
        if (((TWindowSubComCard *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->get_card_data() != 0) {
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        }
        if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
            if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
                *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
            }
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        }
    }
}

void TAdChrSelBSlotGC__sub_8030EF74(void *ad_chr_sel_b_slot_gc) {
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x6C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = 0U;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) == 0U) && (TAdChrSelBSlotGC::get_global_slot_data() != 0U)) {
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) = TAdChrSelASlotGC__sub_8030C5C0((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
    }
}

void update_card_confirm__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {
    s32 var_r31;

    if (((TWindowMessageYesNo *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c))->get_slot_or_neg1()) {
        case 1:
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        case 0:
            if (((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) == 0U) && (TAdChrSelBSlotGC::get_global_slot_data() != 0U)) {
                if (TAdMultiPlyChrSelectGC::get_state() != 0U) {
                    TAdMultiPlyChrSelectGC::get_state();
                    var_r31 = get_state_result__22TAdMultiPlyChrSelectGCFv();
                } else {
                    var_r31 = 0;
                }
                *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = ((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()))->open_confirm_message(1, var_r31);
                ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 8;
                return;
            }
            break;
        }
    } else {
        if (((TWindowSubComCard *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c))->get_card_data() != 0) {
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        }
        if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
            if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
                *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
            }
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        }
    }
}

void TAdChrSelBSlotGC__sub_8030F13C(u8 *ad_chr_sel_b_slot_gc) {
    s32 var_r31;
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x11) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x50)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xC;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c == 0U) && (TAdChrSelBSlotGC::get_global_slot_data() != 0U)) {
        if (TAdMultiPlyChrSelectGC::get_state() != 0U) {
            TAdMultiPlyChrSelectGC::get_state();
            var_r31 = get_state_result__22TAdMultiPlyChrSelectGCFv();
        } else {
            var_r31 = 0;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = ((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()))->create_message_window(1, var_r31);
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 6;
    }
}

void TAdChrSelBSlotGC__sub_8030F228(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x10) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x4C)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 5;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)((void *)(((s32)TAdChrSelBSlotGC::get_global_slot_data()))), 1, 7);
    }
}

void TAdChrSelBSlotGC__sub_8030F2E4(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0xF) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x48)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 4;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)((void *)(((s32)TAdChrSelBSlotGC::get_global_slot_data()))), 1, 5);
    }
}

void TAdChrSelBSlotGC__sub_8030F3A0(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0xE) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x44)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 3;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)((void *)(((s32)TAdChrSelBSlotGC::get_global_slot_data()))), 1, 3);
    }
}

void close_windows__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x44)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x48)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x4C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x6C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_74 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x74)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_74 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x78)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x7C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x50)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x54)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x58)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x5C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x60)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x64)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x68)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) = 0U;
    }
    ((TAdPlyChrSelPlateGC *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_2c))->reset_selection_slots();
    TAdSubPlyItemGC__sub_802D6D88(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x30));
    ((TAdChrSelMovePlateGC *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x34)))->clear_entries();
    TAdChrSelSlotGC__sub_802C7498(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x28), 2);
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0xD) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 2;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 = 0;
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 1);
    }
}

extern s32 lbl_80475910[];
extern const f32 lbl_805DF220;

void reset_windows__16TAdChrSelBSlotGCFPv(void *ad_mc_select_gc) {
    ((TAdChrSelSlotGC *)(((TAdMcSelectGC *)ad_mc_select_gc)->m_28))->reset_all_slots();
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x38) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)ad_mc_select_gc + 0x38));
        *(u32 *)((s8 *)ad_mc_select_gc + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x3C) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)ad_mc_select_gc + 0x3C));
        *(u32 *)((s8 *)ad_mc_select_gc + 0x3C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x40) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x40)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x40) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x44) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x44)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x44) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x48) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x48)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x48) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x4C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x4C)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x4C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x50) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x50)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x50) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x54) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x54)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x54) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x58) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x58)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x58) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x5C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x5C)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x5C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x60) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x60)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x60) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x64) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x64)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x64) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x68) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x68)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x68) = 0U;
    }
    ((TAdPlyChrSelPlateGC *)(((TAdMcSelectGC *)ad_mc_select_gc)->m_2c))->reset_selection_slots();
    TAdSubPlyItemGC__sub_802D6D88(((TAdMcSelectGC *)ad_mc_select_gc)->m_30);
    ((TAdMcSelectGC *)(((TAdMcSelectGC *)ad_mc_select_gc)->m_28))->init_slot(1, lbl_80475910);
    *(u32 *)((s8 *)ad_mc_select_gc + 0x38) = create_draw_line_ctrl__13TAdMcSelectGCFiif(ad_mc_select_gc, 0xE, lbl_805DF220);
    *(u32 *)((s8 *)ad_mc_select_gc + 0x3C) = create_draw_line_ctrl__13TAdMcSelectGCFiif(ad_mc_select_gc, 0x15, lbl_805DF220);
    ((TAdMcSelectGC *)ad_mc_select_gc)->m_24 = -1;
    ((TAdMcSelectGC *)ad_mc_select_gc)->m_1c = 1;
}

struct C_8030F874 {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
    s32 f24;
};
typedef void (C_8030F874::*Pmf_8030F874)();

extern "C" void TAdChrSelBSlotGC__sub_8030E624(TAdChrSelBSlotGC *self);
extern "C" void reset_plate_positions__16TAdChrSelBSlotGCFv();
extern "C" void check_cancel_and_close__16TAdChrSelBSlotGCFv();
extern "C" void enter_state17__16TAdChrSelBSlotGCFv();
extern "C" void init__16TAdChrSelBSlotGCFv();
extern "C" void reset_load_state__16TAdChrSelBSlotGCFv();
extern "C" void reset_slot_state__16TAdChrSelBSlotGCFv();
extern "C" void set_load_state__16TAdChrSelBSlotGCFv();
extern "C" void set_state_confirm__16TAdChrSelBSlotGCFv();
extern "C" void update_load_state__16TAdChrSelBSlotGCFv();
void *lbl_804E7A48[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_windows__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7A54[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&close_windows__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7A60[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F3A0,
};
void *lbl_804E7A6C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F2E4,
};
void *lbl_804E7A78[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F228,
};
void *lbl_804E7A84[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F13C,
};
void *lbl_804E7A90[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_confirm__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7A9C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EF74,
};
void *lbl_804E7AA8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_select__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7AB4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_slot_state__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7AC0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&check_cancel_and_close__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7ACC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EBD0,
};
void *lbl_804E7AD8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EB14,
};
void *lbl_804E7AE4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EA58,
};
void *lbl_804E7AF0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E99C,
};
void *lbl_804E7AFC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E8E0,
};
void *lbl_804E7B08[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E824,
};
void *lbl_804E7B14[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E768,
};
void *lbl_804E7B20[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_plate_positions__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B2C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E624,
};
void *lbl_804E7B38[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E620,
};
void *lbl_804E7B44[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&enter_state17__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B50[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_state_confirm__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B5C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_load_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B68[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E550,
};
void *lbl_804E7B74[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_slot_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B80[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_load_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B8C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&init__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B98[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_load_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7BA4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E458,
};
void *lbl_804E7BB0[90] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

int TAdChrSelBSlotGC__global_state;

void run_task__16TAdChrSelBSlotGCFv(C_8030F874 *self) {
    static s8 init;
    if (self->f1C < 0 || self->f1C >= 30) {
        self->f1C = 1;
    }
    self->f20 = self->f1C;
    if (get_global_state__16TAdChrSelBSlotGCFv(self) <= 0xD && self->f1C > 1) {
        self->f1C = 1;
    }
    if (!init) {
        ((Pmf_8030F874 *)lbl_804E7BB0)[0] = *(Pmf_8030F874 *)lbl_804E7A48;
        ((Pmf_8030F874 *)lbl_804E7BB0)[1] = *(Pmf_8030F874 *)lbl_804E7A54;
        ((Pmf_8030F874 *)lbl_804E7BB0)[2] = *(Pmf_8030F874 *)lbl_804E7A60;
        ((Pmf_8030F874 *)lbl_804E7BB0)[3] = *(Pmf_8030F874 *)lbl_804E7A6C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[4] = *(Pmf_8030F874 *)lbl_804E7A78;
        ((Pmf_8030F874 *)lbl_804E7BB0)[5] = *(Pmf_8030F874 *)lbl_804E7A84;
        ((Pmf_8030F874 *)lbl_804E7BB0)[6] = *(Pmf_8030F874 *)lbl_804E7A90;
        ((Pmf_8030F874 *)lbl_804E7BB0)[7] = *(Pmf_8030F874 *)lbl_804E7A9C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[8] = *(Pmf_8030F874 *)lbl_804E7AA8;
        ((Pmf_8030F874 *)lbl_804E7BB0)[9] = *(Pmf_8030F874 *)lbl_804E7AB4;
        ((Pmf_8030F874 *)lbl_804E7BB0)[10] = *(Pmf_8030F874 *)lbl_804E7AC0;
        ((Pmf_8030F874 *)lbl_804E7BB0)[11] = *(Pmf_8030F874 *)lbl_804E7ACC;
        ((Pmf_8030F874 *)lbl_804E7BB0)[12] = *(Pmf_8030F874 *)lbl_804E7AD8;
        ((Pmf_8030F874 *)lbl_804E7BB0)[13] = *(Pmf_8030F874 *)lbl_804E7AE4;
        ((Pmf_8030F874 *)lbl_804E7BB0)[14] = *(Pmf_8030F874 *)lbl_804E7AF0;
        ((Pmf_8030F874 *)lbl_804E7BB0)[15] = *(Pmf_8030F874 *)lbl_804E7AFC;
        ((Pmf_8030F874 *)lbl_804E7BB0)[16] = *(Pmf_8030F874 *)lbl_804E7B08;
        ((Pmf_8030F874 *)lbl_804E7BB0)[17] = *(Pmf_8030F874 *)lbl_804E7B14;
        ((Pmf_8030F874 *)lbl_804E7BB0)[18] = *(Pmf_8030F874 *)lbl_804E7B20;
        ((Pmf_8030F874 *)lbl_804E7BB0)[19] = *(Pmf_8030F874 *)lbl_804E7B2C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[20] = *(Pmf_8030F874 *)lbl_804E7B38;
        ((Pmf_8030F874 *)lbl_804E7BB0)[21] = *(Pmf_8030F874 *)lbl_804E7B44;
        ((Pmf_8030F874 *)lbl_804E7BB0)[22] = *(Pmf_8030F874 *)lbl_804E7B50;
        ((Pmf_8030F874 *)lbl_804E7BB0)[23] = *(Pmf_8030F874 *)lbl_804E7B5C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[24] = *(Pmf_8030F874 *)lbl_804E7B68;
        ((Pmf_8030F874 *)lbl_804E7BB0)[25] = *(Pmf_8030F874 *)lbl_804E7B74;
        ((Pmf_8030F874 *)lbl_804E7BB0)[26] = *(Pmf_8030F874 *)lbl_804E7B80;
        ((Pmf_8030F874 *)lbl_804E7BB0)[27] = *(Pmf_8030F874 *)lbl_804E7B8C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[28] = *(Pmf_8030F874 *)lbl_804E7B98;
        ((Pmf_8030F874 *)lbl_804E7BB0)[29] = *(Pmf_8030F874 *)lbl_804E7BA4;
        init = 1;
    }
    (self->*((Pmf_8030F874 *)lbl_804E7BB0)[self->f1C])();
    if (self->f1C != self->f20) {
        self->f24 = 0;
    }
    self->f24++;
}
}
