#ifndef PSO_OBJECT_TOBJVOLOPTPILLAR_H
#define PSO_OBJECT_TOBJVOLOPTPILLAR_H

#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjChara.h"
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
    virtual void run_task();
    virtual void render();

    static void cache_target_values();
};

typedef char TObjVoloptPillar_size[sizeof(TObjVoloptPillar) == 0xC0 ? 1 : -1];

extern const char *TObjVoloptPillar_name;
extern const DirectAttackPayload volopt_pillar_attack;
extern const Vec volopt_pillar_push;
extern const TObjChipParams volopt_pillar_chip_params;
extern const f64 volopt_pillar_rad_to_angle;


#endif
