#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/TUnk_804F3A20.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC_8036DE10.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"

struct RecoveredGlobal_8036E8DC_lbl_804C88C0 { s32 value; u8 remaining[0x50]; };
typedef char RecoveredGlobal_8036E8DC_lbl_804C88C0_size[sizeof(RecoveredGlobal_8036E8DC_lbl_804C88C0) == 0x54 ? 1 : -1];

struct RecoveredGlobal_8036E8DC_lbl_804C8914 { char value[0xB]; };
typedef char RecoveredGlobal_8036E8DC_lbl_804C8914_size[sizeof(RecoveredGlobal_8036E8DC_lbl_804C8914) == 0xB ? 1 : -1];

struct RecoveredGlobal_8036E8DC_lbl_804C89BC { s32 value; u8 remaining[0x74]; };
typedef char RecoveredGlobal_8036E8DC_lbl_804C89BC_size[sizeof(RecoveredGlobal_8036E8DC_lbl_804C89BC) == 0x78 ? 1 : -1];


#include <stddef.h>
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
struct Stack_8036EA24 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8036EA24 { s32 words[3]; void (TAdMultiChgGameModeGC::*action)(); };

struct Stack_8036E858 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_8036E858 { s32 words[3]; void (TAdMultiChgGameModeGC::*action)(); };

struct Self_8036E2AC {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    void *win;
};

