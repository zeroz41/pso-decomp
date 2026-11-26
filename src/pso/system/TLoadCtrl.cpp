#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/LocalClientId.h"
#include "pso/map/FloorTransition.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/audio/MusicControl.h"
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
#include "pso/system/ControllerInput.h"

TLoadCtrl *TLoadCtrl::instance;

void TLoadCtrl::set_field1C(s32 poll_input) {
    if (instance != NULL) {
        instance->m_poll_input = poll_input;
    }
}

s32 TLoadCtrl::loading_mode;

TAdFadeGC *load_ctrl_fade_task;

BOOL TLoadCtrl::is_loading() {
    return instance ? TRUE : FALSE;
}

void TLoadCtrl::render() {  }

const char *TLoadCtrl::class_name = "TLoadCtrl";
// The TNowLoading constructor copies it to TNowLoading::m_position.
const Vec now_loading_pos = {0.0f, 0.0f, -100.0f};

void TLoadCtrl::run_task() {
    if (instance != NULL) {
        if (load_ctrl_fade_task != NULL && load_ctrl_fade_task->all_parents_unqueued_for_destruction() == 0) {
            load_ctrl_fade_task = NULL;
        }
        if (++m_frame_count == 2) {
            switch (loading_mode) {
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
        if (m_poll_input != 0) {
            controller_stuff();
            update_keyboard_input_frame();
        }
        update_sound_request_slots();
        Vec position = {0.0f, 0.0f, 0.0f};
        Vec target = {0.0f, 0.0f, -1.0f};
        activate_camera_mode(9);
        set_active_camera_pose(&position, &target);
    }
}

TLoadCtrl::~TLoadCtrl() {
    if (load_ctrl_fade_task != NULL) {
        load_ctrl_fade_task->queue_destruction();
        load_ctrl_fade_task = NULL;
    }
    if (instance != NULL) {
        instance = NULL;
    }
}

TLoadCtrl::TLoadCtrl(TObject *parent) : TObject(parent) {
    m_poll_input = 1;
    load_ctrl_fade_task = NULL;
    m_frame_count = 0;
    m_name = class_name;
    if ((u32)loading_mode == 0 || (u32)loading_mode == 1) {
        load_ctrl_fade_task = new TAdFadeGC(tl_fade, 2);
    }
}

void TLoadCtrl::cleanup_scene() {
    TLoadCtrl *load_ctrl = instance;
    if (load_ctrl != NULL) {
        load_ctrl->queue_destruction();
        instance = NULL;
    }
    switch (loading_mode) {
    case 0:
        release_bgm_resource();
        TNowLoading::cleanup();
        break;
    case 1:
        release_bgm_resource();
        TAdLoadQuestGC::cleanup();
        break;
    case 3:
    case 4:
        release_bgm_resource();
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

void TLoadCtrl::start_loading(u32 mode) {
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    if (mode == 2) {
        s32 entrance = select_area_entrance(&floor_transition_state);
        if (entrance == 0) {
            mode = 3;
        } else if (entrance == 1) {
            mode = 4;
        } else {
            mode = 0;
        }
    }
    switch ((s32)mode) {
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
    loading_mode = mode;
    switch ((s32)mode) {
    case 2:
        break;
    case 0:
        start_bgm_stream(0);
        break;
    case 1:
        start_bgm_stream(3);
        break;
    case 3:
        start_bgm_stream(1);
        break;
    case 4:
        start_bgm_stream(2);
        break;
    }
    new TCameraCtrl(tl_camera);
    instance = new TLoadCtrl(tl_su);
}

void TLoadCtrl::poll_default() { start_loading(0); }
