#include "types.h"
#include "pso/player/TUnk_804A1668.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TItemEffBringer.h"
#include "pso/TMainTask.h"

void TUnk_804A1668::update_weapon() {
    NJS_OBJECT *model;

    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child, uv_scroll, 0, 1);
    }
}

TUnk_804A1668::TUnk_804A1668(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    uv_scroll = 2;
    shot_callback = (WeaponShotCallback)TItemEffBringer::create;
}

u8 *TObjPlayer::create_bringer_effect(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1668(tl_05, arg0);
    }
    return NULL;
}
