#ifndef PSO_UI_FRONTEND_TADENDTEXT_H
#define PSO_UI_FRONTEND_TADENDTEXT_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"

// The ending credits: the lines of AdEnding.rel scrolled up the screen in the
// ending font, with the ADX and Sofdec logos.
class TAdEndText : public TObject {
public:
    TAdEndText(TObject *parent);
    virtual ~TAdEndText();
    virtual void render();
    virtual void run_task();
public:
    static void free_resources();
    static void load_ending_font();
public:
    static void cleanup();

    s32 pad_1C;
    u32 pad_20;
    f32 m_scroll;
    NJS_POINT2 m_line_pos[800];
    u32 m_line_count;
    TexturedQuad m_adx_logo;
    TexturedQuad m_sofdec_logo;
    f32 m_speed;
    f32 m_height;
    s32 m_size_index;
    f32 m_rate;
};

LAYOUT_ASSERT(TAdEndText_size, sizeof(TAdEndText) == 0x197C);

extern "C" {
s32 TAdEndText__sub_8001B3BC(u8 arg0);
s32 TAdEndText__sub_8001B3D4(u8 arg0);
s32 TAdEndText__sub_8001B3EC(u8 arg0);
s32 TAdEndText__sub_8001B404(u8 arg0);
s32 TAdEndText__sub_8001B41C(void);
s32 get_end_text_font_loaded_flag(void);
s32 get_ending_scene_active(void);
}

#endif
