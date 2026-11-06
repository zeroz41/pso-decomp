#include "types.h"
#include "pso/player/TPlyDispData.h"
#include "pso/system/memory.h"
#include "pso/ui/hud/TLockOnCursor.h"

extern s32 lbl_804A7248[];

void *TLockOnCursor::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&this->m_prev = lbl_804A7248;
        TPlyDispConfig::free_if_valid((s32)this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

void TLockOnCursor::sub_8013EEC0(s16 v) { *(s16*)((char*)this + 0x20) = v; }