extern "C" {
void *__nw__7TObjectFUl(int);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
s32 load_system_file(s32 arg0);
void refresh_char_slots__23TAdSinglePlyChrSelectGCFv(void);
s32 encrypt_save_and_write__23TAdSinglePlyChrSelectGCFv();
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);
int init_change_mode__21TAdMultiChgGameModeGCFv(void*);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
extern RecoveredGlobal_8036E8DC_lbl_804C88C0 pso_character_card_filename;
extern RecoveredGlobal_8036E8DC_lbl_804C8914 pso_system_card_filename;
extern RecoveredGlobal_8036E8DC_lbl_804C89BC pso_guildcard_card_filename;
u32 load_system_file_flag__23TAdSinglePlyChrSelectGCFv(void);
u32 update_window_mode_from_progress__6TLobbyFPv(void *, const void *);
void *check_room_seq_4__16TAdChrSelASlotGCFl(void *, s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 align_menu_entry_positions(void *);
s32 all_players_loaded__23TAdSinglePlyChrSelectGCFv();
s32 TAdPlayerLoadGC__sub_801FD770();
void TKeyBoardControl__sub_8000F90C(s32 arg0);

// Message text by id: table_a holds the English text, table_b the Japanese.
const char *multi_chg_game_mode_text_table_a[11] = {
    "\"PSO 1&2 Plus\" save files will overwrite\n"
    "\"PSO 1&2\" save files. When save files\n"
    "are overwritten the following will occur:\n"
    "\n"
    "- Characters created on PSO 1&2 will no longer be\n"
    "  compatible with older PSO 1&2 game.\n"
    "- All Item data for all characters (including all\n"
    "  items in Check Room, and Meseta) will be deleted.\n"
    "- Character level, game progress, and Guild Card\n"
    "  will be retained.",
    "- The Ship (server) for PSO 1&2 and PSO 1&2 Plus\n"
    "  are separate. Search or exchange of simple mail\n"
    "  between the PSO 1&2 Ship and the PSO 1&2 Plus\n"
    "  Ship will not be possible. \n"
    "- Please use the same Serial Number and\n"
    "  Access Key from PSO 1&2.\n"
    "- In order to avoid file corruption, do not turn off\n"
    "  the power, remove the Memory Card, or open the\n"
    "  Disc Cover while game data is being  overwritten.\n"
    "\n"
    "Select \"Yes\" if you agree with the stated\n"
    "conditions to have your files overwritten. ",
    "Next Page",
    "Are you sure?",
    "A Memory Card is required to play \n"
    "Phantasy Star Online. \n"
    "\n"
    "Please insert a Memory Card into Slot A.",
    "\tJ\x93\xFA\x96{\x8C\xEA",
    "YES",
    "NO",
    "Saving.\n"
    "Do not remove the Memory Card or\n"
    "turn the power off.",
    "You can play PSO 1&2,\n"
    "PSO 1&2 [Upgrade for Online play],\n"
    "PSO 1&2 Plus and PSO Episode 3\n"
    "using the same Serial Number/Access Key.\n"
    "\n"
    "The Serial Number/Access Key from PSO Episode 3\n"
    "in the Memory Card in Slot A will be recognized.",
    "Next",
};
const char *multi_chg_game_mode_text_table_b[11] = {
    "\tJ\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82P\x81\x95\x82Q\x81i\x88\xC8\x8D~\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC6\x8C\xC4\x8F\xCC\x81j\x81v\x82\xCC\x83Z\x81[\x83u\n"
    "\x83t\x83@\x83" "C\x83\x8B\x82\xF0\x81" "A\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82P\x81\x95\x82Q\x81@\x82o\x82\x8C\x82\x95\x82\x93\x81i\x88\xC8\x8D~\x82" "d\x82o\x82P\x81\x95\x82Q\n"
    "\x82o\x82\x8C\x82\x95\x82\x93\x82\xC6\x8C\xC4\x8F\xCC\x81j\x81v\x82\xC5\x81" "A\x83v\x83\x8C\x83" "C\x82\xC5\x82\xAB\x82\xE9\x82\xE6\x82\xA4\x83Z\x81[\x83u\x83t\x83@\x83" "C\x83\x8B\x82\xCC\x8F\x91\x82\xAB\n"
    "\x82\xA9\x82\xA6\x82\xF0\x8Ds\x82\xA2\x82\xDC\x82\xB7\x81" "B\x83Z\x81[\x83u\x83t\x83@\x83" "C\x83\x8B\x82\xCC\x8F\x91\x82\xAB\x82\xA9\x82\xA6\x91\x80\x8D\xEC\x82\xF0\x8Ds\x82\xA4\x82\xC6\x81" "A\n"
    "\n"
    "\x81" "E\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xCC\x83L\x83\x83\x83\x89\x83N\x83^\x81[\x82\xCD\x97V\x82\xD7\x82\xC8\x82\xAD\x82\xC8\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"
    "\x81" "E\x83\x81\x83" "C\x83\x93\x83L\x83\x83\x83\x89\x83N\x83^\x81[\x81" "A\x83I\x83t\x83\x89\x83" "C\x83\x93\x83}\x83\x8B\x83`\x83\x82\x81[\x83h\x97p\x82\xCC\x88\xEA\x8E\x9E\x83L\x83\x83\x83\x89\n"
    "\x81@\x83N\x83^\x81[\x93\x99\x82\xCC\x91S\x83" "A\x83" "C\x83" "e\x83\x80\x83" "f\x81[\x83^\x81i\x83`\x83" "F\x83" "b\x83N\x83\x8B\x81[\x83\x80\x82\xF0\x8A\xDC\x82\xDE\x91S\x83" "A\x83" "C\x83" "e\n"
    "\x81@\x83\x80\x82\xA8\x82\xE6\x82\xD1\x83\x81\x83Z\x83^\x81j\x82\xAA\x8D\xED\x8F\x9C\x82\xB3\x82\xEA\x81" "A\x8F\x89\x8A\xFA\x91\x95\x94\xF5\x82\xC6\x82\xC8\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"
    "\x81" "E\x83L\x83\x83\x83\x89\x83N\x83^\x81[\x82\xCC\x83\x8C\x83x\x83\x8B\x82\xE2\x83Q\x81[\x83\x80\x90i\x8Ds\x93x\x81" "A\x83M\x83\x8B\x83h\x83J\x81[\x83h\x93\x99\x82\xCD\n"
    "\x81@\x82\xBB\x82\xCC\x82\xDC\x82\xDC\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B",
    "\tJ\x81" "E\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC6\x82" "d\x82o\x82P\x81\x95\x82Q\x82o\x82\x8C\x82\x95\x82\x93\x82\xCC\x83V\x83" "b\x83v\x81i\x83T\x81[\x83o\x81j\x82\xCD\x95\xCA\x82\xC9\x82\xC8\n"
    "\x81@\x82\xE8\x82\xDC\x82\xB7\x81" "B\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC6\x82" "d\x82o\x82P\x81\x95\x82Q\x82o\x82\x8C\x82\x95\x82\x93\x82\xCC\x83V\x83" "b\x83v\x81i\x83T\x81[\x83o\x81j\n"
    "\x81@\x8A\xD4\x82\xC5\x82\xCC\x8C\x9F\x8D\xF5\x82\xE2\x83V\x83\x93\x83v\x83\x8B\x83\x81\x81[\x83\x8B\x91\x97\x8E\xF3\x90M\x93\x99\x82\xCD\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"
    "\x81" "E\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\x81[\x81" "A\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xCD\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xC5\x83n\x83\x93\x83^\x81[\x83Y\x83\x89\n"
    "\x81@\x83" "C\x83Z\x83\x93\x83X\x82\xF0\x82\xA8\x94\x83\x82\xA2\x8B\x81\x82\xDF\x82\xCC\x8F\xEA\x8D\x87\x82\xCD\x81" "A\x82" "d\x82o\x82P\x81\x95\x82Q\x82\xCC\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\n"
    "\x81@\x81[\x81" "E\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xF0\x82\xBB\x82\xCC\x82\xDC\x82\xDC\x82\xA8\x8Eg\x82\xA2\x89\xBA\x82\xB3\x82\xA2\x81" "B\n"
    "\x81" "E\x83t\x83@\x83" "C\x83\x8B\x82\xAA\x89\xF3\x82\xEA\x82\xE9\x8C\xB4\x88\xF6\x82\xC6\x82\xC8\x82\xE8\x82\xDC\x82\xB7\x82\xCC\x82\xC5\x81" "A\x8F\x91\x82\xAB\x82\xA9\x82\xA6\x92\x86\x82\xCC\x96{\x91\xCC\x93" "d\x8C\xB9\n"
    "\x81@\x82n\x82" "e\x82" "e\x81" "A\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x94\xB2\x82\xAB\x8D\xB7\x82\xB5\x81" "A\x83" "f\x83" "B\x83X\x83N\x83J\x83o\x81[\x83I\x81[\x83v\x83\x93\x82\xCD\n"
    "\x81@\x90\xE2\x91\xCE\x82\xC9\x8Ds\x82\xED\x82\xC8\x82\xA2\x82\xC5\x89\xBA\x82\xB3\x82\xA2\x81" "B\n"
    "\n"
    "\x88\xC8\x8F\xE3\x82\xCC\x93_\x82\xC9\x93\xAF\x88\xD3\x82\xCC\x8F\xE3\x81" "A\x8F\x91\x82\xAB\x82\xA9\x82\xA6\x82\xF0\x82\xA8\x82\xB1\x82\xC8\x82\xA2\x82\xDC\x82\xB7\x81" "B\n"
    "\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x81H",
    "\tJ\x8E\x9F\x82\xCC\x83y\x81[\x83W\x82\xD6",
    "\tJ\x96{\x93\x96\x82\xC9\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x81H",
    "\tJPSO\x82\xF0\x97V\x82\xD4\x82\xC9\x82\xCD\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x95K\x97v\x82\xC5\x82\xB7\x81" "B\n"
    "\x83X\x83\x8D\x83" "b\x83g\x82`\x82\xC9\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x83Z\x83" "b\x83g\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B",
    "English",
    "\tJ\x82\xCD\x82\xA2",
    "\tJ\x82\xA2\x82\xA2\x82\xA6",
    "\tJ\x83Z\x81[\x83u\x92\x86\x82\xC5\x82\xB7\x81" "B\n"
    "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xAB\x8D\xB7\x82\xB5\x82\xB5\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"
    "\x93" "d\x8C\xB9\x82\xF0\x90\xD8\x82\xE7\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B",
    "\tJ\x81u\x82o\x82r\x82n \x82" "d\x82o\x82P\x81\x95\x82Q\x81v\x81u\x82o\x82r\x82n \x82" "d\x82o\x82P\x81\x95\x82Q\x83I\x83\x93\x83\x89\x83" "C\x83\x93\x92\xB2\x90\xAE\x94\xC5\x81v\n"
    "\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82P\x81\x95\x82Q\x82o\x82\x8C\x82\x95\x82\x93\x81v\x82\xC6\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82R\x81v\x82\xCD\n"
    "\x93\xAF\x88\xEA\x82\xCC\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\x81[\x81" "E\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xC5\x97V\x82\xD4\x82\xB1\x82\xC6\x82\xAA\x89\xC2\x94\\\x82\xC5\x82\xB7\x81" "B\n"
    "\n"
    "\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x93\xE0\x82\xC9\x82\xA0\x82\xE9\x81u\x82o\x82r\x82n\x81@\x82" "d\x82o\x82R\x81v\x82\xCC\n"
    "\x83V\x83\x8A\x83" "A\x83\x8B\x83i\x83\x93\x83o\x81[\x81" "E\x83" "A\x83N\x83Z\x83X\x83L\x81[\x82\xCC\x8F\xEE\x95\xF1\x82\xF0\x93\xC7\x82\xDD\x8D\x9E\x82\xDD\x82\xDC\x82\xB7\x81" "B",
    "\tJ\x8E\x9F\x82\xC9\x90i\x82\xDE",
};

// Size of the confirm window; the window is centred on the 640-wide screen in __sinit below.
const f32 multi_chg_game_mode_window_size[2] = {540.0f, 280.0f};

typedef void (TAdMultiChgGameModeGC::*TAdMultiChgGameModeGCAction)();

// One entry per state: enter is called by set_state, task by run_task every frame.
struct TAdMultiChgGameModeGCState {
    TAdMultiChgGameModeGCAction enter;
    TAdMultiChgGameModeGCAction task;
};

TAdMultiChgGameModeGCState multi_chg_game_mode_entry_table[11] = {
    {&TAdMultiChgGameModeGC::sub_8036E9EC, &TAdMultiChgGameModeGC::confirm_mode_selection},
    {&TAdMultiChgGameModeGC::load_system_on_mode_default, &TAdMultiChgGameModeGC::update_mode_selection},
    {&TAdMultiChgGameModeGC::sub_8036E7DC, &TAdMultiChgGameModeGC::check_player_load_result},
    {&TAdMultiChgGameModeGC::sub_8036E51C, &TAdMultiChgGameModeGC::handle_menu_input},
    {&TAdMultiChgGameModeGC::close_windows_and_reopen, &TAdMultiChgGameModeGC::update_card_confirm_selection},
    {&TAdMultiChgGameModeGC::close_windows_and_cleanup, &TAdMultiChgGameModeGC::update_confirm_selection},
    {&TAdMultiChgGameModeGC::sub_8036E750, &TAdMultiChgGameModeGC::update_mode_selection_and_save},
    {&TAdMultiChgGameModeGC::sub_8036E6EC, &TAdMultiChgGameModeGC::sub_8036E6A0},
    {&TAdMultiChgGameModeGC::sub_8036E854, &TAdMultiChgGameModeGC::sub_8036E834},
    {&TAdMultiChgGameModeGC::sub_8036E830, &TAdMultiChgGameModeGC::request_scene_change_vt},
    {&TAdMultiChgGameModeGC::sub_8036DEDC, &TAdMultiChgGameModeGC::close_windows_on_selection},
};
__declspec(section ".data") f32 multi_chg_game_mode_window_extent[2] = {0.5f * (640.0f - multi_chg_game_mode_window_size[0]), 70.0f};
__declspec(section ".data") f32 lbl_804F3A18[2] = {
    20.0f + multi_chg_game_mode_window_extent[0],
    10.0f + (multi_chg_game_mode_window_extent[1] + multi_chg_game_mode_window_size[1]),
};
f32 lbl_805D7020 = multi_chg_game_mode_window_size[0] - 40.0f;

s32 TAdMultiChgGameModeGC__sub_8036DE10(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 == -1) {
        return TQuestVmDownLoadServer__sub_8006EF6C((arg1));
    }
    if (arg2 == 0) {
        return (s32)multi_chg_game_mode_text_table_b[arg1];
    }
    return (s32)multi_chg_game_mode_text_table_a[arg1];
}

