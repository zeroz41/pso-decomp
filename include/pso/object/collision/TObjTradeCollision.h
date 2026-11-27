#ifndef PSO_OBJECT_COLLISION_TOBJTRADECOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJTRADECOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjTradeCollision : public TObjCollidable {
    TObjTradeCollision(TObject *parent, void *set_data);
    virtual ~TObjTradeCollision();
    bool is_player_outside_trade_radius(u32);
    virtual void run_task();
    virtual void render();
    f32 trade_radius;  // the scale along x: how close a player has to be
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjTradeCollision_size, sizeof(TObjTradeCollision) == 0xB0);

#endif
