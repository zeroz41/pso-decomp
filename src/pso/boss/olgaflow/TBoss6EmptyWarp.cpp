#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/unk/TLobby_80226C3C.h"

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Thanks.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


const char *TBoss6EmptyWarp::name = "TBoss6EmptyWarp";

// Full-screen quad drawn over the view by TBoss6EmptyWarp::render.
f32 empty_warp_overlay_vertices[8] = {
    0.0f, 0.0f, 640.0f, 0.0f, 640.0f, 480.0f, 0.0f, 480.0f,
};
extern const f32 empty_warp_overlay_zero_vec[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

void draw_empty_warp_overlay(void) {
    ColorLineList list;
    list.colors = (u32 *)empty_warp_overlay_zero_vec;
    list.tex = NULL;
    list.count = 4;
    list.verts = (ColorLineVertex *)empty_warp_overlay_vertices;
    set_depth_buffer_settings_1();
    list.draw_strip_swap_color(4, 2, -1.0f);
    restore_saved_depth_alpha_state();
}

void TBoss6EmptyWarp::render() { draw_empty_warp_overlay(); }

void TBoss6EmptyWarp::run_task() {
    if (TBoss6PlotFalz::is_flag_set() != 0) {
        queue_destruction();
        return;
    }
    warp_delay = warp_delay + 1;
    if (warp_delay > 3) {
        TBoss6EmptyWarp::init_warp();
        if (TBoss6Thanks::is_ship_door_ready() != 0) {
            TBoss6Thanks::create();
            play_area_music((char *)("T2.adx"));
        } else {
            play_area_music((char *)("HALL.adx"));
        }
        queue_destruction();
    }
}

TBoss6EmptyWarp::~TBoss6EmptyWarp() {
    TBoss6PlotFalz::end_cutscene_camera();
}

TBoss6EmptyWarp::TBoss6EmptyWarp(TObject *parent) : TObject(parent) {
    m_name = TBoss6EmptyWarp::name;
    TBoss6PlotFalz::freeze_all_players();
    warp_delay = 0;
}

void *TBoss6EmptyWarp::create() {
    return new TBoss6EmptyWarp(tl_02);
}
