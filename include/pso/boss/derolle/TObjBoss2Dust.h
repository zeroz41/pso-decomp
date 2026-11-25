#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2DUST_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2DUST_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss2Dust : public TObject {
public:
    TObjBoss2Dust(TObject *parent, const Vec *position);
    virtual ~TObjBoss2Dust();
    virtual void run_task();
    virtual void render();
    s32 ticks;
    s32 strip_slot;
    Vec position;
    static const char *name;
};
LAYOUT_ASSERT(TObjBoss2Dust_size, sizeof(TObjBoss2Dust) == 0x30);

// The De Rol Le tunnel scene's hooks: init loads the boss2 common resource and builds the dust
// strips, create spawns the tunnel and the dust controller, free releases them.
void init_boss2_tunnel(void);
void create_boss2_tunnel(void);
void free_boss2_tunnel(void);

#endif
