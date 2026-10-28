#include "types.h"
#include "pso/object/TObjFogCollision.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/object/TObjFogCollision.h"

struct RecoveredGlobal_80153FD0___vt__16TObjFogCollision {
    s32 value;
    u8 remaining[0x3C];
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__16TObjFogCollision[];
extern s32 lbl_805D2E78;
u8 *TObjFogCollision__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjFogCollision__create(void *arg0);
void *__dt__16TObjFogCollisionFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

}
TObjFogCollision::~TObjFogCollision() {

}
extern "C" {

extern void *tl_05;

typedef char RecoveredGlobal_80153FD0___vt__16TObjFogCollision_size[sizeof(RecoveredGlobal_80153FD0___vt__16TObjFogCollision) == 0x40 ? 1 : -1];
u8 *TObjFogCollision__ct(u8 *fog_collision, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(fog_collision);
    *(s32 **)((s8 *)fog_collision + 0x18) = &(*(RecoveredGlobal_80153FD0___vt__16TObjFogCollision *)&__vt__16TObjFogCollision).value;
    *(s32 *)((s8 *)fog_collision + 0) = (s32) lbl_805D2E78;
    ((TObjFogCollision *)(fog_collision))->apply_object_set_data((void *)arg2);
    ((TObjFogCollision *)fog_collision)->m_90 = 0;
    ((TObjFogCollision *)fog_collision)->m_94 = 0;
    disallow_rendering__7TObjectFv((TObject *)(fog_collision));
    return fog_collision;
}

void *TObjFogCollision__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjFogCollision__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}
