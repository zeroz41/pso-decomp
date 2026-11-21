#include "types.h"
#include "pso/unk/text_80355C1C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/weapon/TUnk_804F1320.h"

TItem *create_photon_field_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F1320(tl_05, item);
    }
    return NULL;
}
