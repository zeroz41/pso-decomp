#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/memory.h"
#include "pso/system/vector.h"
#include "pso/boss/goldragon/TObjBoss8PillerCtrl.h"
#include "pso/system/task/TObject.h"

struct Ent_8035C03C { s32 x; s32 y; };

struct Self_8035C03C {
    u8 pad0[0x1c];
    Vec pos;
    s32 f28;
    u16 f2C;
    u8 pad2e[0x34 - 0x2e];
    const Ent_8035C03C *list;
};

#pragma readonly_strings on

const char *TObjBoss8PillerCtrl__class_name = "TObjBoss8PillerCtrl";

// grid steps around the centre, ring by ring; {0xFFFF, 0xFFFF} closes a ring
const Ent_8035C03C boss8_piller_ctrl_params[41] = {
    {0, 0}, {0xFFFF, 0xFFFF},
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {0xFFFF, 0xFFFF},
    {2, 0}, {-2, 0}, {-1, 1}, {-1, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {0, 2}, {0, -2}, {1, 2}, {1, -2}, {0xFFFF, 0xFFFF},
    {3, 0}, {-3, 0}, {-2, 1}, {-2, -1}, {3, 1}, {3, -1}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}, {-1, 3}, {-1, -3}, {0, 3}, {0, -3}, {1, 3}, {1, -3}, {2, 3}, {2, -3}, {0xFFFF, 0xFFFF},
};

extern "C" {
s32 __ct__7TObjectFP7TObject();
extern s32 __vt__19TObjBoss8PillerCtrl[];
void __ct__15TObjBoss8PillerFv(void *, s32, Vec *, f32, u16);
extern s32 tl_05;
void run_task__19TObjBoss8PillerCtrlFv(Self_8035C03C *self);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

s32 fn_8035BFF8(void *self, const Vec *pos) {
    Vec position;
    VecCopy(&position, (const Vec *)pos);
    return normalize_vector_xz(&position) > 373.0f;
}

void TObjBoss8PillerCtrl__sub_8035C034(void * _w0, void * _w1) {  }
void TObjBoss8PillerCtrl::render() {  }

#pragma fp_contract on
void run_task__19TObjBoss8PillerCtrlFv(Self_8035C03C *self) {
    Vec v;
    void *p;
    switch (self->f28) {
    case 0:
    case 5:
    case 10:
    case 15:
        while (self->list->y != 0xFFFF) {
            VecCopy((Vec *)&v, (const Vec *)&self->pos);
            v.x = 37.5f * self->list->y + v.x;
            v.z = 43.3f * self->list->x + v.z;
            if (self->list->y & 1) {
                v.z += -21.65f;
            }
            if (fn_8035BFF8(self, &v) == 0) {
                p = TObject::operator new(0x34);
                if (p != NULL) {
                    __ct__15TObjBoss8PillerFv(p, tl_05, &v, 100.0f, self->f2C);
                }
            }
            self->list++;
        }
        self->list++;
        break;
    }
    if (self->f28++ > 0x32) {
        ((TObject *)self)->queue_destruction();
    }
}

void *__dt__19TObjBoss8PillerCtrlFv(void *boss8_piller_ctrl, s16 arg1) {
    if (boss8_piller_ctrl != NULL) {
        *(s32 **)((s8 *)boss8_piller_ctrl + 0x18) = __vt__19TObjBoss8PillerCtrl;
        if (*(void **)((s8 *)boss8_piller_ctrl + 0x30) != NULL) { ::operator delete(*(void **)((s8 *)boss8_piller_ctrl + 0x30)); ((TObjBoss8PillerCtrl *)boss8_piller_ctrl)->m_30 = 0; }
        __dt__7TObjectFv(boss8_piller_ctrl, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(boss8_piller_ctrl);
        }
    }
    return boss8_piller_ctrl;
}
u8 *TObjBoss8PillerCtrl__ct(u8 *boss8_piller_ctrl, s32 arg1, s32 arg2, s16 arg3) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)boss8_piller_ctrl + 0x18) = __vt__19TObjBoss8PillerCtrl;
    ((TObject *)boss8_piller_ctrl)->m_name = TObjBoss8PillerCtrl__class_name;
    VecCopy((Vec *)(boss8_piller_ctrl + 0x1C), (const Vec *)(arg2));
    TObjBoss8PillerCtrl__sub_8035C034(boss8_piller_ctrl, boss8_piller_ctrl + 0x1C);
    *(f32 *)((s8 *)boss8_piller_ctrl + 0x20) = 0.0f;
    ((TObjBoss8PillerCtrl *)boss8_piller_ctrl)->m_28 = 0;
    ((TObjBoss8PillerCtrl *)boss8_piller_ctrl)->m_2c = arg3;
    ((TObjBoss8PillerCtrl *)boss8_piller_ctrl)->m_30 = 0;
    ((Self_8035C03C *)boss8_piller_ctrl)->list = boss8_piller_ctrl_params;
    return boss8_piller_ctrl;
}

}
