#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_8006F278.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
extern s32 local_client_id;
extern const char TObjSoloPlayWin_class_name[] = "TObjSoloPlayWin";
const char* TObjSoloPlayWin_name = TObjSoloPlayWin_class_name;
__declspec(section ".data") float solo_play_result_window_extent[2] = {240.0f, 180.0f};
}

s32 TObjSoloPlayWin::has_at_most_one_player() {
    return (TLobby__sub_8006FBE4() <= 1) ? 1 : 0;
}
s32 TObjSoloPlayWin::area_allows_win_timer() {
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1: case AREA_DRAGON: case AREA_DE_ROL_LE: case AREA_VOL_OPT: case AREA_DARK_FALZ: case AREA_PIONEER2_EP2:
    case AREA_GAL_GRYPHON: case AREA_OLGA_FLOW: case AREA_BARBA_RAY: case AREA_GOL_DRAGON:
        return 0;
    }
    return 1;
}
s32 TObjSoloPlayWin::can_start_win_timer() {
    uaddr player = (uaddr)get_player_by_client_id(local_client_id);
    if (has_window_task_root() == 1 && area_allows_win_timer() != 0 &&
        player != 0U && ((TObjCollidable *)player)->test_actor_flags(0x02000000) == 0) {
        return 1;
    }
    return 0;
}
void TObjSoloPlayWin::open_result_window() {
    m_result_window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x3E)), (const f32 *)solo_play_result_window_extent, 1);
    if (m_result_window != 0) {
        ((TWindowBase *)m_result_window)->set_depth(70200.0f);
        ((TWindowMessage *)m_result_window)->append_line((int)(get_message_text(0x5F)), (int)2);
    }
}
void TObjSoloPlayWin::update_close_timer() {
    s32 countdown = m_countdown - 1;
    m_countdown = countdown;
    if (countdown < 0) {
        if (m_result_window != 0) {
            ((TWindowBase *)m_result_window)->close();
            m_result_window = 0;
        }
        TLobby::mark_solo_win_closing();
        queue_destruction();
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

