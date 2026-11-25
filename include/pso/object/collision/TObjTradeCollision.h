#ifndef PSO_OBJECT_COLLISION_TOBJTRADECOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJTRADECOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjTradeCollision : public TObjCollidable {
    TObjTradeCollision(saddr, saddr);
    virtual ~TObjTradeCollision();
    bool is_player_outside_trade_radius(u32);
    virtual void run_task();
    virtual void render();
    u8 unk_AC[0x4];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjTradeCollision_size, sizeof(TObjTradeCollision) == 0xB0);

#endif
