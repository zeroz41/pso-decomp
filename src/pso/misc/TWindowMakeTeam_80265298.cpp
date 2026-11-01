#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMakeTeam_80265298.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TWindowMakeTeam.h"

extern "C" {

void mem_free(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

extern s32 __vt__15TWindowMakeTeam[];

void *__dt__15TWindowMakeTeamFv(TWindowMakeTeam *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowMakeTeam;
        mem_free(*(void **)((s8 *)arg0 + 0x28));
        mem_free(*(void **)((s8 *)arg0 + 0x24));
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x34)); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2C)))->close(); arg0->m_2c = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
