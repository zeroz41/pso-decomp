#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONDEMO_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONDEMO_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Plays the dragon's scripted camera; ends when the playback finishes or the
// dragon clears the flag it passed in.
class TBoss8DragonDemo : public TObject {
public:
    TBoss8DragonDemo(TObject *parent, s32 *flag, f32 frame_step);
    virtual ~TBoss8DragonDemo();
    virtual void run_task();
    virtual void render();

    f32 frame_step;  // copied into CameraPlayback::frame_step
    f32 frame;       // copied into CameraPlayback::frame
    s32 *flag;       // TBoss8Dragon's demo flag; the demo ends when it reads 0
};

#endif
