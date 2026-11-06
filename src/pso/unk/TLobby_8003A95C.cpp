#include "types.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/derolle/TObjBoss2DustCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8003B138.h"
#include "pso/unk/TLobby_8003A95C.h"
#include "pso/boss/derolle/TObjBoss2Dust.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"


void TLobby::init_boss2_stage() { TObjBoss2DustCtrl__sub_8003AD50(); TObjBoss2Tunnel__sub_8003C648(); TLobby__sub_8003A874(); }
void TLobby::create_boss2_tunnel() { TObjBoss2Tunnel::create(); TObjBoss2Tunnel__sub_8003B2B0(); TObjBoss2DustCtrl::create(); }
void TLobby__sub_8003A9AC(void) { TLobby__sub_8003A8D0(); TObjBoss2Tunnel::clear_target_flags(); fn_8003AD54(); }
void TObjBoss2Dust::render() { boss2_dust_draw_at((s32 *)((char*)this + 0x24), (s32)(*(void**)((char*)this + 0x20))); }

