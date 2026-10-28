#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer_8012A224.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TUnk_804A4848.h"

extern "C" {

int rotate_matrix_x(void*, void*);
int get_player_list__10TObjPlayerFv(void*);
}

void s_rank_windmill_turn_blade(void* p) { if (get_player_list__10TObjPlayerFv(p) == 3) { rotate_matrix_x((void*)0, *(void**)((char*)p + 0x1fc)); } }

void TUnk_804A4848::reserved_53() {
    s32 *temp_r31;

    if ((u32) *(u32 *)((s8 *)this + 0xF0) != 0U) {
        temp_r31 = *(s32 **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this + 0xF4)) + 0x2C)) + 0x30)) + 0x30);
        if ((s32) *(s32 *)((s8 *)this + 0x208) == 0) {
            *temp_r31 |= 0x10;
        }
        draw_weapon_model();
        ((TItemWeapon *)this)->update_trail_slot(0);
        if ((s32) *(s32 *)((s8 *)this + 0x208) == 0) {
            *temp_r31 &= 0xFFFFFFEF;
        }
    }
}

void TUnk_804A4848::update_idle() {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)this + 0x200);
    if (temp_r4 > 0xCCC) {
        *(s32 *)((s8 *)this + 0x200) = (temp_r4 - 0xB6);
    }
}

void TUnk_804A4848::update_attack() {
    s32 temp_r4;

    *(s32 *)((s8 *)this + 0x204) = (s32) (*(s32 *)((s8 *)this + 0x204) + 1);
    if (!(*(s32 *)((s8 *)this + 0x204) & 3)) {
        temp_r4 = *(s32 *)((s8 *)this + 0x200);
        if (temp_r4 < 0x3333) {
            *(s32 *)((s8 *)this + 0x200) = (temp_r4 + 0xB6);
        }
    }
}

void TUnk_804A4848::update_weapon() {
    u8 *arg0 = (u8 *)this;
    advance_angle_wrap((s32 *)(arg0 + 0x1FC), *(s32 *)((s8 *)arg0 + 0x200));
}
