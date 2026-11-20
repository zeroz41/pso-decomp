#include "pso/system/task/TMainTask.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/render/TDLGraph.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>


struct Pkt_80214F80 {
    u8 f0;
    u8 chunk;
    u8 pad2[2];
    char name[0x10];
    u8 data[0x400];
    u32 size;
};

// Window sizes {width, height} of the quest download windows.
static const NJS_POINT2 quest_info_window_size = {332.0f, 210.0f};
static const NJS_POINT2 download_window_size = {332.0f, 80.0f};
static const NJS_POINT2 download_barrier_window_size = {332.0f, 80.0f};

const char *THunterGuildSeqOnlineTask__name = "THunterGuildSeqOnlineTask";
const char *THunterGuildSeqOnline_Server__name = "THunterGuildSeqOnline_Server";
const char *THunterGuildSeqOnline_Client__name = "THunterGuildSeqOnline_Client";


extern "C" {
void TKeyBoardControl__sub_8000F95C();
extern unsigned char TQuestListOnline__dat_download_state[];
extern unsigned char TQuestListOnline__bin_download_state[];
extern s32 evt2_random_enemies_mode;
extern int TQuestListOnline__bin_download_complete;
extern int TQuestListOnline__dat_download_complete;
extern uaddr TQuestListOnline__download_window;
extern uaddr TQuestListOnline__quest_info_window;
extern void *TQuestListOnline__download_barrier_window;
void TKeyBoardControl__sub_8000F950();
void *get_player_by_client_id(s32);
void TQuestListOnline__sub_802176DC(void *, s32);
void decompress_quest_buffer__16TQuestListOnlineFl(void *, s32);
extern saddr local_client_id;
extern s32 quest_download_active;
saddr get_message_text(s32 arg0);
void send_quest_barrier__9TProtocolFv(s32);
void *update_window_mode_from_progress__6TLobbyFPv(void *, NJS_POINT2 *);
void *get_window_layout_position(s32);
extern s32 TLobby__protocol_instance;
extern s32 quest_download_received_bytes;
extern s32 quest_download_graph_current_bytes;
extern s32 controller_input_state[];
}

void THunterGuildSeqOnlineTask::run_task() {
    u8 *p;
    if (TQuestListOnline__quest_info_window != 0) {
        p = (u8 *)controller_input_state + 0x20;
        if (TWindowShortListCtrl__check_controller_button(p, 4) != 0 ||
            TWindowShortListCtrl__check_controller_button(p, 2) != 0) {
            ((TWindowBase *)TQuestListOnline__quest_info_window)->close();
            TQuestListOnline__quest_info_window = 0;
            ((TWindowCtrl *)local_client_id)->unsuppress_slot();
        }
    }
}

THunterGuildSeqOnlineTask::~THunterGuildSeqOnlineTask() {}


extern "C" {

void *THunterGuildSeqOnlineTask__ct(void *arg0);
void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__25THunterGuildSeqOnlineTask[];

void *THunterGuildSeqOnlineTask__ct(void *hunter_guild_seq_online_task) {
    __ct__7TObjectFP7TObject(hunter_guild_seq_online_task);
    *(s32 **)((s8 *)hunter_guild_seq_online_task + 0x18) = __vt__25THunterGuildSeqOnlineTask;
    ((THunterGuildSeqOnlineTask *)hunter_guild_seq_online_task)->m_name = THunterGuildSeqOnlineTask__name;
    return hunter_guild_seq_online_task;
}
}
void handle_6x73_exit_quest(void);
extern unsigned char reset_random_enemies_mode[];

void handle_6x73_exit_quest(void) {
    void *o;
    o = TObject::operator new(0x28);
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
        r = TLobby::is_flag_set();
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
            NJS_POINT2 pos = download_barrier_window_size;
            TQuestListOnline__download_barrier_window = update_window_mode_from_progress__6TLobbyFPv(get_window_layout_position(0xBE), &pos);
            ((TWindowMessage *)TQuestListOnline__download_barrier_window)->append_line((int)(get_message_text(0x61)), (int)1);
            ((TWindowBase *)TQuestListOnline__download_barrier_window)->set_depth(36000.0f);
            ((TWindowMessage *)TQuestListOnline__download_barrier_window)->complete_reveal();
        }
        send_quest_barrier__9TProtocolFv(TLobby__protocol_instance);
    }
}

