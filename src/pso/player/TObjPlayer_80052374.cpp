#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/player/TObjPlayer.h"

struct C_80052390 { f32 a, b, c, d; };

extern int saved_model_render_flags;
extern int saved_chunk_polygon_flags_and_mask;
extern int saved_chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_and_mask;
extern int model_render_flags;
extern const f32 lbl_805D8ADC;
extern s32 lbl_805D8AE8;
extern const f32 lbl_805D8AEC;
void TObjPlayer::sync_player_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }
void TObjPlayer__sub_80052390(f32 x) {
    C_80052390 c;
    s32 old = (*(s32 *)&model_render_flags);
    (*(s32 *)&model_render_flags) = old & ~0x10;
    (*(s32 *)&saved_model_render_flags) = old;
    (*(s32 *)&saved_chunk_polygon_flags_and_mask) = (*(s32 *)&chunk_polygon_flags_and_mask);
    (*(s32 *)&saved_chunk_polygon_flags_or_mask) = (*(s32 *)&chunk_polygon_flags_or_mask);
    (*(s32 *)&model_render_flags) |= lbl_805D8AE8;
    set_chunk_material_override_pair(0xFF00, 0x800);
    c.a = lbl_805D8AEC + x;
    c.b = c.c = c.d = lbl_805D8ADC;
    ((TUnk_80494AE0 *)((f32 *)&c))->set_chunk_material_color();
}
