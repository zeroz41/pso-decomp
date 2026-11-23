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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
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
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"

TechniqueParams lbl_80515F90;
// Per player: the technique boosts of the equipped weapon and shield.
TechniqueBoostTable lbl_80515FBC[4];
TechniqueBoostTable lbl_8051607C[4];

extern "C" {
f32 get_battle_value__10TObjPlayerFlil(void *, s32, s16);
}

typedef struct Owner_8022CDE8 {
    u8 pad0[0x424];
    TLockOnCursor *f424;  // TObjPlayer::lock_on_cursor
    u8 slots[0x10];
} Owner_8022CDE8;

typedef struct Cursor_8022CDE8 {
    u8 pad0[0x9C];
    u8 list[0x10];
} Cursor_8022CDE8;


struct Target_8022D27C { u16 id; s16 part; };

struct Entry_8022D27C { u16 id; s16 part; f32 c; };

struct List_8022D27C { s32 count; Entry_8022D27C e[11]; };

struct Coll_8022D27C { u8 pad0[0x1C]; Vec pos; u8 pad28[0x2C - 0x28]; };

struct Ent_8022D27C { u8 pad0[0xA4]; Coll_8022D27C *colls; };

struct Player_8022D27C {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    saddr rotY;
    u8 pad64[0x428 - 0x64];
    u8 tech[1];
};



typedef struct Params_8022C738 { u8 pad0[0x12]; s16 f12; u8 pad14[0x20 - 0x14]; s16 f20; } Params_8022C738;

extern "C" {
void *TObjPlayer__sub_80116620(void *, int);
s32 get_obj_id__10TObjPlayerFv(void *);
void set_slot_type_state__10TObjPlayerFllss(void *, int, u16, s32);
void capture_technique_targets__10TObjPlayerFv(int kind, Owner_8022CDE8 *owner);
u16 get_entity_id(void *);
s32 is_split_screen();
Ent_8022D27C *find_entity_by_id(u16);
void get_hand_joint_position__10TObjPlayerFl(void *, void *);
Target_8022D27C *get_technique_data__10TObjPlayerFPv(void *);
u8 get_cast_technique_level(void *, int);
void launch_technique__10TObjPlayerFv(s32 tech, s32 unused, Player_8022D27C *pl);
void *__ct__13TUnk_804CC794Fll(void *, void *, TObject *);
void *__ct__13TUnk_804CC948Fll(void *, void *, TObject *);
void *__ct__13TUnk_804CCD0CFll(void *, void *, TObject *);
void *__ct__13TUnk_804CC990Fll(void *, void *, TObject *);
void *__ct__13TUnk_804CCAC8Fll(void *, void *, TObject *);
void *__ct__13TUnk_804CC74CFll(void *, void *, TObject *);
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
const char *TTecCtrl__name = "TTecCtrl";

TechniqueLinearPower tech_high_level_linear_power_table[19] = {
    {-85, 65}, {30, 42}, {370, 21}, {-125, 63}, {0, 40},
    {470, 15}, {5, 55}, {-30, 38}, {550, 9}, {1400, 60},
    {10, 1}, {10, 1}, {10, 1}, {10, 1}, {0, 0},
    {-20, 10}, {0, 0}, {0, 0}, {42, 2},
};
TechniqueCostScale lbl_804CC55C[19] = {
    {0.8f, 3.0f}, {0.8f, 2.0f}, {0.6f, 2.0f}, {0.8f, 3.0f}, {0.6f, 2.0f},
    {0.4f, 2.0f}, {0.5f, 4.0f}, {0.4f, 2.0f}, {0.4f, 2.0f}, {0.1f, 2.0f},
    {1.0f, 5.0f}, {1.0f, 5.0f}, {1.0f, 5.0f}, {1.0f, 5.0f}, {1.0f, 1.0f},
    {0.1f, 5.0f}, {1.0f, 10.0f}, {1.0f, 30.0f}, {0.3f, 5.0f},
};

extern "C" {
s32 release_texture_list(void *, s32);
struct TechniqueRingwaveTextureList { u8 * value; u8 remaining[0x8]; };
extern TechniqueRingwaveTextureList technique_ringwave_texture_list;
void bind_gvm_texture_list(const char *, void *);
void __ct__7TObjectFP7TObject(void *, void *);
}
u8 *load_gvm_texture_file(saddr arg0);
void reset_telepipe_visit_counts(void);
s8 lbl_805D63A8;
BmlResource *technique_effect_bml;
GinjaTextureList *lbl_805D63B0;
extern s32 __vt__8TTecCtrl[];

#define ONE_SLOT()                                                                       \
    if (((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, 0)))->get_type_id() != 0xFFFF) { \
        set_slot_type_state__10TObjPlayerFllss(slots, 0,                                                \
            ((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, 0)))->get_type_id(),           \
            get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(c->list, 0)));           \
        ((TObjPlayer *)slots)->set_tech_level(1);                                      \
    }

