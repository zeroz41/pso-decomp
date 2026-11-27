#include "pso/system/memory.h"
#include "pso/system/TScreenFadeOut.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/OnlineQuestMenuRecords.h"
#include "pso/quest/OnlineQuestDownloadState.h"
#include "pso/render/TDLGraph.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildSeqOnline.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/player/PlayerSlots.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/ui/CounterTextLookup.h"
#include "pso/quest/QuestActiveFlag.h"


// Window sizes {width, height} of the quest download windows.
static const NJS_POINT2 quest_info_window_size = {332.0f, 210.0f};
static const NJS_POINT2 download_window_size = {332.0f, 80.0f};
static const NJS_POINT2 download_barrier_window_size = {332.0f, 80.0f};

const char *hunter_guild_seq_online_task_name = "THunterGuildSeqOnlineTask";
const char *hunter_guild_seq_online_server_name = "THunterGuildSeqOnline_Server";
const char *hunter_guild_seq_online_client_name = "THunterGuildSeqOnline_Client";


void THunterGuildSeqOnlineTask::run_task() {
    ControllerInputContext *p;
    if (online_quest_info_window != NULL) {
        p = &controller_input_state.controllers[0];
        if (test_pressed_buttons_packed(p, 4) != 0 ||
            test_pressed_buttons_packed(p, 2) != 0) {
            online_quest_info_window->close();
            online_quest_info_window = NULL;
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
    }
}

THunterGuildSeqOnlineTask::~THunterGuildSeqOnlineTask() {}


THunterGuildSeqOnlineTask::THunterGuildSeqOnlineTask(TObject *parent) : TObject(parent) {
    m_name = hunter_guild_seq_online_task_name;
}

void handle_6x73_exit_quest(void) {
    new TScreenFadeOut(tl_00, reset_random_enemies_mode);
}

void close_windows_and_reset() {
    OnlineQuestDownloadState *q;
    if (get_input() == 0) {
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        clear_keyboard_input_flag();
        q = &quest_list_online_bin_download_state;
        if (q->buffer != NULL) {
            delete[] q->buffer;
            q->buffer = NULL;
        }
        q = &quest_list_online_dat_download_state;
        if (q->buffer != NULL) {
            delete[] q->buffer;
            q->buffer = NULL;
        }
        if (online_quest_download_window != NULL) {
            online_quest_download_window->close();
            online_quest_download_window = NULL;
        }
        if (online_quest_info_window != NULL) {
            online_quest_info_window->close();
            online_quest_info_window = NULL;
        }
        if (online_quest_download_barrier_window != NULL) {
            online_quest_download_barrier_window->close();
            online_quest_download_barrier_window = NULL;
        }
        online_quest_bin_download_complete = 0;
        online_quest_dat_download_complete = 0;
        set_quest_list_online_state(0xB);
        TQuestListOnline::ensure_online_quests_loaded();
        main_task.resume_layers();
        TQuestVmDownLoadServer::reset_download();
    }
}
void handle_quest_ready() {
    s32 i;
    TObjPlayer *p;
    OnlineQuestDownloadState *q;
    s32 r;
    s32 m;
    if (TQuestListOnline::init() != 0) {
        q = &quest_list_online_bin_download_state;
        TQuestListOnline::decompress_quest_buffer(q->buffer, q->size);
        q = &quest_list_online_dat_download_state;
        decompress_online_quest_dat(q->buffer, q->size);
        set_enemy_mode_flag();
        r = is_challenge_mode();
        m = 2;
        if (r != 0) {
            m = 4;
        }
        evt2_random_enemies_mode = m;
        set_keyboard_input_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
    } else {
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        clear_keyboard_input_flag();
        q = &quest_list_online_bin_download_state;
        if (q->buffer != NULL) {
            delete[] q->buffer;
            q->buffer = NULL;
        }
        q = &quest_list_online_dat_download_state;
        if (q->buffer != NULL) {
            delete[] q->buffer;
            q->buffer = NULL;
        }
        online_quest_bin_download_complete = 0;
        online_quest_dat_download_complete = 0;
        set_quest_list_online_state(0xB);
    }
    if (online_quest_download_window != NULL) {
        online_quest_download_window->close();
        online_quest_download_window = NULL;
    }
    if (online_quest_info_window != NULL) {
        online_quest_info_window->close();
        online_quest_info_window = NULL;
    }
    if (online_quest_download_barrier_window != NULL) {
        online_quest_download_barrier_window->close();
        online_quest_download_barrier_window = NULL;
    }
    main_task.resume_layers();
    quest_download_active = 0;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            p->clear_lobby_flag();
            p->activate_body_collision();
        }
    }
    TWindowCtrl::unsuppress_slot(local_client_id);
}
void handle_quest_download_chunk(TRecvDownload &download) {
    TRecvDownload *p = &download;
    int *flag;
    u8 *buf;
    if (p != NULL) {
        if (strncmp(quest_list_online_dat_download_state.name, p->filename, 0x10) == 0) {
            flag = &online_quest_dat_download_complete;
            buf = quest_list_online_dat_download_state.buffer;
        } else if (strncmp(quest_list_online_bin_download_state.name, p->filename, 0x10) == 0) {
            flag = &online_quest_bin_download_complete;
            buf = quest_list_online_bin_download_state.buffer;
        } else {
            return;
        }
        if (buf != NULL) {
            memcpy(buf + (p->header.flags << 10), p->data, p->data_size);
            quest_download_graph_current_bytes += p->data_size;
            TDLGraph::update_graph(quest_download_graph_current_bytes, quest_download_received_bytes);
            if (p->data_size < 0x400) {
                *flag = 1;
            }
        } else {
            return;
        }
    }
    if (online_quest_bin_download_complete != 0 && online_quest_dat_download_complete != 0) {
        if (online_quest_download_barrier_window == NULL) {
            NJS_POINT2 pos = download_barrier_window_size;
            online_quest_download_barrier_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xBE), &pos);
            online_quest_download_barrier_window->append_line((get_message_text(0x61)), (int)1);
            online_quest_download_barrier_window->set_depth(36000.0f);
            online_quest_download_barrier_window->complete_reveal();
        }
        TLobby::protocol_instance->send_quest_barrier();
    }
}


