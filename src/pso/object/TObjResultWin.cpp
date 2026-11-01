#include "pso/object/TObjResultWin.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#pragma defer_codegen off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ControllerInputStateResultWin { s32 value; u8 remaining[0x1AC]; };
extern "C" {
char* TQuestVmDownLoadServer__sub_8006EF6C(s32);
int sprintf(char*, const char*, ...);
int strncmp(const char*, const char*, unsigned long);
char* strncat(char*, const char*, unsigned long);
s32 queue_destruction__7TObjectFv(void*);
s32 TWindowShortListCtrl__check_controller_button(void*, int);
s32 TWindowCtrlMain__sub_8024CE58();
s32 get_window_layout_position(s32);
s32 append_line__14TWindowMessageFii(u32, void*, s32);
u32 create__14TWindowMessageFPvll(s32, void*, s32);
extern ControllerInputStateResultWin controller_input_state;
extern s32 current_lobby_id;
extern TObject* tl_07;
__declspec(section ".rodata") extern const char TObjResultWin_class_name[];
__declspec(section ".rodata") extern const char challenge_result_time_format[];
__declspec(section ".rodata") extern const char challenge_result_total_time_format[];
__declspec(section ".rodata") extern const char challenge_result_indent[];
__declspec(section ".rodata") extern const char challenge_result_equal_time_text[];
__declspec(section ".rodata") extern const char challenge_result_slower_time_format[];
__declspec(section ".rodata") extern const char challenge_result_faster_time_format[];
__declspec(section ".rodata") extern const char challenge_result_value_format[];
__declspec(section ".rodata") extern const char challenge_result_changed_value_format[];
const char* TObjResultWin_name = TObjResultWin_class_name;
__declspec(section ".data") f32 challenge_result_window_extent[2] = {270.0f, 256.0f};
__declspec(section ".sdata2") extern const char challenge_result_rank_none[] = "";
__declspec(section ".sdata2") extern const char challenge_result_rank_b[] = "B";
__declspec(section ".sdata2") extern const char challenge_result_rank_a[] = "A";
__declspec(section ".sdata2") extern const char challenge_result_rank_s[] = "S";
__declspec(section ".data") const char* challenge_result_rank_labels[4] = {
    challenge_result_rank_none, challenge_result_rank_b,
    challenge_result_rank_a, challenge_result_rank_s
};
__declspec(section ".sdata2") extern const char challenge_result_newline[] = "\n";
__declspec(section ".sdata2") extern const f32 challenge_result_split_screen_position;
__declspec(section ".sdata2") extern const f32 challenge_result_window_depth;

void TAdChrSelASlotGC::set_flag_40() { *(u16 *)&this->m_70 |= 0x40; }
int TObjNewFloorWin__sub_8007410C(void) {  return current_lobby_id; }
}

