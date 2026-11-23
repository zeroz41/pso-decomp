#ifndef PSO_UNK_TLOBBY_801E2F94_H
#define PSO_UNK_TLOBBY_801E2F94_H

#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/system/NinjaChunk.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/Draw2D.h"

extern "C" {
s32 TKeyBoardControl__sub_801E3E24(s32 id, saddr name, saddr arg2);
void TLobby__sub_801E3CF0(u32 *p);
s32 TLobby__sub_801E3E9C(s32 id, saddr name, saddr arg2);
}
void reset_line_width(void);
void set_line_width(int a0);

// Draws cell 0 of `sprite` as a quad at its position; flags 4 and 8 mirror the texture's u and v.
void draw_shadow_quad(NJS_SPRITE *sprite, s32 frame, s32 flags);

// Draw a model posed by a motion at a frame.
void draw_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);

#endif
