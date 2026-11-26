#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/memory.h"
#include "pso/system/vector.h"
#include "pso/boss/goldragon/TObjBoss8PillerCtrl.h"
#include "pso/boss/goldragon/TObjBoss8Piller.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

const char *TObjBoss8PillerCtrl::class_name = "TObjBoss8PillerCtrl";

// grid steps around the centre, ring by ring; {0xFFFF, 0xFFFF} closes a ring
const Ent_8035C03C boss8_piller_ctrl_params[41] = {
    {0, 0}, {0xFFFF, 0xFFFF},
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {0xFFFF, 0xFFFF},
    {2, 0}, {-2, 0}, {-1, 1}, {-1, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {0, 2}, {0, -2}, {1, 2}, {1, -2}, {0xFFFF, 0xFFFF},
    {3, 0}, {-3, 0}, {-2, 1}, {-2, -1}, {3, 1}, {3, -1}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}, {-1, 3}, {-1, -3}, {0, 3}, {0, -3}, {1, 3}, {1, -3}, {2, 3}, {2, -3}, {0xFFFF, 0xFFFF},
};

// Written last to first: the unit is generated deferred (see configure.py).

TObjBoss8PillerCtrl::TObjBoss8PillerCtrl(TObject *parent, f32, const Vec *pos, u16 id) : TObject(parent) {
    m_name = TObjBoss8PillerCtrl::class_name;
    VecCopy(&position, pos);
    sub_8035C034(&position);
    position.y = 0.0f;
    frame = 0;
    piller_arg = id;
    buffer = NULL;
    step = boss8_piller_ctrl_params;
}

TObjBoss8PillerCtrl::~TObjBoss8PillerCtrl() {
    if (buffer != NULL) {
        ::operator delete(buffer);
        buffer = NULL;
    }
}

#pragma fp_contract on
void TObjBoss8PillerCtrl::run_task() {
    Vec v;
    switch (frame) {
    case 0:
    case 5:
    case 10:
    case 15:
        while (step->y != 0xFFFF) {
            VecCopy(&v, &position);
            v.x = 37.5f * step->y + v.x;
            v.z = 43.3f * step->x + v.z;
            if (step->y & 1) {
                v.z += -21.65f;
            }
            if (is_outside_arena(&v) == 0) {
                new TObjBoss8Piller(tl_05, &v, 100.0f, piller_arg);
            }
            step++;
        }
        step++;
        break;
    }
    if (frame++ > 0x32) {
        queue_destruction();
    }
}

void TObjBoss8PillerCtrl::render() {  }

void TObjBoss8PillerCtrl::sub_8035C034(Vec *pos) {  }

s32 TObjBoss8PillerCtrl::is_outside_arena(const Vec *pos) {
    Vec position;
    VecCopy(&position, pos);
    return normalize_vector_xz(&position) > 373.0f;
}
