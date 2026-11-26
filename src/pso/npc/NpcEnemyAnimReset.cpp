#include "types.h"
#include "pso/npc/NpcEnemyAnimReset.h"
#include "pso/network/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"


void forward_npc_enemy() { TObjNpcEnemy::reset_all_anim_fields(); }
void reset_npc_enemy_anims_on_floor_load(void* p) { TObjNpcEnemy::reset_all_anim_fields(); }
