#include "pso/misc/MaterialOpacityFade.h"
#include "pso/misc/RenderFadeState.h"
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneRe2Flower.h"

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();

extern "C" {

s32 enemy_clear_target__12TObjEneDD_STFUs(void *);

void TObjEneDD::handle_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->vfunc_95();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 8);
        ((TObjEneDD *)arg0)->set_field_378(2);
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        ((TObjEneRe2Flower *)arg0)->fade.start_fade_in();
        if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
            ((TBoss3Volopt *)(arg0 + 0x38))->play_area_se_with_particle();
            return;
        }
        ((TBoss3Volopt *)(arg0 + 0x38))->play_area_sound_effect();
        return;
    case 3:
        if (((TObjEneRe2Flower *)arg0)->fade.advance_toward_max() != 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state(2);
        }
    case 1:
        return;
    case 0:
        advance_animation();
        this->vfunc_102();
        this->vfunc_88();
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFF7);
        break;
    }
}

void TObjEneRe2Flower::dispatch_action(s32 arg1) {
    switch (arg1) {
    case 4:
        this->vfunc_95();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneDD::noop() {  }

}
