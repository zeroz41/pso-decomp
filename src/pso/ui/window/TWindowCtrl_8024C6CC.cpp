#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024C6CC.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TUnk_804CF0B8.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

void TWindowCtrl__sub_8024C6CC(void* p) { *(u16*)((char*)p + 0x1c) |= 0x40; }
void TWindowCtrl__sub_8024C6DC(void* p) { *(u16*)((char*)p + 0x1c) &= 0xffffffbf; }
void TWindowCtrl__sub_8024C6EC(void* p) { *(u16*)((char*)p + 0x1c) |= 0x2; }
void TWindowCtrl__sub_8024C6FC(void* p) { *(u16*)((char*)p + 0x1c) &= 0xfffffffd; }
void TWindowCtrl__sub_8024C70C(void* p) { *(u16*)((char*)p + 0x1c) |= 0x4; }
void TWindowCtrl__sub_8024C71C(void* p) { *(u16*)((char*)p + 0x1c) &= 0xfffffffb; }
void TWindowCtrl__sub_8024C72C(void* p) { *(u16*)((char*)p + 0x1c) |= 0x8; }
void TWindowCtrl__sub_8024C73C(void* p) { *(u16*)((char*)p + 0x1c) &= 0xfffffff7; }
void TWindowCtrl__sub_8024C74C(void* p) { *(u16*)((char*)p + 0x1c) |= 0x10; }
void TWindowCtrl__sub_8024C75C(void* p) { *(u16*)((char*)p + 0x1c) &= 0xffffffef; }
void TWindowCtrl::set_radar_dirty_flag() {
    this->m_1c = (u16) (this->m_1c | 1);
    TRaderMapCore::hide_radar();
}
void TWindowCtrl::clear_flag_bit0() {
    this->m_1c = (u16) (this->m_1c & 0xFFFE);
    TRaderMapCore::show_radar();
}

bool TWindowCtrl__sub_8024C7C4(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x3C) != 0;
}

int TWindowCtrl__sub_8024C7D4(void* p) { return (*(u16*)((char*)p + 0x1c) >> 1) & 0x1; }
int TWindowCtrl__sub_8024C7E0(void* p) { return (*(u16*)((char*)p + 0x1c) >> 2) & 0x1; }
int TWindowCtrl::is_enabled() { return (this->m_1c >> 3) & 0x1; }
int TWindowCtrl__sub_8024C7F8(void* p) { return (*(u16*)((char*)p + 0x1c) >> 4) & 0x1; }
int TWindowCtrl::is_visible() { return this->m_1c & 0x1; }
s16 TUnk_804CF0B8::get_field_20() { return *(s16 *)&(this->m_20); }
s16 TWindowSimpleStatus::get_width() { return *(s16 *)&this->m_20; }
