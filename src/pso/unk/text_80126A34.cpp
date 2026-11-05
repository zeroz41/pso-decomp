#include "types.h"
#include "pso/unk/text_80126A34.h"
#include "pso/player/TUnk_804A2B98.h"
#include "pso/TMainTask.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
u8 *create_knuckle_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A2B98(tl_05, arg0);
    }
    return NULL;
}
