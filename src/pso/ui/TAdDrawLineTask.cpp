#include "types.h"
#include "pso/ui/TAdDrawLineTask.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/render/render_util.h"

struct V_80019EB8 { f32 x; f32 y; f32 z; f32 w; };

struct O_80019EB8 { u8 pad[0x2c]; f32 f2c; u8 pad2[0x3c - 0x30]; f32 f3c; u8 pad3[0x5c - 0x40]; f32 f5c; u8 pad4[0x6c - 0x60]; V_80019EB8 v[4]; };

extern "C" {
extern const f32 lbl_805D7DDC;
extern const f32 lbl_805D7DE0;
void fn_80019EB8(O_80019EB8 *self, f32 f);
void fn_80019EB8(O_80019EB8 *self, f32 f) {
    s32 i;
    f32 s;
    if (lbl_805D7DDC == f) {
        return;
    }
    s = lbl_805D7DE0 / f;
    self->f2c = s;
    self->f3c = s;
    self->f5c = lbl_805D7DDC;
    for (i = 0; i < 4; i++) {
        self->v[i].x = s;
    }
}

}

#define TOBJECT_OUT_OF_LINE_HELPERS

extern "C" {
void draw_projected_line_strip__10TObjPlayerFPvii(DrawLineVertex *, s32, s32);
void copy_draw_line_record(DrawLineRecord *, const DrawLineRecord *);
void TAdDrawLineTask__sub_80019A8C(DrawLineVertex *, const DrawLineVertex *);
f32 newton_sqrtf(f32);
}

extern const char *TAdDrawLineTask__class_name;
extern const f32 lbl_805D7DE4;

void TAdDrawLineTask::render() {
    set_default_alpha_blend();
    draw_projected_line_strip__10TObjPlayerFPvii(vertices, 4, 1);
}

void TAdDrawLineTask::run_task() {
    allow_rendering();
    if (1.0f + frame < duration) {
        color.channels.green += color_step.channels.green;
        color.channels.red += color_step.channels.red;
        color.channels.alpha += color_step.channels.alpha;
        color.channels.blue += color_step.channels.blue;
        vertices[2].x += step_x;
        vertices[2].y += step_y;
        vertices[2].w += step_w;
        vertices[2].color.value = color.value;
        vertices[3].x += step_x;
        vertices[3].y += step_y;
        vertices[3].w += step_w;
        vertices[3].color.value = color.value;
        frame += 1.0f;
        return;
    }
    vertices[2].x = line.end.x + half_width_x;
    vertices[2].y = line.end.y + half_width_y;
    vertices[2].w = line.end.w;
    vertices[2].color.value = line.end.color.value;
    vertices[3].x = line.end.x - half_width_x;
    vertices[3].y = line.end.y - half_width_y;
    vertices[3].w = line.end.w;
    vertices[3].color.value = line.end.color.value;
    if (controller != NULL) {
        controller->sub_80019B08(line.key);
    }
    suspend_update();
}

TAdDrawLineTask::~TAdDrawLineTask() {}

#pragma fp_contract on
TAdDrawLineTask::TAdDrawLineTask(TObject *parent, const DrawLineRecord *record, TAdDrawLineCtrl *ctrl)
    : TObject(parent) {
    m_name = TAdDrawLineTask__class_name;
    controller = ctrl;
    copy_draw_line_record(&line, record);
    line.start.w = lbl_805D7DE0 / line.start.w;
    line.end.w = lbl_805D7DE0 / line.end.w;
    f32 dx = line.end.x - line.start.x;
    f32 dy = line.end.y - line.start.y;
    f32 length = newton_sqrtf(dx * dx + dy * dy);
    duration = length / line.speed;
    step_x = dx / duration;
    step_y = dy / duration;
    step_w = (line.end.w - line.start.w) / duration;
    DrawLineColor end_color;
    DrawLineColor start_color;
    start_color.value = line.start.color.value;
    end_color.value = line.end.color.value;
    color_step.channels.green = (end_color.channels.green - start_color.channels.green) / duration;
    color_step.channels.red = (end_color.channels.red - start_color.channels.red) / duration;
    color_step.channels.alpha = (end_color.channels.alpha - start_color.channels.alpha) / duration;
    color_step.channels.blue = (end_color.channels.blue - start_color.channels.blue) / duration;
    color.value = line.start.color.value;
    frame = lbl_805D7DDC;
    f32 normal_x = lbl_805D7DE0 * dy;
    f32 half_width = line.width * lbl_805D7DE4;
    half_width_x = normal_x * half_width / length;
    half_width_y = dx * half_width / length;
    vertices[0].x = line.start.x + half_width_x;
    vertices[0].y = line.start.y + half_width_y;
    vertices[0].w = line.start.w;
    vertices[0].color.value = line.start.color.value;
    vertices[1].x = line.start.x - half_width_x;
    vertices[1].y = line.start.y - half_width_y;
    vertices[1].w = line.start.w;
    vertices[1].color.value = line.start.color.value;
    TAdDrawLineTask__sub_80019A8C(&vertices[2], &vertices[0]);
    TAdDrawLineTask__sub_80019A8C(&vertices[3], &vertices[1]);
    disallow_rendering();
}
