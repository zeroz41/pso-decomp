#include "pso/system/ResourceFile.h"
#include "pso/system/TGStream.h"

s32 get_resource_file_size(const char *filename) {
    return TGStream::get_resource_file_size(filename);
}