void TAdMultiChgGameModeGC::close_windows_on_selection() {
    void *temp_r3;
    if (handle_mode_selection() == 0) {
        temp_r3 = *(void **)((s8 *)this + 0x30);
        if ((u32) temp_r3 != 0U) {
            ((TObject *)temp_r3)->queue_destruction();
            *(u32 *)((s8 *)this + 0x30) = 0U;
        }
        temp_r3 = *(void **)((s8 *)this + 0x34);
        if ((u32) temp_r3 != 0U) {
            ((TObject *)temp_r3)->queue_destruction();
            *(u32 *)((s8 *)this + 0x34) = 0U;
        }
        set_state(3);
    }
}

void TAdMultiChgGameModeGC::sub_8036DEDC() {
    if (handle_mode_selection() != 0) {
        return;
    }
}

void TAdMultiChgGameModeGC::update_confirm_selection() {
    s32 selected_menu_value;
    u32 temp_r3_2;

    if (handle_mode_selection() == 0) {
        temp_r3_2 = *(u32 *)((s8 *)this + 0x34);
        if (temp_r3_2 != 0U) {
            if (((TWindowMenu *)temp_r3_2)->is_decided() != 0) {
                selected_menu_value = ((TWindowMenu *)(*(u32 *)((s8 *)this + 0x34)))->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    set_state(6);
                    close_window_30();
                    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 8);
                    return;
                case 1:
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(3);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}
}

void TAdMultiChgGameModeGC::close_windows_and_cleanup() {
    if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close();
        *(u32 *)((s8 *)this + 0x34) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close();
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    TAdMultiChgGameModeGC::setup_mode_menu(this, 0);
    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 4);
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x30)))->append_line(TAdMultiChgGameModeGC__sub_8036DE10((s32)this, 3, (s32)(*(s32 *)((s8 *)this + 0x24))), 3);
    }
}

