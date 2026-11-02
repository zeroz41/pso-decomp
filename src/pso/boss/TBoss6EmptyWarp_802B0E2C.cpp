#include "types.h"
#include "pso/boss/TBoss6EmptyWarp.h"
#include "pso/boss/TBoss6EmptyWarp_802B0E2C.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObject_80019A50.h"

#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/boss/TBoss6Thanks.h"

extern "C" {
s32 is_flag_set__14TBoss6PlotFalzFv();
s32 is_ship_door_ready__12TBoss6ThanksFv();
void end_cutscene_camera__14TBoss6PlotFalzFPv(void);
int draw_empty_warp_overlay(void*);

void TBoss6EmptyWarp::render() { { (void)(draw_empty_warp_overlay(this)); return; } }

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

extern void *lbl_805D3E90;

void *TBoss6EmptyWarp__ct(void *boss6_empty_warp) {
    __ct__7TObjectFP7TObject(boss6_empty_warp);
    *(s32 **)((s8 *)boss6_empty_warp + 0x18) = __vt__15TBoss6EmptyWarp;
    *(void * *)&((TBoss6EmptyWarp *)boss6_empty_warp)->m_name = lbl_805D3E90;
    TBoss6PlotFalz::freeze_all_players();
    *(u32 *)((s8 *)boss6_empty_warp + 0x1C) = 0;
    return boss6_empty_warp;
}

s32 play_sound_effect(s32, s32, s32, s32);
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
