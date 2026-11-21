#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/ItemTextureConstants.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "types.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/item/TItemTexLoad.h"
#include "pso/ui/window/TWindowSubMag_802627D8.h"
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
TWindowLoadItemTexture *fn_802628C0(void *layout, void *table, void *id) {
    TWindowLoadItemTexture *window;
    saddr sprite;

    window = new TWindowLoadItemTexture((u8 *)layout, table, (saddr)id);
    fn_80262C2C(window);
    sprite = reinterpret_cast<saddr>(window->get_array_entry(0));
    *(f32 *)(sprite + 0x8) = 0.5f * window->target_size[0] - 32.0f - 4.0f;
    *(f32 *)(sprite + 0xC) = 0.5f * window->target_size[1] - 32.0f - 1e+01f;
    *(f32 *)(sprite + 0x10) = 64.0f;
    *(f32 *)(sprite + 0x14) = 64.0f;
    set_sprite_uv_bounds((void *)sprite, 0.0f, 0.0f, 1.0f, 1.0f);
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

void *TWindowLoadItemTexture::create(void *client) {
    void *o;
    o = new TWindowLoadItemTexture((u8 *)this, (void *)lbl_8044F280, (saddr)client);
    set_sprite_uv_bounds((void *)((TWindowLoadItemTexture *)o)->get_array_entry(0), 0.0f, 0.0f, 0.625f, 0.46875f);
    return o;
}

void render__22TWindowLoadItemTextureFv(TWindowLoadItemTexture *window_base) {
    saddr temp_r31;

    if ((s32) window_base->m_60 == 1) {
        window_base->m_70 = (uaddr)(*(TItemTexLoad**)((s8 *)window_base + 0x6C))->ready_texture_list();
        if ((u32) window_base->m_70 != 0U) {
            fn_8026287C((u8 *)window_base);
            window_base->m_60 = 1U;
        }
    }
    temp_r31 = reinterpret_cast<saddr>(((TWindowBase *)window_base)->setup_window_draw_context((f32 *)((u8 *)window_base + 0x64)));
    if (window_base->m_61 & 1) {
        ((TWindowBase *)window_base)->draw_window_frame((void *)temp_r31);
    }
    draw_visible_window_entries(
        reinterpret_cast<const void *>(window_base),
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)window_base + 0x24),
        reinterpret_cast<WindowDrawContext *>(temp_r31));
}

void TWindowLoadItemTexture::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

TWindowLoadItemTexture::~TWindowLoadItemTexture() {
    ((TObject *)(*(void **)((s8 *)this + 0x6C)))->queue_destruction();
}

TWindowLoadItemTexture::TWindowLoadItemTexture(u8 *layout, void *table, s32 id) : TWindowBase((u8 *)&TWindowLoadItemTexture__window_descriptor, (s16)id, layout) {
    void *e;
    #define window_load_item_texture this
    *(s32 *)((s8 *)window_load_item_texture + 0) = (saddr)TWindowLoadItemTexture__name;
    switch (TCameraCtrl::get_camera_id()) {
    case 1:
        *(f32 *)((s8 *)window_load_item_texture + 0x68) = *(f32 *)((s8 *)window_load_item_texture + 0x64) = 1.0f;
        break;
    case 2:
        *(f32 *)((s8 *)window_load_item_texture + 0x68) = *(f32 *)((s8 *)window_load_item_texture + 0x64) = 0.5f;
        break;
    case 3:
    case 4:
        *(f32 *)((s8 *)window_load_item_texture + 0x68) = *(f32 *)((s8 *)window_load_item_texture + 0x64) = 0.37f;
        break;
    }
    window_load_item_texture->target_size[0] = *(f32 *)((s8 *)table + 0);
    *(f32 *)((s8 *)window_load_item_texture + 0x3C) = *(f32 *)((s8 *)table + 4);
    ((TWindowBase *)window_load_item_texture)->save_position();
    e = (void *)((TWindowBase *)window_load_item_texture)->get_array_entry(0);
    *(f32 *)((s8 *)e + 0x10) = *(f32 *)((s8 *)table + 0);
    *(f32 *)((s8 *)e + 0x14) = *(f32 *)((s8 *)table + 4);
    window_load_item_texture->m_6c = (saddr)TItemTexLoad::create((TObject*)tl_07);
    window_load_item_texture->m_61 = 0;
    window_load_item_texture->m_60 = 2;
    #undef window_load_item_texture
}

void fn_80262C2C(void* p) { *(u8*)((char*)p + 0x61) |= 0x1; }

}
