#include "types.h"
#include "pso/ui/frontend/TAdDialingGC_801A4C90.h"
#include "pso/unk/TAdDialingSelectGC.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/player/PlayerActionProvider.h"

void select_game_player_actions(void) { player_action_provider_selector = 1; }

TAdDialingGC *TAdDialingGC::get_instance(void) {
    return TAdDialingGC::instance;
}

void TAdDialingSelectGC::update_dial_image() {
    switch (this->selection) {
    case 0:
        TAdDialingGC::select_dial_image((void *)1, 0);
        return;
    case 1:
        TAdDialingGC::select_dial_image((void *)0, 0);
        return;
    case 2:
        TAdDialingGC::select_dial_image((void *)1, 1);
        return;
    case 3:
        TAdDialingGC::select_dial_image((void *)0, 1);
    case 4:
        return;
    }
}

void TAdDialingSelectGC::render() {}
