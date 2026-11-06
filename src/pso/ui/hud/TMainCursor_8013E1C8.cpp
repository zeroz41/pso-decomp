#include "types.h"
#include "pso/ui/hud/TMainCursor_8013E1C8.h"
#include "pso/ui/hud/TMainCursor.h"
struct Obj_8013E240 { s32 a; u16 b; u16 c; f32 d; f32 e; };

extern "C" {

int TObjPlayer__sub_8013A820(void* a0 = 0);
extern const f32 TMainCursor__data_805DB0C0;
extern const f32 lbl_805DB0C4;
void reset_nearest_target_record(Obj_8013E240 *self);
extern int main_cursor_model;
extern int lock_on_cursor_model;

void TMainCursor::set_target_index(s16 v) { this->m_flags = v; }
void TMainCursor::update_cursor_pos() { ((TMainCursor *)((char*)this + 0x14))->copy_from((char*)this + 0xc); }

void*TMainCursor::copy_from(void* a1) { TObjPlayer__sub_8013A820(this); this->m_flags = *(unsigned short*)((char*)a1 + 0x4); this->m_id = *(short*)((char*)a1 + 0x6); return this; }

void reset_nearest_target_record(Obj_8013E240 *self) {
    self->a = 0;
    self->b = 0xffff;
    self->c = 0xffff;
    self->d = TMainCursor__data_805DB0C0;
    self->e = lbl_805DB0C4;
}

void TMainCursor::set_sub_cursor_value(s32 a1) { TMainCursor__sub_8013E290((void*)((char*)this + 0x3c), a1); }
void TMainCursor__sub_8013E290(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
s16 TMainCursor__sub_8013E298(void* p) { return *(s16*)((char*)p + 0x0); }
s32 TMainCursor__sub_8013E2A0(void* p) { return *(s32*)((char*)p + 0x0); }
s32 TMainCursor::get_index() { return *(s32 *)&this->m_flags; }
void TMainCursor__sub_8013E2B0(void* p) { *(s16*)((char*)p + 0x2) = 0; *(s16*)((char*)p + 0x0) = 0; }
void TMainCursor::reset_slot() { this->m_name = 0; }
void TMainCursor::set_type(s32 v) { *(s32 *)&this->m_flags = v; }

int TMainCursor::get_cursor_state() {  return main_cursor_model; }

int TMainCursor__sub_8013E2DC(void) {  return lock_on_cursor_model; }

}
