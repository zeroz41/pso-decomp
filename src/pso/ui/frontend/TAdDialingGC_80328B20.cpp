#include "types.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
extern f32 lbl_804767B8[];
extern f32 lbl_804767C0[];
extern f32 lbl_804767A8[];
extern f32 lbl_804767B0[];

void TAdDialingGC__sub_80328B20(void) {  }

// Draws a flat dark-blue quad of `size` (w, h) at `origin` (x, y) (one 2D polygon, four points).
void TAdDialingGC__sub_80328B24(f32 *origin, f32 *size) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL poly;
    NJS_COLOR col[4];

    poly.p = pos;
    poly.tex = NULL;
    poly.col = col;
    poly.num = 4;
    poly.p[0].x = origin[0];
    poly.p[0].y = origin[1];
    poly.col[0].color = 0x8F;
    poly.p[1].x = origin[0];
    poly.p[1].y = origin[1] + size[1];
    poly.col[1].color = 0x8F;
    poly.p[2].x = origin[0] + size[0];
    poly.p[2].y = origin[1] + size[1];
    poly.col[2].color = 0x8F;
    poly.p[3].x = origin[0] + size[0];
    poly.p[3].y = origin[1];
    poly.col[3].color = 0x8F;
    ((TObjCMHairMenu *)&poly)->draw_tri_fan_2d(4, 7, -120.0f);
}
void TAdDialingGC::draw_if_flag_set() {
    TAdDialingGC *self = this;
    if (self->m_a4 & 1) {
        TAdDialingGC__sub_80328B24(lbl_804767B8, lbl_804767C0);
    }
}
void TAdDialingGC::render_if_flag_set() {
    if ((this->m_a4 & 1) && ((s32) this->m_1c == 0)) {
        TAdDialingGC__sub_80328B24(lbl_804767A8, lbl_804767B0);
    }
}

}
