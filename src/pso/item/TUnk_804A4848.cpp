#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer_8012A224.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TUnk_804A4848.h"
#include "pso/item/TItemEquipVariant_8012A35C.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012A3B4.h"
#include "pso/unk/TUnk_804A4948.h"

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

extern s32 s_rank_windmill_weapon_vtable[];

void *__dt__13TUnk_804A4848Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = s_rank_windmill_weapon_vtable;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void construct_srank_weapon(void *);

extern s32 s_rank_windmill_weapon_vtable[];

void *TObjPlayer__sub_8012A3B4(void *player, s32 parent, s32 item) {
    construct_srank_weapon(player);
    *(s32 **)((s8 *)player + 0x18) = s_rank_windmill_weapon_vtable;
    ((TItemWeapon *)player)->set_weapon_flags(35);
    *(u32 *)((s8 *)player + 0x1FC) = 0;
    *(u32 *)((s8 *)player + 0x200) = 3276;
    *(u32 *)((s8 *)player + 0x204) = 0;
    *(u32 *)((s8 *)player + 0x208) = 1;
    return player;
}

}

struct VBase_18_24931d
{
  char pad[0x18];
};


extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;

u8 *TObjPlayer::create_state_8012a418(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x218));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_8012A3B4(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}


}
typedef struct VBase_18_24931d VBase_18_24931d;

