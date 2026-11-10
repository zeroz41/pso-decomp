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
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/map/FloorArea.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
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
    if (texture_list != 0) {
        release_texture_list((GinjaTextureList *)texture_list);
        TAdSinglePlyChrSelectGC::safe_free(texture_list);
        texture_list = 0;
    }
    if (bml_resource != NULL) {
        free_bin_model_request(bml_resource, 1);
        bml_resource = NULL;
    }
}

void TObjSeabedSuisoBrakable::load_resources() {
    s32 i;
    void *p;
    NJS_OBJECT *model;

    switch (get_current_floor_area()) {
    case AREA_SEABED_LOWER: {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, &bm_obj_seabed_suiso_2_resource_descriptor, 0, 0, 0);
        }
        bml_resource = (BmlResource *)p;
        if ((texture_list = (u32)load_gvm_texture_file((s32)"obj_seabed_suiso_2.GVM")) != 0) {
            SeabedSuisoTextureNames names = seabed_suiso_2_texture_names;
            for (i = 0; i < 5; i++) {
                texture_entries[i] = ((TObjDoorJung *)texture_list)->find_entry_by_name(names.name[i]);
            }
        }
        break;
    }
    case AREA_SEABED_UPPER:
    default: {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, &bm_obj_seabed_suiso_resource_descriptor, 0, 0, 0);
        }
        bml_resource = (BmlResource *)p;
        if ((texture_list = (u32)load_gvm_texture_file((s32)"obj_seabed_suiso.GVM")) != 0) {
            SeabedSuisoTextureNames names = seabed_suiso_texture_names;
            for (i = 0; i < 5; i++) {
                texture_entries[i] = ((TObjDoorJung *)texture_list)->find_entry_by_name(names.name[i]);
            }
        }
        break;
    }
    }
    if ((model = (NJS_OBJECT *)get_bml_model(bml_resource, 12)) != NULL) {
        model12_nodes[0] = find_object_node(model, 1);
        model12_nodes[1] = find_object_node(model, 2);
        model12_nodes[2] = find_object_node(model, 4);
    }
    if ((p = (void *)get_bml_model(bml_resource, 13)) != NULL) {
        model13_nodes[0] = find_object_node((NJS_OBJECT *)p, 1);
        model13_nodes[1] = find_object_node((NJS_OBJECT *)p, 2);
        model13_nodes[2] = find_object_node((NJS_OBJECT *)p, 3);
        for (i = 0; i < 3; i++) {
            if (model13_nodes[i] != NULL) {
                model13_nodes[i]->evalflags |= 0x100000;
            }
        }
    }
}

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
