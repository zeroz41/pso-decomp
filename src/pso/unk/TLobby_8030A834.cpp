#include "types.h"
#include "pso/unk/TLobby_8030A834.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TBoss4ZakoDraw.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"


    extern int lobby_online_ready_flag;
int TLobby::get_online_ready_flag() {  return lobby_online_ready_flag; }

void *fn_8030A83C(void *parent) {
    return new TBoss4ZakoDraw((TObject *)parent);
}
