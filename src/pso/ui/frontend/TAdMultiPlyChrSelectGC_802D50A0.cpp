#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"

extern "C" {
s32 TAdMultiPlyChrSelectGC::get_player_index() { return this->m_24; }
void TAdMultiPlyChrSelectGC::set_cursor_index(s32 v) { this->m_24 = v; }
void TAdMultiPlyChrSelectGC::set_field_100(s32 v) { *(s32*)((char*)this + 0x100) = v; }

void fn_802D50B8(void *arg0, void *arg1, void *arg2, void *arg3) {
    ((TWindowSubSymbolChatPartsSet *)((char *)arg0 + 132))->copy_vec2(arg1);
    ((TWindowSubSymbolChatPartsSet *)((char *)arg0 + 140))->copy_vec2(arg2);
    ((TWindowSubSymbolChatPartsSet *)((char *)arg0 + 148))->copy_vec2(arg3);
}

}
