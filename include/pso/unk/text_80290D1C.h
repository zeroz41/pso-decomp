#ifndef PSO_UNK_TEXT_80290D1C_H
#define PSO_UNK_TEXT_80290D1C_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// Character-creation screen textures and sprite cells.
extern NJS_TEXNAME creation_chara_sprite_entries[20];
__declspec(section ".data") extern NJS_TEXLIST creation_sprite_table;
extern NJS_TEXANIM lbl_804D9670[143];
extern NJS_TEXANIM lbl_804DA19C[49];  // Japanese cells (creation_sprite_table_index 0)
extern NJS_TEXANIM lbl_804DA570[49];  // other-language cells
__declspec(section ".data") extern const char *ccconsole_pvm_file_name_table[2];

// The ruler quad drawn by draw_creation_ruler_lines.
extern NJS_POINT3 lbl_804DA94C[4];
extern u32 creation_ruler_line_colors[4];
extern NJS_POINT3COL lbl_804DA98C;

void draw_creation_ruler_lines(f32 farg0);

#endif
