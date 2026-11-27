#include "pso/boss/TBoss3VoloptLine.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/render/render_util.h"
#include "pso/render/ScreenSpriteDraw.h"

__declspec(section ".data") static NJS_COLOR volopt_line_colors[2] = {
    {0x80FF4040},
    {0x80FF4040},
};

static Vec volopt_line_points[2];

static NJS_POINT3COL volopt_line = {
    volopt_line_points, &volopt_line_colors[0].color, NULL, 4,
};

void TBoss3VoloptLine::render() {
    VecCopy(&volopt_line_points[0], from);
    VecCopy(&volopt_line_points[1], to);
    set_additive_blend();
    draw_line_list(&volopt_line, 1, 5);
    set_default_alpha_blend();
}

void TBoss3VoloptLine::run_task() {}

TBoss3VoloptLine::~TBoss3VoloptLine() {}

TBoss3VoloptLine::TBoss3VoloptLine(Vec *from, Vec *to) : TObject(tl_05) {
    this->from = from;
    this->to = to;
}
