#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7RAFTSPLASH_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7RAFTSPLASH_H

#include "pso/system/vector.h"

class TParticleCtrl;
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TObjBoss7RaftSplash : public TObject {
public:
    TObjBoss7RaftSplash(TObject *parent, const Vec *position, const Vec *offset, f32 *speed);
    virtual ~TObjBoss7RaftSplash();
    virtual void run_task();

    // Twin of TObjBoss2RaftSplash::spawn_splash.
    static void spawn_splash(const Vec *position, s32 particle_index, const Vec *offset);
    // Twin of TObjBoss2RaftSplash::create_particle_effect.
    static void create_particle_effect(const Vec *position, s32 particle_index, f32 speed);
    // Twins of TObjBoss2CeilJunk::create_particle and TObjBoss2RaftSplash::release_splash_children: the
    // same with speed -5.
    static void create_particle(const Vec *position, s32 particle_index);
    static void release_splash_children(TParticleCtrl *particle);
    f32 elapsed;
    f32 interval;
    const f32 *step;
    Vec position;
    Vec splash_offset;
    static const char *name;
};

LAYOUT_ASSERT(TObjBoss7RaftSplash_size, sizeof(TObjBoss7RaftSplash) == 0x40);

#endif
