#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/text_800C7FEC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/TObjControl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

static s32 camera_override_active;
static f32 unused_param_0;
static f32 unused_param_1;
static s32 unused_param_2;
static s32 unused_param_3;
static f32 unused_param_4;

static s32 legacy_enemy_kill_received[128];

void restore_cameras_if_overridden() {
    if (camera_override_active != 0) {
        restore_player_cameras();
    }
}

// dead-stripped: only its literals survive. This unit's .sdata2 pool holds 0.0f, 50.0f, 15.0f in
// that order, but init_override_params, the only live user, loads 50.0f first: a stripped function
// before it made 0.0f. Minimal body after init_override_params' store; name inferred.
static void clear_override_param_1() {
    unused_param_1 = 0.0f;
}

void init_override_params() {
    unused_param_0 = 50.0f;
    unused_param_2 = 0;
    unused_param_3 = 0;
    unused_param_1 = 0.0f;
    unused_param_4 = 15.0f;
}

void reset_camera_override() {
    camera_override_active = 0;
    init_override_params();
}

void handle_6x09_legacy_kill_enemy(G_LegacyKillEnemy_6x09 *cmd) {
    bswap_client_id_header((G_ClientIDHeader *)cmd);
    u16 id = cmd->header.entity_id;
    if (legacy_enemy_kill_received[id] == 0) {
        legacy_enemy_kill_received[id] = 1;
        TObjBase *enemy = (TObjBase *)get_enemy_entity(id);
        if (enemy != NULL) {
            enemy->actorFlags |= 0x800;
        }
    }
}

void release_legacy_enemy_kill_flags() {
}

void clear_legacy_enemy_kill_flags() {
    s32 i;
    for (i = 0; i < 128; i++) {
        legacy_enemy_kill_received[i] = 0;
    }
}

void bswap_client_id_header(G_ClientIDHeader *header) { header->bswap(); }