void begin_file_download(TRecvDownloadHead &file) {
    TRecvDownloadHead *head = &file;
    char buf[0x10];
    char *tok;
    OnlineQuestDownloadState *s;
    if (online_quest_download_window == NULL) {
        NJS_POINT2 p = download_window_size;
        online_quest_download_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0x2C), &p);
        online_quest_download_window->append_line(get_guild_text(0x14), 1);
        online_quest_download_window->complete_reveal();
        online_quest_download_window->set_depth(37000.0f);
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
    if (head == NULL) {
        return;
    }
    memset(buf, 0, sizeof(buf));
    strncpy(buf, head->filename, 0x10);
    if (strtok(buf, ".") == NULL) {
        return;
    }
    tok = strtok(NULL, "");
    if (tok == NULL) {
        return;
    }
    if (strncmp(tok, "dat", 4) == 0) {
        s = &quest_list_online_dat_download_state;
        if (s->buffer == NULL) {
            strncpy(s->name, head->filename, 0x10);
            quest_list_online_dat_download_state.size = head->file_size;
            s->buffer = new u8[head->file_size];
            memset(s->buffer, 0, head->file_size);
            online_quest_dat_download_complete = 0;
            quest_download_received_bytes += head->file_size;
        }
    } else if (strncmp(tok, "bin", 4) == 0) {
        s = &quest_list_online_bin_download_state;
        if (s->buffer == NULL) {
            strncpy(s->name, head->filename, 0x10);
            quest_list_online_bin_download_state.size = head->file_size;
            s->buffer = new u8[head->file_size];
            memset(s->buffer, 0, head->file_size);
            online_quest_bin_download_complete = 0;
            TDLGraph::update_graph(quest_download_graph_current_bytes, quest_download_received_bytes += head->file_size);
        }
    }
}

