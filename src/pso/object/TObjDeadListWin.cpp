#include "pso/object/TObjDeadListWin.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"
extern "C" {
s32 get_player_by_client_id(s32);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(s32, s32);
s32 TWindowCtrlMain__sub_8024CE58();
char* strncpy(char*, const char*, int);
char* strcat(char*, const char*);
void* get_window_layout_position(s32);
void send_and_handle__6TLobbyFii(u32, void*, s32);
u32 set_window_mode_4__6TLobbyFPvll(void*, void*, s32);
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
    m_window_handle = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x3C), dead_list_window_position, 1);
    if (m_window_handle != 0U) {
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
        send_and_handle__6TLobbyFii(m_window_handle, text, 2);
    }
}

void TObjDeadListWin::update_countdown() {
    s32 temp_r0;
    s32 temp_r3;
    temp_r3 = get_player_by_client_id(local_client_id);
    if ((temp_r3 == 0) || (obj_testFlags30__13TUnk_804AF8A0FUl(temp_r3, 0x02000000) != 0)) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if ((((TLobby *)temp_r3)->check_player_flag1() == 0) && (m_countdown > 0x5A)) m_countdown = 0x5A;
    temp_r0 = m_countdown - 1;
    m_countdown = temp_r0;
    if (temp_r0 < 0) {
        if (m_window_handle != 0U) {
            TWindow__close((u8 *)m_window_handle);
            m_window_handle = 0U;
        }
        queue_destruction__7TObjectFv(this);
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
    if ((get_current_area() == 0 || get_current_area() == 0x12)
        && TWindowCtrlMain__sub_8024CE58() != 0 && me != NULL
        && obj_testFlags30__13TUnk_804AF8A0FUl((s32)me, 0x02000000) == 0) {
        build_dead_list_window();
        m_phase = 1;
    }
}

void TObjDeadListWin::run_task() {
    if (get_player_by_client_id(local_client_id) == 0U) {
        queue_destruction__7TObjectFv(this);
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
    m_window_handle = 0;
    m_countdown = 0x12C;
    for (i = 0; i < 4; i++) m_names[i].text[0] = 0;
    m_phase = 0;
}

TObjDeadListWin* TObjDeadListWin::create(TObject* parent) {
    return new TObjDeadListWin(parent);
}
