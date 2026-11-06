#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TUnk_804CF0B8.h"

int TWindowCtrl::is_flag_2_set() { return this->m_flags & 0x4; }
void TWindowCtrl::set_flag1e_bit8() { this->m_1e |= 0x8; }
void TWindowCtrl::clear_flag1e_bit8() { this->m_1e &= 0xfffffff7; }

struct Obj_8024C5C4 { u8 pad[0x1e]; u16 f1e; };

extern "C" {
s32 TWindowCtrl__sub_8024C5C4(Obj_8024C5C4 *self);

s32 TWindowCtrl__sub_8024C5C4(Obj_8024C5C4 *self) {
    if (self->f1e & 2) return 0;
    return 1;
}

void TWindowCtrl::set_flag1e_bit40() { this->m_1e |= 0x40; }
u16 TWindowCtrl::get_flags() { return this->m_76; }
int TUnk_804CF0B8::get_flag_bit1() { return ((this->m_71) >> 1) & 0x1; }

}