void receive_quest_info(OnlineQuestInfo &info) {
    if (quest_list_online_selected_quest_info != NULL) {
        memcpy(quest_list_online_selected_quest_info, &info, sizeof(OnlineQuestInfo));
        set_quest_list_online_state(2);
        if (is_near_designated_player() != 0) {
            TWindowCtrl::suppress_slot(local_client_id);
            if (online_quest_info_window != NULL) {
                online_quest_info_window->close();
                online_quest_info_window = NULL;
            }
            NJS_POINT2 p = quest_info_window_size;
            online_quest_info_window = TWindowMessage::create(get_window_layout_position(0x2E), (const f32 *)&p, 1, local_client_id);
            online_quest_info_window->set_depth(37000.0f);
            online_quest_info_window->append_line(quest_list_online_selected_quest_info->text, 0x80);
            if (TCameraCtrl::get_camera_id() >= 2) {
                online_quest_info_window->set_position_xy(0.75f, 0.75f);
            }
        }
    }
}
void copy_quest_list_data(OnlineQuestMenu &menu) {
    if (quest_list_online_quest_list_buffer != NULL) {
        memcpy(quest_list_online_quest_list_buffer, &menu, sizeof(OnlineQuestMenu));
        set_quest_list_online_state(1);
    }
}

void release_resources() {
    if (quest_list_online_bin_download_state.buffer != NULL) {
        delete[] quest_list_online_bin_download_state.buffer;
        quest_list_online_bin_download_state.buffer = NULL;
    }
    if (quest_list_online_dat_download_state.buffer != NULL) {
        delete[] quest_list_online_dat_download_state.buffer;
        quest_list_online_dat_download_state.buffer = NULL;
    }
    if (quest_list_online_selected_quest_info != NULL) {
        safe_free(quest_list_online_selected_quest_info);
        quest_list_online_selected_quest_info = NULL;
    }
    if (quest_list_online_quest_list_buffer != NULL) {
        safe_free(quest_list_online_quest_list_buffer);
        quest_list_online_quest_list_buffer = NULL;
    }
    if (online_quest_download_window != NULL) {
        online_quest_download_window->close();
        online_quest_download_window = NULL;
    }
    if (online_quest_info_window != NULL) {
        online_quest_info_window->close();
        online_quest_info_window = NULL;
    }
    if (online_quest_download_barrier_window != NULL) {
        online_quest_download_barrier_window->close();
        online_quest_download_barrier_window = NULL;
    }
    quest_download_active = 0;
    memset(&quest_list_online_dat_download_state, 0, sizeof(OnlineQuestDownloadState));
    memset(&quest_list_online_bin_download_state, 0, sizeof(OnlineQuestDownloadState));
    online_quest_bin_download_complete = 0;
    online_quest_dat_download_complete = 0;
    quest_list_online_instance = 0;
}

void init_quest_list_online_buffers() {
    quest_list_online_quest_list_buffer = (OnlineQuestMenu *)alloc(sizeof(OnlineQuestMenu));
    quest_list_online_selected_quest_info = (OnlineQuestInfo *)alloc(sizeof(OnlineQuestInfo));
    online_quest_download_window = NULL;
    online_quest_info_window = NULL;
    online_quest_download_barrier_window = NULL;
    quest_download_active = 0;
    memset(&quest_list_online_dat_download_state, 0, sizeof(OnlineQuestDownloadState));
    memset(&quest_list_online_bin_download_state, 0, sizeof(OnlineQuestDownloadState));
    online_quest_bin_download_complete = 0;
    online_quest_dat_download_complete = 0;
    quest_list_online_instance = 0;
}

void reset_globals(void) { online_quest_download_window = NULL; online_quest_info_window = NULL; online_quest_download_barrier_window = NULL; quest_download_active = 0; memset(&quest_list_online_dat_download_state, 0, sizeof(OnlineQuestDownloadState)); memset(&quest_list_online_bin_download_state, 0, sizeof(OnlineQuestDownloadState)); online_quest_bin_download_complete = 0; online_quest_dat_download_complete = 0; quest_download_received_bytes = 0; quest_download_graph_current_bytes = 0; }
