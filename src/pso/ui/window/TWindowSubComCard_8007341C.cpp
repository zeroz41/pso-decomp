#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TObject.h"
#include <stdio.h>
#include <string.h>
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
char *get_message_text(s32);
s32 fn_80071A9C(void *, void *, void *);
__declspec(section ".data") f32 challenge_window_extent[2] = {240.0f, 200.0f};
char challenge_progress_text_buffer[0x100];
const char *challenge_grade_letter_table[4] = {"", "B", "A", "S"};
int TWindowMenu::is_decided() { return (this->m_70 >> 1) & 0x1; }

void TAdSinglePlyChrSelectGC::format_challenge_stage_times(s32 lobby, s32 challenge_id) {
    char buf2[0x18];
    char buf1[0x10];
    s32 h1, m1, s1;
    s32 h2, m2, s2;
    s32 idx;
    s32 kind;
    ChallengeClientRecords *rec;
    s32 i;
    ChallengeRecord *data;
    s32 t;
    ChallengeStageRank *slot;
    s32 *p;
    s32 sum;
    s32 n;
    s32 j;
    s32 sl;
    if (challenge_id >= 3 && challenge_id <= 0xB) {
        idx = challenge_id - 3;
        kind = 0;
    } else if (challenge_id >= 0xC && challenge_id <= 0x10) {
        kind = 1;
        idx = challenge_id - 0xC;
    }
    sprintf(challenge_progress_text_buffer, "< %s%1d >\n", get_message_text(0x53), idx + 1, 0xFF);
    for (i = 0, rec = challenge_mode_state.client_records; i < 4; i++, rec++) {
        if (rec->present != 0) {
            strcat(challenge_progress_text_buffer, (char *)(((u8 *)get_player_by_client_id(i)) + 0x85C));
            strcat(challenge_progress_text_buffer, "\n  ");
            data = &rec->records;
            slot = TWindowSubStatusDisp__sub_8006F134(data, kind);
            t = TLobby::get_valid_slot(TWindowSubStatusDisp__sub_8006F0D8(data, kind)[idx]);
            if (t == 0) {
                strcat(challenge_progress_text_buffer, "      ");
                strcat(challenge_progress_text_buffer, get_message_text(0x51));
                strcat(challenge_progress_text_buffer, "\n");
            } else {
                if ((s32)TLobby::get_slot_clamped((u32)(slot->rank)) == 0) {
                    strcat(challenge_progress_text_buffer, "            ");
                } else {
                    p = TWindowSubStatusDisp__sub_8006F0D8(data, kind);
                    sum = 0;
                    n = TWindowSubStatusDisp::get_layout_id(kind);
                    for (j = 0; j < n; j++, p++) {
                        sum += TLobby::get_valid_slot(*p);
                    }
                    sl = (s32)TLobby::get_slot_clamped((u32)(slot->rank));
                    TQuestVmDownLoadServer::split_time_hms(sum, &h1, &m1, &s1);
                    sprintf(buf2, "%02d'%02d\"%02d %s", h1, m1, s1, challenge_grade_letter_table[sl]);
                    strcat(challenge_progress_text_buffer, buf2);
                }
                strcat(challenge_progress_text_buffer, "  ");
                TQuestVmDownLoadServer::split_time_hms(t, &h2, &m2, &s2);
                sprintf(buf1, "%1d'%02d\"%02d\n", h2, m2, s2);
                strcat(challenge_progress_text_buffer, buf1);
            }
        }
    }
}

void TLobby::open_challenge_window(s32 lobby, s32 challenge_id) {
    TWindowMessage *window;
    window = reinterpret_cast<TWindowMessage *>(TWindowMessage::create(get_window_layout_position(0x3B), challenge_window_extent, 1));
    challenge_mode_state.record_window = window;
    if (window == NULL) {
        return;
    }
    window->set_depth(37000.0f);
    if (TCameraCtrl::get_camera_id() >= 2) {
        challenge_mode_state.record_window->set_position_xy(0.75f, 0.75f);
    }
    TAdSinglePlyChrSelectGC::format_challenge_stage_times(lobby, challenge_id);
    challenge_mode_state.record_window->append_line((saddr)challenge_progress_text_buffer, 0);
}

void TChallenge::open_challenge_progress_window(void *slot) {
    char tmp[32];
    s32 n;
    ChallengeClientRecords *rec;
    s32 i;
    TWindowMessage *window;
    window = reinterpret_cast<TWindowMessage *>(TWindowMessage::create(get_window_layout_position(0x3B), challenge_window_extent, 1));
    challenge_mode_state.record_window = window;
    if (window == NULL) {
        return;
    }
    window->set_depth(37000.0f);
    if (TCameraCtrl::get_camera_id() >= 2) {
        challenge_mode_state.record_window->set_position_xy(0.75f, 0.75f);
    }
    sprintf(challenge_progress_text_buffer, "< %s >\n", get_message_text(0x4F));
    rec = challenge_mode_state.client_records;
    for (i = 0; i < 4; i++, rec++) {
        if (rec->present != 0) {
            strcat(challenge_progress_text_buffer, (char *)(((u8 *)get_player_by_client_id(i)) + 0x85C));
            strcat(challenge_progress_text_buffer, "\n    ");
            n = fn_80071A9C(this, &rec->records, slot);
            if (n >= TWindowSubStatusDisp::get_layout_id((saddr)slot)) {
                strcat(challenge_progress_text_buffer, get_message_text(0x52));
            } else if (n == 0) {
                strcat(challenge_progress_text_buffer, get_message_text(0x51));
            } else {
                sprintf(tmp, "%s%02d", get_message_text(0x50), n);
                strcat(challenge_progress_text_buffer, tmp);
            }
            strcat(challenge_progress_text_buffer, "\n");
        }
    }
    challenge_mode_state.record_window->append_line((saddr)challenge_progress_text_buffer, 0);
}

void TChallenge::show_challenge_record_window(s32 mode) {
    if (has_window_task_root() == 0) {
        clear_challenge_record_window();
        return;
    }
    if (challenge_mode_state.record_window != NULL) {
        if (mode == 0) {
            challenge_mode_state.record_window->close();
        } else {
            challenge_mode_state.record_window->queue_destruction();
        }
        clear_challenge_record_window();
    }
    switch (mode) {
    case 0:
        return;
    case 1:
        open_challenge_progress_window((void *)0);
        break;
    case 2:
        open_challenge_progress_window((void *)1);
        break;
    default:
        TLobby::open_challenge_window((saddr)this, mode);
        break;
    }
}

void TChallenge::clear_challenge_record_window() {
    challenge_mode_state.record_window_mode = 0;
    challenge_mode_state.record_window = NULL;
}

}
