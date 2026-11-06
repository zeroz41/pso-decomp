#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/unk/text_80087278.h"
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

extern "C" {
    
int get_player_list__10TObjPlayerFv(void*);
}

// Yasminkov 7000V (inferred)
void TUnk_804A6DC0::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 1) { post_translate_matrix(&this->m_1fc); } }

#pragma push
#pragma opt_common_subs off

void TUnk_804A6DC0::update_weapon() {
    f32 buffer_14[3];
    s32 buffer_8[3];
    s32 temp_r31;
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x1F8)) {
    case 1:
        this->m_200 = (f32) (this->m_200 - 0.90000004f);
        if (this->m_200 <= 0.0f) {
            this->m_200 = (f32) 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = 0;
            break;
        }
        break;
    case 2:
        this->m_200 += 0.90000004f;
        if (2.7f <= this->m_200) {
            this->m_200 = (f32) 2.7f;
            *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = 3;
            break;
        }
        break;
    case 3:
        *(s32 *)((s8 *)((u8 *)this) + 0x1F8) = 1;
        temp_r31 = *(s32 *)((s8 *)this->owner + 0x60) - 0x4000;
        buffer_14[0] = sin_table_lookup(temp_r31);
        buffer_14[1] = 1.0f;
        buffer_14[2] = cos_table_lookup(temp_r31);
        buffer_8[0] = 0x4000;
        buffer_8[1] = *(s32 *)((s8 *)this->owner + 0x60);
        buffer_8[2] = 0;
        TObjPlayer::launch_weapon_casing((s32)tl_05, (u32) this, 2, (u32) &buffer_14[0], (u32) &buffer_8[0]);
        break;
    }
}
#pragma pop

void TUnk_804A6DC0::emit_marker_effects() {
    Obj_80131334 *self = (Obj_80131334 *)this;
    u8 buf[0x18];
    self->state = 2;
    ((TItemWeapon *)self)->get_gun_point(buf);
    spawn_particle_effect(buf, 9);
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

u8 *create_yasminkov_7000v(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A6DC0(tl_05, arg0);
    }
    return NULL;
}
