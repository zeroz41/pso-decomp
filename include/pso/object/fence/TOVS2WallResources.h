#ifndef PSO_OBJECT_FENCE_TOVS2_WALL_RESOURCES_H
#define PSO_OBJECT_FENCE_TOVS2_WALL_RESOURCES_H

#include "pso/object/base/TObjMotion.h"

struct BmlResource;
struct BmlResourceDescriptor;
struct TObjChipParams;

extern "C" {
extern BmlResource *vs2_wall01_bml_resource;
extern BmlResourceDescriptor bm_o_vs2_resource_descriptor;
extern CollisionBody ovs2wall01_collision_parts[7];
extern const TObjChipParams vs2_wall_debris_desc;
extern const char *vs2_class_name;
extern const char *vs2_wreck01_class_name;
extern const char *vs2_wreck02_class_name;
extern const char *vs2_wreck03_class_name;
extern const char *vs2_wreck04_class_name;
extern const char *vs2_wreck05_class_name;
extern const char *vs2_wreck06_class_name;
extern const char *vs2_wall01_class_name;
}

#endif
