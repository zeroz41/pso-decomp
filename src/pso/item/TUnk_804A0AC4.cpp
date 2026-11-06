#include "types.h"
#include "pso/item/TUnk_804A0AC4.h"
#include "pso/player/TUnk_804A0AA8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/TMainTask.h"

void TUnk_804A0AA8::render() {
    if ((is_owner_alive() != 0) && ((u32)m_58 != 0U) && ((u32)m_5C != 0U)) {
        push_matrix();
        TParticleCtrl::begin_effect_render();
        set_texlist((u32)m_5C);
        post_translate_matrix(&m_pos.x);
        rotate_matrix_by_node_angles(&m_28, 1);
        draw_ginja_object(m_58);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TUnk_804A0AA8::hook() {
    m_30 = m_30 + 0x3333;
}

TUnk_804A0AA8::TUnk_804A0AA8(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    m_30 = 0;
}

int TObjPlayer::create_item_shoot_model(int weapon, int origin, int end, f32 frames) {
    TUnk_804A0AA8 *model = NULL;
    if (weapon != 0) {
        model = new TUnk_804A0AA8((void *)weapon, (const Vec *)origin, (const Vec *)end, frames);
    }
    return (int)model;
}

void TUnk_804A0AC4::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)this)->launch_rare_weapon_special(NULL, 1, 1.0f);
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

TUnk_804A0AC4::~TUnk_804A0AC4() {}

TUnk_804A0AC4::TUnk_804A0AC4(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = (WeaponShotCallback)TObjPlayer::create_item_shoot_model;
    shot_speed = 10.0f;
}

u8 *TObjPlayer::create_state_34(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A0AC4(tl_05, (u8 *)arg0);
    }
    return NULL;
}

TUnk_804A0AA8::~TUnk_804A0AA8() {}
