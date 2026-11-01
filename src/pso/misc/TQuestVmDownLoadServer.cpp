#include "pso/TMCFormatSequence.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowBase.h"
#include "pso/unk/text_8007C0CC.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/TObject.h"


#include "types.h"

extern "C" {
s32 wait_confirm_and_finish__17TMCFormatSequenceFPv();
s32 update_wait_confirm__17TMCFormatSequenceFPv();
s32 check_memcard_load_result__17TMCFormatSequenceFv();
s32 process_format_result__17TMCFormatSequenceFv();
s32 open_windows__17TMCFormatSequenceFv();
char TQuestVmDownLoadServer__data_804C8690[0xC] = "\xB8\xB4\xBD\xC4\xCC\xA7\xB2\xD9";
s32 TWindowShortListCtrl__check_controller_button(void*, s32);
struct RecoveredGlobal_801F6C74_lbl_8050E208;
void TQuestVmDownLoadServer__sub_801F6B98(void);
}
extern void *TMCFormatSequence__class_name;
extern RecoveredGlobal_801F6C74_lbl_8050E208 controller_input_state;
extern s32 TQuestVmDownLoadServer__instance;

struct RecoveredGlobal_801F6C74_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct QVm_801F6D24 {
    u8 pad0[0x294];
    u32 f294;
    u8 pad1[4];
    s32 f29C_pad;
    s32 f2A0;
};extern "C" {
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32 arg0);
s32 get_localized_text_entry(s32 arg0, s32 arg1);
void return_to_main_menu__6TLobbyFv(void);
s32 __ct__22TQuestVmDownLoadServerFP7TObject(void *, s32);
void *__nw__7TObjectFUl(s32);
typedef char RecoveredGlobal_801F6C74_lbl_8050E208_size[sizeof(RecoveredGlobal_801F6C74_lbl_8050E208) == 0x1B0 ? 1 : -1];
typedef char RecoveredGlobal_801F6C74_lbl_8050E208_size[sizeof(RecoveredGlobal_801F6C74_lbl_8050E208) == 0x1B0 ? 1 : -1];
}
extern s32 quest_download_in_progress;
extern s32 tl_00;

