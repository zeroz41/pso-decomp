#ifndef PSO_TECHNIQUE_TFIREEXPLOSION_H
#define PSO_TECHNIQUE_TFIREEXPLOSION_H
#include "types.h"
#include <stddef.h>
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

struct TEffIndirect;

// Fire explosion (Rafoie's blast, also used by enemy and weapon fire): a
// growing fireball with particle bursts that fades out over 110 frames.
class TFireExplosion : public TObject {
public:
    TFireExplosion(Vec *pos, s16 band, s16 level, TObject *parent, f32 radius);
    TFireExplosion(f32 radius, const Vec *pos, s16 band, TObject *parent);
    virtual ~TFireExplosion();
    void spawn_rafoie_explosion_bursts();
    virtual void render();
    virtual void run_task();
    u8 pad_1C[4];
    u16 band;   // row of rafoie_burst_table
    u16 level;
    TEffIndirect *indirect_effect;
    Vec position;
    Vec scale;
    f32 target_scale;
    f32 radius;
    NJS_ARGB color;
    s32 age;
    s32 anim_frame;
    s32 growing;
};
LAYOUT_ASSERT(TFireExplosion_size, sizeof(TFireExplosion) == 0x64);

LAYOUT_ASSERT(FireExplosionPositionOffset, offsetof(TFireExplosion, position) == 0x28);

#endif
