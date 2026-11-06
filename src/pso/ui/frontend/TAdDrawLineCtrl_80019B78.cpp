#include "types.h"
#include "pso/unk/text_8001A3BC.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
struct Ent_80019B78 { u8 pad[0x2c]; };

struct Tbl_80019B78 { s32 f0; s32 f4; Ent_80019B78 *ents; };

struct Obj_80019B78 { u8 pad[0x1c]; Tbl_80019B78 *tbl; void *f20; f32 f24; };

extern "C" {
void fn_80019EB8(void *n, f32 v);
extern const f32 lbl_805D7DDC;
void TAdDrawLineCtrl::sub_80019B78(s32 idx) {
    Obj_80019B78 *self = (Obj_80019B78 *)this;
    void *r = fn_8001A3BC((s32)self->f20, (u8 *)&self->tbl->ents[idx], (s32)self);
    if (r != 0 && lbl_805D7DDC != self->f24) {
        fn_80019EB8(r, self->f24);
    }
}

}
