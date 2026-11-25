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
};

class TWindowLayoutNumber;

extern "C" {
void draw_action_palette_icon(WindowSpritePart *icon, u16 group, u16 index);
void update_palette_item_count_label(TWindowLayoutNumber *label, WindowSpritePart *icon, u16 group, u16 index, s32 client_id);
void spawn_action_palette_slot_light(TWindowActionPalette *palette, s32 slot);
}
s32 get_palette_consumable_count(u16 slot, s32 client_id);

#endif
