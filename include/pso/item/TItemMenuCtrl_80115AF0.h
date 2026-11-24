#ifndef PSO_ITEM_TITEMMENUCTRL_80115AF0_H
#define PSO_ITEM_TITEMMENUCTRL_80115AF0_H

#include "types.h"

void advance_angle_wrap(s32 *arg0, s32 blade_speed);
struct Vec;
struct StarLightParameters;
class TObject;
class TEffStarLight2D;

TEffStarLight2D *spawn_star_light_2d(const Vec *position, const StarLightParameters *parameters, TObject *parent);
s32 decrement_timer(u32 *packed, s32 step);

#endif
