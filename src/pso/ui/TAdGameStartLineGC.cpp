#include "pso/TAdGameStartLineGC.h"

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

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
extern void *lbl_805D6C18;
extern const f32 lbl_805DF4A0;
extern const f32 lbl_805DF4AC;
extern const f32 lbl_805DF4B0;
extern const f32 lbl_805DF4B4;
extern const f32 lbl_805DF4B8;
extern const f32 lbl_805DF4BC;
extern const f32 lbl_805DF4C0;
extern const f32 lbl_805DF4C4;
extern const f32 lbl_805DF4C8;
extern const f32 lbl_805DF4CC;
extern const f32 lbl_805DF4D0;
extern const f32 lbl_805DF4D4;
TAdGameStartLineGC_80320EF0 *__ct__18TAdGameStartLineGCFv(TAdGameStartLineGC_80320EF0 *self, void *parent);
extern const f32 lbl_805DF4A4;
extern const f32 lbl_805DF4A8;
int fn_80320DE8(void*);

void TAdGameStartLineGC::render() { if (TMainTask::get_render_pass() != 1) { set_additive_blend(); fn_80320DE8(this); set_default_alpha_blend(); } }

#pragma push
#pragma fp_contract on
void TAdGameStartLineGC::run_task() {
    TAdGameStartLineGC_80320EF0 *self = (TAdGameStartLineGC_80320EF0 *)this;
    s32 i;
    self->counter++;
    if (self->counter < 10) {
        self->sx = lbl_805DF4A0 - lbl_805DF4A4 * (f32)self->counter;
        self->sy = lbl_805DF4A0 - lbl_805DF4A4 * (f32)self->counter;
    } else if (self->counter > 28) {
        self->x -= lbl_805DF4A8;
        self->x2 += lbl_805DF4A8;
        self->base[0].x0 = self->x;
        self->base[0].x1 = lbl_805DF4AC + self->x;
        self->base[1].x0 = lbl_805DF4AC + self->x;
        self->base[1].x1 = lbl_805DF4B0 + self->x;
        self->base[2].x0 = self->x2;
        self->base[2].x1 = self->x2 - lbl_805DF4AC;
        self->base[3].x0 = self->x2 - lbl_805DF4AC;
        self->base[3].x1 = self->x2 - lbl_805DF4B0;
        for (i = 0; i < 4; i++) {
            self->mid[i].x = lbl_805DF4B4 * (self->base[i].x1 - self->base[i].x0) + self->base[i].x0;
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
    self->x = lbl_805DF4B8;
    self->y = lbl_805DF4BC;
    self->x2 = lbl_805DF4C0;
    self->y2 = lbl_805DF4C4;
    self->f158 = -1;
    self->counter = -1;
    self->sx = lbl_805DF4A0;
    self->sy = lbl_805DF4A0;
    lbl_805D6C18 = get_instance__10TObjPlayerFv();
    self->base[0].x0 = self->x;
    self->base[0].y0 = self->y;
    self->base[0].x1 = lbl_805DF4AC + self->x;
    self->base[0].y1 = lbl_805DF4C8 + self->y;
    self->base[1].x0 = lbl_805DF4AC + self->x;
    self->base[1].y0 = self->y;
    self->base[1].x1 = lbl_805DF4B0 + self->x;
    self->base[1].y1 = lbl_805DF4C8 + self->y;
    self->base[2].x0 = self->x2;
    self->base[2].y0 = self->y2;
    self->base[2].x1 = self->x2 - lbl_805DF4AC;
    self->base[2].y1 = self->y2 - lbl_805DF4C8;
    self->base[3].x0 = self->x2 - lbl_805DF4AC;
    self->base[3].y0 = self->y2;
    self->base[3].x1 = self->x2 - lbl_805DF4B0;
    self->base[3].y1 = self->y2 - lbl_805DF4C8;
    for (i = 0; i < 4; i++) {
        self->mid[i].x = lbl_805DF4B4 * (self->base[i].x1 - self->base[i].x0) + self->base[i].x0;
        self->mid[i].y = lbl_805DF4B4 * (self->base[i].y1 - self->base[i].y0) + self->base[i].y0;
    }
    for (i = 0; i < 2; i++) {
        self->cur[i * 2].u0 = lbl_805DF4CC;
        self->cur[i * 2].v0 = lbl_805DF4B4;
        self->cur[i * 2].u1 = lbl_805DF4D0;
        self->cur[i * 2].v1 = lbl_805DF4D0;
        self->cur[i * 2 + 1].u0 = lbl_805DF4B4;
        self->cur[i * 2 + 1].v0 = lbl_805DF4B4;
        self->cur[i * 2 + 1].u1 = lbl_805DF4D4;
        self->cur[i * 2 + 1].v1 = lbl_805DF4D0;
    }
    return self;
}
#pragma pop

}
