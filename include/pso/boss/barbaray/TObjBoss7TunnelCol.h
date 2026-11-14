#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7TUNNELCOL_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7TUNNELCOL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjBoss7TunnelCol : public TObjCollidable {
    virtual ~TObjBoss7TunnelCol();
    CollisionBody collision_body; // copied from TObjBoss7TunnelCol__col_desc, then set_collision_body
    virtual void render();
    virtual void run_task();
    s32 is_in_camera_range();
};

typedef char TObjBoss7TunnelCol_size[sizeof(TObjBoss7TunnelCol) == 0xD8 ? 1 : -1];

extern "C" {
void *TObjBoss7TunnelCol__ct(void *arg0, TObject *parent);
}

#endif
