#include "types.h"
#include "pso/ui/hud/TMainCursor_8013DEF8.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/player/TForceOperate.h"
#include "pso/ui/window/TWindowActionPalette.h"

extern "C" {
int find_action_slot_for_target__11TMainCursorFllll(void*);

void TObjPlayer__sub_8013DEF8(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) | 1);
}

u8 TMainCursor::is_channel_active() {
    u8 *arg0 = (u8 *)this;
    return (u8) ((*(s16 *)((s8 *)arg0 + 2) & 1) ^ 1);
}

int TMainCursor::check_visible() { return find_action_slot_for_target__11TMainCursorFllll(this); }
u8 TMainCursor::get_enabled() { return *(u8*)((char*)this + 0x1); }
u8 TMainCursor::get_type() { return *(u8 *)&this->m_name; }

}
