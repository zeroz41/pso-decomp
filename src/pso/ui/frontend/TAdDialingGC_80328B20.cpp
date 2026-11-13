#include "types.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/system/NinjaTypes.h"

struct VtxList_80077BC0 {
    f32 *volatile pos;
    u32 *volatile col;
    s32 n;
    s32 cap;
};

extern "C" {
extern f32 lbl_804767B8[];
extern f32 lbl_804767C0[];
extern f32 lbl_804767A8[];
extern f32 lbl_804767B0[];
extern const f32 lbl_805DF6F8;

void TAdDialingGC__sub_80328B20(void) {  }

// Draws a flat dark-blue quad of `size` (w, h) at `origin` (x, y) (one 2D polygon, four points).
void TAdDialingGC__sub_80328B24(f32 *origin, f32 *size) {
    VtxList_80077BC0 vl;
    u32 col[4];
    f32 pos[8];

    f32 x = origin[0];
    f32 y = origin[1];
    vl.n = 0;
    vl.cap = 4;
    vl.col = col;
    vl.pos = pos;
    pos[0] = x;
    pos[1] = y;
    vl.col[0] = 0x8F;
    vl.pos[2] = origin[0];
    vl.pos[3] = origin[1] + size[1];
    vl.col[1] = 0x8F;
    vl.pos[4] = origin[0] + size[0];
    vl.pos[5] = origin[1] + size[1];
    vl.col[2] = 0x8F;
    vl.pos[6] = origin[0] + size[0];
    vl.pos[7] = origin[1];
    vl.col[3] = 0x8F;
    ((TObjCMHairMenu *)&vl)->draw_tri_fan_2d(4, 7, lbl_805DF6F8);
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
