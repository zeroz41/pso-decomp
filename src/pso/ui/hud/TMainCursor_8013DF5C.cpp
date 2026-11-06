#include "types.h"
#include "pso/ui/hud/TLockOnCursor_8013E0D0.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/unk/TUnk_804A7260.h"
#include "pso/player/TForceOperate.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/window/TWindowActionPalette.h"

struct Obj_8013E020 { u16 a; u16 b; s32 c; };

extern "C" {
void fn_8013E020(Obj_8013E020 *self);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *);
void set_field_0__13TForceOperateFs(void *, void *);

int matches_type_and_enabled__11TMainCursorFiUcUc(s32 arg0, u8 arg1, u8 arg2) {
    s32 var_r31;
    var_r31 = 0;
    if ((arg1 == ((TMainCursor *)arg0)->get_type()) && (arg2 == ((TMainCursor *)arg0)->get_enabled())) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

void TMainCursor__sub_8013DFC4(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) & 0xFFFFFFFE);
}

s32 TMainCursor::get_state() { return *(s32 *)&this->m_flags; }

s32 TForceOperate::destroy(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void TForceOperate::set_field_0(s16 v) { *(s16 *)&this->m_name = v; }

void fn_8013E020(Obj_8013E020 *self) {
    self->a = self->b = 0xffff;
    self->c = 0;
}

u16 TMainCursor__sub_8013E03C(void* p) { return *(u16*)((char*)p + 0x0); }

extern s32 lbl_804A7260[];

void *TUnk_804A7260::destroy_cursor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804A7260;
        TForceOperate::destroy((s32)((s8 *)this + 0x1C), (s16)(-1));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void TMainCursor::destroy_lock_on(s32 a1) { TLockOnCursor__sub_8013E0D0((char*)this + 0x3c, a1); }

struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 { char pad_0[0x1C]; Obj_8013E020 f_1C; };

void TLockOnCursor__sub_8013E0D0(void* p, s32 v) { *(s32*)((char*)p + 0x8) = v; }

void *TUnk_804A7260::init(void *arg1, void *arg2) {
    struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 *self = (struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 *)this;
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A7260;
    fn_8013E020(&self->f_1C);
    disallow_rendering__7TObjectFv(this);
    set_field_0__13TForceOperateFs(&self->f_1C, arg2);
    return this;
}

}