struct Pair_801F6E08 { s32 a; s32 b; };extern "C" {
s32 create_window__24TMessageWindowControllerFll(void*, s32, void*);
s32 get_window_layout_position(s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
void allow_rendering__7TObjectFv(TObject *);
void queue_destruction__7TObjectFv(void *);
void set_ready__6TSceneFv(void *);
}
extern s32 lbl_8044A668[];
extern s32 lbl_805D55C0;
extern u32 lobby_player_construction_window;
extern s32 lbl_805D49B4;

#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TDLGraph.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/TAdMcSelectGC.h"
#include "pso/ui/TAdWarningBaseGC.h"
#include "pso/ui/TMessageWindowController.h"

struct SubtractiveRng {
    SubtractiveRng();
    s32 value;
    u8 remaining[0xE4];
};

struct RecoveredGlobal_801F84AC_lbl_80512BDC {
    s32 value;
    u8 remaining[0x38];
};

struct QVm_801F7890 {
    u8 pad0[0x25C];
    s32 f25C;
    u8 pad260[0x270 - 0x260];
    char name0[0xD];
    char name1[0xD];
    u8 pad28A[0x2A0 - 0x28A];
    s32 f2A0;
};

struct Req_801F7478 {
    char name[0x12];
    char title[0x22];
    u8 key[0x10];
    char *s44;
    char *s48;
    s16 h4C;
    s16 h4E;
    s32 w50;
    s16 h54;
    s32 w58;
    s32 w5C;
};

struct Req_801F770C {
    char name[0x12];
    char title[0x22];
    u8 key[0x10];
    char *s44;
    char *s48;
    s16 h4C;
    s16 h4E;
    s32 w50;
    s16 h54;
    s32 w58;
    s32 w5C;
};

struct Req_801F718C {
    char name[0x12];
    char title[0x22];
    u8 key[0x10];
    char *s44;
    char *s48;
    s16 h4C;
    s16 h4E;
    s32 w50;
    s16 h54;
    s32 w58;
    s32 w5C;
};

struct Src_801F718C {
    u8 pad0[0x10];
    char title[0x24];
    s32 f34;
    s32 f38;
};

struct QVm_801F7890;
struct QVm_801F6D24;extern "C" {
void *memset(void *, int, u32);
int sprintf(char *, const char *, ...);
void subtractive_rng_seed(SubtractiveRng *, u32);
void TAdPlayerLoadGC__sub_801E14E4(void *);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
s32 build_save_file_image__15TAdPlayerLoadGCFPvPv(void *, void *);
char *strncpy(char *, const char *, u32);
void *memcpy(void *, const void *, u32);
}
extern RecoveredGlobal_801F84AC_lbl_80512BDC quest_download_file_header;
s32 *get_quest_download_file_header(void);
extern const char *TQuestVmDownLoadServer__class_name;
extern char lbl_8044A68C[];
extern char TQuestVmDownLoadServer__data_804C8690[];
extern u8 TQuestVmDownLoadServer__memcard_key[];
extern char TQuestVmDownLoadServer__data_805DC5B8[];
extern char TQuestVmDownLoadServer__data_805DC5BC[];
extern Src_801F718C quest_download_file_info;
extern u8 TQuestVmDownLoadServer__download_kind;
struct Slot_801F7FEC { u8 pad[0x34]; s32 f34; void *f38; };
struct Slot_801F8D30 { u8 pad[0x34]; s32 f34; void *f38; };
extern "C" {
s32 TAdPlayerLoadGC__sub_801E1518(void *, s32, u32);
}
extern s32 TQuestVmDownLoadServer__dat_download_complete;
extern s32 TQuestVmDownLoadServer__bin_download_complete;
extern s32 TQuestVmDownLoadServer__pvr_download_complete;
extern s32 TQuestVmDownLoadServer__gba_download_complete;
extern u32 TQuestVmDownLoadServer__download_window;
extern s32 TQuestVmDownLoadServer__total_download_bytes;
extern s32 TQuestVmDownLoadServer__received_file_bytes;
struct Src_801F8A40 {
    char name[0x10];
    char title[0x24];
    s32 f34;
    void *f38;
};
extern "C" {
Src_801F8A40 TQuestVmDownLoadServer__download_file_state;
Src_801F8A40 quest_download_file_slot;
Src_801F718C quest_download_file_info;
RecoveredGlobal_801F84AC_lbl_80512BDC quest_download_file_header;
SubtractiveRng TQuestVmDownLoadServer__rng_cipher_state;
__declspec(section ".data") u32 download_rng_seed_pair[2];
void disallow_rendering__7TObjectFv(TObject *arg0);
u32 create__13TAdMcSelectGCFPv(s32);
s32 TAdPlayerLoadGC__sub_801E0FA4(s32);
s32 query_memcard_capacity__15TAdPlayerLoadGCFl(s32, int);
u8 *init_shop_judgment_window(void *p);
s32 TQuestVmDownLoadServer__sub_801F8538(void *data, s32 size);
s32 draw_window_bg__23TAdSinglePlyChrSelectGCFllll(s32, void *, s32, s32);
typedef char RecoveredGlobal_801F6C74_lbl_8050E208_size[sizeof(RecoveredGlobal_801F6C74_lbl_8050E208) == 0x1B0 ? 1 : -1];
}
extern s32 tl_03;
typedef char RecoveredGlobal_801F84AC_lbl_80512BDC_size[sizeof(RecoveredGlobal_801F84AC_lbl_80512BDC) == 0x3C ? 1 : -1];
typedef char SubtractiveRng_size[sizeof(SubtractiveRng) == 0xE8 ? 1 : -1];
struct SubtractiveRng;

struct Src_801F87CC {
    u8 pad0[0x10];
    char title[0x24];
    s32 f34;
    u8 *f38;
};
extern "C" {
s32 get_serial_access__22TQuestVmDownLoadServerFv();
s32 poll_serial_access__22TQuestVmDownLoadServerFv();
int strncmp(const char *, const char *, u32);
}

struct Pos_801F8A40 { s32 a, b; };
extern "C" {
u32 set_text__18TWindowMessagePageFlll(void *, void *, int);
char *strtok(char *, const char *);
}
extern u8 lbl_8044A648[];
extern s32 lbl_805DC510;
extern s32 lbl_805DC514;
extern s32 lbl_805DC518;
extern s32 lbl_805DC51C;
extern s32 lbl_805DC520;
extern s32 lbl_805DC524;

struct Src_801F8E4C {
    char name[0x10];
    char title[0x24];
    s32 f34;
    u32 f38;
};

struct Src_801F8F14 {
    char name[0x10];
    char title[0x24];
    s32 f34;
    u32 f38;
};

void TQuestVmDownLoadServer::reset_download_state() {
    TQuestVmDownLoadServer__dat_download_complete = 0;
    TQuestVmDownLoadServer__bin_download_complete = 0;
    TQuestVmDownLoadServer__pvr_download_complete = 0;
    TQuestVmDownLoadServer__gba_download_complete = 0;
    memset(((Src_801F8F14 *)&TQuestVmDownLoadServer__download_file_state), 0, 0x3C);
    memset(((Src_801F8F14 *)&quest_download_file_slot), 0, 0x3C);
    memset(((Src_801F8F14 *)&quest_download_file_info), 0, 0x3C);
    memset(((Src_801F8F14 *)&quest_download_file_header), 0, 0x3C);
    quest_download_in_progress = 0;
    TQuestVmDownLoadServer__total_download_bytes = 0;
    TQuestVmDownLoadServer__received_file_bytes = 0;
}
void TQuestVmDownLoadServer::free_download_buffers() {
    Src_801F8E4C *s0;
    Src_801F8E4C *s1;
    Src_801F8E4C *s2;
    Src_801F8E4C *s3;

    if (TQuestVmDownLoadServer__download_window != 0) {
        ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
        TQuestVmDownLoadServer__download_window = 0;
    }
    s0 = ((Src_801F8E4C *)&TQuestVmDownLoadServer__download_file_state);
    if (s0->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void *)s0->f38));
        s0->f38 = 0;
    }
    s1 = ((Src_801F8E4C *)&quest_download_file_slot);
    if (s1->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void *)s1->f38));
        s1->f38 = 0;
    }
    s2 = ((Src_801F8E4C *)&quest_download_file_info);
    if (s2->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void *)s2->f38));
        s2->f38 = 0;
    }
    s3 = ((Src_801F8E4C *)&quest_download_file_header);
    if (s3->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void *)s3->f38));
        s3->f38 = 0;
    }
    quest_download_in_progress = 0;
    TQuestVmDownLoadServer__total_download_bytes = 0;
    TQuestVmDownLoadServer__received_file_bytes = 0;
    TQuestVmDownLoadServer::reset_download();
}
void TQuestVmDownLoadServer::free_buffers() {
    Slot_801F8D30 *s;

    if (TQuestVmDownLoadServer__download_window != 0U) {
        ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
        TQuestVmDownLoadServer__download_window = 0U;
    }
    s = (Slot_801F8D30 *)&TQuestVmDownLoadServer__download_file_state;
    if (s->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)s->f38);
        s->f38 = 0;
    }
    s = (Slot_801F8D30 *)&quest_download_file_slot;
    if (s->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)s->f38);
        s->f38 = 0;
    }
    s = (Slot_801F8D30 *)&quest_download_file_info;
    if (s->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)s->f38);
        s->f38 = 0;
    }
    s = (Slot_801F8D30 *)&quest_download_file_header;
    if (s->f38 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)s->f38);
        s->f38 = 0;
    }
    TQuestVmDownLoadServer__dat_download_complete = 0;
    TQuestVmDownLoadServer__bin_download_complete = 0;
    TQuestVmDownLoadServer__pvr_download_complete = 0;
    TQuestVmDownLoadServer__gba_download_complete = 0;
    memset(&TQuestVmDownLoadServer__download_file_state, 0, 0x3C);
    memset(&quest_download_file_slot, 0, 0x3C);
    memset(&quest_download_file_info, 0, 0x3C);
    memset(&quest_download_file_header, 0, 0x3C);
    quest_download_in_progress = 0;
    TQuestVmDownLoadServer__total_download_bytes = 0;
    TQuestVmDownLoadServer__received_file_bytes = 0;
    TQuestVmDownLoadServer::reset_download();
}
void TQuestVmDownLoadServer::begin_file_download() {
    u8 *arg0 = (u8 *)this;
    char buf[0x10];
    char *ext;
    Src_801F8A40 *s;

    if (TQuestVmDownLoadServer__download_window == 0) {
        Pos_801F8A40 pos = *(Pos_801F8A40 *)lbl_8044A648;
        TQuestVmDownLoadServer__download_window = set_text__18TWindowMessagePageFlll((void *)get_window_layout_position(0x2F), &pos, 1);
        ((TWindowMessage *)TQuestVmDownLoadServer__download_window)->append_line(TQuestVmDownLoadServer__sub_8006EF6C(0x3E), 0x81);
        ((TWindowMessage *)TQuestVmDownLoadServer__download_window)->complete_reveal();
        TQuestVmDownLoadServer__total_download_bytes = 0;
        TQuestVmDownLoadServer__received_file_bytes = 0;
    }
    if (arg0 != NULL) {
        memset(buf, 0, 0x10);
        strncpy(buf, (char *)(arg0 + 0x28), 0x10);
        strtok(buf, (char *)&lbl_805DC510);
        ext = strtok(NULL, (char *)&lbl_805DC514);
        TQuestVmDownLoadServer__download_kind = arg0[0x26];
        if (strncmp(ext, (char *)&lbl_805DC518, 4) == 0) {
            strncpy(TQuestVmDownLoadServer__download_file_state.name, (char *)(arg0 + 0x28), 0x10);
            strncpy(TQuestVmDownLoadServer__download_file_state.title, (char *)(arg0 + 4), 0x22);
            s = &TQuestVmDownLoadServer__download_file_state;
            s->f34 = *(s32 *)(arg0 + 0x38) + 8;
            s->f38 = TQuestVmDownLoadServer::alloc(s->f34);
            memset(s->f38, 0, s->f34);
            TQuestVmDownLoadServer__dat_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
        } else if (strncmp(ext, (char *)&lbl_805DC51C, 4) == 0) {
            strncpy(quest_download_file_slot.name, (char *)(arg0 + 0x28), 0x10);
            strncpy(quest_download_file_slot.title, (char *)(arg0 + 4), 0x22);
            s = &quest_download_file_slot;
            s->f34 = *(s32 *)(arg0 + 0x38) + 8;
            s->f38 = TQuestVmDownLoadServer::alloc(s->f34);
            memset(s->f38, 0, s->f34);
            TQuestVmDownLoadServer__bin_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
            if ((s8)arg0[0x26] == 0) {
                TDLGraph::update_graph(TQuestVmDownLoadServer__received_file_bytes, TQuestVmDownLoadServer__total_download_bytes);
            }
        } else if (strncmp(ext, (char *)&lbl_805DC520, 4) == 0) {
            strncpy((*(Src_801F8A40 *)&quest_download_file_info).name, (char *)(arg0 + 0x28), 0x10);
            strncpy((*(Src_801F8A40 *)&quest_download_file_info).title, (char *)(arg0 + 4), 0x22);
            (*(Src_801F8A40 *)&quest_download_file_info).f34 = *(s32 *)(arg0 + 0x38);
            (*(Src_801F8A40 *)&quest_download_file_info).f38 = TQuestVmDownLoadServer::alloc((*(Src_801F8A40 *)&quest_download_file_info).f34);
            memset((*(Src_801F8A40 *)&quest_download_file_info).f38, 0, *(s32 *)(arg0 + 0x38));
            TQuestVmDownLoadServer__pvr_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
            if ((s32)arg0[0x26] == 1) {
                TDLGraph::update_graph(TQuestVmDownLoadServer__received_file_bytes, TQuestVmDownLoadServer__total_download_bytes);
            }
        } else if (strncmp(ext, (char *)&lbl_805DC524, 4) == 0) {
            strncpy((*(Src_801F8A40 *)&quest_download_file_header).name, (char *)(arg0 + 0x28), 0x10);
            strncpy((*(Src_801F8A40 *)&quest_download_file_header).title, (char *)(arg0 + 4), 0x22);
            (*(Src_801F8A40 *)&quest_download_file_header).f34 = *(s32 *)(arg0 + 0x38);
            (*(Src_801F8A40 *)&quest_download_file_header).f38 = TQuestVmDownLoadServer::alloc((*(Src_801F8A40 *)&quest_download_file_header).f34);
            TQuestVmDownLoadServer__gba_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
            TDLGraph::update_graph(TQuestVmDownLoadServer__received_file_bytes, TQuestVmDownLoadServer__total_download_bytes);
        }
    }
}
void TQuestVmDownLoadServer::receive_file_chunk() {
    u8 *arg0 = (u8 *)this;
    u8 *dst;
    s32 *flag;
    s32 v;

    if (arg0 != NULL) {
        if (strncmp((char *)((Src_801F87CC *)&TQuestVmDownLoadServer__download_file_state), (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__dat_download_complete;
            dst = (*(Src_801F87CC *)&TQuestVmDownLoadServer__download_file_state).f38 + 8;
        } else if (strncmp((char *)((Src_801F87CC *)&quest_download_file_slot), (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__bin_download_complete;
            dst = (*(Src_801F87CC *)&quest_download_file_slot).f38 + 8;
        } else if (strncmp((char *)((Src_801F87CC *)&quest_download_file_info), (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__pvr_download_complete;
            dst = (*(Src_801F87CC *)&quest_download_file_info).f38;
        } else if (strncmp((char *)((Src_801F87CC *)&quest_download_file_header), (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__gba_download_complete;
            dst = (*(Src_801F87CC *)&quest_download_file_header).f38;
        } else {
            return;
        }
        memcpy(dst + (arg0[1] << 10), (u8 *)&this->m_down, *(u32 *)(arg0 + 0x414));
        TQuestVmDownLoadServer__received_file_bytes += *(u32 *)(arg0 + 0x414);
        TDLGraph::update_graph(TQuestVmDownLoadServer__received_file_bytes, TQuestVmDownLoadServer__total_download_bytes);
        if (*(u32 *)(arg0 + 0x414) < 0x400) {
            *flag = 1;
        }
    }
    switch ((s8)TQuestVmDownLoadServer__download_kind) {
    case 0:
        if (TQuestVmDownLoadServer__dat_download_complete != 0 && TQuestVmDownLoadServer__bin_download_complete != 0) {
            if (TQuestVmDownLoadServer__download_window != 0) {
                ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
                TQuestVmDownLoadServer__download_window = 0;
            }
            v = get_serial_access__22TQuestVmDownLoadServerFv();
            if (v == 0) {
                v = poll_serial_access__22TQuestVmDownLoadServerFv();
            }
            download_rng_seed_pair[1] = v;
            download_rng_seed_pair[0] = v;
            ((TQuestVmDownLoadServer *)((u32 *)(*(Src_801F87CC *)&TQuestVmDownLoadServer__download_file_state).f38))->encrypt_download_data((*(Src_801F87CC *)&TQuestVmDownLoadServer__download_file_state).f34);
            ((TQuestVmDownLoadServer *)((u32 *)(*(Src_801F87CC *)&quest_download_file_slot).f38))->encrypt_download_data((*(Src_801F87CC *)&quest_download_file_slot).f34);
            TQuestVmDownLoadServer::create();
        }
        break;
    case 1:
        if (TQuestVmDownLoadServer__dat_download_complete != 0 && TQuestVmDownLoadServer__bin_download_complete != 0 &&
            TQuestVmDownLoadServer__pvr_download_complete != 0) {
            if (TQuestVmDownLoadServer__download_window != 0) {
                ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
                TQuestVmDownLoadServer__download_window = 0;
            }
            v = get_serial_access__22TQuestVmDownLoadServerFv();
            if (v == 0) {
                v = poll_serial_access__22TQuestVmDownLoadServerFv();
            }
            download_rng_seed_pair[1] = v;
            download_rng_seed_pair[0] = v;
            ((TQuestVmDownLoadServer *)((u32 *)(*(Src_801F87CC *)&TQuestVmDownLoadServer__download_file_state).f38))->encrypt_download_data((*(Src_801F87CC *)&TQuestVmDownLoadServer__download_file_state).f34);
            ((TQuestVmDownLoadServer *)((u32 *)(*(Src_801F87CC *)&quest_download_file_slot).f38))->encrypt_download_data((*(Src_801F87CC *)&quest_download_file_slot).f34);
            TQuestVmDownLoadServer::create();
        }
        break;
    case 2:
        if (TQuestVmDownLoadServer__gba_download_complete != 0) {
            if (TQuestVmDownLoadServer__download_window != 0) {
                ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
                TQuestVmDownLoadServer__download_window = 0;
            }
            TAdWarningBaseGC::create();
        }
        break;
    }
}
void TQuestVmDownLoadServer::encrypt_download_data(s32 size) {
    u32 *body;
    void *src;
    void *dst;
    body = ((u32 *)this) + 1;
    ((u32 *)this)[0] = subtractive_rng_next((s32 *)&TQuestVmDownLoadServer__rng_cipher_state);
    *body = 0;
    *body = TQuestVmDownLoadServer__sub_801F8538(this, size);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, ((u32 *)this)[0]);
    subtractive_rng_xor_buffer((s32 *)&TQuestVmDownLoadServer__rng_cipher_state, (u32 *)body, (s32)((size - 4) & ~3));
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, download_rng_seed_pair[0]);
    ((TAdSinglePlyChrSelectGC *)(&TQuestVmDownLoadServer__rng_cipher_state))->apply_rng_cipher(((u32 *)this), size & ~3);
    src = TQuestVmDownLoadServer::alloc(size);
    dst = TQuestVmDownLoadServer::alloc(size);
    ((TLobby *)src)->move_data((const void *)this, (u32)size);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, download_rng_seed_pair[1]);
    subtractive_rng_make_shuffle((s32 *)&TQuestVmDownLoadServer__rng_cipher_state);
    TAdSinglePlyChrSelectGC::permute_save_blocks(&TQuestVmDownLoadServer__rng_cipher_state, (const u8*)src, (u8*)dst, (u32)size);
    ((TLobby *)this)->move_data((const void *)dst, (u32)size);
    TAdSinglePlyChrSelectGC::safe_free((u32)dst);
    TAdSinglePlyChrSelectGC::safe_free((u32)src);
}
void TQuestVmDownLoadServer::unshuffle_and_decrypt(void *data, s32 size) {
    void *src;
    void *dst;
    src = TQuestVmDownLoadServer::alloc(size);
    dst = TQuestVmDownLoadServer::alloc(size);
    ((TLobby *)src)->move_data((const void *)((u32 *)data), (u32)size);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, download_rng_seed_pair[1]);
    subtractive_rng_make_shuffle((s32 *)&TQuestVmDownLoadServer__rng_cipher_state);
    subtractive_rng_unshuffle((void *)&TQuestVmDownLoadServer__rng_cipher_state, (const u8 *)src, (u8 *)dst, (u32)size);
    ((TLobby *)((u32 *)data))->move_data((const void *)dst, (u32)size);
    TAdSinglePlyChrSelectGC::safe_free((u32)dst);
    TAdSinglePlyChrSelectGC::safe_free((u32)src);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, download_rng_seed_pair[0]);
    ((TAdSinglePlyChrSelectGC *)(&TQuestVmDownLoadServer__rng_cipher_state))->apply_rng_cipher(((u32 *)data), size & ~3);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, ((u32 *)data)[0]);
    subtractive_rng_xor_buffer((s32 *)&TQuestVmDownLoadServer__rng_cipher_state, (u32 *)(((u32 *)data) + 1), (s32)((size - 4) & ~3));
}
s32 TQuestVmDownLoadServer__sub_801F8538(void *data, s32 size) {
    u32 crc = -1;
    u32 i;
    for (i = 0; i < (u32)size; i++) {
        s32 j;
        crc ^= ((u8 *)data)[i];
        for (j = 0; j < 8; j++) {
            u32 bit0 = crc & 1;
            crc >>= 1;
            if (bit0 != 0) {
                crc ^= 0xEDB88320;
            }
        }
    }
    return crc ^ 0xFFFFFFFF;
}
s32 TQuestVmDownLoadServer::verify_checksum(const void *arg0, s32 arg1) {
  s32 temp_r31;
  void *temp_r3;
  s32 temp_r29;
  temp_r3 = TQuestVmDownLoadServer::alloc(arg1);
  if (temp_r3 == 0)
  {
    return 0;
  }
  ((TLobby *)temp_r3)->move_data((const void *)arg0, (u32)arg1);
  temp_r29 = *((s32 *) (((s8 *) temp_r3) + 4));
  *((s32 *) (((s8 *) temp_r3) + 4)) = 0;
  temp_r31 = TQuestVmDownLoadServer__sub_801F8538(temp_r3, arg1);
  TAdSinglePlyChrSelectGC::safe_free((u32)temp_r3);
  return ((u32) __cntlzw((u32) (temp_r31 - temp_r29))) >> 5;
}
s32 *get_quest_download_file_header(void) {
    return &quest_download_file_header.value;
}

TQuestVmDownLoadServer::TQuestVmDownLoadServer(TObject *parent) : TObject(parent) {
    m_name = TQuestVmDownLoadServer__class_name;
    state = 0;
    m_22c = 0;
    m_230 = 0;
    m_234 = 0;
    m_238 = 0;
    m_25c = -1;
    m_260 = NULL;
    memset(m_270, 0, 0xD);
    memset(m_27d, 0, 0xD);
    m_28c = NULL;
    m_290 = NULL;
    m_294 = 0;
    m_29c = NULL;
    TQuestVmDownLoadServer__instance = (s32)this;
    m_298 = 2;
    quest_download_in_progress = 0;
}

TQuestVmDownLoadServer::~TQuestVmDownLoadServer() {
    if (m_260 != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((u32)m_260);
        m_260 = NULL;
    }
    if (m_29c != NULL) {
        queue_destruction__7TObjectFv(m_29c);
        m_29c = NULL;
    }
    if (m_290 != NULL) {
        ((TWindowBase *)m_290)->close();
        m_290 = NULL;
    }
    if (m_28c != NULL) {
        ((TWindowBase *)m_28c)->close();
        m_28c = NULL;
    }
    close_message();
    TQuestVmDownLoadServer__instance = 0;
    quest_download_in_progress = 0;
}

void TQuestVmDownLoadServer::run_task() {
    u8 *arg0 = (u8 *)this;
    ((TQuestVmDownLoadServer *)arg0)->check_client_connections();
    switch (state) {
    case 0:
        ((TQuestVmDownLoadServer *)arg0)->sub_801F7FEC();
        break;
    case 1:
        ((TQuestVmDownLoadServer *)arg0)->close_window();
        break;
    case 2:
        ((TQuestVmDownLoadServer *)arg0)->open();
        break;
    case 3:
        ((TQuestVmDownLoadServer *)arg0)->update_mc_select();
        break;
    case 4:
        if (lbl_805D55C0 != 0) {
            if (m_290 != NULL) {
                ((TObject *)m_290)->suspend_update();
            }
            if (m_29c != NULL) {
                ((TObject *)m_29c)->suspend_update();
            }
        } else {
            if (m_290 != NULL) {
                ((TQuestVmDownLoadServer *)m_290)->clear_flag4_bit4();
            }
            if (m_29c != NULL) {
                ((TQuestVmDownLoadServer *)m_29c)->clear_flag4_bit4();
            }
            ((TQuestVmDownLoadServer *)arg0)->handle_confirm_input();
        }
        break;
    case 5:
        ((TQuestVmDownLoadServer *)arg0)->check_memcard_slot();
        break;
    case 6:
        ((TQuestVmDownLoadServer *)arg0)->handle_confirm_window();
        break;
    case 7:
        ((TQuestVmDownLoadServer *)arg0)->find_free_file_names();
        break;
    case 8:
        ((TQuestVmDownLoadServer *)arg0)->sub_801F770C();
        break;
    case 9:
        ((TQuestVmDownLoadServer *)arg0)->load_quest_data();
        break;
    case 10:
        ((TQuestVmDownLoadServer *)arg0)->abort_download();
        break;
    case 11:
        ((TQuestVmDownLoadServer *)arg0)->write_memcard_file();
        break;
    case 12:
        ((TQuestVmDownLoadServer *)arg0)->write_quest_data_named();
        break;
    case 13:
        ((TQuestVmDownLoadServer *)arg0)->finish_download();
        break;
    case 14:
        ((TQuestVmDownLoadServer *)arg0)->sub_801F718C();
        break;
    case 15:
        ((TQuestVmDownLoadServer *)arg0)->write_quest_data();
        break;
    case 16:
        ((TQuestVmDownLoadServer *)arg0)->close_download();
        break;
    case 19:
        ((TQuestVmDownLoadServer *)arg0)->sub_801F6C74();
        break;
    case 20:
        ((TQuestVmDownLoadServer *)arg0)->check_cancel_input();
        break;
    case 17:
        ((TQuestVmDownLoadServer *)arg0)->close();
        break;
    case 18:
        ((TQuestVmDownLoadServer *)arg0)->sub_801F6D24();
        break;
    case 21:
        ((TQuestVmDownLoadServer *)arg0)->destroy();
        break;
    case 22:
        ((TQuestVmDownLoadServer *)arg0)->close_message();
        break;
    case 23:
        ((TQuestVmDownLoadServer *)arg0)->sub_801F6B00();
        break;
    }
}

void TQuestVmDownLoadServer::sub_801F7FEC() {
    Slot_801F7FEC *s;
    u32 n;

    this->m_230 = 0;
    *(s32 *)&this->unk_264 = 0;
    this->m_268 = 0;
    *(s32 *)&this->unk_26C = 0;
    this->m_298 = 0;
    s = (Slot_801F7FEC *)&TQuestVmDownLoadServer__download_file_state;
    if (s->f34 > 0) {
        n = (u32)TAdPlayerLoadGC__sub_801E1518((void *)1, 0, s->f34);
        if (n != 0xFFFFFF00) {
            this->m_230 += n;
            this->m_268 = n;
            this->m_298 += 1;
        } else {
            this->state = 0x15;
            return;
        }
    }
    s = (Slot_801F7FEC *)&quest_download_file_slot;
    if (s->f34 > 0) {
        n = (u32)TAdPlayerLoadGC__sub_801E1518((void *)1, 0, s->f34);
        if (n != 0xFFFFFF00) {
            this->m_230 += n;
            *(s32 *)&this->unk_264 = n;
            this->m_298 += 1;
        } else {
            this->state = 0x15;
            return;
        }
    }
    s = (Slot_801F7FEC *)&quest_download_file_info;
    if (s->f34 > 0) {
        n = (u32)TAdPlayerLoadGC__sub_801E1518((void *)1, 0, s->f34);
        if (n != 0xFFFFFF00) {
            this->m_230 += n;
            *(s32 *)&this->unk_26C = n;
            this->m_298 += 1;
        } else {
            this->state = 0x15;
            return;
        }
    }
    if (this->m_230 > 0) {
        this->state = 1;
        return;
    }
    this->state = 0x15;
}
void TQuestVmDownLoadServer::close_window() {
    u32 temp_r3;
    this->state = 2;
    temp_r3 = (u32) this->m_290;
    if (temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        this->m_290 = 0U;
    }
    close_message();
    this->m_22c = 0;
    if ((u32) this->m_29c != 0U) {
        TAdMcSelectGC::update_state();
    }
}
void TQuestVmDownLoadServer::update_mc_select() {
    u8 *arg0 = (u8 *)this;
    if (((u32) this->m_294 == 0U) || (((TMessageWindowController *)(arg0 + 0x1C))->is_ready() != 0)) {
        if ((void *) this->m_29c == NULL) {
            TScene::reset_counter();
            if (lobby_player_construction_window != 0) {
                disallow_rendering__7TObjectFv((TObject *)((void *)lobby_player_construction_window));
            }
            *(u32 *)&this->m_29c = create__13TAdMcSelectGCFPv(tl_03);
        }
        if ((void *) this->m_29c != NULL) {
            TAdMcSelectGC::select_if_mc_present();
        }
        if (TWindowShortListCtrl__check_controller_button((void *)((u8 *)&controller_input_state.value + 0x20), 2) != 0) {
            TAdMcSelectGC::select_if_mc_present();
            show_status_message((int) (TQuestVmDownLoadServer__sub_8006EF6C(0x42)), 1);
            this->state = 0x14;
            return;
        }
        if ((u32) this->m_294 == 0U) {
            switch (*(s32 *)((s8 *)arg0 + 0x2A4)) {
            case 0:
                show_status_message((int) (get_localized_text_entry(0x29, 0)), 1);
                return;
            case 1:
                show_status_message((int) (TQuestVmDownLoadServer__sub_8006EF6C(0x45)), 1);
                return;
            case 2:
                show_status_message((int) (TQuestVmDownLoadServer__sub_8006EF6C(0x60)), 1);
                return;
            case 3:
                show_status_message((int) (get_localized_text_entry(0x29, 2)), 1);
                return;
            case 4:
                show_status_message((int) (get_localized_text_entry(0x29, 3)), 1);
                return;
            case 5:
                show_status_message((int) (get_localized_text_entry(0x29, 4)), 1);
                break;
            }
        }
    }
}
void TQuestVmDownLoadServer::open() {
    if ((u32) this->m_29c == 0U) {
        TScene::reset_counter();
        u32 temp_r3 = lobby_player_construction_window;
        if (temp_r3 != 0U) {
            disallow_rendering__7TObjectFv((TObject *)((void *)temp_r3));
        }
        *(u32 *)&this->m_29c = create__13TAdMcSelectGCFPv(tl_03);
    }
    this->state = 4;
    show_status_message(get_localized_text_entry(0x29, 1), 1);
}
void TQuestVmDownLoadServer::handle_confirm_input() {
    u8 *temp_r31;
    temp_r31 = (u8 *)&controller_input_state.value + 0x20;
    if (TWindowShortListCtrl__check_controller_button(temp_r31, 4) != 0) {
        TAdMcSelectGC::select_if_mc_present();
        this->state = 5;
        return;
    }
    if (TWindowShortListCtrl__check_controller_button(temp_r31, 2) != 0) {
        TAdMcSelectGC::select_if_mc_present();
        this->show_status_message((s32)((int) (TQuestVmDownLoadServer__sub_8006EF6C(0x42))), 1);
        this->state = 0x14;
    }
}
#pragma push
#pragma opt_propagation off
void TQuestVmDownLoadServer::check_memcard_slot() {
    u8 *arg0 = (u8 *)this;
    s32 slot;
    s32 cap;
    u8 *seq;
    {
        s32 t = TAdMcSelectGC::get_selected_slot_index();
        slot = t;
    }
    if (TAdPlayerLoadGC::probe_card_slot(slot) != 0 && TAdPlayerLoadGC::probe_and_check_card(slot) != 0) {
        cap = query_memcard_capacity__15TAdPlayerLoadGCFl(slot, 0);
        switch (cap) {
        case -0xFD:
            seq = (u8 *)new TMCFormatSequence((TObject *)(void *)arg0, (void *)(void *)((void *)slot));
            *(void **)((s8 *)seq + 0x1C) = (void *)TQuestVmDownLoadServer__sub_801F6B98;
            *(void **)((s8 *)seq + 0x20) = (void *)TQuestVmDownLoadServer::clear_field2A0;
            this->state = 0x16;
            break;
        case -1:
        case -0xFF:
            return;
        default:
            if (cap < this->m_230) {
                show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0x45), 1);
                this->state = 0x12;
                return;
            }
            if (TAdPlayerLoadGC__sub_801E0FA4(slot) < this->m_298) {
                show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0x60), 1);
                this->state = 0x12;
                return;
            }
            if (this->m_290 != NULL) {
                ((TWindowBase *)this->m_290)->close();
                this->m_290 = NULL;
            }
            *(u32 *)&this->m_290 = (u32)init_shop_judgment_window((void *)(get_window_layout_position(0x2B)));
            show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0x40), 1);
            this->m_25c = slot;
            this->state = 6;
            return;
        }
    } else if (TWindowShortListCtrl__check_controller_button((void *)((u8 *)&controller_input_state + 0x20), 2) != 0) {
        TAdMcSelectGC::update_state();
        show_status_message(get_localized_text_entry(0x29, 1), 1);
        this->state = 4;
    }
}
#pragma pop
void TQuestVmDownLoadServer::handle_confirm_window() {
    s32 selected_menu_value;

    if ((u32) this->m_290 != 0U) {
        if (((TWindowMenu *)(this->m_290))->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)(*(u32 *)&this->m_290))->get_selected_value();
            if (selected_menu_value == 0) {
                if ((u32) this->m_290 != 0U) {
                    ((TWindowBase *)this->m_290)->close();
                    this->m_290 = 0U;
                }
                this->state = 7;
                return;
            }
            if (selected_menu_value == 1) {
                if ((u32) this->m_290 != 0U) {
                    ((TWindowBase *)this->m_290)->close();
                    this->m_290 = 0U;
                }
                if ((u32) this->m_28c != 0U) {
                    ((TWindowMenuIconLine *)(this->m_28c))->clear_decided();
                }
                TAdMcSelectGC::update_state();
                show_status_message(get_localized_text_entry(0x29, 1), 1);
                this->state = 4;
                return;
            }
            goto block_12;
        }
