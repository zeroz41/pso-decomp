#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TObjDeadListWin.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <string.h>
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"
extern "C" {
extern s32 local_client_id;
extern const char TObjDeadListWin_class_name[] = "TObjDeadListWin";
const char* TObjDeadListWin_name = TObjDeadListWin_class_name;
__declspec(section ".data") f32 dead_list_window_position[2] = {210.0f, 100.0f};
extern const char dead_list_text_prefix[] = "\tC8";
extern const char dead_list_name_separator[] = "\n";
}

void TObjDeadListWin::build_dead_list_window() {
    char text[0x44];
    s32 i;
    m_window_handle = (TWindowMessage *)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x3C)), (const f32 *)dead_list_window_position, 1);
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
    s32 temp_r0;
    saddr player;
    player = (saddr)get_player_by_client_id(local_client_id);
    if ((player == 0) || (((TObjCollidable *)player)->test_actor_flags(0x02000000) != 0)) {
        queue_destruction();
        return;
    }
    if ((((TObjPlayer *)player)->check_player_flag1() == 0) && (m_countdown > 0x5A)) m_countdown = 0x5A;
    temp_r0 = m_countdown - 1;
    m_countdown = temp_r0;
    if (temp_r0 < 0) {
        if (m_window_handle != NULL) {
            m_window_handle->close();
            m_window_handle = NULL;
        }
        queue_destruction();
    }
}

void TObjDeadListWin::refresh_names() {
    s32 i;
    u8* player;
    u8* me;
    for (i = 0; i < 4; i++) {
        player = (u8*)get_player_by_client_id(i);
        if (m_names[i].text[0] == 0 && player != NULL && TLobby::get_flagged_table_entry(i) != 0) {
            strncpy(m_names[i].text, (char*)player + 0x85C, 15);
            m_names[i].terminator = 0;
        }
    }
    me = (u8*)get_player_by_client_id(local_client_id);
    if ((get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2)
        && has_window_task_root() != 0 && me != NULL
        && ((TObjCollidable *)me)->test_actor_flags(0x02000000) == 0) {
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
