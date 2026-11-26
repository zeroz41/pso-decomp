#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_80228C84.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/player/PlayerSlots.h"



void refresh_player_status(s32 client_id) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        text_builder_append(player->get_name());
    }
}
