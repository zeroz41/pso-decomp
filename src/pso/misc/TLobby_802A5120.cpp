#include "types.h"
#include "pso/TChCrTagPlBack.h"
#include "pso/TObjCMAssignMenu.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct V2_802A5208 { f32 x; f32 y; };

#pragma push
#pragma readonly_strings on
const char *TChCrTagPlBack__name = "TChCrTagPlBack";
#pragma pop

struct Tag_802A5208 { u8 pad0[0x24]; f32 t; };

extern "C" {
void draw_ui_sprite(s32, void *, f32, f32);
void draw_ui_sprite_scaled(s32, void *, void *, f32, f32);
extern const V2_802A5208 lbl_80466720[];
extern const V2_802A5208 lbl_80466728[];
extern const V2_802A5208 lbl_80466730[];
extern const V2_802A5208 lbl_80466738[];
extern const V2_802A5208 lbl_80466740[];
extern const V2_802A5208 lbl_80466748[];
extern const V2_802A5208 lbl_80466750[];
extern const V2_802A5208 lbl_80466758[];
void release_texture_list(void*);

extern u32 lbl_805D6668;
extern const s32 lbl_804666DC[];
extern const s32 lbl_804666F0[];
extern const s32 current_language;
void update_menu_cursor__6TLobbyFv(void);
void TLobby__sub_8023E4B4(s32, s32);

struct Tbl_802A5154 { s32 v[5]; };

void TLobby::free_dialing_gc() {
    if ((u32) lbl_805D6668 != 0U) {
        release_texture_list((void*)lbl_805D6668);
        lbl_805D6668 = 0U;
    }
}
void TLobby__sub_802A5154(void) {
    if (lbl_805D6668 != 0U) {
        return;
    }
    update_menu_cursor__6TLobbyFv();
    Tbl_802A5154 a = *(const Tbl_802A5154 *)lbl_804666DC;
    Tbl_802A5154 b = *(const Tbl_802A5154 *)lbl_804666F0;
    s32 r4 = a.v[current_language];
    lbl_805D6668 = r4;
    TLobby__sub_8023E4B4(b.v[current_language], r4);
}
void TChCrTagPlBack::draw_frame() {
    Tag_802A5208 *self = (Tag_802A5208 *)this;
    f32 a;
    a = 1.0f;
    if (self->t < 0.5f) {
        a = self->t / 0.5f;
    }
    V2_802A5208 p1 = lbl_80466720[0];
    draw_ui_sprite(0x7E, &p1, -3.375f, a);
    V2_802A5208 p2 = lbl_80466728[0];
    draw_ui_sprite(0x80, &p2, -3.375f, a);
    V2_802A5208 p3 = lbl_80466730[0];
    draw_ui_sprite(0x84, &p3, -3.375f, a);
    V2_802A5208 p4 = lbl_80466738[0];
    draw_ui_sprite(0x86, &p4, -3.375f, a);
    V2_802A5208 scale = lbl_80466740[0];
    V2_802A5208 p5 = lbl_80466748[0];
    draw_ui_sprite_scaled(0x7F, &p5, &scale, -3.375f, a);
    V2_802A5208 p6 = lbl_80466750[0];
    draw_ui_sprite_scaled(0x85, &p6, &scale, -3.375f, a);
    V2_802A5208 base = lbl_80466758[0];
    V2_802A5208 cur;
    for (; base.y <= 396.0f; base.y += 8.0f) {
        ((TWindowSubSymbolChatPartsSet *)(&cur))->copy_vec2(&base);
        draw_ui_sprite(0x81, &cur, -3.375f, a);
        cur.x += 32.0f;
        draw_ui_sprite_scaled(0x82, &cur, &scale, -3.375f, a);
        cur.x = 575.0f;
        draw_ui_sprite(0x83, &cur, -3.375f, a);
    }
}

}

// The frame sprites' positions (and the edge scale), defined after their use so
// draw_frame addresses each one on its own.
__declspec(section ".rodata") const V2_802A5208 lbl_80466720[1] = { { 307.0f, 100.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466728[1] = { { 575.0f, 100.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466730[1] = { { 307.0f, 396.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466738[1] = { { 575.0f, 396.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466740[1] = { { 7.375f, 1.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466748[1] = { { 339.0f, 100.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466750[1] = { { 339.0f, 396.0f } };
__declspec(section ".rodata") const V2_802A5208 lbl_80466758[1] = { { 307.0f, 132.0f } };
