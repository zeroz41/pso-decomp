#include "types.h"
#include "pso/camera/TCameraCtrl_801A3C24.h"
#include "pso/camera/TCameraCtrl.h"

void TCameraCtrl__sub_801A3C24(void) { TCameraCtrl::camera_mode = 0; }

void TCameraCtrl__sub_801A3C30(int a0) { TCameraCtrl::camera_id = a0; }

void TCameraCtrl::set_mode(int a0) { TCameraCtrl::camera_mode = a0; }

    extern unsigned char camera_ctrl_view_state_byte;
unsigned char TLobby__sub_801A3C40(void) {  return camera_ctrl_view_state_byte; }
