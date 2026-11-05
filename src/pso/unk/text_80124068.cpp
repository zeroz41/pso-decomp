#include "types.h"
#include "pso/unk/text_80124068.h"

#include "pso/item/TUnk_804A1F20.h"
#include "pso/TMainTask.h"

u8 *create_delsabers_buster_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1F20(tl_05, arg0);
    }
    return NULL;
}
