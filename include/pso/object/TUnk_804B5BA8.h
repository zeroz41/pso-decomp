#ifndef PSO_OBJECT_TUNK_804B5BA8_H
#define PSO_OBJECT_TUNK_804B5BA8_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// The tuning table each city door class hands its base.
struct CityDoorParams {
    f32 speed;             // motion frames the door moves per tick
    f32 open_range_sq;     // a player this close (squared) opens it
    f32 close_range_sq;    // it closes once no player is this close
    f32 body_radius;       // its collision box's half depth
    f32 body_half_width;
    f32 view_far_depth;    // update_object_view_visibility's arguments
    f32 view_radius;
};

// The base of the city's motion-driven doors (shop, guild, warp, medical
// center): it opens while a player stands near and closes when they leave.
class TUnk_804B5BA8 : public TObjCollidable {
public:
    TUnk_804B5BA8(TObject *parent, void *set, const CityDoorParams *params);
    virtual ~TUnk_804B5BA8();
    virtual s32 check_player_in_range(f32 range_sq);
    s32 is_any_city_player_in_range(const Vec *center, f32 range_squared);
    virtual void begin_state_1();
    virtual void city_door_tick_closing();
    virtual void city_door_tick_opening();
    virtual void check_ground_or_fall();
    virtual void city_door_play_close_sound();
    virtual void city_door_play_open_sound();
    virtual void dispatch_state();
    // The door's view check: update_object_view_visibility with the
    // params' view values; the doors draw only when it is nonzero.
    virtual s32 vfunc_22();
    s32 phase;  // 0 closed, 1 opening, 2 open, 3 closing
    f32 end_frame;  // the open motion's last frame
    f32 frame;
    const CityDoorParams *params;
};

#endif
