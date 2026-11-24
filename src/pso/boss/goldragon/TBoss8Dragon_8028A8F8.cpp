#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_80066F10.h"
#include "pso/unk/text_8028A820.h"
#include "pso/boss/goldragon/TBoss8Dragon_8028A8F8.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {

NJS_TEXLIST *get_green_door_textures() {
    return green_door_texture_handle;
}
void TBoss8Dragon__sub_8028A900(TObject *floor_grass, const Vec *pos, const DragonAttackParams *params) {
    NJS_OBJECT *root = boss5_common_bml_resource->models[7].model;
    f32 range_squared = TBoss8Dragon::calc_sq_offset(params, 15.0f);
    for (NJS_OBJECT *node = root->child; node != NULL; node = node->sibling) {
        if (!(node->evalflags & NJD_EVAL_BREAK) && TBoss8Dragon::is_within_xz_distance(pos, node, range_squared) != 0) {
            node->evalflags |= NJD_EVAL_BREAK;
        }
    }
}

}
