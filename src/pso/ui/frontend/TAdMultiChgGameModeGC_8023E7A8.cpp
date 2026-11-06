#include "types.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

struct V3_8023E834 { s32 x; s32 y; s32 z; };

extern "C" {
extern s32 multi_chg_game_mode_state;
extern s32 lbl_805D63C8;
s32 get_current_slot_entry__6TLobbyFv();
s32 strcmp(s32, s32);
void play_area_music(char *name);
s32 get_main_phase(void);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
s32 activate_camera_mode(s32 arg0);
extern V3_8023E834 lbl_8044DD00;
extern V3_8023E834 lbl_8044DD0C;
s32 TAdMultiChgGameModeGC::is_input_phase_active() {
    s32 r = 0;
    switch (get_main_phase()) {
    case 0:
    case 1:
    case 3:
    case 8:
    case 11:
    case 12:
        break;
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 10:
    case 13:
        switch (multi_chg_game_mode_state) {
        case 7:
        case 14:
        case 24:
            r = 1;
            break;
        default:
            r = 0;
            break;
        }
        break;
    case 5:
        r = 1;
        break;
    }
    return r;
}

void TAdMultiChgGameModeGC::set_default_camera() {
    V3_8023E834 a = lbl_8044DD00;
    V3_8023E834 b = lbl_8044DD0C;
    activate_camera_mode(9);
    set_active_camera_pose((u8 *)&a, (u8 *)&b);
}

void TAdMultiChgGameModeGC::set_mode_change_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 3;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::set_change_mode_flags() { TAdMultiChgGameModeGC::sync_mode_state(); (*(int *)&multi_chg_game_mode_state) = 1; (*(int *)&lbl_805D63C8) = 1; }
void TAdMultiChgGameModeGC::apply_bgm_col_ctrl(s32 name) {
    if (strcmp(get_current_slot_entry__6TLobbyFv(), name) != 0) {
        play_area_music((char *)name);
    }
}
void TAdMultiChgGameModeGC::set_state_0x1a() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x1A;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::reset_and_set_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x19;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::set_mode_18() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x18;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::set_mode_17() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x17;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::set_mode_0x15() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x15;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::set_mode_0x14() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x14;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::request_transition() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x11;
    lbl_805D63C8 = 1;
}

}
