#ifndef PSO_UI_CHARCREATE_TOBJCMMAINMENU_H
#define PSO_UI_CHARCREATE_TOBJCMMAINMENU_H
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include <stddef.h>

// The id of the entry selected in the character creation main menu.
extern s32 creation_menu_selected_entry;
u32 get_character_creation_selected_entry_id();

class TObjCMMainMenu;

// The action and optional assign-menu kind for one character creation choice.
struct CreationMenuEntry {
    s32 kind;
    void (TObjCMMainMenu::*select)();
};

LAYOUT_ASSERT(CreationMenuEntrySize, sizeof(CreationMenuEntry) == 0x10);
LAYOUT_ASSERT(CreationMenuEntrySelectOffset, offsetof(CreationMenuEntry, select) == 4);

class TObjCMMainMenu : public TObject {
public:
    TObjCMMainMenu(TObject *parent);
    virtual ~TObjCMMainMenu();
    void update_menu_reveal(s32 ticks);
    void draw_name_warning_and_icons();
    void draw_character_name();
    virtual void run_task();
    virtual void render();
    void handle_creation_input();
    void sub_8029862C();
    // State 2, after confirm_selection: waits for the figure, then fades out on the decide button.
    void update_confirmation();
    // State 5: counts the delay down, then moves to state 3.
    void finish_confirmation();
    // State 6: counts the delay down, then moves to state 4.
    void finish_cancel();
    void sub_802981BC();
    // Draws the class, name and section id being confirmed.
    void draw_confirmation();
    // Empty hooks at the end of the constructor, run_task and render, and after the state handler.
    void after_construct();
    void after_run_task();
    void after_render();
    void after_state_update();
    CharacterAppearanceFields *character;
    s32 mode;
    s32* entries;
    s32 entry_count;
    s32 selected_entry;
    s32 delay;
    s32 reveal_ticks;
    f32 reveal;
    f32 submenu_fade;
    f32 slide_offset;
    f32 unknown44;
    f32 progress;
    s32 idle_ticks;
    TObject* nodes;
    f32 preview;
public:
    void copy_char_name();
    static void select_char_menu();
    static s32 validate_character_name(s8 *arg0);
    static s32 get_current_char_flag();
    s32 is_state_4();
    s32 is_state_3();
    static void *create_fade(void *arg0, void *arg1);
    static void *create_fade_effect(void *arg0, void *arg1);
    static s32 try_pay_fee();
    void confirm_selection();
    void open_name_menu();
    void open_proportion_menu();
    void open_auto_mk_menu();
    void open_hair_menu();
    void open_assign_menu();
    void draw_root_menu();
    void draw_footer_divider();
    void update_submenu_fade();
    void update_slide_offset();
    static void update_random_proportion_action(void * _w0);
    static TObjCMMainMenu *create(TObject *parent);
    static void clear_task_state();
    static f32 get_scale();
    static f32 get_proportion();
    static void set_selection(int selection);
    static void set_speed(f32 farg0);
    static s32 get_creation_sprite_id(s32 sprite_id);
    static s32 is_not_dressing_room_mode();
    // Turns the creation figure by delta.
    static void rotate_figure(s32 delta);
    static s32 *get_name_buffer();

    static const char *class_name;
    // Which run_task handler runs: 0 is the root menu, 1 a submenu, 2 the confirmation (is_state_3/4
    // read 3 and 4).
    static s32 state;
    // What each main menu entry opens.
    static CreationMenuEntry menu_entries[10];
};
LAYOUT_ASSERT(CreationMainMenuSize, sizeof(TObjCMMainMenu)==0x58);
LAYOUT_ASSERT(CreationMainMenu_character_offset, offsetof(TObjCMMainMenu,character)==0x1C);
LAYOUT_ASSERT(CreationMainMenu_mode_offset, offsetof(TObjCMMainMenu,mode)==0x20);
LAYOUT_ASSERT(CreationMainMenu_entries_offset, offsetof(TObjCMMainMenu,entries)==0x24);
LAYOUT_ASSERT(CreationMainMenu_entry_count_offset, offsetof(TObjCMMainMenu,entry_count)==0x28);
LAYOUT_ASSERT(CreationMainMenu_selected_entry_offset, offsetof(TObjCMMainMenu,selected_entry)==0x2C);
LAYOUT_ASSERT(CreationMainMenu_delay_offset, offsetof(TObjCMMainMenu,delay)==0x30);
LAYOUT_ASSERT(CreationMainMenu_reveal_ticks_offset, offsetof(TObjCMMainMenu,reveal_ticks)==0x34);
LAYOUT_ASSERT(CreationMainMenu_reveal_offset, offsetof(TObjCMMainMenu,reveal)==0x38);
LAYOUT_ASSERT(CreationMainMenu_submenu_fade_offset, offsetof(TObjCMMainMenu,submenu_fade)==0x3C);
LAYOUT_ASSERT(CreationMainMenu_slide_offset_offset, offsetof(TObjCMMainMenu,slide_offset)==0x40);
LAYOUT_ASSERT(CreationMainMenu_unknown44_offset, offsetof(TObjCMMainMenu,unknown44)==0x44);
LAYOUT_ASSERT(CreationMainMenu_progress_offset, offsetof(TObjCMMainMenu,progress)==0x48);
LAYOUT_ASSERT(CreationMainMenu_idle_ticks_offset, offsetof(TObjCMMainMenu,idle_ticks)==0x4C);
LAYOUT_ASSERT(CreationMainMenu_nodes_offset, offsetof(TObjCMMainMenu,nodes)==0x50);
LAYOUT_ASSERT(CreationMainMenu_preview_offset, offsetof(TObjCMMainMenu,preview)==0x54);

#endif
