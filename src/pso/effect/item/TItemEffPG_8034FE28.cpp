#include "types.h"
#include "pso/effect/item/TItemEffPG_8034FF4C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/weapon/TItemAttackCol_802E4798.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/effect/item/TItemEffPG_8034FE28.h"
#include "pso/effect/item/TUnk_804F0C08.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D4350 = "TItemEffPG";
}

extern "C" {

void *__nw__7TObjectFUl(int);

extern s32 lbl_804F0C08[];

void *TUnk_804F0C08::initialize(void *arg1, void *parent, void *item) {
    TItemEffPG__ct((u8 *)this, (s32)arg1, (u8 *)parent);
    *(s32 **)((s8 *)this + 0x18) = lbl_804F0C08;
    *(void * *)&this->unk_D4 = item;
    return this;
}

void create__10TItemEffPGFPvPvPv(void *arg0, void *parent, void *item) {
    void *o;
    o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        ((TUnk_804F0C08 *)o)->initialize(arg0, parent, item);
    }
}

}

s32 TItemEffPG::vfunc_7() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    if (player->get_photon_blast_charge() < required_charge) {
        return 0;
    }
    player->vfunc_76(required_charge);
    return 1;
}


struct RecoveredGlobal_8035007C___vt__10TItemEffPG { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_8035007C___vt__10TItemEffPG_size[sizeof(RecoveredGlobal_8035007C___vt__10TItemEffPG) == 0x20 ? 1 : -1];

extern "C" {
void *__nw__7TObjectFUl(int);
extern s32 __vt__10TItemEffPG[];
extern const char *lbl_805D4350;
extern const float lbl_805DFE14;
extern const f32 lbl_805DFE18;
int TObjPlayer__sub_802E451C(void);
void __dl__7TObjectFPv(void *);
s32 has_game_join_id__13TUnk_804E355CFv();

void TItemEffPG::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_r31;

    var_r31 = 1;
    if (has_game_join_id__13TUnk_804E355CFv() == 0) {
        var_r31 = 0;
    }
    if (this->vfunc_7() == 0) {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        temp_f1 = this->m_40;
        if (temp_f1 < *(f32 *)&this->unk_C4) {
            this->m_40 = (f32) (temp_f1 + this->m_c8);
            temp_f1_2 = *(f32 *)&this->unk_C4;
            if (temp_f1_2 < this->m_40) {
                this->m_40 = temp_f1_2;
            }
        }
        check_hits();
        return;
    }
    if ((u32) this->m_down == 0U) {
        queue_destruction__7TObjectFv(this);
        disallow_rendering__7TObjectFv(this);
        return;
    }
    if ((u32) this->m_d0 != 0U) {
        TItemEffPG__begin_visual_fade(*(void * *)&this->m_d0);
        this->m_d0 = 0U;
    }
}

void *__dt__10TItemEffPGFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TItemEffPG;
        ((TUnk_804E355C *)arg0)->destroy_attack_collision(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TItemEffPG__ct(u8 *item_eff_pg, s32 arg1, u8 *arg2) {
    s32 temp_r3;
    s32 var_r0;
    construct_attack_collision((item_eff_pg), (arg1), (arg2));
    *(s32 **)((s8 *)item_eff_pg + 0x18) = &(*(RecoveredGlobal_8035007C___vt__10TItemEffPG *)&__vt__10TItemEffPG).value;
    *(s32 *)((s8 *)item_eff_pg + 0) = (s32) ((s32)lbl_805D4350);
    *(f32 *)((s8 *)item_eff_pg + 0xC4) = (f32) *(f32 *)((s8 *)arg2 + 0x28);
    if ((*(const f32 *)&lbl_805DFE14) < *(f32 *)((s8 *)item_eff_pg + 0xC4)) {
        *(f32 *)((s8 *)item_eff_pg + 0xC4) = (f32) (*(const f32 *)&lbl_805DFE14);
    }
    ((TItemEffPG *)item_eff_pg)->m_c8 = (f32) *(f32 *)((s8 *)arg2 + 0x30);
    *(f32 *)((s8 *)item_eff_pg + 0xCC) = (f32) *(f32 *)((s8 *)arg2 + 0x2C);
    *(f32 *)((s8 *)item_eff_pg + 0xB0) = (f32) (*(f32 *)((s8 *)item_eff_pg + 0xB0) * lbl_805DFE18);
    temp_r3 = ((s32)__nw__7TObjectFUl(0x68));
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (s32)TItemEffPG__visual_ct((u8 *)temp_r3, (u8 *)item_eff_pg, (u8 *)arg2);
    }
    ((TItemEffPG *)item_eff_pg)->m_d0 = var_r0;
    return item_eff_pg;
}

void TItemEffPG::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        TItemEffPG__ct((u8 *)o, (s32)arg0, (u8 *)arg1);
    }
}

    extern const float lbl_805DFE1C;
    extern const float lbl_805DFE20;
void*TItemEffPG::init_params() { TObjPlayer__sub_802E451C(); *(int *)&this->m_up = 10; this->m_28 = lbl_805DFE14; *(float *)&this->unk_2C = lbl_805DFE1C; this->m_30 = lbl_805DFE20; return this; }

}
