#include "types.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"

void TWindowKeyBoardBase::update_close_mode() {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        composition_flags = 5;
        break;
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        composition_flags = 6;
        break;
    }
}
