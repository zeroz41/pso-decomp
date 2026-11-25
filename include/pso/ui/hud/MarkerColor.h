#ifndef PSO_UI_HUD_MARKERCOLOR_H
#define PSO_UI_HUD_MARKERCOLOR_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// A colour (ahead of the vptr): TMainCursor sets it from its colour table and fades its alpha out.
// Members of TMainCursor (+0x4C), TLockOnCursor (+0x48) and TPlyPhotonChair (+0xD0).
class MarkerColor {
public:
    NJS_ARGB color;

    MarkerColor();
    virtual ~MarkerColor();
    void get_color(NJS_ARGB *out);
    void set_color(NJS_ARGB *src);
    f32 get_alpha();
    void set_alpha(f32 alpha);
};


LAYOUT_ASSERT(MarkerColor_size, sizeof(MarkerColor) == 0x14);

#endif
