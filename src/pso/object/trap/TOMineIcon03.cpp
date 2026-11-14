#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineIcon03.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern s32 game_difficulty_selection;
extern void *tl_05;

const char *TOMineIcon03__name = "TOMineIcon03";

void TOMineIcon03::vfunc_84() {  }

void TOMineIcon03::vfunc_82() {
    s32 arg0 = (s32)this;
    spawn_particle_effect((void *)(arg0 + 0x2FC), 0x8D);
    spawn_particle_effect((void *)(arg0 + 0x2FC), 0x8D);
}

void *TOMineIcon03::create(void *arg0) {
    return new TOMineIcon03((TObject *)tl_05, arg0);
}

TOMineIcon03::~TOMineIcon03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

#pragma push
#pragma fp_contract on
TOMineIcon03::TOMineIcon03(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = TOMineIcon03__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(lbl_805D5A50, 6);
    texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 6);
    m_374 = get_bml_model(lbl_805D5A50, 2);
    m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 2);
    mode = 0;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    if (set_params[1] < 6) {
        set_params[1] = 6;
    } else if (set_params[1] > 8) {
        set_params[1] = 8;
    }
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    attack.power = (f32)set_params[0] * (2.0f * (f32)game_difficulty_selection + 1.0f);
    if (game_difficulty_selection == 3) {
        attack.power *= 2.0f;
    }
    attack.kind = set_params[1];
    pad_34C = 0.5f * scale.x + 30.0f;
    m_350 = 0.5f * scale.y + 60.0f;
    update_state();
    m_35c = 0xFFFF;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, mine_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
#pragma pop
