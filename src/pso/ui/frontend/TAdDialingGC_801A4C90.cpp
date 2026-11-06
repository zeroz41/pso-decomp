#include "types.h"
#include "pso/ui/frontend/TAdDialingGC_801A4C90.h"
#include "pso/unk/TUnk_804C2298.h"
#include "pso/ui/frontend/TAdDialingGC.h"

    extern int player_action_provider_selector;
void TAdDialingGC__sub_801A4C90(void) { player_action_provider_selector = 1; }

extern s32 TAdDialingGC__instance;

s32 TAdDialingGC__sub_801A4C9C(void) {
    return TAdDialingGC__instance;
}

void TUnk_804C2298::sub_801A4CA4() {

    switch (this->m_20) {
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
void TUnk_804C2298::render() {  }
