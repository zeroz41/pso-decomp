#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/ItemTextureConstants.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "types.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/item/TItemTexLoad.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"

#include "pso/unk/WindowLayoutRecord.h"

#pragma push
#pragma opt_common_subs off

extern "C" {

#pragma push
#pragma fp_contract on
TWindowLoadItemTexture *fn_802628C0(void *position, const f32 *extent, s32 client) {
    TWindowLoadItemTexture *window;
    WindowSpritePart *sprite;

    window = new TWindowLoadItemTexture(position, (f32 *)extent, client);
    fn_80262C2C(window);
    sprite = static_cast<WindowSpritePart *>(window->get_array_entry(0));
    sprite->x = 0.5f * window->target_size[0] - 32.0f - 4.0f;
    sprite->y = 0.5f * window->target_size[1] - 32.0f - 1e+01f;
    sprite->w = 64.0f;
    sprite->h = 64.0f;
    set_sprite_uv_bounds(sprite, 0.0f, 0.0f, 1.0f, 1.0f);
    return window;
}
#pragma pop
}

#pragma pop

// inferred: TWindowLoadItemTexture__window_descriptor (passed to the TWindowBase constructor by the window's constructor) and
// TWindowLoadItemTexture__layout_entries, the layout table it points at.
struct LoadItemTextureWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
};

LoadItemTextureWindowLayout TWindowLoadItemTexture__layout_entries = {
    1, 1,
    {6, {-4.0f, -10.0f}, {0.0f, 0.0f}, 0.0f, 0.0f, 0.5f, -1, NULL, 0, 6},
};

WindowDescriptor TWindowLoadItemTexture__window_descriptor = {
    {0.0f, 0.0f}, 38000.0f, &TWindowLoadItemTexture__layout_entries, 0x2B,
};

extern "C" {

#pragma push
#pragma readonly_strings on
const char *TWindowLoadItemTexture__name = "TWindowLoadItemTexture";
#pragma pop
extern saddr tl_07;


extern const f32 lbl_8044F280[2] = { 160.0f, 120.0f };

TWindowLoadItemTexture *TWindowLoadItemTexture::create(void *position, s32 client) {
    TWindowLoadItemTexture *window = new TWindowLoadItemTexture(position, (f32 *)lbl_8044F280, client);
    set_sprite_uv_bounds(reinterpret_cast<WindowSpritePart *>(window->get_array_entry(0)), 0.0f, 0.0f, 0.625f, 0.46875f);
    return window;
}

void TWindowLoadItemTexture::render() {
    if ((s32)m_60 == 1) {
        texture_list = texture_loader->ready_texture_list();
        if (texture_list != NULL) {
            fn_8026287C(this);
            m_60 = 1;
        }
    }
    WindowDrawContext *context = setup_window_draw_context(draw_scale);
    if (m_61 & 1) {
        draw_window_frame(context);
    }
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowLoadItemTexture::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(&entry_list);
}

TWindowLoadItemTexture::~TWindowLoadItemTexture() {
    texture_loader->queue_destruction();
}

TWindowLoadItemTexture::TWindowLoadItemTexture(void *position, f32 *extent, s32 client)
    : TWindowBase((u8 *)&TWindowLoadItemTexture__window_descriptor, (s16)client, (u8 *)position) {
    m_name = TWindowLoadItemTexture__name;
    switch (TCameraCtrl::get_camera_id()) {
    case 1:
        draw_scale[1] = draw_scale[0] = 1.0f;
        break;
    case 2:
        draw_scale[1] = draw_scale[0] = 0.5f;
        break;
    case 3:
    case 4:
        draw_scale[1] = draw_scale[0] = 0.37f;
        break;
    }
    target_size[0] = extent[0];
    target_size[1] = extent[1];
    save_position();
    WindowSpritePart *entry = static_cast<WindowSpritePart *>(get_array_entry(0));
    entry->w = extent[0];
    entry->h = extent[1];
    texture_loader = TItemTexLoad::create((TObject *)tl_07);
    m_61 = 0;
    m_60 = 2;
}

void fn_80262C2C(TWindowLoadItemTexture *window) { window->m_61 |= 1; }

}
