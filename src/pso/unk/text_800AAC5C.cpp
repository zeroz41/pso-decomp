#include "pso/enemy/TObjEneDubchik.h"
#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/object/TObject_80019A50.h"
struct VBase_800AAC5C { char pad[0x18]; };

struct VObj_800AAC5C : VBase_800AAC5C {
    virtual void m0(int);
};

typedef struct O_800AAC5C {
    u8 pad0[0x18];
    void *vptr;
    u8 pad1c[0x394 - 0x1C];
    void *objs[3];
    u8 pad3A0[0x3A8 - 0x3A0];
    void *f3A8;
    VObj_800AAC5C *f3AC;
} O_800AAC5C;

extern "C" {
void *__dt__15TObjEnemyCustomFv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
extern u8 lbl_804912C8[];
O_800AAC5C *fn_800AAC5C(O_800AAC5C *arg0, s16 arg1);
O_800AAC5C *fn_800AAC5C(O_800AAC5C *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vptr = lbl_804912C8;
        if (arg0->f3A8 != NULL) {
            queue_destruction__7TObjectFv(arg0->f3A8);
        }
        free_collision_body_parts(arg0);
        for (i = 0; i < 3; i++) {
            if (arg0->objs[i] != NULL) {
                queue_destruction__7TObjectFv(arg0->objs[i]);
            }
        }
        if (arg0->f3AC != NULL) {
            arg0->f3AC->m0(1);
        }
        ((TObjEneDubchik *)arg0)->fade.MaterialOpacityFade::~MaterialOpacityFade();
        __dt__15TObjEnemyCustomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
