#ifndef PSO_OBJECT_WRECK_TOWRECK_ANCIENT_RESOURCES_H
#define PSO_OBJECT_WRECK_TOWRECK_ANCIENT_RESOURCES_H

#include "pso/object/TObjChip.h"
#include "pso/object/base/TObjMotion.h"

struct BmlResource;
struct BmlResourceDescriptor;

struct AncientWreckDebrisOffsets {
    Vec offsets[9];
};

LAYOUT_ASSERT(AncientWreckDebrisOffsets_size, sizeof(AncientWreckDebrisOffsets) == 0x6C);

extern "C" {
extern BmlResourceDescriptor bm_o_wreck_ancient_resource_descriptor;
extern BmlResourceDescriptor TOWreckAncient__resource_descriptor;
extern BmlResource *wreck_ancient_bml_resource;
extern BmlResource *wreck_ancient_brakable_bml_resource;
extern const CollisionBody TOWreckAncient__collision_body_templates[7];
extern const AncientWreckDebrisOffsets TOWreckAncientBrakable__debris_table;
extern const TObjChipParams TOWreckAncientBrakable__debris_param_table;
}

#endif
