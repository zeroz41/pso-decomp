#include "types.h"
#include "pso/object/base/TObjCharaData.h"

// TObjChara's constants (doubles, MESETA/MISS, angle scale).

__declspec(section ".rodata") const f64 accuracy_distance_penalty_scale = 0.01;

__declspec(section ".rodata") const f64 newton_sqrt_half = 0.5;

__declspec(section ".rodata") const f64 newton_sqrt_three = 3.0;

__declspec(section ".rodata") const char meseta_label_text[7] ATTRIBUTE_ALIGN(4) = "MESETA";

__declspec(section ".rodata") const char miss_label_text[5] ATTRIBUTE_ALIGN(4) = "MISS";

__declspec(section ".rodata") const f64 angle_units_per_radian = 10430.38043493439;
