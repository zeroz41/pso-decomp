#include "pso/system/save/CardSaveFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include <stdio.h>
#include <string.h>
#include "pso/system/TMCFormatSequence.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/text_8007C0CC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/system/task/TObject.h"


#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"

// .rodata 0x8044A648: window_size {444,84} (the layout position is the other argument), "TQuestVmDownLoadServer", window_size, "TMCFormatSequence", window_size,
// "%s%02d". The positions interleave with the class names, so they are function statics (emitted while parsing,
// like the class-name strings) rather than aggregate literals (emitted with the code, after them). The short
// strings "." "" "dat" "bin" "pvr" "gba" go to .sdata2 0x805DC510.
#pragma readonly_strings on
#pragma dont_reuse_strings off


extern "C" {
char TQuestVmDownLoadServer__data_804C8690[0xC] = "\xB8\xB4\xBD\xC4\xCC\xA7\xB2\xD9";
void TQuestVmDownLoadServer__sub_801F6B98(TMCFormatSequence *);
}
// This TU's .sbss, 0x805D5F00-0x805D5F28 (address order).
s32 TQuestVmDownLoadServer__dat_download_complete;
s32 TQuestVmDownLoadServer__bin_download_complete;
s32 TQuestVmDownLoadServer__pvr_download_complete;
s32 TQuestVmDownLoadServer__gba_download_complete;
u8 TQuestVmDownLoadServer__download_kind;
uaddr TQuestVmDownLoadServer__download_window;
s32 quest_download_in_progress;
s32 TQuestVmDownLoadServer__total_download_bytes;
s32 TQuestVmDownLoadServer__received_file_bytes;
TQuestVmDownLoadServer *TQuestVmDownLoadServer__instance;

extern TObject *tl_00;

struct Pair_801F6E08 { f32 a; f32 b; };extern "C" {
saddr get_window_layout_position(s32);
s32 poll_memcard_result(saddr);
}
extern s32 lbl_805D55C0;
extern uaddr lobby_player_construction_window;
extern s32 lbl_805D49B4;


#include "pso/render/TDLGraph.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/ui/window/TWindowMessagePage.h"

struct SubtractiveRng {
    SubtractiveRng();
    s32 value;
    u8 remaining[0xE4];
};



extern "C" {
void subtractive_rng_seed(SubtractiveRng *, u32);
}
extern char TQuestVmDownLoadServer__data_804C8690[];
extern u8 TQuestVmDownLoadServer__memcard_key[];
QuestDownloadRecord TQuestVmDownLoadServer__download_file_state;
QuestDownloadRecord quest_download_file_slot;
QuestDownloadRecord quest_download_file_info;
QuestDownloadRecord quest_download_file_header;
SubtractiveRng TQuestVmDownLoadServer__rng_cipher_state;
__declspec(section ".data") u32 download_rng_seed_pair[2];
extern "C" {
s32 get_memcard_free_files(s32);
u8 *init_shop_judgment_window(void *p);
s32 TQuestVmDownLoadServer__sub_801F8538(void *data, s32 size);
}
extern TObject *tl_03;
LAYOUT_ASSERT(SubtractiveRng_size, sizeof(SubtractiveRng) == 0xE8);
struct SubtractiveRng;

struct Pos_801F8A40 { f32 a, b; };
extern "C" {
char *strtok(char *, const char *);
}

