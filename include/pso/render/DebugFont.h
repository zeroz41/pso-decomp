#ifndef PSO_RENDER_DEBUG_FONT_H
#define PSO_RENDER_DEBUG_FONT_H
#include "types.h"

enum { DEBUG_FONT_WIDTH = 128, DEBUG_FONT_HEIGHT = 128,
       DEBUG_FONT_TEXTURE_BYTES = DEBUG_FONT_WIDTH * DEBUG_FONT_HEIGHT / 2 };
struct _GXTexObj;
extern "C" {
extern u8 debug_font_texture_i4[DEBUG_FONT_TEXTURE_BYTES];
extern struct _GXTexObj debug_font_texture_object;
void render_debug_text(u32 enabled);
}
#endif
