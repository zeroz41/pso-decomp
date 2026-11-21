#include "pso/item/TItemTexLoad.h"
#include "pso/ui/window/TWindowSubMag_802627D8.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

#include "types.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowBase.h"

extern "C" {


int TWindowKeyBoardSoft::get_flag_bit0() { return this->m_60 & 0x1; }
int TWindowKeyBoardSoft::is_cursor_locked() { return (this->m_60 >> 7) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit6() { return (this->m_60 >> 6) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit5() { return (this->m_60 >> 5) & 0x1; }
int TWindowKeyBoardBase::get_flag62_bit8() { return this->m_62 & 0x8; }

void TWindowSubMag::set_mag_slot_state(saddr item) {

    *(u16 *)((TWindowBase *)this)->get_array_entry(0) |= 2;
    if ((*(TItemTexLoad**)((s8 *)this + 0x6C))->load_item_icon((TItemData*)item) != 0) {
        *(s8 *)((s8 *)this + 0x60) = 1;
        return;
    }
    *(s8 *)((s8 *)this + 0x60) = 2;
}
void fn_8026287C(u8 *window_base) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(((saddr)((TWindowBase *)window_base)->get_array_entry(0)));
    *(u8 **)((s8 *)temp_r3 + 0x30) = (unsigned char *) (window_base + 0x70);
    *(u16 *)((s8 *)temp_r3 + 0) = (u16) (*(u16 *)((s8 *)temp_r3 + 0) & 0xFFFFFFFD);
}

}
