#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2DUST_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2DUST_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss2Dust : public TObject {
public:
    virtual ~TObjBoss2Dust();
    virtual void run_task();
    virtual void render();
    s32 ticks;
    s32 strip_slot;
    Vec position;
};
typedef char TObjBoss2Dust_size[sizeof(TObjBoss2Dust) == 0x30 ? 1 : -1];

extern "C" {
u8 *__ct__13TObjBoss2DustFv(u8 *object, s32 arg1, s32 arg2);
}

#endif
