#ifndef PSO_UI_UI_SPRITE_H
#define PSO_UI_UI_SPRITE_H
#include "types.h"
#include "pso/math/TMath.h"
#include "pso/system/NinjaTypes.h"

// Character-creation screen textures and sprite cells.
extern NJS_TEXLIST creation_sprite_table;
extern NJS_TEXANIM creation_sprite_cells_common[143];
extern NJS_TEXANIM creation_sprite_cells_japanese[49];  // Japanese cells (creation_sprite_table_index 0)
extern NJS_TEXANIM creation_sprite_cells_other_language[49];  // other-language cells
extern const char *ccconsole_pvm_file_name_table[2];

// The ruler lines (16 point pairs) and quad drawn by draw_creation_ruler_lines.
extern const NJS_POINT3 creation_ruler_line_vertices[32];
extern NJS_POINT3 creation_ruler_line_verts[4];
extern u32 creation_ruler_line_colors[4];
extern NJS_POINT3COL creation_ruler_line_desc;

void draw_creation_ruler_lines(f32 fade);

struct UISpriteTint {
    f32 alpha;
    f32 channels[3];
};

// One corner of the sprite draw_compass_sprite draws.
struct CompassSpriteVertex {
    f32 x, y, z;
    f32 u, v;
    s32 color;
};

void draw_compass_sprite(const NJS_SPRITE *sprite, s32 index, s32 color, s32 flags, f32 depth);
extern "C" {
void draw_creation_sprite_offset(s32 sprite_id, const vec2f* position, const vec2f* scale,
                                 f32 depth, f32 alpha);
}
void draw_ui_sprite_tinted(s32 sprite_id, vec2f* position, vec2f* scale, UISpriteTint* tint,
                           f32 depth);
void draw_ui_sprite_shaded(s32 sprite_id, const vec2f* position, const vec2f* scale,
                          f32 depth, f32 alpha, f32 brightness);
void draw_ui_sprite_scaled(s32 sprite_id, const vec2f* position, const vec2f* scale,
                          f32 depth, f32 alpha);
void draw_ui_sprite_opaque(s32 sprite_id, const vec2f* position, const vec2f* scale,
                           f32 depth);
// The UI scale TObjCMMainMenu::get_scale returns.
extern f32 ui_sprite_scale;
void draw_ui_sprite(s32 sprite_id, const vec2f* position, f32 depth, f32 alpha);
// Points *table at the cell table of sprite *id; ids from 143 on index the language's own table.
void resolve_creation_sprite_table(NJS_TEXANIM** table, s32* id);
void free_creation_sprites(void);
void load_creation_sprites(void);

#include <stddef.h>
LAYOUT_ASSERT(UISpriteTintSize, sizeof(UISpriteTint) == 0x10);
LAYOUT_ASSERT(UISpriteTintAlphaOffset, offsetof(UISpriteTint, alpha) == 0);
LAYOUT_ASSERT(UISpriteScaleSize, sizeof(vec2f) == 8);
#endif
