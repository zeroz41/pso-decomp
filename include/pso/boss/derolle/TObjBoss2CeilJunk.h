#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2CEILJUNK_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2CEILJUNK_H

#include <stddef.h>

#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

// A piece of the ceiling that drops during the De Rol Le fight: it falls onto the ground
// spawn_effect finds under it (hitting players on the way) and bounces and fades, or into
// the water when there is none.
struct TObjBoss2CeilJunk : public TObjBase {
    TObjBoss2CeilJunk(TObject *parent, const Vec *position);
    virtual ~TObjBoss2CeilJunk();
    virtual void run_task();
    virtual void render();
    static TObjBoss2CeilJunk *create(const Vec *position);
    static void create_particle(const Vec *position, s32 particle_index);

    // prev_position holds the ground point under it and home_position.y its resting height.
    Vec velocity;
    Vec ground_normal; // spawn_effect's surface normal, the shadow's orientation
    s32 state;         // 0 falling into the water, 1 sinking, 2 falling onto ground, 3 bouncing away
    s32 kind;          // index into the model, height and radius tables
    s32 fade_timer;    // frames since the bounce; it fades out after 10
    f32 alpha;
};

LAYOUT_ASSERT(TObjBoss2CeilJunk_size, sizeof(TObjBoss2CeilJunk) == 0xB8);
LAYOUT_ASSERT(TObjBoss2CeilJunk_velocity_offset, offsetof(TObjBoss2CeilJunk, velocity) == 0x90);
LAYOUT_ASSERT(TObjBoss2CeilJunk_ground_normal_offset, offsetof(TObjBoss2CeilJunk, ground_normal) == 0x9C);

#endif
