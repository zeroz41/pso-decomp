#ifndef PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H
#define PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H

#include "types.h"

struct TWindowHelpItem;
extern "C" void update_palette_item_count_label(TWindowHelpItem *arg0, u8 *arg1, u16 arg2, u16 arg3, s32 arg4);

struct TWindowActionPalette {
    void run_task();
    struct ChildList {
        u32 count;
        void **entries;
    };
    struct Scale {
        f32 x;
        f32 y;
    };

    void render();

    u8 unk_0[0x1];

    u8 m_1;

    u8 unk_2[0x1E];

    s16 m_20;

    u8 unk_22[0x2];
    ChildList children;
    u8 unk_2C[0x28];
    f32 m_54;
    u8 unk_58[0x4];
    s32 m_5c;
    u8 resources[3][4];
    u8 state;
    u8 unknown_6d[3];
    Scale scale;
    void set_bank_panel_art(unsigned short state);
    static void update_slot_icon(void *arg0, int idx, int mode, int slot);
    void update_slot_sprites(int idx, int mode, u16 slot);
    void draw_frame(int arg1);
    void set_slot(u8 v);
    void set_mode(u8 v);
    int handle_input_forward();
    static void is_channel_active_at(s32 arg0, s32 arg1, s32 arg2);
    static void set_palette_entry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    static void set_slot_by_index(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void set_slot_mode(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void get_entry_by_index(s32 *arg0, s32 arg1);
    static u8 *get_slot_type(s32 arg0, s32 arg1, s32 arg2);
    static void get_slot_type_for_index(s32 *arg0, s32 arg1);
};

#endif
