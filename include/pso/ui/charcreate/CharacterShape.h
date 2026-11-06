#ifndef PSO_UI_CHARCREATE_CHARACTERSHAPE_H
#define PSO_UI_CHARCREATE_CHARACTERSHAPE_H
#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

struct CreationShapePoint { f32 width, height; };
struct CreationShapeTriangle { s32 sample[3]; };
struct CreationShapeBlend {
    s32 region;
    f32 weights[3];
    CreationModelNodeState *destination, *sources[3];
};
void reset_creation_body_shapes();
void reset_creation_head_shapes();
#endif
