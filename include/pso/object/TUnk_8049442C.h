#ifndef PSO_OBJECT_TUNK_8049442C_H
#define PSO_OBJECT_TUNK_8049442C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_OBJECT;

class TUnk_8049442C : public TObjCollidable {
public:
    // TObjEneGyaranzo::spawn_missile's mine (me4_y_mine.nj): owner's room and id, launch
    // position, yaw and turn rate.
    TUnk_8049442C(TObjBase *owner, Vec *pos, s32 angle, s32 spin);
    virtual ~TUnk_8049442C();
    // Hits every hittable character but the owner, then goes off.
    void explode();
    // Falls onto the ground below (height above it); ground receives the ground point.
    void update_ground_fall(Vec *ground, f32 height);
    virtual void render();
    virtual void run_task();
    Vec velocity;
    s32 pad_B8;
    s32 yaw;
    s32 pitch;             // tips from -0x4000 up to 0 while it falls
    NJS_OBJECT *mine_model;
    saddr mine_textures;
    s32 state;             // 0 falling, 1 rolling, 2 stopped
    s32 timer;             // goes off at 150 frames
    f32 roll_distance;     // stops rolling at 50
    u16 owner_id;  // get_entity_id of the owner, find_entity_by_id'd on impact
    u8 pad_DA[0x2];
    s32 spin;              // added to yaw when it lands
    Vec probe_position;    // 5 above the position, where the wall test starts
    s32 arm_delay;         // frames before collisions set it off
};
LAYOUT_ASSERT(TUnk_8049442C_size, sizeof(TUnk_8049442C) == 0xF0);

#endif
