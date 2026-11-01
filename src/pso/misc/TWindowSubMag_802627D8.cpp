#include "pso/item/TItemTexLoad.h"
#include "pso/misc/TWindowSubMag_802627D8.h"
#include "pso/misc/TWindowKeyBoardSoft.h"

#include "types.h"
#include "pso/misc/TWindowSubMag.h"

extern "C" {
u16 * get_array_entry__11TWindowBaseFi(void * a0, s32 a1);

u16 * get_array_entry__11TWindowBaseFi(void * a0 = 0, s32 a1 = 0);

int TWindowSubMag__sub_802627D8(void* p) { return *(u32*)((char*)p + 0x60) & 0x1; }
int TWindowKeyBoardSoft::is_cursor_locked() { return (this->m_7c >> 7) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit6() { return (this->m_7c >> 6) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit5() { return (this->m_7c >> 5) & 0x1; }
int TWindowSubMag__sub_80262808(void* p) { return *(u16*)((char*)p + 0x62) & 0x8; }

void TWindowSubMag::set_mag_slot_state(s32 item) {

    *get_array_entry__11TWindowBaseFi(this, 0) |= 2;
    if ((*(TItemTexLoad**)((s8 *)this + 0x6C))->load_item_icon((TItemData*)item) != 0) {
        *(s8 *)((s8 *)this + 0x60) = 1;
        return;
    }
    *(s8 *)((s8 *)this + 0x60) = 2;
}
void fn_8026287C(u8 *arg0) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(((s32)get_array_entry__11TWindowBaseFi(arg0, 0)));
    *(u8 **)((s8 *)temp_r3 + 0x30) = (unsigned char *) (arg0 + 0x70);
    *(u16 *)((s8 *)temp_r3 + 0) = (u16) (*(u16 *)((s8 *)temp_r3 + 0) & 0xFFFFFFFD);
}

}
