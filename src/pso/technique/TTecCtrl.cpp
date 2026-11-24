#include "pso/system/memory.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/technique/TTecCircle.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/TActorLight.h"
#include "pso/player/TObjPlayer_8022C6C4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecGrants.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecMegid.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TTecRaZonde.h"
#include "pso/technique/TTecReverser.h"
#include "pso/technique/TTecSifta.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecDeband.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/technique/TTecResta.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/TUnk_804CC794.h"
#include "pso/object/TUnk_804CC948.h"
#include "pso/unk/TUnk_804CCD0C.h"
#include "pso/unk/TUnk_804CC990.h"
#include "pso/object/TUnk_804CCAC8.h"
#include "pso/object/TUnk_804CC74C.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/render/GinjaTexture.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/technique/TechniqueRingwaveList.h"

TechniqueParams calculated_technique_params;
// Per player: the technique boosts of the equipped weapon and shield.
TechniqueBoostTable technique_boost_tables[4];
TechniqueBoostTable lbl_8051607C[4];

extern "C" {
}

struct Target_8022D27C { u16 id; s16 part; };


extern "C" {
void *TObjPlayer__sub_80116620(void *, int);
s32 get_obj_id__10TObjPlayerFv(void *);
void set_slot_type_state__10TObjPlayerFllls(void *, int, u16, s32);
s32 is_split_screen();
void get_hand_joint_position__10TObjPlayerFl(void *, void *);
u8 get_cast_technique_level(void *, int);
}
extern u8 identity_matrix[];
extern s32 local_client_id;

// The technique effects' models and motions, and the archive that holds them.
const char *bm_technic_model_names[13] = {
    "eff_f_bartaturara.gj",
    "eff_f_gibarta_01.gj",
    "eff_f_gibartalv1.gj",
    "eff_f_gibartalv4.gj",
    "eff_f_gibartalv6.gj",
    "eff_f_ice_piece.gj",
    "eff_f_rabarta.gj",
    "eff_f_rabarta_02.gj",
    "eff_f_rabarta_03.gj",
    "eff_f_rafoie_shushku.gj",
    "eff_f_ringwave.gj",
    "eff_rafoie.gj",
    NULL
};
const char *bm_technic_motion_names[6] = {
    "eff_f_bartaturara.njm",
    "eff_f_gibarta_01.njm",
    "eff_f_rabarta.njm",
    "eff_f_rabarta_02.njm",
    "eff_f_rabarta_03.njm",
    NULL
};
BmlResourceDescriptor technique_resource_descriptor = {
    "bm_technic.bml", bm_technic_model_names, bm_technic_motion_names, 12, 5
};
// Per technique id (0-18): the base parameters calc_technique_parameters scales by level.
TechniqueParams technique_param_table[19] = {
    {110.0f, 3.0f, 100.0f, 0.0f, 5, 5, 40, 1, 5461, 7281, 15, 1, 130, 50, 10, 20, 30},
    {260.0f, 8.0f, 50.0f, 0.0f, 20, 7, 100, 1, 65536, 0, 20, 10, 70, 26, 5, 25, 0},
    {350.0f, 0.0f, 100.0f, 10.0f, 30, 13, 133, 1, 7281, 0, 25, 10, 25, 22, 10, 28, 40},
    {50.0f, 3.0f, 90.0f, 0.0f, 4, 5, 35, 2, 9102, 0, 15, 1, 120, 50, 30, 25, 50},
    {230.0f, 0.0f, 100.0f, 0.0f, 25, 7, 100, 2, 20024, 0, 40, 10, 50, 24, 10, 24, 120},
    {400.0f, 0.0f, 40.0f, 0.0f, 35, 13, 106, 2, 65536, 0, 25, 10, 20, 19, 2, 30, 0},
    {80.0f, 0.0f, 110.0f, 10.0f, 6, 5, 44, 3, 32768, 16384, 15, 1, 110, 50, 10, 24, 0},
    {200.0f, 0.0f, 80.0f, 0.0f, 25, 7, 100, 3, 16384, 16384, 20, 10, 60, 22, 20, 25, 0},
    {450.0f, 0.0f, 50.0f, 0.0f, 35, 13, 134, 3, 65536, 16384, 25, 10, 30, 16, 20, 30, 0},
    {1180.0f, 0.0f, 150.0f, 10.0f, 45, 15, 160, 3, 32768, 16384, 35, 1, 110, 75, 30, 30, 0},
    {0.0f, 0.0f, 60.0f, 0.0f, 10, 5, 60, 10, 32768, 16384, 30, 10, 100, 1, 25, 17, 0},
    {0.0f, 0.0f, 50.0f, 0.0f, 10, 5, 60, 11, 32768, 16384, 15, 10, 50, 1, 4, 28, 0},
    {0.0f, 0.0f, 50.0f, 0.0f, 10, 5, 60, 12, 32768, 16384, 15, 10, 50, 1, 4, 28, 0},
    {0.0f, 0.0f, 60.0f, 0.0f, 10, 5, 60, 9, 32768, 16384, 30, 10, 100, 1, 25, 28, 0},
    {0.0f, 0.0f, 10.0f, 0.0f, 10, 20, 150, 14, 0, 0, 20, 0, 50, 0, 0, 0, 0},
    {50.0f, 0.0f, 60.0f, 0.0f, 15, 7, 50, 6, 0, 0, 20, 10, 120, 5, 25, 30, 0},
    {0.0f, 0.0f, 60.0f, 0.0f, 10, 7, 85, 7, 0, 0, 20, 10, 50, 0, 25, 26, 0},
    {0.0f, 0.0f, 100.0f, 0.0f, 20, 10, 150, 8, 0, 0, 30, 1, 0, 0, 0, 0, 0},
    {27.0f, 2.0f, 100.0f, 0.0f, 30, 15, 160, 5, 7281, 7281, 35, 1, 105, 3, 20, 28, 10},
};
const char *TTecCtrl::class_name = "TTecCtrl";

