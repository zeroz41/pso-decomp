#ifndef PSO_UI_FRONTEND_TADBACKTXTGC_H
#define PSO_UI_FRONTEND_TADBACKTXTGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdBackTxtGC : public TObject {
public:
    TAdBackTxtGC(TObject *parent);
    virtual ~TAdBackTxtGC();
    void draw_character_background_frame(s32, s32);
    virtual void render();
    virtual void run_task();
    void set_field_24(s32 v);
    void set_depth(f32 v);

    s32 frame;
    f32 m_depth;
    s32 m_24;
};

LAYOUT_ASSERT(TAdBackTxtGC_size, sizeof(TAdBackTxtGC) == 0x28);

extern "C" {
void register_texture_f256_backtext(void);
}

#endif
