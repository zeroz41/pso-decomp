#include "types.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_801272B4.h"
#include "pso/player/TObjPlayer.h"

struct Self_801272B4 { u8 pad[0x18]; void *vt; u8 pad1c[0x1e4 - 0x1c]; f32 f1e4; u8 pad1e8[0x1f0 - 0x1e8]; void *f1f0; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void create_lavis_shot(void);
extern void *lbl_804A3168[];
extern const f32 lbl_805DADC8;

u8 *TObjPlayer__sub_801272B4(void *self_, s32 a, void *b) {
    Self_801272B4 *self = (Self_801272B4 *)self_;
    TItemWeapon__ct((TItemWeapon *)((u8 *)self), (void *)a, (u8 *)b);
    self->vt = lbl_804A3168;
    ((TObjPlayer *)self)->set_status_flags(0x100622);
    self->f1f0 = (void *)create_lavis_shot;
    ((TObjPlayer *)self)->m_1e4 = lbl_805DADC8;
    return (u8 *)self;
}

u8 *TObjPlayer__sub_80127314(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_801272B4(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
