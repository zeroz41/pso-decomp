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
    s32 enemy_check_target_valid();
    s32 enemy_has_live_target();
    void update_velocity();
    void turn_toward_target_direction(s32 max_step);
    void turn_and_calc_clamped_destination(Vec *out, s32 max_step, f32 distance);
    void turn_and_calc_slide_destination(Vec *out, s32 max_step, f32 distance);
    void turn_and_calc_shot_destination(Vec *shot_pos, s32 iscale, f32 scale);
    void set_target_destination(const Vec *position);
    void enemy_set_target_id(u16 id);
    s32 enemy_bind_or_clear_target(u16 id);
    s32 enemy_validate_retained_target();
    // 0 and the target cleared unless confused or targeting a player, else enemy_validate_retained_target().
    s32 update_death_check();
    CsnHit *enemy_turn_and_move_shot_step(s32 iscale, f32 scale);
    CsnHit *enemy_turn_and_move_on_ground(s32 max_step, f32 currentSpeed);
    CsnHit *enemy_turn_and_move_xz_slide(s32 max_step, f32 distance);
    CsnHit *enemy_turn_and_move_xz_clamped(s32 max_step, f32 distance);

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
    static const char *name;
};

#endif
