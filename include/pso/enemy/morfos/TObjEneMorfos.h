#ifndef PSO_ENEMY_MORFOS_TOBJENEMORFOS_H
#define PSO_ENEMY_MORFOS_TOBJENEMORFOS_H

#include "types.h"

struct BmlResource;
struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/TUnk_80494938.h"

class TObject;
class TParticleCtrl;

// The Morfos row TLobby::dispatch_shared_handler_a returns (TObjEneMorfos__param_table).
struct MorfosParams {
    f32 projectile_speed;    // copied to morfos_projectile_speed
    f32 projectile_speed_b;  // copied to morfos_param_table_speed_copy
    u8 pad_8[0x10];
    s32 turn_step;           // approach_value step while walking (state 4)
    s32 attack_turn_step;    // approach_value step of the attack states, the burst's turn per shot
    s32 retreat_wait;        // frames state 6 waits before it turns back
    s32 charge_frames;       // frames the burst spins before it fires
    s32 charge_spin_step;    // rotation the burst adds per charging frame
};

struct TObjEneMorfos : public TObjEneDD_ST {
    TObjEneMorfos(TObject *parent, void *set_data);
    virtual ~TObjEneMorfos();
    virtual f32 receive_physical_attack(void *attacker, f32 scale);
    virtual void dispatch_action(u32 state, s32 reason);
    s32 render_model_if_visible();
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void render();
    virtual void run_task();
    u32 m_3c0;
    u32 m_3c4;
    Vec reflection_point;     // push_reflection_matrix mirrors the body about it
    s32 texture_scroll;       // 0..12, scrolls the body and wall textures each frame
    f32 walk_speed;           // 0.28 + parameters[0]: walk step and walk_timer increment
    f32 walk_duration;        // 20 + parameters[1]: walk_timer limit
    f32 wall_chance;          // check_low_hp_trigger's roll for raising the wall (flag 0x10)
    f32 burst_chance;         // try_enter_low_hp_state's roll for the burst (state 9)
    s32 can_walk;             // variant <= 0
    TUnk_80490470 m_3ec;
    TUnk_80494938 m_408;
    RenderFadeState m_424[4];
    TParticleCtrl *burst_emitter; // the burst's charge particles
    Vec node_points[2];       // record_camera_path_point stores two model nodes here
    static BmlResource *get_instance();
    void draw_body();
    static void record_camera_path_point(NJS_OBJECT *);
    void state_death(s32 arg1);
    void state_patrol(s32 ev);
    void state_appear(s32 ev);
    void handle_event_transition(s32 ev);
    void play_sound_in_band();
    void init_target_offsets();
    void set_hover_target_position();
    s32 approach_value(s32 arg1, s32 arg2);
    s32 try_enter_low_hp_state();
    s32 check_low_hp_trigger();
    void init_instance();
    static void unload_static_data();
    void *create();
    static s32 snap_to_ground(s32 arg0, saddr arg1);
    void sub_80332DBC(s32 ev);
    void sub_80332FD4(s32 ev);
    void sub_80333690(s32 ev);
    void sub_80333AD0(s32 ev);
    void sub_80333E48(s32 ev);
    void sub_80334030(s32 ev);
    void sub_803342B8(s32 ev);
    s32 sub_803344F0();
    void sub_80334704();
    void update_ground_probe();
    static u8 check_value_in_range(void *arg0, u16 arg1, u16 arg2, u16 arg3);
    s32 substate;             // step inside the current state
    s32 m_4b4;
    s32 step_timer;
    s32 m_4bc;
    s32 burst_start_angle;    // rotation_y when the burst turn started
    f32 m_4c4;
    u8 unk_4C8[0x4];
    f32 m_4cc;
    u8 unk_4D0[0x4];
    f32 m_4d4;
    void render_part(s32 idx, s32 mode);
    void state_rotating_projectile_burst(s32 ev);
    s32 select_target_in_view();
};

#include <stddef.h>
LAYOUT_ASSERT(TObjEneMorfos_size, sizeof(TObjEneMorfos) == 0x4D8);
LAYOUT_ASSERT(TObjEneMorfos_fades, offsetof(TObjEneMorfos, m_3ec) == 0x3EC);

extern MorfosParams *TObjEneMorfos__param_table;

#endif
