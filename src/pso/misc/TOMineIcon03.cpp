#include "types.h"
#include "pso/unk/text_80171A98.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOMineIcon03.h"

extern "C" {

s32 __dl__7TObjectFPv(void *);
void *__dt__6TOMineFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 free_collision_body_parts(void *);

extern void *tl_05;

void *TOMineIcon03::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x37C);
    if (o != NULL) {
        o = TOMineIcon03__ct(o, tl_05, arg0);
    }
    return o;
}

extern s32 __vt__12TOMineIcon03[];

void *__dt__12TOMineIcon03Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOMineIcon03;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__6TOMineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
