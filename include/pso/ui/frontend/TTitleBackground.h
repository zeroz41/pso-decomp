#ifndef PSO_UI_FRONTEND_TTITLEBACKGROUND_H
#define PSO_UI_FRONTEND_TTITLEBACKGROUND_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TTitleScene;

// The title screen's background layer: the logo, the pulse and the rotating
// rings, animated from a frame counter.
class TTitleBackground : public TObject {
public:
    TTitleBackground(TTitleScene *scene);
    virtual ~TTitleBackground();
    virtual void render();
    virtual void run_task();
    TTitleScene *scene;
    s32 frame;
};
LAYOUT_ASSERT(TTitleBackground_size, sizeof(TTitleBackground) == 0x24);

#endif
