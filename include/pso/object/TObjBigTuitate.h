#ifndef PSO_OBJECT_TOBJBIGTUITATE_H
#define PSO_OBJECT_TOBJBIGTUITATE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjBigTuitate : public TObjCollidable {
    virtual ~TObjBigTuitate();
    u32 m_c8;
    void render();
    void run_task();
    static void free_instance();
    u8 unk_B0[0x1C];
};

typedef char TObjBigTuitate_size[sizeof(TObjBigTuitate) == 0xCC ? 1 : -1];

extern "C" {
void *TObjBigTuitate__create(void *arg0);
void *TObjBigTuitate__ct(void *arg0, void *arg1, void *arg2);
void *__dt__14TObjBigTuitateFv(void *arg0, s16 arg1);
}

#endif
