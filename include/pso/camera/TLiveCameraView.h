#ifndef PSO_CAMERA_TLIVECAMERAVIEW_H
#define PSO_CAMERA_TLIVECAMERAVIEW_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include <stddef.h>

// The picture of a live camera (TObjLiveCameraCtrl) on the Gol Dragon floor:
// in the shadow pass it renders the scene from eye towards target into the
// camera render target, which the arena's monitors show as their texture.
class TLiveCameraView : public TObject {
public:
    // id is the camera's view id (0xF44E8 + its slot), which the view keeps
    // nowhere; value is kept in pad_38, which nothing reads.
    TLiveCameraView(TObject *parent, s32 id, const Vec *eye, const Vec *target, f32 value);
    virtual ~TLiveCameraView();
    virtual void render_shadows();
    virtual void render();
    virtual void run_task();
    void set_view(const Vec *eye, const Vec *target);
    // Makes the camera render target the current texture (outside split screen).
    void bind_texture();
    void enable();
    void disable();

    u8 flags; // 4 while disabled
    Vec eye;
    Vec target;
    f32 pad_38;
};
LAYOUT_ASSERT(TLiveCameraView_eye, offsetof(TLiveCameraView, eye) == 0x20);
LAYOUT_ASSERT(TLiveCameraView_size, sizeof(TLiveCameraView) == 0x3C);

#endif
