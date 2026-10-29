#ifndef PSO_ENEMY_TOBJENEMY_H
#define PSO_ENEMY_TOBJENEMY_H
#include "types.h"
#include "pso/player/TObjChara.h"
struct TObjEnemy : public TObjChara {
    TObjEnemy(TObject *parent);
    void refresh_and_send_entity_flags();
    int submit_default_cursor_candidate();
    virtual ~TObjEnemy();
    void send_6x0A_enemy_state(void *);
    s32 bind_enemy_combat_stats(u8 *, u8 *, u8 *);
    void set_param(s32);
    s32 remap_sound_for_area(s32 sound_id);
    f32 enemy_wander_home(f32 speed, f32 range_x, f32 range_z, s32 turn_speed);
    virtual void render_shadows();
    s32 send_entity_set_flags();
    void update_prev_position();
    s32 turn_toward_direction(s32 max_step, Vec *direction);
    void award_enemy_experience(s32);
    void distribute_experience();
    void send_6x9C_enemy_low_game_flags(s32);
    void set_flags_B0(u32);
    void sub_800A7798(f32);
    void render_with_position_override(u8 *, s32);
    virtual void vfunc_79(s32 *);
    virtual void apply_hit_message_flags(void *);
    virtual void apply_set_data(void *);
    virtual void clear_lobby_object_state();
    virtual s32 vfunc_74(s32);
    s32 exchange_object_state(s32, s16);
    void sub_8002AE64();
    virtual const char *get_name();
    TObjEnemy* groupRoot();
    u32 subtype;
    u16 targetId;
    s16 resetTimer;
    s16 timer;
    s16 referenceHp;
    TObjEnemy* group;
    TObjEnemy* previous;
    TObjEnemy* next;
    TObjEnemy* children;
    void* movementParameters;
    f32 parameters[5];
    u32 variant;
    u32 state36C;
    void* control;
    static s32 apply_by_index(s16 arg0);
    int apply_player_54a00();
    s32 mask_sub_flags(s32 arg1);
};
typedef char EnemyBaseSize[(sizeof(TObjEnemy)==0x374)?1:-1];
#endif
