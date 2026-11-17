#ifndef PSO_BOSS_TUNK_804E4B3C_H
#define PSO_BOSS_TUNK_804E4B3C_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include <dolphin/mtx/GeoTypes.h>

// Inferred: Barba Ray's tunnel (it builds TObjBoss7TunnelCol, TObjBoss7RaftSplash and TObjBoss7Dust).
class TUnk_804E4B3C : public TObject {
public:
    TUnk_804E4B3C(TObject *parent);
    virtual ~TUnk_804E4B3C();
    virtual void run_task();
    void update_phase_motion();
    void spawn(s32 kind, Vec *position);
    // the constructor builds the starting segment rows with one of these
    void spawn_segment_row_a();
    void spawn_segment_row_b();
    virtual void render();
    // run_task's phase handlers (indexed by unk_1C)
    void init_effect();
    void sub_802F2400();
    void sub_802F23FC();
    void sub_802F273C();
    void update_dust_spawn();
    void update_spawn_timer(s32 arg1, s32 arg2, s32 arg3);
    void double_scroll_speed();
    void advance_effect_timer();
    // Out-of-line helpers at the end of the tunnel file (0x802F2C90..0x802F2CC4),
    // called by its segments (TUnk_804E4B24).
    void copy_position(const Vec *position);
    f32 sub_802F2CB4();
    f32 sub_802F2CBC();
    // Size 0x94 (TObjBoss2Tunnel__sub_802F2C50's operator new).
    s32 phase;          // index into run_task's phase handlers
    PiecewiseCurve curve; // update_phase_motion's sideways sway
    s32 sway_state;     // update_phase_motion's switch (0..3)
    f32 sway_sign;      // 1.0 or -1.0, the sway direction
    f32 segment_x;      // sub_802F2CBC: a segment's position.x
    f32 scroll_offset;  // update_spawn_timer adds scroll_speed, spawns a segment per 800
    f32 scroll_speed;   // sub_802F2CB4: a segment's z step per frame
    u8 pad_60[0x10];
    s32 spawn_index;    // update_spawn_timer's index into its spawn table
    s32 dust_timer;     // update_dust_spawn spawns a TObjBoss7Dust every 30 frames
    Vec unk_78;         // copy_position: the position of the kind-4 segment
    f32 half_length;
    TObject *tunnel_col; // the TObjBoss7TunnelCol the constructor creates
    TObject *effect_nodes; // parent of the segments spawn creates
    TObject *render_nodes; // parent of the three TUnk_804E4AD4; render walks its children
};
typedef char TUnk_804E4B3C_size[sizeof(TUnk_804E4B3C) == 0x94 ? 1 : -1];

#endif
