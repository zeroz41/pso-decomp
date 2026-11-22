#ifndef PSO_ENEMY_RECON_TOBJENERECON_H
#define PSO_ENEMY_RECON_TOBJENERECON_H

#include "types.h"

struct NJS_OBJECT;
struct TObjEneRecobox;
class TParticleCtrl;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

struct TObjEneRecon : public TObjEneDD_ST {
    TObjEneRecon(TObject *parent, TObjEneRecobox *owner, u16 id, s32 index, Vec *pos, Vec *dir);
    virtual ~TObjEneRecon();
    virtual s32 acquire_target(f32);
    s32 render_model_if_visible();
    virtual void check_collisions();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void dispatch_action(u32 state, s32 reason);
    void update_flag_0x444();
    void sub_8031D4B0(s32);
    void sub_8031C364(s32 reason);
    void sub_8031C624(s32 reason);
    void sub_8031C7BC(s32 reason);
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    f32 get_field_4d4();
    f32 get_field_4d0();
    void render_shadows();
    static void advance_intro_stage(NJS_OBJECT *);
    void update_ground_probe();
    s32 is_anim_5();
    u16 sub_8031D878();
    void spawn_trap_a();
    void spawn_trap_b();
    f32 approach_value(f32 farg0, f32 farg1);
    void clamp_min_height();
    void update_position_from_offsets();
    void init_state();
    static void release_static_instance();
    static TObjEneRecon *create(TObjEneRecobox *owner, u16 id, s32 index, Vec *pos, Vec *dir);
    static void load_resources();
    void*get_field_38_ptr();
    s32 calc_scaled_value();
    void handle_message(s32 message);
    void retarget();
    void select_next_target();
    void update_collide_flag();
    void set_flag2(f32 x, f32 z, f32 r);
    void set_orbit_destination(s32 arg1);
    void advance_field398();
    void sync_height();

    s32 state_step;               // step inside the current action state
    u8 pad_3C4[0x1C];
    f32 rise_speed;               // vertical speed added to hover_height while knocked back (gravity 0.1)
    f32 move_speed;               // horizontal speed: length of velocity, decays by 0.98
    u8 pad_3E8[0x30];
    s32 floor_flags;              // flags of the floor under it (update_ground_probe); 0x4000 = reflective
    Vec floor_point;              // that floor point
    Vec spawn_direction;          // the box's launch direction (ctor)
    u16 owner_id;                 // entity id of the TObjEneRecobox that spawned it
    u8 pad_436[0x2];
    Vec owner_position;           // where that box stood at the spawn
    u32 recon_flags;              // bit 1: done for (exploded, faded out or let go by its box)
    f32 hover_height;
    Vec velocity;                 // xz drift of the knockback (normalize_vector_xz)
    u8 pad_458[0x8];
    f32 offset_max;               // orbit height over the box: 45 + 2x + the box's recon_offset_max
    f32 pad_464;
    f32 rotate_rad;               // orbit radius: 50 + 5x + the box's recon_rotate_rad
    u8 pad_46C[0xC];
    TParticleCtrl *emitter;       // particle emitter 0x217 trailing the body
    s32 emitter_side;             // flips each frame: the emitter swings 3 units to either side
    TUnk_80494938 fade;
    u8 pad_49C[0x34];
    f32 m_4d0;
    u8 pad_4D4[0x4];
    s32 m_4d8;
    u8 pad_4DC[0x8];
};

LAYOUT_ASSERT(TObjEneRecon_size, sizeof(TObjEneRecon) == 0x4E4);

#endif
