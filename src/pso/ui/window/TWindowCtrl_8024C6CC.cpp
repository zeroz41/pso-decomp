#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowCtrl_8024C6CC.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

LAYOUT_ASSERT(WindowCtrlFlagsOffset, offsetof(TWindowCtrl, flags) == 0x1C);
LAYOUT_ASSERT(WindowCtrlChildOffset, offsetof(TWindowCtrl, m_3c) == 0x3C);

void TWindowCtrl__sub_8024C6CC(TWindowCtrl *window) {
    window->flags |= 0x40;
}
void TWindowCtrl__sub_8024C6DC(TWindowCtrl *window) {
    window->flags &= ~0x40;
}
void TWindowCtrl__sub_8024C6EC(TWindowCtrl *window) {
    window->flags |= 0x2;
}
void TWindowCtrl__sub_8024C6FC(TWindowCtrl *window) {
    window->flags &= ~0x2;
}
void TWindowCtrl__sub_8024C70C(TWindowCtrl *window) {
    window->flags |= 0x4;
}
void TWindowCtrl__sub_8024C71C(TWindowCtrl *window) {
    window->flags &= ~0x4;
}
void TWindowCtrl__sub_8024C72C(TWindowCtrl *window) {
    window->flags |= 0x8;
}
void TWindowCtrl__sub_8024C73C(TWindowCtrl *window) {
    window->flags &= ~0x8;
}
void TWindowCtrl__sub_8024C74C(TWindowCtrl *window) {
    window->flags |= 0x10;
}
void TWindowCtrl__sub_8024C75C(TWindowCtrl *window) {
    window->flags &= ~0x10;
}
void TWindowCtrl::set_radar_dirty_flag() {
    this->flags |= 1;
    TRaderMapCore::hide_radar();
}
void TWindowCtrl::clear_flag_bit0() {
    this->flags &= ~1;
    TRaderMapCore::show_radar();
}

s32 TWindowCtrl__sub_8024C7C4(const TWindowCtrl *window) {
    return window->m_3c != 0 ? 1 : 0;
}

s32 TWindowCtrl__sub_8024C7D4(const TWindowCtrl *window) {
    return (window->flags >> 1) & 1;
}
s32 TWindowCtrl__sub_8024C7E0(const TWindowCtrl *window) {
    return (window->flags >> 2) & 1;
}
int TWindowCtrl::is_enabled() { return (this->flags >> 3) & 0x1; }
s32 TWindowCtrl__sub_8024C7F8(const TWindowCtrl *window) {
    return (window->flags >> 4) & 1;
}
int TWindowCtrl::is_visible() { return this->flags & 0x1; }
s16 TWindowFukidasi::get_field_20() { return *(s16 *)&(this->client_index); }
s32 TWindowSimpleStatus::get_width() { return (s16)(*(s16 *)&this->client_index); }
