#include "types.h"
#include "pso/misc/TORockCaveM01.h"
#include "pso/unk/text_80174AB4.h"
#include "pso/object/TObjMotion.h"

extern "C" {

s32 __dl__7TObjectFPv(void *);
void *__dt__10TORockCaveFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 free_collision_body_parts(void *);

void *TORockCaveM01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TORockCaveM01__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

extern s32 __vt__13TORockCaveM01[];

void *__dt__13TORockCaveM01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TORockCaveM01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__10TORockCaveFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
