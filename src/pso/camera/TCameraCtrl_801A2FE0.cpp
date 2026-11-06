#include "types.h"
#include "pso/camera/TCameraCtrl.h"

extern "C" {

s32 get_camera_mode__11TCameraCtrlFv();
s32 is_split_screen();

extern s32 local_client_id;

s32 TCameraCtrl::get_camera_no() {
    if (is_split_screen() != 0) {
        return get_camera_mode__11TCameraCtrlFv();
    }
    return local_client_id;
}

}