#define COLLECT_8022D27C()                                              \
    list.count = 0;                                                     \
    for (i = 0; i < n; i++) {                                           \
        if (targets == NULL || targets->id == 0xFFFF) {                 \
            break;                                                      \
        }                                                               \
        list.e[i].id = targets->id;                                     \
        list.e[i].part = targets->part;                                 \
        targets++;                                                      \
    }                                                                   \
    list.count = n;
#define AIM_8022D27C()                                                  \
    if (targets->id == 0xFFFF) {                                        \
        return;                                                         \
    }                                                                   \
    ent = find_entity_by_id(targets->id);                               \
    if (ent == NULL) {                                                  \
        return;                                                         \
    }                                                                   \
    if (ent->colls == NULL) {                                           \
        return;                                                         \
    }                                                                   \
    VecCopy((Vec *)(&aim), (const Vec *)(&ent->colls[targets->part].pos));

// This unit was built with deferred inlining, which emits functions in reverse
// order: they are defined here from the last address to the first.

void load_technique_resources(void) {
    technique_effect_bml = new BmlResource(1, &technique_resource_descriptor, 0, 0, NULL);
    lbl_805D63B0 = (GinjaTextureList *)load_gvm_texture_file((saddr)"technic.gvm");
    bind_gvm_texture_list("technic_pt", ((u8 *)&technique_ringwave_texture_list));
    TTecZondeEff::init_resources();
}

void TLobby__sub_8022F068(void) {
    GinjaTextureEntry *entries;
    clear_zonde_beam_vertex_pointer();
    if ((u32) *(u32 *)((s8 *)technique_ringwave_texture_list.value + 8) != 0U) {
        release_texture_list(&technique_ringwave_texture_list.value, (saddr) technique_ringwave_texture_list.value);
    }
    if (lbl_805D63B0 != NULL) {
        entries = lbl_805D63B0->entries;
        if (entries->texture != NULL) {
            release_texture_list(lbl_805D63B0, (saddr) entries);
        }
        TAdSinglePlyChrSelectGC::safe_free((uaddr) lbl_805D63B0);
        lbl_805D63B0 = NULL;
    }
    if (technique_effect_bml != NULL) {
        delete technique_effect_bml;
    }
    technique_effect_bml = NULL;
}

void *__ct__8TTecCtrlFv(void *tec_ctrl, void *parent) {
    __ct__7TObjectFP7TObject(tec_ctrl, parent);
    *(s32 **)((s8 *)tec_ctrl + 0x18) = __vt__8TTecCtrl;
    ((TTecCtrl *)tec_ctrl)->m_name = TTecCtrl__name;
    *(u32 *)((s8 *)tec_ctrl + 0x1C) = 0;
    return tec_ctrl;
}

TTecCtrl::~TTecCtrl() {}

void TTecCtrl::run_task() {
    lbl_805D63A8 = 0;
    reset_telepipe_visit_counts();
}

void* get_technique_base_params(int a0) {  return &technique_param_table[a0]; }

s32 clamp_nonnegative_int(s32 x) {
    if (x <= 0) {
        x = 0;
    }
    return x;
}

