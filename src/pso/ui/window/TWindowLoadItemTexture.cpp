#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/ItemTextureConstants.h"
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
    s32 sprite;

    window = (TWindowLoadItemTexture *)TObject::operator new(0x74);
    if (window != NULL) {
        window = (TWindowLoadItemTexture *)TWindowLoadItemTexture__ct(window, layout, table, id);
    }
    fn_80262C2C(window);
    sprite = window->get_array_entry(0);
    *(f32 *)(sprite + 0x8) = 0.5f * window->m_38 - 32.0f - 4.0f;
    *(f32 *)(sprite + 0xC) = 0.5f * *(f32 *)window->unk_3C - 32.0f - 1e+01f;
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

void get_array_entry__11TWindowBaseFi(void *, int);
extern s32 __vt__22TWindowLoadItemTexture[];
#pragma push
#pragma readonly_strings on
const char *TWindowLoadItemTexture__name = "TWindowLoadItemTexture";
#pragma pop
extern s32 tl_07;

s32 draw_visible_window_entries(void *, void *, s32);

extern const f32 lbl_8044F280[2] = { 160.0f, 120.0f };

void *TWindowLoadItemTexture::create(void *arg1) {
    void *o;
    o = TObject::operator new(0x74);
    if (o != NULL) {
        o = TWindowLoadItemTexture__ct((TWindowLoadItemTexture *)o, (void *)this, (void *)lbl_8044F280, (void *)arg1);
    }
    set_sprite_uv_bounds((void *)((TWindowLoadItemTexture *)o)->get_array_entry(0), 0.0f, 0.0f, 0.625f, 0.46875f);
    return o;
}

void render__22TWindowLoadItemTextureFv(TWindowLoadItemTexture *arg0) {
    s32 temp_r31;

    if ((s32) arg0->m_60 == 1) {
        arg0->m_70 = (u32)(*(TItemTexLoad**)((s8 *)arg0 + 0x6C))->ready_texture_list();
        if ((u32) arg0->m_70 != 0U) {
            fn_8026287C((u8 *)arg0);
            arg0->m_60 = 1U;
        }
    }
    temp_r31 = ((TWindowBase *)arg0)->setup_window_draw_context((s32)((u8 *)arg0 + 0x64));
    if (arg0->m_61 & 1) {
        ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r31);
    }
    draw_visible_window_entries(arg0, (u8 *)arg0 + 0x24, temp_r31);
}

void TWindowLoadItemTexture::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_fade(); update_window_entry_list((char*)this + 0x24); }

TWindowLoadItemTexture::~TWindowLoadItemTexture() {
    ((TObject *)(*(void **)((s8 *)this + 0x6C)))->queue_destruction();
}

void *TWindowLoadItemTexture__ct(TWindowLoadItemTexture *window_load_item_texture, void *arg1, void *arg2, void *arg3) {
    void *e;
    __ct__11TWindowBaseFPUcsPUc(window_load_item_texture, (u8 *)&TWindowLoadItemTexture__window_descriptor, (s16)((s16)(s32)arg3), (u8 *)arg1);
    *(s32 **)((s8 *)window_load_item_texture + 0x18) = __vt__22TWindowLoadItemTexture;
    *(s32 *)((s8 *)window_load_item_texture + 0) = (s32)TWindowLoadItemTexture__name;
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
    window_load_item_texture->m_38 = *(f32 *)((s8 *)arg2 + 0);
    *(f32 *)((s8 *)window_load_item_texture + 0x3C) = *(f32 *)((s8 *)arg2 + 4);
    ((TWindowBase *)window_load_item_texture)->save_position();
    e = ((void *(*)(void *, int))get_array_entry__11TWindowBaseFi)(window_load_item_texture, 0);
    *(f32 *)((s8 *)e + 0x10) = *(f32 *)((s8 *)arg2 + 0);
    *(f32 *)((s8 *)e + 0x14) = *(f32 *)((s8 *)arg2 + 4);
    window_load_item_texture->m_6c = (s32)TItemTexLoad::create((TObject*)tl_07);
    window_load_item_texture->m_61 = 0;
    window_load_item_texture->m_60 = 2;
    return window_load_item_texture;
}

void fn_80262C2C(void* p) { *(u8*)((char*)p + 0x61) |= 0x1; }

}
