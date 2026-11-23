#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A0AC4.h"
#include "pso/weapon/shoot/TUnk_804A0AA8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A0AA8::render() {
    if ((is_owner_alive() != 0) && ((uaddr)model != 0U) && ((uaddr)texture_list != 0U)) {
        push_matrix();
        TParticleCtrl::begin_effect_render();
        set_texlist(texture_list);
        post_translate_matrix(&m_pos.x);
        rotate_matrix_by_node_angles(&m_28, 1);
        draw_ginja_object(model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TUnk_804A0AA8::hook() {
    rot_b = rot_b + 0x3333;
}

TUnk_804A0AA8::TUnk_804A0AA8(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    rot_b = 0;
}

saddr TObjPlayer::create_item_shoot_model(void *weapon, const Vec *origin, const Vec *end, f32 frames) {
    TUnk_804A0AA8 *model = NULL;
    if (weapon != NULL) {
        model = new TUnk_804A0AA8(weapon, origin, end, frames);
    }
    return (saddr)model;
}

void TUnk_804A0AC4::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)this)->launch_rare_weapon_special(NULL, 1, 1.0f);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

TUnk_804A0AC4::~TUnk_804A0AC4() {}

TUnk_804A0AC4::TUnk_804A0AC4(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = (WeaponShotCallback)TObjPlayer::create_item_shoot_model;
    shot_speed = 10.0f;
}

TItem *TObjPlayer::create_state_34(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A0AC4(tl_05, item);
    }
    return NULL;
}

TUnk_804A0AA8::~TUnk_804A0AA8() {}
