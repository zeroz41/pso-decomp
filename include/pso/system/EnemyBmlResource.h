#ifndef PSO_SYSTEM_ENEMY_BML_RESOURCE_H
#define PSO_SYSTEM_ENEMY_BML_RESOURCE_H

struct BmlResource;
struct BmlResourceDescriptor;

extern "C" {
BmlResource *load_enemy_bml_resource(BmlResourceDescriptor *descriptor);
BmlResource *load_enemy_bml_resource_named(BmlResourceDescriptor *descriptor, const char *archive_filename);
}

#endif
