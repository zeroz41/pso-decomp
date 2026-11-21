#ifndef PSO_UI_CHARCREATE_TCHCRTAGPLGRAPHIC_H
#define PSO_UI_CHARCREATE_TCHCRTAGPLGRAPHIC_H
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/math/TMath.h"
#include "types.h"

class TChCrTagPlGraphic : public TChCrTag {
public:
    TChCrTagPlGraphic(TObject *parent, void *arg);
    virtual ~TChCrTagPlGraphic();
    void sub_802A3230();
    virtual void render();
    virtual void run_task();
    virtual s32 vt4();
public:
    static void *create(void *arg0);
    static void create_matching_tags();
    void draw_class_illustration();

    f32 m_3c;
    f32 m_40;
    f32 m_44;
    vec2f pos;
};

LAYOUT_ASSERT(TChCrTagPlGraphic_size, sizeof(TChCrTagPlGraphic) == 0x50);

#endif