struct Slot_802150E8 { char name[0x34]; s32 size; void *buf; };

struct Ent_802150E8 { u8 pad[0x28]; char name[0x10]; s32 size; };


extern "C" {
extern uaddr TQuestListOnline__quest_list_buffer;
extern saddr TQuestListOnline__selected_quest_info;
extern s32 TQuestListOnline__instance;
}
s32 get_guild_text(s32);
extern "C" {
char *strtok(char *, const char *);
s32 THunterGuildSeqOffline__sub_80212074();
int create__14TWindowMessageFlPCfUll(void *, NJS_POINT2 *, s32, s32);

void TQuestListOnline::begin_file_download() {
    Ent_802150E8 *arg0 = (Ent_802150E8 *)this;
    char buf[0x10];
    char *tok;
    Slot_802150E8 *s;
    if ((u32) TQuestListOnline__download_window == 0U) {
        NJS_POINT2 p = download_window_size;
        TQuestListOnline__download_window = (uaddr)update_window_mode_from_progress__6TLobbyFPv(get_window_layout_position(0x2C), &p);
        ((TWindowMessage *)TQuestListOnline__download_window)->append_line(get_guild_text(0x14), 1);
        ((TWindowMessage *)TQuestListOnline__download_window)->complete_reveal();
        ((TWindowBase *)TQuestListOnline__download_window)->set_depth(37000.0f);
        main_task.begin_frame();
        ((TMainTask *)((u8 *)&main_task))->run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        render_tick();
        main_task.begin_frame();
        ((TMainTask *)((u8 *)&main_task))->run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        render_tick();
        main_task.begin_frame();
        ((TMainTask *)((u8 *)&main_task))->run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        render_tick();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
        main_task.toggle_pause_layers();
        quest_download_active = 1;
        quest_download_received_bytes = 0;
        quest_download_graph_current_bytes = 0;
    }
    if (arg0 == NULL) {
        return;
    }
    memset(buf, 0, 0x10);
    strncpy(buf, arg0->name, 0x10);
    if (strtok(buf, ".") == NULL) {
        return;
    }
    tok = strtok(NULL, "");
    if (tok == NULL) {
        return;
    }
    if (strncmp(tok, "dat", 4) == 0) {
        s = (Slot_802150E8 *)TQuestListOnline__dat_download_state;
        if (s->buf == NULL) {
            strncpy(s->name, arg0->name, 0x10);
            ((Slot_802150E8 *)TQuestListOnline__dat_download_state)->size = arg0->size;
            s->buf = mem_alloc(arg0->size);
            memset(s->buf, 0, arg0->size);
            TQuestListOnline__dat_download_complete = 0;
            quest_download_received_bytes += arg0->size;
        }
    } else if (strncmp(tok, "bin", 4) == 0) {
        s = (Slot_802150E8 *)TQuestListOnline__bin_download_state;
        if (s->buf == NULL) {
            strncpy(s->name, arg0->name, 0x10);
            ((Slot_802150E8 *)TQuestListOnline__bin_download_state)->size = arg0->size;
            s->buf = mem_alloc(arg0->size);
            memset(s->buf, 0, arg0->size);
            TQuestListOnline__bin_download_complete = 0;
            TDLGraph::update_graph(quest_download_graph_current_bytes, quest_download_received_bytes += arg0->size);
        }
    }
}

void TQuestListOnline::receive_quest_info(void *arg0) {
    if ((u32) TQuestListOnline__selected_quest_info != 0U) {
        memcpy((void *)TQuestListOnline__selected_quest_info, arg0, 0x124);
        TQuestListOnline__sub_8013ACF4(2);
        if (THunterGuildSeqOffline__sub_80212074() != 0) {
            ((TWindowCtrl *)local_client_id)->suppress_slot();
            if ((u32) TQuestListOnline__quest_info_window != 0U) {
                ((TWindowBase *)TQuestListOnline__quest_info_window)->close();
                TQuestListOnline__quest_info_window = 0;
            }
            NJS_POINT2 p = quest_info_window_size;
            TQuestListOnline__quest_info_window = create__14TWindowMessageFlPCfUll(get_window_layout_position(0x2E), &p, 1, local_client_id);
            ((TWindowBase *)TQuestListOnline__quest_info_window)->set_depth(37000.0f);
            ((TWindowMessage *)TQuestListOnline__quest_info_window)->append_line(TQuestListOnline__selected_quest_info + 4, 0x80);
            if (TCameraCtrl::get_camera_id() >= 2) {
                ((TWindowAddition *)TQuestListOnline__quest_info_window)->set_position_xy(0.75f, 0.75f);
            }
        }
    }
}

void TQuestListOnline::copy_quest_list_data() {
    if ((u32) TQuestListOnline__quest_list_buffer != 0U) {
        memcpy((void *)TQuestListOnline__quest_list_buffer, this, 0x11D4);
        TQuestListOnline__sub_8013ACF4(1);
    }
}

void TQuestListOnline::release_resources() {
    if ((u32) *(u32 *)((s8 *)&TQuestListOnline__bin_download_state + 0x38) != 0U) {
        mem_free((void *)(*(uaddr *)((s8 *)&TQuestListOnline__bin_download_state + 0x38)));
        *(u32 *)((s8 *)&TQuestListOnline__bin_download_state + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)&TQuestListOnline__dat_download_state + 0x38) != 0U) {
        mem_free((void *)(*(uaddr *)((s8 *)&TQuestListOnline__dat_download_state + 0x38)));
        *(u32 *)((s8 *)&TQuestListOnline__dat_download_state + 0x38) = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__selected_quest_info) != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((int) ((*(u32 *)&TQuestListOnline__selected_quest_info)));
        (*(u32 *)&TQuestListOnline__selected_quest_info) = 0U;
    }
    if ((u32) TQuestListOnline__quest_list_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(TQuestListOnline__quest_list_buffer);
        TQuestListOnline__quest_list_buffer = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__download_window) != 0U) {
        ((TWindowBase *)(*(uaddr *)&TQuestListOnline__download_window))->close();
        (*(u32 *)&TQuestListOnline__download_window) = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__quest_info_window) != 0U) {
        ((TWindowBase *)(*(uaddr *)&TQuestListOnline__quest_info_window))->close();
        (*(u32 *)&TQuestListOnline__quest_info_window) = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__download_barrier_window) != 0U) {
        ((TWindowBase *)(*(uaddr *)&TQuestListOnline__download_barrier_window))->close();
        (*(u32 *)&TQuestListOnline__download_barrier_window) = 0U;
    }
    (*(s32 *)&quest_download_active) = 0;
    memset((void*)&TQuestListOnline__dat_download_state, 0, 0x3C);
    memset((void*)&TQuestListOnline__bin_download_state, 0, 0x3C);
    (*(s32 *)&TQuestListOnline__bin_download_complete) = 0;
    (*(s32 *)&TQuestListOnline__dat_download_complete) = 0;
    TQuestListOnline__instance = 0;
}

