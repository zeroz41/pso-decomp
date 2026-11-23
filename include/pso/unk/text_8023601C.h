#ifndef PSO_UNK_TEXT_8023601C_H
#define PSO_UNK_TEXT_8023601C_H

#include "types.h"

#include <dolphin/mtx.h>

// Moves `center` `distance` units toward the camera into `out`.
void offset_point_toward_camera(Vec *center, Vec *out, f32 distance);

#endif
