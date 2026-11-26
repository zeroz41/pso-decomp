#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TObjDeadListWin.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include <string.h>
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
extern const char TObjDeadListWin_class_name[] = "TObjDeadListWin";
const char* TObjDeadListWin_name = TObjDeadListWin_class_name;
__declspec(section ".data") f32 dead_list_window_position[2] = {210.0f, 100.0f};
extern const char dead_list_text_prefix[] = "\tC8";
extern const char dead_list_name_separator[] = "\n";

void TObjDeadListWin::build_dead_list_window() {
    char text[0x44];
    s32 i;
    m_window_handle = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x3C)), (const f32 *)dead_list_window_position, 1);
    if (m_window_handle != NULL) {
        text[0] = 0;
        strcat(text, dead_list_text_prefix);
        i = 0;
        do {
            if (m_names[i].text[0] != 0) {
                strcat(text, m_names[i].text);
                if (i != 3) strcat(text, dead_list_name_separator);
            }
            i += 1;
        } while (i < 4);
        m_window_handle->append_line((saddr)text, (int)2);
    }
}

void TObjDeadListWin::update_countdown() {
    s32 countdown;
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if ((player == NULL) || (player->test_actor_flags(0x02000000) != 0)) {
        queue_destruction();
        return;
    }
    if ((player->check_player_flag1() == 0) && (m_countdown > 0x5A)) m_countdown = 0x5A;
    countdown = m_countdown - 1;
    m_countdown = countdown;
    if (countdown < 0) {
        if (m_window_handle != NULL) {
            m_window_handle->close();
            m_window_handle = NULL;
        }
        queue_destruction();
    }
}

void TObjDeadListWin::refresh_names() {
    s32 i;
    TObjPlayer *player;
    TObjPlayer *me;
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (m_names[i].text[0] == 0 && player != NULL && challenge_client_died(i) != 0) {
            strncpy(m_names[i].text, player->name, 15);
            m_names[i].terminator = 0;
        }
    }
    me = get_player_by_client_id(local_client_id);
    if ((get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2)
        && has_window_task_root() != 0 && me != NULL
        && me->test_actor_flags(0x02000000) == 0) {
        build_dead_list_window();
        m_phase = 1;
    }
}

void TObjDeadListWin::run_task() {
    if (get_player_by_client_id(local_client_id) == NULL) {
        queue_destruction();
        return;
    }
    switch (m_phase) {
    case 0: refresh_names(); return;
    case 1: update_countdown(); return;
    }
}

TObjDeadListWin::~TObjDeadListWin() {}

TObjDeadListWin::TObjDeadListWin(TObject* parent) : TObject(parent) {
    s32 i;
    m_name = TObjDeadListWin_name;
    m_window_handle = NULL;
    m_countdown = 0x12C;
    for (i = 0; i < 4; i++) m_names[i].text[0] = 0;
    m_phase = 0;
}

TObjDeadListWin* TObjDeadListWin::create(TObject* parent) {
    return new TObjDeadListWin(parent);
}
