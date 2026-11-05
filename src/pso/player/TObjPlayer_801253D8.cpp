#include "types.h"
#include "pso/player/TUnk_804A2450.h"
#include "pso/player/TObjPlayer.h"

#include "pso/unk/text_8011BEF0.h"

TUnk_804A2450::TUnk_804A2450(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)spawn_shoot_particle_9f;
    shot_speed = 11.0f;
}
