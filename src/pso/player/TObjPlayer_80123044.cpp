#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TUnk_804A1668.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

void TUnk_804A1668::update_weapon() {
    void *temp_r3;

    temp_r3 = (*(void * *)((u8 *)this + 0xF4));
    if (temp_r3 != NULL) {
        scroll_item_model_uvs(*(NJS_OBJECT **)((s8 *)temp_r3 + 0x2C), *(s16 *)&this->unk_1F8, 0, 1);
    }
}

extern s32 lbl_804A1668[];
extern s32 create__15TItemEffBringerFUlllf[];

void *TUnk_804A1668::init_bringer_effect() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A1668;
    *(u16 *)((s8 *)this + 0x1F8) = 2;
    *(s32 **)((s8 *)this + 0x1F0) = create__15TItemEffBringerFUlllf;
    return this;
}

}
