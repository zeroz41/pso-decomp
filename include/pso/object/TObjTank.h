#ifndef PSO_OBJECT_TOBJTANK_H
#define PSO_OBJECT_TOBJTANK_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjTank : public TObjCollidable {
    virtual ~TObjTank();
    virtual void render();
    virtual void run_task();
    static void free_globals();
    static void load_globals();
};

typedef char TObjTank_size[sizeof(TObjTank) == 0xAC ? 1 : -1];

extern "C" {
void *TObjTank__create(void *arg0);
u8 *TObjTank__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__8TObjTankFv(void *arg0, s16 arg1);
}

#endif
