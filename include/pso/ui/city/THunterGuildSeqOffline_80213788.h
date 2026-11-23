#ifndef PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_80213788_H
#define PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_80213788_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TQuestThread;
class TWindowBase;
struct TWindowMenu;

// The hunter's guild counter in an online lobby: the client side (vtable 0x804C9740) and the
// server side (vtable 0x804C97F0). Both derive straight from TShopSequence (their ctors call it).
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
    void sub_80213B18();
    void sub_80213980();
    TObject *counter_camera;  // 0x2C: set_service_counter_camera
    s32 pad_30;
    s32 pad_34;
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
    void sub_802145F8();
    void sub_80214058();
    void update_confirm_input();
    void update();
    void create_judgment_item_window();
    void sub_80214254();
    void confirm_and_close_if_valid();
    TObject *counter_camera;  // 0x2C: set_service_counter_camera
    s32 pad_30;
    s32 pad_34;
    TWindowMenu *choice_menu; // 0x38: create_yes_no_window
    TObject *quest_thread;    // 0x3C: TQuestThread::create_in_root
    s32 pad_40;
};

LAYOUT_ASSERT(THunterGuildSeqOnline_Server_size, sizeof(THunterGuildSeqOnline_Server) == 0x44);

// The live counter of each side; set by its ctor, cleared by its dtor.
extern THunterGuildSeqOnline_Server *hunter_guild_seq_online_server_instance;
extern THunterGuildSeqOnline_Client *hunter_guild_seq_online_client_instance;

void set_random_enemies_mode(TObject *fade);
void reset_random_enemies_mode(TObject *fade);

// --- C functions defined in THunterGuildSeqOffline_80213788.cpp ---
extern "C" {
void THunterGuildSeqOffline__sub_80213CA4(void);
void THunterGuildSeqOffline__sub_80213E64(void);
void THunterGuildSeqOffline__sub_80213EBC(void);
void THunterGuildSeqOffline__sub_80213F78(void);
}
// --- end of C functions

#endif
