#include "pso/ui/TAdEnterBaseGC.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"

extern const f32 lbl_804771D8[];

void TAdEnterBaseGC::fn_8032B318(Position *position) {
    u32 half_width = calc_text_width((char *)get_localized_text_entry(23, 4)) >> 1;
    f32 offset = half_width;
    f32 x = lbl_804771D8[0];
    offset = x - offset;
    position->x = offset;
    position->y = lbl_804771D8[1];
}
