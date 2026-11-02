#include "types.h"
#include "pso/npc/TObjNpcLappy_8014B840.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcLappy.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1);

    extern int npc_lappy_cached_object;
    extern int lbl_805D5D78;
void TObjNpcLappy__sub_8014B840(void) { npc_lappy_cached_object = lbl_805D5D78; }

extern s32 lbl_804A9F50[];

void *__dt__13TUnk_804A9F50Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A9F50;
        __dt__11TObjNpcBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
