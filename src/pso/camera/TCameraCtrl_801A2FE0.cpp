#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/network/client_id.h"

s32 TCameraCtrl::get_camera_no() {
    if (is_split_screen() != 0) {
        return TCameraCtrl::get_camera_mode();
    }
    return local_client_id;
}

