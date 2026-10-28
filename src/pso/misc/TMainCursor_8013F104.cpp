#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TMainCursor_8013F104.h"
#include "pso/system/memory.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8013F1F0_lbl_804A7254 {
    s32 value;
    u8 remaining[0x8];
};

struct Rec_8013F154 { u8 pad[0x8]; };

struct Obj_8013F154 { u8 pad[0x4]; Rec_8013F154 recs[1]; };

struct Obj_8013F24C { u8 pad[0x44]; u8 arr[1]; };

extern "C" {
extern s32 lbl_804A7254[];
Rec_8013F154 *get_record_at__11TMainCursorFPvi(Obj_8013F154 *self, s32 i);
u8 fn_8013F24C(Obj_8013F24C *self, s16 i);

void TMainCursor__sub_8013F104(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }
void TMainCursor__sub_8013F10C(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
void TMainCursor__sub_8013F114(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }

void TMainCursor::set_cursor_id(s16 v) { *(s16 *)&this->m_name = v; }
void TMainCursor::set_field2(s16 v) { *(s16*)((char*)this + 0x2) = v; }
void TMainCursor::set_size(f32 v) { *(f32 *)&this->m_flags = v; }

void TMainCursor__sub_8013F13C(s32 *arg0) {
    *arg0 += 1;
}

f32 TMainCursor__sub_8013F14C(void* p) { return *(f32*)((char*)p + 0x4); }

Rec_8013F154 *get_record_at__11TMainCursorFPvi(Obj_8013F154 *self, s32 i) {
    return &self->recs[i];
}

s32 TMainCursor__sub_8013F168(void* p) { return *(s32*)((char*)p + 0x0); }
void TMainCursor__sub_8013F170(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

f32 TMainCursor::get_pos() { return *(f32 *)&this->m_name; }
void TMainCursor__sub_8013F180(void* p, f32 v) { *(f32*)((char*)p + 0x0) = v; }

int TMainCursor::get_rader_map() { return ((int (*)(void *))copy_argb)(this); }

void *TMainCursor::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&this->m_up = lbl_804A7254;
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

    extern const float TMainCursor__data_805DB0C0;

typedef char RecoveredGlobal_8013F1F0_lbl_804A7254_size[sizeof(RecoveredGlobal_8013F1F0_lbl_804A7254) == 0xC ? 1 : -1];
u8 *TMainCursor__sub_8013F1F0(u8 *arg0) {
    *(s32 **)((s8 *)arg0 + 0x10) = &(*(RecoveredGlobal_8013F1F0_lbl_804A7254 *)&lbl_804A7254).value;
    TMainCursor__sub_8013F22C(arg0);
    return arg0;
}

void TMainCursor__sub_8013F22C(void* a0) { *(float*)((char*)a0 + 0xc) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x8) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x4) = TMainCursor__data_805DB0C0; *(float*)((char*)a0 + 0x0) = TMainCursor__data_805DB0C0; }

int TMainCursor__sub_8013F244(void) { return -1; }
u8 fn_8013F24C(Obj_8013F24C *self, s16 i) {
    return self->arr[i];
}

}
