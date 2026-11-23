#ifndef PSO_OBJECT_TOBJBIGTUITATE_H
#define PSO_OBJECT_TOBJBIGTUITATE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjBigTuitate : public TObjCollidable {
    TObjBigTuitate(TObject *parent, void *arg2);
    virtual ~TObjBigTuitate();
    u32 m_c8;
    void render();
    void run_task();
    static void free_instance();
    u8 unk_B0[0x1C];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjBigTuitate_size, sizeof(TObjBigTuitate) == 0xCC);

extern "C" {
void *__dt__14TObjBigTuitateFv(void *arg0, s16 arg1);
}

#endif
