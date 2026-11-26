#include "types.h"
#include "pso/unk/text_803DA12C.h"
extern "C" {
s32 init_ginja_texture_header(void *p);
void alloc_buffer_from_heap(void *header);
#pragma push
#pragma scheduling off
#pragma peephole off
void init_texture_header_and_alloc(void *p) {
    switch (init_ginja_texture_header(p)) {
    case 0:
        alloc_buffer_from_heap(p);
        break;
    }
}
#pragma pop

}
