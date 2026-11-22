#ifndef PSO_ENEMY_BERURA_TOBJENERE7BERURAPUNCH_H
#define PSO_ENEMY_BERURA_TOBJENERE7BERURAPUNCH_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/render/TUnk_80490470.h"

class TParticleCtrl;
class AreaAttackHistory;

struct TObjEneRe7BeruraPunch : public TUnk_804928CC {
    TObjEneRe7BeruraPunch(TObject *parent, TObjBase *owner);
    virtual ~TObjEneRe7BeruraPunch();
    virtual void apply_hit_if_active(void *, f32 *);
    s32 update_attack_collision();
    void update_flight();
    void snap_to_ground();
    void reset();
    virtual void run_task();
    void init();
    void deactivate();
    virtual void render();
    void update_velocity_and_snap();
    void launch(s32 arm, const Vec *position, const Vec *destination);

    u16 owner_id;  // get_entity_id(owner) in the ctor; find_entity_by_id gives the Berura back
    u8 pad_b2[0x2];
    s32 state;       // 0 idle, 1 flying (update_flight), 2 fading out (update_velocity_and_snap)
    s32 arm;         // the Berura arm drawn as the fist (TObjEneRe7Berura::draw_arm)
    Vec direction;   // sin/cos of rotation_y at launch
    f32 range;       // distance at which the flight ends (300)
    f32 height;      // travel_position.y above the ground, at least 10
    TParticleCtrl *trail_emitter;  // particle 0xDD, 40 units behind
    TParticleCtrl *front_emitter;  // particle 0x150, 20 units ahead
    AreaAttackHistory *attack_history;
    Vec travel_position;  // the fist; position is the ground point under it
    Vec ground_normal;  // CsnContact::normal of the ground under travel_position
    f32 scale;       // grows by 0.15 a frame to 2 while flying
    TUnk_80490470 fade;
    f32 distance;    // travelled, 10 a frame
    s32 pad_118;
};

LAYOUT_ASSERT(TObjEneRe7BeruraPunch_size, sizeof(TObjEneRe7BeruraPunch) == 0x11C);

#endif
