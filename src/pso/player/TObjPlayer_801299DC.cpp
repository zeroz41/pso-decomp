#include "types.h"
#include "pso/player/TObjPlayer_801299DC.h"
#include "pso/player/TUnk_804A444C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int construct_srank_weapon(void);

void TUnk_804A444C::update_idle() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x200) < 0x2000) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x200), 0x2D8, 0x2000);
    }
}

void TUnk_804A444C::update_attack() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x200) > 0) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x200), -0x2000, 0);
    }
}

    extern unsigned char create_gun_shot[];
    extern unsigned char s_rank_shot_weapon_vtable[];
    extern const float lbl_805DAE40;
void* init_s_rank_shot(void* a0) { construct_srank_weapon(); *(int*)((char*)a0 + 0x18) = (int)s_rank_shot_weapon_vtable; *(int*)((char*)a0 + 0x200) = 8192; ((TItemWeapon *)a0)->set_weapon_flags(2); *(int*)((char*)a0 + 0x1f0) = (int)create_gun_shot; *(float*)((char*)a0 + 0x1e4) = lbl_805DAE40; return a0; }

}
