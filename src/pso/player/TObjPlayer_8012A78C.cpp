#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 get_owner_client__5TItemFv(void *);
s32 init_item_timer_event__13TUnk_804A0648Fv(s32, s32, s32, s32);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 construct_timer_event__13TUnk_804A0628Fv(s32, s32, s32, s32);

void TObjPlayer::start_srank_regen_timer() {
    s32 temp_r3;
    s32 temp_r3_2;

    switch (*(s32 *)&this->unk_1F8) {
    case 3:
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_item_timer_event__13TUnk_804A0648Fv(temp_r3, *(s32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
        }
        return;
    case 4:
        temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3_2 != 0) {
            construct_timer_event__13TUnk_804A0628Fv(temp_r3_2, *(s32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
        }
        break;
    }
}

}
