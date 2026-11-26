#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
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
struct TObjBoss2Tunnel : public TObject {
    static void free_resources();
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
    static void create_particle_effect(const Vec *position, s32 particle_index, f32 speed);
    // Hand the emitter's particles over to particle_parent, adding offset to their
    // step or speed to its z, so they outlive the emitter (TObjBoss2Tunnel_8003B1FC.cpp).
    static void detach_children(TParticleCtrl *particle, const Vec *offset);
    static void release_children(TParticleCtrl *particle, f32 speed);
    // release_children with the -5.0f drift, for the boss splash emitters (TObjBoss2RaftSplash.cpp).
    static void release_splash_children(TParticleCtrl *particle);
    // Creates particle_parent under tl_07 (TObjBoss2Tunnel_8003B1FC.cpp).
    static void create_parent_object();
    // The object detach_children and release_children re-parent the particles to.
    static TObject *particle_parent;
    // Empty; called by free_boss2_tunnel.
    static void free_state();
    // Set global flag 0x1000 and clear 0x2000, and the reverse.
    static void start_sway_negative_x();
    static void start_sway_positive_x();
    static void set_global_flag_100();
    static const Vec raft_splash_offset_table[2];
    static const char *name;
    static u32 global_flags;
    static void * snapshot_buffer;
    static u16 snapshot_state;
    static s32 snapshot_saved_flag;
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
extern NJS_OBJECT debug_chunk_b_object;

// Two debug chunk models other units draw with draw_chunk_object: debug_chunk_object (TObjEneBm3FlyNest,
// TObjEneRecobox, and TObjHMS_EZRope_Player through debug_chunk_b_object) and debug_cylinder_object (TBoss1Dragon, TBoss2Mine,
// TObjFogCollision, TBoss8Dragon). Each is a strip list, an NJD_CV_VN vertex list, an NJS_CNK_MODEL and its NJS_OBJECT.
struct DebugChunkVertexVN {
    f32 pos[3];
    f32 nrm[3];
};
struct DebugChunkVertices16 {
    s32 head;   // NJD_CV_VN chunk header
    s32 range;  // index offset 0, vertex count
    DebugChunkVertexVN vertex[16];
    s32 end;    // NJD_CE
};
struct DebugChunkVertices58 {
    s32 head;
    s32 range;
    DebugChunkVertexVN vertex[58];
    s32 end;
};
struct Quad_8007D828 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };
// screen.bin / the PSO_SCREEN card file: a 256x192 capture and who was in the room.
struct ScreenSnapshot {
    u32 checksum;
    u16 width;
    u16 height;
    u8 pixels[0x18000];
    u8 bits_per_pixel;
    u8 format;
    u16 player_count;
    u32 class_flags[12];
    u32 levels[12];
    char names[12][0x18];
};
// The "GetFrameBuffer" temp buffer: the snapshot, then its card file image at the next 32-byte boundary.
struct SnapshotFrameBuffer {
    ScreenSnapshot snapshot;
    u8 pad_1818C[0x14];
    u8 save_image[0x1E000];
};

struct G_PlaySound_6xB2;

void bswap_6xB2_play_sound(G_PlaySound_6xB2 *cmd);

#endif
