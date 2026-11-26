#ifndef PSO_NETWORK_ENTITYSETFLAGSCMD_H
#define PSO_NETWORK_ENTITYSETFLAGSCMD_H

#include "types.h"

struct G_SetEntitySetFlags_6x76;

void build_6x76_set_entity_set_flags(G_SetEntitySetFlags_6x76 *cmd);

class TEnemyTaskList;
class TObjEnemy;

void append_wave_member(TEnemyTaskList *list, TObjEnemy *enemy);

#endif
