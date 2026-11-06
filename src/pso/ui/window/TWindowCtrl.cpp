#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"

void TWindowCtrl::render() {  }
void TWindowCtrl::run_task() { update_open_sequence(); update(); TLobby::update_game_modes(); }
