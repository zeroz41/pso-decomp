#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCHEADER_H
#include "pso/TChCrTag.h"
#include "types.h"

class TChCrTagOccHeader : public TChCrTag {
public:
    virtual ~TChCrTagOccHeader();
    virtual void run_task();
    virtual void render();
};

#endif
