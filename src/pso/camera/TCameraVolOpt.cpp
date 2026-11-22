// The Vol Opt camera (mode 11), and the TCameraController virtuals that do
// nothing.
#include "types.h"
#include "pso/camera/TCameraVolOpt.h"
#include "pso/camera/TCameraController.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"

void TCameraController::apply_camera_params(s32) {  }
void TCameraController::reset_state() {  }
void TCameraController::reset_to_actor_offset(TObjPlayer *, Vec *) {  }
void TCameraController::reset_to_actor(TObjPlayer *) {  }
void TCameraController::init_pose() {  }

TCameraController *TCameraVolOpt::create() {
    return new TCameraVolOpt();
}

#pragma push
#pragma fp_contract on
void TCameraVolOpt::run_task() {
    Vec dir;
    Vec *focus;
    this->eye_rate = 1.0f;
    if (this->actor != NULL) {
        focus = TBoss3Volopt::get_camera_focus();
        if (focus != NULL) {
            VecCopy(&this->target, focus);
            dir.x = this->actor->position.x - focus->x;
            dir.z = this->actor->position.z - focus->z;
            dir.y = 0.0f;
            if (0.0f != vector_length(&dir)) {
                normalize_vector(&dir);
                this->position.x = 30.0f * dir.x + this->actor->position.x;
                this->position.y = 10.0f + this->actor->position.y;
                this->position.z = 30.0f * dir.z + this->actor->position.z;
            }
        }
    }
}
#pragma pop

TCameraVolOpt::~TCameraVolOpt() {

}

TCameraVolOpt::TCameraVolOpt() : TCameraController() {
    this->flags = FLAG_CHECK_OBSTRUCTION | FLAG_SMOOTH_POSE;
    this->set_target(get_player_by_client_id(0));
}
