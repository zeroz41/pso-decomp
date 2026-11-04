#ifndef PSO_MISC_TWINDOWMAINMENU_H
#define PSO_MISC_TWINDOWMAINMENU_H

#include "types.h"
#include "pso/TObject.h"

struct TWindowMainMenu : public TObject {
    virtual ~TWindowMainMenu();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    void handle_menu_selection();
    void create_submenu(u32);
    void destroy_submenu();
    void close_child_window();
    void sub_80263FE0();
    void update_keyboard_card_state();
    void update_selection_value();
    void add_menu_entry(s16);
    void sub_80263D7C();
    void open(s32);
    void close_and_clear_flags();
    s32 close_active_submenu();
    void set_scale_f();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x8];
    u32 m_48;
    u32 m_4c;
    u16 m_50;
    u16 m_52;
    u32 m_54;
    u8 _pad58[0x4];
    u32 m_5c;
    void update_trade_submenu();
    void update_submenu();
    void close_submenu(void* a1);
    void refresh_submenu(void* a1);
    void close();
    void render();
    void run_task();
    static void set_entry_field_20(s32 arg0, s32 arg1);
    int is_item_active();
    void set_symbol_chat_parts(void * _w1);
    void update_item_tween();
    void init_color();
    void pop_level();
    int get_selected_item_type();
    void clear_menu_flags();
    s32 find_free_slot();
    s32 update_if_active(s32 _w1);
    void set_target_y(f32 farg0);
    void update_scaled_position();
    void draw_entries_reversed(u8 *arg1);
    void update_slide_position();
    s32 is_not_split_screen();
    static void *create_menu(void *arg0, void *arg1);
    void open_menu_with_entry(s16 arg1);
    void try_open_battle_menu(s16 arg1);
    s32 filter_menu_entry(s16 *arg1, s32 *arg2);
    void update_description_text(s32 arg1);
};

extern "C" {
u8 *__dt__15TWindowMainMenuFv(u8 *arg0, s16 arg1);
}
int test_keyboard_card_flag4(void *p);

// --- C functions defined in TWindowMainMenu.cpp ---
extern "C" {
u8 *__dt__15TWindowMainMenuFv(u8 *arg0, s16 arg1);
}
// --- end of C functions

#endif
