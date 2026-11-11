#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_80340EA8.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

void *dt__22TWindowDD_WS_ScrollBarFs(void *arg0, s16 arg1);
s32 draw_visible_window_entries(s32, s32, void *, f32);
int update_window_entry_list__11TWindowBaseFPv(void*, void*);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void *draw_default_entry__9TWindowDDFl();
int update_fade__11TWindowBaseFv(void*);

extern "C" void init__9TWindowDDFv();
extern "C" void render_shadows__7TObjectFv();
struct W_80340F00 { s32 f0; u8 pad4[0x14]; void *p18; u8 pad1c[0x5C - 0x1C]; s32 f5c; u8 pad60[4]; f32 f64; f32 f68; f32 f6c; };
extern s32 lbl_805D42D0;
extern const f32 lbl_805DFC50;
extern const f32 lbl_805DFC70;
__declspec(section ".data") void *lbl_804EFBC8[2] = {
    (void *)0x0, (void *)0x0,
};
void *lbl_804EFBD0[5] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x3,
};
void *lbl_804EFBE4[7] = {
    (void *)0x0, (void *)0x0, (void *)&dt__22TWindowDD_WS_ScrollBarFs, (void *)&init__9TWindowDDFv,
    (void *)&TWindowDD__sub_80340A78, (void *)&render_shadows__7TObjectFv, (void *)0x0,
};

#define lbl_804EFBE4 ((s32 *)lbl_804EFBE4)
W_80340F00 *construct_variant_b__9TWindowDDFPv(W_80340F00 *arg0);

void *TWindowDD_WS_ScrollBar::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804EFBE4;
        ((TWindowDD *)this)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

W_80340F00 *construct_variant_b__9TWindowDDFPv(W_80340F00 *arg0) {
    ((TWindowDD *)arg0)->construct_base((u8 *)lbl_804EFBD0, (s16)4, (u8 *)lbl_804EFBC8);
    arg0->p18 = lbl_804EFBE4;
    arg0->f0 = lbl_805D42D0;
    arg0->f64 = lbl_805DFC70;
    arg0->f68 = lbl_805DFC70;
    arg0->f6c = lbl_805DFC50;
    arg0->f5c = 0x01000000;
    return arg0;
}

void *TWindowDD__sub_80340F70(void) {
    void *o = __nw__7TObjectFUl(0x70);
    if (o != NULL) {
        o = (void *)construct_variant_b__9TWindowDDFPv((W_80340F00 *)o);
    }
    return o;
}

extern const f32 TWindowDD__data_805DFB18;
extern const f32 lbl_805DFC74;
extern const f32 lbl_805DFBCC;
extern const f32 lbl_805DFB34;
extern const f32 lbl_805DFB3C;
extern const f32 lbl_805DFB2C;
extern const f32 lbl_805DFB38;
extern const f32 lbl_805DFB30;
extern const f32 lbl_805DFC64;
extern const f32 lbl_805DFC84;
extern const f32 lbl_805DFC78;
extern const f32 lbl_805DFC88;
extern const f32 lbl_805DFBC4;
extern const f32 lbl_805DFBBC;
extern const f32 lbl_805DFC7C;
extern const f32 lbl_805DFC80;
extern const f32 lbl_805DFC8C;
extern const f32 lbl_805DFBC8;
extern const f32 lbl_805DFBC0;
extern const f32 lbl_805DFC24;
extern f32 lbl_805D6DC0;
extern f32 lbl_805D6DC4;
f32 lbl_805D6DC8;
extern f32 lbl_805D6DCC;
extern f32 lbl_805D6DD0;
extern f32 lbl_805D6DD4;
extern f32 lbl_805D6DD8;
extern f32 lbl_805D6DDC;
extern f32 lbl_805D6DE0;
extern f32 lbl_805D6DE4;
extern f32 lbl_805D6DE8;
extern f32 lbl_805D6DEC;
extern f32 lbl_805D6DF0;
extern f32 lbl_805D6DF4;
extern f32 lbl_805D6DF8;
extern f32 lbl_805D6DFC;
extern f32 lbl_805D6E00;

void __sinit_TWindowDD_80340EA8_cpp(void) {
    lbl_805D6DC0 = lbl_805DFC74 + lbl_805DFBCC;
    lbl_805D6DC4 = lbl_805DFC64 + (lbl_805DFC74 + lbl_805DFBCC);
    lbl_805D6DC8 = TWindowDD__data_805DFB18;
    lbl_805D6DCC = lbl_805DFB34 * lbl_805D6DC8;
    lbl_805D6DD0 = lbl_805D6DC8 * (lbl_805DFB34 + lbl_805DFB3C);
    lbl_805D6DD4 = lbl_805DFB2C * lbl_805D6DC8;
    lbl_805D6DD8 = lbl_805D6DC8 * (lbl_805DFB2C + lbl_805DFB38);
    lbl_805D6DDC = lbl_805DFB30 * lbl_805D6DC8;
    lbl_805D6DE0 = lbl_805D6DC8 * (lbl_805DFB30 + lbl_805DFB38);
    lbl_805D6DE4 = lbl_805DFC78 * lbl_805D6DC8;
    lbl_805D6DE8 = lbl_805DFC7C * lbl_805D6DC8;
    lbl_805D6DEC = lbl_805DFC80 * lbl_805D6DC8;
    lbl_805D6DF0 = lbl_805DFC84 * lbl_805D6DC8;
    lbl_805D6DF4 = lbl_805DFC88 * lbl_805D6DC8;
    lbl_805D6DF8 = lbl_805DFC8C * lbl_805D6DC8;
    lbl_805D6DFC = lbl_805DFC84 * lbl_805D6DC8;
    lbl_805D6E00 = lbl_805DFC88 * lbl_805D6DC8;
    ((f32 *)lbl_804EFBC8)[0] = lbl_805DFBC4;
    ((f32 *)lbl_804EFBC8)[1] = lbl_805DFBC8;
    ((f32 *)lbl_804EFBD0)[0] = lbl_805DFBBC;
    ((f32 *)lbl_804EFBD0)[1] = lbl_805DFBC0;
    ((f32 *)lbl_804EFBD0)[2] = lbl_805DFC24;
}
__declspec(section ".ctors") static void *const __sinit_TWindowDD_80340EA8_cpp_ref = (void *)__sinit_TWindowDD_80340EA8_cpp;

}
