#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TPlyPhotonChair.h"

extern "C" {

s32 is_lobby_floor_15__15TFontSmallLobbyFv();
s32 test_flags_any(void *, s32);
s32 is_on_current_floor__10TObjPlayerFi(void *);
s32 run_action_state_phase__10TObjPlayerFisi(void *, s32, s32);

s32 obj_isState2_324__9TObjCharaFv();
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
extern const f32 TObjPlayer__data_805DC294;

void TObjPlayer::update_action_animation() {
    u8 *arg0 = (u8 *)this;
    if (obj_isState2_324__9TObjCharaFv() == 0) {
        ((TObjPlayer *)arg0)->update_position_from_target();
        return;
    }
    if (is_on_current_floor__10TObjPlayerFi(arg0) != 0) {
        ((TObjPlayer *)arg0)->sub_8011E204(4);
        if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x800) != 0) {
            run_action_state_phase__10TObjPlayerFisi(arg0, 0xF, 0);
            if (test_flags_any((u8 *)&this->m_858, 1) != 0) {
                this->requested_action = ((TObjPlayer *)arg0)->get_action_animation();
            } else {
                ((TObjPlayer *)arg0)->restart_death_pose();
            }
            ((TObjPlayer *)(arg0 + 0x5FC))->set_pos_z(TObjPlayer__data_805DC294);
            ((TObjPlayer *)arg0)->revive_or_spawn_marker();
            return;
        }
        if ((is_lobby_floor_15__15TFontSmallLobbyFv() != 0) && (((TPlyPhotonChair *)arg0)->is_mounted() != 0)) {
            run_action_state_phase__10TObjPlayerFisi(arg0, 0x18, 0);
            return;
        }
        run_action_state_phase__10TObjPlayerFisi(arg0, 1, 0);
    }
}

}