void TObjResultWin::build_result_text() {
    char tmp[0x28];
    s32 h;
    s32 m;
    s32 sec;
    s32 h2;
    s32 m2;
    s32 s2;
    s32 h3;
    s32 m3;
    s32 s3;
    s32 i;
    s32 d;
    char c;
    char *n;
    for (i = 0; i < 0x100; i++) {
        m_text[i] = 0;
    }
    c = m_result.summary.stage_index + '1';
    TQuestVmDownLoadServer::split_time_hms(m_result.current.time, &h, &m, &sec);
    sprintf(tmp, challenge_result_time_format, TQuestVmDownLoadServer__sub_8006EF6C(0x54), TQuestVmDownLoadServer__sub_8006EF6C(0x53), c, h, m, sec);
    strncat(m_text, tmp, 0x30);
    if (m_result.summary.total_time != 0) {
        TQuestVmDownLoadServer::split_time_hms(m_result.summary.total_time, &h2, &m2, &s2);
        sprintf(tmp, challenge_result_total_time_format, TQuestVmDownLoadServer__sub_8006EF6C(0x55), h2, m2, s2);
        strncat(m_text, tmp, 0x30);
    }
    if (m_result.previous.time == 0) {
        strncat(m_text, challenge_result_indent, 0x30);
        strncat(m_text, TQuestVmDownLoadServer__sub_8006EF6C(0x56), 0x30);
    } else {
        d = m_result.current.time - m_result.previous.time;
        if (d == 0) {
            sprintf(tmp, challenge_result_equal_time_text);
        } else if (d >= 0) {
            TQuestVmDownLoadServer::split_time_hms(d, &h3, &m3, &s3);
            sprintf(tmp, challenge_result_slower_time_format, h3, m3, s3);
        } else {
            TQuestVmDownLoadServer::split_time_hms(-d, &h3, &m3, &s3);
            sprintf(tmp, challenge_result_faster_time_format, h3, m3, s3, TQuestVmDownLoadServer__sub_8006EF6C(0x56));
        }
        strncat(m_text, tmp, 0x30);
    }
    strncat(m_text, challenge_result_newline, 2);
    if (TWindowSubStatusDisp::resolve_player_slot(-1) == 0) {
        n = TQuestVmDownLoadServer__sub_8006EF6C(0x57);
        if (m_result.previous.award_name[0] == 0 || strncmp(m_result.previous.award_name, m_result.current.award_name, 0xC) == 0) {
            sprintf(tmp, challenge_result_value_format, n, m_result.current.award_name);
        } else {
            sprintf(tmp, challenge_result_changed_value_format, n, m_result.previous.award_name, m_result.current.award_name);
        }
        strncat(m_text, tmp, 0x30);
        strncat(m_text, challenge_result_newline, 2);
    }
    if (m_result.current.rank != 0) {
        n = TQuestVmDownLoadServer__sub_8006EF6C(0x58);
        if (m_result.previous.rank == 0 || m_result.previous.rank == m_result.current.rank) {
            sprintf(tmp, challenge_result_value_format, n, challenge_result_rank_labels[m_result.current.rank]);
        } else {
            sprintf(tmp, challenge_result_changed_value_format, n, challenge_result_rank_labels[m_result.previous.rank], challenge_result_rank_labels[m_result.current.rank]);
        }
        strncat(m_text, tmp, 0x30);
    }
}
void TObjResultWin::run_task() {
    s32 temp_r0;
    if ((u32) m_window == 0U) {
        if (TWindowCtrlMain__sub_8024CE58() != 0) {
            create_window();
        }
    } else {
        temp_r0 = m_countdown - 1;
        m_countdown = temp_r0;
        if (temp_r0 < 0) {
            m_countdown = 0;
        }
        if ((s32) m_close_requested != 0) {
            if ((s32) m_countdown == 0) {
                ((TWindowBase *)m_window)->close();
                queue_destruction__7TObjectFv(this);
            }
        } else if (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + 0x20), 4) != 0) {
            m_close_requested = 1;
        }
    }
}
void TObjResultWin::create_window() {
    m_window = create__14TWindowMessageFPvll(get_window_layout_position(0x41), challenge_result_window_extent, 1);
    if ((u32) m_window != 0U) {
        if (TCameraCtrl::get_camera_id() == 4) {
            ((TWindowAddition *)m_window)->set_position_xy(challenge_result_split_screen_position, challenge_result_split_screen_position);
        }
        append_line__14TWindowMessageFii(m_window, m_text, 0);
        ((TWindowBase *)m_window)->set_depth(challenge_result_window_depth);
    }
}
TObjResultWin::~TObjResultWin() {}
TObjResultWin::TObjResultWin(TObject* parent, const ChallengeResultRecord* result) : TObject(parent) {
    m_name = TObjResultWin_name;
    m_window = 0;
    copy_challenge_result_record(&m_result, result);
    m_countdown = 60;
    m_close_requested = 0;
    build_result_text();
}
struct ResultCopySummary { s32 stage_index, reserved, total_time; };
struct ResultCopyEntry { s32 words[5]; };
struct ResultCopyRecord { ResultCopySummary summary; ResultCopyEntry previous, current; };
ChallengeResultRecord* copy_challenge_result_record(ChallengeResultRecord* destination, const ChallengeResultRecord* source) {
    ResultCopyRecord* d = (ResultCopyRecord*)destination;
    const ResultCopyRecord* s = (const ResultCopyRecord*)source;
    d->summary = s->summary;
    d->previous = s->previous;
    d->current = s->current;
    return destination;
}

TObjResultWin* TObjResultWin::create(const ChallengeResultRecord* result) {
    return new TObjResultWin(tl_07, result);
}

__declspec(section ".sdata2") extern const f32 challenge_result_split_screen_position = 0.75f;
__declspec(section ".sdata2") extern const f32 challenge_result_window_depth = 36999.0f;
__declspec(section ".rodata") extern const char TObjResultWin_class_name[] = "TObjResultWin";
__declspec(section ".rodata") extern const char challenge_result_time_format[] = "%s < %s%c >\n   %1d'%02d\"%02d\n";
__declspec(section ".rodata") extern const char challenge_result_total_time_format[] = "%s\n  %02d'%02d\"%02d\n";
__declspec(section ".rodata") extern const char challenge_result_indent[] = "    ";
__declspec(section ".rodata") extern const char challenge_result_equal_time_text[] = "   0'00\"00\n";
__declspec(section ".rodata") extern const char challenge_result_slower_time_format[] = "  +%1d'%02d\"%02d\n";
__declspec(section ".rodata") extern const char challenge_result_faster_time_format[] = "  -%1d'%02d\"%02d  %s\n";
__declspec(section ".rodata") extern const char challenge_result_value_format[] = "%s\n  %s\n";
__declspec(section ".rodata") extern const char challenge_result_changed_value_format[] = "%s\n  %s -> %s\n";
