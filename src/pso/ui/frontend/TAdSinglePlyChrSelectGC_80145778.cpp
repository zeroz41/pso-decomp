#include "pso/ui/MenuText.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

void draw_menu_text(f32 x, f32 y, const char *text, u32 color) {
    draw_menu_font_string(text, color, 0, x, y, 0.5f);
}

struct Base_801457A4 { char pad[0x18]; };

struct VObj_801457A4 : Base_801457A4 {
    virtual void m0(int);
};

extern "C" {
s32 release_texture_list(s32 *);
void mem_free(void *p);
extern s32 menu_font_texture_list[];
extern s32 menu_font_glyph_data;
extern s32 lbl_805D56B4;
extern s32 menu_font_glyph_table;
extern struct VObj_801457A4 *menu_font_object;
void draw_menu_font_string(const char *s, s32 arg1, u32 flags, f32 x, f32 y, f32 scale);

void TAdSinglePlyChrSelectGC::render_status_disp(f32 arg1, f32 arg2) {
    draw_menu_font_string((const char *)this, -1, (u32)(0), (f32)arg1, (f32)arg2, (f32)0.5f);
}
#pragma push
#pragma fp_contract on
void TAdSinglePlyChrSelectGC::free_resources() {
    if (menu_font_object != NULL) {
        menu_font_object->m0(1);
    }
    release_texture_list(menu_font_texture_list);
    mem_free((void *)menu_font_glyph_table);
    mem_free((void *)lbl_805D56B4);
    TAdSinglePlyChrSelectGC::safe_free(menu_font_glyph_data);
}
#pragma pop

}