void TAdMultiChgGameModeGC::update_card_confirm_selection() {
    s32 selected_menu_value;

    if (handle_mode_selection() == 0) {
        if (*(void **)((s8 *)this + 0x34) != 0) {
            if (((TWindowMenu *)(*(void **)((s8 *)this + 0x34)))->is_decided() != 0) {
                selected_menu_value = ((TWindowMenu *)(*(void **)((s8 *)this + 0x34)))->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    close_window_30();
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(5);
                    return;
                case 1:
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(3);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}

void TAdMultiChgGameModeGC::close_windows_and_reopen() {
    if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close();
        *(u32 *)((s8 *)this + 0x34) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close();
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    TAdMultiChgGameModeGC::setup_mode_menu(this, 0);
    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 4);
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x30)))->append_line(TAdMultiChgGameModeGC__sub_8036DE10((s32)this, 1, (s32)(*(s32 *)((s8 *)this + 0x24))), 3);
    }
}

void TAdMultiChgGameModeGC__sub_8036E19C(u8 *arg0, s32 arg1) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close();
        *(u32 *)((s8 *)arg0 + 0x30) = 0U;
    }
    *(u32 *)((s8 *)arg0 + 0x30) = update_window_mode_from_progress__6TLobbyFPv(multi_chg_game_mode_window_extent, multi_chg_game_mode_window_size);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)arg0 + 0x30)))->append_line((s32)((int) (TAdMultiChgGameModeGC__sub_8036DE10((s32)arg0, (s32)arg1, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x24)))))), 3);
    }
}

