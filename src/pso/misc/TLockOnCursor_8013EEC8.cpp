#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TLockOnCursor_8013EDC4.h"
#include "pso/misc/TLockOnCursor_8013EEC8.h"
#include "pso/misc/TMainCursor_8013F104.h"
#include "pso/unk/text_80072004.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/misc/TMainCursor.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
extern s32 TMainCursor__sub_8013E2B0[];
void __construct_array(void *, void *, int, int, int);
int TLockOnCursor__sub_8013EC1C(void*);
int reset_nearest_target_record(void*);
void *fn_8004438C(void *p);

extern s32 lbl_804A7248[];

void *TLockOnCursor::init_vtable() {
    init_gc_tag((s32)this);
    *(s32 * *)&this->m_prev = lbl_804A7248;
    *(u32 *)&this->m_flags = 0;
    return this;
}

void*TLockOnCursor::init_cursor() { reset_nearest_target_record(this); return this; }
void*TLockOnCursor::init_forward() { TLockOnCursor__sub_8013EC1C(this); return this; }
void*TLockOnCursor::cleanup() { init_gc_tag((s32)((char*)this + 0x8)); ((TMainCursor *)((char*)this + 0xc))->reset(); ((TMainCursor *)((char*)this + 0x14))->reset(); reset_state(); return this; }

void *TLockOnCursor__sub_8013EFB8(void *main_cursor) {
    init_gc_tag((s32)main_cursor);
    ((TObjPlayer *)((char *)main_cursor + 64))->construct_target_cursor_records();
    TLockOnCursor__sub_8013F000((void *)((void *)((void *)((char *)main_cursor + 156))));
    ((TMainCursor *)main_cursor)->reset_state();
    return main_cursor;
}

int TLockOnCursor__sub_8013F000(void *self) {
    __construct_array((char *)self + 4, (void *)init_sub__13TLockOnCursorFPv, (int)TLockOnCursor__sub_8013EDC4, 0xc, 0xb);
    ((TMainCursor *)self)->reset_slot();
    return (int)self;
}

void* init_sub__13TLockOnCursorFPv(void* p) { fn_8004438C(p); __ct__8FlagWordFv(((char*)p + 0x8)); return p; }
void TLockOnCursor::reset_fields() { *(s32 *)&this->m_name = 0; *(s32 *)&this->m_flags = 0; *(s32 *)&this->m_prev = 0; }

struct VOff_8013F0A0_arg0 { char pad_0[0x8]; char f_8[1]; };
void *fn_8013F0A0(void *arg0) {
    struct VOff_8013F0A0_arg0 *self = (struct VOff_8013F0A0_arg0 *)arg0;
    TMainCursor__sub_8013F114(arg0);
    __construct_array(self->f_8, TMainCursor__sub_8013E2B0, 0, 4, 4);
    TMainCursor__sub_8013F10C(arg0, 4);
    TMainCursor__sub_8013F104((void*)arg0, (s32)self->f_8);
    return arg0;
}

}
