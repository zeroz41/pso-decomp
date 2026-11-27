#ifndef PSO_PLAYER_DAMAGE_BOOKKEEPING_H
#define PSO_PLAYER_DAMAGE_BOOKKEEPING_H
#include "types.h"
class TObjBase;
class TObjChara;
void record_local_damage_if_enabled(TObjChara *victim, TObjBase *attacker, saddr damage);
// Adds damage to the battle scores: the local victim's damage taken and the attacking
// player's damage given (a mine trap counts for the player who placed it).
void record_damage_stats(TObjChara *victim, TObjBase *attacker, s32 damage);
void empty_post_damage_hook(void *defender, void *attacker);
#endif
