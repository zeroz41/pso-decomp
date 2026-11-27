#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TObject.h"
#include <stdio.h>
#include <string.h>
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TObjBagWarnWin.h"

extern "C" {
__declspec(section ".data") f32 challenge_window_extent[2] = {240.0f, 200.0f};
char challenge_progress_text_buffer[0x100];
const char *challenge_grade_letter_table[4] = {"", "B", "A", "S"};
int TWindowMenu::is_decided() { return (this->menu_flags >> 1) & 0x1; }

}
void format_challenge_stage_times(TChallenge *challenge, s32 challenge_id) {
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
            strcat(challenge_progress_text_buffer, get_player_by_client_id(i)->appearance.name);
            strcat(challenge_progress_text_buffer, "\n  ");
            data = &rec->records;
            slot = challenge_set_rank(data, kind);
            t = decode_challenge_time(challenge_set_stage_times(data, kind)[idx]);
            if (t == 0) {
                strcat(challenge_progress_text_buffer, "      ");
                strcat(challenge_progress_text_buffer, get_message_text(0x51));
                strcat(challenge_progress_text_buffer, "\n");
            } else {
                if ((s32)decode_challenge_count(slot->rank) == 0) {
                    strcat(challenge_progress_text_buffer, "            ");
                } else {
                    p = challenge_set_stage_times(data, kind);
                    sum = 0;
                    n = challenge_set_stage_count(kind);
                    for (j = 0; j < n; j++, p++) {
                        sum += decode_challenge_time(*p);
                    }
                    sl = (s32)decode_challenge_count(slot->rank);
                    split_challenge_time(sum, &h1, &m1, &s1);
                    sprintf(buf2, "%02d'%02d\"%02d %s", h1, m1, s1, challenge_grade_letter_table[sl]);
                    strcat(challenge_progress_text_buffer, buf2);
                }
                strcat(challenge_progress_text_buffer, "  ");
                split_challenge_time(t, &h2, &m2, &s2);
                sprintf(buf1, "%1d'%02d\"%02d\n", h2, m2, s2);
                strcat(challenge_progress_text_buffer, buf1);
            }
        }
    }
}
void open_challenge_window(TChallenge *challenge, s32 challenge_id) {
    TWindowMessage *window;
    window = TWindowMessage::create(get_window_layout_position(0x3B), challenge_window_extent, 1);
    challenge_mode_state.record_window = window;
    if (window == NULL) {
        return;
    }
    window->set_depth(37000.0f);
    if (TCameraCtrl::get_camera_id() >= 2) {
        challenge_mode_state.record_window->set_position_xy(0.75f, 0.75f);
    }
    format_challenge_stage_times(challenge, challenge_id);
    challenge_mode_state.record_window->append_line(challenge_progress_text_buffer, 0);
}
extern "C" {

void TChallenge::open_challenge_progress_window(s32 slot) {
    char tmp[32];
    s32 n;
    ChallengeClientRecords *rec;
    s32 i;
    TWindowMessage *window;
    window = TWindowMessage::create(get_window_layout_position(0x3B), challenge_window_extent, 1);
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
            strcat(challenge_progress_text_buffer, get_player_by_client_id(i)->appearance.name);
            strcat(challenge_progress_text_buffer, "\n    ");
            n = count_cleared_stages(&rec->records, slot);
            if (n >= challenge_set_stage_count(slot)) {
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
    challenge_mode_state.record_window->append_line(challenge_progress_text_buffer, 0);
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
        open_challenge_progress_window(0);
        break;
    case 2:
        open_challenge_progress_window(1);
        break;
    default:
        open_challenge_window(this, mode);
        break;
    }
}

void TChallenge::clear_challenge_record_window() {
    challenge_mode_state.record_window_mode = 0;
    challenge_mode_state.record_window = NULL;
}

}
