#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ChoiceSearchSelection.h"

struct GuildCardEntry;
struct GuildCardSlot;
struct TRecvChoiceSearchOptions;
struct ChoiceSearchResultList;
struct NJS_POINT2;
struct TWindowComCard;
struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowMessage;
struct TWindowSubComCardList;
struct TWindowChoiceSetting;
struct TWindowUserSort;
struct TWindowMessageYesNo;
struct TKeyBoardControl;

struct TWindowSubComCard : public TObject {
    static void update_display_value(TWindowMenu *list_window, TWindowComCard *card_window, s32 *last_selected);
    static void update_selection(TWindowMenu *list_window, TWindowComCard *card_window, s32 *last_selected, s32 cards);
    static void update_selection(TWindowMenu *list_window, TWindowComCard *card_window, s32 *last_selected);
    static GuildCardSlot *get_card_entry(s32 index);
    static char *get_card_note_text(s32 index);
    TWindowSubComCard(TObject *parent, s32 client);
    virtual ~TWindowSubComCard();
    void rebuild_com_card_list(TWindowMenu *list_window);
    static const char *class_name;
    TWindowChoiceSetting *create_choice_search_window();
    // Stores the option `val` picked for the category `key` (0 is the com param) and updates the menus.
    void set_choice_search_option(ChoiceSearchSelection *selections, s32 key, saddr val);
    s32 reinit(int);
    s32 init_guild_card_tag(int);
    TWindowMessageYesNo *sub_802730E0();
    TWindowMenu *create_option_list_window(ChoiceSearchSelection *selections, s32 key);
    void send_short_mail();
    // Text of the option `selections[index]` picks, or NULL.
    char *find_option_text(ChoiceSearchSelection *selections, s32 index);
    void send_state_if_dirty();
    void send_choice_search(ChoiceSearchSelection *selections);
    void handle_close_flag();
    virtual void render();
    virtual void run_task();
    u8 state;
    u8 dirty_flags;
    u8 _pad1E[0x2];
    uaddr client_id;
    uaddr selected_card;
    uaddr shown_card_index;
    uaddr idle_time;
    ChoiceSearchSelection choice_selections[5];
    // The options the server offered, taken from get_choice_search_options once they arrive.
    TRecvChoiceSearchOptions *search_options;
    TWindowMainMenu *parent_menu;
    TWindowMenu *menu_window;
    // Menu the current state waits on (option lists, menus, player select).
    TWindowMenu *com_card_menu;
    // Card list or card action menu.
    TWindowMenu *sub_menu;
    TWindowMessage *message_window;
    TWindowMessageYesNo *confirm_window;
    TWindowComCard *com_card_window;
    TWindowUserSort *user_sort_window;
    TWindowChoiceSetting *entry_list_window;
    TKeyBoardControl *keyboard;
    TWindowSubComCardList *card_list;
    static saddr get_card_slot(s32 slot);
    static TWindowComCard *send_command(s32 index);
    static TWindowComCard *apply_selection(s32 index);
    static ChoiceSearchResultList *get_choice_search_results();
    static void release();
    static TRecvChoiceSearchOptions *get_choice_search_options();
    void clear_and_init(void* local_client_id);
    s32 get_card_id();
    int is_active();
    static int get_keyboard_mode();
    TKeyBoardControl *create_keyboard();
    TKeyBoardControl *create_keyboard(s32 card_index);
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
    static TWindowSubComCardList *create_card_list(const NJS_POINT2 *position, s32 card_slot, s32 count, s32 empty_message);
    // Opens the list over every stored guild card (create_card_list's all-cards form).
    static TWindowSubComCardList *sub_802754EC(const NJS_POINT2 *position);
    void set_card_text(saddr src);
    static GuildCardSlot *find_card_by_id(u32 id);
    static void swap_cards(s32 first_index, s32 second_index);
    static s32 init_com_card();
    static void remove_card_at(s32 i);
    s32 send_guild_card();
    static void start_player_data_load(s32 ply_guild_card_tag);
    static s32 count_active_cards();
    static s32 count_leading_active(GuildCardEntry *cards, s32 count);
    void set_text(void *text);
    static void handle_press_a(saddr ply_guild_card_tag, s32 id);
    static void handle_press_b(saddr ply_guild_card_tag, s32 client_id);

    void set_card_index(s32 card_index);
    void set_selected_card(s32 card_index);
    void set_help_message(s32 help_index);
    static TWindowMenu *create_card_action_window();
    TWindowMenu *sub_80272640();
    TWindowMenu *sub_802728CC();
    TWindowMenu *sub_80272A98();
    TWindowMenu *sub_80273004();
    static TWindowMenu *sub_8027337C();
    TWindowMenu *sub_8027346C();
    TWindowMenu *sub_8027353C();
    TWindowChoiceSetting *create_entry_list_window();
    TWindowMessageYesNo *open_yesno_dialog();
    TWindowMessageYesNo *confirm_and_free();
    static void set_com_param(saddr client_id, s32 com_param);
    void set_page(s16 v);
    void set_display_page();
    static TWindowComCard *create_com_card_window(const NJS_POINT2 *position);
    TWindowMenu *create_menu();
    TWindowMenu *create_single_entry_window();
    TWindowMenu *open_menu();
    TWindowMessage *open_layout_window();
    TWindowMessage *open_mode4_window();
    TWindowMenu *create_menu_window();
    TWindowMenu *create_player_select_window();
    TWindowMessage *create();
    static void cleanup(void* p);
    static TWindowSubComCardList *send_cmd_133();
    static TWindowSubComCardList *init_layout();
    void *get_message_10(s32 index);
};

LAYOUT_ASSERT(TWindowSubComCard_size, sizeof(TWindowSubComCard) == 0x88);
struct TWindowMenu;
extern "C" void add_gray_text_entry(TWindowMenu *list, const char *text, s32 kind, s32 id);

#endif
