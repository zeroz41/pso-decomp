#include "pso/system/memory.h"
#include "pso/unk/TScreenFadeOut.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/OnlineQuestMenuRecords.h"
#include "pso/quest/OnlineQuestDownloadState.h"
#include "pso/render/TDLGraph.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildSeqOffline_80213788.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/player/PlayerSlots.h"


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
extern s32 evt2_random_enemies_mode;
extern int TQuestListOnline__bin_download_complete;
extern int TQuestListOnline__dat_download_complete;
void TKeyBoardControl__sub_8000F950();
extern s32 local_client_id;
extern s32 quest_download_active;
saddr get_message_text(s32 arg0);
void *get_window_layout_position(s32);
extern s32 quest_download_received_bytes;
extern s32 quest_download_graph_current_bytes;
}

void THunterGuildSeqOnlineTask::run_task() {
    ControllerInputContext *p;
    if (TQuestListOnline__quest_info_window != NULL) {
        p = &controller_input_state.controllers[0];
        if (test_pressed_buttons_packed(p, 4) != 0 ||
            test_pressed_buttons_packed(p, 2) != 0) {
            TQuestListOnline__quest_info_window->close();
            TQuestListOnline__quest_info_window = NULL;
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
    }
}

THunterGuildSeqOnlineTask::~THunterGuildSeqOnlineTask() {}


THunterGuildSeqOnlineTask::THunterGuildSeqOnlineTask(TObject *parent) : TObject(parent) {
    m_name = THunterGuildSeqOnlineTask__name;
}
void handle_6x73_exit_quest(void);

void handle_6x73_exit_quest(void) {
    new TScreenFadeOut(tl_00, reset_random_enemies_mode);
}

void TQuestListOnline::close_windows_and_reset() {
    OnlineQuestDownloadState *q;
    if (TKeyBoardControl::get_input() == 0) {
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F95C();
        q = &TQuestListOnline__bin_download_state;
        if (q->buffer != NULL) {
            mem_free(q->buffer);
            q->buffer = NULL;
        }
        q = &TQuestListOnline__dat_download_state;
        if (q->buffer != NULL) {
            mem_free(q->buffer);
            q->buffer = NULL;
        }
        if (TQuestListOnline__download_window != NULL) {
            TQuestListOnline__download_window->close();
            TQuestListOnline__download_window = NULL;
        }
        if (TQuestListOnline__quest_info_window != NULL) {
            TQuestListOnline__quest_info_window->close();
            TQuestListOnline__quest_info_window = NULL;
        }
        if (TQuestListOnline__download_barrier_window != NULL) {
            TQuestListOnline__download_barrier_window->close();
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
    OnlineQuestDownloadState *q;
    s32 r;
    s32 m;
    if (TQuestListOnline::init() != 0) {
        q = &TQuestListOnline__bin_download_state;
        TQuestListOnline::decompress_quest_buffer(q->buffer, q->size);
        q = &TQuestListOnline__dat_download_state;
        TQuestListOnline__sub_802176DC(q->buffer, q->size);
        TLobby::set_enemy_mode_flag();
        r = TLobby::is_flag_set();
        m = 2;
        if (r != 0) {
            m = 4;
        }
        evt2_random_enemies_mode = m;
        TKeyBoardControl__sub_8000F950();
        TWindowCtrl::unsuppress_slot(local_client_id);
    } else {
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F95C();
        q = &TQuestListOnline__bin_download_state;
        if (q->buffer != NULL) {
            mem_free(q->buffer);
            q->buffer = NULL;
        }
        q = &TQuestListOnline__dat_download_state;
        if (q->buffer != NULL) {
            mem_free(q->buffer);
            q->buffer = NULL;
        }
        TQuestListOnline__bin_download_complete = 0;
        TQuestListOnline__dat_download_complete = 0;
        TQuestListOnline__sub_8013ACF4(0xB);
    }
    if (TQuestListOnline__download_window != NULL) {
        TQuestListOnline__download_window->close();
        TQuestListOnline__download_window = NULL;
    }
    if (TQuestListOnline__quest_info_window != NULL) {
        TQuestListOnline__quest_info_window->close();
        TQuestListOnline__quest_info_window = NULL;
    }
    if (TQuestListOnline__download_barrier_window != NULL) {
        TQuestListOnline__download_barrier_window->close();
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
    TWindowCtrl::unsuppress_slot(local_client_id);
}
void TLobby::handle_quest_download_chunk() {
    Pkt_80214F80 *p = (Pkt_80214F80 *)this;
    int *flag;
    u8 *buf;
    if (p != NULL) {
        if (strncmp(TQuestListOnline__dat_download_state.name, p->name, 0x10) == 0) {
            flag = &TQuestListOnline__dat_download_complete;
            buf = TQuestListOnline__dat_download_state.buffer;
        } else if (strncmp(TQuestListOnline__bin_download_state.name, p->name, 0x10) == 0) {
            flag = &TQuestListOnline__bin_download_complete;
            buf = TQuestListOnline__bin_download_state.buffer;
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
            TQuestListOnline__download_barrier_window = reinterpret_cast<TWindowMessage *>(
                create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xBE), &pos));
            TQuestListOnline__download_barrier_window->append_line((int)(get_message_text(0x61)), (int)1);
            TQuestListOnline__download_barrier_window->set_depth(36000.0f);
            TQuestListOnline__download_barrier_window->complete_reveal();
        }
        protocol_instance->send_quest_barrier();
    }
}

s32 get_guild_text(s32);
extern "C" {
char *strtok(char *, const char *);
s32 THunterGuildSeqOffline__sub_80212074();

void TQuestListOnline::begin_file_download(TRecvDownloadHead &file) {
    TRecvDownloadHead *arg0 = &file;
    char buf[0x10];
    char *tok;
    OnlineQuestDownloadState *s;
    if (TQuestListOnline__download_window == NULL) {
        NJS_POINT2 p = download_window_size;
        TQuestListOnline__download_window = reinterpret_cast<TWindowMessage *>(
            create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0x2C), &p));
        TQuestListOnline__download_window->append_line(get_guild_text(0x14), 1);
        TQuestListOnline__download_window->complete_reveal();
        TQuestListOnline__download_window->set_depth(37000.0f);
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
        TWindowCtrl::suppress_slot(local_client_id);
        main_task.toggle_pause_layers();
        quest_download_active = 1;
        quest_download_received_bytes = 0;
        quest_download_graph_current_bytes = 0;
    }
    if (arg0 == NULL) {
        return;
    }
    memset(buf, 0, sizeof(buf));
    strncpy(buf, arg0->filename, 0x10);
    if (strtok(buf, ".") == NULL) {
        return;
    }
    tok = strtok(NULL, "");
    if (tok == NULL) {
        return;
    }
    if (strncmp(tok, "dat", 4) == 0) {
        s = &TQuestListOnline__dat_download_state;
        if (s->buffer == NULL) {
            strncpy(s->name, arg0->filename, 0x10);
            TQuestListOnline__dat_download_state.size = arg0->file_size;
            s->buffer = (u8 *)mem_alloc(arg0->file_size);
            memset(s->buffer, 0, arg0->file_size);
            TQuestListOnline__dat_download_complete = 0;
            quest_download_received_bytes += arg0->file_size;
        }
    } else if (strncmp(tok, "bin", 4) == 0) {
        s = &TQuestListOnline__bin_download_state;
        if (s->buffer == NULL) {
            strncpy(s->name, arg0->filename, 0x10);
            TQuestListOnline__bin_download_state.size = arg0->file_size;
            s->buffer = (u8 *)mem_alloc(arg0->file_size);
            memset(s->buffer, 0, arg0->file_size);
            TQuestListOnline__bin_download_complete = 0;
            TDLGraph::update_graph(quest_download_graph_current_bytes, quest_download_received_bytes += arg0->file_size);
        }
    }
}

void TQuestListOnline::receive_quest_info(OnlineQuestInfo &info) {
    if (TQuestListOnline__selected_quest_info != NULL) {
        memcpy(TQuestListOnline__selected_quest_info, &info, sizeof(OnlineQuestInfo));
        TQuestListOnline__sub_8013ACF4(2);
        if (THunterGuildSeqOffline__sub_80212074() != 0) {
            TWindowCtrl::suppress_slot(local_client_id);
            if (TQuestListOnline__quest_info_window != NULL) {
                TQuestListOnline__quest_info_window->close();
                TQuestListOnline__quest_info_window = NULL;
            }
            NJS_POINT2 p = quest_info_window_size;
            TQuestListOnline__quest_info_window = (TWindowMessage *)TWindowMessage::create((saddr)get_window_layout_position(0x2E), (const f32 *)&p, 1, local_client_id);
            TQuestListOnline__quest_info_window->set_depth(37000.0f);
            TQuestListOnline__quest_info_window->append_line((saddr)TQuestListOnline__selected_quest_info->text, 0x80);
            if (TCameraCtrl::get_camera_id() >= 2) {
                TQuestListOnline__quest_info_window->set_position_xy(0.75f, 0.75f);
            }
        }
    }
}

void copy_quest_list_data__16TQuestListOnlineFv(OnlineQuestMenu &menu) {
    if (TQuestListOnline__quest_list_buffer != NULL) {
        memcpy(TQuestListOnline__quest_list_buffer, &menu, sizeof(OnlineQuestMenu));
        TQuestListOnline__sub_8013ACF4(1);
    }
}

void TQuestListOnline::release_resources() {
    if (TQuestListOnline__bin_download_state.buffer != NULL) {
        mem_free(TQuestListOnline__bin_download_state.buffer);
        TQuestListOnline__bin_download_state.buffer = NULL;
    }
    if (TQuestListOnline__dat_download_state.buffer != NULL) {
        mem_free(TQuestListOnline__dat_download_state.buffer);
        TQuestListOnline__dat_download_state.buffer = NULL;
    }
    if (TQuestListOnline__selected_quest_info != NULL) {
        safe_free(TQuestListOnline__selected_quest_info);
        TQuestListOnline__selected_quest_info = NULL;
    }
    if (TQuestListOnline__quest_list_buffer != NULL) {
        safe_free(TQuestListOnline__quest_list_buffer);
        TQuestListOnline__quest_list_buffer = NULL;
    }
    if (TQuestListOnline__download_window != NULL) {
        TQuestListOnline__download_window->close();
        TQuestListOnline__download_window = NULL;
    }
    if (TQuestListOnline__quest_info_window != NULL) {
        TQuestListOnline__quest_info_window->close();
        TQuestListOnline__quest_info_window = NULL;
    }
    if (TQuestListOnline__download_barrier_window != NULL) {
        TQuestListOnline__download_barrier_window->close();
        TQuestListOnline__download_barrier_window = NULL;
    }
    (*(s32 *)&quest_download_active) = 0;
    memset(&TQuestListOnline__dat_download_state, 0, sizeof(OnlineQuestDownloadState));
    memset(&TQuestListOnline__bin_download_state, 0, sizeof(OnlineQuestDownloadState));
    (*(s32 *)&TQuestListOnline__bin_download_complete) = 0;
    (*(s32 *)&TQuestListOnline__dat_download_complete) = 0;
    TQuestListOnline__instance = 0;
}

void TQuestListOnline::init_download_buffers() {
    TQuestListOnline__quest_list_buffer = (OnlineQuestMenu *)TQuestVmDownLoadServer::alloc(sizeof(OnlineQuestMenu));
    TQuestListOnline__selected_quest_info = (OnlineQuestInfo *)TQuestVmDownLoadServer::alloc(sizeof(OnlineQuestInfo));
    TQuestListOnline__download_window = NULL;
    TQuestListOnline__quest_info_window = NULL;
    TQuestListOnline__download_barrier_window = NULL;
    (*(s32 *)&quest_download_active) = 0;
    memset(&TQuestListOnline__dat_download_state, 0, sizeof(OnlineQuestDownloadState));
    memset(&TQuestListOnline__bin_download_state, 0, sizeof(OnlineQuestDownloadState));
    (*(s32 *)&TQuestListOnline__bin_download_complete) = 0;
    (*(s32 *)&TQuestListOnline__dat_download_complete) = 0;
    TQuestListOnline__instance = 0;
}

void reset_globals(void) { TQuestListOnline__download_window = NULL; TQuestListOnline__quest_info_window = NULL; TQuestListOnline__download_barrier_window = NULL; quest_download_active = 0; memset(&TQuestListOnline__dat_download_state, 0, sizeof(OnlineQuestDownloadState)); memset(&TQuestListOnline__bin_download_state, 0, sizeof(OnlineQuestDownloadState)); TQuestListOnline__bin_download_complete = 0; TQuestListOnline__dat_download_complete = 0; quest_download_received_bytes = 0; quest_download_graph_current_bytes = 0; }
}
