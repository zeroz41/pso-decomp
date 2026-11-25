#include "types.h"
#include "pso/unk/TLobby_8030A834.h"
#include "pso/network/TLobby.h"
#include "pso/boss/darkfalz/TBoss4ZakoDraw.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/scene/TScene.h"


int TLobby::get_online_ready_flag() {  return lobby_online_ready_flag; }

void *create_boss4_zako_draw(void *parent) {
    return new TBoss4ZakoDraw((TObject *)parent);
}
