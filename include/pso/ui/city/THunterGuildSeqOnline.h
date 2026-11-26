#ifndef PSO_UI_CITY_THUNTERGUILDSEQONLINE_H
#define PSO_UI_CITY_THUNTERGUILDSEQONLINE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TQuestThread;
class TWindowBase;
struct TWindowMenu;

// The hunter's guild counter in an online lobby: the client side and the
// server side. Both derive straight from TShopSequence (their ctors call it).
struct THunterGuildSeqOnline_Client : public TShopSequence {
    THunterGuildSeqOnline_Client(TObject *parent, TObjPlayer *player);
    virtual ~THunterGuildSeqOnline_Client();
    void update_state();
    void restore_player_state();
    void close_window();
    void handle_confirm_window();
    void open_judgment_item_window();
    void update_shop_close();
    void update_close_shop();
    void handle_close();
    void open_greeting();
    void resolve_active_quest_result();
    TObject *counter_camera;  // 0x2C: set_service_counter_camera
    s32 check_step;
    s32 exit_action;  // 1: close_window leaves through the fade-out; 0 and 2 just close
    TQuestThread *quest_thread;    // 0x38: TQuestThread::create_in_root
    TWindowMenu *choice_menu; // 0x3C: create_yes_no_window
};

LAYOUT_ASSERT(THunterGuildSeqOnline_Client_size, sizeof(THunterGuildSeqOnline_Client) == 0x40);

struct THunterGuildSeqOnline_Server : public TShopSequence {
    THunterGuildSeqOnline_Server(TObject *parent, TObjPlayer *player);
    virtual ~THunterGuildSeqOnline_Server();
    void update_state();
    void restore_player_state();
    void close_window();
    void init_window();
    void handle_party_check();
    void open_quest_list();
    void update_confirm_input();
    void update();
    void create_judgment_item_window();
    void handle_judgment_choice();
    void confirm_and_close_if_valid();
    TObject *counter_camera;  // 0x2C: set_service_counter_camera
    s32 check_step;
    s32 exit_action;  // 1: close_window leaves through the fade-out; 0 and 2 just close
    TWindowMenu *choice_menu; // 0x38: create_yes_no_window
    TObject *quest_thread;    // 0x3C: TQuestThread::create_in_root
    s32 message_pending;
};

LAYOUT_ASSERT(THunterGuildSeqOnline_Server_size, sizeof(THunterGuildSeqOnline_Server) == 0x44);

// The live counter of each side; set by its ctor, cleared by its dtor.
extern THunterGuildSeqOnline_Server *hunter_guild_seq_online_server_instance;
extern THunterGuildSeqOnline_Client *hunter_guild_seq_online_client_instance;
extern s32 quest_download_active;
// Per-player slot flags, set by each class's ctor and cleared by its dtor.
extern s32 hunter_guild_online_server_instance_table[4];
extern s32 hunter_guild_online_client_instance_table[4];

void set_random_enemies_mode(TObject *fade);
void reset_random_enemies_mode(TObject *fade);

// --- C functions defined in THunterGuildSeqOnline.cpp ---
void clear_online_client_instance_table(void);
void on_guild_quest_downloaded(void);
void on_guild_quest_list_cancelled(void);
extern "C" {
void on_quest_list_state_10(void);
}
// --- end of C functions

#endif
