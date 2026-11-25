#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItemData.h"
#include <stddef.h>

struct PageIndicator;

// One of a weapon's three attribute slots: the area it boosts (1-5) and the
// percentage.
struct WeaponAttribute {
    u8 area;
    s8 percent;
};

struct TWindowHelpItem : public TWindowBase
{
    static void * description_text_layout[9];
    static void * resistance_layout_entries[31];
    static void * item_layout_entries[67];
    virtual ~TWindowHelpItem();
    virtual void render();
    virtual void run_task();
    void show_item_description();
    void update_tech_disk_details();
    void init_text(void *);
    void unlock_page_flip();
    void lock_page_flip();
    void disable_help_toggle();
    void enable_help_toggle();
    TItemData *get_mag_state();
    s32 update_mag_status_gauges();
    void update_help_item(s32 mode);
    // 1: an item is shown, 2: it has pages, 4: page flipping locked,
    // 8: the help button toggle is off.
    u8 help_flags;
    u8 _pad61[0x3];
    PageIndicator *page_indicator;
    TItemData *active_item;
    u32 item_data;            // shown when no displayed item is set (item_id)
    uaddr displayed_item_data;  // takes precedence; compared with the equipped one
    u8 _pad74[0x14];
    TItemData displayed_item;
    s32 shown_item_id;  // id of the item on show, -1 for none
    u32 item_id;
    u32 displayed_item_id;
    f32 scale_x;
    f32 scale_y;
    void (TWindowHelpItem::*m_callback)();  // run each frame for the page on show

    TWindowHelpItem(void *position, s32 index);
    void set_flag0_bit2();
    static void set_help_text(saddr help, saddr client_id);
    static s32 get_help_value(u16 slot, s32 client_id);
    void update_displayed_item();
    void update_stat_disp();
    void update_resistance_rows();
    // The pages dispatch_item_help shows for each item type.
    void show_weapon_requirements();
    void show_weapon_attributes();
    void show_armor_requirements();
    void show_armor_resistances();
    void show_shield_resistances();
    void show_mag_stats();
    void show_mag_growth();
    void show_mag_photon_blasts();
    void update_requirements();
    void update_level_requirement();
    void update_stat_comparison();
    void set_percentage_rows(WeaponAttribute *attributes, void (TWindowHelpItem::*set)(s32));
    void init_help_texts();
    void invoke_callback_pmf();
    void dispatch_item_help();
    void set_displayed_item_colored(uaddr displayed_item_colored);
    void set_displayed_item_by_id(saddr id);
    void set_scale(f32 x, f32 y);
    void set_displayed_item_data(void* a1, void* a2);
    void set_items_and_refresh(void* a1, void* a2);
    void update_cursor_selection();
    void set_flag0_bit20();
    void update_visible_flags();
    static void draw_number_value(void *entry, f32 *pos, s32 value, s32 color, s32 percent);
    static void set_flag_0x10(u16 *arg0, s32 arg1);
    void set_compare_value(s32 value);
    void set_compare_color(s32 count);
    void set_value(s32 value);
    void set_help_text(uaddr str);
    void reset_float_field();
    s32 is_item_already_equipped();
    void format_description_with_price();
    void refresh_copied_items();
    void update_stat_disp2();
    static void tick_display_timer(void *arg0);
    static void *destroy(void *arg0, s16 arg1);
};

LAYOUT_ASSERT(TWindowHelpItem_size_check, sizeof(TWindowHelpItem) == 0xBC);
LAYOUT_ASSERT(HelpItem_name_offset, offsetof(TWindowHelpItem, m_name) == 0);
LAYOUT_ASSERT(HelpItem_active_item_offset, offsetof(TWindowHelpItem, active_item) == 0x68);
LAYOUT_ASSERT(HelpItem_page_offset, offsetof(TWindowHelpItem, page_indicator) == 0x64);
LAYOUT_ASSERT(HelpItem_callback_offset, offsetof(TWindowHelpItem, m_callback) == 0xB0);
#endif
