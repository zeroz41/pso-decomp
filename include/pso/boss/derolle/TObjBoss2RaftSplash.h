#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2RAFTSPLASH_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2RAFTSPLASH_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/vector.h"

class TObjBoss2RaftSplash : public TObject {
public:
    TObjBoss2RaftSplash(TObject *parent, const Vec *position, const Vec *offset, f32 *speed);
    virtual ~TObjBoss2RaftSplash();
    virtual void run_task();

    // A particle at position whose children drift by offset once handed to the tunnel.
    static void spawn_splash(const Vec *position, s32 particle_index, const Vec *offset);
    f32 elapsed;
    f32 interval;
    const f32 *step;
    Vec position;
    Vec splash_offset;
};

LAYOUT_ASSERT(TObjBoss2RaftSplash_size, sizeof(TObjBoss2RaftSplash) == 0x40);

#endif
