#ifndef PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H
#define PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

// A sprite part of a window (layout record type 6): position, texture rectangle, colour.
struct Icon_80243630 {
    u8 pad0[0x8];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    u8 pad18[0x1C - 0x18];
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    s32 color;
    u8 pad30[0x34 - 0x30];
    s32 kind;
};

struct TWindowActionPalette : public TWindowBase {
    struct ChildList {
        u32 count;
        void **entries;
    };
    struct Scale {
        f32 x;
        f32 y;
    };

    // run_task comes first: it is the key function that emits the vtable in
    // TWindowActionPalette.cpp, whose destructor is still the hand-made one (its
    // base and member-array destructors carry no real names yet).
    virtual void run_task();
    virtual void render();
    virtual ~TWindowActionPalette();

    u8 pad_1C[0x4];
    s16 m_20;
    u8 pad_22[0x2];
    ChildList children;
    u8 unk_2C[0x14];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    u8 unk_50[0x4];
    f32 m_54;
    f32 m_58;
    s32 m_5c;
    u8 resources[3][4];
    u8 state;
    u8 unknown_6d[3];
    Scale scale;

    void set_bank_panel_art(unsigned short state);
    void update_slot_icon(int idx, u16 mode, u16 slot);
    void update_slot_sprites(int idx, u16 mode, u16 slot);
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

struct TWindowHelpItem;

extern "C" {
void draw_action_palette_icon(Icon_80243630 *icon, u16 group, u16 index);
void update_palette_item_count_label(TWindowHelpItem *label, Icon_80243630 *icon, u16 group, u16 index, s32 client_id);
void spawn_action_palette_slot_light(TWindowActionPalette *palette, s32 slot);
// The constructor; a placeholder until TWindowBase's constructor carries its real name.
TWindowActionPalette *TWindowActionPalette__ct(TWindowActionPalette *self, s16 slot);
}
s32 get_palette_consumable_count(u16 slot, s32 client_id);
s32 get_help_value(u16 slot, s32 client_id);

#endif
