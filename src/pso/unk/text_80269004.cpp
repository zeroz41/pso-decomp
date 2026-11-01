#include "types.h"
struct Obj_80269004 { u8 p0[0x18]; void *f18; };

extern "C" {
void construct_with_parent__15TWindowAdditionFPv(void *, void *, s32, void *);
void TWindowMenuInfomation__ct(u8 *arg0, u32 arg1);
extern u8 choice_setting_popup_window_descriptor[];
extern u8 choice_setting_popup_vtable[];
Obj_80269004 *fn_80269004(Obj_80269004 *self, void *parent, void *arg2);
Obj_80269004 *fn_80269004(Obj_80269004 *self, void *parent, void *arg2) {
    construct_with_parent__15TWindowAdditionFPv(self, choice_setting_popup_window_descriptor, 4, parent);
    self->f18 = choice_setting_popup_vtable;
    TWindowMenuInfomation__ct((u8 *)self, (u32)arg2);
    return self;
}

}
