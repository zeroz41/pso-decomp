#ifndef PSO_UNK_TEXT_800C7FEC_H
#define PSO_UNK_TEXT_800C7FEC_H

#include "types.h"
#include "pso/network/protocol/subcmd_6x.h"

// Floor resource callbacks: reset_camera_override on load,
// restore_cameras_if_overridden on release.
void restore_cameras_if_overridden();
void init_override_params();
void reset_camera_override();

void handle_6x09_legacy_kill_enemy(G_LegacyKillEnemy_6x09 *cmd);

// Game-mode callbacks: clear_legacy_enemy_kill_flags on init,
// release_legacy_enemy_kill_flags on release.
void release_legacy_enemy_kill_flags();
void clear_legacy_enemy_kill_flags();

#endif
