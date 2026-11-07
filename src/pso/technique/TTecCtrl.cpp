#include "pso/technique/TTecCtrl.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/technique/TTecAnti.h"

TTecCtrl::~TTecCtrl() {}

#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8022F068_lbl_804CC934 {
    u8 * value;
    u8 remaining[0x8];
};

extern "C" {
u8 * TLobby__sub_8001FE7C(void *, s16);
s32 release_texture_list(void *, s32);
extern RecoveredGlobal_8022F068_lbl_804CC934 technique_ringwave_texture_list;
extern u8 *technique_effect_bml;
extern void **lbl_805D63B0;
extern u8 technique_resource_descriptor[];
extern u8 lbl_8044D088[];
extern u8 lbl_8044D094[];
u8 *load_resource_from_descriptor(u8 *, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);
void bind_gvm_texture_list(void *, void *);
void reset_telepipe_visit_counts(void);
void __ct__7TObjectFP7TObject(void *);

void TTecCtrl::render() {  }

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
    ((TTecAnti *)&lbl_80515F90)->copy_params((u8 *)&technique_param_table[technique]);
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
}

s32 clamp_nonnegative_int(s32 x) {
    if (x <= 0) {
        x = 0;
    }
    return x;
}

void* get_technique_base_params(int a0) {  return &technique_param_table[a0]; }

extern s8 lbl_805D63A8;

void TTecCtrl::run_task() {
    lbl_805D63A8 = 0;
    reset_telepipe_visit_counts();
}

extern s32 __vt__8TTecCtrl[];
extern void *TTecCtrl__name;

void *__ct__8TTecCtrlFv(void *tec_ctrl) {
    __ct__7TObjectFP7TObject(tec_ctrl);
    *(s32 **)((s8 *)tec_ctrl + 0x18) = __vt__8TTecCtrl;
    *(void * *)&((TTecCtrl *)tec_ctrl)->m_name = TTecCtrl__name;
    *(u32 *)((s8 *)tec_ctrl + 0x1C) = 0;
    return tec_ctrl;
}
typedef char RecoveredGlobal_8022F068_lbl_804CC934_size[sizeof(RecoveredGlobal_8022F068_lbl_804CC934) == 0xC ? 1 : -1];
void TLobby__sub_8022F068(void) {
    u8 *temp_r4;
    clear_zonde_beam_vertex_pointer();
    if ((u32) *(u32 *)((s8 *)technique_ringwave_texture_list.value + 8) != 0U) {
        release_texture_list(&technique_ringwave_texture_list.value, (s32) technique_ringwave_texture_list.value);
    }
    if ((void **) lbl_805D63B0 != NULL) {
        temp_r4 = (u8 *)(*lbl_805D63B0);
        if ((u32) *(u32 *)((s8 *)temp_r4 + 8) != 0U) {
            release_texture_list(lbl_805D63B0, (s32) temp_r4);
        }
        TAdSinglePlyChrSelectGC::safe_free((u32) lbl_805D63B0);
        lbl_805D63B0 = NULL;
    }
    if ((void *) technique_effect_bml != NULL) {
        TLobby__sub_8001FE7C(technique_effect_bml, 1);
    }
    technique_effect_bml = NULL;
}
void load_technique_resources(void) {
    u8 *p = (u8 *)::operator new(0x440);
    if (p != 0) {
        p = load_resource_from_descriptor(p, 1, technique_resource_descriptor, 0, 0, 0);
    }
    technique_effect_bml = p;
    lbl_805D63B0 = (void **)load_gvm_texture_file((s32)lbl_8044D088);
    bind_gvm_texture_list(lbl_8044D094, ((u8 *)&technique_ringwave_texture_list));
    TTecZondeEff::init_resources();
}
