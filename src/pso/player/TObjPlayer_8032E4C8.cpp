#include "types.h"
#include "pso/player/TObjPlayer_8032E4C8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804EDD44.h"
#include "pso/system/task/TMainTask.h"

void start_guardianna_wall_card(s32 item_id, saddr arg1, saddr direction) {
    new TUnk_804EDD44(tl_05, (f32 *)arg1, (f32 *)direction, -0x100, item_id);
}

void TObjPlayer::start_guardianna_hit_card(s32 item_id, u32 *arg1, saddr direction) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD44(tl_05, (ActorBodyHit *)arg1, (f32 *)direction, -0x100, item_id);
    }
}

void TItemWpnCardEffect__sub_8032E588(s32 item_id, saddr arg1, saddr direction) {
    new TUnk_804EDD44(tl_05, (f32 *)arg1, (f32 *)direction, 0xFFFF0000, item_id);
}

void TObjPlayer::create_aux_object(s32 item_id, u32 *arg1, saddr direction) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD44(tl_05, (ActorBodyHit *)arg1, (f32 *)direction, 0xFFFF0000, item_id);
    }
}

void TObjPlayer__sub_8032E648(s32 item_id, saddr arg1, saddr direction) {
    new TUnk_804EDD44(tl_05, (f32 *)arg1, (f32 *)direction, 0, item_id);
}

void TObjPlayer::create_network_object(s32 item_id, u32 *arg1, saddr direction) {
    if ((arg1 != NULL) && ((u32) *arg1 != 0U)) {
        new TUnk_804EDD44(tl_05, (ActorBodyHit *)arg1, (f32 *)direction, 0, item_id);
    }
}
