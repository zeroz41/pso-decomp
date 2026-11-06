#include "types.h"
#include "pso/item/TUnk_804A0DB0.h"
#include "pso/player/TObjPlayer_80122014.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"


void belra_cannon_return_timer(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
    }
}

void TUnk_804A0DB0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        scale_current_matrix(&scale.x);
    }
}

void TUnk_804A0DB0::emit_marker_effects() { scale.y = 0.1f; }

void TUnk_804A0DB0::update_weapon() {
    f32 y;

    y = scale.y;
    if (y < 1.0f) {
        scale.y += 0.1f;
        if (1.0f <= scale.y) {
            scale.y = 1.0f;
        }
    }
}

TUnk_804A0DB0::~TUnk_804A0DB0() {}

TUnk_804A0DB0::TUnk_804A0DB0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_state_vector_state(s32 item) {
    if (item != 0) {
        return (u8 *)new TUnk_804A0DB0(tl_05, (u8 *)item);
    }
    return NULL;
}
