#include "types.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

extern "C" {

int get_selection__19TWindowSubTechniqueFPsPll(void*, void* a1 = 0);

s32 TWindowSubTechnique::update_selection(s16 *arg0, s32 *arg1) {
    s32 spC;
    s16 sp8;

    get_selection__19TWindowSubTechniqueFPsPll(&sp8, &spC);
    if ((sp8 == (s16) *arg0) && (spC == (s32) *arg1)) {
        return 0;
    }
    *arg0 = sp8;
    *arg1 = spC;
    return 1;
}

}
