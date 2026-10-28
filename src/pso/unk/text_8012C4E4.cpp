#include "types.h"
#include "pso/TItemShootModel.h"
#include "pso/player/TObjPlayer.h"
struct Obj_8012C4E4 { u8 pad[0x18]; void *vt; };

extern "C" {
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *self, void *owner, const void *a, const void *b, f32 f);
extern char __vt__13TUnk_804A5340[];
Obj_8012C4E4 *TObjPlayer__sub_8012C4E4(Obj_8012C4E4 *self, void *owner, const void *a, const void *b, f32 f);
Obj_8012C4E4 *TObjPlayer__sub_8012C4E4(Obj_8012C4E4 *self, void *owner, const void *a, const void *b, f32 f) {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(self, owner, a, b, f);
    self->vt = __vt__13TUnk_804A5340;
    ((TItemShootModel *)self)->sub_80129118(((TObjPlayer *)owner)->get_hp_by_flag(), ((TObjPlayer *)owner)->get_texture_id());
    return self;
}

}
