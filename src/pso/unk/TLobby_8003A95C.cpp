#include "types.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/derolle/TObjBoss2DustCtrl.h"
#include "pso/unk/TLobby_8003A95C.h"
#include "pso/boss/derolle/TObjBoss2Dust.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"


void TLobby::init_boss2_stage() { TObjBoss2DustCtrl::free_strips(); TObjBoss2Tunnel::sub_8003C648(); free_boss2_common_resource(); }
void TLobby::create_boss2_tunnel() { TObjBoss2Tunnel::create(); TObjBoss2Tunnel::create_parent_object(); TObjBoss2DustCtrl::create(); }
void TLobby__sub_8003A9AC(void) { load_boss2_common_resource(); TObjBoss2Tunnel::clear_target_flags(); TObjBoss2DustCtrl::init_strips(); }
void TObjBoss2Dust::render() { boss2_dust_draw_at(&position, strip_slot); }

