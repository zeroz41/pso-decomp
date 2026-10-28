#ifndef PSO_MISC_TBUTTERFLY_H
#define PSO_MISC_TBUTTERFLY_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TButterfly : public TObjBase {
    virtual ~TButterfly();
    u8 unk_90[0xC];
    void* m_9c;
    u8 unk_A0[0x4];
    f32 m_a4;
    u8 unk_A8[0x8];
    f32 m_b0;
    s16 m_b4;
    s16 m_b6;
    u8 m_b8;
    u8 m_b9;
    u8 m_ba;
    void init_motion();
    virtual void render();
    virtual void run_task();
    static void destroy_instance();
    void draw_model();
    u8 unk_BB[0x1];
};

typedef char TButterfly_size[sizeof(TButterfly) == 0xBC ? 1 : -1];

extern "C" {
void *__dt__10TButterflyFv(void *arg0, s16 arg1);
}

#endif
