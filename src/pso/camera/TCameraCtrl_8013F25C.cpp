#include "types.h"
#include "pso/camera/TCameraCtrl.h"

    extern int TCameraCtrl__fixed_npc_camera_active;
int TCameraCtrl::get_mode() {  return TCameraCtrl__fixed_npc_camera_active; }
