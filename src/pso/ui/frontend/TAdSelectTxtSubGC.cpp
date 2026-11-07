#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtSubGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/npc/TObjNpcHosa.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

const char *ad_select_txt_sub_gc_class_name = "TAdSelectTxtSubGC";
s32 status_disp_texture_handle;

void TAdSelectTxtSubGC::render_status() {
    begin_screen_draw(1);
    TObjFish::set_global_param(status_disp_texture_handle);
    set_draw_texture_and_color((s32)(*(void * *)&(*(s16 *)((u8 *)this + 0x20))), (s32)(*(void **)((s8 *)this + 0x80)));
    draw_textured_quad_at_depth((f32 *)((char *)this + 68), 0.25f);
    TWindowSubStatusDisp::get_player();
}

struct Src_802A37A0 {
    s32 f0;
    s32 f4;
    f32 v8[2];
    s32 f10;
};

struct Txt_802A37A0 {
    const char *f0;
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
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__17TAdSelectTxtSubGC[];
Txt_802A37A0 *__ct__17TAdSelectTxtSubGCFv(Txt_802A37A0 *arg0, void *parent, Src_802A37A0 *src);
void *__ct__11TObjControlFP7TObject(void *, void *);
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
    *(f32 *)((s8 *)arg0 + 0x74) = (2.0f - 0.2f * (f32) *(s32 *)((s8 *)arg0 + 0x84));
    *(f32 *)((s8 *)arg0 + 0x78) = (2.0f - 0.2f * (f32) *(s32 *)((s8 *)arg0 + 0x84));
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
    arg0->f74 = 2.0f;
    arg0->f78 = 2.0f;
    status_disp_texture_handle = TObjNpcHosa__sub_802A39B0();
    arg0->f20 = arg0->f7c > 8;
    arg0->f7c -= (arg0->f7c > 8) ? 9 : 0;
    arg0->f24 = 32.0f * (f32) arg0->f1c + arg0->f64;
    arg0->f28 = arg0->f68;
    arg0->f2c = 32.0f * (arg0->f1c + 1) + arg0->f64;
    arg0->f30 = 27.0f + arg0->f68;
    arg0->f6c = 0.5f * (arg0->f2c - arg0->f24) + arg0->f24;
    arg0->f70 = 0.5f * (arg0->f30 - arg0->f28) + arg0->f28;
    arg0->f54 = (32.0f * (f32) arg0->f1c) / 256.0f;
    arg0->f58 = (28.0f * (f32) arg0->f7c) / 256.0f;
    arg0->f5c = (32.0f * (arg0->f1c + 1) - 1.0f) / 256.0f;
    arg0->f60 = (28.0f * (arg0->f7c + 1) - 1.0f) / 256.0f;
    return arg0;
}
#pragma pop

int TObjNpcHosa__sub_802A39B0(void) {  return ad_select_text_texture_handle; }


void * TObjNpcHosa__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHosa__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
