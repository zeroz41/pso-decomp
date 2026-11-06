#include "types.h"
#include "pso/object/quest/TObjQuestCol2_80196E68.h"
#include "pso/object/quest/TObjQuestColBase_80196BFC.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__13TObjQuestCol2[];

void *__dt__13TObjQuestCol2Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjQuestCol2;
        __dt__16TObjQuestColBaseFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

    extern int quest_collision_warp_pending;
void TQuestColCtrl__sub_80196EC0(void) { quest_collision_warp_pending = 0; }

}
