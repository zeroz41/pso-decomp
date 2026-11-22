#ifndef PSO_ENEMY_DD_TOBJENEDD_800BABA4_H
#define PSO_ENEMY_DD_TOBJENEDD_800BABA4_H

#include "types.h"
#include <dolphin/mtx.h>

class TObjEneDD;

void calc_wall_clamped_destination(void *self, void *dest, f32 dx, f32 dz, f32 dist);
void calc_wall_slide_destination(TObjEneDD *self, Vec *out, f32 dx, f32 dz, f32 dist);

#endif
