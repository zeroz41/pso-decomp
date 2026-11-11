#include "types.h"
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
const char *TItemEffPG__name = "TItemEffPG";
}

extern "C" {

TUnk_804F0C08::TUnk_804F0C08(TObject *parent, S_8035016C *params, s32 count) : TItemEffPG(parent, params) {
    pad_D4 = count;
}

void create__10TItemEffPGFPvPvPv(void *parent, void *params, void *count) {
    new TUnk_804F0C08((TObject *)parent, (S_8035016C *)params, (s32)count);
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


extern "C" {
extern const char *TItemEffPG__name;
extern const float lbl_805DFE14;
extern const f32 lbl_805DFE18;
void __dl__7TObjectFPv(void *);

void TItemEffPG::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_r31;

    var_r31 = 1;
    if (has_game_join_id() == 0) {
        var_r31 = 0;
    }
    if (this->vfunc_7() == 0) {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        temp_f1 = this->body.radius;
        if (temp_f1 < this->pad_C4) {
            this->body.radius = (f32) (temp_f1 + this->m_c8);
            temp_f1_2 = this->pad_C4;
            if (temp_f1_2 < this->body.radius) {
                this->body.radius = temp_f1_2;
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

TItemEffPG::~TItemEffPG() {}

TItemEffPG::TItemEffPG(TObject *parent, S_8035016C *params) : TUnk_804E355C(parent, params) {
    void *visual;
    m_name = TItemEffPG__name;
    pad_C4 = params->pad_28;
    if (lbl_805DFE14 < pad_C4) {
        pad_C4 = lbl_805DFE14;
    }
    m_c8 = params->pad_30;
    required_charge = params->required_charge;
    pad_B0 = pad_B0 * lbl_805DFE18;
    visual = operator new(0x68);
    if (visual != NULL) {
        visual = TItemEffPG__visual_ct((u8 *)visual, (u8 *)this, (u8 *)params);
    }
    m_d0 = (u32)visual;
}

void TItemEffPG::create(void *arg0, void *arg1) {
    new TItemEffPG((TObject *)arg0, (S_8035016C *)arg1);
}

    extern const float lbl_805DFE1C;
    extern const float lbl_805DFE20;
S_8035016C *S_8035016C::init_params() {
    TObjPlayer__sub_802E451C(this);
    hits = 10;
    pad_28 = lbl_805DFE14;
    required_charge = lbl_805DFE1C;
    pad_30 = lbl_805DFE20;
    return this;
}

}
