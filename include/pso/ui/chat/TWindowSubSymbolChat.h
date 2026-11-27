#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHAT_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHAT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
class TWindowCheckBox;
struct SymbolChatPreset;
struct TWindowChatSymbol;
struct TWindowMenu;
struct TWindowMessageYesNo;
class TKeyBoardControl;
struct TWindowSubSymbolChatFaceType;
struct TWindowSubSymbolChatParts;
struct TWindowSubSymbolChatPartsSet;
struct TWindowSubSymbolChatHelp;

struct TWindowSubSymbolChat : public TObject {
    static void * instance;
    TWindowSubSymbolChat(TObject *parent, s32 client);
    virtual ~TWindowSubSymbolChat();
    static const char *class_name;
    void add_part_at_cursor();
    void set_face_part_from_cursor();
    u8 selected_value;
    u8 _pad1D[0x1];
    s16 symbol_index;
    uaddr selected_list_index;
    u32 client_id;
    SymbolChatPreset *selected_preset;
    TWindowMainMenu *parent_menu;
    TWindowChatSymbol *symbol_window;
    TWindowChatSymbol *second_symbol_window;
    TWindowMenu *symbol_list;
    TWindowMenu *main_menu;
    TWindowMessageYesNo *confirm_window;
    TWindowCheckBox *option_window;
    TWindowSubSymbolChatFaceType *face_type_window;
    TWindowSubSymbolChatParts *parts;
    TWindowSubSymbolChatPartsSet *parts_set;
    TWindowSubSymbolChatHelp *help_window;
    TKeyBoardControl *keyboard;
    uaddr close_callback;
    static s32 compute_total_height();
    static s32 calc_remaining_slots();
    static unsigned char get_global_4e54();
    static s32 count_instance_empty_slots();
    static s32 update_layout();
    static void update_symbol_chat_result(s32 index);
    static void play_symbol_sound(s32 sound_index);
    u8 *get_symbol_chat_data();
    static saddr get_instance();
    int is_initialized();
    static void close_child(void *window, void *frame_context);
    s32 is_card_confirmed();
    void update_sub_window();
    void update_state();
    void draw_selected_entry();
    TKeyBoardControl *create_keyboard_control();
    TWindowCheckBox *create_confirm_window();
    TWindowMessageYesNo *open_confirm_prompt();
    TWindowMenu *create_menu();
    static TWindowMenu *create_menu(TWindowSubSymbolChat *chat);
    TWindowSubSymbolChatPartsSet *create_parts_set();
    TWindowSubSymbolChatParts *create_parts();
    void open_menu(TWindowMenu *menu);
    TWindowMenu *open_edit_menu();
    TWindowMenu *open_main_menu();
    void apply_symbol();
    TWindowMenu *create_symbol_list_card();
    TWindowChatSymbol *create_chat_symbol_window(s32 index);
    virtual void render();
    virtual void run_task();
    static void set_flag_bit2(s32 *arg0);
    static void clear_flag_bit2(s32 *arg0);
    s32 get_cursor_pos();
    s32 get_cursor_x();
    void clear_flag60_bit2();
    void clear_flag60_bit4();
    void set_pos_and_flag(s32 arg1, s32 arg2);
    static void set_flag_bit1(s32 *flags);
    s32 commit(s32 *src);
    void set_flag60_bit1();
    void set_flag60_bit2();
    void set_selection_and_refresh(s32 selection);
    void init_layout_entries(saddr player);
    void set_from_key(s32 arg1);
    // The "New Parts" menu.
    TWindowMenu *create_new_parts_menu();
};

LAYOUT_ASSERT(TWindowSubSymbolChat_size, sizeof(TWindowSubSymbolChat) == 0x60);

SymbolChatPreset *get_symbol_chat_receive_buffer(void);
void send_selected_symbol_chat(s32 *preset_index);

// 0x58-byte record held in symbol_chat_receive_buffer; its compiler-generated operator=
// copies the char array at +4 with __copy and the word array at +0x1C as a block.
struct SymbolChatPresetCopy { s32 value; u8 pad_4[0x17]; u32 pad_1C[0xF]; };

#endif
