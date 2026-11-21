#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

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
    void update_help_item(s32 mode);
    u8 m_60;
    u8 _pad61[0x3];
    PageIndicator *m_64;
    uaddr m_68;
    u32 m_6c;
    uaddr m_70;
    u8 _pad74[0x28];
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    f32 m_a8;
    f32 m_ac;
    struct CallbackWords { u32 words[3]; } m_callback;

    static void *operator new(unsigned long size) { return TObject::operator new(size); }
    TWindowHelpItem(void *position, u16 index);
    void set_flag0_bit2();
    static void set_help_text(saddr help, saddr arg1);
    static s32 get_help_value(u16 slot, s32 client_id);
    void update_displayed_item();
    void update_stat_disp();
    static void update_resistance_rows(void *window_base);
    void init_help_texts();
    void invoke_callback_pmf();
    void dispatch_item_help();
    void set_displayed_item_colored(uaddr arg1);
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
#endif
