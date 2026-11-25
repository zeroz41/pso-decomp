#ifndef PSO_UI_FRONTEND_TADBACKTXTGC_H
#define PSO_UI_FRONTEND_TADBACKTXTGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct NJS_TEXLIST;

class TAdBackTxtGC : public TObject {
public:
    static NJS_TEXLIST *backtext_texture_list;
    TAdBackTxtGC(TObject *parent);
    virtual ~TAdBackTxtGC();
    void draw_character_background_frame(s32, s32);
    virtual void render();
    virtual void run_task();
    void set_render_direct(s32 v);
    void set_depth(f32 v);

    s32 frame;
    f32 m_depth;
    s32 render_direct;
};

LAYOUT_ASSERT(TAdBackTxtGC_size, sizeof(TAdBackTxtGC) == 0x28);

void register_texture_f256_backtext(void);

#endif
