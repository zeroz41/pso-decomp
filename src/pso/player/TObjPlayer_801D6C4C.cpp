#include "types.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

void TObjPlayer::reset_particle_ctrl(s32 *ctrl) {
    *ctrl = 0;
    ((TParticleCtrl *)ctrl)->destroy_particle();
}

s32 destroy__10TObjPlayerFis(saddr ctrl, s16 flags) {
    if (ctrl != 0) {
        ((TParticleCtrl *)ctrl)->destroy_particle();
        if (flags > 0) {
            ::operator delete((void *)ctrl);
        }
    }
    return ctrl;
}

PlayerBattleScore::PlayerBattleScore() {
    pad_4 = 0;
    TObjPlayer::reset_particle_ctrl(&timer);
}

}

s32 LobbyRuleSettings::get_sonar_count() {
    s32 count = sonar_count;
    if ((count < 0) || (count > 99)) {
        return 0;
    }
    return count;
}

void LobbyRuleSettings::set_sonar_count(s32 count) {
    if ((count < 0) || (count > 99)) {
        count = 0;
    }
    sonar_count = count;
}
