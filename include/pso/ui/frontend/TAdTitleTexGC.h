#ifndef PSO_UI_FRONTEND_TADTITLETEXGC_H
#define PSO_UI_FRONTEND_TADTITLETEXGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdTitleTexGC : public TObject {
public:
    virtual ~TAdTitleTexGC();
    void sub_802A4D74(s32, u8 *, u8 *);
    void render_status_pair(s32 color);
    virtual void run_task();
    virtual void render();
};

extern "C" {
void *__ct__13TAdTitleTexGCFv(void *ad_title_tex_gc);
}

#endif
