#ifndef PSO_SYSTEM_RELMODULEBUFFER_H
#define PSO_SYSTEM_RELMODULEBUFFER_H

#include "types.h"
#include <stddef.h>

struct OSModuleHeader;

struct RelModuleBuffer {
    void *bss;
    OSModuleHeader *image;
};

LAYOUT_ASSERT(RelModuleBuffer_size, sizeof(RelModuleBuffer) == 8);
LAYOUT_ASSERT(RelModuleBuffer_image_offset, offsetof(RelModuleBuffer, image) == 4);

extern "C" {
RelModuleBuffer *load_rel_module(RelModuleBuffer *module, const char *filename);
OSModuleHeader *get_rel_module_image(RelModuleBuffer *module);
RelModuleBuffer *destroy_rel_module(RelModuleBuffer *module, s16 should_delete);
}

#endif