void TQuestListOnline::init_download_buffers() {
    (*(s32 *)&TQuestListOnline__quest_list_buffer) = (saddr)TQuestVmDownLoadServer::alloc(0x11D4);
    TQuestListOnline__selected_quest_info = (saddr)TQuestVmDownLoadServer::alloc(0x124);
    (*(s32 *)&TQuestListOnline__download_window) = 0;
    (*(s32 *)&TQuestListOnline__quest_info_window) = 0;
    (*(s32 *)&TQuestListOnline__download_barrier_window) = 0;
    (*(s32 *)&quest_download_active) = 0;
    memset((void*)&TQuestListOnline__dat_download_state, 0, 0x3C);
    memset((void*)&TQuestListOnline__bin_download_state, 0, 0x3C);
    (*(s32 *)&TQuestListOnline__bin_download_complete) = 0;
    (*(s32 *)&TQuestListOnline__dat_download_complete) = 0;
    TQuestListOnline__instance = 0;
}

void reset_globals(void) { TQuestListOnline__download_window = 0; TQuestListOnline__quest_info_window = 0; TQuestListOnline__download_barrier_window = 0; quest_download_active = 0; memset(TQuestListOnline__dat_download_state, 0, 60); memset(TQuestListOnline__bin_download_state, 0, 60); TQuestListOnline__bin_download_complete = 0; TQuestListOnline__dat_download_complete = 0; quest_download_received_bytes = 0; quest_download_graph_current_bytes = 0; }
}
