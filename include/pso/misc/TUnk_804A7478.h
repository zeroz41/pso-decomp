#ifndef PSO_MISC_TUNK_804A7478_H
#define PSO_MISC_TUNK_804A7478_H
#include "types.h"
#include "pso/misc/TUnk_804A7488.h"
#include "pso/system/NinjaTypes.h"

// A model part that plays one motion: TPlyPhotonChair's two seat halves.
class TUnk_804A7478 : public TUnk_804A7488 {
public:
    NJS_MOTION *motion;
    f32 frame;
    f32 frame_count;
    f32 speed;
    s32 state;  // 0 loop, 1 stopped, 2 play to the end and stop
    virtual ~TUnk_804A7478();
    virtual void draw_model();
    // Steps the frame back (forward) by speed, looping, or stops at the
    // first (last) frame in state 2.
    void play_backward();
    void play_forward();
    f32 get_frame();
    NJS_MOTION *get_motion();
    void stop();
    void *init();
    void sub_8035B610();
};

typedef char TUnk_804A7478Size[sizeof(TUnk_804A7478) == 0x1C ? 1 : -1];

extern "C" {
extern void *__vt__13TUnk_804A7478[];
void *__dt__13TUnk_804A7478Fv(TUnk_804A7478 *self, s16 del);
}

#endif
