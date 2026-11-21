#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"

extern "C" {

void TAdSelectCurGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_quads(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

}
