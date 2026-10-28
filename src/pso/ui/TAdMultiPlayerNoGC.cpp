#include "pso/TAdMultiPlayerNoGC.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ModelDrawContext.h"

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

struct Self_8033A668 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern void *__vt__18TAdMultiPlayerNoGC[];
extern s32 TAdMultiPlayerNoGC__name;
Self_8033A668 *__ct__18TAdMultiPlayerNoGCFv(Self_8033A668 *self, void *parent, s32 n, u32 idx, u32 arg);

extern s32 lbl_805D6D78;

void TAdMultiPlayerNoGC::render_status() {
    s32 arg0 = (s32)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D6D78);
    set_draw_texture_and_color(0, -1);
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x20), (0.25f));
    TWindowSubStatusDisp::get_player();
}

void TAdMultiPlayerNoGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); render_status(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }
void TAdMultiPlayerNoGC::run_task() {  }
#pragma fp_contract on
TAdMultiPlayerNoGC::~TAdMultiPlayerNoGC() {}
Self_8033A668 *__ct__18TAdMultiPlayerNoGCFv(Self_8033A668 *self, void *parent, s32 n, u32 idx, u32 arg) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__18TAdMultiPlayerNoGC;
    self->f0 = TAdMultiPlayerNoGC__name;
    switch (n) {
    case 2:
        self->f40 = idx * 0x130 + 0x68;
        break;
    case 3:
        self->f40 = idx * 0xCB + 0x35;
        break;
    case 4:
        self->f40 = idx * 0x98 + 0x1C;
        break;
    default:
        queue_destruction__7TObjectFv(self);
        return self;
    }
    self->f44 = (112.0f);
    self->f1C = arg;
    self->f20 = self->f40;
    self->f24 = self->f44;
    self->f28 = (128.0f) + self->f40;
    self->f2C = (22.0f) + self->f44;
    self->f30 = (0.0f);
    self->f34 = (22.0f) * self->f1C / 128.0f;
    self->f38 = 1.0f;
    self->f3C = ((22.0f) * self->f1C + (22.0f)) / 128.0f;
    return self;
}

}
