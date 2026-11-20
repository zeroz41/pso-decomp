#ifndef PSO_OBJECT_MINE_TOLIGHTMACHINE01_H
#define PSO_OBJECT_MINE_TOLIGHTMACHINE01_H

#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOLightMachine01 : public TObjBase {
    TOLightMachine01(void *arg1);
    virtual ~TOLightMachine01();
    f32 view_range;
    f32 m_94;
    f32 bob_amplitude;
    f32 m_9c;
    f32 bob_speed;
    u32 m_a4;
    u32 m_a8;
    u32 m_ac;
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    static void destroy_instance();
    static void load_assets();
};

typedef char TOLightMachine01ViewRangeOffset[offsetof(TOLightMachine01, view_range) == 0x90 ? 1 : -1];
typedef char TOLightMachine01_size[sizeof(TOLightMachine01) == 0xB0 ? 1 : -1];

extern "C" {
void *__dt__16TOLightMachine01Fv(void *arg0, s16 arg1);
}

#endif
