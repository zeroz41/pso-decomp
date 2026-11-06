#include "pso/object/ambient/TObjRain.h"

#include "types.h"

struct RecoveredGlobal_80197C84___vt__8TObjRain {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 __ct__7TObjectFP7TObject();
extern RecoveredGlobal_80197C84___vt__8TObjRain __vt__8TObjRain;
extern s32 lbl_805D3420;
void TObjRain::render() { draw_streaks(); }
void TObjRain::run_task() { update_drops(); }
typedef char RecoveredGlobal_80197C84___vt__8TObjRain_size[sizeof(RecoveredGlobal_80197C84___vt__8TObjRain) == 0x18 ? 1 : -1];
TObjRain::~TObjRain() {}
u8 *__ct__8TObjRainFv(u8 *rain, s32 arg1, u32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)rain + 0x18) = &__vt__8TObjRain.value;
    *(s32 *)((s8 *)rain + 0) = (s32) lbl_805D3420;
    *(u32 *)((s8 *)rain + 0x21C) = (arg2 > 0x10U) ? 0x10U : arg2;
    ((TObjRain *)rain)->init_drops();
    return rain;
}

}
