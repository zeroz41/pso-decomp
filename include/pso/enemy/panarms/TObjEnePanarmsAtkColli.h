#ifndef PSO_ENEMY_PANARMS_TOBJENEPANARMSATKCOLLI_H
#define PSO_ENEMY_PANARMS_TOBJENEPANARMSATKCOLLI_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

// The hit volume a Panarms arm attack spawns: it moves by its velocity each
// frame and hits every player and enemy inside its radius once.
struct TObjEnePanarmsAtkColli : public TObjEnemy {
    TObjEnePanarmsAtkColli(TObject *parent, Vec *position, Vec *velocity, s32 type);
    virtual ~TObjEnePanarmsAtkColli();
    virtual void run_task();
    static TObjEnePanarmsAtkColli *create(TObject *parent, Vec *position, Vec *velocity, s32 type);
    void hit_enemy_near(Vec *point);
    void hit_enemy(TObjChara *enemy);
    void hit_player(TObjChara *player);
    void sweep_segment_collisions();
    void check_radius_collisions();

    s32 type;               // 0 a radius check, 1 a segment sweep along the velocity
    f32 radius;             // squared against horizontal_distance_squared
    f32 radius_growth;      // added to the radius every frame
    s32 lifetime;           // frames left before it destroys itself
    TObjChara *last_hit_player;  // hit_player skips the player it hit last
    TObjChara *last_hit_enemy;   // and hit_enemy the enemy
    f32 attack_power;       // the DirectAttackPayload power, from the 0x31 table
};

LAYOUT_ASSERT(TObjEnePanarmsAtkColli_size, sizeof(TObjEnePanarmsAtkColli) == 0x390);
#endif
