#include "pso/TTecCtrl.h"
#include "pso/misc/TTecCtrl.h"
#include "pso/misc/TTecZondeEff.h"

TTecCtrl::~TTecCtrl() {}

#include "types.h"
#include "pso/TTecZondeEff.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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
}

    extern unsigned char technique_param_table[];

s32 clamp_nonnegative_int(s32 x) {
    if (x <= 0) {
        x = 0;
    }
    return x;
}

void* get_technique_base_params(int a0) {  return (char*)technique_param_table + a0 * 44; }

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
