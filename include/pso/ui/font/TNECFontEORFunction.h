#ifndef PSO_UI_FONT_TNECFONTEORFUNCTION_H
#define PSO_UI_FONT_TNECFONTEORFUNCTION_H

#include "pso/system/task/TObject.h"
#include "types.h"

extern "C" s16 *menu_font_palette;

class TNECFontEORFunction : public TObject {
public:
    TNECFontEORFunction();
    virtual ~TNECFontEORFunction();
    virtual void run_task();
public:
    static void run_task();
};

#endif
