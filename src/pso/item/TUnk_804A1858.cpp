#include "types.h"
#include "pso/player/TUnk_804A1858.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/TMainTask.h"

void TUnk_804A1858::emit_marker_effects() {
    WeaponVector pos;

    get_joint_position(2, &pos);
    pos.y -= 15.0f;
    spawn_particle_effect(&pos, 0x1D2);
}

void TUnk_804A1858::update_weapon() {
    NJS_OBJECT *model;

    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child, uv_scroll, 0, 0);
    }
}

TUnk_804A1858::TUnk_804A1858(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    uv_scroll = 35;
}

u8 *TObjPlayer::create_state_35(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1858(tl_05, arg0);
    }
    return NULL;
}
