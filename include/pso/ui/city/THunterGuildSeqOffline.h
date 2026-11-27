#ifndef PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_H
#define PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TObjPlayer;
class TQuestThread;
struct TWindowMenu;

struct THunterGuildSeqOffline : public TShopSequence {
    static THunterGuildSeqOffline * active_instance;
    static s32 instance_table[4];
    THunterGuildSeqOffline(TObject *parent, TObjPlayer *player);
    virtual ~THunterGuildSeqOffline();
    virtual void close_window();
    virtual void restore_player_state();
    void update_state();
    void handle_select();
    void open_judgment_window();
    void resolve_active_quest_result();
    void open_greeting();
    static void clear_instance_table();
    static void notify_quest_thread();
    static void reset_quest_result_callbacks();
    static void unload_quest_result_callbacks();
    static THunterGuildSeqOffline *create(TObjPlayer *player);
    static s32 check_party_gathered();
    static void set_state_close(TShopWindowBase *sequence);
    static void set_state_4(TShopWindowBase *sequence);
    void handle_click();
    static void set_state_3();
    static void init_quest_list();
    static void notify_close();
    static void create_quest_list_vm(TShopWindowBase *sequence);
    static void set_state_close2(TShopWindowBase *sequence);
    static void set_enemy_mode_5(TObject *fade);
    static void set_enemy_mode_1(TObject *fade);
    static void set_enemy_mode_0(TObject *fade);
    static void request_close(TShopWindowBase *sequence);
    void handle_cancel_choice();
    void open_quest_list();
    void handle_window_input();
    TWindowMenu *choice_menu; // 0x2C: create_yes_no_window
    TObject *counter_camera; // 0x30: set_service_counter_camera
    TQuestThread *quest_thread;       // 0x34: TQuestThread::create_in_root
    s32 exit_action;       // 0: close; 1-4: leave through a fade-out that sets enemy mode 0, 1, 3 or 5
    static void clear_slots();
    static void clear_slot_flags();
    static void zero_four_slots();
};

LAYOUT_ASSERT(THunterGuildSeqOffline_size, sizeof(THunterGuildSeqOffline) == 0x3C);

// Quest thread ids started per quest result ([1] success, [2] cancel, [3] exit); -1 when unset.
extern "C" s32 quest_result_callbacks[4];

s32 get_online_client_state(void);
void clear_offline_instance_table(void);

void set_quest_failure_callback(s32 quest_failure_callback);
void set_quest_cancel_callback(s32 quest_cancel_callback);
void set_quest_exit_callback(s32 quest_exit_callback);
void set_quest_success_callback(s32 quest_success_callback);


// Nonzero while a THunterGuildSeqOnline (client or server side) or a THunterGuildSeqOffline runs for the client.
s32 get_online_client_instance(s32 client_id);
s32 get_online_server_instance(s32 client_id);
s32 get_offline_instance(s32 client_id);
s32 is_near_designated_player(void);

struct GuildMenuCallbackBase { char pad[0x18]; };

#endif
