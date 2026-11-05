#include "types.h"
#include "pso/unk/text_80121318.h"
#include "pso/item/TUnk_804A07C0.h"
#include "pso/TMainTask.h"

extern "C" {
u8 *TObjPlayer__sub_80121318(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A07C0(tl_05, arg0);
    }
    return NULL;
}

}
