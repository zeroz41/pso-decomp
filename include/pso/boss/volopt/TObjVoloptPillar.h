#ifndef PSO_BOSS_VOLOPT_TOBJVOLOPTPILLAR_H
#define PSO_BOSS_VOLOPT_TOBJVOLOPTPILLAR_H

#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include <dolphin/mtx.h>

// A pillar Vol Opt drops on the floor: it waits, crashes down, damages and
// pushes away every actor it hits, then rises out of sight.
class TObjVoloptPillar : public TObjCollidable {
public:
    s32 state;
    u8 pad_b0[0x4];
    s32 timer;
    f32 start_y;
    TObject *owner;

    TObjVoloptPillar(Vec *pos, TObject *owner);
    virtual ~TObjVoloptPillar();
    void spawn_debris_chips();
    virtual void run_task();
    virtual void render();

    static void cache_target_values();
};

LAYOUT_ASSERT(TObjVoloptPillar_size, sizeof(TObjVoloptPillar) == 0xC0);

extern const char *TObjVoloptPillar_name;
extern const DirectAttackPayload volopt_pillar_attack;
extern const Vec volopt_pillar_push;


#endif
