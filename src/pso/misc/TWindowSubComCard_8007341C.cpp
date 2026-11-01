#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_8007341C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

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
char *TQuestVmDownLoadServer__sub_8006EF6C(s32);
s32 get_layout_id__20TWindowSubStatusDispFv(void *);
s32 fn_80071A9C(void *, void *, void *);
u8 *get_player_by_client_id(s32);
void append_line__14TWindowMessageFii(void *, char *, s32);
void *create__14TWindowMessageFPvll(void *, void *, s32);
void *get_window_layout_position(s32);
int sprintf(char *, const char *, ...);
char *strcat(char *, const char *);
extern char lbl_80438628[];
extern char lbl_80438630[];
extern char lbl_80438638[];
extern u8 challenge_window_extent[];
extern char challenge_progress_text_buffer[];
extern char lbl_805D912C[2];
extern const f32 lbl_805D9134;
extern const f32 lbl_805D9138;
s32 *TWindowSubStatusDisp__sub_8006F0D8(void *, s32);
Slot_80073428 *TWindowSubStatusDisp__sub_8006F134(void *, s32);
s32 get_slot_clamped__6TLobbyFv(s32);
extern char lbl_804385E0[];
extern char lbl_804385EC[];
extern char lbl_804385F4[];
extern char lbl_80438604[];
extern char lbl_80438618[];
extern s32 challenge_grade_letter_table[];
extern char lbl_805D9128[2];
extern char lbl_805D9130[2];
s32 TWindowCtrlMain__sub_8024CE58();
int TWindowMenu::is_decided() { return (this->m_70 >> 1) & 0x1; }
typedef char RecoveredGlobal_800739BC_lbl_8048C9D8_size[sizeof(RecoveredGlobal_800739BC_lbl_8048C9D8) == 0x748 ? 1 : -1];

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
    sprintf(challenge_progress_text_buffer, lbl_804385E0, TQuestVmDownLoadServer__sub_8006EF6C(0x53), idx + 1, 0xFF);
    for (i = 0, rec = CHAL_80073428->recs; i < 4; i++, rec++) {
        if (rec->flag != 0) {
            strcat(challenge_progress_text_buffer, (char *)(get_player_by_client_id(i) + 0x85C));
            strcat(challenge_progress_text_buffer, lbl_805D9128);
            data = rec->data;
            slot = TWindowSubStatusDisp__sub_8006F134(data, kind);
            t = TLobby::get_valid_slot(TWindowSubStatusDisp__sub_8006F0D8(data, kind)[idx]);
            if (t == 0) {
                strcat(challenge_progress_text_buffer, lbl_804385EC);
                strcat(challenge_progress_text_buffer, TQuestVmDownLoadServer__sub_8006EF6C(0x51));
                strcat(challenge_progress_text_buffer, lbl_805D912C);
            } else {
                if (get_slot_clamped__6TLobbyFv(slot->slot) == 0) {
                    strcat(challenge_progress_text_buffer, lbl_804385F4);
                } else {
                    p = TWindowSubStatusDisp__sub_8006F0D8(data, kind);
                    sum = 0;
                    n = ((s32 (*)(s32))get_layout_id__20TWindowSubStatusDispFv)(kind);
                    for (j = 0; j < n; j++, p++) {
                        sum += TLobby::get_valid_slot(*p);
                    }
                    sl = get_slot_clamped__6TLobbyFv(slot->slot);
                    TQuestVmDownLoadServer::split_time_hms(sum, &h1, &m1, &s1);
                    sprintf(buf2, lbl_80438604, h1, m1, s1, challenge_grade_letter_table[sl]);
                    strcat(challenge_progress_text_buffer, buf2);
                }
                strcat(challenge_progress_text_buffer, lbl_805D9130);
                TQuestVmDownLoadServer::split_time_hms(t, &h2, &m2, &s2);
                sprintf(buf1, lbl_80438618, h2, m2, s2);
                strcat(challenge_progress_text_buffer, buf1);
            }
        }
    }
}

void TLobby::open_challenge_window(s32 arg0, s32 arg1) {
    void *win;
    win = create__14TWindowMessageFPvll(get_window_layout_position(0x3B), challenge_window_extent, 1);
    (*(Chal_8007369C *)&challenge_mode_state).window = win;
    if (win == NULL) {
        return;
    }
    ((TWindowBase *)win)->set_depth(lbl_805D9134);
    if (TCameraCtrl::get_camera_id() >= 2) {
        ((TWindowAddition *)((*(Chal_8007369C *)&challenge_mode_state).window))->set_position_xy(lbl_805D9138, lbl_805D9138);
    }
    TAdSinglePlyChrSelectGC::format_challenge_stage_times(arg0, arg1);
    append_line__14TWindowMessageFii((*(Chal_8007369C *)&challenge_mode_state).window, challenge_progress_text_buffer, 0);
}

void TLobby::open_challenge_progress_window(void *arg1) {
    char tmp[32];
    s32 n;
    Rec_80073738 *rec;
    s32 i;
    void *win;
    win = create__14TWindowMessageFPvll(get_window_layout_position(0x3B), challenge_window_extent, 1);
    CHAL->window = win;
    if (win == NULL) {
        return;
    }
    ((TWindowBase *)win)->set_depth(lbl_805D9134);
    if (TCameraCtrl::get_camera_id() >= 2) {
        ((TWindowAddition *)(CHAL->window))->set_position_xy(lbl_805D9138, lbl_805D9138);
    }
    sprintf(challenge_progress_text_buffer, lbl_80438628, TQuestVmDownLoadServer__sub_8006EF6C(0x4F));
    rec = CHAL->recs;
    for (i = 0; i < 4; i++, rec++) {
        if (rec->flag != 0) {
            strcat(challenge_progress_text_buffer, (char *)(get_player_by_client_id(i) + 0x85C));
            strcat(challenge_progress_text_buffer, lbl_80438630);
            n = fn_80071A9C(this, rec->data, arg1);
            if (n >= get_layout_id__20TWindowSubStatusDispFv(arg1)) {
                strcat(challenge_progress_text_buffer, TQuestVmDownLoadServer__sub_8006EF6C(0x52));
            } else if (n == 0) {
                strcat(challenge_progress_text_buffer, TQuestVmDownLoadServer__sub_8006EF6C(0x51));
            } else {
                sprintf(tmp, lbl_80438638, TQuestVmDownLoadServer__sub_8006EF6C(0x50), n);
                strcat(challenge_progress_text_buffer, tmp);
            }
            strcat(challenge_progress_text_buffer, lbl_805D912C);
        }
    }
    append_line__14TWindowMessageFii(CHAL->window, challenge_progress_text_buffer, 0);
}

void TLobby__sub_800738F4(void *lobby, s32 arg1) {
    if (TWindowCtrlMain__sub_8024CE58() == 0) {
        ((void (*)(void *))TLobby__sub_800739BC)(lobby);
        return;
    }
    if ((*(Chal_800738F4 *)&challenge_mode_state).window != NULL) {
        if (arg1 == 0) {
            ((TWindowBase *)((*(Chal_800738F4 *)&challenge_mode_state).window))->close();
        } else {
            queue_destruction__7TObjectFv((*(Chal_800738F4 *)&challenge_mode_state).window);
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
        TLobby::open_challenge_window((s32)lobby, (s32)arg1);
        break;
    }
}

void TLobby__sub_800739BC(void) {
    *(s32 *)((s8 *)&challenge_mode_state.value + 0x48) = 0;
    *(s32 *)((s8 *)&challenge_mode_state.value + 0x4C) = 0;
}

}
