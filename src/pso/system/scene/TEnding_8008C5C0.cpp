#include "pso/system/scene/TEnding.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/system/scene/TEnding_8008C5C0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/camera/TCameraCtrl.h"

#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
struct Vec_8008C5E8 { s32 x, y, z; };

extern "C" {
void set_active_camera_pose(u8 *arg0, u8 *arg1);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void __ct__7TEndingFv(void *);
void run_load_callback_table(void *, int);
void set_copy_clear_color_argb(int, int, int);
int render_tick__Fv(void);
void *__nw__7TObjectFUl(int);
extern Vec_8008C5E8 lbl_80439570;
extern Vec_8008C5E8 lbl_8043957C;
extern u8 lbl_80439588[];
extern u8 ending_scene_callbacks[];
extern u8 default_scene_light_config[];
extern void *tl_camera;
extern s32 ending_scene_active;

void TEnding::set_flag_and_advance() {
    ending_scene_active = 1;
    TEnding::start_ending_scene();
}

int TEnding::start_ending_scene() {
    void *p;
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    init_map_lights(default_scene_light_config);
    p = __nw__7TObjectFUl(0x1D4);
    if (p != 0) {
        TCameraCtrl__ct((u8 *)p, tl_camera);
    }
    Vec_8008C5E8 a = lbl_80439570;
    Vec_8008C5E8 b = lbl_8043957C;
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose((u8 *)&a, (u8 *)&b);
    clear_resource_load_tasks();
    run_load_callback_table(ending_scene_callbacks, 0x68);
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(2);
    play_area_music((char *)lbl_80439588);
    TParticleCtrl::create_quad_sprites();
    p = __nw__7TObjectFUl(0x710);
    if (p != 0) {
        __ct__7TEndingFv(p);
    }
    return render_tick__Fv();
}

void TEnding__sub_8008C6E8() {}
void TEnding__sub_8008C6EC() {}
}

void TEnding::render() {}
