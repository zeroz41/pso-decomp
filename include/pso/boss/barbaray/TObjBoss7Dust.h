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
LAYOUT_ASSERT(TObjBoss7Dust_size, sizeof(TObjBoss7Dust) == 0x30);

extern "C" {
u8 *__ct__13TObjBoss7DustFv(u8 *object, saddr parent, saddr origin);
void fn_802F105C(void);
void fn_802F1084(void);
}
void init_scene_boss2_tunnel(void);

#endif
