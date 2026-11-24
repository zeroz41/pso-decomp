#ifndef PSO_ENEMY_TOBJENEMY_H
#define PSO_ENEMY_TOBJENEMY_H
#include "types.h"
#include "pso/enemy/EnemyStateRecord.h"
#include "pso/object/base/TObjChara.h"

struct player_stats;

struct TObjEnemy : public TObjChara {
    TObjEnemy(TObject *parent);
    void refresh_and_send_entity_flags();
    int submit_default_cursor_candidate();
    virtual ~TObjEnemy();
    void draw_motion_model();
    s32 calc_joint_matrices(f32);
    s32 enemy_turn_toward_dest(s32);
    void send_6x0A_enemy_state(void *);
    s32 bind_enemy_combat_stats(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats);
    void set_param(s32);
    s32 remap_sound_for_area(s32 sound_id);
    f32 enemy_wander_home(f32 speed, f32 range_x, f32 range_z, s32 turn_speed);
    virtual void render_shadows();
    s32 send_entity_set_flags();
    void update_prev_position();
    void register_by_id();
    s32 turn_toward_direction(s32 max_step, Vec *direction);
    void award_enemy_experience(s32);
    void distribute_experience();
    // send_6x60_standard_drop_item_request for this enemy.
    int query_lobby_state();
    // distribute_experience, then query_lobby_state; the death reactions call it.
    void refresh_lobby_state();
    void send_6x9C_enemy_low_game_flags(s32);
    void draw_ground_shadow(const Vec *scale, s32 forceDraw);
    virtual void apply_enemy_state(s32 *);
    virtual void apply_hit_message_flags(void *);
    virtual void apply_set_data(void *);
    virtual void clear_lobby_object_state();
    virtual s32 sync_enemy_state(s32 status);
    s32 exchange_object_state(void *record, s16 mode);
    virtual const char *get_name();
    TObjEnemy* groupRoot();
    s32 has_group();
    void link_chain_nodes(TObjEnemy *source, TObjEnemy *destination);
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
    s32 variant;
    u32 state36C;
    void* control;
    static s32 apply_by_index(s16 index, const EnemyStateRecord *record);
    int apply_player_54a00();
    s32 mask_sub_flags(s32 mask);
};
LAYOUT_ASSERT(EnemyBaseSize, sizeof(TObjEnemy)==0x374);
#endif
