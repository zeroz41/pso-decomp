#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2CEILJUNK_8003A81C_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2CEILJUNK_8003A81C_H

#include "types.h"

// Shared by the Boss2 dust, raft splash and tunnel objects: TObjBoss2Tunnel clamps its
// scroll speed (f20) to it and the dust/splash objects drift by it each frame.
extern const f32 boss2_tunnel_max_scroll_speed;

// --- C functions defined in TObjBoss2CeilJunk_8003A81C.cpp ---
extern "C" {
void TLobby__sub_8003A874(void);
}
void load_boss2_common_resource(void);
extern "C" {
void __sinit_TObjBoss2CeilJunk_8003A81C_cpp(void);
}
// --- end of C functions

#endif
