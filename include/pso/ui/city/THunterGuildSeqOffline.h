#ifndef PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_H
#define PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct THunterGuildSeqOffline : public TShopSequence {
    virtual ~THunterGuildSeqOffline();
    virtual void close_window();
    virtual void restore_player_state();
    void vfunc_11();
    u32 m_38;
    void handle_select();
    void open_judgment_window();
    void resolve_active_quest_result();
    void open_greeting();
    static void clear_instance_table();
    static void notify_quest_thread();
    static void reset_quest_result_callbacks(void* _w0);
    void handle_confirm_window();
    void open_judgment_item_window();
    static void *create(void *arg0);
    static s32 check_party_gathered();
    static void set_state_close();
    static void set_state_4();
    void handle_click();
    static void set_state_3();
    static void init_quest_list();
    static void notify_close();
    static void create_quest_list_vm();
    static void set_state_close2();
    static void set_enemy_mode_5();
    static void set_enemy_mode_1();
    static void set_enemy_mode_0();
    static void request_close();
    void handle_cancel_choice();
    void open_quest_list();
    void handle_window_input();
    void *init(void *arg1, void *arg2);
    u8 unk_20[0x4];
    s32 m_24;
    u8 unk_28[0x4];
    u8 * m_2c;
    u8 unk_30[0x4];
    s32 m_34;
    u8 unk_38[0x4];
    void advance_matching_entries(s32 arg1, s32 arg2);
};

typedef char THunterGuildSeqOffline_size[sizeof(THunterGuildSeqOffline) == 0x3C ? 1 : -1];
#endif
