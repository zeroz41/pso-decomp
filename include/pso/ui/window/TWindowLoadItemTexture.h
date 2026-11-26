#ifndef PSO_UI_WINDOW_TWINDOWLOADITEMTEXTURE_H
#define PSO_UI_WINDOW_TWINDOWLOADITEMTEXTURE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

class TItemTexLoad;
struct NJS_TEXLIST;
struct TItemData;
struct LoadItemTextureWindowLayout;

struct TWindowLoadItemTexture : public TWindowBase {
    static WindowDescriptor window_descriptor;
    static LoadItemTextureWindowLayout layout_entries;
    static const char *class_name;
    TWindowLoadItemTexture(void *position, f32 *extent, s32 client);
    virtual ~TWindowLoadItemTexture();
    virtual void render();
    virtual void run_task();
    static TWindowLoadItemTexture *create(void *position, s32 client);
    void set_mag_slot_state(TItemData *item);

    u8 load_state;
    u8 draw_flags;
    u8 _pad62[0x2];
    f32 draw_scale[2];
    TItemTexLoad *texture_loader;
    NJS_TEXLIST *texture_list;
};

LAYOUT_ASSERT(TWindowLoadItemTexture_size, sizeof(TWindowLoadItemTexture) == 0x74);
LAYOUT_ASSERT(TWindowLoadItemTexture_scale_offset, offsetof(TWindowLoadItemTexture, draw_scale) == 0x64);
LAYOUT_ASSERT(TWindowLoadItemTexture_loader_offset, offsetof(TWindowLoadItemTexture, texture_loader) == 0x6C);
LAYOUT_ASSERT(TWindowLoadItemTexture_list_offset, offsetof(TWindowLoadItemTexture, texture_list) == 0x70);

TWindowLoadItemTexture *create_load_item_texture_window(void *position, const f32 *extent, s32 client);
void bind_item_texture(TWindowLoadItemTexture *window);
extern "C" {
void fn_80262C2C(TWindowLoadItemTexture *window);
}

// TWindowLoadItemTexture::window_descriptor (passed to the TWindowBase constructor by the window's constructor) and
// TWindowLoadItemTexture::layout_entries, the layout table it points at.
struct LoadItemTextureWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
};


#endif
