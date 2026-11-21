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

void init_scene_boss2_tunnel(void);
// Twins of TLobby::create_boss2_tunnel and TLobby::init_boss2_stage (which frees the boss2
// common resource): the Barba Ray tunnel scene's create and free hooks.
void create_boss7_tunnel(void);
void free_boss7_tunnel(void);

#endif
