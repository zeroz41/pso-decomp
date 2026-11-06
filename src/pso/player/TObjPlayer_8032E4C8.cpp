#include "types.h"
#include "pso/player/TObjPlayer_8032E4C8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804EDD44.h"
#include "pso/TMainTask.h"

void start_guardianna_wall_card(s32 arg0, s32 arg1, s32 arg2) {
    new TUnk_804EDD44(tl_05, (f32 *)arg1, (f32 *)arg2, -0x100, arg0);
}

void TObjPlayer::start_guardianna_hit_card(s32 arg0, u32 *arg1, s32 arg2) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD44(tl_05, (ActorBodyHit *)arg1, (f32 *)arg2, -0x100, arg0);
    }
}

void TItemWpnCardEffect__sub_8032E588(s32 arg0, s32 arg1, s32 arg2) {
    new TUnk_804EDD44(tl_05, (f32 *)arg1, (f32 *)arg2, 0xFFFF0000, arg0);
}

void TObjPlayer::create_aux_object(s32 arg0, u32 *arg1, s32 arg2) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD44(tl_05, (ActorBodyHit *)arg1, (f32 *)arg2, 0xFFFF0000, arg0);
    }
}

void TObjPlayer__sub_8032E648(s32 arg0, s32 arg1, s32 arg2) {
    new TUnk_804EDD44(tl_05, (f32 *)arg1, (f32 *)arg2, 0, arg0);
}

void TObjPlayer::create_network_object(s32 arg0, u32 *arg1, s32 arg2) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD44(tl_05, (ActorBodyHit *)arg1, (f32 *)arg2, 0, arg0);
    }
}
