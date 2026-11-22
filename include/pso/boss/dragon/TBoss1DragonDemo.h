#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONDEMO_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONDEMO_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Plays the dragon's entry camera (bank 1, index 0 or 1 by isV2Mode); ends when the
// playback finishes or the dragon clears the flag it passed in.
class TBoss1DragonDemo : public TObject {
public:
    TBoss1DragonDemo(TObject *parent, s32 *flag, f32 frame_step);
    virtual ~TBoss1DragonDemo();
    virtual void run_task();
    virtual void render();

    f32 frame_step;  // copied into CameraPlayback::frame_step
    f32 frame;       // copied into CameraPlayback::frame
    s32 *flag;       // TBoss1Dragon's demo flag; the demo ends when it reads 0
};

extern "C" {
void TBoss1DragonDemo__sub_8002B68C(void);
void TBoss1DragonDemo__sub_8002B690(void);
}

#endif
