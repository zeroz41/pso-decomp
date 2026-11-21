#ifndef PSO_SYSTEM_RELMODULEBUFFER_H
#define PSO_SYSTEM_RELMODULEBUFFER_H

#include "types.h"
#include <stddef.h>

struct OSModuleHeader;

struct RelModuleBuffer {
    void *bss;
    OSModuleHeader *image;
};

typedef char RelModuleBuffer_size[sizeof(RelModuleBuffer) == 8 ? 1 : -1];
typedef char RelModuleBuffer_image_offset[offsetof(RelModuleBuffer, image) == 4 ? 1 : -1];

extern "C" {
RelModuleBuffer *load_rel_module(RelModuleBuffer *module, const char *filename);
OSModuleHeader *get_rel_module_image(RelModuleBuffer *module);
RelModuleBuffer *destroy_rel_module(RelModuleBuffer *module, s16 should_delete);
}

#endif
