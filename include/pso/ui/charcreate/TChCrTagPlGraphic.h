#ifndef PSO_UI_CHARCREATE_TCHCRTAGPLGRAPHIC_H
#define PSO_UI_CHARCREATE_TCHCRTAGPLGRAPHIC_H
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/math/TMath.h"
#include "types.h"

class TChCrTagPlGraphic : public TChCrTag {
public:
    TChCrTagPlGraphic(TObject *parent, s32 index);
    virtual ~TChCrTagPlGraphic();
    void update_layout();
    virtual void render();
    virtual void run_task();
    virtual s32 is_selected();
public:
    static TChCrTagPlGraphic *create(s32 index);
    static void create_matching_tags();
    void draw_class_illustration();

    f32 alpha;
    f32 depth;
    f32 scale;
    vec2f pos;
};

LAYOUT_ASSERT(TChCrTagPlGraphic_size, sizeof(TChCrTagPlGraphic) == 0x50);

#endif
