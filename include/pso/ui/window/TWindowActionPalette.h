#ifndef PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H
#define PSO_UI_WINDOW_TWINDOWACTIONPALETTE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/ActionPaletteTag.h"
#include "pso/unk/WindowLayoutRecord.h"

class WindowSpritePart;

struct TWindowActionPalette : public TWindowBase {
    static const char *class_name;
    static const f32 bank_panel_uv_origins[4][2];
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
    u8 pad_6d[3];
    Scale scale;

    void set_bank_panel_art(unsigned short state);
    void update_slot_icon(int idx, u16 mode, u16 slot);
    void update_slot_sprites(int idx, u16 mode, u16 slot);
    void draw_frame(WindowDrawContext *ctx);
};

class TWindowLayoutNumber;

// An action a palette slot can hold: its mode (draw_action_palette_icon's group: 2 attacks, 3
// techniques, 4 items, 8 ends a custom-select table) and its slot within that mode.
struct PaletteAction {
    u16 mode;
    u16 slot;
};

void draw_action_palette_icon(WindowSpritePart *icon, u16 group, u16 index);
void update_palette_item_count_label(TWindowLayoutNumber *label, WindowSpritePart *icon, u16 group, u16 index, s32 client_id);
void spawn_action_palette_slot_light(TWindowActionPalette *palette, s32 slot);
s32 get_palette_consumable_count(u16 slot, s32 client_id);

struct PaletteItemKind { u8 group; u8 index; };

struct PaletteIconUV { f32 u; f32 v; };

struct ActionPaletteWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    SpritePartLayoutRecord rec_2;
    ValueLayoutRecord rec_3;
    SpritePartLayoutRecord rec_4;
    ValueLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    ValueLayoutRecord rec_7;
};


s32 get_palette_item_amount(u16 slot, s32 client_id);

void set_help_icon_uv(WindowSpritePart *help, s32 client_id);

#endif
