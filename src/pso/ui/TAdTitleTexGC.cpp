#include "pso/ui/TAdTitleTexGC.h"
#include "pso/misc/TLobby_80132ED0.h"

#include "types.h"
#include "pso/TMainTask.h"

struct V_802A4EF4 { f32 x, y; };

struct B_802A4EF4 {
    f32 x, y, x2, y2;
    u8 pad[0x10];
};

struct Obj_802A4EF4 {
    u8 pad[0x1C];
    B_802A4EF4 b[3];
    u8 pad7C[4];
    s32 f80;
    V_802A4EF4 a[3];
};

extern "C" {
extern const f32 lbl_805DDF8C;
extern const f32 lbl_805DDF90;
extern const f32 lbl_805DDF94;
extern const f32 lbl_805DDF98;
void update_title_tex_positions__13TAdTitleTexGCFPv(Obj_802A4EF4 *arg0);
void __ct__7TObjectFP7TObject(void *);
s32 render_status_pair__20TWindowSubStatusDispFl(void *, s32);

void TAdTitleTexGC::render() {
    s32 temp_r31;

    if (TMainTask::get_render_pass() != 1) {
        render_status_pair__20TWindowSubStatusDispFl(this, (*(s32 *)((s8 *)this + 0x7C) << 0x18) | 0xFF0000 | 0xFFFF);
        sub_802A4D74((s32)((*(s32 *)((s8 *)this + 0x7C) << 0x18) | 0xFF0000 | 0xFFFF), (u8 *)(get_localized_text_entry(0x28, 0)), (u8 *)(get_localized_text_entry(0x28, 1)));
    }
}

void update_title_tex_positions__13TAdTitleTexGCFPv(Obj_802A4EF4 *arg0) {
    V_802A4EF4 sp[3];
    s32 i;
    for (i = 0; i < 3; i++) {
        s32 t = 0x14 - arg0->f80;
        sp[i].x = ((lbl_805DDF8C - arg0->a[i].x) * (f32)(t * t)) / lbl_805DDF90;
        sp[i].y = lbl_805DDF94;
        arg0->b[i].x = arg0->a[i].x + sp[i].x;
        arg0->b[i].y = arg0->a[i].y + sp[i].y;
        arg0->b[i].x2 = lbl_805DDF98 + arg0->b[i].x;
        arg0->b[i].y2 = lbl_805DDF98 + arg0->b[i].y;
    }
}

void TAdTitleTexGC::run_task() {
    s32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r4_3;

    temp_r4 = *(s32 *)((s8 *)this + 0x80);
    if (temp_r4 < 0x14) {
        *(s32 *)((s8 *)this + 0x80) = (temp_r4 + 1);
    }
    temp_r4_2 = *(u32 *)((s8 *)this + 0x7C);
    if (temp_r4_2 < 0xFFU) {
        *(u32 *)((s8 *)this + 0x7C) = (temp_r4_2 + 0xC);
    }
    temp_r4_3 = *(u32 *)((s8 *)this + 0x7C);
    *(u32 *)((s8 *)this + 0x7C) = (temp_r4_3 <= 0xFFU) ? temp_r4_3 : 0xFFU;
    update_title_tex_positions__13TAdTitleTexGCFPv((Obj_802A4EF4 *)(this));
}

extern s32 __vt__13TAdTitleTexGC[];
extern const f32 lbl_805DDF9C;
extern void *TAdTitleTexGC__name;
extern const f32 lbl_805DDFA0;
extern const f32 lbl_805DDFA4;
extern const f32 lbl_805DDFA8;
extern const f32 lbl_805DDFAC;
extern const f32 lbl_805DDFB0;
extern const f32 lbl_805DDFB4;
extern const f32 lbl_805DDFB8;
extern const f32 lbl_805DDFBC;
extern const f32 lbl_805DDFC0;

TAdTitleTexGC::~TAdTitleTexGC() {}
void *__ct__13TAdTitleTexGCFv(void *ad_title_tex_gc) {
    __ct__7TObjectFP7TObject(ad_title_tex_gc);
    *(s32 **)((s8 *)ad_title_tex_gc + 0x18) = __vt__13TAdTitleTexGC;
    *(void * *)&((TAdTitleTexGC *)ad_title_tex_gc)->m_name = TAdTitleTexGC__name;
    *(u32 *)((s8 *)ad_title_tex_gc + 0x7C) = 51;
    *(u32 *)((s8 *)ad_title_tex_gc + 0x80) = -1;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x34) = lbl_805DDF9C;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x38) = lbl_805DDFA0;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x2C) = lbl_805DDFA4;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x30) = lbl_805DDFA8;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x4C) = lbl_805DDFAC;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x50) = lbl_805DDFA8;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x54) = lbl_805DDFB0;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x58) = lbl_805DDFA0;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x84) = lbl_805DDFB4;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x88) = lbl_805DDFB8;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x8C) = lbl_805DDFBC;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x90) = lbl_805DDFB8;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x94) = lbl_805DDFC0;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x98) = lbl_805DDFB8;
    return ad_title_tex_gc;
}

}
