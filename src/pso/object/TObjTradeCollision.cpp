#include "types.h"
#include "pso/object/TObjTradeCollision.h"
#include "pso/misc/TWindowSubTradeMain_802D3924.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjTradeCollision.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct RecoveredGlobal_802C8034___vt__18TObjTradeCollision {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 is_player_outside_trade_radius__18TObjTradeCollisionFUl(void *, int);
extern s32 __vt__18TObjTradeCollision[];
extern s32 TObjTradeCollision__name;
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjTradeCollision::render() {  }

void run_task__18TObjTradeCollisionFv(s32 arg0) {
    s32 var_r31;
    var_r31 = 0;
    do {
        if (is_player_outside_trade_radius__18TObjTradeCollisionFUl((void *)arg0, (int)var_r31) != 0) {
            set_trade_range_bit((var_r31));
        } else {
            clear_trade_range_bit((var_r31));
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

}
TObjTradeCollision::~TObjTradeCollision() {

}
extern "C" {

extern void *tl_05;

typedef char RecoveredGlobal_802C8034___vt__18TObjTradeCollision_size[sizeof(RecoveredGlobal_802C8034___vt__18TObjTradeCollision) == 0x38 ? 1 : -1];
u8 *TObjTradeCollision__ct(u8 *trade_collision, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(trade_collision, arg1);
    *(s32 **)((s8 *)trade_collision + 0x18) = &(*(RecoveredGlobal_802C8034___vt__18TObjTradeCollision *)&__vt__18TObjTradeCollision).value;
    *(s32 *)((s8 *)trade_collision + 0) = (s32) TObjTradeCollision__name;
    ((TObjTradeCollision *)(trade_collision))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)trade_collision + 0xAC) = (f32) ((TObjTradeCollision *)trade_collision)->scale.x;
    disallow_rendering__7TObjectFv((TObject *)(trade_collision));
    return trade_collision;
}

void *TObjTradeCollision__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = TObjTradeCollision__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}
