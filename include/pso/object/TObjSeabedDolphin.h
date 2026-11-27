#ifndef PSO_OBJECT_TOBJSEABEDDOLPHIN_H
#define PSO_OBJECT_TOBJSEABEDDOLPHIN_H
#include "types.h"
#include "pso/object/lobby/TObjPathObj.h"

struct NJS_OBJECT;
struct NJS_MOTION;

class TObjSeabedDolphin : public TObjPathObj {
public:
    TObjSeabedDolphin(TObject *parent, ObjectSetData *set_data);
    static void *create(ObjectSetData *set_data);
    static void load_static_resource();
    static void destroy_instance();
    virtual ~TObjSeabedDolphin();
    s32 initialize_path();
    s32 update_path_steering();
    virtual void update();
    virtual void draw();
    NJS_OBJECT *model;
    NJS_MOTION *motion;   // the model's own motion
    NJS_MOTION *path;     // the path motion of the profile
    f32 path_frame;
    f32 motion_frame;
    Vec path_position;         // the path's root node at path_frame, from position
    s32 path_yaw;
    s32 path_pitch;
    s32 path_roll;             // banks into turns, up to 0x2000
    s32 roll_speed;
    s32 profile;               // index into the path profiles, set_params[0] clamped
};
LAYOUT_ASSERT(TObjSeabedDolphin_size, sizeof(TObjSeabedDolphin) == 0xCC);

#endif
