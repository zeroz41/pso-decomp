#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_802F3AB4_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_802F3AB4_H

#include "types.h"

class TObject;
class TUnk_804E4BF0;

// The leader's constructor makes boss8_dragon_leader_part; TLobby's floor callbacks clear and release it.
TUnk_804E4BF0 *create_boss8_dragon_leader_part(TObject *parent, void *set_data);
void release_boss8_dragon_leader_part(void);
void clear_boss8_dragon_leader_part(void);

#endif
