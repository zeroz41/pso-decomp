#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_H

#include "types.h"
struct NJS_POINT2;
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItemData.h"
#include "pso/item/WeaponAttribute.h"
#include "pso/unk/WindowLayoutRecord.h"
#include <stddef.h>

struct PageIndicator;
class HelpItemStatCompareRow;

// One of a weapon's three attribute slots: the area it boosts (1-5) and the
// percentage.

// Layout tables of the help item window (cols, rows, then the records read by
// init_window_layout_entries).

// item_layout_entries: six type-11 points, the item icon sprite and a row of text and value entries.
struct HelpItemLayout {
    u32 cols;
    u32 rows;
    PointLayoutRecord lines[6];
    SpritePartLayoutRecord icon;
    TextLayoutRecord rec_7;
    ValueLayoutRecord rec_8;
    TextLayoutRecord rec_9;
    ValueLayoutRecord rec_10;
    TextLayoutRecord rec_11;
};

struct HelpItemLinesLayout {
    u32 cols;
    u32 rows;
    PointLayoutRecord lines[5];
};

struct HelpItemResistanceLayout {
    u32 cols;
    u32 rows;
    PointLayoutRecord lines[5];
    TextLayoutRecord rec_5;
    ValueLayoutRecord rec_6;
};

// One stat row: its name, its value and its gauge.
struct HelpItemStatRowLayout {
    TextLayoutRecord name;
    ValueLayoutRecord value;
    LayoutEntryCopyRecord gauge;
};

struct HelpItemStatsLayout {
    u32 cols;
    u32 rows;
    PointLayoutRecord lines[3];
    HelpItemStatRowLayout stats[4];
    TextLayoutRecord level_up;
};

struct HelpItemSpritesLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord sprites[4];
};

struct HelpItemTextLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord text;
    PointLayoutRecord rec_1;
};

struct HelpItemTechDiskLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord text;
    SpritePartLayoutRecord icon;
    TextLayoutRecord rec_2;
    ValueLayoutRecord rec_3;
    TextLayoutRecord rec_4;
    ValueLayoutRecord rec_5;
    TextLayoutRecord rec_6;
};

struct HelpItemDescriptionLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord text;
};

// The attribute area names show_weapon_attributes labels the first four rows with
// ("Hit" is the fifth).
extern const char native_attribute_label[];
extern const char abeast_attribute_label[];
extern const char machine_attribute_label[];
extern const char dark_attribute_label[];

const char *get_help_text_string(s32 id);

struct TWindowHelpItem : public TWindowBase
{
    static const char *class_name;
    static HelpItemDescriptionLayout description_text_layout;
    static HelpItemResistanceLayout resistance_layout_entries;
    static HelpItemLayout item_layout_entries;
    virtual ~TWindowHelpItem();
    virtual void render();
    virtual void run_task();
    void show_item_description();
    void show_item_by_id(saddr id);
    void update_tech_disk_details();
    void update_tech_disk_stats();
    void idle_update();
    void init_text(const char *);
    void unlock_page_flip();
    void lock_page_flip();
    void disable_help_toggle();
    void enable_help_toggle();
    TItemData *get_mag_state();
    s32 update_mag_status_gauges();
    s32 are_status_entries_ready();
    s32 advance_mag_levels();
    void update_help_item(s8 page);
    // Drops the shown item and forgets every item id.
    void clear_help_item();
    // 1: an item is shown, 2: it has pages, 4: page flipping locked,
    // 8: the help button toggle is off.
    u8 help_flags;
    u8 _pad61[0x3];
    PageIndicator *page_indicator;
    TItemData *active_item;
    TItemData *secondary_item; // shown when no primary item is set (secondary_id)
    TItemData *primary_item;   // takes precedence; compared with the equipped one
    TItemData item_copy;      // copy of the item secondary_id names
    TItemData displayed_item;
    s32 active_id;  // id of the item on show, -1 for none
    s32 secondary_id;
    s32 primary_id;
    f32 scale_x;
    f32 scale_y;
    void (TWindowHelpItem::*m_callback)();  // run each frame for the page on show

    TWindowHelpItem(const NJS_POINT2 *position, s32 index);
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
    void set_percentage_rows(WeaponAttribute *attributes, void (HelpItemStatCompareRow::*set)(s32));
    void init_help_texts();
    void invoke_callback_pmf();
    void dispatch_item_help();
    void set_displayed_item_colored(TItemData *item);
    void set_displayed_item_by_id(saddr id);
    void set_scale(f32 x, f32 y);
    void set_displayed_item_data(TItemData *item, s32 id);
    void set_items_and_refresh(TItemData *item, s32 id);
    void update_cursor_selection();
    void update_visible_flags();
    static void draw_number_value(void *entry, f32 *pos, s32 value, s32 color, s32 percent);
    void set_compare_color(s32 count);
    void set_help_text(uaddr str);
    s32 is_item_already_equipped();
    void format_description_with_price();
    void refresh_copied_items();
    void update_stat_disp2();
};

LAYOUT_ASSERT(TWindowHelpItem_size_check, sizeof(TWindowHelpItem) == 0xBC);
LAYOUT_ASSERT(HelpItem_name_offset, offsetof(TWindowHelpItem, m_name) == 0);
LAYOUT_ASSERT(HelpItem_active_item_offset, offsetof(TWindowHelpItem, active_item) == 0x68);
LAYOUT_ASSERT(HelpItem_page_offset, offsetof(TWindowHelpItem, page_indicator) == 0x64);
LAYOUT_ASSERT(HelpItem_callback_offset, offsetof(TWindowHelpItem, m_callback) == 0xB0);
#endif
