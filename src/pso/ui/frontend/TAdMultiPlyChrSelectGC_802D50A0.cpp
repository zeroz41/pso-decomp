#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"

extern "C" {
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *);
s32 TAdMultiPlyChrSelectGC::get_player_index() { return this->m_24; }
void TAdMultiPlyChrSelectGC::set_cursor_index(s32 v) { this->m_24 = v; }
void TAdMultiPlyChrSelectGC::set_field_100(s32 v) { *(s32*)((char*)this + 0x100) = v; }

void fn_802D50B8(void *arg0, void *arg1, void *arg2, void *arg3) {
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv((void *)((char *)arg0 + 132));
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)arg0 + 140), arg2);
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)arg0 + 148), arg3);
}

}
