#include "types.h"
#include "pso/object/collision/TObjTradeCollision.h"
#include "pso/network/TradeSession.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on


const char *trade_collision_name = "TObjTradeCollision";


extern "C" s32 is_player_outside_trade_radius__18TObjTradeCollisionFUl(TObjTradeCollision *object, u32 client);

void TObjTradeCollision::render() {  }

void TObjTradeCollision::run_task() {
    s32 i;
    i = 0;
    do {
        if (is_player_outside_trade_radius__18TObjTradeCollisionFUl(this, i) != 0) {
            set_trade_range_bit(i);
        } else {
            clear_trade_range_bit(i);
        }
        i += 1;
    } while (i < 4);
}

TObjTradeCollision::~TObjTradeCollision() {

}


TObjTradeCollision::TObjTradeCollision(TObject *parent, ObjectSetData *set_data) : TObjCollidable(parent) {
    m_name = trade_collision_name;
    apply_object_set_data(set_data);
    trade_radius = this->scale.x;
    disallow_rendering();
}

void *TObjTradeCollision::create(ObjectSetData *set_data) {
    void *o = (void *)new TObjTradeCollision(tl_05, set_data);
    return o;
}