void TAdMultiChgGameModeGC::close_window_30() {
    void *temp_r3 = *(void **)((s8 *)this + 0x30);
    if ((u32) temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    close_window__21TAdMultiChgGameModeGCFPv(this);
}
void close_window__21TAdMultiChgGameModeGCFPv(void* p) { if (*(unsigned int*)((char*)p + 0x34) != 0) { ((TWindowBase *)((void*)(*(void**)((char*)p + 0x34))))->close(); *(int*)((char*)p + 0x34) = 0; } }

#define self ((Self_8036E2AC *)arg0)
s32 TAdMultiChgGameModeGC::setup_mode_menu(void *arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    self->win = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_804F3A18, 2);
    a = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 6, self->f24);
    b = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 7, self->f24);
    c = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 2, self->f24);
    d = TAdMultiChgGameModeGC__sub_8036DE10((s32)self, 5, self->f24);
    if (self->win != 0) {
        if (arg1 == 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, a, 5, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, b, 5, 1);
            ((TWindowSubComCardList *)(self->win))->set_selected_index(1);
        } else {
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, c, 5, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, d, 5, 1);
            ((TWindowSubComCardList *)(self->win))->set_selected_index(0);
        }
        ((TWindowSubComCardList *)(self->win))->update_layout_height(lbl_805D7020);
        align_menu_entry_positions(self->win);
    }
}
#undef self