TechniqueLinearPower tech_high_level_linear_power_table[19] = {
    {-85, 65}, {30, 42}, {370, 21}, {-125, 63}, {0, 40},
    {470, 15}, {5, 55}, {-30, 38}, {550, 9}, {1400, 60},
    {10, 1}, {10, 1}, {10, 1}, {10, 1}, {0, 0},
    {-20, 10}, {0, 0}, {0, 0}, {42, 2},
};
TechniqueCostScale technique_scale_table[19] = {
    {0.8f, 3.0f}, {0.8f, 2.0f}, {0.6f, 2.0f}, {0.8f, 3.0f}, {0.6f, 2.0f},
    {0.4f, 2.0f}, {0.5f, 4.0f}, {0.4f, 2.0f}, {0.4f, 2.0f}, {0.1f, 2.0f},
    {1.0f, 5.0f}, {1.0f, 5.0f}, {1.0f, 5.0f}, {1.0f, 5.0f}, {1.0f, 1.0f},
    {0.1f, 5.0f}, {1.0f, 10.0f}, {1.0f, 30.0f}, {0.3f, 5.0f},
};

void reset_telepipe_visit_counts(void);
s8 lbl_805D63A8;
BmlResource *technique_effect_bml;
NJS_TEXLIST *technique_texture_list;

#define ONE_SLOT()                                                                       \
    if (((TObjPlayer *)(TObjPlayer__sub_80116620(&c->target_records, 0)))->get_type_id() != 0xFFFF) { \
        set_slot_type_state__10TObjPlayerFllls(slots, 0,                                                \
            ((TObjPlayer *)(TObjPlayer__sub_80116620(&c->target_records, 0)))->get_type_id(),           \
            get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(&c->target_records, 0)));           \
        slots->set_tech_level(1);                                      \
    }

#define COLLECT_8022D27C()                                              \
    list.count = 0;                                                     \
    for (i = 0; i < n; i++) {                                           \
        if (targets == NULL || targets->entity_id == 0xFFFF) {                 \
            break;                                                      \
        }                                                               \
        list.records[i].id = targets->entity_id;                               \
        list.records[i].flag = targets->index;                           \
        targets++;                                                      \
    }                                                                   \
    list.count = n;
