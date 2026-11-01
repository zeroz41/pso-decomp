#include "pso/TMainTask.h"
#include "pso/misc/TWindowBase.h"
#include "pso/THunterGuildSeqOnlineTask.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowCtrl.h"

#include "types.h"
#include "pso/TObject.h"

struct Pkt_80214F80 {
    u8 f0;
    u8 chunk;
    u8 pad2[2];
    char name[0x10];
    u8 data[0x400];
    u32 size;
};

struct Pos_80214F80 { s32 a; s32 b; };

extern "C" {
void TKeyBoardControl__sub_8000F95C();
void TQuestListOnline__sub_8013ACF4(s32);
void mem_free(void *);
extern unsigned char TQuestListOnline__dat_download_state[];
extern unsigned char TQuestListOnline__bin_download_state[];
extern s32 evt2_random_enemies_mode;
extern int TQuestListOnline__bin_download_complete;
extern int TQuestListOnline__dat_download_complete;
extern u32 TQuestListOnline__download_window;
extern u32 TQuestListOnline__quest_info_window;
extern void *TQuestListOnline__download_barrier_window;
void TKeyBoardControl__sub_8000F950();
s32 is_flag_set__6TLobbyFv();
void *get_player_by_client_id(s32);
void TQuestListOnline__sub_802176DC(void *, s32);
void decompress_quest_buffer__16TQuestListOnlineFl(void *, s32);
extern s32 local_client_id;
extern s32 quest_download_active;
void *TQuestVmDownLoadServer__sub_8006EF6C(s32);
void send_quest_barrier__9TProtocolFv(s32);
void append_line__14TWindowMessageFii(void *, void *, s32);
void *update_window_mode_from_progress__6TLobbyFPv(void *, Pos_80214F80 *);
void *get_window_layout_position(s32);
int strncmp(const char *, const char *, u32);
void *memcpy(void *, const void *, u32);
extern Pos_80214F80 lbl_8044BCC8[];
extern s32 TLobby__protocol_instance;
extern s32 quest_download_received_bytes;
extern s32 quest_download_graph_current_bytes;
extern const f32 lbl_805DC660;
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern s32 controller_input_state[];
}

void THunterGuildSeqOnlineTask::run_task() {
    u8 *p;
    if (TQuestListOnline__quest_info_window != 0) {
        p = (u8 *)controller_input_state + 0x20;
        if (TWindowShortListCtrl__check_controller_button((int)p, 4) != 0 ||
            TWindowShortListCtrl__check_controller_button((int)p, 2) != 0) {
            ((TWindowBase *)TQuestListOnline__quest_info_window)->close();
            TQuestListOnline__quest_info_window = 0;
            ((TWindowCtrl *)local_client_id)->unsuppress_slot();
        }
    }
}

THunterGuildSeqOnlineTask::~THunterGuildSeqOnlineTask() {}

#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/misc/TDLGraph.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

extern "C" {

void *THunterGuildSeqOnlineTask__ct(void *arg0);
void __ct__7TObjectFP7TObject(void *);
void *__nw__7TObjectFUl(int);

extern s32 __vt__25THunterGuildSeqOnlineTask[];
extern void *lbl_805D3660;

void *THunterGuildSeqOnlineTask__ct(void *hunter_guild_seq_online_task) {
    __ct__7TObjectFP7TObject(hunter_guild_seq_online_task);
    *(s32 **)((s8 *)hunter_guild_seq_online_task + 0x18) = __vt__25THunterGuildSeqOnlineTask;
    *(void * *)&((THunterGuildSeqOnlineTask *)hunter_guild_seq_online_task)->m_name = lbl_805D3660;
    return hunter_guild_seq_online_task;
}
}
void handle_6x73_exit_quest(void);
extern unsigned char reset_random_enemies_mode[];

void handle_6x73_exit_quest(void) {
    void *o;
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        ((THunterGuildSeqOffline *)o)->init(tl_00, reset_random_enemies_mode);
    }
}

