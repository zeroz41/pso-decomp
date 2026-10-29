#ifndef PSO_MISC_TPLYPHOTONCHAIR_80142524_H
#define PSO_MISC_TPLYPHOTONCHAIR_80142524_H

#include "types.h"
#include "pso/render/render_util.h"

extern "C" {
int TLobby__sub_80142944(void *p);
void restore_actor_draw_lighting(s32);
}
void setup_actor_draw_lighting(void);

#endif
