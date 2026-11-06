#include "types.h"
#include "pso/ui/TChCrEffFade.h"
#include "pso/object/TObjCMMainMenu.h"

extern "C" {

void *__nw__7TObjectFUl(int);

void *TObjCMMainMenu::create_fade(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = __ct__12TChCrEffFadeFlll(o, -1, (s32)arg0, (s32)arg1);
    }
    return o;
}

void *TObjCMMainMenu::create_fade_effect(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = __ct__12TChCrEffFadeFlll(o, 1, (s32)arg0, (s32)arg1);
    }
    return o;
}

}
