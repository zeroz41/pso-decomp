#ifndef PSO_UI_WINDOW_TWINDOWMENUICONLINE_H
#define PSO_UI_WINDOW_TWINDOWMENUICONLINE_H
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/network/TradeItemEntry.h"

struct TItem;
struct TItemData;
struct WindowScrollBar;

class TWindowMenuIconLine : public TWindowAddition {
public:
    TWindowMenuIconLine(u8 *parent, u32 count, s16 client, u8 *descriptor);
    TWindowMenuIconLine(u8 *parent, u32 count, s16 client);
    virtual ~TWindowMenuIconLine();
    virtual void run_task();
    virtual void render();
    virtual void init(u32, s32);
    void draw_selected_list_entry(WindowDrawContext *context);
    void update_scroll_offset();
    void clamp_item_list_scroll();
    void center_list_selection();
    void ensure_status_display(s32);
    void create_menu_scroll_bar();
    void move_cursor();
    void move_cursor_next();
    void handle_open();
    void set_flag4();
    // Opening the selected entry then plays no decide sound.
    void disable_decide_sound();
    int get_flag();
    int is_decided();
    int is_cancelled();
    void clear_decided();
    void reset_list();
    void set_flag70_bit10();
    void start_scroll(f32 height);
    void add_status_entry(s8 flags, s32 src, s32 item);
    void add_list_entry(u8 icon, s32 src, s32 item);
    void add_list_entry(TItem *item, s32 index);
    void add_item(TItem *item, s32 price, s32 index);
    // Append a row for an item record kept outside the inventory (bank, shop stock); count 0 hides the stack size.
    void add_item_info_entry(TItemData *item, s32 index, s32 count);
    void add_ground_item(TItemData *item, s32 index);
    // Append a row with no item that shows message (-1 for the empty-list row).
    void add_list_entry(s32 message);
    void add_inventory_item(TItem *item, s32 count, s32 id);
    // Fill the list from the player's inventory: the 31 slots of a trade
    // offer, usable items, armor of one kind and group to equip, mags of one
    // kind, items to appraise.
    void fill_trade_item_list(TradeItemEntry *entries);
    void build_usable_item_list();
    void add_armor_equip_candidates(u16 kind, u16 sub);
    void build_mag_item_candidates(u16 kind);
    void populate_judgment_item_list();
    // The short list's pages: battle items, items for the item palette,
    // weapons the player can equip (the equipped one last).
    void build_battle_stat_list();
    void build_item_shortcut_list();
    void build_weapon_shortcut_list();
    void save_cursor_selection();
    void clamp_selection_to_valid_entry();
    // Rebuild the list keeping the cursor: usable items, items to appraise,
    // armor of one kind to equip.
    void refresh_usable_item_list();
    void refresh_judgment_item_list();
    void refresh_armor_equip_list(u16 kind, u16 sub);
    void refresh_mag_item_list(u16 kind);
    void refresh_trade_item_list(TradeItemEntry *entries);
    void refresh_battle_stat_list();
    void refresh_item_shortcut_list();
    void refresh_weapon_shortcut_list();
    saddr get_cursor_value();
    s16 get_cursor_index();
    void set_cursor_index(s16 index);
    void calc_content_extent();
    void clamp_scroll_offset();
    void disable_cancel();
    void advance_line(s32 message);
    void advance_status_disp_entry(s32 message);
    void push_status_disp_entry(s32 count, s32 id);
    // Append a row for one of the player's five battle items (stat 0-4) when
    // they hold any; gray_out greys it where items cannot be used.
    void add_battle_stat_entry(s32 stat, s32 item, s32 gray_out);
    u16 state_flags;
    s16 entry_count;
    s16 cursor;
    s16 entry_capacity;
    s16 saved_cursor;           // save_cursor_selection, before the list is rebuilt
    u8 unk_7A[0x2];
    s32 saved_cursor_value;
    void * status_display;
    WindowScrollBar *scroll_bar; // created by create_menu_scroll_bar, drawn by draw_window_scrollbar
};
LAYOUT_ASSERT(TWindowMenuIconLine_size, sizeof(TWindowMenuIconLine) == 0x88);

#endif