block_12:
        if (((TWindowMenu *)(this->m_290))->is_cancelled() != 0) {
            if ((u32) this->m_290 != 0U) {
                ((TWindowBase *)this->m_290)->close();
                this->m_290 = 0U;
            }
            if ((u32) this->m_28c != 0U) {
                ((TWindowMenuIconLine *)(this->m_28c))->clear_decided();
            }
            TAdMcSelectGC::update_state();
            show_status_message(get_localized_text_entry(0x29, 1), 1);
            this->state = 4;
        }
    }
}
void TQuestVmDownLoadServer::find_free_file_names() {
    QVm_801F7890 *self = (QVm_801F7890 *)this;
    char buf[0xD];
    s32 i;
    memset(self->name0, 0, 0xD);
    memset(self->name1, 0, 0xD);
    for (i = quest_file_first_index; i < quest_file_index_limit; i += 2) {
        memset(buf, 0, 0xD);
        sprintf(buf, lbl_8044A68C, quest_file_prefix, i);
        if (TAdPlayerLoadGC::find_card_file(self->f25C, buf) == 0xFFFFFF05) {
            sprintf(buf, lbl_8044A68C, quest_file_prefix, i + 1);
            if (TAdPlayerLoadGC::find_card_file(self->f25C, buf) == 0xFFFFFF05) {
                sprintf(self->name0, lbl_8044A68C, quest_file_prefix, i);
                sprintf(self->name1, lbl_8044A68C, quest_file_prefix, i + 1);
                self->f2A0 = 8;
                return;
            }
        }
    }
    self->f2A0 = 0x11;
}

