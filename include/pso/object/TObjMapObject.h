#ifndef PSO_OBJECT_TOBJMAPOBJECT_H
#define PSO_OBJECT_TOBJMAPOBJECT_H
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/animation/ActorAnimationState.h"

// The base of the map objects (TOKey, TODoor*, TOSign*, TOAircon* and the
// other TO* set objects): a collidable that loops one model motion and draws
// itself when it is in view.
class TObjMapObject : public TObjCollidable {
public:
    TObjMapObject(TObject *parent);
    virtual ~TObjMapObject();
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
    s32 object_state;           // the object's state (TODoorBase: DOOR_CLOSED..DOOR_CLOSING); compared signed
    f32 animation_frame;        // the motion frame update_anim_phase advances
    f32 animation_end_frame;    // where animation_frame wraps
    f32 animation_step;         // frames per update
    AnimationMotion *motion;    // the looped motion, NULL for a static model
    f32 view_range;             // range classify_actor_view_detail is asked with
    f32 model_radius;
};

typedef char TObjMapObjectSize[sizeof(TObjMapObject) == 0xC8 ? 1 : -1];

// The derived destructors still written out by hand call the base one by
// its symbol.
extern "C" void *__dt__13TObjMapObjectFv(void *self, s16 del);

#endif
