#ifndef PSO_BOSS_OLGAFLOW_TBOSS6ROCKCHASE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6ROCKCHASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;

// The rock model a size kind draws and how far its landing hurts.
struct TBoss6RockChaseKind {
    s32 model;
    f32 radius;
};

// A rock that drops on a player and crushes the floor where it lands.
struct TBoss6RockChase : public TObjCollidable {
    TBoss6RockChase(TObject *parent, const Vec *position, s32 size_kind);
    virtual ~TBoss6RockChase();
    TObject *owner;
    s32 size_kind;   // index into boss6_rock_chase_model_radius_table
    s32 delay;       // frames before it starts to fall
    f32 fall_speed;
    s32 spin_speed;  // added to rotation_y every frame
    NJS_OBJECT *model;
    NJS_TEXLIST *textures;
    void damage_players_in_range();
    virtual void render();
    virtual void run_task();
    static TBoss6RockChase *spawn(TObject *parent, const Vec *position);
};

LAYOUT_ASSERT(TBoss6RockChase_size, sizeof(TBoss6RockChase) == 0xC8);

#endif
