#include "types.h"
#include "pso/item/TUnk_804A1F20.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

void TUnk_804A1F20::update_weapon() {
    NJS_OBJECT *model;

    refresh_owner_stats();
    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child, 2, 0, 1);
    }
}

TUnk_804A1F20::~TUnk_804A1F20() {}
TUnk_804A1F20::TUnk_804A1F20(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *create_delsabers_buster_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1F20(tl_05, arg0);
    }
    return NULL;
}
