#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

void TLobby::reset_player_state() {
    end_primitive_draw();
}
