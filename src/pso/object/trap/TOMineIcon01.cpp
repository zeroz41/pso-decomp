#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineIcon01.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/TLevelSelect.h"


const char *mine_icon01_name = "TOMineIcon01";

void TOMineIcon01::vfunc_84() {  }

void *TOMineIcon01::create(void *set_data) {
    return new TOMineIcon01(tl_05, set_data);
}

TOMineIcon01::~TOMineIcon01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

#pragma push
#pragma fp_contract on
TOMineIcon01::TOMineIcon01(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = mine_icon01_name;
    apply_object_set_data(set_data);
    init_position_vectors();
    calc_attach_pos();
    model = get_bml_model(mine_model_archive, 4);
    texlist = get_bml_texlist(mine_model_archive, 4);
    light_model = get_bml_model(mine_model_archive, 1);
    light_textures = get_bml_texlist(mine_model_archive, 1);
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
    detect_radius = 0.5f * scale.x + 30.0f;
    trigger_radius = 0.5f * scale.y + 60.0f;
    update_state();
    target_id = 0xFFFF;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, mine_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
#pragma pop
