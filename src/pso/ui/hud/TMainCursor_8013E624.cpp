#include "types.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/hud/TMainCursor_8013E624.h"
#include "pso/player/TPlyDispConfig_80071F1C.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {
s32 __dl__FPv(void* a0);
int set_slot__20TWindowActionPaletteFUc(void*);
int set_mode__20TWindowActionPaletteFUc(void*);

s32 TMainCursor::delete_this(s16 arg1) {
    s32 arg0 = (s32)this;
    if ((arg0 != 0) && (arg1 > 0)) {
        ((s32)__dl__FPv((void*)arg0));
    }
    return arg0;
}

}

#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/player/TObjPlayer.h"

s32 destroy__11TMainCursorFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TPlyDispConfig::free_if_valid(arg0, -1);
        if (arg1 > 0) {
            __dl__FPv((void*)arg0);
        }
    }
    return arg0;
}
void TMainCursor::set_offset_y(s16 a1) { TMainCursor__sub_8013E694((char*)this + 0x24, a1); }
void TMainCursor__sub_8013E694(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
int TMainCursor::init_field_60() { return ((TMainCursor *)((char*)this + 0x60))->get_action_palette(); }
int TMainCursor::get_action_palette() { return set_slot__20TWindowActionPaletteFUc(this); }
int TMainCursor__sub_8013E6E0(void* p) { return ((TMainCursor *)((char*)p + 0x60))->update_action_palette(); }
int TMainCursor::update_action_palette() { return set_mode__20TWindowActionPaletteFUc(this); }
void TMainCursor::sub_8013E724(f32 v) { this->m_2c = v; }
