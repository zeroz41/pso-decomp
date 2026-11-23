#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/collision/TObjTradeCollision.h"
#include "pso/ui/window/TWindowSubTradeMain_802D3924.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on


const char *TObjTradeCollision__name = "TObjTradeCollision";


extern "C" {
s32 is_player_outside_trade_radius__18TObjTradeCollisionFUl(void *, int);

void TObjTradeCollision::render() {  }

void run_task__18TObjTradeCollisionFv(saddr arg0) {
    s32 i;
    i = 0;
    do {
        if (is_player_outside_trade_radius__18TObjTradeCollisionFUl((void *)arg0, (int)i) != 0) {
            set_trade_range_bit((i));
        } else {
            clear_trade_range_bit((i));
        }
        i += 1;
    } while (i < 4);
}

}
TObjTradeCollision::~TObjTradeCollision() {

}


TObjTradeCollision::TObjTradeCollision(saddr parent, saddr set_data) : TObjCollidable((TObject *)parent) {
    *(s32 *)((s8 *)this + 0) = (s32) ((saddr)TObjTradeCollision__name);
    ((TObjTradeCollision *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    *(f32 *)((s8 *)this + 0xAC) = (f32) this->scale.x;
    ((TObject *)(((u8 *)this)))->disallow_rendering();
}

void *TObjTradeCollision::create(void *set_data) {
    void *o = (void *)new TObjTradeCollision((saddr)tl_05, (saddr)set_data);
    return o;
}

