#ifndef PSO_UI_FONT_TUNK_8049CA54_H
#define PSO_UI_FONT_TUNK_8049CA54_H
#include "types.h"
#include "pso/ui/font/TFontSmallHelp.h"

class TUnk_8049CA54 : public TFontSmallHelp {
public:
    virtual ~TUnk_8049CA54();
    virtual void run_task();
    u8 unk_60[0x4];
};
typedef char TUnk_8049CA54_size[sizeof(TUnk_8049CA54) == 0x64 ? 1 : -1];

#endif
