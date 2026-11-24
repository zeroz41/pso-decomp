#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItemData.h"
#include <stddef.h>

struct PageIndicator;

struct TWindowHelpItem : public TWindowBase
{
    virtual ~TWindowHelpItem();
    virtual void render();
    virtual void run_task();
    void sub_802534B0();
    void update_tech_disk_details();
    void init_text(void *);
    void sub_80255E24();
    void set_flag60_bit4();
    void set_flag60_bit8();
    void clear_flag60_bit8();
    TItemData *get_mag_state();
    s32 update_mag_status_gauges();
    void update_help_item(s32 mode);
    u8 m_60;
    u8 _pad61[0x3];
    PageIndicator *m_64;
    TItemData *active_item;
    u32 m_6c;
    uaddr m_70;
    u8 _pad74[0x14];
    TItemData displayed_item;
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    f32 scale_x;
    f32 scale_y;
    struct CallbackWords { u32 words[3]; } m_callback;

    TWindowHelpItem(void *position, s32 index);
    void set_flag0_bit2();
    static void set_help_text(saddr help, saddr client_id);
    static s32 get_help_value(u16 slot, s32 client_id);
    void update_displayed_item();
    void update_stat_disp();
    static void update_resistance_rows(void *window_base);
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
    void set_flag8_and_field20(s32 arg1);
    void set_compare_color(s32 count);
    void set_flag4_and_field1c(s32 count);
    void set_help_text(uaddr str);
    void reset_float_field();
    s32 is_item_already_equipped();
    void format_description_with_price();
    void refresh_copied_items();
    static void update_stat_disp2(void *window_base);
    static void tick_display_timer(void *arg0);
    static void *destroy(void *arg0, s16 arg1);
};

LAYOUT_ASSERT(TWindowHelpItem_size_check, sizeof(TWindowHelpItem) == 0xBC);
LAYOUT_ASSERT(HelpItem_name_offset, offsetof(TWindowHelpItem, m_name) == 0);
LAYOUT_ASSERT(HelpItem_active_item_offset, offsetof(TWindowHelpItem, active_item) == 0x68);
LAYOUT_ASSERT(HelpItem_page_offset, offsetof(TWindowHelpItem, m_64) == 0x64);
LAYOUT_ASSERT(HelpItem_callback_offset, offsetof(TWindowHelpItem, m_callback) == 0xB0);
LAYOUT_ASSERT(HelpItem_callback_size, sizeof(TWindowHelpItem::CallbackWords) == 12);
#endif