void TAdMultiChgGameModeGC::handle_menu_input() {
    s32 selected_menu_value;
    u8 *window_menu;
    if (handle_mode_selection() == 0) {
        window_menu = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x34));
        if (window_menu != NULL) {
            if (((int)((TWindowMenu *)window_menu)->is_decided()) != 0) {
                selected_menu_value = ((TWindowMenu *)(*(u8 **)((s8 *)((u8 *)this) + 0x34)))->get_selected_value();
                switch (selected_menu_value) {
                case 0:
                    close_window_30();
                    close_window__21TAdMultiChgGameModeGCFPv(this);
                    set_state(4);
                    return;
                case 1:
                    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x24) == 0) {
                        *(s32 *)((s8 *)((u8 *)this) + 0x24) = 1;
                    } else {
                        *(s32 *)((s8 *)((u8 *)this) + 0x24) = 0;
                    }
                    set_state(0xA);
                    return;
                }
            }
        } else {
            set_state(8);
        }
    }
}
void TAdMultiChgGameModeGC::create_back_objects() {
    void *o;
    void *o2;
    if (*(void **)((s8 *)this + 0x28) == NULL) {
        o = __nw__7TObjectFUl(0x24);
        if (o != NULL) {
            o = __ct__9TAdBackGCFv(o, this);
        }
        *(void **)((s8 *)this + 0x28) = o;
    }
    if (*(void **)((s8 *)this + 0x2C) == NULL) {
        o2 = __nw__7TObjectFUl(0x28);
        if (o2 != NULL) {
            o2 = __ct__12TAdBackTxtGCFv(o2, this);
        }
        *(void **)((s8 *)this + 0x2C) = o2;
    }
}
void TAdMultiChgGameModeGC::sub_8036E51C() {
    if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
        ((TWindowBase *)((void*)(*(void **)((s8 *)this + 0x34))))->close();
        *(u32 *)((s8 *)this + 0x34) = 0U;
    }
    TAdMultiChgGameModeGC::setup_mode_menu(this, 1);
    TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 4);
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x30)))->append_line((s32)((int) (TAdMultiChgGameModeGC__sub_8036DE10((s32)this, 0, (s32)((s32)((int) (*(s32 *)((s8 *)this + 0x24))))))), 3);
    }
    create_back_objects();
}
void TAdMultiChgGameModeGC::update_mode_selection() {
    s32 arg0 = (s32)this;
    if ((handle_mode_selection() == 0) && (TAdPlayerLoadGC::get_instance() == 0)) {
        set_state(2);
    }
}
void TAdMultiChgGameModeGC::load_system_on_mode_default() { if (handle_mode_selection() == 0) { load_system_file((s32)((void*)0)); } }
s32 TAdMultiChgGameModeGC::handle_mode_selection() {
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)this + 0x20);
    if (temp_r4 & 1) {
        set_state(9);
        return 1;
    }
    if (temp_r4 & 2) {
        return 0;
    }
    if (temp_r4 & 4) {
        set_state(9);
        return 1;
    }
    if (temp_r4 & 8) {
        set_state(9);
        return 1;
    }
    return 0;
}
void TAdMultiChgGameModeGC::sub_8036E6A0() {
    if ((handle_mode_selection() == 0) && (TAdPlayerLoadGC::get_instance() == 0)) {
        set_state(8);
    }
}
void TAdMultiChgGameModeGC::sub_8036E6EC() {  }
void TAdMultiChgGameModeGC::update_mode_selection_and_save() {
    s32 arg0 = (s32)this;
    if (((int)handle_mode_selection()) == 0) {
        refresh_char_slots__23TAdSinglePlyChrSelectGCFv();
        if (encrypt_save_and_write__23TAdSinglePlyChrSelectGCFv() != 0) {
            set_state((s32)((s32)((void*)(7))));
            return;
        }
        set_state((s32)((s32)((void*)(8))));
    }
}
void TAdMultiChgGameModeGC::sub_8036E750() {  }

void TAdMultiChgGameModeGC::check_player_load_result() {
    if (handle_mode_selection() != 0) {
        return;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return;
    }
    switch (TAdPlayerLoadGC__sub_801FD770()) {
    case 5:
        if (all_players_loaded__23TAdSinglePlyChrSelectGCFv() != 0) {
            set_state(3);
        } else {
            set_state(8);
        }
        break;
    default:
        set_state(8);
        break;
    }
}

void TAdMultiChgGameModeGC::sub_8036E7DC() {
    if (handle_mode_selection() != 0) {
        return;
    }
    if (load_system_file_flag__23TAdSinglePlyChrSelectGCFv() == 0xFFFFFF05) {
        return;
    }
}

