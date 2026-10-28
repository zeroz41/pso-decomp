#include "types.h"
#include "pso/object/TObjMotion.h"

extern "C" {

void *__dt__10TOMineDispFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

extern s32 __vt__10TOMineDisp[];

void *__dt__10TOMineDispFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TOMineDisp;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
