#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHAT_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHAT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;

struct TWindowSubSymbolChat : public TObject {
    TWindowSubSymbolChat(TObject *parent, s32 client);
    virtual ~TWindowSubSymbolChat();
    static const char *class_name;
    void sub_80281CC4();
    void sub_80281C60();
    u8 selected_value;
    u8 _pad1D[0x1];
    s16 symbol_index;
    uaddr m_20;
    u32 m_24;
    uaddr m_28;
    TWindowMainMenu *parent_menu;
    uaddr m_30;
    uaddr m_34;
    uaddr m_38;
    uaddr main_menu;
    uaddr confirm_window;
    uaddr m_44;
    uaddr face_type_window;
    uaddr parts;
    uaddr parts_set;
    uaddr m_54;
    uaddr m_58;
    uaddr m_5c;
    void clear_entries();
    void load_symbol_chat_data();
    static s32 compute_total_height();
    static s32 calc_remaining_slots();
    void*get_keyboard_ptr();
    static unsigned char get_global_4e54();
    static void send_selected_symbol_chat(s32 *arg0);
    void set_entry_name(void *entry_name);
    void set_flag_bit9(s32 arg1);
    void set_symbol_index(s32 symbol_index);
    s32 count_empty_slots();
    s32 count_used_slots();
    void remove_slot_shift_down(s32 i);
    void set_entry(s32 arg1, s32 arg2, s32 x, s32 y, s32 arg5, s32 arg6);
    void add(s32 part_id, s32 x, s32 y, s32 flags, s32 arg5);
    void set_entry_bits(s32 v, s32 a, s32 idx, s32 b, s32 c);
    void set_symbol_flags(s32 arg1, s32 arg2);
    static s32 count_instance_empty_slots();
    void update_layout();
    void update_symbol_chat_result();
    static void play_symbol_sound(s32 arg0);
    u8 *get_symbol_chat_data();
    void bswap_symbol_chat_packet();
    void byteswap_entry();
    void send_symbol_chat();
    static saddr get_instance();
    int is_initialized();
    void bswap_entry();
    static void close_child(void *window, void *frame_context);
    s32 is_card_confirmed();
    void update_sub_window();
    void update_state();
    void draw_selected_entry();
    s32 create_keyboard_control();
    s32 create_confirm_window();
    s32 open_confirm_prompt();
    s32 create_menu();
    s32 create_parts_set();
    s32 create_parts();
    static void open_menu(s32 arg0, saddr list);
    s32 open_edit_menu();
    static s32 open_main_menu(void * _w0);
    void apply_symbol();
    s32 create_symbol_list_card();
    static saddr create_chat_symbol_window(s32 arg0, s32 arg1);
    virtual void render();
    virtual void run_task();
    static void set_flag_bit2(s32 *arg0);
    static void clear_flag_bit2(s32 *arg0);
    s32 get_cursor_pos();
    s32 get_cursor_x();
    void clear_flag60_bit2();
    void clear_flag60_bit4();
    void set_pos_and_flag(s32 arg1, s32 arg2);
    static void set_flag_bit1(s32 *arg0);
    s32 commit(s32 *src);
    void set_flag60_bit1();
    void set_flag60_bit2();
    void set_selection_and_refresh(s32 arg1);
    void init_layout_entries(saddr player);
    void set_from_key(s32 arg1);
};

LAYOUT_ASSERT(TWindowSubSymbolChat_size, sizeof(TWindowSubSymbolChat) == 0x60);
#endif
