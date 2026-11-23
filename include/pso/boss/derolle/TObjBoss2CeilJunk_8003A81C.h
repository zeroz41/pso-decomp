#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2CEILJUNK_8003A81C_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2CEILJUNK_8003A81C_H

#include "types.h"

struct BmlResource;
struct NJS_TEXLIST;

// bm_obj_boss2_common.bml (rocks, tunnel segments, water) and its texture list, loaded by
// load_boss2_common_resource and drawn by TObjBoss2CeilJunk and TObjBoss2Tunnel.
extern BmlResource *boss2_common_resource;
extern NJS_TEXLIST *boss2_common_texture_list;

// Shared by the Boss2 dust, raft splash and tunnel objects: TObjBoss2Tunnel clamps its
// scroll speed (f20) to it and the dust/splash objects drift by it each frame.
extern const f32 boss2_tunnel_max_scroll_speed;

// --- C functions defined in TObjBoss2CeilJunk_8003A81C.cpp ---
// Twin of free_boss7_common_resources: clears boss2_dermt_slot_table and frees what
// load_boss2_common_resource loaded; called by TLobby::init_boss2_stage.
void free_boss2_common_resource(void);
void load_boss2_common_resource(void);
extern "C" {
void __sinit_TObjBoss2CeilJunk_8003A81C_cpp(void);
}
// --- end of C functions

#endif
