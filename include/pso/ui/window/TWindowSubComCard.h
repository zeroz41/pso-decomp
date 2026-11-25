#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ChoiceSearchSelection.h"

struct GuildCardSlot;
struct NJS_POINT2;
struct TWindowComCard;
struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowSubComCardList;
struct TWindowMessageYesNo;
struct TKeyBoardControl;

struct TWindowSubComCard : public TObject {
    static void update_display_value(uaddr list_window, uaddr card_window, s32 *last_selected);
    static GuildCardSlot *get_card_entry(s32 index);
    TWindowSubComCard(TObject *parent, s32 client);
    virtual ~TWindowSubComCard();
    void rebuild_com_card_list(saddr list_window);
    static const char *class_name;
    u32 sub_80272DE0();
    // Stores the option `val` picked for the category `key` (0 is the com param) and updates the menus.
    void set_choice_search_option(ChoiceSearchSelection *selections, s32 key, saddr val);
    s32 reinit(int);
    s32 init_guild_card_tag(int);
    s32 sub_802730E0();
    s32 create_option_list_window(ChoiceSearchSelection *selections, s32 key);
    void sub_802721D8();
    u8 *find_entry_rest(void *, s32);
    void send_state_if_dirty();
    void send_choice_search(ChoiceSearchSelection *selections);
    void handle_close_flag();
    virtual void render();
    virtual void run_task();
    u8 state;
    u8 m_1d;
    u8 _pad1E[0x2];
    uaddr client_id;
    uaddr selected_card;
    uaddr m_28;
    uaddr m_2c;
    ChoiceSearchSelection choice_selections[5];
    uaddr chr_select;
    TWindowMainMenu *parent_menu;
    TWindowMenu *menu_window;
    TWindowMenu *com_card_menu;
    TWindowMenu *sub_menu;
    uaddr message_window;
    TWindowMessageYesNo *confirm_window;
    uaddr com_card_window;
    uaddr user_sort_window;
    uaddr entry_list_window;
    TKeyBoardControl *keyboard;
    TWindowSubComCardList *card_list;
    static saddr get_card_slot(s32 arg0);
    static void *send_command(saddr index);
    static u8 *apply_selection(s32 index);
    static saddr get_com_count();
    static void release();
    static saddr get_chr_select();
    void clear_and_init(void* local_client_id);
    s32 get_card_id();
    int is_active();
    void bswap_guild_card();
    int bswap_guild_card_tag();
    void init_card(void* client_id);
    static int get_keyboard_mode();
    void *init_guild_card();
    static s32 init_card();
    static void remove_entry(s32 index);
    static s32 scroll_list(s32 ply_guild_card_tag);
    static void init_and_press_a(s32 id);
    static void init_and_press_b(s32 client_id);
    void update_press();
    static void select_card_entry(saddr ply_guild_card_tag);
    static s32 contains_profanity(char *text);
    static void mask_profanity_words(char *src, char *dst);
    uaddr get_field_20();
    void set_entry_value_clear_flag(s32 idx, s32 val);
    s32 get_entry_id();
    static s32 create_card_list(saddr parent, s32 card_slot, s32 count, s32 empty_message);
    void free_windows();
    void update_card_slot();
    void notify_trade_main();
    void*init_fields(int rec, int client);
    int is_flag_4_set();
    static f32 trunc_float(f32 value);
    void set_card_text(saddr src);
    u8 *get_card_entry_data();
    static GuildCardSlot *find_card_by_id(u32 id);
    static void swap_cards(s32 first_index, s32 second_index);
    static s32 init_com_card();
    static void remove_card_at(s32 i);
    s32 send_guild_card();
    static void start_player_data_load(s32 ply_guild_card_tag);
    static s32 count_active_cards();
    void set_text(void *text);
    static void handle_press_a(saddr ply_guild_card_tag, s32 id);
    static void handle_press_b(saddr ply_guild_card_tag, s32 client_id);

    void set_card_index(s32 card_index);
    void set_selected_card(s32 card_index);
    void set_help_message(s32 help_index);
    static s32 create_card_action_window();
    s32 create_entry_list_window();
    s32 open_yesno_dialog();
    s32 confirm_and_free();
    static void set_com_param(saddr client_id, s32 com_param);
    void set_page(s16 v);
    void set_display_page();
    static TWindowComCard *create_com_card_window(const NJS_POINT2 *position);
    static s32 create_menu();
    static s32 create_single_entry_window();
    static s32 open_menu();
    static void open_layout_window();
    static void open_mode4_window();
    static s32 create_menu_window();
    static s32 create_player_select_window();
    static saddr create();
    static void cleanup(void* p);
    static u8 *send_cmd_133();
    static void init_layout();
    void *get_message_10(s32 index);
};

LAYOUT_ASSERT(TWindowSubComCard_size, sizeof(TWindowSubComCard) == 0x88);
struct TWindowMenu;
struct TWindowSubComCardList;
extern "C" void add_gray_text_entry(TWindowMenu *list, const char *text, s32 kind, s32 id);

#endif
