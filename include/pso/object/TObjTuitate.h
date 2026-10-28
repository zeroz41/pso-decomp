#ifndef PSO_OBJECT_TOBJTUITATE_H
#define PSO_OBJECT_TOBJTUITATE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjTuitate : public TObjCollidable {
    virtual ~TObjTuitate();
    u32 m_c8;
    void render();
    void run_task();
    u8 unk_B0[0x1C];
};

typedef char TObjTuitate_size[sizeof(TObjTuitate) == 0xCC ? 1 : -1];

extern "C" {
void *TObjTuitate__create(void *arg0);
void *TObjTuitate__ct(void *arg0, void *arg1, void *arg2);
void *__dt__11TObjTuitateFv(void *arg0, s16 arg1);
void fn_8019B09C(void);
}

#endif
