#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccHeader : public TChCrTag {
public:
    TChCrTagOccHeader(TObject *parent, void *arg);
    virtual ~TChCrTagOccHeader();
    virtual void run_task();
    virtual void render();

    s32 m_3c;
};

typedef char TChCrTagOccHeader_size[sizeof(TChCrTagOccHeader) == 0x40 ? 1 : -1];

#endif
