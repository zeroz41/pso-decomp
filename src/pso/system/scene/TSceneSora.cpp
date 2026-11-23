#include "pso/system/Adxf.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/ResourceFile.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "types.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80140FF4.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_80011014.h"


struct Ent_80207478 { s32 f0; char *name; };


#pragma readonly_strings on

s32 TSceneSora::sky_active_flag = 1;
const char *TSceneSora__name = "TSceneSora";
TSceneSora *TSceneSora::instance;
BmlResource *TSceneSora__sky_bml_resource;
s32 TSceneSora__has_sky_motion;

extern "C" {
void TSceneSora__sub_80207430(void);
s32 rotate_matrix_y(int, int);
extern char sky_model_ext_s_njm[];
extern char sky_model_ext_sm_gj[];
extern char sky_model_ext_s_gj[];
void TLobby__sub_802075F4(void);


void TSceneSora::render() {
    if ((s32) TSceneSora::sky_active_flag != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(get_bml_texlist((BmlResource *)TSceneSora__sky_bml_resource, 0));
        push_matrix();
        rotate_matrix_y(0, this->rotation_y);
        if (sky_motion != NULL) {
            draw_ginja_model_with_motion(sky_model, sky_motion, m_a0);
        } else {
            draw_ginja_object(sky_model);
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TSceneSora::run_task() {
    if (sky_motion != NULL) {
        m_a0 += motion_step;
        if (m_a0 > (sky_motion->frameCount - 1)) {
            m_a0 = 0.0f;
        }
    } else {
        switch (get_current_floor_area()) {
        case AREA_FOREST1:
        case AREA_FOREST2:
            rotation_y++;
            break;
        }
    }
}

}
TSceneSora::~TSceneSora() {
    TSceneSora::instance = 0;
}
TSceneSora::TSceneSora(TObject *parent) : TObjBase(parent) {
    m_name = TSceneSora__name;
    sky_model = reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TSceneSora__sky_bml_resource, 0));
    if (TSceneSora__has_sky_motion != 0) {
        sky_motion = get_bml_motion(TSceneSora__sky_bml_resource, 0);
    } else {
        sky_motion = NULL;
    }
    sky_textures = reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist((BmlResource *)TSceneSora__sky_bml_resource, 0));
    motion_step = 0.1f;
    m_a0 = 0.0f;
}
extern "C" {

void TSceneSora::create_instance() {
    if (TSceneSora__sky_bml_resource != NULL) {
        TSceneSora::instance = new TSceneSora(tl_05);
        return;
    }
    TSceneSora::instance = 0;
}

void TSceneSora__sub_80207430(void) {
    TSceneSora::sky_active_flag = 1;
    if (TSceneSora__sky_bml_resource != NULL) {
        delete (BmlResource *)TSceneSora__sky_bml_resource;
        TSceneSora__sky_bml_resource = NULL;
    }
    TSceneSora::instance = 0;
}

void TSceneSora::load_sky_resources() {
    char name2[0x20];
    char name1[0x20];
    FloorMapSelection ref;
    const char *models[2];
    const char *motions[2];
    Ent_80207478 *tbl;
    s32 ok;
    AdxfHandle *p;
    BmlResource *o;
    TSceneSora::instance = 0;
    TSceneSora__sky_bml_resource = NULL;
    TSceneSora__has_sky_motion = 0;
    if (lookup_floor_map_selection(get_current_floor(), &ref) != 0) {
        ok = 0;
        tbl = (Ent_80207478 *)get_floor_scene_table(ref.area);
        replace_file_extension__6TLobbyFPvPvPv(name1, tbl[ref.terrain].name, sky_model_ext_s_njm);
        if (TRaderMapCore::is_not_split_screen() == 1) {
            replace_file_extension__6TLobbyFPvPvPv(name2, tbl[ref.terrain].name, sky_model_ext_sm_gj);
            ok = get_resource_file_size((const char *)name2);
        }
        if (ok <= 0) {
            replace_file_extension__6TLobbyFPvPvPv(name2, tbl[ref.terrain].name, sky_model_ext_s_gj);
        }
        p = ADXF_Open(name2, 0);
        if (p != NULL) {
            models[0] = name2;
            ADXF_Close(p);
        } else {
            return;
        }
        p = ADXF_Open(name1, 0);
        if (p != NULL) {
            motions[0] = name1;
            TSceneSora__has_sky_motion = 1;
            ADXF_Close(p);
        } else {
            motions[0] = NULL;
        }
        models[1] = NULL;
        motions[1] = NULL;
        o = static_cast<BmlResource *>(::operator new(sizeof(BmlResource)));
        if (o != 0) {
            o = init_bin_model_request(o, 1, models, motions, NULL, NULL, NULL);
        }
        TSceneSora__sky_bml_resource = o;
        TSceneSora::sky_active_flag = 1;
    }
}

void TLobby__sub_802075F4(void) {  }
}
extern s32 pending_adventure_map_floor;
void prepare_adventure_maps(void);
void prepare_adventure_maps(void) {
    randomize_adventure_maps();
    if ((s32) pending_adventure_map_floor != -1) {
        initialize_floor_transition(&floor_transition_state, pending_adventure_map_floor, get_floor_map_terrain(pending_adventure_map_floor));
        pending_adventure_map_floor = -1;
    }
}
