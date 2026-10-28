#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_8012712C.h"
#include "pso/item/TUnk_804A3070.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"

struct Self_8012712C { u8 pad[0x18]; void *vt; u8 pad1c[0x1e4 - 0x1c]; f32 f1e4; u8 pad1e8[0x1f0 - 0x1e8]; void *f1f0; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void create_lavis_shot(void);
extern void *lbl_804A3070[];
extern const f32 lbl_805DADB8;

u8 *TUnk_804A3070::construct_agito(s32 a, void *b) {
    Self_8012712C *self = (Self_8012712C *)this;
    TItemWeapon__ct((TItemWeapon *)((u8 *)self), (void *)a, (u8 *)b);
    self->vt = lbl_804A3070;
    ((TObjPlayer *)self)->set_status_flags(2);
    if (((TItem *)self)->get_item_index() == 0) {
        ((TObjPlayer *)self)->set_status_flags(0x20);
        self->f1f0 = (void *)create_lavis_shot;
        self->f1e4 = lbl_805DADB8;
    }
    return (u8 *)self;
}
}

u8 *create_agito_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TUnk_804A3070 *)temp_r3)->construct_agito(tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
