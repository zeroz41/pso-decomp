#include "types.h"
#include "pso/enemy/moja/TObjEneMoja_800AF56C.h"
struct TObjEnemy;
#include "pso/system/task/TObject_80019A50.h"

extern "C" {
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(s32);
s32 __destroy_arr(void *, void *, int, int);
extern s32 __dt__15RenderFadeStateFv[];
extern s32 __vt__11TObjEneMoja[];
u8 *__dt__11TObjEneMojaFv(u8 *arg0, s16 arg1) {
    u8 *object;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjEneMoja;
        object = (u8 *)(*(u8 **)((s8 *)arg0 + 0x398));
        if (object != NULL) {
            queue_destruction__7TObjectFv(object);
            *(u8 **)((s8 *)arg0 + 0x398) = NULL;
        }
        free_collision_body_parts(arg0);
        __destroy_arr(arg0 + 0x39C, __dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}
