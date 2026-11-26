#include "types.h"
#include "pso/npc/NpcEnemyAnimReset.h"
#include "pso/network/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"


void TLobby::forward_npc_enemy() { TObjNpcEnemy::reset_all_anim_fields(); }
void TLobby__sub_802D7A0C(void* p) { TObjNpcEnemy::reset_all_anim_fields(); }
