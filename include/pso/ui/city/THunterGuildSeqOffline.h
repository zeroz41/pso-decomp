#ifndef PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_H
#define PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TQuestThread;
struct TWindowMenu;

struct THunterGuildSeqOffline : public TShopSequence {
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
    static void *create(void *player);
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
    TQuestThread *m_34;       // 0x34: TQuestThread::create_in_root
    s32 unk_38;
    void advance_matching_entries(s32 arg1, s32 arg2);
    static void clear_slots();
    static void reset_quest_list_vm();
    static void clear_slot_flags();
    static void zero_four_slots();
};

LAYOUT_ASSERT(THunterGuildSeqOffline_size, sizeof(THunterGuildSeqOffline) == 0x3C);
extern "C" THunterGuildSeqOffline *THunterGuildSeqOffline__active_instance;

extern "C" void THunterGuildSeqOffline__sub_80213410(void);
#endif
