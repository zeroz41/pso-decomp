#include "types.h"
#include "pso/unk/text_802F1F58.h"

extern "C" {

void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
extern s32 __vt__13TUnk_804E4B24[];

void *__dt__13TUnk_804E4B24Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804E4B24;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
