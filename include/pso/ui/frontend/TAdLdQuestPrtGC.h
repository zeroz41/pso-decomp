#ifndef PSO_UI_FRONTEND_TADLDQUESTPRTGC_H
#define PSO_UI_FRONTEND_TADLDQUESTPRTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

// Four particles placed in front of the camera on the quest-load screen; the
// first controller's stick turns them and a button cycles their tint.
struct TAdLdQuestPrtGC : public TObject {
    // Angles in 0x10000-per-turn units.
    struct Angles {
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
    Angles angle_speed[4];
    // Index into the six-entry tint table; advanced by the button.
    u32 tint_index;
    // Frames since the tint changed, held at 12.
    u32 tint_timer;
    u32 frame_count;
    Tint tints[4];
};

typedef char TAdLdQuestPrtGC_size[sizeof(TAdLdQuestPrtGC) == 0x158 ? 1 : -1];
#endif
