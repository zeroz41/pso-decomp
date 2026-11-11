#include "types.h"
#include "pso/ui/frontend/TAdGameStartLineGC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

extern "C" {
extern void *lbl_805D6C18;
}

#pragma push
#pragma fp_contract on
void TAdGameStartLineGC::fn_80320DE8() {
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)lbl_805D6C18);
    set_draw_texture_and_color(0, m_158);
    for (u32 i = 0; i < 4; i++) {
        draw_textured_quad_at_depth(&cur[i].x0, 0.0001f * i + 0.795f);
    }
    TWindowSubStatusDisp::get_player();
}
#pragma pop

struct Quad_80320EF0 {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

struct Vec2_80320EF0 {
    f32 x, y;
};

struct TAdGameStartLineGC_80320EF0 {
    void *name;
    u8 pad4[0x14];
    void *vt;
    Quad_80320EF0 base[4];
    Quad_80320EF0 cur[4];
    f32 x, y, x2, y2;
    Vec2_80320EF0 mid[4];
    f32 sx, sy;
    s32 pad154;
    s32 f158;
    s32 counter;
};

extern "C" {
void *__ct__7TObjectFP7TObject(void *, void *);
void *get_instance__10TObjPlayerFv(void);
extern void *__vt__18TAdGameStartLineGC[];
extern void *TAdGameStartLineGC__name;
TAdGameStartLineGC_80320EF0 *__ct__18TAdGameStartLineGCFv(TAdGameStartLineGC_80320EF0 *self, void *parent);

void TAdGameStartLineGC::render() { if (TMainTask::get_render_pass() != 1) { set_additive_blend(); fn_80320DE8(); set_default_alpha_blend(); } }

#pragma push
#pragma fp_contract on
void TAdGameStartLineGC::run_task() {
    TAdGameStartLineGC_80320EF0 *self = (TAdGameStartLineGC_80320EF0 *)this;
    s32 i;
    self->counter++;
    if (self->counter < 10) {
        self->sx = 3.0f - 0.2f * (f32)self->counter;
        self->sy = 3.0f - 0.2f * (f32)self->counter;
    } else if (self->counter > 28) {
        self->x -= 64.0f;
        self->x2 += 64.0f;
        self->base[0].x0 = self->x;
        self->base[0].x1 = 384.0f + self->x;
        self->base[1].x0 = 384.0f + self->x;
        self->base[1].x1 = 640.0f + self->x;
        self->base[2].x0 = self->x2;
        self->base[2].x1 = self->x2 - 384.0f;
        self->base[3].x0 = self->x2 - 384.0f;
        self->base[3].x1 = self->x2 - 640.0f;
        for (i = 0; i < 4; i++) {
            self->mid[i].x = 0.5f * (self->base[i].x1 - self->base[i].x0) + self->base[i].x0;
        }
    }
    for (i = 0; i < 4; i++) {
        self->cur[i].x0 = self->sx * (self->base[i].x0 - self->mid[i].x) + self->mid[i].x;
        self->cur[i].y0 = self->sy * (self->base[i].y0 - self->mid[i].y) + self->mid[i].y;
        self->cur[i].x1 = self->sx * (self->base[i].x1 - self->mid[i].x) + self->mid[i].x;
        self->cur[i].y1 = self->sy * (self->base[i].y1 - self->mid[i].y) + self->mid[i].y;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdGameStartLineGC::~TAdGameStartLineGC() {}
TAdGameStartLineGC_80320EF0 *__ct__18TAdGameStartLineGCFv(TAdGameStartLineGC_80320EF0 *self, void *parent) {
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__18TAdGameStartLineGC;
    self->name = TAdGameStartLineGC__name;
    self->x = 27.0f;
    self->y = 191.0f;
    self->x2 = 613.0f;
    self->y2 = 289.0f;
    self->f158 = -1;
    self->counter = -1;
    self->sx = 3.0f;
    self->sy = 3.0f;
    lbl_805D6C18 = get_instance__10TObjPlayerFv();
    self->base[0].x0 = self->x;
    self->base[0].y0 = self->y;
    self->base[0].x1 = 384.0f + self->x;
    self->base[0].y1 = 128.0f + self->y;
    self->base[1].x0 = 384.0f + self->x;
    self->base[1].y0 = self->y;
    self->base[1].x1 = 640.0f + self->x;
    self->base[1].y1 = 128.0f + self->y;
    self->base[2].x0 = self->x2;
    self->base[2].y0 = self->y2;
    self->base[2].x1 = self->x2 - 384.0f;
    self->base[2].y1 = self->y2 - 128.0f;
    self->base[3].x0 = self->x2 - 384.0f;
    self->base[3].y0 = self->y2;
    self->base[3].x1 = self->x2 - 640.0f;
    self->base[3].y1 = self->y2 - 128.0f;
    for (i = 0; i < 4; i++) {
        self->mid[i].x = 0.5f * (self->base[i].x1 - self->base[i].x0) + self->base[i].x0;
        self->mid[i].y = 0.5f * (self->base[i].y1 - self->base[i].y0) + self->base[i].y0;
    }
    for (i = 0; i < 2; i++) {
        self->cur[i * 2].u0 = 0.0f;
        self->cur[i * 2].v0 = 0.5f;
        self->cur[i * 2].u1 = 0.75f;
        self->cur[i * 2].v1 = 0.75f;
        self->cur[i * 2 + 1].u0 = 0.5f;
        self->cur[i * 2 + 1].v0 = 0.5f;
        self->cur[i * 2 + 1].u1 = 1.0f;
        self->cur[i * 2 + 1].v1 = 0.75f;
    }
    return self;
}
#pragma pop

}
