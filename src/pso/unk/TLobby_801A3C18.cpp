#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"

    extern int switch_doors_force_closed;
void TLobby::reset_door_state() { switch_doors_force_closed = 0; }

void TCameraCtrl::reset_mode() { TCameraCtrl::camera_mode = 0; }

void TCameraCtrl::set_camera_id(int id) { TCameraCtrl::camera_id = id; }

void TCameraCtrl::set_mode(int mode) { TCameraCtrl::camera_mode = mode; }

s8 TCameraCtrl::get_view_state() { return camera_ctrl_view_state_byte; }
