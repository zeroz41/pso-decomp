#include "types.h"
#include "pso/player/TObjPlayer_80128728.h"
#include "pso/item/TUnk_804A3E20.h"
#include "pso/item/TItemEquipVariant_801287A4.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {

int scale_current_matrix(void*);
int get_player_list__10TObjPlayerFv(void*);
}

void s_rank_harisen_scale_node(void* p) { if (get_player_list__10TObjPlayerFv(p) == 1) { scale_current_matrix((char*)p + 0x1fc); } }

void s_rank_harisen_reset_fan(void* a0) { *(float*)((char*)a0 + 0x200) = 0.1f; }

void TUnk_804A3E20::update_weapon() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x200);
    if (temp_f2 < 1.0f) {
        *(f32 *)((s8 *)arg0 + 0x200) += 0.1f;
        if (1.0f <= *(f32 *)((s8 *)arg0 + 0x200)) {
            *(f32 *)((s8 *)arg0 + 0x200) = (f32) 1.0f;
        }
    }
}

extern s32 lbl_804A3E20[];

void *__dt__13TUnk_804A3E20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3E20;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int construct_srank_weapon(void);

void*TUnk_804A3E20::init_shot_state() { construct_srank_weapon(); *(int*)((char*)this + 0x18) = (int)lbl_804A3E20; *(float *)&(*(s32 *)((u8 *)this + 0x204)) = 1.0f; *(float*)((char*)this + 0x200) = 1.0f; *(float *)&(*(s32 *)((u8 *)this + 0x1FC)) = 1.0f; return this; }

}
