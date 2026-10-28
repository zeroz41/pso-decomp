#include "pso/protocol/protocol_types.h"
#include "pso/unk/text_800C7FEC.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjControl.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

static s32 camera_override_active;
static f32 unused_param_0;
static f32 unused_param_1;
static s32 unused_param_2;
static s32 unused_param_3;
static f32 unused_param_4;

static s32 legacy_enemy_kill_received[128];

// This unit's .sdata2 pool holds 0.0f, 50.0f, 15.0f in that order, while
// init_override_params stores 50.0f first; no store order of plain literals
// gives both, so the pool stays outside the unit and is named here.
extern "C" {
extern const f32 lbl_805DA098;
extern const f32 lbl_805DA09C;
extern const f32 lbl_805DA0A0;
}

void restore_cameras_if_overridden() {
    if (camera_override_active != 0) {
        restore_player_cameras();
    }
}

void init_override_params() {
    unused_param_0 = lbl_805DA09C;
    unused_param_2 = 0;
    unused_param_3 = 0;
    unused_param_1 = lbl_805DA098;
    unused_param_4 = lbl_805DA0A0;
}

void reset_camera_override() {
    camera_override_active = 0;
    init_override_params();
}

void handle_6x09_legacy_kill_enemy(G_LegacyKillEnemy_6x09 *cmd) {
    ((TLobby *)cmd)->bswap_packet_header();
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

void TLobby::bswap_packet_header() { ((G_ClientIDHeader *)this)->bswap(); }
