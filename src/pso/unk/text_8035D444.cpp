#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/unk/text_8035D444.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TMainTask.h"

TUnk_804F1EC8::~TUnk_804F1EC8() {}

TUnk_804F1EC8::TUnk_804F1EC8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
}

u8 *alloc_and_init_obj_effect(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804F1EC8(tl_05, arg0);
    }
    return NULL;
}
