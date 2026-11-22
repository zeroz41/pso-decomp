#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdGameStartShineGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/TObjPlayer.h"

#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

#pragma readonly_strings on

s32 lbl_805D6E88;

void TAdGameStartShineGC::render_status_box() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lbl_805D6E88));
    set_draw_texture_and_color(0, ((*(s32 *)((s8 *)arg0 + 0x74) << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x54), 0.899f);
    TWindowSubStatusDisp::get_player();
}

struct Shine_8034AB4C {
    const char *name;
    u8 pad4[0x18 - 4];
    void *vt;
    f32 f1C;
    f32 f20;
    f32 x24;
    f32 y28;
    f32 x2C;
    f32 y30;
    f32 x34;
    f32 y38;
    u8 pad3C[0x4C - 0x3C];
    f32 x4C;
    f32 y50;
    u8 pad54[0x64 - 0x54];
    f32 f64;
    f32 f68;
    f32 f6C;
    f32 f70;
    s32 alpha;
    s32 timer;
    s32 visible;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *);
extern s32 __vt__19TAdGameStartShineGC[];
// Shine quad origin and extent the constructor lays the quad out from.
static const NJS_POINT2 game_start_shine_origin = {94.0f, 196.0f};
static const NJS_POINT2 game_start_shine_extent = {512.0f, 128.0f};
const char *lbl_805D4320 = "TAdGameStartShineGC"; // TAdGameStartShineGC__name
Shine_8034AB4C *__ct__19TAdGameStartShineGCFv(Shine_8034AB4C *self);

void TAdGameStartShineGC::render() {
    if ((TMainTask::get_render_pass() != 1) && ((s32) *(s32 *)((s8 *)this + 0x7C) != 0)) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        render_status_box();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}
#pragma push
#pragma fp_contract on
void TAdGameStartShineGC::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    s32 temp_r4;
    s32 var_r0;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x78);
    *(s32 *)((s8 *)arg0 + 0x78) = (temp_r4 + 1);
    if (temp_r4 >= 0xA) {
        *(s32 *)((s8 *)arg0 + 0x7C) = 1;
        *(s32 *)((s8 *)arg0 + 0x74) = (s32) (*(s32 *)((s8 *)arg0 + 0x74) - 0xE);
        var_r0 = *(s32 *)((s8 *)arg0 + 0x74);
        if (var_r0 < 0) {
            var_r0 = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x74) = var_r0;
        *(f32 *)((s8 *)arg0 + 0x1C) = 1.0f - -0.011111114f * (f32) (*(s32 *)((s8 *)arg0 + 0x78) - 0xB);
        *(f32 *)((s8 *)arg0 + 0x20) = 1.0f;
        temp_f2 = *(f32 *)((s8 *)arg0 + 0x4C);
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) ((*(f32 *)((s8 *)arg0 + 0x1C) * (*(f32 *)((s8 *)arg0 + 0x2C) - temp_f2)) + temp_f2);
        temp_f2_2 = *(f32 *)((s8 *)arg0 + 0x50);
        *(f32 *)((s8 *)arg0 + 0x58) = (f32) ((*(f32 *)((s8 *)arg0 + 0x20) * (*(f32 *)((s8 *)arg0 + 0x30) - temp_f2_2)) + temp_f2_2);
        temp_f2_3 = *(f32 *)((s8 *)arg0 + 0x4C);
        *(f32 *)((s8 *)arg0 + 0x5C) = (f32) ((*(f32 *)((s8 *)arg0 + 0x1C) * (*(f32 *)((s8 *)arg0 + 0x34) - temp_f2_3)) + temp_f2_3);
        temp_f2_4 = *(f32 *)((s8 *)arg0 + 0x50);
        *(f32 *)((s8 *)arg0 + 0x60) = (f32) ((*(f32 *)((s8 *)arg0 + 0x20) * (*(f32 *)((s8 *)arg0 + 0x38) - temp_f2_4)) + temp_f2_4);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdGameStartShineGC::~TAdGameStartShineGC() {}
Shine_8034AB4C *__ct__19TAdGameStartShineGCFv(Shine_8034AB4C *self) {
    __ct__7TObjectFP7TObject(self);
    self->vt = __vt__19TAdGameStartShineGC;
    self->name = lbl_805D4320;
    self->f1C = 1.0f;
    self->f20 = 1.0f;
    copy_vec2((&self->x24), (void *)&game_start_shine_origin);
    self->x2C = self->x24;
    self->y30 = self->y28;
    self->x34 = self->x24 + game_start_shine_extent.x;
    self->y38 = self->y28 + game_start_shine_extent.y;
    self->f64 = 0.0f;
    self->f68 = 0.0f;
    self->f6C = 1.0f;
    self->f70 = 0.25f;
    self->x4C = 0.5f * (self->x34 - self->x2C) + self->x2C;
    self->y50 = 0.5f * (self->y38 - self->y30) + self->y30;
    self->alpha = 0xFF;
    self->timer = -1;
    self->visible = 0;
    lbl_805D6E88 = TObjPlayer::get_instance();
    return self;
}
#pragma pop

}
