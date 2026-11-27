#include "types.h"
#include "pso/unk/TAdDialingSelectGC.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/system/SwitcherLaunch.h"

void select_game_player_actions(void) { player_action_provider_selector = 1; }

TAdDialingGC *TAdDialingGC::get_instance(void) {
    return TAdDialingGC::instance;
}

void TAdDialingSelectGC::update_dial_image() {
    switch (this->selection) {
    case 0:
        select_dial_image(1, 0);
        return;
    case 1:
        select_dial_image(0, 0);
        return;
    case 2:
        select_dial_image(1, 1);
        return;
    case 3:
        select_dial_image(0, 1);
    case 4:
        return;
    }
}

void TAdDialingSelectGC::render() {}
