#ifndef PSO_UI_FRONTEND_TADTITLEGC_H
#define PSO_UI_FRONTEND_TADTITLEGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdTitleGC : public TObject {
public:
    TAdTitleGC(TObject *parent, s32 idx);
    virtual ~TAdTitleGC();
    virtual void run_task();
    virtual void render();
public:
    s32 draw_title_layer(s32 arg1, s32 arg2);
    static void calc_text_pos(s32 arg0, u8 *arg1, s32 arg2);
    s32 update_title_rects();
};

extern "C" {
void run_task__10TAdTitleGCFv(u8 *arg0);
}

#endif