void TQuestListOnline::close_windows_and_reset() {
    u8 *q;
    if (TKeyBoardControl::get_input() == 0) {
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F95C();
        q = TQuestListOnline__bin_download_state;
        if (*(void **)(q + 0x38) != NULL) {
            mem_free(*(void **)(q + 0x38));
            *(void **)(q + 0x38) = NULL;
        }
        q = TQuestListOnline__dat_download_state;
        if (*(void **)(q + 0x38) != NULL) {
            mem_free(*(void **)(q + 0x38));
            *(void **)(q + 0x38) = NULL;
        }
        if (TQuestListOnline__download_window != 0) {
            ((TWindowBase *)TQuestListOnline__download_window)->close();
            TQuestListOnline__download_window = 0;
        }
        if (TQuestListOnline__quest_info_window != 0) {
            ((TWindowBase *)TQuestListOnline__quest_info_window)->close();
            TQuestListOnline__quest_info_window = 0;
        }
        if (TQuestListOnline__download_barrier_window != NULL) {
            ((TWindowBase *)TQuestListOnline__download_barrier_window)->close();
            TQuestListOnline__download_barrier_window = NULL;
        }
        TQuestListOnline__bin_download_complete = 0;
        TQuestListOnline__dat_download_complete = 0;
        TQuestListOnline__sub_8013ACF4(0xB);
        TQuestListOnline::ensure_online_quests_loaded();
        main_task.resume_layers();
        TQuestVmDownLoadServer::reset_download();
    }
}
void TQuestListOnline::handle_quest_ready() {
    s32 i;
    void *p;
    u8 *q;
    s32 r;
    s32 m;
    if (TQuestListOnline::init() != 0) {
        q = TQuestListOnline__bin_download_state;
        decompress_quest_buffer__16TQuestListOnlineFl(*(void **)(q + 0x38), *(s32 *)(q + 0x34));
        q = TQuestListOnline__dat_download_state;
        TQuestListOnline__sub_802176DC(*(void **)(q + 0x38), *(s32 *)(q + 0x34));
        TLobby::set_enemy_mode_flag();
        r = is_flag_set__6TLobbyFv();
        m = 2;
        if (r != 0) {
            m = 4;
        }
        evt2_random_enemies_mode = m;
        TKeyBoardControl__sub_8000F950();
        ((TWindowCtrl *)local_client_id)->unsuppress_slot();
    } else {
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F95C();
        q = TQuestListOnline__bin_download_state;
        if (*(void **)(q + 0x38) != NULL) {
            mem_free(*(void **)(q + 0x38));
            *(void **)(q + 0x38) = NULL;
        }
        q = TQuestListOnline__dat_download_state;
        if (*(void **)(q + 0x38) != NULL) {
            mem_free(*(void **)(q + 0x38));
            *(void **)(q + 0x38) = NULL;
        }
        TQuestListOnline__bin_download_complete = 0;
        TQuestListOnline__dat_download_complete = 0;
        TQuestListOnline__sub_8013ACF4(0xB);
    }
    if (TQuestListOnline__download_window != 0) {
        ((TWindowBase *)TQuestListOnline__download_window)->close();
        TQuestListOnline__download_window = 0;
    }
    if (TQuestListOnline__quest_info_window != 0) {
        ((TWindowBase *)TQuestListOnline__quest_info_window)->close();
        TQuestListOnline__quest_info_window = 0;
    }
    if (TQuestListOnline__download_barrier_window != NULL) {
        ((TWindowBase *)TQuestListOnline__download_barrier_window)->close();
        TQuestListOnline__download_barrier_window = NULL;
    }
    main_task.resume_layers();
    quest_download_active = 0;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            TObjPlayer::clear_lobby_flag(p);
            ((TObjPlayer *)p)->activate_body_collision();
        }
    }
    ((TWindowCtrl *)local_client_id)->unsuppress_slot();
}
void TLobby::handle_quest_download_chunk() {
    Pkt_80214F80 *p = (Pkt_80214F80 *)this;
    int *flag;
    u8 *buf;
    if (p != NULL) {
        if (strncmp((char *)TQuestListOnline__dat_download_state, p->name, 0x10) == 0) {
            flag = &TQuestListOnline__dat_download_complete;
            buf = *(u8 **)(TQuestListOnline__dat_download_state + 0x38);
        } else if (strncmp((char *)TQuestListOnline__bin_download_state, p->name, 0x10) == 0) {
            flag = &TQuestListOnline__bin_download_complete;
            buf = *(u8 **)(TQuestListOnline__bin_download_state + 0x38);
        } else {
            return;
        }
        if (buf != NULL) {
            memcpy(buf + (p->chunk << 10), p->data, p->size);
            quest_download_graph_current_bytes += p->size;
            TDLGraph::update_graph(quest_download_graph_current_bytes, quest_download_received_bytes);
            if (p->size < 0x400) {
                *flag = 1;
            }
        } else {
            return;
        }
    }
    if (TQuestListOnline__bin_download_complete != 0 && TQuestListOnline__dat_download_complete != 0) {
        if (TQuestListOnline__download_barrier_window == NULL) {
            Pos_80214F80 pos = lbl_8044BCC8[0];
            TQuestListOnline__download_barrier_window = update_window_mode_from_progress__6TLobbyFPv(get_window_layout_position(0xBE), &pos);
            append_line__14TWindowMessageFii(TQuestListOnline__download_barrier_window, TQuestVmDownLoadServer__sub_8006EF6C(0x61), 1);
            ((TWindowBase *)TQuestListOnline__download_barrier_window)->set_depth(lbl_805DC660);
            ((TWindowMessage *)TQuestListOnline__download_barrier_window)->complete_reveal();
        }
        send_quest_barrier__9TProtocolFv(TLobby__protocol_instance);
    }
}
