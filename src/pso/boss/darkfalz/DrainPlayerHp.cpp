#include "types.h"
#include "pso/boss/darkfalz/DrainPlayerHp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"


// Takes up to `damage` HP from the player in Dark Falz's arena and returns what was taken
// (the arena twin of TBoss6PlotFalz::damage_player_hp).
u32 drain_player_hp(u16 client, u32 damage) {
    u32 drained;
    TObjPlayer *p;
    s32 hp;
    drained = damage;
    if (client == 0xFFFF || (p = get_player_by_client_id(client)) == NULL ||
        is_player_in_boss_area(client) == 0) {
        return 0;
    }
    hp = p->get_actor_hp();
    if (hp < drained) {
        drained = hp;
    }
    if (p->obj_isState2_324() != 0) {
        return drained;
    }
    hp -= drained;
    send_6x2F_change_player_hp(0xFFFF, client, hp);
    p->gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(p, drained));
    return drained;
}
