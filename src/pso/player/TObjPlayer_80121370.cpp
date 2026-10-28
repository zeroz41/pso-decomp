#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_80121370.h"
#include "pso/unk/text_80087278.h"
#include "pso/item/TUnk_804A08B8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 get_owner_client__5TItemFv(void *);
s32 init_item_timer_event__13TUnk_804A0648Fv(s32, u32, s32, s32);
s32 is_mode_two_and_ready__10TObjPlayerFv();
s32 __nw__15TItemHeapObjectFUl(s32);

void TUnk_804A08B8::emit_marker_effects() {
    s32 arg0 = (s32)this;
    s32 sp8;

    if (is_mode_two_and_ready__10TObjPlayerFv() != 0) {
        ((TObjPlayer *)arg0)->draw_icon(2, (s32)&sp8);
        spawn_particle_effect(&sp8, 0x1BE);
    }
}
}

void marina_bag_start_regen(void *item_pro_armor) {
    s32 temp_r3;

    if ((u32) ((TItemProArmor *)item_pro_armor)->effect_objects != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_item_timer_event__13TUnk_804A0648Fv(temp_r3, (u32)((TItemProArmor *)item_pro_armor)->effect_objects, get_owner_client__5TItemFv(item_pro_armor), 0x5A);
        }
    }
}
