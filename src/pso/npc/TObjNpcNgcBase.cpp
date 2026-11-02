#include "types.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcLappy.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__14TObjNpcNgcBase[];

void *__dt__14TObjNpcNgcBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjNpcNgcBase;
        __dt__13TUnk_804A9F50Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
