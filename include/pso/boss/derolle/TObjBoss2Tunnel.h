#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TParticleCtrl;
struct Vec;

// A velocity/position ramp: accelerate from v0 to peak, cruise, brake to rest over dist.
// init fills it, speed_at reads the speed and sample the distance at a time; advance samples
// the distance at t and steps t by one frame.
// TObjBoss2Tunnel (+0x68) and TObjBoss7Tunnel (+0x20) hold one as a member.
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
struct Vec;

// The De Rol Le tunnel the raft travels through: it scrolls the tunnel segments past the
// camera (segment_queue, models of the bm_obj_boss2_common resource), sways and rolls them,
// flickers the fog and drives the brake to the boss arena (state 3).
// Vertex of TObjBoss2Tunnel::draw_projected_quads: a view-space position and an RGBA colour.
struct ProjectedVertex {
    f32 x;
    f32 y;
    f32 z;
    u32 color;
};

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
    // 0, or texture_frame + 31: the texture render swaps into boss2_common_texture_list's first entry.
    s32 current_texture_index();
    s32 is_swaying();
    // Global flags 0x1000 (sway to -x) and 0x2000 (sway to +x); is_swaying is either.
    s32 is_flag_set();
    s32 is_swaying_positive_x();
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
    static void show_message_and_wait(s32 message);
    static BOOL verify_snapshot_checksum();
    static s32 load_snapshot();
    static s32 save_snapshot_to_card();
    static s32 save_snapshot();
    static void free_buffers();
    static void reset_state();
    static s32 decrement_packed_timer(u32 *packed, s32 step);
    // Drops from 20 units above from to the ground: out gets the ground point and normal its
    // normal, or out = from and 0 when there is no ground.
    static s32 spawn_effect(const Vec *from, Vec *out, Vec *normal);
    static s32 adjust_to_ground(const Vec *from, Vec *out);
    static s32 turn_toward_angle_limited(s32 angle, s32 cur, s32 target, s32 step, s32 limit);
    static f32 calc_scaled_value(s32 angle, f32 length);
    static void enable_and_trigger();
    static void reset_player_state();
    static void create_particle_effect(const Vec *position, s32 particle_index, f32 speed);
    // Hand the emitter's particles over to TObjBoss2Tunnel_parent_object, adding offset to their
    // step or speed to its z, so they outlive the emitter (TObjBoss2Tunnel_8003B1FC.cpp).
    static void detach_children(TParticleCtrl *particle, const Vec *offset);
    static void release_children(TParticleCtrl *particle, f32 speed);
    // release_children with the -5.0f drift, for the boss splash emitters (TObjBoss2RaftSplash.cpp).
    static void release_splash_children(TParticleCtrl *particle);
    // Creates TObjBoss2Tunnel_parent_object under tl_07 (TObjBoss2Tunnel_8003B1FC.cpp).
    static void create_parent_object();
    // Empty; called by TLobby::init_boss2_stage.
    static void sub_8003C648();
    // Set global flag 0x1000 and clear 0x2000, and the reverse.
    static void start_sway_negative_x();
    static void start_sway_positive_x();
    static void set_global_flag_100();
    // Draws n vertices as a triangle strip, dividing x and y by -z.
    static void draw_projected_quads(ProjectedVertex *vertices, s32 n);
    // Loads the screen-space matrix and the colour vertex state for draw_projected_quads,
    // blended when mode != 0.
    static void setup_projected_color_draw(s32 mode);
};

LAYOUT_ASSERT(TObjBoss2Tunnel_size, sizeof(TObjBoss2Tunnel) == 0xDC);

struct NJS_OBJECT;
// The number of nodes in the model tree under `node` (itself, children and siblings).
s32 count_tree_nodes(NJS_OBJECT *node);
// The nodes of that tree that are drawn: NJD_EVAL_HIDE (8) skips a node, NJD_EVAL_BREAK
// (0x10) its children.
s32 count_visible_nodes(NJS_OBJECT *node);
// Debug chunk model of an 8-sided cylinder (radius 2, y -5..5, named from its vertex data); the Dragon,
// De Rol Le's mines, TBoss8Dragon and TObjFogCollision draw it scaled to show hit volumes.
extern NJS_OBJECT *debug_cylinder_object;

#endif