// pad_12 lowered by one per level above 4, not below 0.
inline s32 lowered_pad_12(s32 level) {
    return clamp_nonnegative_int(lbl_80515F90.pad_12 - clamp_nonnegative_int(level - 4));
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
    ((TechniqueParams *)&lbl_80515F90)->copy(&technique_param_table[technique]);
    if (technique != 17 && technique != 14) {
        lbl_80515F90.tp_cost += level * (lbl_80515F90.tp_cost_percent / 100.0f);
    }
    switch (technique) {
    case 0:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 10) * 5;
        lbl_80515F90.pad_18 = 182.04445f * (lbl_80515F90.pad_18 + lbl_80515F90.pad_2A * (level / 5));
        break;
    case 1:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 = 40;
        break;
    case 2:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        lbl_80515F90.pad_18 = 182.04445f * (lbl_80515F90.pad_18 + lbl_80515F90.pad_2A * (level / 5));
        break;
    case 3:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 10) * 5;
        lbl_80515F90.pad_18 = 182.04445f * (lbl_80515F90.pad_18 + lbl_80515F90.pad_2A * (level / 5));
        lbl_80515F90.pad_18 = 182.04445f * (lbl_80515F90.pad_18 + lbl_80515F90.pad_2A * (level / 5));
        break;
    case 4:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        lbl_80515F90.pad_18 = 182.04445f * (lbl_80515F90.pad_18 + lbl_80515F90.pad_2A * (level / 5));
        break;
    case 5:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        break;
    case 6:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 10) * 5;
        break;
    case 7:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        break;
    case 8:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        break;
    case 9:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        break;
    case 10:
        lbl_80515F90.pad_08 = lbl_80515F90.pad_08 * (1.0f + calc_technique_boost(10, client));
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        if (level <= 1) {
            lbl_80515F90.pad_22 = 0;
        }
        break;
    case 11:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 10) * 5;
        break;
    case 12:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * clamp_nonnegative_int(level - 4);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 10) * 5;
        break;
    case 13:
        lbl_80515F90.pad_08 = lbl_80515F90.pad_08 * (1.0f + calc_technique_boost(13, client));
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        if (level <= 1) {
            lbl_80515F90.pad_22 = 0;
        }
        break;
    case 15:
        lbl_80515F90.pad_08 = lbl_80515F90.pad_08 * (1.0f + calc_technique_boost(15, client));
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        if (level <= 1) {
            lbl_80515F90.pad_22 = 0;
        }
        break;
    case 16:
        lbl_80515F90.pad_08 = lbl_80515F90.pad_08 * (1.0f + calc_technique_boost(16, client));
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        if (level < 1) {
            lbl_80515F90.pad_22 = 0;
        }
        break;
    case 18:
        lbl_80515F90.pad_08 += lbl_80515F90.pad_26 * (level / 5);
        if (TTecCtrl::is_technique_ready()) {
            lbl_80515F90.tp_cost = lbl_80515F90.tp_cost * lbl_804CC55C[technique].tp_cost;
        }
        lbl_80515F90.pad_12 = lowered_pad_12(level);
        lbl_80515F90.pad_14 += lbl_80515F90.pad_28 * level;
        lbl_80515F90.pad_20 -= (capped / 5) * 5;
        lbl_80515F90.pad_18 = 182.04445f * (lbl_80515F90.pad_18 + lbl_80515F90.pad_2A * (level / 5));
        break;
    }
    if (lbl_80515F90.pad_20 <= 0) {
        lbl_80515F90.pad_20 = 10;
    }
    if (lbl_80515F90.pad_12 <= 0) {
        lbl_80515F90.pad_12 = 0;
    }
    return &lbl_80515F90;
}

void TTecCtrl::render() {  }

void launch_technique__10TObjPlayerFv(s32 tech, s32 unused, Player_8022D27C *pl) {
    Vec aim;
    Vec hand;
    Vec ofs;
    List_8022D27C list;
    void *td;
    s32 n;
    Target_8022D27C *targets;
    s32 i;
    Ent_8022D27C *ent;
    __ct__16TargetCursorListFv((&list));
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
    td = pl->tech;
    targets = get_technique_data__10TObjPlayerFPv(td);
    if (targets == NULL) {
        return;
    }
    n = ((TObjPlayer *)td)->get_section_clamped();
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, pl->rotY);
    matrix_mult_vec(0, &ofs, &ofs);
    pop_matrices(1);
    ofs.x += pl->pos.x;
    ofs.y += pl->pos.y;
    ofs.z += pl->pos.z;
    get_hand_joint_position__10TObjPlayerFl(pl, &hand);
    switch (tech) {
    case 0:
        if (n != 0) {
            AIM_8022D27C()
            TTecFoie::create_ex(pl, &hand, &aim, get_cast_technique_level(td, 0));
        } else {
            TTecFoie::create(pl, &hand, pl->rotY, get_cast_technique_level(td, 0));
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
            TTecBarta::create(pl, &pl->pos, &aim, get_cast_technique_level(td, 3));
        } else {
            TTecBarta::create_ex(pl, &pl->pos, pl->rotY, get_cast_technique_level(td, 3));
        }
        break;
    case 4:
        if (n != 0) {
            AIM_8022D27C()
            TTecGiBarta::create(pl, &hand, &aim, get_cast_technique_level(td, 4));
        } else {
            TTecGiBarta::create_ex(pl, &hand, pl->rotY, get_cast_technique_level(td, 4));
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
        } else if (local_client_id == get_entity_id(pl)) {
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
            TTecMegid::create_ex((saddr)pl, (saddr)&hand, pl->rotY, (s32)(get_cast_technique_level(td, 18)));
        }
        break;
    }
}

