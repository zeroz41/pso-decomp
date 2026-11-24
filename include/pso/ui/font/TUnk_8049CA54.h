#ifndef PSO_UI_FONT_TUNK_8049CA54_H
#define PSO_UI_FONT_TUNK_8049CA54_H
#include "types.h"
#include "pso/ui/font/TFontSmallHelp.h"

class TUnk_8049CA54 : public TFontSmallHelp {
public:
    virtual ~TUnk_8049CA54();
    virtual void run_task();
    s32 card_status_bits;
};
LAYOUT_ASSERT(TUnk_8049CA54_size, sizeof(TUnk_8049CA54) == 0x64);

#endif
