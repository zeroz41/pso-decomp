#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/player/PlayerStatusRefresh.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"

void refresh_player_status(s32 client_id) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        text_builder_append(player->get_name());
    }
}
