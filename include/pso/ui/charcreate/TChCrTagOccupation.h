#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H

#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccupation : public TChCrTag {
public:
    TChCrTagOccupation(TObject *parent, void *arg);
    virtual ~TChCrTagOccupation();
    virtual void render();
    void sub_802A2DF4();
public:
    static void *create(void *arg0);
    static void create_all();

    f32 m_3c;
    f32 m_40;
};

typedef char TChCrTagOccupation_size[sizeof(TChCrTagOccupation) == 0x44 ? 1 : -1];

class TChCrTagOccHeader;

extern "C" {
TChCrTagOccHeader *__dt__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag, s16 free);
TChCrTagOccupation *__dt__18TChCrTagOccupationFv(TChCrTagOccupation *tag, s16 free);
}
void create_all_ch_cr_tag_headers(void);
void *create_ch_cr_tag_occ_header(void *arg0);

#endif
