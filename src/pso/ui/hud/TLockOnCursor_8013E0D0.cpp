#include "types.h"
#include "pso/ui/hud/TLockOnCursor_8013E0D0.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/unk/TUnk_804A7260.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 { char pad_0[0x1C]; char f_1C[1]; };

void __ct__7TObjectFP7TObject(void *);
void fn_8013E020(void *);
void set_field_0__13TForceOperateFs(void *, void *);

void TLockOnCursor__sub_8013E0D0(void* p, s32 v) { *(s32*)((char*)p + 0x8) = v; }

extern s32 lbl_804A7260[];

void *TUnk_804A7260::init(void *arg1, void *arg2) {
    struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 *self = (struct VOff_8013E0D8_arg0_8013e0d8_8013E0D0 *)this;
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A7260;
    fn_8013E020(self->f_1C);
    disallow_rendering__7TObjectFv(this);
    set_field_0__13TForceOperateFs(self->f_1C, arg2);
    return this;
}

}
