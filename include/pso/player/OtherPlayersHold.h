#ifndef PSO_PLAYER_OTHERPLAYERSHOLD_H
#define PSO_PLAYER_OTHERPLAYERSHOLD_H

#include "types.h"

class TObject;

void release_other_players_hold(TObject *caller);
void impose_other_players_hold(TObject *caller);

#endif
