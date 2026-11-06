#include "types.h"
#include "pso/unk/TUnk_8048E1A4.h"

extern const f32 lbl_805D937C;
extern const f32 lbl_805D9380;

void TUnk_8048E1A4::update_freeze_shell_timer() {
    u8 *arg0 = (u8 *)this;
    this->m_340 = (f32) (this->m_340 - lbl_805D937C);
    if (this->m_340 <= lbl_805D9380) {
        *(s32 *)((s8 *)arg0 + 0x334) = 3;
        this->m_340 = (f32) lbl_805D9380;
    }
}