#define AIM_8022D27C()                                                  \
    if (targets->entity_id == 0xFFFF) {                                        \
        return;                                                         \
    }                                                                   \
    ent = find_entity_by_id(targets->entity_id);                               \
    if (ent == NULL) {                                                  \
        return;                                                         \
    }                                                                   \
    if (ent->bodies == NULL) {                                          \
        return;                                                         \
    }                                                                   \
    VecCopy(&aim, &ent->bodies[targets->index].center);

// This unit was built with deferred inlining, which emits functions in reverse
// order: they are defined here from the last address to the first.

void load_technique_resources(void) {
    technique_effect_bml = new BmlResource(1, &technique_resource_descriptor, 0, 0, NULL);
    technique_texture_list = load_gvm_texture_file("technic.gvm");
    bind_gvm_texture_list("technic_pt", &technique_ringwave_texture_list);
    TTecZondeEff::init_resources();
}

void TLobby__sub_8022F068(void) {
    clear_zonde_beam_vertex_pointer();
    if (technique_ringwave_texture_list.textures->texture != NULL) {
        release_texture_list(&technique_ringwave_texture_list);
    }
    if (technique_texture_list != NULL) {
        if (technique_texture_list->textures->texture != NULL) {
            release_texture_list(technique_texture_list);
        }
        safe_free(technique_texture_list);
        technique_texture_list = NULL;
    }
    if (technique_effect_bml != NULL) {
        delete technique_effect_bml;
    }
    technique_effect_bml = NULL;
}

TTecCtrl::TTecCtrl(TObject *parent) : TObject(parent) {
    m_name = class_name;
    pad_1C = 0;
}

TTecCtrl::~TTecCtrl() {}

void TTecCtrl::run_task() {
    lbl_805D63A8 = 0;
    reset_telepipe_visit_counts();
}

TechniqueParams *get_technique_base_params(int kind) {  return &technique_param_table[kind]; }

s32 clamp_nonnegative_int(s32 x) {
    if (x <= 0) {
        x = 0;
    }
    return x;
}

// pad_12 lowered by one per level above 4, not below 0.
inline s32 lowered_pad_12(s32 level) {
    return clamp_nonnegative_int(calculated_technique_params.pad_12 - clamp_nonnegative_int(level - 4));
}

TechniqueParams *calc_technique_parameters(s32 technique, s32 level, u16 client) {
    s32 capped = 15;
    if (level < 15) {
        capped = level;
    }
    if (level < 0) {
        level = 0;
    }
    if (level > 29) {
        level = 29;
    }
    ((TechniqueParams *)&calculated_technique_params)->copy(&technique_param_table[technique]);
    if (technique != 17 && technique != 14) {
        calculated_technique_params.tp_cost += level * (calculated_technique_params.tp_cost_percent / 100.0f);
    }
    switch (technique) {
    case 0:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 10) * 5;
        calculated_technique_params.pad_18 = 182.04445f * (calculated_technique_params.pad_18 + calculated_technique_params.pad_2A * (level / 5));
        break;
    case 1:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 = 40;
        break;
    case 2:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        calculated_technique_params.pad_18 = 182.04445f * (calculated_technique_params.pad_18 + calculated_technique_params.pad_2A * (level / 5));
        break;
    case 3:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 10) * 5;
        calculated_technique_params.pad_18 = 182.04445f * (calculated_technique_params.pad_18 + calculated_technique_params.pad_2A * (level / 5));
        calculated_technique_params.pad_18 = 182.04445f * (calculated_technique_params.pad_18 + calculated_technique_params.pad_2A * (level / 5));
        break;
    case 4:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        calculated_technique_params.pad_18 = 182.04445f * (calculated_technique_params.pad_18 + calculated_technique_params.pad_2A * (level / 5));
        break;
    case 5:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        break;
    case 6:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 10) * 5;
        break;
    case 7:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        break;
    case 8:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        break;
    case 9:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        break;
    case 10:
        calculated_technique_params.pad_08 = calculated_technique_params.pad_08 * (1.0f + calc_technique_boost(10, client));
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        if (level <= 1) {
            calculated_technique_params.pad_22 = 0;
        }
        break;
    case 11:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 10) * 5;
        break;
    case 12:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 10) * 5;
        break;
    case 13:
        calculated_technique_params.pad_08 = calculated_technique_params.pad_08 * (1.0f + calc_technique_boost(13, client));
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        if (level <= 1) {
            calculated_technique_params.pad_22 = 0;
        }
        break;
    case 15:
        calculated_technique_params.pad_08 = calculated_technique_params.pad_08 * (1.0f + calc_technique_boost(15, client));
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        if (level <= 1) {
            calculated_technique_params.pad_22 = 0;
        }
        break;
    case 16:
        calculated_technique_params.pad_08 = calculated_technique_params.pad_08 * (1.0f + calc_technique_boost(16, client));
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        if (level < 1) {
            calculated_technique_params.pad_22 = 0;
        }
        break;
    case 18:
        calculated_technique_params.pad_08 += calculated_technique_params.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            calculated_technique_params.tp_cost = calculated_technique_params.tp_cost * technique_scale_table[technique].tp_cost;
        }
        calculated_technique_params.pad_12 = lowered_pad_12(level);
        calculated_technique_params.pad_14 += calculated_technique_params.pad_28 * level;
        calculated_technique_params.pad_20 -= (capped / 5) * 5;
        calculated_technique_params.pad_18 = 182.04445f * (calculated_technique_params.pad_18 + calculated_technique_params.pad_2A * (level / 5));
        break;
    }
    if (calculated_technique_params.pad_20 <= 0) {
        calculated_technique_params.pad_20 = 10;
    }
    if (calculated_technique_params.pad_12 <= 0) {
        calculated_technique_params.pad_12 = 0;
    }
    return &calculated_technique_params;
}

