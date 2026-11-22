#ifndef PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNER_H
#define PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNER_H
#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80490470.h"

class TObject;
class TParticleCtrl;
class TeneFakeTecThunderEff;

struct TObjEneDarkGunner : public TObjEnemyCustom {
    TObjEneDarkGunner(TObject *parent, void *set_data);
    virtual ~TObjEneDarkGunner();
    static void *create(void *set_data);
    void sub_800A27CC();
    void update_move();     // mode 1: drop, spin and glide (drop/move motions)
    void update_attack();   // mode 2: attack/await/pullback, fires the thunder shots
    void sub_800A16C4();    // mode 3
    void update_damage();   // mode 4: damage/duckdame motions
    void update_dying();    // mode 5: die motion, then the death fade
    virtual void run_task();
    virtual void render();
    void set_fields_24_34_from_global(void*);
    void sub_800A159C();
    void sub_800A1520();
    int is_flag_set_388_bit26();
    void apply_fall_damage_flag();
    void set_hidden_flag();
    void trigger_action_if_not_flagged();
    void update_hide_sequence();
    virtual s32 update_movement_status();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual s32 update_action_hold_status();
    virtual void refresh_target();
    void step_along_ground();
    void update_move_to_destination();
    int sub_800A1808();
    void spawn_hamon_effects(s32 type, s32 variant, f32 scale);
    void render_shadow();
    static void cleanup_effects();
    f32 render_y_offset;
    f32 hover_height;  // integrated from hover_speed, clamped to 0..9
    f32 hover_speed;
    s16 spin_count;    // 0x555 turns before the move state
    s16 attack_timer;
    s16 hide_timer;
    s16 pad_39e;
    f32 move_speed;     // fed to enemy_set_heading_velocity, decays each frame
    f32 move_distance;  // sum of move_speed; the move ends past a parameter
    s32 move_heading;
    s32 turn_delay;
    s32 attack_count;
    Vec shadow_pos;  // above position by 5 + hover_height; render_shadow draws here
    Vec child_offsets[4];
    TeneFakeTecThunderEff *children[4];  // the beams update_attack spawns at child_offsets
    TParticleCtrl *trail_emitter;  // particle 0xD9/0xD4 at shadow_pos while m_388 & 0x200000
    TParticleCtrl *glow_emitter;   // particle 0xDB at body_center while m_388 & 0x800000
    TUnk_80490470 render_control;
    s32 material_phase;
    u16 center_id;  // entity id of the TObjEneDarkGunCenter that links it
    u8 pad_42a[2];
};
extern "C" const char *TObjEneDarkGunner__class_name;

LAYOUT_ASSERT(DarkGunnerSize, sizeof(TObjEneDarkGunner)==0x42C);
#endif
