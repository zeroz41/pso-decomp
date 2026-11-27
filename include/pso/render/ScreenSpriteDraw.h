#ifndef PSO_RENDER_SCREENSPRITEDRAW_H
#define PSO_RENDER_SCREENSPRITEDRAW_H

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

// Draws `count` lines through the camera view, each a pair of lines->p points with their lines->col ARGB
// words. Flags: 4 blends, 0x10 joins the points into one strip.
void draw_line_list(NJS_POINT3COL *lines, s32 count, u32 flags);
void draw_with_camera(NJS_SPRITE *sprite, s32 frame_index, s32 flags, f32 depth);

// Empty hooks: the duel start (TLobby::start_duel_battle, TPlayerBattleCtrl4P::start_duel) calls the first two,
// the Dark Falz and Sorcerer renders set_texture_scroll, the 2D line and polygon draws draw_2d_stub.
void start_duel_stub_a(s32);
void start_duel_stub_b(void);
void set_texture_scroll(f32, f32);
void draw_2d_stub(void);

u32 *copy_u32(u32 *p, const u32 *q);
void gx_write_u32(s32 value);
void gx_write_f32x3(f32 x, f32 y, f32 z);
void gx_write_f32x2(f32 x, f32 y);

#endif
