#include "types.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"
#include "pso/ui/frontend/TAdDialingGC.h"

extern "C" {
void TAdDialingGC__sub_80328B24(void *, void *);
extern char lbl_804767B8[];
extern char lbl_804767C0[];
extern s32 lbl_804767A8[];
extern s32 lbl_804767B0[];

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

}
