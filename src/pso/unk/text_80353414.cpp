#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_804F112C.h"

TUnk_804F112C *TUnk_804F112C::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F112C(tl_05, item);
    }
    return NULL;
}
