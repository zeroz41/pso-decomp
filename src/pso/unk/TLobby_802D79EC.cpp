#include "types.h"
#include "pso/unk/TLobby_802D79EC.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"

extern "C" {

int reset_all_anim_fields__12TObjNpcEnemyFv(void*);

void TLobby::forward_npc_enemy() { TObjNpcEnemy::reset_all_anim_fields(); }
int TLobby__sub_802D7A0C(void* p) { return reset_all_anim_fields__12TObjNpcEnemyFv(p); }

}