void TTecCtrl::render() {  }

void launch_technique(s32 tech, s32 level, TObjPlayer *pl) {
    Vec aim;
    Vec hand;
    Vec ofs;
    TargetCursorList list;
    void *td;
    s32 n;
    PhotonBlastTarget *targets;
    s32 i;
    TObjCollidable *ent;
    ofs.x = 0.0f;
    ofs.y = 0.0f;
    ofs.z = 100.0f;
    if (pl == NULL) {
        return;
    }
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_LOBBY) {
        switch (tech) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 18:
            return;
        }
    }
    td = &pl->technique_state;
    targets = pl->technique_state.get_technique_data();
    if (targets == NULL) {
        return;
    }
    n = reinterpret_cast<PlayerTechniqueState *>(td)->get_section_clamped();
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, pl->rotation_y);
    matrix_mult_vec(0, &ofs, &ofs);
    pop_matrices(1);
    ofs.x += pl->position.x;
    ofs.y += pl->position.y;
    ofs.z += pl->position.z;
    get_hand_joint_position__10TObjPlayerFl(pl, &hand);
    switch (tech) {
    case 0:
        if (n != 0) {
            AIM_8022D27C()
            TTecFoie::create_ex(pl, &hand, &aim, get_cast_technique_level(td, 0));
        } else {
            TTecFoie::create(pl, &hand, pl->rotation_y, get_cast_technique_level(td, 0));
        }
        break;
    case 1:
        TTecGiFoie::create(pl, &hand, get_cast_technique_level(td, 1));
        break;
    case 2:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TTecRaFoie::create_ex(pl, &hand, &list, get_cast_technique_level(td, 2));
        break;
    case 3:
        if (n != 0) {
            AIM_8022D27C()
            TTecBarta::create(pl, &pl->position, &aim, get_cast_technique_level(td, 3));
        } else {
            TTecBarta::create_ex(pl, &pl->position, pl->rotation_y, get_cast_technique_level(td, 3));
        }
        break;
    case 4:
        if (n != 0) {
            AIM_8022D27C()
            TTecGiBarta::create(pl, &hand, &aim, get_cast_technique_level(td, 4));
        } else {
            TTecGiBarta::create_ex(pl, &hand, pl->rotation_y, get_cast_technique_level(td, 4));
        }
        break;
    case 5:
        TTecRaBarta::create(pl, &hand, get_cast_technique_level(td, 5));
        break;
    case 6:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TObjPlayer::create_tec_zonde(pl, &hand, &list, get_cast_technique_level(td, 6));
        break;
    case 7:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TTecGiZonde::create(pl, &hand, &list, get_cast_technique_level(td, 7));
        break;
    case 8:
        TTecRaZonde::create(pl, &hand, get_cast_technique_level(td, 8));
        break;
    case 9:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TTecGrants::create(pl, &hand, &list, get_cast_technique_level(td, 9));
        break;
    case 10:
        COLLECT_8022D27C()
        TTecDeband::create((saddr)pl, (saddr)(&hand), (saddr)(&list), (s32)(get_cast_technique_level(td, 10)));
        break;
    case 11:
        COLLECT_8022D27C()
        TObjPlayer::create_tec_jelin(pl, &hand, &list, get_cast_technique_level(td, 11));
        break;
    case 12:
        COLLECT_8022D27C()
        TObjPlayer::create_tec_zarua(pl, &hand, &list, get_cast_technique_level(td, 12));
        break;
    case 13:
        COLLECT_8022D27C()
        TTecSifta::create_instance(pl, &hand, &list, get_cast_technique_level(td, 13));
        break;
    case 14:
        if (is_split_screen() != 0) {
            ((TTecLuker *)pl)->create(&hand, &ofs, 0);
        } else if (local_client_id == pl->get_entity_id()) {
            ((TTecLuker *)pl)->create(&hand, &ofs, 0);
        }
        break;
    case 15:
        COLLECT_8022D27C()
        TTecResta::create(pl, &hand, &list, get_cast_technique_level(td, 15));
        break;
    case 16:
        COLLECT_8022D27C()
        TTecAnti::create(pl, &hand, &list, get_cast_technique_level(td, 16));
        break;
    case 17:
        COLLECT_8022D27C()
        if (n == 0) {
            return;
        }
        TTecReverser::create(pl, &hand, &list, get_cast_technique_level(td, 17));
        break;
    case 18:
        if (n != 0) {
            AIM_8022D27C()
            TTecMegid::create((saddr)pl, (saddr)&hand, (saddr)&aim, (s32)(get_cast_technique_level(td, 18)));
        } else {
            TTecMegid::create_ex((saddr)pl, (saddr)&hand, pl->rotation_y, (s32)(get_cast_technique_level(td, 18)));
        }
        break;
    }
}

