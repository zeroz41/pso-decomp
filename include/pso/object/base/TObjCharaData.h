#ifndef PSO_OBJECT_BASE_TOBJCHARADATA_H
#define PSO_OBJECT_BASE_TOBJCHARADATA_H

#include "types.h"

// TObjChara's constants, defined in TObjCharaData.cpp (interim data unit until it folds into TObjChara).
// Hit-chance loss per unit of attacker-to-target distance.
extern const f64 accuracy_distance_penalty_scale;
// The 0.5 and 3.0 of the Newton step 0.5 * g * (3 - x * g * g) for 1 / sqrt(x).
extern const f64 newton_sqrt_half;
extern const f64 newton_sqrt_three;
extern const char meseta_label_text[7];
extern const char miss_label_text[5];
// Angle units (0x10000 a turn) per radian.
extern const f64 angle_units_per_radian;

#endif
