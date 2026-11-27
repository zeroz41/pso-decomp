#ifndef PSO_UI_FONT_TNECFONTEORFUNCTION_H
#define PSO_UI_FONT_TNECFONTEORFUNCTION_H

#include "pso/system/task/TObject.h"
#include "types.h"

#include "pso/system/NinjaTypes.h"

struct TexturedQuad;

// One cached glyph of the menu font: where it sits on the two glyph texture pages.
struct MenuGlyphEntry {
    u16 code;
    u8 width;
    u8 epoch; // stamped with menu_font_upload_epoch when the glyph is drawn
    u8 page;
    u8 x;
    u8 y;
    u8 pad_7[3];
};
LAYOUT_ASSERT(MenuGlyphEntry_size, sizeof(MenuGlyphEntry) == 0xA);

extern NJS_TEXLIST menu_font_texture_list[1];
extern u32 *menu_font_glyph_pixel_buffers[2];
extern u8 *menu_font_glyph_data;
extern MenuGlyphEntry *menu_font_glyph_table;
extern s32 menu_font_upload_flags;
extern u8 menu_font_upload_epoch;
extern TObject *menu_font_object;

void load_menu_font();
void free_menu_font();

extern s16 *menu_font_palette;
const char *parse_text_control_codes(const char *p, s32 *shift_jis, s32 *color);
extern "C" {
void set_glyph_quad_extents(u8 advance, TexturedQuad *quad);
}

class TNECFontEORFunction : public TObject {
public:
    TNECFontEORFunction();
    virtual ~TNECFontEORFunction();
    virtual void run_task();
public:
};

#endif
