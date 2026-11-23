#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccHeader : public TChCrTag {
public:
    TChCrTagOccHeader(TObject *parent, s32 index);
    virtual ~TChCrTagOccHeader();
    virtual void run_task();
    virtual void render();
    virtual s32 is_selected();
    void draw_header();

    s32 m_frame;
};

LAYOUT_ASSERT(TChCrTagOccHeader_size, sizeof(TChCrTagOccHeader) == 0x40);

void create_all_ch_cr_tag_headers();
TChCrTagOccHeader *create_ch_cr_tag_occ_header(s32 index);

#endif
