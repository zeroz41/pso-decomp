#ifndef PSO_UI_TCHCREFFTAG_H
#define PSO_UI_TCHCREFFTAG_H

#include "pso/TObject.h"
#include "types.h"

class TChCrEffTag : public TObject {
public:
    virtual void run_task();
    s32 heading;
    f32 width,targetWidth;
    TObject* label;
    virtual ~TChCrEffTag();
    void draw_chcr_tag_frame();
    virtual void render();
public:
    void refresh_label();
    static void set_eff_tag(int a0);
    static void *create_str(void *arg0, void *arg1, void *arg2);
};

void *create_TChCrEffTag(void *arg0);

#endif
