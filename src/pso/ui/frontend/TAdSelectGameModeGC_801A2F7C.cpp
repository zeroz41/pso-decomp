#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_801A3B84.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/network/client_id.h"

void TAdSelectGameModeGC::enable_camera() { TLobby__sub_801A3B90(1); TCameraCtrl::set_camera_id(1); TCameraCtrl::reset_mode(); }

void TAdSelectGameModeGC::free_sub_ctrls() { TLobby__sub_801A3B90((saddr)this); TCameraCtrl::set_camera_id((saddr)this); }

s32 TCameraCtrl::get_camera_no() {
    if (is_split_screen() != 0) {
        return get_camera_mode();
    }
    return local_client_id;
}
