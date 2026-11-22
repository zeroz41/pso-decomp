#ifndef PSO_ENEMY_GIBBLES_TOBJENEGIBBLES_H
#define PSO_ENEMY_GIBBLES_TOBJENEGIBBLES_H
#include "types.h"

struct NJS_OBJECT;
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"

struct TObjEneGibbles : public TObjEnemy {
    virtual ~TObjEneGibbles();
    void sub_802D8580();
    virtual void render();
    virtual void run_hit_reaction();
    virtual void run_task();
    void sub_802DBC94(s32);
    void update_wander();
    void sub_802DA7A4();
    void sub_802DA0BC();
    void sub_802D8984();
    void sub_802D8140();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual s32 is_target_in_attack_range();
    virtual void run_attack_action();
    virtual int test_flag_256();
    virtual void run_miss_reaction();
    virtual void run_death_reaction();
    void *get_center();
    u32 resolve_sound_id(u32 sound_id);
    s32 m_374;
    u8 unk_378[0x4];
    s16 m_37c;
    u8 unk_37E[0x2];
    s32 m_380;
    u8 unk_384[0x4];
    s16 m_388;
    u8 unk_38A[0x2];
    f32 m_38c;
    u8 unk_390[0x4];
    f32 m_394;
    u8 unk_398[0x4];
    s32 m_39c;
    u8 unk_3A0[0x10];
    u8 * m_3b0;
    u8 unk_3B4[0x4];
    void * m_3b8;
    s32 m_3bc;
    u8 unk_3C0[0x8C];
    static void set_min_clamped_entry_value(s32 arg0, s32 arg1, f32 fC);
    s32 spawn_ground_impact_effects(const Vec *pos, f32 scale);
    s32 spawn_ground_contact_effect();
    void play_ground_contact_sound();
    void play_distance_sound();
    void update_shadow_height();
    void update_position();
    void sync_state();
    void update_move_state();
    void update_action_state();
    void update_death_sequence();
    void update_spawn_state();
    void init_state();
    void clamp_angle(s32 arg1);
    void init_params();
    static void *create(void *arg0);
    static void free_static();
    static void load_resources();
    void turn_toward_target();
    void slam_damage_players(s32 arg1);
};
LAYOUT_ASSERT(TObjEneGibbles_size, sizeof(TObjEneGibbles) ==0x44C);

extern "C" {
u8 *TObjEneGibbles__ct(u8 *arg0, void *parent, saddr arg2);
void TObjEneGibbles__sub_802D7A54(void *arg0);
void TObjEneGibbles__sub_802D7E3C(void);
void TObjEneGibbles__sub_802D8034(void);
void TObjEneGibbles__sub_802D8E8C(u8 *arg0);
s32 TObjEneGibbles__sub_802D9A04(void *target);
void render__14TObjEneGibblesFv(TObjEneGibbles *arg0);
}
void gibbles_render_node_callback(NJS_OBJECT *);
extern "C" {
void render_and_get_joint_pos__14TObjEneGibblesFPvii(u8 *arg0, saddr arg1, s32 arg2);
void run_task__14TObjEneGibblesFv(TObjEneGibbles *arg0);
void slam_damage_players__14TObjEneGibblesFl(s32 target, s32 arg1);
}

#endif
