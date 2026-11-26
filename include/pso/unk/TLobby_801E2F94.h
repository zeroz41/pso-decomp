#ifndef PSO_UNK_TLOBBY_801E2F94_H
#define PSO_UNK_TLOBBY_801E2F94_H

#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/system/NinjaChunk.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/Draw2D.h"

// Opens an AFS file and spins the input loop until its table of contents is read.
s32 open_afs_file_wait_input(s32 id, const char *name, void *buf, s32 size);
void bswap_u32_in_place(u32 *p);
s32 open_afs_file_wait_render(s32 id, const char *name, void *buf, s32 size);
void reset_line_width(void);
void set_line_width(int a0);

// Draws cell 0 of `sprite` as a quad at its position; flags 4 and 8 mirror the texture's u and v.
void draw_shadow_quad(NJS_SPRITE *sprite, s32 frame, s32 flags);

// Draw a model posed by a motion at a frame.
void draw_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);

struct Ctrl_801E352C {
    u8 pad[4];
    u32 *data;
};

struct DrawTransformedPrimitiveLines {
    Vec *positions;
    u32 *colors;
};

#endif
