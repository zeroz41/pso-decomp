#ifndef PSO_UI_FRONTEND_TADBACKGC_H
#define PSO_UI_FRONTEND_TADBACKGC_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/ui/frontend/TitleBackground.h"

class TAdBackGC : public TObject {
public:
    static const char *class_name;
    TAdBackGC(TObject *parent);
    virtual ~TAdBackGC();
    void draw_backdrop();
    virtual void run_task();
    virtual void render();
public:
    void set_render_direct(s32 v);
    void set_depth(f32 v);

    f32 m_depth;
    s32 render_direct;
};

LAYOUT_ASSERT(TAdBackGC_size, sizeof(TAdBackGC) == 0x24);

void register_texture_f256_ad_pic_2(void);

#endif
