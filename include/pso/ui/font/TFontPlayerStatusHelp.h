#ifndef PSO_UI_FONT_TFONTPLAYERSTATUSHELP_H
#define PSO_UI_FONT_TFONTPLAYERSTATUSHELP_H
#include "types.h"
#include "pso/ui/font/TFontSmallHelp.h"

class TFontPlayerStatusHelp : public TFontSmallHelp {
public:
    virtual ~TFontPlayerStatusHelp();
    virtual void run_task();
    s32 card_status_bits;
};
LAYOUT_ASSERT(TFontPlayerStatusHelp_size, sizeof(TFontPlayerStatusHelp) == 0x64);

#endif
