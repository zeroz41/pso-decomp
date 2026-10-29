#ifndef PSO_MISC_TUNK_804AFBF8_H
#define PSO_MISC_TUNK_804AFBF8_H
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/animation/ActorAnimationState.h"

// The base of the map objects (TOKey, TODoor*, TOSign*, TOAircon* and the
// other TO* set objects): a collidable that loops one model motion and draws
// itself when it is in view.
class TUnk_804AFBF8 : public TObjCollidable {
public:
    TUnk_804AFBF8(TObject *parent);
    virtual ~TUnk_804AFBF8();
    void update_anim_phase();
    // 1 unless its first collision body (at least min_radius) lies wholly in
    // front of the camera's near plane.
    s32 is_in_view_depth(f32 min_radius);
    // 1 when a player on the current floor stands within sqrt(radius_sq) of
    // it on the ground plane.
    s32 is_any_player_within_radius_xz(f32 radius_sq);
    virtual void run_task();
    virtual void render();
    // run_task's demo-mode step, empty in this build.
    void sub_80158604();
    u32 m_ac;
    f32 m_b0;  // the motion frame update_anim_phase advances
    union { u32 m_b4; f32 animation_end_frame; };
    f32 m_b8;  // frames per update
    union { u32 m_bc; AnimationMotion *motion; };
    f32 m_c0;  // view range classify_actor_view_detail is asked with
    union { u32 m_c4; f32 model_radius; };
};

typedef char TUnk_804AFBF8Size[sizeof(TUnk_804AFBF8) == 0xC8 ? 1 : -1];

// The derived destructors still written out by hand call the base one by
// its symbol.
extern "C" void *__dt__13TUnk_804AFBF8Fv(void *self, s16 del);

#endif
