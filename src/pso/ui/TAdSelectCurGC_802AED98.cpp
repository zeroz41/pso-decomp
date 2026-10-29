#ifndef PSO_TADSELECTCURGC_H
#define PSO_TADSELECTCURGC_H
#include "pso/TObject.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/TAdSelectCurGC_802AED98.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "types.h"
class TAdSelectCurGC : public TObject {
public:
    virtual ~TAdSelectCurGC();
    virtual void run_task();
    virtual void render();
};
#endif

#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { s32 v[5]; };

typedef struct TAdSelectCurGC_802AED98 {
    u8 pad0[0xA4];
    s32 fA4;
    u32 fA8;
    s32 fAC;
    s32 fB0;
    s32 fB4;
    s32 fB8;
    u8 padBC[0x6BC - 0xBC];
    s32 tbl[16];
    s32 f6FC;
    s32 f700;
} TAdSelectCurGC_802AED98;

struct TAdSelectCurGC_802AF0E0 {
    s32 f0;
    u8 pad4[0x14];
    void *vt18;
    u8 pad1C[0x9C - 0x1C];
    u8 pad9C[0x08];
    s32 fA4, fA8, fAC, fB0, fB4, fB8;
    u8 padBC[0x6BC - 0xBC];
    s32 tbl[16];
    s32 f6FC, f700;
};

extern "C" {
extern const s32 lbl_80470764[];
extern const s32 lbl_80470778[];
extern const s32 current_language;
extern u32 menu_selection_cursor_texture_list;
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 check_flag_0x48__14TAdSelectCurGCFv(void *, int);
void play_sound_effect(int, int, int, int);
void fn_802AEAA4(void *, s32);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
void run_task__14TAdSelectCurGCFv(TAdSelectCurGC_802AED98 *o);
void __ct__7TObjectFP7TObject(void *);
extern void *__vt__14TAdSelectCurGC[];
extern s32 lbl_805D3E70;
extern const f32 lbl_805DE1E0;
TAdSelectCurGC_802AF0E0 *__ct__14TAdSelectCurGCFv(TAdSelectCurGC_802AF0E0 *o, void *unused, void *a, void *b);
void release_texture_list(void*);
void *__nw__7TObjectFUl(int);

void run_task__14TAdSelectCurGCFv(TAdSelectCurGC_802AED98 *o) {
    s32 ok;
    u32 i;
    fn_802AEAA4(o, o->f6FC++);
    if (o->fB0 == 0 && o->fAC == 0 && (s32)o->fA8 != 0) {
        if (o->fB8 != 0) {
            u8 t = 0;
            if (check_flag_0x48__14TAdSelectCurGCFv(controller_input_state + 0x20, 0x10) == 0 &&
                check_flag_0x48__14TAdSelectCurGCFv(controller_input_state + 0x20, 0x20) == 0) {
                t = 1;
            }
            ok = t;
        } else {
            ok = 1;
        }
        if (ok != 0) {
            if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)(controller_input_state + 0x20), 0x10, 6, 1) != 0 ||
                TWindowChoiceSetting::apply_choice((s32)(controller_input_state + 0x160), 0x10, 6, 1) != 0) {
                play_sound_effect(0x54100, 0, 0, 0);
                o->fA4--;
            }
            if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)(controller_input_state + 0x20), 0x20, 6, 1) != 0 ||
                TWindowChoiceSetting::apply_choice((s32)(controller_input_state + 0x160), 0x20, 6, 1) != 0) {
                play_sound_effect(0x54100, 0, 0, 0);
                o->fA4++;
            }
        }
        if (o->fA4 > (s32)(o->fA8 - 1)) {
            o->fA4 = 0;
        }
        if (o->fA4 < 0) {
            o->fA4 = o->fA8 - 1;
        }
        if (o->fB4 == 0 &&
            (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 4) != 0 ||
             test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 4) != 0)) {
            play_sound_effect(0x52D01, 0, 0, 0);
            o->fAC = 1;
        }
    }
    for (i = 0; i < o->fA8; i++) {
        o->tbl[i] -= 25;
        if (o->tbl[i] < 0) {
            o->tbl[i] = 0;
        }
    }
    o->tbl[o->fA4] = 0xFF;
    switch (o->f700) {
    case 0:
        break;
    case 1:
        o->fAC = 0;
        o->f700 = 0;
        break;
    case 2:
        o->fAC = 1;
        o->f700 = 0;
        break;
    case 3:
        o->fB0 = 0;
        o->f700 = 0;
        break;
    case 4:
        o->fB0 = 1;
        o->f700 = 0;
        break;
    }
}

TAdSelectCurGC::~TAdSelectCurGC() {}
TAdSelectCurGC_802AF0E0 *__ct__14TAdSelectCurGCFv(TAdSelectCurGC_802AF0E0 *o, void *unused, void *a, void *b) {
    s32 i;
    __ct__7TObjectFP7TObject(o);
    o->vt18 = __vt__14TAdSelectCurGC;
    o->f0 = lbl_805D3E70;
    ((TWindowSubSymbolChatPartsSet *)((u8 *)o + 0x1C))->copy_vec2(a);
    ((TWindowSubSymbolChatPartsSet *)((u8 *)o + 0x9C))->copy_vec2(b);
    o->fA4 = 0;
    o->fA8 = 0;
    o->fAC = 0;
    o->f6FC = -1;
    o->fB0 = 0;
    o->fB8 = 0;
    o->fB4 = 0;
    o->f700 = 0;
    TAdSelectCurGC__sub_802AF274(o, lbl_805DE1E0);
    for (i = 0; i < 16; i++) {
        o->tbl[i] = 0;
    }
    return o;
}

void TLobby__sub_802AF198(void) {
    if ((u32) menu_selection_cursor_texture_list != 0U) {
        release_texture_list((void*)menu_selection_cursor_texture_list);
        menu_selection_cursor_texture_list = 0U;
    }
}

void TLobby::apply_menu_cursor_selection() {
    TLobby::update_menu_cursor();
    ByteBlock_14 a = *(const ByteBlock_14 *)lbl_80470764;
    ByteBlock_14 b = *(const ByteBlock_14 *)lbl_80470778;
    s32 r4 = b.v[current_language];
    menu_selection_cursor_texture_list = r4;
    TLobby__sub_8023E4B4(a.v[current_language], r4);
}

void TAdSelectCurGC__sub_802AF274(void* p, f32 v) { *(f32*)((char*)p + 0x704) = v; }


}
