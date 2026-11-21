#ifndef PSO_BOSS_OLGAFLOW_TBOSS6ROCKCHASE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6ROCKCHASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct GinjaTextureList;
struct NJS_OBJECT;

struct TBoss6RockChase : public TObjCollidable {
    TBoss6RockChase(TObject *parent, const Vec *position, s32 size_kind);
    virtual ~TBoss6RockChase();
    TObject *owner;
    u32 m_b0;
    u32 m_b4;
    u8 _padB8[0x4];
    u32 m_bc;
    NJS_OBJECT *model;
    GinjaTextureList *textures;
    void damage_players_in_range();
    virtual void render();
    virtual void run_task();
    static TBoss6RockChase *spawn(TObject *parent, const Vec *position);
};

LAYOUT_ASSERT(TBoss6RockChase_size, sizeof(TBoss6RockChase) == 0xC8);

extern "C" {
void *__dt__15TBoss6RockChaseFv(void *arg0, s16 arg1);
}

#endif
