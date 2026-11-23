#ifndef PSO_UI_CHARCREATE_TCHCRTAGINFORMATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGINFORMATION_H

#include "types.h"
#include "pso/ui/charcreate/TChCrTag.h"

struct TChCrTagInformation : public TChCrTag {
    TChCrTagInformation(TObject *parent, s32 index);
    virtual ~TChCrTagInformation();
    void draw_char_info_sprites();
    void render();
    void update_selected_char();
    void run_task();
    virtual s32 is_selected();
    static TChCrTagInformation *create(s32 index);
    static TChCrTagInformation *create_default();
};

LAYOUT_ASSERT(TChCrTagInformation_size, sizeof(TChCrTagInformation) == 0x3C);

#endif
