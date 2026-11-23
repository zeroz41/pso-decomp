#include "types.h"
#include "pso/ui/charcreate/TChCrEffFade.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"

void *TObjCMMainMenu::create_fade(void *duration, void *mode) {
    return new TChCrEffFade(-1, (saddr)duration, (saddr)mode);
}

void *TObjCMMainMenu::create_fade_effect(void *duration, void *mode) {
    return new TChCrEffFade(1, (saddr)duration, (saddr)mode);
}
