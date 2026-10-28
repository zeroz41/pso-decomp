#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TMainCursor_8013E44C.h"
#include "pso/misc/TMainCursor.h"

extern "C" {
int set__8FlagWordFUl(void*, int);

int TMainCursor::is_same_target(void *b) {
    u8 result = 0;
    if (TMainCursor__sub_8013E40C((TMainCursor *)this, ((TMainCursor *)b)->get_id()) != 0) {
        if (((u8)this->get_type()) == ((u8)((TMainCursor *)b)->get_type())) {
            if (((u8)this->get_enabled()) == ((u8)((TMainCursor *)b)->get_enabled())) {
                result = 1;
            }
        }
    }
    return result;
}

int TMainCursor__sub_8013E40C(TMainCursor *main_cursor, u16 arg1) {
    return (u8) (arg1 == main_cursor->get_id());
}

}

#include "pso/TAdRicoRing.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/misc/TWindowActionPalette.h"

void*TMainCursor::get_list() { return (char*)this + 0xc; }
int TMainCursor::update_target_sub() { return set__8FlagWordFUl((char*)this + 0x20, 1); }
