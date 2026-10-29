#include "types.h"
#include "pso/misc/TUnk_804F0EA8.h"
#include "pso/misc/TLobby_80351E64.h"
#include "pso/object/TObject_80019A50.h"

#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80351FDC_lbl_804F0EA8 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80351FDC_lbl_804F0EA8_size[sizeof(RecoveredGlobal_80351FDC_lbl_804F0EA8) == 0x18 ? 1 : -1];

struct L_80351EAC { u8 pad[0x1C]; u32 flags; s32 mode; };

extern "C" {
extern const s32 __vt__13TUnk_804F0EA8[];
extern void *lobby_event_theme_controller;
s32 release_texture_list(void*);
extern int lobby_main_texture_gvm;
u8 *load_gvm_texture_file(s32 arg0);
    extern unsigned char lbl_80478E20[];
void __ct__7TObjectFP7TObject(void *, void *);
extern u8 *tl_00;
void TLobby__sub_80351DF8(void *, s32);
void *__nw__7TObjectFUl(int);

s32 TLobby::is_connected() {
    if ((void *) lobby_event_theme_controller != NULL) {
        return ((u32) *(u32 *)((s8 *)lobby_event_theme_controller + 0x1C) >> 2U) & 1;
    }
    return 0;
}

s32 TLobby::is_lobby_obj_active() {
    if ((void *) lobby_event_theme_controller != NULL) {
        return ((u32) *(u32 *)((s8 *)lobby_event_theme_controller + 0x1C) >> 1U) & 1;
    }
    return 0;
}

int TLobby::get_lobby_texlist() {  return lobby_main_texture_gvm; }

void TUnk_804F0EA8::run_task() {
    L_80351EAC *arg0 = (L_80351EAC *)this;
    s32 mode = TLobby::get_filtered_event_theme();
    arg0->flags &= ~7;
    if (arg0->mode != mode) {
        arg0->flags |= 1;
        if (arg0->mode == 0) {
            arg0->flags |= 2;
        } else if (mode == 0) {
            arg0->flags |= 4;
        }
        arg0->mode = mode;
    }
    TLobby__sub_80351DF8(arg0, mode);
}

void TLobby__sub_80351F3C(void) {
    void *o;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = TLobby__sub_80351FDC((u8 *)o);
    }
    lobby_event_theme_controller = o;
}
}
TUnk_804F0EA8::~TUnk_804F0EA8() {
    queue_destruction__7TObjectFv(this);
    (*(s32 *)&lobby_event_theme_controller) = 0;
}


u8 *TLobby__sub_80351FDC(u8 *arg0) {
    __ct__7TObjectFP7TObject(arg0, tl_00);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80351FDC_lbl_804F0EA8 *)&__vt__13TUnk_804F0EA8).value;
    ((TUnk_804F0EA8 *)arg0)->m_20 = TLobby::get_filtered_event_theme();
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    return arg0;
}

void TLobby__sub_8035202C(void) {
    if ((u32) (*(u32 *)&lobby_main_texture_gvm) != 0U) {
        release_texture_list((void*)(*(u32 *)&lobby_main_texture_gvm));
        TAdSinglePlyChrSelectGC::safe_free((*(u32 *)&lobby_main_texture_gvm));
        (*(u32 *)&lobby_main_texture_gvm) = 0U;
    }
}
void load_obj_lobby_main(void) { lobby_main_texture_gvm = (int)load_gvm_texture_file((s32)lbl_80478E20); }
s32 get_theme_lobby_type(void) {
    s32 r = TLobby::get_filtered_event_theme();
    switch (r) {
    case 12:
        r = 0;
        break;
    case 13:
        r = 8;
        break;
    }
    return r;
}
