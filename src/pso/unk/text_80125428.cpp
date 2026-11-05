#include "types.h"
#include "pso/unk/text_80125428.h"
#include "pso/player/TUnk_804A2450.h"
#include "pso/TMainTask.h"

extern "C" {
u8 *TObjPlayer__sub_80125428(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A2450(tl_05, arg0);
    }
    return NULL;
}

}
