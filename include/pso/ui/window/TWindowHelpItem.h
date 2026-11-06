#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowHelpItem
{
    void sub_802534B0();
    void update_tech_disk_details();
    void init_text(void *);
    void sub_80255E24();
    void set_flag60_bit4();
    u32 m_00;
    u8 unk_4[0x4];
    f32 m_8;
    u8 unk_C[0x4];
    s32 m_10;
    u8 unk_14[0x4];
    void *m_vtable18;
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 unk_28[0x4];
    s32 m_2c;
    void* m_30;
    u8 unk_34[0x28];
    s32 m_5c;
    u8 m_60;
    u8 _pad61[0x3];
    u32 m_64;
    u32 m_68;
    u32 m_6c;
    u32 m_70;
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
    static void set_help_text(s32 arg0, s32 arg1);
    void update_displayed_item();
    void update_stat_disp();
    static void update_resistance_rows(void *arg0);
    void init_help_texts();
    void invoke_callback_pmf();
    void dispatch_item_help();
    void set_displayed_item_colored(u32 arg1);
    void set_displayed_item_data(void* a1, void* a2);
    void set_items_and_refresh(void* a1, void* a2);
    void update_cursor_selection();
    void update_display();
    void *dt(s16 arg1);
    void set_flag0_bit20();
    void update_visible_flags();
    static void draw_number_value(void *entry, f32 *pos, s32 value, s32 color, s32 percent);
    static void set_flag_0x10(u16 *arg0, s32 arg1);
    void set_flag8_and_field20(s32 arg1);
    void set_compare_color(s32 arg1);
    void set_flag4_and_field1c(s32 arg1);
    void set_help_text(u32 arg1);
    void reset_float_field();
    s32 is_item_already_equipped();
    void format_description_with_price();
    void refresh_copied_items();
};

typedef char TWindowHelpItem_size_check[sizeof(TWindowHelpItem) == 0xBC ? 1 : -1];
#endif
