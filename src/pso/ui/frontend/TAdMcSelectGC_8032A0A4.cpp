#include "types.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMcSelectGC_8032A0A4.h"
#include "pso/ui/frontend/TAdMcSelectMcGC_8032A964.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"

extern "C" {
void *TAdMcSelectGC__ct(void *, void *);
void *__nw__7TObjectFUl(int);

extern void *TAdMcSelectGC__instance;

void *TAdMcSelectGC::create(void *arg0) {
    void *o;
    o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = TAdMcSelectGC__ct(o, arg0);
    }
    TAdMcSelectGC__instance = o;
    return o;
}

void TAdMcSelectGC::open() { TLobby__sub_802C78EC(); release_selected_entry__15TAdMcSelectMcGCFv(); TAdMcSelectCursorGC::release_cursor_entry(); }
void TAdMcSelectGC::close() { TAdMcSelectCursorGC::init_resource(); init_memorycard__15TAdMcSelectMcGCFv(); TLobby__sub_802C7920(); }
void TAdMcSelectGC__sub_8032A140(void* p) { *(s32*)((char*)p + 0x1c) = 0; }

    extern int TAdMcSelectCursorGC__instance;
int TAdMcSelectGC::get_mc_count() {  return TAdMcSelectCursorGC__instance; }

s32 TAdMcSelectGC::get_slot_index() { return *(s32 *)&this->_pad20; }
void TAdMcSelectGC__sub_8032A15C(void* p) { *(s32*)((char*)p + 0x1c) = 1; }
void TAdMcSelectGC::set_field_13c(s32 v) { *(s32*)((char*)this + 0x13c) = v; }
void TAdMcSelectGC::set_field_0x1c(s32 v) { this->m_1c = v; }
void TAdMcSelectGC::set_select_index(s32 v) { *(s32*)((char*)this + 0x124) = v; }
void TAdMcSelectGC__sub_8032A180(void* p, s32 v) { *(s32*)((char*)p + 0x28) = v; }

void TAdMcSelectGC::set_field_134(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x134) = arg1;
    TAdMcSelectGC__sub_8032A180((void*)((int) (*(s32 *)((s8 *)arg0 + 0x130))), arg1);
}

void TAdMcSelectGC::set_field_24(s32 v) { this->m_24 = v; }
void TAdMcSelectGC::set_field20(f32 v) { *(f32 *)&this->_pad20 = v; }
void TAdMcSelectGC::set_field_20(s32 v) { *(s32 *)&this->_pad20 = v; }
void TAdMcSelectGC::set_float_1c(f32 v) { *(f32 *)&this->m_1c = v; }

}
