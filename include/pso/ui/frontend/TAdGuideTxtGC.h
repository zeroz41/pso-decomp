#ifndef PSO_UI_FRONTEND_TADGUIDETXTGC_H
#define PSO_UI_FRONTEND_TADGUIDETXTGC_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/math/TMath.h"

class TAdGuideTxtGC : public TObject {
public:
    static const char *class_name;
    TAdGuideTxtGC(TObject *parent);
    void set_line(s32 index, const char *line);
    const char *text[2];
    const char *previous_text[2];
    vec2f position[2];
    u32 alpha[2];
    virtual ~TAdGuideTxtGC();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdGuideTxtGCSize, sizeof(TAdGuideTxtGC) == 0x44);

#endif
