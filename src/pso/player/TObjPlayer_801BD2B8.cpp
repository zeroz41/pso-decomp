#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

extern "C" {

int TObjPlayer__sub_801C2114(void);

extern "C" {

void TObjPlayer::update_input_and_draw() {
    s32 ctl = (s32)this;
    if (is_current_area_item_enabled() == 0) {
        ((TObjPlayer *)ctl)->set_action_provider_variant((int) (TObjPlayer__sub_801C2114()));
    }
    ((TObjPlayer *)ctl)->init_idle_animation();
    ((TObjPlayer *)ctl)->draw();
    ((TObjPlayer *)ctl)->update_action_animation();
}

}

}
