#ifndef PSO_OBJECT_FENCE_TOVS2_WALL_RESOURCES_H
#define PSO_OBJECT_FENCE_TOVS2_WALL_RESOURCES_H

#include "pso/object/base/TObjMotion.h"

struct BmlResource;
struct BmlResourceDescriptor;
struct TObjChipParams;

extern "C" {
extern BmlResource *TOVS2Wall01__bml_resource;
extern BmlResourceDescriptor bm_o_vs2_resource_descriptor;
extern CollisionBody ovs2wall01_collision_parts[7];
extern const TObjChipParams vs2_wall_debris_desc;
extern const char *TOVS2__class_name;
extern const char *TOVS2Wreck01__class_name;
extern const char *TOVS2Wreck02__class_name;
extern const char *TOVS2Wreck03__class_name;
extern const char *TOVS2Wreck04__class_name;
extern const char *TOVS2Wreck05__class_name;
extern const char *TOVS2Wreck06__class_name;
extern const char *TOVS2Wall01__class_name;
}

#endif
