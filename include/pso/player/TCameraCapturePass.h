#ifndef PSO_PLAYER_TCAMERACAPTUREPASS_H
#define PSO_PLAYER_TCAMERACAPTUREPASS_H
#include "types.h"
#include "pso/system/task/TObject.h"

// One of the two camera capture passes TLobby::create_tasks starts: flags 1 draws the captured
// overlay over the screen, flags 0 captures the viewport into the capture texture.
class TCameraCapturePass : public TObject {
public:
    TCameraCapturePass(TObject *parent, s32 flags);
    virtual ~TCameraCapturePass();
    virtual void render_shadows();
    virtual void render();
    virtual void run_task();
    s32 flags;
};
LAYOUT_ASSERT(TCameraCapturePass_size, sizeof(TCameraCapturePass) == 0x20);

#endif
