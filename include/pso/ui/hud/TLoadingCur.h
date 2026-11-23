#ifndef PSO_UI_HUD_TLOADINGCUR_H
#define PSO_UI_HUD_TLOADINGCUR_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TParticleCtrl;
struct NJS_POINT2;

// The 3D cursor shown while loading: a particle steered with the stick in
// front of the camera.
struct TLoadingCur : public TObject {
    TLoadingCur(TObject *parent, Vec *pos);
    virtual ~TLoadingCur();
    virtual void render();
    virtual void run_task();
    void update_camera_facing_offset();
    s32 calc_clamp_offset(const f32 *screen, NJS_POINT2 *push);
    void sub_8001CCD4();

    static const char *class_name;

    TParticleCtrl *particle;
    Vec offset;   // steered position, relative to anchor
    Vec pos;      // offset turned to face the camera, plus anchor
    Vec velocity;
    Vec anchor;   // 100 units in front of the camera
    Vec facing;   // reverse of the camera view vector
};

LAYOUT_ASSERT(TLoadingCur_size, sizeof(TLoadingCur) == 0x5C);

extern "C" Vec calc_loading_cursor_pos(TLoadingCur *cursor);

#endif
