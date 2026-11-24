#include "pso/item/TItemTexLoad.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

#include "types.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowSpritePart.h"

extern "C" {


int TWindowKeyBoardSoft::get_flag_bit0() { return this->m_60 & 0x1; }
int TWindowKeyBoardSoft::is_cursor_locked() { return (this->m_60 >> 7) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit6() { return (this->m_60 >> 6) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit5() { return (this->m_60 >> 5) & 0x1; }
int TWindowKeyBoardBase::get_flag62_bit8() { return this->m_62 & 0x8; }

void TWindowLoadItemTexture::set_mag_slot_state(TItemData *item) {
    static_cast<WindowSpritePart *>(get_array_entry(0))->flags |= 2;
    if (texture_loader->load_item_icon(item) != 0) {
        m_60 = 1;
        return;
    }
    m_60 = 2;
}

void fn_8026287C(TWindowLoadItemTexture *window) {
    WindowSpritePart *sprite = static_cast<WindowSpritePart *>(window->get_array_entry(0));
    sprite->texture_list_slot = &window->texture_list;
    sprite->flags &= ~2;
}

}
