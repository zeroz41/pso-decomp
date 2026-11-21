#ifndef PSO_UI_FRONTEND_TADDIALINGGC_80328B20_H
#define PSO_UI_FRONTEND_TADDIALINGGC_80328B20_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

struct TAdDialingGC;

extern "C" {
void TAdDialingGC__sub_80328B20(TAdDialingGC *screen);
void draw_dialing_rectangle(const NJS_POINT2 *origin, const NJS_POINT2 *size);
}

#endif
