#include "types.h"
#include "pso/player/TObjPlayer.h"

#include "pso/item/TUnk_804A1288.h"
#include "pso/TMainTask.h"

u8 *TObjPlayer::create_vtable_804a1288(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1288(tl_05, arg0);
    }
    return NULL;
}
