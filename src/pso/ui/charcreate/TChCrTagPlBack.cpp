#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

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

int TChCrTagPlBack__vt4(void);
int render__14TChCrTagPlBackFv(void* p);
void __dl__7TObjectFPv(void *);
void render_shadows__7TObjectFv(void *);
TChCrTagPlBack *__dt__14TChCrTagPlBackFv(TChCrTagPlBack *tag, s16 free);
extern void *__vt__14TChCrTagPlBack[6];

void TChCrTagPlBack::render() { draw_frame(); }
int TChCrTagPlBack__vt4(void) { return 0; }
TChCrTagPlBack *__dt__14TChCrTagPlBackFv(TChCrTagPlBack *tag, s16 free) {
    if (tag != NULL) {
        *(void ***)((u8 *)tag + 0x18) = __vt__14TChCrTagPlBack;
        __dt__8TChCrTagFv(tag, 0);
        if (free > 0) {
            __dl__7TObjectFPv(tag);
        }
    }
    return tag;
}

void *__vt__14TChCrTagPlBack[6] = {
    0, 0, (void *)__dt__14TChCrTagPlBackFv, (void *)update_fade__8TChCrTagFPv,
    (void *)render__14TChCrTagPlBackFv, (void *)render_shadows__7TObjectFv,
};

}

TChCrTagPlBack::TChCrTagPlBack(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = TChCrTagPlBack__name;
    m_28 = 0.06666667f;
    m_2c = -0.06666667f;
    m_34 = 0.06666667f;
    m_38 = -0.06666667f;
}

extern "C" {

void *TChCrTagPlBack::create(void *arg0) {
    return new TChCrTagPlBack(tl_03, arg0);
}

void *TChCrTagPlBack::create_default() { return TChCrTagPlBack::create(NULL); }

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
