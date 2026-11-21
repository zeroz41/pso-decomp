#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccHeader : public TChCrTag {
public:
    TChCrTagOccHeader(TObject *parent, void *arg);
    virtual ~TChCrTagOccHeader();
    virtual s32 vt4();
    virtual void run_task();
    virtual void render();

    s32 m_3c;
};

LAYOUT_ASSERT(TChCrTagOccHeader_size, sizeof(TChCrTagOccHeader) == 0x40);

// --- C functions defined in TChCrTagOccHeader.cpp ---
extern "C" {
TChCrTagOccHeader *__dt__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag, s16 free);
void fn_802A2A00(TChCrTag *tag);
}
// --- end of C functions

#endif
