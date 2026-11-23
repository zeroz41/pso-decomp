#ifndef PSO_OBJECT_AMBIENT_TBUTTERFLY_H
#define PSO_OBJECT_AMBIENT_TBUTTERFLY_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TButterfly : public TObjBase {
    TButterfly(TObject *parent, void *arg2);
    virtual ~TButterfly();
    u8 unk_90[0xC];
    void* m_9c;
    u8 unk_A0[0x4];
    f32 m_a4;
    f32 motion_frame; // frame passed to draw_ginja_model_with_motion, randomised by the ctor (name inferred)
    u8 unk_AC[0x4];
    f32 m_b0;
    s16 m_b4;
    s16 m_b6;
    u8 m_b8;
    u8 m_b9;
    u8 m_ba;
    void init_motion();
    virtual void render();
    virtual void run_task();
    static void load_resources();
    static void destroy_instance();
    void draw_model();
    u8 unk_BB[0x1];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TButterfly_size, sizeof(TButterfly) == 0xBC);

extern "C" {
void *__dt__10TButterflyFv(void *arg0, s16 arg1);
}

extern "C" {
void *__ct__10TButterflyFP7TObjectPv(void *butterfly, void *arg1, void *arg2);
}

#endif
