#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7DUST_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7DUST_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss7Dust : public TObject {
public:
    virtual ~TObjBoss7Dust();
    virtual void run_task();
    virtual void render();
    s32 ticks;
    s32 strip_slot;
    Vec position;
};
typedef char TObjBoss7Dust_size[sizeof(TObjBoss7Dust) == 0x30 ? 1 : -1];

extern "C" {
u8 *__ct__13TObjBoss7DustFv(u8 *arg0, s32 arg1, s32 arg2);
void fn_802F105C(void);
void fn_802F1084(void);
}
void init_scene_boss2_tunnel(void);

// --- C functions defined in TObjBoss7Dust.cpp ---
extern "C" {
void fn_802F105C(void);
void fn_802F1084(void);
}
// --- end of C functions

#endif
