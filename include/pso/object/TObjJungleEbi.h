#ifndef PSO_OBJECT_TOBJJUNGLEEBI_H
#define PSO_OBJECT_TOBJJUNGLEEBI_H
#include "types.h"
#include "pso/object/TObjPathObj.h"

struct NJS_OBJECT;
struct AnimationMotion;

class TObjJungleEbi : public TObjPathObj {
public:
    TObjJungleEbi(TObject *parent, void *set_data);
    static void *create(void *set_data);
    static void load_static_resource();
    static void destroy_instance();
    virtual ~TObjJungleEbi();
    s32 initialize_path();
    s32 update_path_follow_rotation(void *, f32);
    virtual void update();
    virtual void draw();
    NJS_OBJECT *model;
    AnimationMotion *motion;   // the model's own motion
    AnimationMotion *path;     // the path motion of the profile
    f32 path_frame;
    f32 motion_frame;
    Vec path_position;         // the path's root node at path_frame, from position
    s32 path_yaw;
    s32 path_pitch;
    s32 path_roll;             // banks into turns, up to 0x2000
    s32 roll_speed;
    s32 profile;               // index into the path profiles, set_params[0] clamped
};
LAYOUT_ASSERT(TObjJungleEbi_size, sizeof(TObjJungleEbi) == 0xCC);

#endif
