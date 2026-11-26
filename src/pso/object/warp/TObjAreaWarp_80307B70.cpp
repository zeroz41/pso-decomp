#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"

// The entity id of the first player whose bit is clear in the warp's present_mask, or 0.
s32 TObjAreaWarp::find_active_player() {
    u32 present_mask;
    s32 client;
    TObjPlayer *player;

    if ((saddr)m_down != 0) {
        present_mask = *(u32 *)&entity_id & m_20;
        for (client = 0; client < 4; client++) {
            if (!((present_mask >> client) & 1) && (player = get_player_by_client_id(client)) != NULL) {
                return player->get_entity_id();
            }
        }
    }
    return (u16)0;
}
