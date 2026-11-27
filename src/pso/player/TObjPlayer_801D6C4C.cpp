#include "types.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/LobbyRuleSettings.h"
#include "pso/effect/particle/TParticleCtrl.h"

void TObjPlayer::reset_particle_ctrl(s32 *ctrl) {
    *ctrl = 0;
    ((TParticleCtrl *)ctrl)->destroy_particle();
}

PlayerBattleScore::~PlayerBattleScore() {
    ((TParticleCtrl *)&timer)->destroy_particle();
}

PlayerBattleScore::PlayerBattleScore() {
    pad_4 = 0;
    TObjPlayer::reset_particle_ctrl(&timer);
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
