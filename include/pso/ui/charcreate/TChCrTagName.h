#ifndef PSO_UI_CHARCREATE_TCHCRTAGNAME_H
#define PSO_UI_CHARCREATE_TCHCRTAGNAME_H

#include "types.h"
#include "pso/math/TMath.h"
#include "pso/ui/charcreate/TChCrTag.h"

class TChCrTagName : public TChCrTag {
public:
    TChCrTagName(TObject *parent, s32 index);
    virtual ~TChCrTagName();
    virtual void run_task();
    virtual void render();
    virtual s32 is_selected();
    void update_slide_in();
    f32 calc_highlight_scale();
    void draw_tag_sprite();
    void draw_tag_frame();
    void draw_tag_sprites();

    f32 m_slide_start;
    f32 m_slide_end;
    s32 m_frame;
    vec2f pos;
public:
    static TChCrTagName *create(s32 index);
    static void create_all();
};

LAYOUT_ASSERT(TChCrTagName_size, sizeof(TChCrTagName) == 0x50);

#endif
