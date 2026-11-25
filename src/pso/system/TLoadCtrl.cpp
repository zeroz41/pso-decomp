#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/TLobby_80228154.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/ui/frontend/TAdFadeGC.h"
#include "pso/ui/frontend/TAdFloorLoadGC.h"
#include "pso/ui/frontend/TAdFloorLoadPrtGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/network/TLobby.h"

#include "pso/system/vector.h"
#include "pso/ui/hud/TNowLoading.h"

uaddr TLoadCtrl__instance;

void TLoadCtrl::set_field1C(s32 arg0) {
    if ((void *) TLoadCtrl__instance != NULL) {
        *(s32 *)((s8 *)TLoadCtrl__instance + 0x1C) = arg0;
    }
}

struct Obj_8001C620 { u8 pad[0x1C]; s32 f1c; s32 f20; };

extern "C" {
s32 TLoadCtrl__loading_mode;
saddr load_ctrl_fade_task;
void TLoadCtrl__sub_80226DA0(s32 index);
}
void update_sound_request_slots(void);
extern "C" {

BOOL TLoadCtrl::is_loading() {
    return TLoadCtrl__instance ? TRUE : FALSE;
}

void TLoadCtrl::render() {  }

const char *TLoadCtrl__class_name = "TLoadCtrl";
const Vec now_loading_pos = {0.0f, 0.0f, -100.0f}; // inferred: the TNowLoading constructor copies it to TNowLoading::m_position

void TLoadCtrl::run_task() {
    Obj_8001C620 *self = (Obj_8001C620 *)this;
    if (TLoadCtrl__instance != 0U) {
        if ((u32)load_ctrl_fade_task != 0U && ((TObject *)load_ctrl_fade_task)->all_parents_unqueued_for_destruction() == 0) {
            load_ctrl_fade_task = 0;
        }
        if (++self->f20 == 2) {
            switch (TLoadCtrl__loading_mode) {
            case 0:
                new TNowLoading(this, (Vec *)&now_loading_pos);
                break;
            case 1:
                new TAdLoadQuestGC(this);
                break;
            case 2:
                break;
            case 3:
                new TAdFloorLoadGC(this, 0);
                break;
            case 4:
                new TAdFloorLoadGC(this, 1);
                break;
            }
        }
        if (self->f1c != 0) {
            controller_stuff();
            TKeyBoardControl::update_input_frame();
        }
        update_sound_request_slots();
        Vec a = {0.0f, 0.0f, 0.0f};
        Vec b = {0.0f, 0.0f, -1.0f};
        activate_camera_mode(9);
        set_active_camera_pose(&a, &b);
    }
}

TLoadCtrl::~TLoadCtrl() {
    if ((void *) (*(u8 * *)&load_ctrl_fade_task) != NULL) {
        ((TObject *)(*(u8 * *)&load_ctrl_fade_task))->queue_destruction();
        (*(u8 * *)&load_ctrl_fade_task) = NULL;
    }
    if ((u32) TLoadCtrl__instance != 0U) {
        TLoadCtrl__instance = 0U;
    }
}

}
TLoadCtrl::TLoadCtrl(TObject *parent) : TObject(parent) {
    this->m_1c = 1;
    load_ctrl_fade_task = 0;
    this->m_20 = 0;
    this->m_name = TLoadCtrl__class_name;
    if (((u32)TLoadCtrl__loading_mode == 0U) || ((u32)TLoadCtrl__loading_mode == 1U)) {
        load_ctrl_fade_task = (saddr)new TAdFadeGC(tl_fade, 2);
    }
}
extern "C" {

void TLoadCtrl::cleanup_scene() {
    uaddr t;

    t = TLoadCtrl__instance;
    if (t != 0U) {
        ((TObject *)t)->queue_destruction();
        TLoadCtrl__instance = 0U;
    }
    switch (TLoadCtrl__loading_mode) {
    case 0:
        TLobby::release_bgm_resource();
        TNowLoading::cleanup();
        break;
    case 1:
        TLobby::release_bgm_resource();
        TAdLoadQuestGC::cleanup();
        break;
    case 3:
    case 4:
        TLobby::release_bgm_resource();
        TAdFloorLoadGC::cleanup();
        break;
    }
    TCameraCtrl::reset_default_view();
    TCameraCtrl::reset();
    if (camera_ctrl_instance != NULL) {
        delete camera_ctrl_instance;
        camera_ctrl_instance = NULL;
    }
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    TCameraCtrl::create();
}

void TLoadCtrl::start_loading(u32 arg0) {
    s32 temp_r3;
    u8 *load_ctrl;
    u32 var_r31;
    var_r31 = arg0;
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    if (var_r31 == 2U) {
        temp_r3 = select_area_entrance(&floor_transition_state);
        if (temp_r3 == 0) {
            var_r31 = 3U;
        } else if (temp_r3 == 1) {
            var_r31 = 4U;
        } else {
            var_r31 = 0U;
        }
    }
    switch ((s32) var_r31) {
    case 0:
        TNowLoading::setup();
        break;
    case 1:
        TAdLoadQuestGC::setup();
        break;
    case 3:
    case 4:
        TAdFloorLoadGC::setup();
        break;
    }
    TLoadCtrl__loading_mode = (s32) var_r31;
    switch ((s32) var_r31) {
    case 2:
        break;
    case 0:
        TLoadCtrl__sub_80226DA0(0);
        break;
    case 1:
        TLoadCtrl__sub_80226DA0(3);
        break;
    case 3:
        TLoadCtrl__sub_80226DA0(1);
        break;
    case 4:
        TLoadCtrl__sub_80226DA0(2);
        break;
    }
    new TCameraCtrl(tl_camera);
    load_ctrl = (u8 *)new TLoadCtrl(tl_su);
    TLoadCtrl__instance = (uaddr) load_ctrl;
}

void TLoadCtrl::poll_default() { TLoadCtrl::start_loading((uaddr)((void*)(0))); }
}
