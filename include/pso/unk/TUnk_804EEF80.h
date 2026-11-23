#ifndef PSO_UNK_TUNK_804EEF80_H
#define PSO_UNK_TUNK_804EEF80_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TTitleScene;

// The title screen's background layer: the logo, the pulse and the rotating
// rings, animated from a frame counter.
class TUnk_804EEF80 : public TObject {
public:
    TUnk_804EEF80(TTitleScene *scene);
    virtual ~TUnk_804EEF80();
    virtual void render();
    virtual void run_task();
    TTitleScene *scene;
    s32 frame;
};
LAYOUT_ASSERT(TUnk_804EEF80_size, sizeof(TUnk_804EEF80) == 0x24);

#endif
