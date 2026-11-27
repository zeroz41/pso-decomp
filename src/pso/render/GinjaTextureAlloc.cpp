#include "types.h"
#include "pso/render/GinjaTextureAlloc.h"
#include "pso/render/GinjaTextureHeader.h"
extern "C" {
#pragma push
#pragma scheduling off
#pragma peephole off
s32 init_texture_header_and_alloc(GinjaTextureHeader *header, u32 width, u32 height, u32 format) {
    s32 result = init_ginja_texture_header(header, width, height, format);
    switch (result) {
    case 0:
        result = alloc_buffer_from_heap(header);
        break;
    }
    return result;
}
#pragma pop
}
