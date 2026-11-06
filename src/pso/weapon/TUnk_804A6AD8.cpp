#include "types.h"
#include "pso/weapon/TUnk_804A6AD8.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_80120908.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A6AD8::reserved_53() {
    draw_weapon_model();
    get_joint_position(3, &muzzles[0]);
    get_joint_position(1, &ejectors[0]);
    draw_weapon_at_joint((s32)this, 35);
    get_joint_position(3, &muzzles[1]);
    get_joint_position(1, &ejectors[1]);
}

void TUnk_804A6AD8::vfunc_60() {
    if (TObjPlayer::get_player_list() == 2) {
        post_translate_matrix(&slide.x);
    }
}

void TUnk_804A6AD8::update_weapon() {
    switch (slide_state) {
    case 1:
        slide.y -= 0.29999998f;
        if (slide.y <= 0.0f) {
            slide.y = 0.0f;
            slide_state = 0;
        }
        break;
    case 2:
        slide.y += 0.29999998f;
        if (0.9f <= slide.y) {
            slide.y = 0.9f;
            slide_state = 3;
        }
        break;
    case 3:
        slide_state = 1;
        yasminkov_9000m_eject_casing(&ejectors[0], 0x4000);
        yasminkov_9000m_eject_casing(&ejectors[1], -0x4000);
        break;
    }
}

void TUnk_804A6AD8::emit_marker_effects() {
    slide_state = 2;
    if (launch_shot((u8 *)&muzzles[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&muzzles[1], 0, 0, 0);
    } else {
        launch_shot((u8 *)&muzzles[1], 0, 0, 1);
    }
    spawn_particle_effect(&muzzles[0], 9);
    spawn_particle_effect(&muzzles[1], 9);
}

void TUnk_804A6AD8::yasminkov_9000m_eject_casing(WeaponVector *pos, s32 angle_offset) {
    WeaponVector dir;
    s32 angle[3];
    s32 a;

    if (owner != NULL) {
        a = owner->rotation_y - angle_offset;
        dir.x = sin_table_lookup(a);
        dir.y = 1.0f;
        dir.z = cos_table_lookup(a);
        angle[0] = 0x4000;
        angle[1] = owner->rotation_y;
        angle[2] = 0;
        TObjPlayer::spawn_weapon_casing((s32)tl_05, (u32)this, (u32)pos, (u32)&dir, (u32)angle);
    }
}

TUnk_804A6AD8::~TUnk_804A6AD8() {}

TUnk_804A6AD8::TUnk_804A6AD8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    set_weapon_flags(515);
    slide_state = 0;
    slide.x = slide.y = slide.z = 0.0f;
}

u8 *create_yasminkov_9000m(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A6AD8(tl_05, item);
    }
    return NULL;
}
