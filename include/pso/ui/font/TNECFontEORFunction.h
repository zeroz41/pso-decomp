#ifndef PSO_UI_FONT_TNECFONTEORFUNCTION_H
#define PSO_UI_FONT_TNECFONTEORFUNCTION_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TNECFontEORFunction : public TObject {
public:
    virtual ~TNECFontEORFunction();
    virtual void run_task();
public:
    static void run_task();
};

#endif
