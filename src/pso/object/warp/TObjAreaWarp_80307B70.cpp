#include "types.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/player/PlayerCommands.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"

// The entity id of the first player whose bit is clear in confirmed_mask & in_range_mask, or 0.
s32 WarpPartyCheck::find_active_player() {
    u32 present_mask;
    s32 client;
    TObjPlayer *player;

    if (all_in_range != 0) {
        present_mask = confirmed_mask & in_range_mask;
        for (client = 0; client < 4; client++) {
            if (!((present_mask >> client) & 1) && (player = get_player_by_client_id(client)) != NULL) {
                return player->get_entity_id();
            }
        }
    }
    return (u16)0;
}
