#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/weapon/TUnk_804A6CC8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A6DC0.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"

struct Obj_80131334 { u8 pad[0x1f8]; s32 state; };


// Yasminkov 7000V (inferred)
void TUnk_804A6DC0::vfunc_60() { if (TObjPlayer::get_player_list() == 1) { post_translate_matrix(&this->m_1fc); } }

#pragma push
#pragma opt_common_subs off

void TUnk_804A6DC0::update_weapon() {
    f32 buffer_14[3];
    s32 buffer_8[3];
    s32 angle;
    switch (this->state) {
    case 1:
        this->m_200 = (f32) (this->m_200 - 0.90000004f);
        if (this->m_200 <= 0.0f) {
            this->m_200 = 0.0f;
            this->state = 0;
            break;
        }
        break;
    case 2:
        this->m_200 += 0.90000004f;
        if (2.7f <= this->m_200) {
            this->m_200 = 2.7f;
            this->state = 3;
            break;
        }
        break;
    case 3:
        this->state = 1;
        angle = *(s32 *)((s8 *)this->owner + 0x60) - 0x4000;
        buffer_14[0] = sin_table_lookup(angle);
        buffer_14[1] = 1.0f;
        buffer_14[2] = cos_table_lookup(angle);
        buffer_8[0] = 0x4000;
        buffer_8[1] = *(s32 *)((s8 *)this->owner + 0x60);
        buffer_8[2] = 0;
        TObjPlayer::launch_weapon_casing((saddr)tl_05, (uaddr) this, 2, (uaddr) &buffer_14[0], (uaddr) &buffer_8[0]);
        break;
    }
}
#pragma pop

void TUnk_804A6DC0::emit_marker_effects() {
    Obj_80131334 *self = (Obj_80131334 *)this;
    Vec muzzle;
    this->state = 2;
    ((TItemWeapon *)self)->get_gun_point(&muzzle);
    spawn_particle_effect(&muzzle, 9);
}

TUnk_804A6DC0::~TUnk_804A6DC0() {

}

TUnk_804A6DC0::TUnk_804A6DC0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    state = 0;
    *(f32 *)unk_204 = 0.0f;
    m_200 = 0.0f;
    m_1fc = 0.0f;
}

TItem *create_yasminkov_7000v(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A6DC0(tl_05, item);
    }
    return NULL;
}
