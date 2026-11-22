// The player 0 watch camera (mode 10), and the scripted camera's banks per
// floor area.
#include "types.h"
#include "pso/camera/TCameraWatchPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraScripted.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"

static CameraBankFile camera_files_common[1] = { { "CommonCam.rel", 0x48 } };
static CameraBankFile camera_files_bo01[3] = { { "CommonCam.rel", 0x48 }, { "Bo01OpCam.rel", 0xC }, { "Bo01EnCam.rel", 0x48 } };
static CameraBankFile camera_files_bo02[3] = { { "CommonCam.rel", 0x48 }, { "Bo02OpCam.rel", 0xC }, { "Bo02EnCam.rel", 0x48 } };
static CameraBankFile camera_files_bo03[3] = { { "CommonCam.rel", 0x48 }, { "Bo03OpCam.rel", 0xC }, { "Bo03EnCam.rel", 0x48 } };
static CameraBankFile camera_files_bo04[2] = { { "Bo04OpCam.rel", 0x48 }, { "CommonCam.rel", 0x48 } };
static CameraBankFile camera_files_bo05[3] = { { "CommonCam.rel", 0x48 }, { "Bo05OpCam.rel", 0xC }, { "Bo05EnCam.rel", 0x48 } };
static CameraBankFile camera_files_bo06[2] = { { "CommonCam.rel", 0x48 }, { "Bo06OpCam.rel", 0x48 } };
static CameraBankFile camera_files_bo07[3] = { { "CommonCam.rel", 0x48 }, { "Bo07OpCam.rel", 0xC }, { "Bo07EnCam.rel", 0xC } };
static CameraBankFile camera_files_bo08[3] = { { "CommonCam.rel", 0x48 }, { "Bo08OpCam.rel", 0xC }, { "Bo08EnCam.rel", 0x48 } };

// Camera path banks per floor area (get_current_floor_area()), read by load_camera_banks.
CameraBankList camera_path_bank_table[36] = {
    { NULL, 0 }, { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 },
    { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 },
    { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_bo01, 3 },
    { camera_files_bo02, 3 }, { camera_files_bo03, 3 }, { camera_files_bo04, 2 }, { NULL, 0 },
    { camera_files_common, 1 }, { camera_files_common, 1 }, { NULL, 0 }, { camera_files_common, 1 },
    { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 },
    { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_common, 1 },
    { camera_files_common, 1 }, { camera_files_common, 1 }, { camera_files_bo05, 3 }, { camera_files_bo06, 2 },
    { camera_files_bo07, 3 }, { camera_files_bo08, 3 }, { camera_files_common, 1 }, { camera_files_common, 1 },
};

TCameraController *TCameraWatchPlayer::create() {
    return new TCameraWatchPlayer();
}

void TCameraWatchPlayer::apply_camera_params(s32) {
    CameraParams *params;
    TObjPlayer *player;

    if (camera_ctrl_instance != NULL) {
        params = camera_ctrl_instance->get_params();
        player = get_player_by_client_id(0);
        if (player != NULL) {
            target.x = player->position.x;
            target.y = 19.8f + player->position.y;
            target.z = player->position.z;
            position.x = params->position.x;
            position.y = params->position.y;
            position.z = params->position.z;
            eye_rate = params->eye_rate;
        }
    }
}

TCameraWatchPlayer::~TCameraWatchPlayer() {}

TCameraWatchPlayer::TCameraWatchPlayer() {
    flags = FLAG_SMOOTH_POSE;
}

void TCameraWatchPlayer::run_task() {}
