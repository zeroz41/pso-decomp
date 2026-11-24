#ifndef PSO_UI_FONT_TNECFONTEORFUNCTION_H
#define PSO_UI_FONT_TNECFONTEORFUNCTION_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TexturedQuad;

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
