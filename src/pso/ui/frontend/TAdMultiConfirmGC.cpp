#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/frontend/TAdMultiOkGC.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdMultiPlayerNoGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"

#pragma defer_codegen on

const char *multi_confirm_name = "TAdMultiConfirmGC";
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"

extern "C" {
s32 is_player_model_shown(void *);
extern const char multi_confirm_empty_line[] = "";
}
#pragma push
#pragma opt_common_subs off
TAdMultiConfirmGC::TAdMultiConfirmGC(TObject *parent) : TObject(parent) {
    TAdMultiOkSetup arg;
    u32 i;
    u32 j;
    u32 n;
    TAdGuideTxtGC *p;
    m_name = multi_confirm_name;
    state = 0;
    guide = 0;
    for (i = 0; i < 4; i++) {
        players[i] = 0;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdTitleGC(this, 0x10);
    new TAdTitleTexGC(this);
    count = 0;
    for (i = 0; i < 4; i++) {
        ids[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            ids[count] = i;
            count++;
        }
    }
    arg.count = count;
    arg.mask = 0;
    for (j = 0; j < (n = count); j++) {
        players[j] = TAdMultiPlyChrSelectGC::get_or_create_player(this, n + 1, j, ids[j]);
        new TAdMultiPlayerNoGC(this, count, j, ids[j]);
        arg.mask |= 1 << ids[j];
    }
    ok = new TAdMultiOkGC(this, &arg);
    p = new TAdGuideTxtGC(this);
    guide = p;
    guide->set_line(0, reinterpret_cast<const char *>((get_localized_text_entry(0x25, 0))));
    guide->set_line(1, multi_confirm_empty_line);
    set_confirm_camera();
}

#pragma pop

TAdMultiConfirmGC::~TAdMultiConfirmGC() {
    restore_default_camera();
}
void TAdMultiConfirmGC::run_task() {
    u32 j;
    u32 i;
    switch (this->state) {
    case 0:
        this->state = 1;
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            if (players[i] != NULL) {
                players[i]->request_state(2);
            }
        }
        this->state = 2;
        break;
    case 2:
        i = 1;
        for (j = 0; j < this->count; j++) {
            if (players[j] != NULL && is_player_model_shown(players[j]) == 0) {
                i = 0;
                break;
            }
        }
        if ((s32)i == 1) {
            for (i = 0; i < this->count; i++) {
                if (players[i] != NULL) {
                    enable_spin_model(players[i]);
                    reset_animation_ticks(players[i]);
                }
            }
            this->state = 3;
        }
        break;
    case 3:
        if (ok->multi_confirm_cancel_requested() != 0) {
            TAdMultiChgGameModeGC::open_multi_ply_chr_select_scene();
        } else if (ok->are_all_entries_finished() != 0) {
            TAdMultiChgGameModeGC::open_multi_sel_game_mode_scene();
        }
        break;
    }
}
void TAdMultiConfirmGC::render() {  }
void TAdMultiConfirmGC::set_confirm_camera() {
    CameraParams cam;
    Vec b = {0.0f, 0.0f, 0.0f};
    Vec a = {0.0f, 0.0f, -100.0f};
    VecCopy(&cam.position, &b);
    VecCopy(&cam.target, &a);
    cam.fov = 0x1999;
    activate_camera_mode(9);
    set_active_camera_pose_from_params(&cam);
}
void TAdMultiConfirmGC::restore_default_camera() {
    CameraParams cam;
    Vec b = {0.0f, 0.0f, 0.0f};
    Vec a = {0.0f, 0.0f, -100.0f};
    VecCopy(&cam.position, &b);
    VecCopy(&cam.target, &a);
    cam.fov = 0x36C1;
    activate_camera_mode(9);
    set_active_camera_pose_from_params(&cam);
}
