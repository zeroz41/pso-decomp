#ifndef PSO_OBJECT_TOBJJUNGLEKAMOME_H
#define PSO_OBJECT_TOBJJUNGLEKAMOME_H
#include "types.h"
#include "pso/object/TObjPathObj.h"

struct NJS_OBJECT;
struct AnimationMotion;

class TObjJungleKamome : public TObjPathObj {
public:
    TObjJungleKamome(TObject *parent, void *set_data);
    static void *create(void *set_data);
    static void load_static_resource();
    static void destroy_instance();
    virtual ~TObjJungleKamome();
    s32 initialize_path();
    s32 update_path_steering();
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
    s32 cry_delay;             // frames to the next cry, 150 to 270
};
LAYOUT_ASSERT(TObjJungleKamome_size, sizeof(TObjJungleKamome) == 0xD0);

#endif
