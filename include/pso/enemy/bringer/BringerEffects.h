#ifndef PSO_ENEMY_BRINGER_BRINGEREFFECTS_H
#define PSO_ENEMY_BRINGER_BRINGEREFFECTS_H

#include "types.h"

// The ring vertex directions and colors TUnk_8048FE7C reads; TObjEneDf2Bringer fills them at load.
void init_bringer_effect_tables(void);
void bringer_effect_cleanup_noop(void);
// Builds a TObjEneDf2Bringer_Eff_Rush in TObject::operator new(0x34)'s memory (see BringerEffects.cpp).
u8 *construct_bringer_rush_effect(u8 *rush, saddr parent, u8 *source, saddr recipient, f32 speed);

#endif
