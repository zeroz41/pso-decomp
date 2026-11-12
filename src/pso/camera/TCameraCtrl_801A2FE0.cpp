#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl.h"

extern "C" {

s32 is_split_screen();

extern s32 local_client_id;

s32 TCameraCtrl::get_camera_no() {
    if (is_split_screen() != 0) {
        return TCameraCtrl::get_camera_mode();
    }
    return local_client_id;
}

}
