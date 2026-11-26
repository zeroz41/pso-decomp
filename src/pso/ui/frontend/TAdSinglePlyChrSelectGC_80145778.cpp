#include "pso/system/memory.h"
#include "pso/render/GinjaTextureHeader.h"
#include "pso/render/GinjaTextureInput.h"
#pragma readonly_strings on

#include "pso/system/ResourceFile.h"
#include "pso/ui/MenuText.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_80145804.h"
#include "pso/render/GinjaTexture.h"
#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/network/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803DD5E0.h"

void draw_menu_text(f32 x, f32 y, const char *text, u32 color) {
    draw_menu_font_string(text, color, 0, x, y, 0.5f);
}


extern NJS_TEXLIST menu_font_texture_list[];
u8 *menu_font_glyph_data;
s16 *menu_font_palette;
s32 menu_font_upload_flags;
MenuFontGlyph *menu_font_glyph_table;
u8 menu_font_upload_epoch;
TObject *menu_font_object;

void draw_menu_font_string_white(const char *text, f32 x, f32 y) {
    draw_menu_font_string(text, -1, (u32)(0), x, y, 0.5f);
}
#pragma push
#pragma fp_contract on
void TAdSinglePlyChrSelectGC::free_resources() {
    delete menu_font_object;
    release_texture_list(menu_font_texture_list);
    mem_free(menu_font_glyph_table);
    mem_free(menu_font_palette);
    safe_free(menu_font_glyph_data);
}
#pragma pop



extern "C" {
__declspec(section ".data") u32 *menu_font_glyph_pixel_buffers[2];
GinjaTextureInput menu_font_render_rects[2];
NJS_TEXNAME menu_font_texnames[2];
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void clear_words_80145804(u32 *p, s32 count) {
    s32 n;
    for (n = 0; n < count; n++) {
        *p++ = 0;
    }
}
}
void load_menu_font(void) {
    u32 m;
    u32 *p;
    s16 *t;
    s32 n;
    MenuFontGlyph *g;
    void *f;
    u32 i;
    u32 j;
    u32 k;
    u32 u;
    u32 v;
    TLobby::load_font_texture();
    menu_font_glyph_data = load_disc_file("S18all04.fon");
    TLobby::release_menu_font();
    for (i = 0; i < 2; i++) {
        menu_font_render_rects[i].set_render_rect(NULL, 0x208, 0x100, 0x100);
        set_texture_name(menu_font_texnames + i, menu_font_render_rects + i, i + 0xDCF28, 0x08800000);
    }
    load_texture_list(menu_font_texture_list);
    for (m = 0; m < 2; m++) {
        *(menu_font_glyph_pixel_buffers + m) = menu_font_texture_list[0].textures[m].texture->surface->header.pixels;
        clear_words_80145804(*(menu_font_glyph_pixel_buffers + m), 0x2000);
    }
    menu_font_palette = (s16 *)mem_alloc(0x100);
    clear_words_80145804((u32 *)menu_font_palette, 0x40);
    menu_font_palette[0] = 0xFFF;
    menu_font_palette[1] = 0x3FFF;
    menu_font_palette[2] = 0x5FFF;
    menu_font_palette[3] = 0x7FFF;
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(menu_font_texture_list));
    for (i = 0; i < 2; i++) {
        set_context_texture_palette_bank(i, 0);
    }
    g = (MenuFontGlyph *)mem_alloc(0xB40);
    menu_font_glyph_table = g;
    for (i = 0; i < 2; i++) {
        v = 0;
        for (j = 0; j < 12; j++) {
            u = 0;
            for (k = 0; k < 12; k++) {
                g->code = 0x2EF;
                g->width = 9;
                g->epoch = 0xF0;
                g->page = i;
                g->x = u;
                g->y = v;
                g++;
                u += 20;
            }
            v += 20;
        }
    }
    menu_font_upload_epoch = 0;
    menu_font_upload_flags = 3;
    f = (void *)new TNECFontEORFunction();
    menu_font_object = (TObject *)f;
}
#pragma pop
