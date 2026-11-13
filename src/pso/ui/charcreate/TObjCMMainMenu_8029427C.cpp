#include "types.h"
#include "pso/ui/charcreate/TChCrEffFade.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"

void *TObjCMMainMenu::create_fade(void *arg0, void *arg1) {
    return new TChCrEffFade(-1, (s32)arg0, (s32)arg1);
}

void *TObjCMMainMenu::create_fade_effect(void *arg0, void *arg1) {
    return new TChCrEffFade(1, (s32)arg0, (s32)arg1);
}
