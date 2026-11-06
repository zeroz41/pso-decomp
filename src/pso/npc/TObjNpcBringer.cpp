#include "types.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/npc/TObjNpcBringer_8014952C.h"

extern "C" {

void *__dt__14TObjNpcBringerFv(void *arg0, s16 arg1);
void *__ct__11TObjControlFP7TObject(void *, void *);
void __dl__7TObjectFPv(void *);
void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

extern void *tl_04;

void *TObjNpcBringer::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcBringer__ct((u8 *)o2, o, (s32)arg0);
    }
    return o2;
}

extern s32 __vt__14TObjNpcBringer[];

void *__dt__14TObjNpcBringerFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjNpcBringer;
        __dt__11TObjNpcBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
