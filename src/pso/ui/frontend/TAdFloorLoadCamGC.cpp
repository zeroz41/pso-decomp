#include "types.h"
#include "pso/ui/frontend/TAdFloorLoadCamGC.h"
#include "pso/system/vector.h"

#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/ControllerInputState.h"
#include "pso/quest/challenge/TChallenge4PResult.h"
#include "pso/player/TObjPlayer.h"


const char *floor_load_cam_class_name = "TAdFloorLoadCamGC";
extern const f32 floor_load_cam_zero;

s32 TChallenge4PResult::get_slot_index() { return slot_index; }
void fn_8034BE38(TObjPlayer *player) { player->state_flags &= ~0x40000000; }
void fn_8034BE48(TObjPlayer *player) { player->state_flags |= 0x40000000; }
void TAdFloorLoadCamGC::render() {  }

extern const f32 floor_load_cam_angle_units_per_degree = 182.04445f;
extern const f32 floor_load_cam_stick_scale = -0.1f;
extern const f32 floor_load_cam_x_scale = 1.2f;
extern const f32 floor_load_cam_radius = 100.0f;
extern const f32 floor_load_cam_zero = 0.0f;
extern const f32 floor_load_cam_target_radius = 99.3f;
extern const f32 floor_load_cam_tilt_scale = 0.4f;
#pragma push
#pragma fp_contract on
void TAdFloorLoadCamGC::run_task() {
    Vec up;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dy;
    f32 dz;
    s16 tilt;
    s32 a;
    activate_camera_mode(9);
    this->ticks++;
    tilt = controller_physical_port_bank.controllers[0].stick_x;
    this->angle += (s32)((*(const f32 *)&floor_load_cam_angle_units_per_degree) * (f32)(s32)((*(const f32 *)&floor_load_cam_stick_scale) * (f32)controller_physical_port_bank.controllers[0].cstick_y)) / 10 + 0x1B4;
    a = this->angle;
    if (a >= 0x10000) {
        a -= 0x10000;
    }
    this->angle = a;
    this->pos.x = (*(const f32 *)&floor_load_cam_x_scale) * sin_table_lookup(this->angle);
    this->pos.y = (*(const f32 *)&floor_load_cam_radius) * cos_table_lookup(this->angle);
    this->pos.z = (*(const f32 *)&floor_load_cam_radius) * sin_table_lookup(this->angle);
    this->target.x = (*(const f32 *)&floor_load_cam_zero);
    this->target.y = (*(const f32 *)&floor_load_cam_target_radius) * cos_table_lookup(this->angle + 0x1B4);
    this->target.z = (*(const f32 *)&floor_load_cam_target_radius) * sin_table_lookup(this->angle + 0x1B4);
    if (this->mode == 0) {
        x = (*(const f32 *)&floor_load_cam_tilt_scale) * (f32)tilt + -this->pos.x;
        y = -this->pos.y;
        z = -this->pos.z;
    } else {
        x = (*(const f32 *)&floor_load_cam_tilt_scale) * (f32)tilt + this->pos.x;
        y = this->pos.y;
        z = this->pos.z;
    }
    dx = (x - this->up.x) / 15.0f;
    dy = (y - this->up.y) / 15.0f;
    dz = (z - this->up.z) / 15.0f;
    this->up.x += dx;
    this->up.y += dy;
    this->up.z += dz;
    VecCopy(&up, (const Vec *)&this->up);
    if (vec_squared_length(&this->up) == (*(const f32 *)&floor_load_cam_zero)) {
        up.y = 1.0f;
    } else {
        normalize_vector(&up);
    }
    TCameraCtrl::copy_vec_to_default(&up);
    set_active_camera_pose(&this->pos, &this->target);
}
#pragma pop

TAdFloorLoadCamGC::~TAdFloorLoadCamGC() {
    TCameraCtrl::reset_up_vector();
}
TAdFloorLoadCamGC::TAdFloorLoadCamGC(TObject *parent, s32 mode) : TObject(parent) {
    m_name = floor_load_cam_class_name;
    this->ticks = 0;
    this->angle = 0;
    this->up.x = (*(const f32 *)&floor_load_cam_zero);
    this->up.y = (*(const f32 *)&floor_load_cam_zero);
    this->up.z = (*(const f32 *)&floor_load_cam_zero);
    this->mode = mode;
    TAdMultiChgGameModeGC::set_default_camera();
}
