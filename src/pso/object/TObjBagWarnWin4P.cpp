#include "pso/TObjBagWarnWin4P.h"

#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 TWindow__close(int);
s32 TWindowCtrlMain__sub_8024CE58();
void *__ct__16TObjBagWarnWin4PFv(void *arg0);
u32 create_message_window__6TLobbyFllUls(s32, void *, s32, s32);
void *get_player_by_client_id(s32 i);
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32);
s32 has_player_active_menu__11TWindowCtrlFv(u16);
s32 is_slot_visible__11TWindowCtrlFv(u16);
s32 get_window_layout_position(s32);
void __ct__7TObjectFP7TObject(void *);
s32 get_character_save_record(u32 arg0);
s32 is_active__19THunterGuildWarningFv();
s32 is_level_capped__23TAdSinglePlyChrSelectGCFv();
s32 get_entity_id();
s32 send_and_handle__6TLobbyFii(u32, void *, s32);
s32 strncpy(void *, s32, s32);

s32 TObjBagWarnWin4P::check_can_open(void * _w0) {
    s32 i;
    s32 var_r30;

    for (i = 0; i < 4; i++) {
        if ((get_player_by_client_id(i) != 0U) && (has_player_active_menu__11TWindowCtrlFv(get_entity_id()) != 0)) {
            return 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((get_player_by_client_id(i) != 0U) && (is_slot_visible__11TWindowCtrlFv(get_entity_id()) != 0)) {
            return 0;
        }
    }
    if (is_active__19THunterGuildWarningFv() != 0) {
        return 0;
    }
    i = 0;
    var_r30 = 0;
    do {
        if ((get_player_by_client_id(var_r30) != 0U) && (get_character_save_record(var_r30) != 0U) && (is_level_capped__23TAdSinglePlyChrSelectGCFv() != 0)) {
            i = 1;
        }
        var_r30 += 1;
    } while (var_r30 < 4);
    return i;
}

extern s32 TObjBagWarnWin4P__message_window_size[];

void TObjBagWarnWin4P::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) == 0U) {
        if (TWindowCtrlMain__sub_8024CE58() != 0) {
            if (TObjBagWarnWin4P::check_can_open(arg0) != 0) {
                temp_r0 = *(s32 *)((s8 *)arg0 + 0xA0) - 1;
                *(s32 *)((s8 *)arg0 + 0xA0) = temp_r0;
                if (temp_r0 < 0) {
                    *(s32 *)((s8 *)arg0 + 0xA0) = 0;
                }
            } else {
                *(s32 *)((s8 *)arg0 + 0xA0) = 0x1E;
            }
            if ((s32) *(s32 *)((s8 *)arg0 + 0xA0) == 0) {
                create_window();
            }
        }
    } else if (TObjBagWarnWin4P::check_can_open(arg0) == 0) {
        TWindow__close((int) (*(u32 *)((s8 *)arg0 + 0x1C)));
        *(u32 *)((s8 *)arg0 + 0x1C) = 0U;
        *(s32 *)((s8 *)arg0 + 0xA0) = 0x1E;
    }
}

void TObjBagWarnWin4P::create_window() {
    u8 *arg0 = (u8 *)this;
    s32 r3 = get_window_layout_position(0x5B);
    *(u32 *)((s8 *)arg0 + 0x1C) = create_message_window__6TLobbyFllUls(r3, TObjBagWarnWin4P__message_window_size, 1, 4);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) != 0U) {
        strncpy(arg0 + 0x20, TQuestVmDownLoadServer__sub_8006EF6C(0x69), 0x7F);
        *(s8 *)((s8 *)arg0 + 0x9F) = 0;
        send_and_handle__6TLobbyFii(*(u32 *)((s8 *)arg0 + 0x1C), arg0 + 0x20, 0);
    }
}

extern s32 __vt__16TObjBagWarnWin4P[];
extern void *lbl_805D284C;

TObjBagWarnWin4P::~TObjBagWarnWin4P() {}
void *__ct__16TObjBagWarnWin4PFv(void *bag_warn_win4_p) {
    __ct__7TObjectFP7TObject(bag_warn_win4_p);
    *(s32 **)((s8 *)bag_warn_win4_p + 0x18) = __vt__16TObjBagWarnWin4P;
    *(void * *)&((TObjBagWarnWin4P *)bag_warn_win4_p)->m_name = lbl_805D284C;
    *(u32 *)((s8 *)bag_warn_win4_p + 0x1C) = 0;
    *(u32 *)((s8 *)bag_warn_win4_p + 0xA0) = 0;
    return bag_warn_win4_p;
}

}
