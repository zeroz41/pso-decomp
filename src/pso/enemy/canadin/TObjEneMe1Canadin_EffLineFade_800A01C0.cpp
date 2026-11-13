#include "types.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLineFade.h"
#include "pso/boss/TUnk_80484840.h"
#include "pso/render/render_util.h"

extern "C" void draw_line_list(VoloptLineList *lines, s32 count, u32 flags);

void TObjEneMe1Canadin_EffLineFade::render() {
    VoloptLineList lines;
    lines.points = &m_1C;
    lines.colors = (VoloptLineColor *)m_34;
    lines.pad_8 = 0;
    lines.pad_c = 2;
    set_additive_blend();
    draw_line_list(&lines, 1, 5);
}
