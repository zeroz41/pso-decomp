#include "types.h"
#include "pso/player/TObjPlayer_80129048.h"
#include "pso/TItemShootModel.h"
#include "pso/player/TObjPlayer.h"
struct Obj_80128BD4 { u8 pad[0x18]; void *vt; };

extern "C" {
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *self, void *owner, const void *a, const void *b, f32 f);
extern char __vt__13TUnk_804A4020[];
Obj_80128BD4 *TObjPlayer__sub_80128BD4(Obj_80128BD4 *self, void *owner, const void *a, const void *b, f32 f);
Obj_80128BD4 *TObjPlayer__sub_80128BD4(Obj_80128BD4 *self, void *owner, const void *a, const void *b, f32 f) {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(self, owner, a, b, f);
    self->vt = __vt__13TUnk_804A4020;
    ((TItemShootModel *)self)->sub_80129118(TObjPlayer__sub_801290D0((u8 *)owner), ((TObjPlayer *)owner)->get_texture_id());
    return self;
}

}
