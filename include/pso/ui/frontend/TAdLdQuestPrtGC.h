#ifndef PSO_UI_FRONTEND_TADLDQUESTPRTGC_H
#define PSO_UI_FRONTEND_TADLDQUESTPRTGC_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

// Four particles placed in front of the camera on the quest-load screen; the
// first controller's stick turns them and a button cycles their tint.
struct TAdLdQuestPrtGC : public TObject {
    // Angles in 0x10000-per-turn units.
    struct Angles {
        u32 x;
        u32 y;
        u32 z;
    };
    struct AngleSteps {
        s32 x;
        s32 y;
        s32 z;
    };
    // Tint unpacked from the colour table, one channel per float.
    struct Tint {
        f32 a;
        f32 r;
        f32 g;
        f32 b;
        u8 pad_10[0x14];
    };

    TAdLdQuestPrtGC(TObject *parent);
    virtual ~TAdLdQuestPrtGC();
    virtual void run_task();
    virtual void render();
    static int get_abs(int value);

    TParticleCtrl *particles[4];
    Vec particle_pos[4];
    Angles particle_angles[4];
    AngleSteps angle_speed[4];
    // Index into the six-entry tint table; advanced by the button.
    u32 tint_index;
    // Frames since the tint changed, held at 12.
    u32 tint_timer;
    u32 frame_count;
    Tint tints[4];
};

LAYOUT_ASSERT(TAdLdQuestPrtGC_size, sizeof(TAdLdQuestPrtGC) == 0x158);
LAYOUT_ASSERT(QuestParticlePositionsOffset, offsetof(TAdLdQuestPrtGC, particle_pos) == 0x2C);
LAYOUT_ASSERT(QuestParticleAnglesOffset, offsetof(TAdLdQuestPrtGC, particle_angles) == 0x5C);
LAYOUT_ASSERT(QuestParticleStepsOffset, offsetof(TAdLdQuestPrtGC, angle_speed) == 0x8C);
LAYOUT_ASSERT(QuestParticleTintsOffset, offsetof(TAdLdQuestPrtGC, tints) == 0xC8);
#endif
