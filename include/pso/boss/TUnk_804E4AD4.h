#ifndef PSO_BOSS_TUNK_804E4AD4_H
#define PSO_BOSS_TUNK_804E4AD4_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/animation/ActorAnimationState.h"

struct NJS_OBJECT;

class TUnk_804E4AD4 : public TObject {
public:
    TUnk_804E4AD4(TObject *parent, s32 kind);
    virtual ~TUnk_804E4AD4();
    virtual void run_task();
    // Called for each of them by TObjBoss7Tunnel::render (TObjBoss7Tunnel_802F190C.cpp).
    void draw_particle_effect();
    NJS_OBJECT *model; // get_bml_model(boss7_common_bml_resource, kind + 0x11)
    AnimationMotion *motion; // get_bml_motion(boss7_common_bml_resource, kind)
    f32 last_frame; // motion->frameCount - 1
    f32 frame;      // run_task advances it by 1 and wraps it at last_frame
};
LAYOUT_ASSERT(TUnk_804E4AD4_size, sizeof(TUnk_804E4AD4) == 0x2C);

#endif
