#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaTexture.h"
// The seabed tanks' shared resources: the archive and texture loader, the
// scrolled-texture and model-node tables TObjSeabedSuiso_CH and
// TObjSeabedSuisoBrakable read.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/seabed/TObjSuisoChip.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/object/seabed/TObjSeabedSuiso_CH.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/map/FloorArea.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/vector.h"
#include "pso/render/NinjaUtil.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"

s32 TObjSeabedSuisoBrakable::texture_entries[5];
NJS_OBJECT *TObjSeabedSuisoBrakable::model12_nodes[3];
NJS_OBJECT *TObjSeabedSuisoBrakable::model13_nodes[3];

void TObjSeabedSuisoBrakable::free_static_resources() {
    if (texture_list != NULL) {
        release_texture_list(texture_list);
        safe_free(texture_list);
        texture_list = NULL;
    }
    if (bml_resource != NULL) {
        delete (BmlResource *)bml_resource;
        bml_resource = NULL;
    }
}

#pragma push
#pragma opt_propagation off
void TObjSeabedSuisoBrakable::load_resources() {
    s32 i;
    void *loaded;
    NJS_OBJECT *model;

    switch (get_current_floor_area()) {
    case AREA_SEABED_LOWER: {
        loaded = new BmlResource(1, (BmlResourceDescriptor *)&bm_obj_seabed_suiso_2_resource_descriptor, 0, 0, NULL);
        bml_resource = static_cast<BmlResource *>(loaded);
        if ((texture_list = load_gvm_texture_file("obj_seabed_suiso_2.GVM")) != NULL) {
            SeabedSuisoTextureNames names = seabed_suiso_2_texture_names;
            for (i = 0; i < 5; i++) {
                texture_entries[i] = find_texture_entry_by_name(texture_list, names.name[i]);
            }
        }
        break;
    }
    case AREA_SEABED_UPPER:
    default: {
        loaded = new BmlResource(1, (BmlResourceDescriptor *)&bm_obj_seabed_suiso_resource_descriptor, 0, 0, NULL);
        bml_resource = static_cast<BmlResource *>(loaded);
        if ((texture_list = load_gvm_texture_file("obj_seabed_suiso.GVM")) != NULL) {
            SeabedSuisoTextureNames names = seabed_suiso_texture_names;
            for (i = 0; i < 5; i++) {
                texture_entries[i] = find_texture_entry_by_name(texture_list, names.name[i]);
            }
        }
        break;
    }
    }
    if ((model = (NJS_OBJECT *)get_bml_model((BmlResource *)bml_resource, 12)) != NULL) {
        model12_nodes[0] = find_object_node(model, 1);
        model12_nodes[1] = find_object_node(model, 2);
        model12_nodes[2] = find_object_node(model, 4);
    }
    if ((loaded = (NJS_OBJECT *)get_bml_model((BmlResource *)bml_resource, 13)) != NULL) {
        model13_nodes[0] = find_object_node(static_cast<NJS_OBJECT *>(loaded), 1);
        model13_nodes[1] = find_object_node(static_cast<NJS_OBJECT *>(loaded), 2);
        model13_nodes[2] = find_object_node(static_cast<NJS_OBJECT *>(loaded), 3);
        for (i = 0; i < 3; i++) {
            if (model13_nodes[i] != NULL) {
                model13_nodes[i]->evalflags |= 0x100000;
            }
        }
    }
}
#pragma pop

s32 TObjSeabedSuisoBrakable::get_texture_entry(int index) {
    return texture_entries[index];
}

NJS_OBJECT *TObjSeabedSuisoBrakable::get_model12_node(int index) {
    return model12_nodes[index];
}

NJS_OBJECT *TObjSeabedSuisoBrakable::get_model13_node(int index) {
    return model13_nodes[index];
}

void TObjSeabedSuisoBrakable::vfunc_19() {}

extern "C" {
int match_coordinate_pair(u8 *pair, s32 a, s32 b) {
    u8 match = 0;
    if (a == ((s32 *)pair)[0] && b == ((s32 *)pair)[1]) {
        match = 1;
    }
    return match;
}
u8 is_valid_player_motion_variant(u32 variant) {
    return variant < 19;
}

u8 TLobby__sub_802A7278(u32 arg0) {
    return arg0 < 6;
}

}
