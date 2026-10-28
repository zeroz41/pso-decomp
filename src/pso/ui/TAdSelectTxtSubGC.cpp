#include "pso/TAdSelectTxtSubGC.h"
#include "pso/npc/TObjNpcHosa.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/ui/TAdSelectTxtSubGC.h"

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct Src_802A37A0 {
    s32 f0;
    s32 f4;
    f32 v8[2];
    s32 f10;
};

struct Txt_802A37A0 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    s32 f1c;
    s32 f20;
    f32 f24, f28, f2c, f30;
    u8 pad34[0x54 - 0x34];
    f32 f54, f58, f5c, f60;
    f32 f64, f68;
    f32 f6c, f70;
    f32 f74, f78;
    s32 f7c;
    s32 f80;
    s32 f84;
};

extern "C" {
extern const f32 lbl_805DDF3C;
extern const f32 lbl_805DDF40;
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__17TAdSelectTxtSubGC[];
extern s32 ad_select_txt_sub_gc_class_name;
extern s32 status_disp_texture_handle;
extern const f32 lbl_805DDF44;
extern const f32 lbl_805DDF48;
extern const f32 lbl_805DDF4C;
extern const f32 lbl_805DDF54;
extern const f32 lbl_805DDF58;
Txt_802A37A0 *__ct__17TAdSelectTxtSubGCFv(Txt_802A37A0 *arg0, void *parent, Src_802A37A0 *src);
void *TObjControl__ct(void *, void *);
void *__nw__7TObjectFUl(int);

void TAdSelectTxtSubGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); render_status(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

    extern int ad_select_text_texture_handle;

#pragma push
#pragma fp_contract on
void TAdSelectTxtSubGC::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x84);
    if (temp_r4 < 5) {
        *(s32 *)((s8 *)arg0 + 0x84) = (temp_r4 + 1);
    }
    *(f32 *)((s8 *)arg0 + 0x74) = (f32) -((lbl_805DDF40 * (f32) *(s32 *)((s8 *)arg0 + 0x84)) - lbl_805DDF3C);
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) -((lbl_805DDF40 * (f32) *(s32 *)((s8 *)arg0 + 0x84)) - lbl_805DDF3C);
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x6C);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) ((*(f32 *)((s8 *)arg0 + 0x74) * (*(f32 *)((s8 *)arg0 + 0x24) - temp_f2)) + temp_f2);
    temp_f2_2 = *(f32 *)((s8 *)arg0 + 0x70);
    *(f32 *)((s8 *)arg0 + 0x48) = (f32) ((*(f32 *)((s8 *)arg0 + 0x78) * (*(f32 *)((s8 *)arg0 + 0x28) - temp_f2_2)) + temp_f2_2);
    temp_f2_3 = *(f32 *)((s8 *)arg0 + 0x6C);
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) ((*(f32 *)((s8 *)arg0 + 0x74) * (*(f32 *)((s8 *)arg0 + 0x2C) - temp_f2_3)) + temp_f2_3);
    temp_f2_4 = *(f32 *)((s8 *)arg0 + 0x70);
    *(f32 *)((s8 *)arg0 + 0x50) = (f32) ((*(f32 *)((s8 *)arg0 + 0x78) * (*(f32 *)((s8 *)arg0 + 0x30) - temp_f2_4)) + temp_f2_4);
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdSelectTxtSubGC::~TAdSelectTxtSubGC() {}
Txt_802A37A0 *__ct__17TAdSelectTxtSubGCFv(Txt_802A37A0 *arg0, void *parent, Src_802A37A0 *src) {
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->vt = __vt__17TAdSelectTxtSubGC;
    arg0->f0 = ad_select_txt_sub_gc_class_name;
    arg0->f7c = src->f0;
    arg0->f1c = src->f4;
    ((TWindowSubSymbolChatPartsSet *)(&arg0->f64))->copy_vec2(src->v8);
    arg0->f80 = src->f10;
    arg0->f84 = -1;
    arg0->f74 = lbl_805DDF3C;
    arg0->f78 = lbl_805DDF3C;
    status_disp_texture_handle = TObjNpcHosa__sub_802A39B0();
    arg0->f20 = arg0->f7c > 8;
    arg0->f7c -= (arg0->f7c > 8) ? 9 : 0;
    arg0->f24 = lbl_805DDF44 * (f32) arg0->f1c + arg0->f64;
    arg0->f28 = arg0->f68;
    arg0->f2c = lbl_805DDF44 * (arg0->f1c + 1) + arg0->f64;
    arg0->f30 = lbl_805DDF48 + arg0->f68;
    arg0->f6c = lbl_805DDF4C * (arg0->f2c - arg0->f24) + arg0->f24;
    arg0->f70 = lbl_805DDF4C * (arg0->f30 - arg0->f28) + arg0->f28;
    arg0->f54 = (lbl_805DDF44 * (f32) arg0->f1c) / 256.0f;
    arg0->f58 = (lbl_805DDF54 * (f32) arg0->f7c) / 256.0f;
    arg0->f5c = (lbl_805DDF44 * (arg0->f1c + 1) - lbl_805DDF58) / 256.0f;
    arg0->f60 = (lbl_805DDF54 * (arg0->f7c + 1) - lbl_805DDF58) / 256.0f;
    return arg0;
}
#pragma pop

int TObjNpcHosa__sub_802A39B0(void) {  return ad_select_text_texture_handle; }


void * TObjNpcHosa__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHosa__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
