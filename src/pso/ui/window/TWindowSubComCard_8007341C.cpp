#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_8007341C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TObject.h"
#include <stdio.h>
#include <string.h>

struct RecoveredGlobal_800739BC_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct Rec_80073738 { s32 flag; u8 data[0x100]; };

struct Chal_80073738 {
    u8 pad0[0x4C];
    void *window;
    u8 pad50[0x270 - 0x50];
    Rec_80073738 recs[4];
};

struct Rec_80073428 { s32 flag; u8 data[0x100]; };

struct Chal_80073428 {
    u8 pad0[0x270];
    Rec_80073428 recs[4];
};

struct Slot_80073428 { s32 a; s32 slot; };

struct Chal_8007369C { u8 pad[0x4C]; void *window; u8 rest[0x748 - 0x50]; };

struct Chal_800738F4 { u8 pad[0x4C]; void *window; u8 rest[0x748 - 0x50]; };

extern "C" {
extern RecoveredGlobal_800739BC_lbl_8048C9D8 challenge_mode_state;
char *get_message_text(s32);
s32 fn_80071A9C(void *, void *, void *);
u8 *get_player_by_client_id(s32);
void *get_window_layout_position(s32);
__declspec(section ".data") f32 challenge_window_extent[2] = {240.0f, 200.0f};
char challenge_progress_text_buffer[0x100];
const char *challenge_grade_letter_table[4] = {"", "B", "A", "S"};
s32 *TWindowSubStatusDisp__sub_8006F0D8(void *, s32);
Slot_80073428 *TWindowSubStatusDisp__sub_8006F134(void *, s32);
s32 has_window_task_root();
int TWindowMenu::is_decided() { return (this->m_70 >> 1) & 0x1; }
LAYOUT_ASSERT(RecoveredGlobal_800739BC_lbl_8048C9D8_size, sizeof(RecoveredGlobal_800739BC_lbl_8048C9D8) == 0x748);

#define CHAL ((Chal_80073738 *)&challenge_mode_state)

#define CHAL_80073428 ((Chal_80073428 *)&challenge_mode_state)
void TAdSinglePlyChrSelectGC::format_challenge_stage_times(s32 arg0, s32 arg1) {
    char buf2[0x18];
    char buf1[0x10];
    s32 h1, m1, s1;
    s32 h2, m2, s2;
    s32 idx;
    s32 kind;
    Rec_80073428 *rec;
    s32 i;
    u8 *data;
    s32 t;
    Slot_80073428 *slot;
    s32 *p;
    s32 sum;
    s32 n;
    s32 j;
    s32 sl;
    if (arg1 >= 3 && arg1 <= 0xB) {
        idx = arg1 - 3;
        kind = 0;
    } else if (arg1 >= 0xC && arg1 <= 0x10) {
        kind = 1;
        idx = arg1 - 0xC;
    }
    sprintf(challenge_progress_text_buffer, "< %s%1d >\n", get_message_text(0x53), idx + 1, 0xFF);
    for (i = 0, rec = CHAL_80073428->recs; i < 4; i++, rec++) {
        if (rec->flag != 0) {
            strcat(challenge_progress_text_buffer, (char *)(get_player_by_client_id(i) + 0x85C));
            strcat(challenge_progress_text_buffer, "\n  ");
            data = rec->data;
            slot = TWindowSubStatusDisp__sub_8006F134(data, kind);
            t = TLobby::get_valid_slot(TWindowSubStatusDisp__sub_8006F0D8(data, kind)[idx]);
            if (t == 0) {
                strcat(challenge_progress_text_buffer, "      ");
                strcat(challenge_progress_text_buffer, get_message_text(0x51));
                strcat(challenge_progress_text_buffer, "\n");
            } else {
                if ((s32)TLobby::get_slot_clamped((u32)(slot->slot)) == 0) {
                    strcat(challenge_progress_text_buffer, "            ");
                } else {
                    p = TWindowSubStatusDisp__sub_8006F0D8(data, kind);
                    sum = 0;
                    n = TWindowSubStatusDisp::get_layout_id(kind);
                    for (j = 0; j < n; j++, p++) {
                        sum += TLobby::get_valid_slot(*p);
                    }
                    sl = (s32)TLobby::get_slot_clamped((u32)(slot->slot));
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

void TLobby::open_challenge_window(s32 lobby, s32 arg1) {
    void *win;
    win = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x3B)), (const f32 *)challenge_window_extent, 1);
    (*(Chal_8007369C *)&challenge_mode_state).window = win;
    if (win == NULL) {
        return;
    }
    ((TWindowBase *)win)->set_depth(37000.0f);
    if (TCameraCtrl::get_camera_id() >= 2) {
        ((TWindowAddition *)((*(Chal_8007369C *)&challenge_mode_state).window))->set_position_xy(0.75f, 0.75f);
    }
    TAdSinglePlyChrSelectGC::format_challenge_stage_times(lobby, arg1);
    ((TWindowMessage *)((*(Chal_8007369C *)&challenge_mode_state).window))->append_line((saddr)challenge_progress_text_buffer, (int)0);
}

void TLobby::open_challenge_progress_window(void *slot) {
    char tmp[32];
    s32 n;
    Rec_80073738 *rec;
    s32 i;
    void *win;
    win = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x3B)), (const f32 *)challenge_window_extent, 1);
    CHAL->window = win;
    if (win == NULL) {
        return;
    }
    ((TWindowBase *)win)->set_depth(37000.0f);
    if (TCameraCtrl::get_camera_id() >= 2) {
        ((TWindowAddition *)(CHAL->window))->set_position_xy(0.75f, 0.75f);
    }
    sprintf(challenge_progress_text_buffer, "< %s >\n", get_message_text(0x4F));
    rec = CHAL->recs;
    for (i = 0; i < 4; i++, rec++) {
        if (rec->flag != 0) {
            strcat(challenge_progress_text_buffer, (char *)(get_player_by_client_id(i) + 0x85C));
            strcat(challenge_progress_text_buffer, "\n    ");
            n = fn_80071A9C(this, rec->data, slot);
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
    ((TWindowMessage *)(CHAL->window))->append_line((saddr)challenge_progress_text_buffer, (int)0);
}

void TLobby__sub_800738F4(void *lobby, s32 arg1) {
    if (has_window_task_root() == 0) {
        ((void (*)(void *))TLobby__sub_800739BC)(lobby);
        return;
    }
    if ((*(Chal_800738F4 *)&challenge_mode_state).window != NULL) {
        if (arg1 == 0) {
            ((TWindowBase *)((*(Chal_800738F4 *)&challenge_mode_state).window))->close();
        } else {
            ((TObject *)((*(Chal_800738F4 *)&challenge_mode_state).window))->queue_destruction();
        }
        ((void (*)(void *))TLobby__sub_800739BC)(lobby);
    }
    switch (arg1) {
    case 0:
        return;
    case 1:
        ((TLobby *)lobby)->open_challenge_progress_window((void *)0);
        break;
    case 2:
        ((TLobby *)lobby)->open_challenge_progress_window((void *)1);
        break;
    default:
        TLobby::open_challenge_window((saddr)lobby, (s32)arg1);
        break;
    }
}

void TLobby__sub_800739BC(void) {
    *(s32 *)((s8 *)&challenge_mode_state.value + 0x48) = 0;
    *(s32 *)((s8 *)&challenge_mode_state.value + 0x4C) = 0;
}

}
