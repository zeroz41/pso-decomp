#include "types.h"
#include "pso/camera/TCameraCtrl_801A3C24.h"
#include "pso/unk/TLobby_801A3B84.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"

void TAdSelectGameModeGC::enable_camera() { TLobby__sub_801A3B90(1); TCameraCtrl__sub_801A3C30(1); TCameraCtrl__sub_801A3C24(); }

void TAdSelectGameModeGC::free_sub_ctrls() { TLobby__sub_801A3B90((saddr)this); TCameraCtrl__sub_801A3C30((saddr)this); }
