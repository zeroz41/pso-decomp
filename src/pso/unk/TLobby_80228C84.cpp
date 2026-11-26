#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_80228C84.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/player/PlayerSlots.h"



void refresh_player_status(s32 client_id) {
    struct VObj_80228C84 *o = (struct VObj_80228C84 *)get_player_by_client_id(client_id);
    if (o != NULL) {
        text_builder_append(o->m10());
    }
}
