#include "types.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"

struct VtxList_80077BC0 {
    f32 *volatile pos;
    u32 *volatile col;
    s32 n;
    s32 cap;
};

extern "C" {
void TAdDialingGC__sub_80328B24(void *, void *);
extern char lbl_804767B8[];
extern char lbl_804767C0[];
extern s32 lbl_804767A8[];
extern s32 lbl_804767B0[];
extern const f32 lbl_805DF6F8;

void TAdDialingGC__sub_80328B20(void) {  }
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

void TAdDialingGC__sub_80328B24(void *arg0, void *arg1) {
    const f32 *start = (const f32 *)arg0;
    const f32 *delta = (const f32 *)arg1;
    VtxList_80077BC0 vl;
    u32 col[4];
    f32 pos[8];
    vl.n = 0;
    vl.cap = 4;
    vl.col = col;
    vl.pos = pos;
    pos[0] = start[0];
    pos[1] = start[1];
    vl.col[0] = 0x8f;
    vl.pos[2] = start[0];
    vl.pos[3] = start[1] + delta[1];
    vl.col[1] = 0x8f;
    vl.pos[4] = start[0] + delta[0];
    vl.pos[5] = start[1] + delta[1];
    vl.col[2] = 0x8f;
    vl.pos[6] = start[0] + delta[0];
    vl.pos[7] = start[1];
    vl.col[3] = 0x8f;
    ((TObjCMHairMenu *)(&vl))->draw_tri_fan_2d(4, 7, lbl_805DF6F8);
}

}
