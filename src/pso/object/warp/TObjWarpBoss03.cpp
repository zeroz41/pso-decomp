#include "pso/render/render_util.h"
#include "pso/object/warp/TObjWarpBoss03.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"

#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/object/warp/TObjWarpJungMain.h"

#pragma readonly_strings on

extern "C" {

void TObjWarpBoss03::sub_8019F9E4() {
    if (this->update_object_view_visibility(4e+02f, 2e+01f) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, 2.0f * this->warp_range);
    }
}


void TObjWarpBoss03::debug_print_area_num() { this->TObjAreaWarp::debug_print_area_num(); sub_8019F9E4(); }
void TObjWarpBoss03::run_task() { handle_area_selection(); }

}
TObjWarpBoss03::~TObjWarpBoss03() {

}


const char *TObjWarpBoss03__name = "TObjWarpBoss03";

TObjWarpBoss03::TObjWarpBoss03(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = TObjWarpBoss03__name;
    warp_range = 2e+01f;
}


void *TObjWarpJungMain::create(void *set_data) {
    return new TObjWarpJungMain(tl_05, set_data);
}

