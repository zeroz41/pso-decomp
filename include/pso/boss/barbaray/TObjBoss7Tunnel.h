#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7TUNNEL_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7TUNNEL_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include <dolphin/mtx/GeoTypes.h>

// Barba Ray's tunnel, the twin of TObjBoss2Tunnel: it builds TObjBoss7TunnelCol, two
// TObjBoss7RaftSplash and TObjBoss7Dust, and runs the same sway state machine.
class TObjBoss7Tunnel : public TObject {
public:
    TObjBoss7Tunnel(TObject *parent);
    virtual ~TObjBoss7Tunnel();
    virtual void run_task();
    void update_phase_motion();
    void spawn(s32 kind, Vec *position);
    // the constructor builds the starting segment rows with one of these
    void spawn_segment_row_a();
    void spawn_segment_row_b();
    virtual void render();
    // run_task's phase handlers (indexed by phase)
    void init_effect();
    // Phase 1 (name inferred): spawns from table b and slows the scroll as the kind-4 segment comes
    // within 300/200/100; below 1 it stops the tunnel and moves on to phase 2.
    void update_arrival();
    // Phase 2 (name inferred): the tunnel has stopped; nothing to do.
    void update_stopped();
    void sub_802F273C();
    void update_dust_spawn();
    // spawns table[spawn_index] each 800 units of scroll; at count it wraps to 0, or holds
    // the last entry when hold_last is set
    void update_spawn_timer(const s32 *table, s32 count, s32 hold_last);
    void double_scroll_speed();
    void advance_effect_timer();
    // Out-of-line helpers at the end of the tunnel file (0x802F2C90..0x802F2CC4),
    // called by its segments (TUnk_804E4B24).
    void copy_position(const Vec *position);
    f32 get_scroll_speed();
    f32 get_segment_x();
    // The tunnel's state flags (boss2_tunnel_state_flags): 0x1000 and 0x2000 pick the sway
    // direction (update_phase_motion swings to -x on 0x1000), 0x8 is set by the kind-4 segment.
    s32 check_both();
    s32 is_phase_active();
    static s32 is_swaying_positive_x();
    static void set_flag_0x8();
    // Set 0x1000 (sway to -x) or 0x2000 (sway to +x) and clear the other (TBoss7DeRolLeC picks
    // by the side its position slot is on); clear_flags_0x3000 ends the sway.
    static void start_sway_negative_x();
    static void start_sway_positive_x();
    // Sets 0x200, which moves init_effect on to phase 1, and clears the sway.
    static void set_flag_0x200();
    static void clear_flags_0x3000();
    // Bit 0x8000: set when the tunnel reaches its end (phase 2, scroll_speed 0).
    static s32 has_stopped();
    // Twins of TObjBoss2Tunnel's detach_children/release_children/create_parent_object (TObjBoss7Tunnel_802F190C.cpp).
    static void detach_children(TParticleCtrl *particle, const Vec *offset);
    static void release_children(TParticleCtrl *particle, f32 speed);
    static void create_parent_object();
    // Twin of TObjBoss2Tunnel::create_particle_effect (TObjBoss7RaftSplash.cpp).
    static void create_particle_effect(const Vec *position, s32 particle_index, f32 speed);
    // Twins of TObjBoss2CeilJunk::create_particle and TObjBoss2Tunnel::release_splash_children: the
    // same with speed -5.
    static void create_particle(const Vec *position, s32 particle_index);
    static void release_splash_children(TParticleCtrl *particle);
    // Clears boss2_tunnel_state_flags (init_scene_boss2_tunnel).
    static void clear_state_flags();
    // Creates the tunnel under tl_04 (fn_802F1084).
    static void create();
    // Empty (fn_802F105C).
    static void sub_802F2C4C();
    // Size 0x94 (create's operator new).
    s32 phase;          // index into run_task's phase handlers
    PiecewiseCurve curve; // update_phase_motion's sideways sway
    s32 sway_state;     // update_phase_motion's switch (0..3)
    f32 sway_sign;      // 1.0 or -1.0, the sway direction
    f32 segment_x;      // get_segment_x: a segment's position.x
    f32 scroll_offset;  // update_spawn_timer adds scroll_speed, spawns a segment per 800
    f32 scroll_speed;   // get_scroll_speed: a segment's z step per frame
    u8 pad_60[0x10];
    s32 spawn_index;    // update_spawn_timer's index into its spawn table
    s32 dust_timer;     // update_dust_spawn spawns a TObjBoss7Dust every 30 frames
    Vec kind4_position; // copy_position: the kind-4 segment's position; phase 2 starts when its z < 1
    f32 half_length;
    TObject *tunnel_col; // the TObjBoss7TunnelCol the constructor creates
    TObject *effect_nodes; // parent of the segments spawn creates
    TObject *render_nodes; // parent of the three TUnk_804E4AD4; render walks its children
};
LAYOUT_ASSERT(TObjBoss7Tunnel_size, sizeof(TObjBoss7Tunnel) == 0x94);

#endif
