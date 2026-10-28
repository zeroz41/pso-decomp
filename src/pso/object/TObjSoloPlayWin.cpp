#include "pso/object/TObjSoloPlayWin.h"
#include "pso/misc/TLobby_8006F278.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

extern "C" {
u32 get_player_by_client_id(s32);
s32 TWindowCtrlMain__sub_8024CE58();
s32 obj_testFlags30__13TUnk_804AF8A0FUl(u32, s32);
void* get_window_layout_position(s32);
void* set_window_mode_4__6TLobbyFPvll(void*, void*, s32);
void* TQuestVmDownLoadServer__sub_8006EF6C(s32);
s32 send_and_handle__6TLobbyFii(void*, void*, s32);
extern s32 local_client_id;
extern const char TObjSoloPlayWin_class_name[] = "TObjSoloPlayWin";
const char* TObjSoloPlayWin_name = TObjSoloPlayWin_class_name;
__declspec(section ".data") float solo_play_result_window_extent[2] = {240.0f, 180.0f};
__declspec(section ".sdata2") extern const f32 solo_play_result_window_depth;
}

s32 TObjSoloPlayWin::has_at_most_one_player() {
    return (TLobby__sub_8006FBE4() <= 1) ? 1 : 0;
}
s32 TObjSoloPlayWin::area_allows_win_timer() {
    switch (get_current_area()) {
    case 0: case 0xB: case 0xC: case 0xD: case 0xE: case 0x12:
    case 0x1E: case 0x1F: case 0x20: case 0x21:
        return 0;
    }
    return 1;
}
s32 TObjSoloPlayWin::can_start_win_timer() {
    u32 player = get_player_by_client_id(local_client_id);
    if (TWindowCtrlMain__sub_8024CE58() == 1 && area_allows_win_timer() != 0 &&
        player != 0U && obj_testFlags30__13TUnk_804AF8A0FUl(player, 0x02000000) == 0) {
        return 1;
    }
    return 0;
}
void TObjSoloPlayWin::open_result_window() {
    m_result_window = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x3E), solo_play_result_window_extent, 1);
    if (m_result_window != 0) {
        ((TLobby *)m_result_window)->set_field_1c(solo_play_result_window_depth);
        send_and_handle__6TLobbyFii(m_result_window, TQuestVmDownLoadServer__sub_8006EF6C(0x5F), 2);
    }
}
void TObjSoloPlayWin::update_close_timer() {
    s32 countdown = m_countdown - 1;
    m_countdown = countdown;
    if (countdown < 0) {
        if (m_result_window != 0) {
            TWindow__close((u8 *)m_result_window);
            m_result_window = 0;
        }
        TLobby::mark_solo_win_closing();
        queue_destruction__7TObjectFv(this);
    }
}
void TObjSoloPlayWin::start_win_timer() {
    if (m_result_window == 0 && can_start_win_timer() != 0 && has_at_most_one_player() != 0) {
        open_result_window();
        m_countdown = 300;
        m_state = 1;
    }
}
void TObjSoloPlayWin::run_task() {
    switch (m_state) {
    case 0: start_win_timer(); return;
    case 1: update_close_timer(); return;
    }
}
TObjSoloPlayWin::~TObjSoloPlayWin() {}
TObjSoloPlayWin::TObjSoloPlayWin(TObject* parent) : TObject(parent) {
    m_name = TObjSoloPlayWin_name;
    m_result_window = 0;
    m_state = 0;
}
TObjSoloPlayWin* TObjSoloPlayWin::create(TObject* parent) {
    return new TObjSoloPlayWin(parent);
}

__declspec(section ".sdata2") extern const f32 solo_play_result_window_depth = 70200.0f;
