#include "types.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp_802B0E2C.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Thanks.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/SoundEffect.h"


const char *TBoss6EmptyWarp__name = "TBoss6EmptyWarp";

// Full-screen quad drawn over the view by TBoss6EmptyWarp::render.
f32 empty_warp_overlay_vertices[8] = {
    0.0f, 0.0f, 640.0f, 0.0f, 640.0f, 480.0f, 0.0f, 480.0f,
};
extern const f32 empty_warp_overlay_zero_vec[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

struct Stack_802B0DCC {
    f32 * sp8;
    const f32 * spC;
    s32 sp10;
    s32 sp14;
};

void draw_empty_warp_overlay(void) {
    Stack_802B0DCC stack;
    stack.spC = empty_warp_overlay_zero_vec;
    stack.sp10 = 0;
    stack.sp14 = 4;
    stack.sp8 = empty_warp_overlay_vertices;
    set_depth_buffer_settings_1();
    ((TWindowCtrlMain *)(&stack.sp8))->draw_strip_swap_color(4, 2, -1.0f);
    restore_saved_depth_alpha_state();
}

extern "C" {
s32 is_flag_set__14TBoss6PlotFalzFv();
s32 is_ship_door_ready__12TBoss6ThanksFv();
void end_cutscene_camera__14TBoss6PlotFalzFPv(void);

void TBoss6EmptyWarp::render() { draw_empty_warp_overlay(); }

extern s32 __vt__15TBoss6EmptyWarp[];

void TBoss6EmptyWarp::run_task() {
    u8 *arg0 = (u8 *)this;
    if (is_flag_set__14TBoss6PlotFalzFv() != 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(s32 *)&this->unk_1C = (s32) (*(s32 *)&this->unk_1C + 1);
    if ((s32) *(s32 *)&this->unk_1C > 3) {
        TBoss6EmptyWarp::init_warp();
        if (is_ship_door_ready__12TBoss6ThanksFv() != 0) {
            TBoss6Thanks::create();
            play_area_music((char *)("T2.adx"));
        } else {
            play_area_music((char *)("HALL.adx"));
        }
        queue_destruction__7TObjectFv((arg0));
    }
}

}
TBoss6EmptyWarp::~TBoss6EmptyWarp() {
    end_cutscene_camera__14TBoss6PlotFalzFPv();
}
extern "C" {

void __ct__7TObjectFP7TObject(void *);


void *TBoss6EmptyWarp__ct(void *boss6_empty_warp) {
    __ct__7TObjectFP7TObject(boss6_empty_warp);
    *(s32 **)((s8 *)boss6_empty_warp + 0x18) = __vt__15TBoss6EmptyWarp;
    ((TBoss6EmptyWarp *)boss6_empty_warp)->m_name = TBoss6EmptyWarp__name;
    TBoss6PlotFalz::freeze_all_players();
    *(u32 *)((s8 *)boss6_empty_warp + 0x1C) = 0;
    return boss6_empty_warp;
}

void *__nw__7TObjectFUl(int);

extern void *tl_02;

void *TBoss6EmptyWarp::create() {
    void *o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = ((void *(*)(void *, void *))TBoss6EmptyWarp__ct)(o, tl_02);
    }
    return o;
}

void TBoss6EmptyWarp::activate_warp() {
    *(s32 *)&this->unk_1C = 1;
    play_sound_effect(0x4003351F, 0, 0, 0);
}
void TBoss6EmptyWarp__sub_802B1004(void* p) { *(s32*)((char*)p + 0x20) = 0; *(s32*)((char*)p + 0x1c) = 2; }
int TBoss6EmptyWarp__sub_802B1018(void) { return 0; }

}
