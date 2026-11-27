#ifndef PSO_ENEMY_BRINGER_BRINGEREFFECTS_H
#define PSO_ENEMY_BRINGER_BRINGEREFFECTS_H

#include "types.h"

class TObjBase;
class TObjChara;

// The ring vertex directions and colors TObjEneDf2BringerRing reads; TObjEneDf2Bringer fills them at load.
void init_bringer_effect_tables(void);
void bringer_effect_cleanup_noop(void);

#endif
