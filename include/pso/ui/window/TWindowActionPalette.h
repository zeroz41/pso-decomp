#ifndef PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H
#define PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/ActionPaletteTag.h"

class WindowSpritePart;

struct TWindowActionPalette : public TWindowBase {
    TWindowActionPalette(s32 slot);
    struct ChildList {
        u32 count;
        void **entries;
    };
    struct Scale {
        f32 x;
        f32 y;
    };

    virtual void run_task();
    virtual void render();
    virtual ~TWindowActionPalette();

    ActionPaletteTag resources[3];
    u8 state;
    u8 unknown_6d[3];
    Scale scale;

    void set_bank_panel_art(unsigned short state);
    void update_slot_icon(int idx, u16 mode, u16 slot);
    void update_slot_sprites(int idx, u16 mode, u16 slot);
    void draw_frame(saddr arg1);
    int handle_input_forward();
    static s32 is_channel_active_at(saddr arg0, s32 arg1, s32 arg2);
    static void set_palette_entry(saddr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    static void set_slot_by_index(saddr arg0, s32 arg1, s32 arg2, s32 arg3);
    static void set_slot_mode(saddr arg0, s32 arg1, s32 arg2, s32 arg3);
    static void get_entry_by_index(s32 *arg0, s32 arg1);
    static u16 get_slot_type(void *effect, s32 arg1, s32 id);
    static u16 get_slot_type_for_index(s32 *effect, s32 id);
};

class TUnk_804CF9C8;

extern "C" {
void draw_action_palette_icon(WindowSpritePart *icon, u16 group, u16 index);
void update_palette_item_count_label(TUnk_804CF9C8 *label, WindowSpritePart *icon, u16 group, u16 index, s32 client_id);
void spawn_action_palette_slot_light(TWindowActionPalette *palette, s32 slot);
}
s32 get_palette_consumable_count(u16 slot, s32 client_id);

#endif
