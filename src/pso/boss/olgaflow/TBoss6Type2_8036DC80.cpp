#include "types.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

// One client's look as the Olga Flow fight starts; free_chara_making puts it back.
struct Boss6PlayerSnapshot {
    s32 active;
    Boss6PlayerLook look;
};

Boss6PlayerSnapshot boss6_type2_player_snapshot_table[4] = { 0 };

void restore_boss6_player_snapshot(TObjPlayer *player) {
    u16 client_id;
    Boss6PlayerSnapshot *snapshot;

    client_id = player->get_entity_id();
    if (client_id < 4U) {
        snapshot = &boss6_type2_player_snapshot_table[client_id];
        if (snapshot->active != 0) {
            snapshot->active = 0;
            if (TBoss6PlotFalz::is_state_1f(player) != 0) {
                copy_texlist(&player->body_textures, &snapshot->look.body_textures);
                copy_texlist((NJS_TEXLIST *)player->head_textures, &snapshot->look.head_textures);
                copy_texlist((NJS_TEXLIST *)player->attachment_textures, &snapshot->look.attachment_textures);
                player->model = snapshot->look.model;
                player->head_model = snapshot->look.head_model;
                player->hair_model = snapshot->look.hair_model;
                player->attachment_model = snapshot->look.attachment_model;
            }
        }
    }
}

void capture_boss6_player_snapshots() {
    s32 i;
    Boss6PlayerSnapshot *snapshot;
    TObjPlayer *player;
    for (i = 0; i < 4; i++) {
        snapshot = &boss6_type2_player_snapshot_table[i];
        snapshot->active = 0;
        player = get_player_by_client_id(i);
        if (player != NULL && TBoss6PlotFalz::is_state_1f(player) != 0) {
            copy_texlist(&snapshot->look.body_textures, &player->body_textures);
            copy_texlist(&snapshot->look.head_textures, (NJS_TEXLIST *)player->head_textures);
            copy_texlist(&snapshot->look.attachment_textures, (NJS_TEXLIST *)player->attachment_textures);
            snapshot->look.model = player->model;
            snapshot->look.head_model = player->head_model;
            snapshot->look.hair_model = player->hair_model;
            snapshot->look.attachment_model = player->attachment_model;
            snapshot->active = 1;
        }
    }
}

void clear_boss6_player_snapshots(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        boss6_type2_player_snapshot_table[i].active = 0;
    }
}
