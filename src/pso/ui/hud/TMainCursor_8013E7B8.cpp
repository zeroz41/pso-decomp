#include "types.h"
#include "pso/ui/hud/TMainCursor_8013E7B8.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

s32 init__6gc_tagFv();
int test_flags_any(void*, int);
int TObjPlayer__sub_8013DEF8(void*);
int is_channel_active__11TMainCursorFv(void*);
int get_enabled__11TMainCursorFv(void*);
int get_type__11TMainCursorFv(void*);
int set_slot__20TWindowActionPaletteFUc(void*);
int set_mode__20TWindowActionPaletteFUc(void*);
int TMainCursor__sub_8013DFC4(void*);
int set_target_index__11TMainCursorFs(void*, void* a1 = 0);

void TMainCursor::reset_target() {
    s32 arg0 = (s32)this;
    init__6gc_tagFv();
    set_target_index__11TMainCursorFs((void*)arg0, (void*)(0xFFFF));
    ((TMainCursor *)arg0)->set_target_id(0);
}

}

struct Obj_8013E800 { u16 a; };

extern "C" {
void TMainCursor__sub_8013E800(Obj_8013E800 *self);

void TMainCursor__sub_8013E800(Obj_8013E800 *self) {
    self->a = 0xffff;
}

s32 TMainCursor::get_body_exclude_mask() { return *(s32 *)&this->m_next; }
s32 TMainCursor::get_body_include_mask() { return *(s32 *)&this->m_prev; }
s32 TMainCursor::get_actor_exclude_mask() { return *(s32 *)&this->m_down; }
s32 TMainCursor::get_actor_include_mask() { return *(s32 *)&this->m_up; }
void TMainCursor::store_sorted_record(void* p, void* a1, void* a2) { ((int (*)(void *))copy_target_record__11TMainCursorFPvPv)(a2); }

}

struct Rec_8013E870 { u8 pad[0x124]; };

struct Obj_8013E870 { u8 pad[0x5c]; Rec_8013E870 recs[1]; };

void copy_target_record__11TMainCursorFPvPv(u8 *arg0, u8 *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(f32 *)((s8 *)arg0 + 4) = (f32) *(f32 *)((s8 *)arg1 + 4);
}
void TMainCursor::init_slot(s32 i) {
    TMainCursor__sub_8013E8A0((void*)(&((Obj_8013E870 *)this)->recs[i]));
}

#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

int TMainCursor__sub_8013E8A0(void* p) { return TObjPlayer__sub_8013DEF8(p); }
int TMainCursor::get_selected_entry() { return is_channel_active__11TMainCursorFv(this); }
int TMainCursor::get_active() { return get_enabled__11TMainCursorFv(this); }
int TMainCursor__sub_8013E900(void* p) { return get_type__11TMainCursorFv(p); }
s16 TMainCursor__sub_8013E920(void* p) { return *(s16*)((char*)p + 0x2); }
void TMainCursor__sub_8013E928(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }
void TMainCursor__sub_8013E930(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
u16 TLockOnCursor::get_target_id() { return *(u16 *)&(*(void * *)((u8 *)this + 0x20)); }
int TMainCursor::is_cursor_clear() { return (test_flags_any((char*)this + 0x1c, 1)) == 0; }

void TMainCursor__sub_8013E970(u8 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    *(s16 *)((s8 *)arg0 + 0) = arg1;
    *(s16 *)((s8 *)arg0 + 2) = arg2;
    *(s16 *)((s8 *)arg0 + 4) = arg3;
}

void TMainCursor::set_color_mode(s32 v) { *(s32 *)&this->m_up = v; }
void TMainCursor::set_color(s32 v) { *(s32 *)&this->m_prev = v; }
void TMainCursor::set_field_0c(s32 v) { *(s32 *)&this->m_next = v; }
void TMainCursor::set_flags(s32 v) { *(s32 *)&this->m_down = v; }

int TMainCursor__sub_8013E9A0(void* p) { return TMainCursor__sub_8013DFC4(p); }
int TMainCursor__sub_8013E9C0(void* p) { return set_slot__20TWindowActionPaletteFUc(p); }
int TMainCursor__sub_8013E9E0(void* p) { return set_mode__20TWindowActionPaletteFUc(p); }
void TMainCursor__sub_8013EA00(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
