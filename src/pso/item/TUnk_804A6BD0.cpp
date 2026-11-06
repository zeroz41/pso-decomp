#include "types.h"
#include "pso/item/TUnk_804A6BD0.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_80087278.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"

void TUnk_804A6BD0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        post_translate_matrix(&slide.x);
    }
}

void TUnk_804A6BD0::emit_marker_effects() {
    WeaponVector dir;
    s32 angle[3];
    WeaponVector muzzle;
    s32 a;

    slide_state = 2;
    a = owner->rotation_y - 0x4000;
    dir.x = sin_table_lookup(a);
    dir.y = 1.0f;
    dir.z = cos_table_lookup(a);
    angle[0] = 0x4000;
    angle[1] = owner->rotation_y;
    angle[2] = 0;
    TObjPlayer::launch_weapon_casing((s32)tl_05, (u32)this, 3, (u32)&dir, (u32)angle);
    get_joint_position(2, &muzzle);
    spawn_particle_effect(&muzzle, 9);
}

void TUnk_804A6BD0::update_weapon() {
    switch (slide_state) {
    case 1:
        if (0.0f < slide.z) {
            slide.z -= 0.5f;
            if (slide.z <= 0.0f) {
                slide.z = 0.0f;
                slide_state = 0;
            }
        }
        break;
    case 2:
        if (slide.z < 1.4f) {
            slide.z += 0.5f;
            if (1.4f <= slide.z) {
                slide.z = 1.4f;
                slide_state = 3;
            }
        }
        break;
    case 3:
        slide_state = 1;
        break;
    }
}

TUnk_804A6BD0::~TUnk_804A6BD0() {}

TUnk_804A6BD0::TUnk_804A6BD0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    slide.x = slide.y = slide.z = 0.0f;
    slide_state = 0;
}

u8 *create_yasminkov_3000r(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A6BD0(tl_05, item);
    }
    return NULL;
}
