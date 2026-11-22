#include "pso/boss/darkfalz/TBoss4ZakoTexture.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"

extern "C" {

extern s32 TBoss4ZakoDraw__rotation_phase;

void TBoss4DarkFalz::init_uro_link() {
    falz_zako_texture_list = get_bml_texlist(TBoss4Uro::get_instance_count(), 8);
    NJS_OBJECT *child = get_bml_model(TBoss4Uro::get_instance_count(), 8)->child;
    child->evalflags &= ~NJD_EVAL_UNIT_ANG;
    if (child->model != NULL) {
        falz_zako_chunk_model = child->model;
        TBoss4ZakoDraw__rotation_phase = 0;
        TBoss4DarkFalz::clear_uro_link_state();
    }
}

}