void capture_technique_targets(int kind, TObjPlayer *owner) {
    LockOnActionSlot *c;
    PlayerTechniqueState *slots;
    if (owner == NULL) {
        return;
    }
    if (owner->lock_on_cursor == NULL) {
        return;
    }
    slots = &owner->technique_state;
    if (slots == NULL) {
        return;
    }
    owner->technique_state.reset_slots();
    c = owner->lock_on_cursor->find_by_pos(3, kind);
    if (c == NULL) {
        return;
    }
    switch (kind) {
    case 0:
        ONE_SLOT();
        break;
    case 2:
        ONE_SLOT();
        break;
    case 3:
        ONE_SLOT();
        break;
    case 4:
        ONE_SLOT();
        break;
    case 6:
        ONE_SLOT();
        break;
    case 7: {
        int n = 0;
        int i;
        for (i = 0; i < ((TLockOnCursor *)(&c->target_records))->get_target(); i++) {
            if (((TObjPlayer *)(TObjPlayer__sub_80116620(&c->target_records, n)))->get_type_id() != 0xFFFF) {
                set_slot_type_state__10TObjPlayerFllls(slots, n,
                    ((TObjPlayer *)(TObjPlayer__sub_80116620(&c->target_records, n)))->get_type_id(),
                    get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(&c->target_records, n)));
                n++;
            }
        }
        slots->set_tech_level(n);
        break;
    }
    case 9:
        ONE_SLOT();
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
    case 16: {
        int i;
        int n = 0;
        for (i = 0; i < ((TLockOnCursor *)(&c->target_records))->get_target(); i++) {
            set_slot_type_state__10TObjPlayerFllls(slots, n,
                ((TObjPlayer *)(TObjPlayer__sub_80116620(&c->target_records, n)))->get_type_id(),
                get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(&c->target_records, n)));
            n++;
        }
        slots->set_tech_level(n);
        break;
    }
    case 17:
        ONE_SLOT();
        break;
    case 18:
        ONE_SLOT();
        break;
    }
}

