#include "pso/ui/ItemTextureConstants.h"
#include "types.h"
#include "pso/misc/TWindowLoadItemTexture.h"
#include "pso/misc/TWindowSubStatusDisp_8025B050.h"
#include "pso/item/TItemTexLoad.h"
#include "pso/misc/TWindowSubMag_802627D8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDD.h"

#pragma push
#pragma opt_common_subs off

extern "C" {
void *__nw__7TObjectFUl(int);

#pragma push
#pragma fp_contract on
TWindowLoadItemTexture *fn_802628C0(void *layout, void *table, void *id) {
    TWindowLoadItemTexture *window;
    s32 sprite;

    window = (TWindowLoadItemTexture *)__nw__7TObjectFUl(0x74);
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

extern "C" {

void get_array_entry__11TWindowBaseFi(void *, int);
extern s32 lbl_804D0058[];
extern s32 __vt__22TWindowLoadItemTexture[];
extern s32 lbl_805D3940;
extern s32 tl_07;

s32 draw_visible_window_entries(void *, void *, s32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

int initialize_subwindow__9TWindowDDFv(void*);

extern s32 lbl_8044F280[];

void *TWindowLoadItemTexture::create(void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x74);
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

void TWindowLoadItemTexture::run_task() { initialize_subwindow__9TWindowDDFv(this); update_fade(); update_window_entry_list((char*)this + 0x24); }

void *__dt__22TWindowLoadItemTextureFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TWindowLoadItemTexture;
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x6C));
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TWindowLoadItemTexture__ct(TWindowLoadItemTexture *window_load_item_texture, void *arg1, void *arg2, void *arg3) {
    void *e;
    ((TWindowDD *)window_load_item_texture)->construct_base((u8 *)lbl_804D0058, (s16)((s16)(s32)arg3), (u8 *)arg1);
    *(s32 **)((s8 *)window_load_item_texture + 0x18) = __vt__22TWindowLoadItemTexture;
    *(s32 *)((s8 *)window_load_item_texture + 0) = lbl_805D3940;
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
