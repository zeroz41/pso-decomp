#ifndef PSO_OBJECT_TUNK_804B5BA8_H
#define PSO_OBJECT_TUNK_804B5BA8_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804B5BA8 : public TObjCollidable {
public:
    virtual ~TUnk_804B5BA8();
    virtual s32 check_player_in_range(s32, f32);
    virtual void begin_state_1();
    virtual void city_door_tick_closing();
    virtual void city_door_tick_opening();
    virtual void check_ground_or_fall();
    virtual void city_door_play_close_sound();
    virtual void city_door_play_open_sound();
    virtual void dispatch_state();
    virtual void vfunc_22();
    u8 unk_AC[0x4];
    f32 m_b0;
    f32 m_b4;
    u8 unk_B8[0x4];
};

#endif
