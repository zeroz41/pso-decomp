#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H

#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccupation : public TChCrTag {
public:
    TChCrTagOccupation(TObject *parent, s32 index);
    virtual ~TChCrTagOccupation();
    virtual void render();
    virtual s32 is_selected();
    void draw_occupation();
public:
    static TChCrTagOccupation *create(s32 index);
    static void create_all();

    f32 m_slide_start;
    f32 m_slide_end;
};

LAYOUT_ASSERT(TChCrTagOccupation_size, sizeof(TChCrTagOccupation) == 0x44);

#endif
