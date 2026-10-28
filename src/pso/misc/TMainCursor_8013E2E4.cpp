#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TMainCursor_8013E2E4.h"
#include "pso/misc/TMainCursor.h"
#include "pso/TAdRicoRing.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/misc/TWindowActionPalette.h"

extern "C" {

int set__8FlagWordFUl(void*, int);
int TMainCursor__sub_8013B2A4(void*);
int get_enabled__11TMainCursorFv(void*);
int get_type__11TMainCursorFv(void*);

int TMainCursor::check_field_24() { return TMainCursor__sub_8013B2A4((char*)this + 0x24); }
u16 TMainCursor::get_id() { return this->m_flags; }
int TMainCursor__sub_8013E310(void* p) { return set__8FlagWordFUl((char*)p + 0x20, 2); }
int TMainCursor__sub_8013E338(void* p) { return get_enabled__11TMainCursorFv(p); }
int TMainCursor__sub_8013E358(void* p) { return get_type__11TMainCursorFv(p); }

}
