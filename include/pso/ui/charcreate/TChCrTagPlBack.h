#ifndef PSO_UI_CHARCREATE_TCHCRTAGPLBACK_H
#define PSO_UI_CHARCREATE_TCHCRTAGPLBACK_H
#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagPlBack : public TChCrTag {
public:
    TChCrTagPlBack(TObject *parent, s32 index);
    virtual ~TChCrTagPlBack();
    virtual void render();
    virtual s32 is_selected();
    void draw_frame();
public:
    static TChCrTagPlBack *create(s32 index);
    static TChCrTagPlBack *create_default();
};

extern const char *TChCrTagPlBack__name;

#endif
