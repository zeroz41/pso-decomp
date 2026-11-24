#ifndef PSO_ENEMY_DD_TOBJENEDD_ST_H
#define PSO_ENEMY_DD_TOBJENEDD_ST_H
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"

class TObjEneDD_ST : public TObjEneDD {
public:
    TObjEneDD_ST(TObject *parent);
    virtual ~TObjEneDD_ST();
    f32 get_motion_frame();
    void draw_with_alt_model(s32);
    void set_active();
    void init_float_params();
    void set_target_player(void *);
    void enemy_clear_target();
    void enemy_init_acquire_period(s32);
    s32 select_and_apply_target(f32);
    s32 select_nearest_target(f32);
    s32 enemy_tick_target_acquisition(s32 *, s32, f32);
    s32 update_linked_position(f32);
    void enemy_copy_target_destination();
    void enemy_init_validate_period(s32);
    virtual s32 update_status_effects();
    virtual s32 acquire_target(f32);
    void sub_800F5874(s32);
    void sub_800F5864(s32);
    s32 enemy_check_target_valid();
    s32 enemy_has_live_target();
    void update_velocity();
    void turn_toward_target_direction(s32 max_step);
    void fire_attack_a(Vec *out, s32 max_step, f32 distance);
    void fire_attack_b(Vec *out, s32 max_step, f32 distance);
    void fire_attack_c(Vec *shot_pos, s32 iscale, f32 scale);
    void set_target_destination(const Vec *position);

    u16 target_id;                // 0xFFFF: no target
    u8 pad_38E[0x2];
    TObjChara *current_target;    // the entity target_id names
    Vec destination;              // set_target_destination's point
    Vec destination_direction;    // towards destination, normalized in xz
    f32 destination_distance;     // xz distance to destination
    s32 acquire_counter;          // update_linked_position re-picks a target every acquire_period frames
    s32 acquire_period;
    s32 validate_counter;         // the held target is re-checked every validate_period frames
    s32 validate_period;
};

extern "C" {
void enemy_set_target_id(TObjEneDD_ST *self, u16 id);
s32 enemy_bind_or_clear_target(TObjEneDD_ST *self, u16 id);
s32 enemy_validate_retained_target(TObjEneDD_ST *self);
}

#endif
