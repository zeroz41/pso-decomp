#include "pso/render/render_util.h"
#include "pso/object/warp/TObjWarpBoss03.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/warp/TObjWarpBoss03.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/object/warp/TObjWarpJungMain.h"

#pragma readonly_strings on

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {

void TObjWarpBoss03::sub_8019F9E4() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18_26a62c *)(arg0))->m8(4e+02f, 2e+01f) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, 2.0f * *(f32 *)(arg0 + 0xAC));
    }
}

}

extern "C" {

void *TObjWarpJungMain__create(void *arg0);
void *__dt__14TObjWarpBoss03Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
u8 *__dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjWarpBoss03::debug_print_area_num() { this->TObjAreaWarp::debug_print_area_num(); sub_8019F9E4(); }
void TObjWarpBoss03::run_task() { { (void)(handle_area_selection()); return; } }

extern s32 __vt__14TObjWarpBoss03[];

}
TObjWarpBoss03::~TObjWarpBoss03() {

}
extern "C" {

const char *TObjWarpBoss03__name = "TObjWarpBoss03";

TObjWarpBoss03::TObjWarpBoss03(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = TObjWarpBoss03__name;
    warp_range = 2e+01f;
}


void *TObjWarpJungMain__create(void *arg0) {
    return new TObjWarpJungMain(tl_05, arg0);
}

}
