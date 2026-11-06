#ifndef PSO_UI_CHARCREATE_TOBJCMMAINMENU_H
#define PSO_UI_CHARCREATE_TOBJCMMAINMENU_H
#include "pso/system/task/TObject.h"
#include <stddef.h>

// The id of the entry selected in the character creation main menu.
extern s32 creation_menu_selected_entry;

class TObjCMMainMenu : public TObject {
public:
    virtual ~TObjCMMainMenu();
    void update_menu_reveal();
    void sub_80297B18();
    void sub_802979BC();
    virtual void run_task();
    virtual void render();
    void handle_creation_input();
    void sub_8029862C();
    void sub_80298534();
    void sub_80298518();
    void sub_802984FC();
    void sub_802981BC();
    void sub_80297EF4();
    void* character;
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
    static u8 is_state_4();
    static u8 is_state_3();
    static void *create_fade(void *arg0, void *arg1);
    static void *create_fade_effect(void *arg0, void *arg1);
    static s32 try_pay_fee();
    void confirm_selection(void *);
    void open_name_menu(void *);
    void open_proportion_menu(void *);
    void open_auto_mk_menu(void *);
    void open_hair_menu(void *);
    void open_assign_menu(void *);
    void draw_root_menu();
    void draw_footer_divider();
    void update_submenu_fade();
    void update_slide_offset();
    static void update_random_proportion_action(void * _w0);
    void *create();
    void *destroy(s16 arg1);
    static void clear_task_state();
    static f32 get_scale();
    static f32 get_proportion();
    static void set_selection(int a0);
    static void set_speed(f32 farg0);
    static s16 get_creation_sprite_id(s32 arg0);
};
typedef char CreationMainMenuSize[sizeof(TObjCMMainMenu)==0x58?1:-1];
typedef char CreationMainMenu_character_offset[offsetof(TObjCMMainMenu,character)==0x1C?1:-1];
typedef char CreationMainMenu_mode_offset[offsetof(TObjCMMainMenu,mode)==0x20?1:-1];
typedef char CreationMainMenu_entries_offset[offsetof(TObjCMMainMenu,entries)==0x24?1:-1];
typedef char CreationMainMenu_entry_count_offset[offsetof(TObjCMMainMenu,entry_count)==0x28?1:-1];
typedef char CreationMainMenu_selected_entry_offset[offsetof(TObjCMMainMenu,selected_entry)==0x2C?1:-1];
typedef char CreationMainMenu_delay_offset[offsetof(TObjCMMainMenu,delay)==0x30?1:-1];
typedef char CreationMainMenu_reveal_ticks_offset[offsetof(TObjCMMainMenu,reveal_ticks)==0x34?1:-1];
typedef char CreationMainMenu_reveal_offset[offsetof(TObjCMMainMenu,reveal)==0x38?1:-1];
typedef char CreationMainMenu_submenu_fade_offset[offsetof(TObjCMMainMenu,submenu_fade)==0x3C?1:-1];
typedef char CreationMainMenu_slide_offset_offset[offsetof(TObjCMMainMenu,slide_offset)==0x40?1:-1];
typedef char CreationMainMenu_unknown44_offset[offsetof(TObjCMMainMenu,unknown44)==0x44?1:-1];
typedef char CreationMainMenu_progress_offset[offsetof(TObjCMMainMenu,progress)==0x48?1:-1];
typedef char CreationMainMenu_idle_ticks_offset[offsetof(TObjCMMainMenu,idle_ticks)==0x4C?1:-1];
typedef char CreationMainMenu_nodes_offset[offsetof(TObjCMMainMenu,nodes)==0x50?1:-1];
typedef char CreationMainMenu_preview_offset[offsetof(TObjCMMainMenu,preview)==0x54?1:-1];
#endif