void TQuestVmDownLoadServer::reset_download_state() {
    TQuestVmDownLoadServer__dat_download_complete = 0;
    TQuestVmDownLoadServer__bin_download_complete = 0;
    TQuestVmDownLoadServer__pvr_download_complete = 0;
    TQuestVmDownLoadServer__gba_download_complete = 0;
    memset(&TQuestVmDownLoadServer__download_file_state, 0, sizeof(TQuestVmDownLoadServer__download_file_state));
    memset(&quest_download_file_slot, 0, sizeof(quest_download_file_slot));
    memset(&quest_download_file_info, 0, sizeof(quest_download_file_info));
    memset(&quest_download_file_header, 0, sizeof(quest_download_file_header));
    quest_download_in_progress = 0;
    TQuestVmDownLoadServer__total_download_bytes = 0;
    TQuestVmDownLoadServer__received_file_bytes = 0;
}
void TQuestVmDownLoadServer::free_download_buffers() {
    QuestDownloadRecord *s0;
    QuestDownloadRecord *s1;
    QuestDownloadRecord *s2;
    QuestDownloadRecord *s3;

    if (TQuestVmDownLoadServer__download_window != 0) {
        ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
        TQuestVmDownLoadServer__download_window = 0;
    }
    s0 = &TQuestVmDownLoadServer__download_file_state;
    if (s0->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s0->data);
        s0->data = 0;
    }
    s1 = &quest_download_file_slot;
    if (s1->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s1->data);
        s1->data = 0;
    }
    s2 = &quest_download_file_info;
    if (s2->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s2->data);
        s2->data = 0;
    }
    s3 = &quest_download_file_header;
    if (s3->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s3->data);
        s3->data = 0;
    }
    quest_download_in_progress = 0;
    TQuestVmDownLoadServer__total_download_bytes = 0;
    TQuestVmDownLoadServer__received_file_bytes = 0;
    TQuestVmDownLoadServer::reset_download();
}
void TQuestVmDownLoadServer::free_buffers() {
    QuestDownloadRecord *s;

    if (TQuestVmDownLoadServer__download_window != 0U) {
        ((TWindowBase *)TQuestVmDownLoadServer__download_window)->close();
        TQuestVmDownLoadServer__download_window = 0U;
    }
    s = &TQuestVmDownLoadServer__download_file_state;
    if (s->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s->data);
        s->data = 0;
    }
    s = &quest_download_file_slot;
    if (s->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s->data);
        s->data = 0;
    }
    s = &quest_download_file_info;
    if (s->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s->data);
        s->data = 0;
    }
    s = &quest_download_file_header;
    if (s->data != 0) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)s->data);
        s->data = 0;
    }
    TQuestVmDownLoadServer__dat_download_complete = 0;
    TQuestVmDownLoadServer__bin_download_complete = 0;
    TQuestVmDownLoadServer__pvr_download_complete = 0;
    TQuestVmDownLoadServer__gba_download_complete = 0;
    memset(&TQuestVmDownLoadServer__download_file_state, 0, sizeof(TQuestVmDownLoadServer__download_file_state));
    memset(&quest_download_file_slot, 0, sizeof(quest_download_file_slot));
    memset(&quest_download_file_info, 0, sizeof(quest_download_file_info));
    memset(&quest_download_file_header, 0, sizeof(quest_download_file_header));
    quest_download_in_progress = 0;
    TQuestVmDownLoadServer__total_download_bytes = 0;
    TQuestVmDownLoadServer__received_file_bytes = 0;
    TQuestVmDownLoadServer::reset_download();
}
void TQuestVmDownLoadServer::begin_file_download() {
    u8 *arg0 = (u8 *)this;
    char buf[0x10];
    char *ext;
    QuestDownloadRecord *s;

    if (TQuestVmDownLoadServer__download_window == 0) {
        static const Pos_801F8A40 window_size = {444.0f, 84.0f};
        Pos_801F8A40 pos = window_size;
        TQuestVmDownLoadServer__download_window = (uaddr)TWindowMessagePage::set_text((s32)get_window_layout_position(0x2F), (saddr)&pos, 1);
        ((TWindowMessage *)TQuestVmDownLoadServer__download_window)->append_line(get_message_text(0x3E), 0x81);
        ((TWindowMessage *)TQuestVmDownLoadServer__download_window)->complete_reveal();
        TQuestVmDownLoadServer__total_download_bytes = 0;
        TQuestVmDownLoadServer__received_file_bytes = 0;
    }
    if (arg0 != NULL) {
        memset(buf, 0, 0x10);
        strncpy(buf, (char *)(arg0 + 0x28), 0x10);
        strtok(buf, ".");
        ext = strtok(NULL, "");
        TQuestVmDownLoadServer__download_kind = arg0[0x26];
        if (strncmp(ext, "dat", 4) == 0) {
            strncpy(TQuestVmDownLoadServer__download_file_state.name, (char *)(arg0 + 0x28), 0x10);
            strncpy(TQuestVmDownLoadServer__download_file_state.title, (char *)(arg0 + 4), 0x22);
            s = &TQuestVmDownLoadServer__download_file_state;
            s->size = *(s32 *)(arg0 + 0x38) + 8;
            s->data = (u8 *)TQuestVmDownLoadServer::alloc(s->size);
            memset(s->data, 0, s->size);
            TQuestVmDownLoadServer__dat_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
        } else if (strncmp(ext, "bin", 4) == 0) {
            strncpy(quest_download_file_slot.name, (char *)(arg0 + 0x28), 0x10);
            strncpy(quest_download_file_slot.title, (char *)(arg0 + 4), 0x22);
            s = &quest_download_file_slot;
            s->size = *(s32 *)(arg0 + 0x38) + 8;
            s->data = (u8 *)TQuestVmDownLoadServer::alloc(s->size);
            memset(s->data, 0, s->size);
            TQuestVmDownLoadServer__bin_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
            if ((s8)arg0[0x26] == 0) {
                TDLGraph::update_graph(TQuestVmDownLoadServer__received_file_bytes, TQuestVmDownLoadServer__total_download_bytes);
            }
        } else if (strncmp(ext, "pvr", 4) == 0) {
            strncpy(quest_download_file_info.name, (char *)(arg0 + 0x28), 0x10);
            strncpy(quest_download_file_info.title, (char *)(arg0 + 4), 0x22);
            quest_download_file_info.size = *(s32 *)(arg0 + 0x38);
            quest_download_file_info.data = (u8 *)TQuestVmDownLoadServer::alloc(quest_download_file_info.size);
            memset(quest_download_file_info.data, 0, *(s32 *)(arg0 + 0x38));
            TQuestVmDownLoadServer__pvr_download_complete = 0;
            TQuestVmDownLoadServer__total_download_bytes += *(s32 *)(arg0 + 0x38);
            if ((s32)arg0[0x26] == 1) {
                TDLGraph::update_graph(TQuestVmDownLoadServer__received_file_bytes, TQuestVmDownLoadServer__total_download_bytes);
            }
        } else if (strncmp(ext, "gba", 4) == 0) {
            strncpy(quest_download_file_header.name, (char *)(arg0 + 0x28), 0x10);
            strncpy(quest_download_file_header.title, (char *)(arg0 + 4), 0x22);
            quest_download_file_header.size = *(s32 *)(arg0 + 0x38);
            quest_download_file_header.data = (u8 *)TQuestVmDownLoadServer::alloc(quest_download_file_header.size);
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
        if (strncmp(TQuestVmDownLoadServer__download_file_state.name, (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__dat_download_complete;
            dst = TQuestVmDownLoadServer__download_file_state.data + 8;
        } else if (strncmp(quest_download_file_slot.name, (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__bin_download_complete;
            dst = quest_download_file_slot.data + 8;
        } else if (strncmp(quest_download_file_info.name, (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__pvr_download_complete;
            dst = quest_download_file_info.data;
        } else if (strncmp(quest_download_file_header.name, (char *)(arg0 + 4), 0x10) == 0) {
            flag = &TQuestVmDownLoadServer__gba_download_complete;
            dst = quest_download_file_header.data;
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
            v = TQuestVmDownLoadServer::get_serial_access();
            if (v == 0) {
                v = TQuestVmDownLoadServer::poll_serial_access();
            }
            download_rng_seed_pair[1] = v;
            download_rng_seed_pair[0] = v;
            ((TQuestVmDownLoadServer *)TQuestVmDownLoadServer__download_file_state.data)->encrypt_download_data(TQuestVmDownLoadServer__download_file_state.size);
            ((TQuestVmDownLoadServer *)quest_download_file_slot.data)->encrypt_download_data(quest_download_file_slot.size);
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
            v = TQuestVmDownLoadServer::get_serial_access();
            if (v == 0) {
                v = TQuestVmDownLoadServer::poll_serial_access();
            }
            download_rng_seed_pair[1] = v;
            download_rng_seed_pair[0] = v;
            ((TQuestVmDownLoadServer *)TQuestVmDownLoadServer__download_file_state.data)->encrypt_download_data(TQuestVmDownLoadServer__download_file_state.size);
            ((TQuestVmDownLoadServer *)quest_download_file_slot.data)->encrypt_download_data(quest_download_file_slot.size);
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
    move_data((void *)(src), (const void *)((const void *)this), (u32)size);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, download_rng_seed_pair[1]);
    subtractive_rng_make_shuffle((s32 *)&TQuestVmDownLoadServer__rng_cipher_state);
    TAdSinglePlyChrSelectGC::permute_save_blocks(&TQuestVmDownLoadServer__rng_cipher_state, (const u8*)src, (u8*)dst, (u32)size);
    move_data((void *)(this), (const void *)((const void *)dst), (u32)size);
    TAdSinglePlyChrSelectGC::safe_free((uaddr)dst);
    TAdSinglePlyChrSelectGC::safe_free((uaddr)src);
}
void TQuestVmDownLoadServer::unshuffle_and_decrypt(void *data, s32 size) {
    void *src;
    void *dst;
    src = TQuestVmDownLoadServer::alloc(size);
    dst = TQuestVmDownLoadServer::alloc(size);
    move_data((void *)(src), (const void *)((const void *)((u32 *)data)), (u32)size);
    subtractive_rng_seed(&TQuestVmDownLoadServer__rng_cipher_state, download_rng_seed_pair[1]);
    subtractive_rng_make_shuffle((s32 *)&TQuestVmDownLoadServer__rng_cipher_state);
    subtractive_rng_unshuffle((void *)&TQuestVmDownLoadServer__rng_cipher_state, (const u8 *)src, (u8 *)dst, (u32)size);
    move_data((void *)(((u32 *)data)), (const void *)((const void *)dst), (u32)size);
    TAdSinglePlyChrSelectGC::safe_free((uaddr)dst);
    TAdSinglePlyChrSelectGC::safe_free((uaddr)src);
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
s32 TQuestVmDownLoadServer::verify_checksum(const void *arg0, s32 size) {
  s32 temp_r31;
  void *temp_r3;
  s32 temp_r29;
  temp_r3 = TQuestVmDownLoadServer::alloc(size);
  if (temp_r3 == 0)
  {
    return 0;
  }
  move_data((void *)(temp_r3), (const void *)((const void *)arg0), (u32)size);
  temp_r29 = *((s32 *) (((s8 *) temp_r3) + 4));
  *((s32 *) (((s8 *) temp_r3) + 4)) = 0;
  temp_r31 = TQuestVmDownLoadServer__sub_801F8538(temp_r3, size);
  TAdSinglePlyChrSelectGC::safe_free((uaddr)temp_r3);
  return ((u32) __cntlzw((u32) (temp_r31 - temp_r29))) >> 5;
}
QuestDownloadRecord *get_quest_download_file_header(void) {
    return &quest_download_file_header;
}

const char *TQuestVmDownLoadServer__class_name = "TQuestVmDownLoadServer";
TQuestVmDownLoadServer::TQuestVmDownLoadServer(TObject *parent) : TObject(parent) {
    m_name = TQuestVmDownLoadServer__class_name;
    state = 0;
    pad_22c = 0;
    total_blocks = 0;
    card_mask = 0;
    prev_card_mask = 0;
    memcard_slot = -1;
    save_image = NULL;
    memset(slot_file_name, 0, 0xD);
    memset(state_file_name, 0, 0xD);
    icon_menu = NULL;
    status_window = NULL;
    message_window = 0;
    mc_select = NULL;
    TQuestVmDownLoadServer__instance = this;
    file_count = 2;
    quest_download_in_progress = 0;
}

TQuestVmDownLoadServer::~TQuestVmDownLoadServer() {
    if (save_image != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)save_image);
        save_image = NULL;
    }
    if (mc_select != NULL) {
        mc_select->queue_destruction();
        mc_select = NULL;
    }
    if (status_window != NULL) {
        ((TWindowBase *)status_window)->close();
        status_window = NULL;
    }
    if (icon_menu != NULL) {
        ((TWindowBase *)icon_menu)->close();
        icon_menu = NULL;
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
        ((TQuestVmDownLoadServer *)arg0)->count_download_file_blocks();
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
            if (status_window != NULL) {
                ((TObject *)status_window)->suspend_update();
            }
            if (mc_select != NULL) {
                ((TObject *)mc_select)->suspend_update();
            }
        } else {
            if (status_window != NULL) {
                ((TObject *)status_window)->clear_update_suspension();
            }
            if (mc_select != NULL) {
                ((TObject *)mc_select)->clear_update_suspension();
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
        ((TQuestVmDownLoadServer *)arg0)->build_file_slot_image();
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
        ((TQuestVmDownLoadServer *)arg0)->build_file_info_image();
        break;
    case 15:
        ((TQuestVmDownLoadServer *)arg0)->write_quest_data();
        break;
    case 16:
        ((TQuestVmDownLoadServer *)arg0)->close_download();
        break;
    case 19:
        ((TQuestVmDownLoadServer *)arg0)->handle_download_done_input();
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
        ((TQuestVmDownLoadServer *)arg0)->check_dismiss_to_close_input();
        break;
    }
}

void TQuestVmDownLoadServer::count_download_file_blocks() {
    QuestDownloadRecord *s;
    u32 n;

    this->total_blocks = 0;
    this->slot_file_blocks = 0;
    this->state_file_blocks = 0;
    this->info_file_blocks = 0;
    this->file_count = 0;
    s = &TQuestVmDownLoadServer__download_file_state;
    if (s->size > 0) {
        n = (u32)TAdPlayerLoadGC__sub_801E1518((void *)1, 0, s->size);
        if (n != 0xFFFFFF00) {
            this->total_blocks += n;
            this->state_file_blocks = n;
            this->file_count += 1;
        } else {
            this->state = 0x15;
            return;
        }
    }
    s = &quest_download_file_slot;
    if (s->size > 0) {
        n = (u32)TAdPlayerLoadGC__sub_801E1518((void *)1, 0, s->size);
        if (n != 0xFFFFFF00) {
            this->total_blocks += n;
            this->slot_file_blocks = n;
            this->file_count += 1;
        } else {
            this->state = 0x15;
            return;
        }
    }
    s = &quest_download_file_info;
    if (s->size > 0) {
        n = (u32)TAdPlayerLoadGC__sub_801E1518((void *)1, 0, s->size);
        if (n != 0xFFFFFF00) {
            this->total_blocks += n;
            this->info_file_blocks = n;
            this->file_count += 1;
        } else {
            this->state = 0x15;
            return;
        }
    }
    if (this->total_blocks > 0) {
        this->state = 1;
        return;
    }
    this->state = 0x15;
}
void TQuestVmDownLoadServer::close_window() {
    uaddr temp_r3;
    this->state = 2;
    temp_r3 = (uaddr) this->status_window;
    if (temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        this->status_window = 0U;
    }
    close_message();
    this->pad_22c = 0;
    if ((uaddr) this->mc_select != 0U) {
        TAdMcSelectGC::update_state();
    }
}
void TQuestVmDownLoadServer::update_mc_select() {
    if ((this->message_window == 0) || (TMessageWindowController::is_ready() != 0)) {
        if (this->mc_select == NULL) {
            TScene::reset_counter();
            if (lobby_player_construction_window != 0) {
                ((TObject *)((void *)lobby_player_construction_window))->disallow_rendering();
            }
            this->mc_select = (TObject *)TAdMcSelectGC::create(tl_03);
        }
        if (this->mc_select != NULL) {
            TAdMcSelectGC::select_if_mc_present();
        }
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) {
            TAdMcSelectGC::select_if_mc_present();
            show_status_message((int) (get_message_text(0x42)), 1);
            this->state = 0x14;
            return;
        }
        if (this->message_window == 0) {
            switch (this->pad_2a4) {
            case 0:
                show_status_message((int) (get_localized_text_entry(0x29, 0)), 1);
                return;
            case 1:
                show_status_message((int) (get_message_text(0x45)), 1);
                return;
            case 2:
                show_status_message((int) (get_message_text(0x60)), 1);
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
    if ((uaddr) this->mc_select == 0U) {
        TScene::reset_counter();
        uaddr temp_r3 = lobby_player_construction_window;
        if (temp_r3 != 0U) {
            ((TObject *)((void *)temp_r3))->disallow_rendering();
        }
        this->mc_select = (TObject *)TAdMcSelectGC::create(tl_03);
    }
    this->state = 4;
    show_status_message(get_localized_text_entry(0x29, 1), 1);
}
void TQuestVmDownLoadServer::handle_confirm_input() {
    ControllerInputContext *context;
    context = &controller_input_state.controllers[0];
    if (TWindowShortListCtrl__check_controller_button(context, 4) != 0) {
        TAdMcSelectGC::select_if_mc_present();
        this->state = 5;
        return;
    }
    if (TWindowShortListCtrl__check_controller_button(context, 2) != 0) {
        TAdMcSelectGC::select_if_mc_present();
        this->show_status_message((s32)((int) (get_message_text(0x42))), 1);
        this->state = 0x14;
    }
}
#pragma push
#pragma opt_propagation off
void TQuestVmDownLoadServer::check_memcard_slot() {
    saddr slot;
    s32 cap;
    TMCFormatSequence *seq;
    {
        s32 t = TAdMcSelectGC::get_selected_slot_index();
        slot = t;
    }
    if (TAdPlayerLoadGC::probe_card_slot(slot) != 0 && TAdPlayerLoadGC::probe_and_check_card(slot) != 0) {
        cap = TAdPlayerLoadGC::query_memcard_capacity(slot, 0);
        switch (cap) {
        case -0xFD:
            seq = new TMCFormatSequence(this, slot);
            seq->done_callback = TQuestVmDownLoadServer__sub_801F6B98;
            seq->error_callback = TQuestVmDownLoadServer::clear_field2A0;
            this->state = 0x16;
            break;
        case -1:
        case -0xFF:
            return;
        default:
            if (cap < this->total_blocks) {
                show_status_message(get_message_text(0x45), 1);
                this->state = 0x12;
                return;
            }
            if (get_memcard_free_files(slot) < this->file_count) {
                show_status_message(get_message_text(0x60), 1);
                this->state = 0x12;
                return;
            }
            if (this->status_window != NULL) {
                ((TWindowBase *)this->status_window)->close();
                this->status_window = NULL;
            }
            this->status_window = init_shop_judgment_window((void *)(get_window_layout_position(0x2B)));
            show_status_message(get_message_text(0x40), 1);
            this->memcard_slot = slot;
            this->state = 6;
            return;
        }
    } else if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 2) != 0) {
        TAdMcSelectGC::update_state();
        show_status_message(get_localized_text_entry(0x29, 1), 1);
        this->state = 4;
    }
}
#pragma pop
void TQuestVmDownLoadServer::handle_confirm_window() {
    s32 selected_menu_value;

    if ((uaddr) this->status_window != 0U) {
        if (((TWindowMenu *)(this->status_window))->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)(this->status_window))->get_selected_value();
            if (selected_menu_value == 0) {
                if ((uaddr) this->status_window != 0U) {
                    ((TWindowBase *)this->status_window)->close();
                    this->status_window = 0U;
                }
                this->state = 7;
                return;
            }
            if (selected_menu_value == 1) {
                if ((uaddr) this->status_window != 0U) {
                    ((TWindowBase *)this->status_window)->close();
                    this->status_window = 0U;
                }
                if ((uaddr) this->icon_menu != 0U) {
                    ((TWindowMenuIconLine *)(this->icon_menu))->clear_decided();
                }
                TAdMcSelectGC::update_state();
                show_status_message(get_localized_text_entry(0x29, 1), 1);
                this->state = 4;
                return;
            }
            goto block_12;
        }
block_12:
        if (((TWindowMenu *)(this->status_window))->is_cancelled() != 0) {
            if ((uaddr) this->status_window != 0U) {
                ((TWindowBase *)this->status_window)->close();
                this->status_window = 0U;
            }
            if ((uaddr) this->icon_menu != 0U) {
                ((TWindowMenuIconLine *)(this->icon_menu))->clear_decided();
            }
            TAdMcSelectGC::update_state();
            show_status_message(get_localized_text_entry(0x29, 1), 1);
            this->state = 4;
        }
    }
}
void TQuestVmDownLoadServer::find_free_file_names() {
    char buf[0xD];
    s32 i;
    memset(this->slot_file_name, 0, 0xD);
    memset(this->state_file_name, 0, 0xD);
    for (i = quest_file_first_index; i < quest_file_index_limit; i += 2) {
        memset(buf, 0, 0xD);
        sprintf(buf, "%s%02d", quest_file_prefix, i);
        if (TAdPlayerLoadGC::find_card_file(this->memcard_slot, buf) == 0xFFFFFF05) {
            sprintf(buf, "%s%02d", quest_file_prefix, i + 1);
            if (TAdPlayerLoadGC::find_card_file(this->memcard_slot, buf) == 0xFFFFFF05) {
                sprintf(this->slot_file_name, "%s%02d", quest_file_prefix, i);
                sprintf(this->state_file_name, "%s%02d", quest_file_prefix, i + 1);
                this->state = 8;
                return;
            }
        }
    }
    this->state = 0x11;
}

void TQuestVmDownLoadServer::build_file_slot_image() {
    CardSaveDescriptor req;
    s32 r;
    if (this->memcard_slot >= 0 && poll_memcard_result(this->memcard_slot) == 0) {
        if (this->slot_file_blocks > 0) {
            if (this->save_image != NULL) {
                TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
                this->save_image = NULL;
            }
            this->save_image = TQuestVmDownLoadServer::alloc(this->slot_file_blocks << 13);
            if (this->save_image != NULL) {
                memset(&req, 0, sizeof(req));
                strncpy(req.filename, TQuestVmDownLoadServer__data_804C8690, 0x12);
                strncpy(req.title, quest_download_file_slot.title, 0x22);
                memcpy(req.key, TQuestVmDownLoadServer__memcard_key, 0x10);
                req.banner = memcard_default_banner;
                req.icon = memcard_default_icon;
                req.field_4c = 1;
                req.field_4e = 1;
                req.field_50 = 0;
                req.omit_title_space = 1;
                req.data = quest_download_file_slot.data;
                req.size = quest_download_file_slot.size;
                TAdPlayerLoadGC__sub_801E14E8(&req, 3);
                r = TAdPlayerLoadGC::build_save_file_image(this->save_image, &req);
                TAdPlayerLoadGC__sub_801E14E4(&req);
                switch (r) {
                case -0x100:
                    this->state = 0x11;
                    break;
                default:
                    if (r != this->slot_file_blocks) {
                        this->slot_file_blocks = r;
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
    TAdSinglePlyChrSelectGC::set_quest_download_server(this->memcard_slot);
    lbl_805D49B4 = 1;
    if (TAdSinglePlyChrSelectGC::draw_window_bg(this->memcard_slot, (saddr)&this->slot_file_name, (s32)(*(s32 *)&this->save_image), (s32)(this->slot_file_blocks)) == 0) {
        this->state = 0xA;
        show_status_message(get_message_text(0xC), 1);
        quest_download_in_progress = 1;
        return;
    }
    show_status_message(get_localized_text_entry(0x29, 2), 1);
    this->state = 0x17;
    lbl_805D49B4 = 0;
}
void TQuestVmDownLoadServer::abort_download() {
    if (poll_memcard_result(this->memcard_slot) == 0) {
        TAdSinglePlyChrSelectGC::reset_quest_id();
        if ((uaddr) this->save_image != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
            this->save_image = 0U;
        }
        this->state = 0xB;
        lbl_805D49B4 = 0;
    }
}
void TQuestVmDownLoadServer::write_memcard_file() {
    CardSaveDescriptor req;
    s32 r;
    if (this->memcard_slot >= 0 && poll_memcard_result(this->memcard_slot) == 0) {
        if (this->state_file_blocks > 0) {
            if (this->save_image != NULL) {
                TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
                this->save_image = NULL;
            }
            this->save_image = TQuestVmDownLoadServer::alloc(this->state_file_blocks << 13);
            if (this->save_image != NULL) {
                memset(&req, 0, sizeof(req));
                strncpy(req.filename, TQuestVmDownLoadServer__data_804C8690, 0x12);
                strncpy(req.title, TQuestVmDownLoadServer__download_file_state.title, 0x22);
                memcpy(req.key, TQuestVmDownLoadServer__memcard_key, 0x10);
                req.banner = memcard_default_banner;
                req.icon = memcard_default_icon;
                req.field_4c = 1;
                req.field_4e = 1;
                req.field_50 = 0;
                req.omit_title_space = 1;
                req.data = TQuestVmDownLoadServer__download_file_state.data;
                req.size = TQuestVmDownLoadServer__download_file_state.size;
                TAdPlayerLoadGC__sub_801E14E8(&req, 3);
                r = TAdPlayerLoadGC::build_save_file_image(this->save_image, &req);
                TAdPlayerLoadGC__sub_801E14E4(&req);
                switch (r) {
                case -0x100:
                    this->state = 0x11;
                    break;
                default:
                    if (r != this->state_file_blocks) {
                        this->state_file_blocks = r;
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
    TAdSinglePlyChrSelectGC::set_quest_download_server(this->memcard_slot);
    lbl_805D49B4 = 1;
    if (TAdSinglePlyChrSelectGC::draw_window_bg(this->memcard_slot, (saddr)&this->state_file_name, (saddr)this->save_image, this->state_file_blocks) == 0) {
        this->state = 0xD;
        show_status_message(get_message_text(0xC), 1);
        return;
    }
    show_status_message(get_localized_text_entry(0x29, 2), 1);
    this->state = 0x17;
    lbl_805D49B4 = 0;
}
void TQuestVmDownLoadServer::finish_download() {
    if (poll_memcard_result(this->memcard_slot) == 0) {
        TAdSinglePlyChrSelectGC::reset_quest_id();
        if ((uaddr) this->save_image != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
            this->save_image = 0U;
        }
        if ((uaddr) this->icon_menu != 0U) {
            ((TWindowMenuIconLine *)(this->icon_menu))->clear_decided();
        }
        this->state = 0xE;
        lbl_805D49B4 = 0;
    }
}
void TQuestVmDownLoadServer::build_file_info_image() {
    CardSaveDescriptor req;
    s32 r;
    if ((s32)TQuestVmDownLoadServer__download_kind != 1) {
        this->show_status_message(get_message_text(0x41), 1);
        this->state = 0x13;
        return;
    }
    if (this->memcard_slot >= 0 && quest_download_file_info.size > 0) {
        if (poll_memcard_result(this->memcard_slot) == 0) {
            if (this->info_file_blocks > 0) {
                if (this->save_image != NULL) {
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
                    this->save_image = NULL;
                }
                this->save_image = TQuestVmDownLoadServer::alloc(this->info_file_blocks << 13);
                if (this->save_image != NULL) {
                    memset(&req, 0, sizeof(req));
                    strncpy(req.filename, TQuestVmDownLoadServer__data_804C8690, 0x12);
                    strncpy(req.title, quest_download_file_info.title, 0x22);
                    memcpy(req.key, TQuestVmDownLoadServer__memcard_key, 0x10);
                    req.banner = memcard_default_banner;
                    req.icon = memcard_default_icon;
                    req.field_4c = 1;
                    req.field_4e = 1;
                    req.field_50 = 0;
                    req.omit_title_space = 1;
                    req.data = quest_download_file_info.data;
                    req.size = quest_download_file_info.size;
                    TAdPlayerLoadGC__sub_801E14E8(&req, 3);
                    r = TAdPlayerLoadGC::build_save_file_image(this->save_image, &req);
                    TAdPlayerLoadGC__sub_801E14E4(&req);
                    switch (r) {
                    case -0x100:
                        this->state = 0x11;
                        break;
                    default:
                        if (r != this->info_file_blocks) {
                            this->info_file_blocks = r;
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
    TAdSinglePlyChrSelectGC::set_quest_download_server(this->memcard_slot);
    lbl_805D49B4 = 1;
    if (TAdSinglePlyChrSelectGC::draw_window_bg(this->memcard_slot, (saddr)quest_file_99_name, (s32)(*(s32 *)&this->save_image), (s32)(this->info_file_blocks)) == 0) {
        this->state = 0x10;
        show_status_message(get_message_text(0xC), 1);
        return;
    }
    show_status_message(get_localized_text_entry(0x29, 2), 1);
    this->state = 0x17;
    lbl_805D49B4 = 0;
}
void TQuestVmDownLoadServer::close_download() {
    if (poll_memcard_result(this->memcard_slot) == 0) {
        TAdSinglePlyChrSelectGC::reset_quest_id();
        if ((uaddr) this->save_image != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
            this->save_image = 0U;
        }
        if ((uaddr) this->icon_menu != 0U) {
            ((TWindowMenuIconLine *)(this->icon_menu))->clear_decided();
        }
        show_status_message((s32)(get_message_text(0x41)), 1);
        this->state = 0x13;
        lbl_805D49B4 = 0;
    }
}
void TQuestVmDownLoadServer::destroy() {
    TScene::set_ready();
    if (lobby_player_construction_window != 0) {
        ((TObject *)((void *)lobby_player_construction_window))->allow_rendering();
    }
    TQuestVmDownLoadServer::free_buffers();
    queue_destruction();
}
void TQuestVmDownLoadServer::close() {
    if ((uaddr) this->save_image != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)this->save_image);
        this->save_image = 0U;
    }
    if ((uaddr) this->icon_menu != 0U) {
        ((TWindowMenuIconLine *)(this->icon_menu))->clear_decided();
    }
    TAdMcSelectGC::update_state();
    show_status_message((s32)(get_localized_text_entry(0x29, 1)), 1);
    this->state = 4;
    quest_download_in_progress = 0;
}
void TQuestVmDownLoadServer::check_client_connections() {
    s32 temp_r0;
    s32 temp_r3;
    s32 chan;

    temp_r0 = this->state;
    if ((temp_r0 == 0) || (temp_r0 == 0x15) || (temp_r0 == 0x16)) {
        return;
    }
    {
        if ((s32) lbl_805D55C0 != 0) {
            if ((uaddr) this->mc_select != 0U) {
                ((TObject *)(this->mc_select))->suspend_update();
            }
        } else {
            if ((uaddr) this->mc_select != 0U) {
                ((TObject *)(this->mc_select))->clear_update_suspension();
            }
            chan = 0;
            this->card_mask = 0;
            do {
                if (TAdPlayerLoadGC::probe_card_slot(chan) != 0) {
                    this->card_mask = (s32) (this->card_mask | (1 << chan));
                }
                chan += 1;
            } while (chan < 8);
            temp_r3 = this->card_mask;
            if (temp_r3 != (s32) this->prev_card_mask) {
                this->prev_card_mask = temp_r3;
                if ((s32) quest_download_in_progress != 0) {
                    quest_download_in_progress = 0;
                    show_status_message((s32)(get_message_text(0xB)), 1);
                    this->state = 0x12;
                } else {
                    this->state = 1;
                }
            }
        }
    }
}
void TQuestVmDownLoadServer::show_status_message(saddr text, s32 arg2) {
    if (this->message_window == NULL) {
        static const Pair_801F6E08 window_size = {444.0f, 84.0f};
        Pair_801F6E08 sp = window_size;
        this->message_window = TMessageWindowController::create_window(get_window_layout_position(0x2F), (saddr)&sp);
    }
    TMessageWindowController::display_message((const char *)text, (s32)(arg2 | 0x80));
}
void TQuestVmDownLoadServer::close_message() { if (this->message_window != 0) { TMessageWindowController::close(); this->message_window = 0; } }
void TQuestVmDownLoadServer::sub_801F6D24() {
    ControllerInputContext *p;
    if (this->message_window == 0 || TMessageWindowController::is_ready() != 0) {
        p = &controller_input_state.controllers[0];
        if (TWindowShortListCtrl__check_controller_button(p, 4) != 0 || TWindowShortListCtrl__check_controller_button(p, 2) != 0) {
            TAdMcSelectGC::update_state();
            this->show_status_message((int)(get_localized_text_entry(0x29, 1)), 1);
            this->state = 4;
        }
    }
}
void TQuestVmDownLoadServer::handle_download_done_input() {
    ControllerInputContext *context;
    context = &controller_input_state.controllers[0];
    quest_download_in_progress = 0;
    if (TWindowShortListCtrl__check_controller_button(context, 4) != 0) {
        TAdMcSelectGC::update_state();
        this->show_status_message((int) (get_localized_text_entry(0x29, 1)), 1);
        this->state = 4;
    }
    if (TWindowShortListCtrl__check_controller_button(context, 2) != 0) {
        TAdMcSelectGC::select_if_mc_present();
        this->show_status_message((int) (get_message_text(0x42)), 1);
        this->state = 0x14;
    }
}
void TQuestVmDownLoadServer::check_cancel_input() {
    ControllerInputContext *context;
    context = &controller_input_state.controllers[0];
    if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (TWindowShortListCtrl__check_controller_button(context, 2) != 0)) {
        TLobby::return_to_main_menu();
        this->state = 0x15;
    }
}
void TQuestVmDownLoadServer::create() {
    if (TQuestVmDownLoadServer__instance == NULL) {
        new TQuestVmDownLoadServer(tl_00);
    }
}
s32 TQuestVmDownLoadServer::get_field230() {
    if (TQuestVmDownLoadServer__instance != NULL) {
        return TQuestVmDownLoadServer__instance->total_blocks;
    }
    return 0;
}
void TQuestVmDownLoadServer__sub_801F6B98(TMCFormatSequence *) {
    if (TQuestVmDownLoadServer__instance != NULL) {
        TQuestVmDownLoadServer__instance->state = 0;
    }
}
void TQuestVmDownLoadServer::clear_field2A0(TMCFormatSequence *) {
    if (TQuestVmDownLoadServer__instance != NULL) {
        TQuestVmDownLoadServer__instance->state = 0;
    }
}
void TQuestVmDownLoadServer::check_dismiss_to_close_input() {
    if (this->message_window == 0 || TMessageWindowController::is_ready() != 0) {
        ControllerInputContext *p = &controller_input_state.controllers[0];
        if (TWindowShortListCtrl__check_controller_button(p, 4) != 0 || TWindowShortListCtrl__check_controller_button(p, 2) != 0) {
            this->state = 0x11;
        }
    }
}
const char *TMCFormatSequence__class_name = "TMCFormatSequence";
TMCFormatSequence::TMCFormatSequence(TObject *parent, s32 card_slot) : TObject(parent) {
    this->m_name = TMCFormatSequence__class_name;
    this->state = 0;
    this->card_slot = card_slot;
    this->done_callback = NULL;
    this->error_callback = NULL;
    this->message_window = NULL;
    this->confirm_menu = NULL;
    this->message_group = 11;
    this->message_id = 101;
}
TMCFormatSequence::~TMCFormatSequence() {
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = NULL; }
    close_window();
}
void TMCFormatSequence::run_task() {
    switch (this->state) {
    case 0:
        open_windows();
        return;
    case 1:
        process_format_result();
        return;
    case 2:
        check_memcard_load_result();
        return;
    case 3:
        wait_confirm_and_finish();
        return;
    case 4:
        update_wait_confirm();
        return;
    }
}

// TMCFormatSequence (text 0x801F6554-0x801F69A0): its class name and window position sit in this TU's
// .sdata/.rodata, so it is the tail of this file (deferred: the source runs backwards from the text).
struct Pair_801F68FC { f32 a; f32 b; };

extern "C" {
s32 start_memcard_format(s32, s32, s32, s32, s32);
}

void TMCFormatSequence::open_windows() {
    if (this->message_window == NULL) {
        static const Pair_801F68FC window_size = {444.0f, 84.0f};
        Pair_801F68FC t = window_size;
        this->message_window = (TWindowMessagePage *)TWindowMessagePage::set_text((s32)get_window_layout_position(0x2F), (saddr)&t, 1);
        show_message(get_localized_text_entry(this->message_group, this->message_id), 0);
    }
    if (this->confirm_menu == NULL) {
        this->confirm_menu = (TWindowMenu *)init_shop_judgment_window((void *)get_window_layout_position(0x2B));
    }
    this->state = 1;
}
void TMCFormatSequence::process_format_result() {
    s32 selected_menu_value;

    if (TAdPlayerLoadGC::probe_card_slot(this->card_slot) == 0) {
        show_message((s32)(get_localized_text_entry(0xB, 0x6C)), 0);
        this->state = 3;
        return;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(this->card_slot) == 0) {
        show_message((s32)(get_localized_text_entry(0xB, 0x6C)), 0);
        this->state = 3;
        return;
    }
    if ((u32) (TAdPlayerLoadGC::check_memcard_status(this->card_slot) + 0x10000) != 0xFF03U) {
        show_message((s32)(get_localized_text_entry(0xB, 0x6C)), 0);
        this->state = 3;
        return;
    }
    if ((this->confirm_menu != NULL) && (this->confirm_menu->is_decided() != 0)) {
        selected_menu_value = this->confirm_menu->get_selected_value();
        if (selected_menu_value == 0) {
            if (start_memcard_format(this->card_slot, 0, 0, 0, 0) == 0) {
                this->state = 2;
            } else {
                show_message((s32)(get_localized_text_entry(0xB, 0x6C)), 0);
                this->state = 3;
            }
        }
        if (selected_menu_value == 1) {
            close_window();
            this->state = 4;
        }
        this->confirm_menu->close();
        this->confirm_menu = NULL;
    }
    if ((this->confirm_menu != NULL) && (this->confirm_menu->is_cancelled() != 0)) {
        this->state = 4;
        this->confirm_menu->close();
        this->confirm_menu = NULL;
        close_window();
    }
}
void TMCFormatSequence::check_memcard_load_result() {
    if (TAdPlayerLoadGC::probe_card_slot(this->card_slot) == 0) {
        show_message((s32)(get_localized_text_entry(0xB, 0x6C)), 0);
        this->state = 3;
        return;
    }
    if (poll_memcard_result(this->card_slot) == 0) {
        show_message((s32)(get_localized_text_entry(0xB, 0x6B)), 0);
        this->state = 4;
    }
}
void TMCFormatSequence::update_wait_confirm() {
    TWindowMessagePage *window = this->message_window;
    if (window == NULL || (window->is_message_window_ready() != 0 && TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 4) != 0)) {
        if (this->done_callback != NULL) {
            this->done_callback(this);
            queue_destruction();
        }
    }
}
void TMCFormatSequence::wait_confirm_and_finish() {
    TWindowMessagePage *window = this->message_window;
    if (window == NULL || (window->is_message_window_ready() != 0 && TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 4) != 0)) {
        if (this->error_callback != NULL) {
            this->error_callback(this);
            queue_destruction();
        }
    }
}
void TMCFormatSequence::show_message(s32 text, s32 flags) {
    TWindowMessagePage *window = this->message_window;
    if (window != NULL) {
        window->append_line(text, flags | 0x81);
    }
}
void TMCFormatSequence::close_window() {
    if (this->message_window != NULL) {
        this->message_window->close();
        this->message_window = NULL;
    }
}
