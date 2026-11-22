#include "pso/item/TItemTexLoad.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
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

void TWindowLoadItemTexture::set_mag_slot_state(TItemData *item) {
    *(u16 *)get_array_entry(0) |= 2;
    if (m_6c->load_item_icon(item) != 0) {
        m_60 = 1;
        return;
    }
    m_60 = 2;
}

void fn_8026287C(TWindowLoadItemTexture *window) {
    u8 *sprite = (u8 *)window->get_array_entry(0);
    *(GinjaTextureList ***)(sprite + 0x30) = &window->m_70;
    *(u16 *)sprite = (u16)(*(u16 *)sprite & 0xFFFFFFFD);
}

}
