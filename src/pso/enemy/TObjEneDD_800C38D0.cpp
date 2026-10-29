#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneRe2Flower.h"

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
struct Base_Sub_800c38d0 { char pad[0x14]; };
struct V_Sub_800c38d0 : Base_Sub_800c38d0 {
    PADV4
    PADV
    virtual s32 m5();
};
extern "C" {

s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
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
        TObjEneMe3SinowZoa__sub_800D758C(arg0 + 0x3F4);
        if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
            ((TBoss3Volopt *)(arg0 + 0x38))->play_area_se_with_particle();
            return;
        }
        ((TBoss3Volopt *)(arg0 + 0x38))->play_area_sound_effect();
        return;
    case 3:
        if (((V_Sub_800c38d0 *) (arg0 + 0x3F4))->m5() != 0) {
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
