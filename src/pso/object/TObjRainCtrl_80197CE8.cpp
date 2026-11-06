#include "types.h"
#include "pso/object/TObjRainCtrl.h"
#include "pso/misc/TRaderMapCore.h"

extern "C" {

void *__nw__7TObjectFUl(s32);

extern void *tl_particle;

void TObjRainCtrl::create() {
    void *temp_r3;

    if (TRaderMapCore::is_not_split_screen() == 0) {
        temp_r3 = __nw__7TObjectFUl(0x20);
        if (temp_r3 != 0) {
            TObjRainCtrl__ct(temp_r3, tl_particle);
        }
    }
}

}
