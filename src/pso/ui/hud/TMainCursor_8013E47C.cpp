#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/hud/TMainCursor_8013E2E4.h"
#include "pso/ui/hud/TMainCursor_8013E47C.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/TWindowActionPalette.h"

extern "C" {

int set__8FlagWordFUl(void*, int);
int test_flags_any(void*, int);

u16 TMainCursor::get_render_flag() { return TMainCursor__sub_8013E4A0((char*)this + 0x24); }
u16 TMainCursor__sub_8013E4A0(void* p) { return *(u16*)((char*)p + 0x0); }
int TMainCursor::test_flag_2_at_20() { return test_flags_any((char*)this + 0x20, 2); }
int TMainCursor::init_render_flags() { return test_flags_any((char*)this + 0x20, 8); }
int TMainCursor::update() { return test_flags_any((char*)this + 0x20, 4); }
int TMainCursor::check_flag_1() { return test_flags_any((char*)this + 0x20, 1); }
u8 TMainCursor::is_position_moved() { return (u8)(TMainCursor__sub_8013E570((char*)this + 0x60)); }
s16 TMainCursor__sub_8013E570(void* p) { return *(s16*)((char*)p + 0x6); }
int TMainCursor::check_flag_4() { return set__8FlagWordFUl((char*)this + 0x20, 4); }
int TMainCursor::forward_13E338_at_60() { return TMainCursor__sub_8013E338((char*)this + 0x60); }
int TMainCursor::update_sub_60() { return TMainCursor__sub_8013E358((char*)this + 0x60); }

}
