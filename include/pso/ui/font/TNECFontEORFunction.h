#ifndef PSO_UI_FONT_TNECFONTEORFUNCTION_H
#define PSO_UI_FONT_TNECFONTEORFUNCTION_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TexturedQuad;

// One cached glyph of the menu font texture: which character it holds and where it sits in the texture pages.
struct MenuFontGlyph {
    u16 code;
    u8 width;
    u8 epoch;   // stamped with menu_font_upload_epoch when the glyph was used
    u8 page;
    u8 x;
    u8 y;
    u8 pad_07[3];
};
LAYOUT_ASSERT(MenuFontGlyph_size, sizeof(MenuFontGlyph) == 10);

extern MenuFontGlyph *menu_font_glyph_table;
extern s32 menu_font_upload_flags;
extern u8 menu_font_upload_epoch;

extern "C" {
extern s16 *menu_font_palette;
const char *parse_text_control_codes(const char *p, s32 *shift_jis, s32 *color);
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
