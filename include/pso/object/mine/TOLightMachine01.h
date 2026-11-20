#ifndef PSO_OBJECT_MINE_TOLIGHTMACHINE01_H
#define PSO_OBJECT_MINE_TOLIGHTMACHINE01_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOLightMachine01 : public TObjBase {
    virtual ~TOLightMachine01();
    u8 unk_90[0x4];
    f32 m_94;
    u8 unk_98[0x4];
    f32 m_9c;
    u8 unk_A0[0x4];
    u32 m_a4;
    u32 m_a8;
    u32 m_ac;
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    static void destroy_instance();
    static void load_assets();
};

LAYOUT_ASSERT(TOLightMachine01_size, sizeof(TOLightMachine01) == 0xB0);

extern "C" {
u8 *TOLightMachine01__ct(TOLightMachine01 *arg0, saddr arg1);
void *__dt__16TOLightMachine01Fv(void *arg0, s16 arg1);
}

#endif
