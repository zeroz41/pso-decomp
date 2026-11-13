#ifndef PSO_UI_CHARCREATE_TCHCREFFTAG_H
#define PSO_UI_CHARCREATE_TCHCREFFTAG_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrEffTagStr;

class TChCrEffTag : public TObject {
public:
    TChCrEffTag(TObject *parent);
    virtual void run_task();
    s32 heading;
    f32 width,targetWidth;
    TChCrEffTagStr *label;
    virtual ~TChCrEffTag();
    void draw_chcr_tag_frame();
    virtual void render();
public:
    void refresh_label();
    static void set_eff_tag(int a0);
    static void *create_str(void *arg0, void *arg1, void *arg2);
};

typedef char TChCrEffTag_size[sizeof(TChCrEffTag) == 0x2C ? 1 : -1];

void *create_TChCrEffTag(void *arg0);

#endif
