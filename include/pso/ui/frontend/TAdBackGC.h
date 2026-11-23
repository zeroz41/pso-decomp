#ifndef PSO_UI_FRONTEND_TADBACKGC_H
#define PSO_UI_FRONTEND_TADBACKGC_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/ui/frontend/TitleBackground.h"

class TAdBackGC : public TObject {
public:
    TAdBackGC(TObject *parent);
    virtual ~TAdBackGC();
    void sub_8029A6EC();
    virtual void run_task();
    virtual void render();
public:
    void set_field_20(s32 v);
    void set_depth(f32 v);

    f32 m_depth;
    s32 m_20;
};

LAYOUT_ASSERT(TAdBackGC_size, sizeof(TAdBackGC) == 0x24);

extern "C" {
void register_texture_f256_ad_pic_2(void);
}

#endif
