#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H

#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccupation : public TChCrTag {
public:
    TChCrTagOccupation(TObject *parent, s32 index);
    virtual ~TChCrTagOccupation();
    virtual void render();
    void sub_802A2DF4();
public:
    static TChCrTagOccupation *create(s32 index);
    static void create_all();

    f32 m_3c;
    f32 m_40;
};

typedef char TChCrTagOccupation_size[sizeof(TChCrTagOccupation) == 0x44 ? 1 : -1];

// --- C functions defined in TChCrTagOccupation.cpp ---
extern "C" {
int TChCrTagOccupation__vt4(TChCrTagOccupation *tag);
TChCrTagOccupation *__dt__18TChCrTagOccupationFv(TChCrTagOccupation *tag, s16 free);
}
// --- end of C functions

#endif
