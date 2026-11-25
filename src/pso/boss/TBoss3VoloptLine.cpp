#include "pso/boss/TBoss3VoloptLine.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/render/render_util.h"

extern "C" void draw_line_list(VoloptLineList *lines, s32 count, u32 flags);

__declspec(section ".data") static VoloptLineColor volopt_line_colors[2] = {
    {0x80, 0xFF, 0x40, 0x40},
    {0x80, 0xFF, 0x40, 0x40},
};

static Vec volopt_line_points[2];

static VoloptLineList volopt_line = {
    volopt_line_points, volopt_line_colors, 0, 4,
};

void TBoss3VoloptLine::render() {
    VecCopy(&volopt_line_points[0], (Vec *)from);
    VecCopy(&volopt_line_points[1], (Vec *)to);
    set_additive_blend();
    draw_line_list(&volopt_line, 1, 5);
    set_default_alpha_blend();
}

void TBoss3VoloptLine::run_task() {}

TBoss3VoloptLine::~TBoss3VoloptLine() {}

TBoss3VoloptLine::TBoss3VoloptLine(void *from, void *to) : TObject(tl_05) {
    this->from = from;
    this->to = to;
}