void capture_technique_targets__10TObjPlayerFv(int kind, Owner_8022CDE8 *owner) {
    Cursor_8022CDE8 *c;
    void *slots;
    if (owner == NULL) {
        return;
    }
    if (owner->f424 == NULL) {
        return;
    }
    slots = owner->slots;
    if (slots == NULL) {
        return;
    }
    ((TObjPlayer *)(owner->slots))->reset_slots();
    c = (Cursor_8022CDE8 *)owner->f424->find_by_pos(3, kind);
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
        for (i = 0; i < ((TLockOnCursor *)(c->list))->get_target(); i++) {
            if (((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, n)))->get_type_id() != 0xFFFF) {
                set_slot_type_state__10TObjPlayerFllss(slots, n,
                    ((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, n)))->get_type_id(),
                    get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(c->list, n)));
                n++;
            }
        }
        ((TObjPlayer *)slots)->set_tech_level(n);
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
        for (i = 0; i < ((TLockOnCursor *)(c->list))->get_target(); i++) {
            set_slot_type_state__10TObjPlayerFllss(slots, n,
                ((TObjPlayer *)(TObjPlayer__sub_80116620(c->list, n)))->get_type_id(),
                get_obj_id__10TObjPlayerFv(TObjPlayer__sub_80116620(c->list, n)));
            n++;
        }
        ((TObjPlayer *)slots)->set_tech_level(n);
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
        void *o;                                                                                 \
        new TActorLight(0.1f, 0.35f, TObjLight__scene_light_state.intensity, &c, &v, base,          \
                          (TObjBase *)owner, tl_07);                                             \
        if (TObjPlayer::is_locally_controlled(owner) != 0) {                                \
            o = TObject::operator new(0x34);                                                     \
            if (o != NULL) {                                                                     \
                INIT(o, owner, tl_07);                                                           \
            }                                                                                    \
        }                                                                                        \
    }
void create_technique_charge_light(u32 kind, void *owner) {
    Params_8022C738 *p = (Params_8022C738 *)get_technique_base_params(kind);
    s32 base = p->f12 + p->f20 + 50;
    switch (kind) {
    case 1:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 0.5f, 0.0f, __ct__13TUnk_804CC794Fll)
        break;
    case 0:
    case 2:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 0.5f, 0.0f, __ct__13TUnk_804CC794Fll)
        break;
    case 3:
    case 4:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 1.0f, 1.0f, __ct__13TUnk_804CC948Fll)
        break;
    case 5:
        CHARGE_LIGHT_8022C738(1.0f, 0.3f, 0.7f, 1.0f, __ct__13TUnk_804CC948Fll)
        break;
    case 6:
    case 7:
    case 8:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 1.0f, 0.3f, __ct__13TUnk_804CCD0CFll)
        break;
    case 9:
    case 15:
    case 16:
    case 17:
        CHARGE_LIGHT_8022C738(1.0f, 1.0f, 1.0f, 1.0f, __ct__13TUnk_804CC990Fll)
        break;
    case 10:
    case 11:
    case 12:
    case 14:
        CHARGE_LIGHT_8022C738(1.0f, 0.3f, 0.9f, 1.0f, __ct__13TUnk_804CCAC8Fll)
        break;
    case 13:
        CHARGE_LIGHT_8022C738(1.0f, 0.9f, 0.3f, 1.0f, __ct__13TUnk_804CCAC8Fll)
        break;
    case 18:
        CHARGE_LIGHT_8022C738(1.0f, 0.6f, 0.2f, 0.7f, __ct__13TUnk_804CC74CFll)
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
        lbl_80515FBC[client].set(index, boost);
    }
}

f32 calc_technique_boost(s32 technique, u16 actor) {
    f32 sum;
    void *player;
    s32 i;

    sum = 0.0f;
    if (actor >= 4) {
        return sum;
    }
    for (i = 0; i < 6; i++) {
        if (technique == lbl_80515FBC[actor].boosts[i].technique) {
            sum += lbl_80515FBC[actor].boosts[i].amount;
        }
    }
    player = get_player_by_client_id(actor);
    if (player != NULL) {
        sum += ((f32 (*)(void *, u16, s16))get_battle_value__10TObjPlayerFlil)(player, actor, technique);
    }
    return sum;
}

u32 get_technique_caster_flags(s32 technique, u16 actor) {
    u32 flags;
    void *player;
    s32 i;

    flags = 0;
    if (actor >= 4) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        player = get_player_by_client_id(actor);
        if (player != NULL) {
            flags += ((f32 (*)(void *, u16, s16))get_battle_value__10TObjPlayerFlil)(player, actor, technique);
            switch (technique) {
            case 18:
                if (((f32 (*)(void *, u16, s16))get_battle_value__10TObjPlayerFlil)(player, actor, technique) == 1.0f) {
                    flags |= 1;
                }
                break;
            }
        }
        if (technique == lbl_80515FBC[actor].boosts[i].technique) {
            flags |= lbl_80515FBC[actor].boosts[i].flags;
        }
    }
    return flags;
}

s32 TTecCtrl::classify_distance_band(s32 technique, s32 level, u16 arg2) {
    f32 temp_f1;

    calc_technique_parameters(technique, level, arg2);
    if ((level == 0) || (level == 1)) {
        return 0;
    }
    temp_f1 = calc_technique_boost(technique, arg2);
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
