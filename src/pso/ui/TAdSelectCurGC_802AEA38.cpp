#include "types.h"
#include "pso/TMainTask.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/TAdSelectCurGC.h"

extern "C" {

int draw_select_cursor_quads(void*);

void TAdSelectCurGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_select_cursor_quads(this); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

}
