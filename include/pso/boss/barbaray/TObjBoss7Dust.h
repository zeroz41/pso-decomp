#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7DUST_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7DUST_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss7Dust : public TObject {
public:
    TObjBoss7Dust(TObject *parent, const Vec *position);
    virtual ~TObjBoss7Dust();
    virtual void run_task();
    virtual void render();
    s32 ticks;
    s32 strip_slot;
    Vec position;
};
LAYOUT_ASSERT(TObjBoss7Dust_size, sizeof(TObjBoss7Dust) == 0x30);

// Twins of init_boss2_tunnel, create_boss2_tunnel and free_boss2_tunnel: the Barba Ray tunnel
// scene's init, create and free hooks.
void init_boss7_tunnel(void);
void create_boss7_tunnel(void);
void free_boss7_tunnel(void);

#endif