// One technique's charge light: colour A, R, G, B, shining down; INIT builds its
// charge effect when the caster is played here.
#define CHARGE_LIGHT_8022C738(A, R, G, B, INIT)                                                  \
    {                                                                                            \
        NJS_ARGB c = {A, R, G, B};                                                               \
        Vec v = {0.0f, -1.0f, 0.0f};                                                             \
        new TActorLight(0.1f, 0.35f, scene_light_state.intensity, &c, &v, base,          \
                          (TObjBase *)owner, tl_07);                                             \
        if (TObjPlayer::is_locally_controlled(owner) != 0) {                                \
            new INIT((TObjPlayer *)owner, tl_07);                                                \
        }                                                                                        \
    }
void create_technique_charge_light(u32 kind, void *owner) {
    TechniqueParams *p = get_technique_base_params(kind);
    s32 base = p->pad_12 + p->pad_20 + 50;
    switch (kind) {
    case 1:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 0.5f, 0.0f, TUnk_804CC794)
        break;
    case 0:
    case 2:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 0.5f, 0.0f, TUnk_804CC794)
        break;
    case 3:
    case 4:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 1.0f, 1.0f, TUnk_804CC948)
        break;
    case 5:
        CHARGE_LIGHT_8022C738(1.0f, 0.3f, 0.7f, 1.0f, TUnk_804CC948)
        break;
    case 6:
    case 7:
    case 8:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 1.0f, 0.3f, TUnk_804CCD0C)
        break;
    case 9:
    case 15:
    case 16:
    case 17:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 1.0f, 1.0f, TUnk_804CC990)
        break;
    case 10:
    case 11:
    case 12:
    case 14:
        CHARGE_LIGHT_8022C738(1.0f, 0.3f, 0.9f, 1.0f, TUnk_804CCAC8)
        break;
    case 13:
        CHARGE_LIGHT_8022C738(1.0f, 0.9f, 0.3f, 1.0f, TUnk_804CCAC8)
        break;
    case 18:
        CHARGE_LIGHT_8022C738(1.0f, 0.6f, 0.2f, 0.7f, TUnk_804CC74C)
        break;
    }
}

s32 TObjPlayer::get_level_tier(s32 arg0) {

    switch (arg0 / 5) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        return 0;
    }
}

void set_technique_boost(TechniqueBoost *boost, u16 client, s32 index) {
    if (client < 4U) {
        technique_boost_tables[client].set(index, boost);
    }
}

f32 calc_technique_boost(s32 technique, u16 actor) {
    f32 sum;
    TObjPlayer *player;
    s32 i;

    sum = 0.0f;
    if (actor >= 4) {
        return sum;
    }
    for (i = 0; i < 6; i++) {
        if (technique == technique_boost_tables[actor].boosts[i].technique) {
            sum += technique_boost_tables[actor].boosts[i].amount;
        }
    }
    player = get_player_by_client_id(actor);
    if (player != NULL) {
        sum += player->get_battle_value(actor, technique);
    }
    return sum;
}

u32 get_technique_caster_flags(s32 technique, u16 actor) {
    u32 flags;
    TObjPlayer *player;
    s32 i;

    flags = 0;
    if (actor >= 4) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        player = get_player_by_client_id(actor);
        if (player != NULL) {
            flags += player->get_battle_value(actor, technique);
            switch (technique) {
            case 18:
                if (player->get_battle_value(actor, technique) == 1.0f) {
                    flags |= 1;
                }
                break;
            }
        }
        if (technique == technique_boost_tables[actor].boosts[i].technique) {
            flags |= technique_boost_tables[actor].boosts[i].flags;
        }
    }
    return flags;
}

s32 TTecCtrl::classify_distance_band(s32 technique, s32 level, u16 slot) {
    f32 temp_f1;

    calc_technique_parameters(technique, level, slot);
    if ((level == 0) || (level == 1)) {
        return 0;
    }
    temp_f1 = calc_technique_boost(technique, slot);
    if (temp_f1 < 1.0f) {
        return 1;
    }
    if (temp_f1 < 2.0f) {
        return 2;
    }
    return 3;
}

void TTecCircle::vfunc_9() {  }
void TTecCircle::vfunc_8(void *) {  }
void TTecCircle::vfunc_6(void *) {  }
