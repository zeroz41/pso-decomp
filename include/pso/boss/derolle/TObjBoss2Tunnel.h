#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_H

#include "types.h"
#include "pso/system/task/TObject.h"

// A velocity/position ramp: accelerate from v0 to peak, cruise, brake to rest over dist.
// init fills it, speed_at reads the speed and sample the distance at a time; advance samples
// the distance at t and steps t by one frame.
// TObjBoss2Tunnel (+0x68) and the tunnel of TObjBoss2Tunnel_802F1A58 (+0x20) hold one as a member.
struct PiecewiseCurve {
    PiecewiseCurve();
    ~PiecewiseCurve();
    void reset_floats();
    void init(f32 accel, f32 decel, f32 dist, f32 v0, f32 peak);
    f32 speed_at(f32 time);
    f32 current_speed();
    s32 sample(f32 *out, f32 time);
    s32 advance(f32 *out);

    f32 accel;
    f32 decel;
    f32 v0;
    f32 peak;
    f32 accelEnd;
    f32 decelStart;
    f32 end;
    f32 t;
    f32 accelDist;
    f32 decelPos;
    f32 dist;
};

class TObjBoss2RaftSplash;
class TParticleCtrl;

// The De Rol Le tunnel the raft travels through: it scrolls the tunnel segments past the
// camera (segment_queue, models of the bm_obj_boss2_common resource), sways and rolls them,
// flickers the fog and drives the brake to the boss arena (state 3).
struct TObjBoss2Tunnel : public TObject {
    TObjBoss2Tunnel(TObject *parent);
    virtual ~TObjBoss2Tunnel();
    virtual void run_task();
    virtual void render();
    void init_queue_from_start();
    void copy_ring_buffer_window();
    void shift_queue_push_next();
    void enable_fog();
    void restore_fog();
    s32 sub_8003C21C();
    s32 is_swaying();
    s32 is_flag_set();
    s32 sub_8003C1C8();
    void update_particles();

    f32 segment_pos;
    f32 scroll_speed;
    s32 state;
    s32 queue_pos;
    s32 segment_queue[6];
    s32 shift_index;
    s32 brake_frame;
    f32 brake_pos;
    f32 brake_end;
    f32 brake_speed;
    s32 pad_58;
    s32 texture_frame;
    f32 start_offset;
    s32 sway_state;
    PiecewiseCurve sway_curve;
    f32 sway_dir;
    f32 sway_offset;
    s32 bob_angle;
    s32 roll_angle;
    s32 roll_phase;
    s32 inner_roll_angle;
    f32 bob_height;
    s32 saved_fog;
    s32 fog_state;
    s32 fog_timer;
    s32 fog_step;
    TObjBoss2RaftSplash *raft_splashes[2];
    TParticleCtrl *particles[4];
    s32 dust_timer;

    static void set_global_flag_200();
    static void clear_global_flag_3000();
    static void set_global_flag_800();
    static void set_global_flag_400();
    static void *create();
    static s32 is_active();
    static void clear_target_flags();
    static s32 run_confirm_message_loop();
    static void poll_pso_screen_load();
    static void show_message_and_wait(s32 arg0);
    static bool verify_snapshot_checksum();
    static s32 load_snapshot();
    static s32 save_snapshot_to_card();
    static s32 save_snapshot();
    static void free_buffers();
    static void reset_state();
    static s32 decrement_packed_timer(u32 *arg0, s32 arg1);
    static s32 spawn_effect(saddr arg0, void *arg1, void *arg2);
    static s32 adjust_to_ground(saddr arg0, void *arg1);
    static s32 turn_toward_angle_limited(s32 arg0, s32 cur, s32 target, s32 step, s32 limit);
    static f32 calc_scaled_value(s32 arg0, f32 farg0);
    static void transform_vec_by_camera(saddr arg0, saddr arg1, saddr arg2);
    void render(void* a1);
    static void set_flag_0x200();
    static void clear_flags_0x3000();
    static s32 is_phase_active(s32 _w0);
    static s32 check_both(s32 arg0);
    static void enable_and_trigger();
    static void reset_player_state();
    static void create_particle_effect(const void *position, s32 particle_index, f32 speed);
    static void release_children(void *particle, f32 speed);
    void detach_children(void *arg);
    static void set_global_flag_100();
    static void draw_projected_quads(void *, int);
};

LAYOUT_ASSERT(TObjBoss2Tunnel_size, sizeof(TObjBoss2Tunnel) == 0xDC);

struct NJS_OBJECT;
// The number of nodes in the model tree under `node` (itself, children and siblings).
s32 count_tree_nodes(NJS_OBJECT *node);

#endif
