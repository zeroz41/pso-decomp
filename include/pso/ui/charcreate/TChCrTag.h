#ifndef PSO_UI_CHARCREATE_TCHCRTAG_H
#define PSO_UI_CHARCREATE_TCHCRTAG_H
#include "pso/system/task/TObject.h"
#include "types.h"

// Base of the character-creation screen's tags: fades in on creation, fades
// its highlight while is_selected() holds and fades out once the selection
// step reaches 2.
class TChCrTag : public TObject {
public:
    TChCrTag(TObject *parent, s32 index);
    virtual ~TChCrTag();
    virtual void run_task();
    virtual void render();
    virtual s32 is_selected();

    s32 m_fade_state;
    s32 m_index;
    f32 m_fade;
    f32 m_fade_in_step;
    f32 m_fade_out_step;
    f32 m_highlight;
    f32 m_highlight_in_step;
    f32 m_highlight_out_step;
};

LAYOUT_ASSERT(TChCrTag_size, sizeof(TChCrTag) == 0x3C);

#endif
