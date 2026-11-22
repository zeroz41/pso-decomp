#include "types.h"
#include "pso/player/TObjPlayer_80126460.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/TUnk_804A2A58.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80126740.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
u32 spawn_shoot_particle__10TObjPlayerFUlllf(void *, s32, s32, f32);

int rotate_matrix_y(void*, void*);
}

u32 baranz_launcher_create_shot(void *player, s32 arg1, s32 arg2, f32 farg0) {
    uaddr temp_r31;
    uaddr temp_r30;
    void *temp_r4;

    temp_r31 = TObjPlayer::create_shoot_model((uaddr)player, arg1, arg2, farg0);
    temp_r30 = spawn_shoot_particle__10TObjPlayerFUlllf(player, arg1, arg2, farg0);
    if ((temp_r31 != 0U) && (temp_r30 != 0U)) {
        temp_r4 = *(void **)((s8 *)player + 0x188);
        if (temp_r4 != NULL) {
            *(s32 *)((s8 *)temp_r4 + 0) = (s32) (*(s32 *)((s8 *)temp_r4 + 0) & 0xFFFFFFFD);
            *(s32 *)((s8 *)temp_r4 + 0x14) = 0x4000;
        }
        ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0x1BB, 0);
        ((TObject *)temp_r30)->set_parent((TObject *)temp_r31);
    }
    return temp_r31;
}

// Baranz Launcher (inferred)
void TUnk_804A2A58::vfunc_60() { if (TObjPlayer::get_player_list() == 1) { rotate_matrix_y((void*)0, *(void **)&rotation_y); } }


void TUnk_804A2A58::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 temp_r4;
    temp_r4 = spin_speed;
    spin_speed = (temp_r4 + 0x2AAA);
    if (((TItem *)(arg0))->is_model_shown() != 0) {
        ((TItemWeapon *)arg0)->get_joint_position(2, &sp8);
        this->launch_shot((u8 *)&sp8, 0, 0x4FA, 1);
        ((TItemWeapon *)arg0)->get_joint_position(3, &sp8);
        this->launch_shot((u8 *)&sp8, 1, 0xE38, 1);
        ((TItemWeapon *)arg0)->get_joint_position(4, &sp8);
        this->launch_shot((u8 *)&sp8, 2, -0x4FA, 1);
        ((TItemWeapon *)arg0)->get_joint_position(5, &sp8);
        this->launch_shot((u8 *)&sp8, 3, -0xE38, 1);
    }
}


void TUnk_804A2A58::update_weapon() {
    s32 temp_r4;

    temp_r4 = spin_speed;
    if (temp_r4 > 0) {
        spin_speed = (temp_r4 - 0x888);
        rotation_y -= 0x888;
    }
}

TUnk_804A2A58::~TUnk_804A2A58() {

}


TUnk_804A2A58::TUnk_804A2A58(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    shot_callback = (WeaponShotCallback)baranz_launcher_create_shot;
    spin_speed = 0;
    rotation_y = 0;
    shot_speed = 7.0f;
}

// ---- pso/unk/text_80126740


TItem *create_baranz_launcher(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2A58(tl_05, item);
    }
    return NULL;
}

