#include "types.h"
#include "pso/player/TObjPlayer_80083360.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/player/TObjPlayer_800847A8.h"
#include "pso/system/memory.h"
#include "pso/player/TUnk_8048E5F4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 init_render_target__10TObjPlayerFv();
extern u32 camera_render_target_singleton;
s32 TCameraCtrl__sub_80068EF0();
extern u8 camera_capture_overlay_alpha;
extern f32 lbl_805D93D0;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
extern s32 lbl_8048E5F4[];

void TObjPlayer::free_singleton() {
    if ((u32) camera_render_target_singleton != 0U) {
        ((TObjPlayer *)camera_render_target_singleton)->reset_lobby_subobject();
    }
    if ((u32) camera_render_target_singleton != 0U) {
        ::operator delete((void *)camera_render_target_singleton);
        camera_render_target_singleton = 0U;
    }
}
void TObjPlayer::init_render_target_singleton() {
    u32 temp_r3;
    camera_render_target_singleton = 0U;
    if (TOKeyMachine01::get_global_state() == 0x21) {
        temp_r3 = (int)::operator new(0x28);
        camera_render_target_singleton = temp_r3;
        if (temp_r3 != 0U) {
            init_render_target__10TObjPlayerFv();
        }
    }
}
void TUnk_8048E5F4::render() {
    if (!(TObjPlayer__sub_800847CC() & 4)) {
        if (*(s32 *)&this->unk_1C & 1) {
            if (TObjPlayer__sub_800847A8() == 1) {
                TCameraCtrl::restore_full_screen_view();
                TParticleCtrl::begin_effect_render();
                TObjPlayer::draw_screen_quad(camera_capture_overlay_alpha << 0x18, 0, lbl_805D93D0);
                TParticleCtrl::end_effect_render();
                TCameraCtrl__sub_80068EF0();
                disable_camera_capture_overlay();
            }
        } else {
            TObjPlayer__sub_80084780();
            capture_viewport_texture();
        }
        if (TObjPlayer::get_camera_flag() != 0) {
            TObjPlayer__sub_80084764();
            TObjPlayer::setup_tev_swap();
        }
    }
}
void TUnk_8048E5F4::render_shadows() { if (TObjPlayer::get_camera_flag() != 0) { TObjPlayer::set_tev_swap_mode((u8)((void*)0)); } }
void TUnk_8048E5F4::run_task() {  }
void *__dt__13TUnk_8048E5F4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8048E5F4;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}
