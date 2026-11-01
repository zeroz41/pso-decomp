#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/ui/TAdMultiSaveGC_802FF14C.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/ui/TAdMultiSaveGC.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32 arg0);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
extern s32 lbl_80474D90[];
extern const f32 lbl_805DEF28;
s32 update_window_mode_from_progress__6TLobbyFPv(void *, void *);
extern u8 TAdMultiSaveGC__data_80474D70[];
extern u8 TAdMultiSaveGC__data_80474D78[];
s32 verify_system_file__23TAdSinglePlyChrSelectGCFPv();
void *__nw__7TObjectFUl(u32);
extern s32 tl_fade;
int queue_destruction__7TObjectFv(void);

void TAdMultiSaveGC::queue_destruction() { queue_destruction__7TObjectFv(); TAdMultiChgGameModeGC::begin_change_game_mode(); }
s32 TAdMultiSaveGC__sub_802FF170(void) {
    s32 temp_r31;
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_80474D90, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(TQuestVmDownLoadServer__sub_8006EF6C(0xD)), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(TQuestVmDownLoadServer__sub_8006EF6C(0xE)), 6, 1);
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DEF28);
    return temp_r31;
}
s32 TAdMultiSaveGC__sub_802FF1F4(void) {
    s32 r = update_window_mode_from_progress__6TLobbyFPv(TAdMultiSaveGC__data_80474D70, TAdMultiSaveGC__data_80474D78);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x20, 2), 1);
    return r;
}
s32 TAdMultiSaveGC__sub_802FF254(void) {
    s32 r = update_window_mode_from_progress__6TLobbyFPv(TAdMultiSaveGC__data_80474D70, TAdMultiSaveGC__data_80474D78);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x20, 3), 1);
    return r;
}
s32 TAdMultiSaveGC__sub_802FF2B4(void) {
    s32 r = update_window_mode_from_progress__6TLobbyFPv(TAdMultiSaveGC__data_80474D70, TAdMultiSaveGC__data_80474D78);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x20, 3), 1);
    return r;
}
s32 TAdMultiSaveGC__sub_802FF314(void) {
    s32 r = update_window_mode_from_progress__6TLobbyFPv(TAdMultiSaveGC__data_80474D70, TAdMultiSaveGC__data_80474D78);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x20, 0), 1);
    return r;
}
void run_task__14TAdMultiSaveGCFv(TAdMultiSaveGC *ad_multi_save_gc) {
    s32 selected_menu_value;
    s32 var_r30;
    if (((TAdPlayerLoadGC *)0)->probe_card_slot() == 0) {
        ad_multi_save_gc->m_1c = 0U;
    }
    switch (ad_multi_save_gc->m_1c) {
    case 0:
        if ((u32) ad_multi_save_gc->m_24 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_multi_save_gc + 0x24)))->close();
            ad_multi_save_gc->m_24 = 0U;
        }
        if ((u32) ad_multi_save_gc->m_28 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_multi_save_gc + 0x28)))->close();
            ad_multi_save_gc->m_28 = 0U;
        }
        if ((u32) ad_multi_save_gc->m_2c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_multi_save_gc + 0x2C)))->close();
            ad_multi_save_gc->m_2c = 0U;
        }
        if ((u32) ad_multi_save_gc->m_30 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_multi_save_gc + 0x30)))->close();
            ad_multi_save_gc->m_30 = 0U;
        }
        if (((TAdPlayerLoadGC *)0)->probe_card_slot() != 0) {
            ad_multi_save_gc->m_1c = 1U;
            return;
        }
        if ((u32) ad_multi_save_gc->m_20 == 0U) {
            ad_multi_save_gc->m_20 = ((s32 (*)(void *))TAdMultiSaveGC__sub_802FF314)(ad_multi_save_gc);
        }
        break;
    case 1:
        if ((u32) ad_multi_save_gc->m_20 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_multi_save_gc + 0x20)))->close();
            ad_multi_save_gc->m_20 = 0U;
        }
        if (TAdPlayerLoadGC::check_memcard_status(0) == 0) {
            ad_multi_save_gc->m_1c = 2U;
            return;
        }
        if ((u32) ad_multi_save_gc->m_24 == 0U) {
            ad_multi_save_gc->m_24 = ((s32 (*)(void *))TAdMultiSaveGC__sub_802FF254)(ad_multi_save_gc);
            return;
        }
        break;
    case 2:
        var_r30 = 1;
        if (verify_system_file__23TAdSinglePlyChrSelectGCFPv() == 0) {
            var_r30 = 0;
        }
        if (TAdSinglePlyChrSelectGC::load_save_from_card() == 0) {
            var_r30 = 0;
        }
        if (var_r30 != 0) {
            ad_multi_save_gc->m_1c = 4U;
            return;
        }
        ad_multi_save_gc->m_2c = ((s32 (*)(void *))TAdMultiSaveGC__sub_802FF2B4)(ad_multi_save_gc);
        ad_multi_save_gc->m_30 = ((s32 (*)(void *))TAdMultiSaveGC__sub_802FF170)(ad_multi_save_gc);
        ad_multi_save_gc->m_1c = 3U;
        return;
    case 3:
        if (((TWindowMenu *)(ad_multi_save_gc->m_30))->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)ad_multi_save_gc->m_30)->get_selected_value();
            switch (selected_menu_value) {
            case 1:
                ad_multi_save_gc->m_1c = 8U;
                return;
            case 0:
                ad_multi_save_gc->m_1c = 0U;
                return;
            }
        }
        break;
    case 4:
        write_encrypted_save__23TAdSinglePlyChrSelectGCFv();
        ad_multi_save_gc->m_28 = ((s32 (*)(void *))TAdMultiSaveGC__sub_802FF1F4)(ad_multi_save_gc);
        ad_multi_save_gc->m_1c = 5U;
        return;
    case 5:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            ad_multi_save_gc->m_1c = 6U;
            return;
        }
        break;
    case 6:
        TAdSinglePlyChrSelectGC__sub_801FDAAC();
        ad_multi_save_gc->m_1c = 7U;
        return;
    case 7:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            if ((u32) ad_multi_save_gc->m_28 != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)ad_multi_save_gc + 0x28)))->close();
                ad_multi_save_gc->m_28 = 0U;
            }
            ad_multi_save_gc->m_1c = 8U;
            return;
        }
        break;
    case 8:
        {
            void *p = __nw__7TObjectFUl(0x28);
            if (p != 0) {
                ((THunterGuildSeqOffline *)p)->init((void *) tl_fade, (void *) TAdMultiSaveGC::queue_destruction);
            }
        }
        break;
    case 9:
        break;
    }
}

}