void TAdMultiChgGameModeGC::request_scene_change_vt() { request_scene_change__21TAdMultiChgGameModeGCFv(this); }
void TAdMultiChgGameModeGC::sub_8036E830() {  }
void TAdMultiChgGameModeGC::sub_8036E834() { init_change_mode__21TAdMultiChgGameModeGCFv(this); }
void TAdMultiChgGameModeGC::sub_8036E854() {  }

typedef char MemberActionStorage_8036E858_size[sizeof(MemberActionStorage_8036E858) == 12 ? 1 : -1];
void TAdMultiChgGameModeGC::set_state(s32 arg1) {
    MemberActionStorage_8036E858 member_action;
    typedef char sp8_offset[(offsetof(Stack_8036E858, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8036E858, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8036E858, sp10) == 0x8) ? 1 : -1];
    Stack_8036E858 stack;
    u8 *temp_r6;
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x1C) != arg1) {
        *(s32 *)((s8 *)((u8 *)this) + 0x1C) = arg1;
        temp_r6 = (u8 *)multi_chg_game_mode_entry_table + (*(s32 *)((s8 *)((u8 *)this) + 0x1C) * 0x18);
        member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0);
        member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 4);
        member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 8);
        if (member_action.action != 0) {
            (this->*member_action.action)();
        }
    }
}

s32 check_system_file_status__23TAdSinglePlyChrSelectGCFv(void) {
    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        return 1;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) != 0) {
        return 2;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        return 4;
    }
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        return 4;
    }
    if ((TAdPlayerLoadGC::find_card_file(0, (const char *)&pso_character_card_filename.value) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)((const char *)&pso_guildcard_card_filename.value)) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)((const char *)&pso_system_card_filename.value)) != 0)) {
        return 8;
    }
    return 0;
}

void TAdMultiChgGameModeGC::confirm_mode_selection() { if (((int)handle_mode_selection()) == 0) { set_state((s32)((s32)((void*)((void*)1)))); } }
void TAdMultiChgGameModeGC::sub_8036E9EC() { close_window_30(); TAdMultiChgGameModeGC__sub_8036E19C((u8 *)this, 4); }

typedef char MemberActionStorage_8036EA24_size[sizeof(MemberActionStorage_8036EA24) == 12 ? 1 : -1];
void TUnk_804F3A20::run_task() {
    u8 *arg0 = (u8 *)this;
    MemberActionStorage_8036EA24 member_action;
    typedef char sp8_offset[(offsetof(Stack_8036EA24, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8036EA24, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8036EA24, sp10) == 0x8) ? 1 : -1];
    Stack_8036EA24 stack;
    u8 *temp_r6;
    this->m_20 = check_system_file_status__23TAdSinglePlyChrSelectGCFv();
    if (this->m_20 & 1) {
        ((TAdMultiChgGameModeGC *)arg0)->set_state(9);
    }
    temp_r6 = (u8 *)multi_chg_game_mode_entry_table + (*(s32 *)&this->unk_1C * 0x18);
    member_action.words[0] = *(s32 *)((s8 *)temp_r6 + 0xC);
    member_action.words[1] = *(s32 *)((s8 *)temp_r6 + 0x10);
    member_action.words[2] = *(s32 *)((s8 *)temp_r6 + 0x14);
    if (member_action.action != 0) {
        (((TAdMultiChgGameModeGC *)(arg0))->*member_action.action)();
    }
}

TUnk_804F3A20::~TUnk_804F3A20() {
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x30)))->queue_destruction(); this->m_30 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x34)))->queue_destruction(); *(s32 *)((s8 *)this + 0x34) = 0; }
}

TUnk_804F3A20::TUnk_804F3A20(TObject *object) : TObject(object) {
    *(s32 *)((s8 *)this + 0x1C) = -1;
    this->m_20 = 1;
    *(s32 *)((s8 *)this + 0x24) = current_language;
    this->m_30 = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    this->m_28 = 0;
    *(s32 *)((s8 *)this + 0x2C) = 0;
    this->m_20 = ((s32 (*)(void *))check_system_file_status__23TAdSinglePlyChrSelectGCFv)(this);
    if (this->m_20 & 1) {
        ((TAdMultiChgGameModeGC *)this)->set_state(0);
    } else {
        ((TAdMultiChgGameModeGC *)this)->set_state(1);
    }
    TLobby::stop_audio_streams();
    TKeyBoardControl__sub_8000F90C(9);
}
