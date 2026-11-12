#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineIcon01.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern s32 game_difficulty_selection;
extern void *tl_05;

const char *TOMineIcon01__name = "TOMineIcon01";

void TOMineIcon01::vfunc_84() {  }

void *TOMineIcon01::create() {
    return new TOMineIcon01((TObject *)tl_05, this);
}

TOMineIcon01::~TOMineIcon01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

#pragma push
#pragma fp_contract on
TOMineIcon01::TOMineIcon01(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = TOMineIcon01__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(lbl_805D5A50, 4);
    texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 4);
    m_374 = get_bml_model(lbl_805D5A50, 1);
    m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 1);
    mode = 0;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 5) {
        set_params[1] = 5;
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
