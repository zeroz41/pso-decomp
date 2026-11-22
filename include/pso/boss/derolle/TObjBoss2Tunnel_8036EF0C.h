#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8036EF0C_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8036EF0C_H

#include "types.h"

extern "C" {
s32 get_display_copy_filter(void);
}

void set_display_copy_filter(int enabled);
// Turns the display copy filter flag back on without touching GX (shutdown_and_reset_system).
void reset_display_copy_filter(void);

#endif