void TQuestVmDownLoadServer::sub_801F770C() {
    Req_801F770C req;
    s32 r;
    if (this->m_25c >= 0 && TAdPlayerLoadGC__sub_801E1B50(this->m_25c) == 0) {
        if (*(s32 *)&this->unk_264 > 0) {
            if (this->m_260 != NULL) {
                TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
                this->m_260 = NULL;
            }
            this->m_260 = TQuestVmDownLoadServer::alloc(*(s32 *)&this->unk_264 << 13);
            if (this->m_260 != NULL) {
                memset(&req, 0, sizeof(req));
                strncpy(req.name, TQuestVmDownLoadServer__data_804C8690, 0x12);
                strncpy(req.title, quest_download_file_slot.title, 0x22);
                memcpy(req.key, TQuestVmDownLoadServer__memcard_key, 0x10);
                req.s44 = TQuestVmDownLoadServer__data_805DC5B8;
                req.s48 = TQuestVmDownLoadServer__data_805DC5BC;
                req.h4C = 1;
                req.h4E = 1;
                req.w50 = 0;
                req.h54 = 1;
                req.w58 = (s32)quest_download_file_slot.f38;
                req.w5C = quest_download_file_slot.f34;
                TAdPlayerLoadGC__sub_801E14E8((u8 *)&req, 3);
                r = build_save_file_image__15TAdPlayerLoadGCFPvPv(this->m_260, &req);
                TAdPlayerLoadGC__sub_801E14E4(&req);
                switch (r) {
                case -0x100:
                    this->state = 0x11;
                    break;
                default:
                    if (r != *(s32 *)&this->unk_264) {
                        *(s32 *)&this->unk_264 = r;
                    }
                    this->state = 0x9;
                    break;
                }
            } else {
                this->state = 0x11;
            }
        } else {
            this->state = 0x11;
        }
    }
}
void TQuestVmDownLoadServer::load_quest_data() {
    TAdSinglePlyChrSelectGC::set_quest_download_server(this->m_25c);
    lbl_805D49B4 = 1;
    if (draw_window_bg__23TAdSinglePlyChrSelectGCFllll(this->m_25c, (u8 *)&this->m_270, (s32)(*(s32 *)&this->m_260), (s32)(*(s32 *)&this->unk_264)) == 0) {
        this->state = 0xA;
        show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0xC), 1);
        quest_download_in_progress = 1;
        return;
    }
    show_status_message(get_localized_text_entry(0x29, 2), 1);
    this->state = 0x17;
    lbl_805D49B4 = 0;
}
void TQuestVmDownLoadServer::abort_download() {
    if (TAdPlayerLoadGC__sub_801E1B50(this->m_25c) == 0) {
        TAdSinglePlyChrSelectGC::reset_quest_id();
        if ((u32) this->m_260 != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
            this->m_260 = 0U;
        }
        this->state = 0xB;
        lbl_805D49B4 = 0;
    }
}
void TQuestVmDownLoadServer::write_memcard_file() {
    Req_801F7478 req;
    s32 r;
    if (this->m_25c >= 0 && TAdPlayerLoadGC__sub_801E1B50(this->m_25c) == 0) {
        if (this->m_268 > 0) {
            if (this->m_260 != NULL) {
                TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
                this->m_260 = NULL;
            }
            this->m_260 = TQuestVmDownLoadServer::alloc(this->m_268 << 13);
            if (this->m_260 != NULL) {
                memset(&req, 0, sizeof(req));
                strncpy(req.name, TQuestVmDownLoadServer__data_804C8690, 0x12);
                strncpy(req.title, TQuestVmDownLoadServer__download_file_state.title, 0x22);
                memcpy(req.key, TQuestVmDownLoadServer__memcard_key, 0x10);
                req.s44 = TQuestVmDownLoadServer__data_805DC5B8;
                req.s48 = TQuestVmDownLoadServer__data_805DC5BC;
                req.h4C = 1;
                req.h4E = 1;
                req.w50 = 0;
                req.h54 = 1;
                req.w58 = (s32)TQuestVmDownLoadServer__download_file_state.f38;
                req.w5C = TQuestVmDownLoadServer__download_file_state.f34;
                TAdPlayerLoadGC__sub_801E14E8((u8 *)&req, 3);
                r = build_save_file_image__15TAdPlayerLoadGCFPvPv(this->m_260, &req);
                TAdPlayerLoadGC__sub_801E14E4(&req);
                switch (r) {
                case -0x100:
                    this->state = 0x11;
                    break;
                default:
                    if (r != this->m_268) {
                        this->m_268 = r;
                    }
                    this->state = 0xC;
                    break;
                }
            } else {
                this->state = 0x11;
            }
        } else {
            this->state = 0x11;
        }
    }
}
void TQuestVmDownLoadServer::write_quest_data_named() {
    TAdSinglePlyChrSelectGC::set_quest_download_server(this->m_25c);
    lbl_805D49B4 = 1;
    if (draw_window_bg__23TAdSinglePlyChrSelectGCFllll(this->m_25c, (u8 *)&this->m_27d, (s32)this->m_260, this->m_268) == 0) {
        this->state = 0xD;
        show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0xC), 1);
        return;
    }
    show_status_message(get_localized_text_entry(0x29, 2), 1);
    this->state = 0x17;
    lbl_805D49B4 = 0;
}
void TQuestVmDownLoadServer::finish_download() {
    if (TAdPlayerLoadGC__sub_801E1B50(this->m_25c) == 0) {
        TAdSinglePlyChrSelectGC::reset_quest_id();
        if ((u32) this->m_260 != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
            this->m_260 = 0U;
        }
        if ((u32) this->m_28c != 0U) {
            ((TWindowMenuIconLine *)(this->m_28c))->clear_decided();
        }
        this->state = 0xE;
        lbl_805D49B4 = 0;
    }
}
void TQuestVmDownLoadServer::sub_801F718C() {
    Req_801F718C req;
    s32 r;
    if ((s32)TQuestVmDownLoadServer__download_kind != 1) {
        this->show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0x41), 1);
        this->state = 0x13;
        return;
    }
    if (this->m_25c >= 0 && quest_download_file_info.f34 > 0) {
        if (TAdPlayerLoadGC__sub_801E1B50(this->m_25c) == 0) {
            if (*(s32 *)&this->unk_26C > 0) {
                if (this->m_260 != NULL) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
                    this->m_260 = NULL;
                }
                this->m_260 = TQuestVmDownLoadServer::alloc(*(s32 *)&this->unk_26C << 13);
                if (this->m_260 != NULL) {
                    memset(&req, 0, sizeof(req));
                    strncpy(req.name, TQuestVmDownLoadServer__data_804C8690, 0x12);
                    strncpy(req.title, quest_download_file_info.title, 0x22);
                    memcpy(req.key, TQuestVmDownLoadServer__memcard_key, 0x10);
                    req.s44 = TQuestVmDownLoadServer__data_805DC5B8;
                    req.s48 = TQuestVmDownLoadServer__data_805DC5BC;
                    req.h4C = 1;
                    req.h4E = 1;
                    req.w50 = 0;
                    req.h54 = 1;
                    req.w58 = quest_download_file_info.f38;
                    req.w5C = quest_download_file_info.f34;
                    TAdPlayerLoadGC__sub_801E14E8((u8 *)&req, 3);
                    r = build_save_file_image__15TAdPlayerLoadGCFPvPv(this->m_260, &req);
                    TAdPlayerLoadGC__sub_801E14E4(&req);
                    switch (r) {
                    case -0x100:
                        this->state = 0x11;
                        break;
                    default:
                        if (r != *(s32 *)&this->unk_26C) {
                            *(s32 *)&this->unk_26C = r;
                        }
                        this->state = 0xF;
                        break;
                    }
                } else {
                    this->state = 0x11;
                }
            } else {
                this->state = 0x11;
            }
        }
    } else {
        this->state = 0x11;
    }
}
void TQuestVmDownLoadServer::write_quest_data() {
    TAdSinglePlyChrSelectGC::set_quest_download_server(this->m_25c);
    lbl_805D49B4 = 1;
    if (draw_window_bg__23TAdSinglePlyChrSelectGCFllll(this->m_25c, (void *)quest_file_99_name, (s32)(*(s32 *)&this->m_260), (s32)(*(s32 *)&this->unk_26C)) == 0) {
        this->state = 0x10;
        show_status_message(TQuestVmDownLoadServer__sub_8006EF6C(0xC), 1);
        return;
    }
    show_status_message(get_localized_text_entry(0x29, 2), 1);
    this->state = 0x17;
    lbl_805D49B4 = 0;
}
void TQuestVmDownLoadServer::close_download() {
    if (TAdPlayerLoadGC__sub_801E1B50(this->m_25c) == 0) {
        TAdSinglePlyChrSelectGC::reset_quest_id();
        if ((u32) this->m_260 != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
            this->m_260 = 0U;
        }
        if ((u32) this->m_28c != 0U) {
            ((TWindowMenuIconLine *)(this->m_28c))->clear_decided();
        }
        show_status_message((s32)(TQuestVmDownLoadServer__sub_8006EF6C(0x41)), 1);
        this->state = 0x13;
        lbl_805D49B4 = 0;
    }
}
void TQuestVmDownLoadServer::destroy() {
    set_ready__6TSceneFv(this);
    if (lobby_player_construction_window != 0) {
        allow_rendering__7TObjectFv((TObject *)((void *)lobby_player_construction_window));
    }
    TQuestVmDownLoadServer::free_buffers();
    queue_destruction__7TObjectFv(this);
}
void TQuestVmDownLoadServer::close() {
    if ((u32) this->m_260 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)this->m_260);
        this->m_260 = 0U;
    }
    if ((u32) this->m_28c != 0U) {
        ((TWindowMenuIconLine *)(this->m_28c))->clear_decided();
    }
    TAdMcSelectGC::update_state();
    show_status_message((s32)(get_localized_text_entry(0x29, 1)), 1);
    this->state = 4;
    quest_download_in_progress = 0;
}
void TQuestVmDownLoadServer::check_client_connections() {
    s32 temp_r0;
    s32 temp_r3;
    s32 var_r30;

    temp_r0 = this->state;
    if ((temp_r0 == 0) || (temp_r0 == 0x15) || (temp_r0 == 0x16)) {
        return;
    }
    {
        if ((s32) lbl_805D55C0 != 0) {
            if ((u32) this->m_29c != 0U) {
                ((TObject *)(this->m_29c))->suspend_update();
            }
        } else {
            if ((u32) this->m_29c != 0U) {
                ((TQuestVmDownLoadServer *)(this->m_29c))->clear_flag4_bit4();
            }
            var_r30 = 0;
            this->m_234 = 0;
            do {
                if (TAdPlayerLoadGC::probe_card_slot(var_r30) != 0) {
                    this->m_234 = (s32) (this->m_234 | (1 << var_r30));
                }
                var_r30 += 1;
            } while (var_r30 < 8);
            temp_r3 = this->m_234;
            if (temp_r3 != (s32) this->m_238) {
                this->m_238 = temp_r3;
                if ((s32) quest_download_in_progress != 0) {
                    quest_download_in_progress = 0;
                    show_status_message((s32)(TQuestVmDownLoadServer__sub_8006EF6C(0xB)), 1);
                    this->state = 0x12;
                } else {
                    this->state = 1;
                }
            }
        }
    }
}
void TQuestVmDownLoadServer::show_status_message(s32 text, s32 arg2) {
    u8*arg0 = (u8*)this;
    Pair_801F6E08 sp;
    if (*(u32*)(arg0 + 0x294) == 0) {
        sp.a = lbl_8044A668[0];
        sp.b = lbl_8044A668[1];
        *(s32*)(arg0 + 0x294) = create_window__24TMessageWindowControllerFll(arg0 + 0x1C, get_window_layout_position(0x2F), &sp);
    }
    ((TMessageWindowController *)(arg0 + 0x1C))->display_message((const char *)text, (s32)(arg2 | 0x80));
}
void TQuestVmDownLoadServer::close_message() { if (*(unsigned int *)&this->m_294 != 0) { ((TMessageWindowController *)((char*)this + 0x1c))->close(); *(int *)&this->m_294 = 0; } }
void TQuestVmDownLoadServer::sub_801F6D24() {
    u8 *p;
    if (((QVm_801F6D24 *)this)->f294 == 0 || ((TMessageWindowController *)((u8 *)((QVm_801F6D24 *)this) + 0x1C))->is_ready() != 0) {
        p = ((u8 *)&controller_input_state) + 0x20;
        if (TWindowShortListCtrl__check_controller_button(p, 4) != 0 || TWindowShortListCtrl__check_controller_button(p, 2) != 0) {
            TAdMcSelectGC::update_state();
            this->show_status_message((int)(get_localized_text_entry(0x29, 1)), 1);
            ((QVm_801F6D24 *)this)->f2A0 = 4;
        }
    }
}
void TQuestVmDownLoadServer::sub_801F6C74() {
    u8 *temp_r31;
    temp_r31 = (u8 *)&controller_input_state.value + 0x20;
    quest_download_in_progress = 0;
    if (TWindowShortListCtrl__check_controller_button(temp_r31, 4) != 0) {
        TAdMcSelectGC::update_state();
        this->show_status_message((int) (get_localized_text_entry(0x29, 1)), 1);
        this->state = 4;
    }
    if (TWindowShortListCtrl__check_controller_button(temp_r31, 2) != 0) {
        TAdMcSelectGC::select_if_mc_present();
        this->show_status_message((int) (TQuestVmDownLoadServer__sub_8006EF6C(0x42)), 1);
        this->state = 0x14;
    }
}
void TQuestVmDownLoadServer::check_cancel_input() {
    u8 *temp_r31;
    temp_r31 = (u8 *)&(*(RecoveredGlobal_801F6C74_lbl_8050E208 *)&controller_input_state).value + 0x20;
    if ((TWindowShortListCtrl__check_controller_button(temp_r31, 4) != 0) || (TWindowShortListCtrl__check_controller_button(temp_r31, 2) != 0)) {
        return_to_main_menu__6TLobbyFv();
        this->state = 0x15;
    }
}
void TQuestVmDownLoadServer::create() {
    void *quest_vm_down_load_server;

    if ((u32) TQuestVmDownLoadServer__instance == 0U) {
        quest_vm_down_load_server = __nw__7TObjectFUl(0x2A8);
        if (quest_vm_down_load_server != 0) {
            __ct__22TQuestVmDownLoadServerFP7TObject(quest_vm_down_load_server, tl_00);
        }
    }
}
s32 TQuestVmDownLoadServer::get_field230() {
    if ((void *) TQuestVmDownLoadServer__instance != NULL) {
        return *(s32 *)((s8 *)TQuestVmDownLoadServer__instance + 0x230);
    }
    return 0;
}
void TQuestVmDownLoadServer__sub_801F6B98(void) {
    if ((void *) TQuestVmDownLoadServer__instance != NULL) {
        *(s32 *)((s8 *)TQuestVmDownLoadServer__instance + 0x2A0) = 0;
    }
}
void TQuestVmDownLoadServer::clear_field2A0() {
    if ((void *) TQuestVmDownLoadServer__instance != NULL) {
        *(s32 *)((s8 *)TQuestVmDownLoadServer__instance + 0x2A0) = 0;
    }
}
void TQuestVmDownLoadServer::sub_801F6B00() {
    if (*(u32 *)&this->m_294 == 0 || ((TMessageWindowController *)(((u8*)this) + 0x1C))->is_ready() != 0) {
        void* p = (u8 *)&controller_input_state + 0x20;
        if (TWindowShortListCtrl__check_controller_button(p, 4) != 0 || TWindowShortListCtrl__check_controller_button(p, 2) != 0) {
            this->state = 0x11;
        }
    }
}
TMCFormatSequence::TMCFormatSequence(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TMCFormatSequence__class_name;
    this->m_24 = 0;
    *(void **)((s8 *)this + 0x28) = arg2;
    *(u32 *)((s8 *)this + 0x1C) = 0;
    this->m_20 = 0;
    this->m_34 = 0;
    *(u32 *)((s8 *)this + 0x38) = 0;
    this->m_2c = 11;
    *(u32 *)((s8 *)this + 0x30) = 101;
}
TMCFormatSequence::~TMCFormatSequence() {
    if (m_38 != nullptr) { ((TWindowBase *)m_38)->close(); m_38 = nullptr; }
    close_window();
}
void TMCFormatSequence::run_task() {
    switch (this->m_24) {
    case 0:
        open_windows__17TMCFormatSequenceFv();
        return;
    case 1:
        process_format_result__17TMCFormatSequenceFv();
        return;
    case 2:
        check_memcard_load_result__17TMCFormatSequenceFv();
        return;
    case 3:
        wait_confirm_and_finish__17TMCFormatSequenceFPv();
        return;
    case 4:
        update_wait_confirm__17TMCFormatSequenceFPv();
        return;
    }
}
