#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/misc/TPlyPhotonChair_80142524.h"
#include "pso/misc/TPlyPhotonChair_80143888.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/misc/TUnk_804A7488.h"
#include "pso/misc/TPlyPhotonChair.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct RecoveredGlobal_801426DC_lbl_8050BFF0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801426DC_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80142734_lbl_8050BFF0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80142734_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

extern s32 model_render_flags;
    extern int lbl_805D566C;
    extern int lbl_805D5670;
    extern int lbl_805D5674;
    extern int chunk_polygon_flags_or_mask;
    extern int chunk_polygon_flags_and_mask;
extern "C" {
s32 activate__15TPlyPhotonChairFv();

int draw_chunk_object(void);
extern RecoveredGlobal_801426DC_lbl_8050BFF0 photon_chair_color_vec4;
extern RecoveredGlobal_801426DC_lbl_8058D4C0 model_material_color;
extern const f64 lbl_8043F298;
extern const f64 lbl_8043F2A0;
extern const f64 lbl_8043F2A8;
extern const f32 __float_nan[];
extern const f32 __float_huge[];

void TPlyPhotonChair::play_sound_with_arg(void* p, void* a1) { set_global_draw_flag_bits((s32)p, (s32)((void*)2064)); set_chunk_material_override_pair((s32)((void*)-1), (s32)((void*)2048)); set_constant_material((const NJS_ARGB *)a1); }

void TPlyPhotonChair::play_sound() { set_global_draw_flag_bits((s32)this, (s32)((void*)2064)); set_chunk_material_override_pair((s32)((void*)-1), (s32)((void*)2048)); set_constant_material((const NJS_ARGB *)this); }

void TPlyPhotonChair::update_parts(void* p) { TPlyPhotonChair__sub_8014270C((s32)p); TPlyPhotonChair::copy_vec4_forward((s32)p); TPlyPhotonChair::restore_state((s32)p); }

void TPlyPhotonChair::update_parts2(void* p) { TPlyPhotonChair::save_state((s32)p); TPlyPhotonChair::copy_vec4_reverse((s32)p); TPlyPhotonChair__sub_80142720((s32)p); }

#pragma push
#pragma fp_contract on
f64 TPlyPhotonChair__sub_80142624(f64 x) {
    if (x > lbl_8043F298) {
        f64 g = __frsqrte(x);
        g = lbl_8043F2A0 * g * (lbl_8043F2A8 - x * (g * g));
        g = lbl_8043F2A0 * g * (lbl_8043F2A8 - x * (g * g));
        g = lbl_8043F2A0 * g * (lbl_8043F2A8 - x * (g * g));
        g = lbl_8043F2A0 * g * (lbl_8043F2A8 - x * (g * g));
        return x * g;
    }
    if (lbl_8043F298 == x) {
        return lbl_8043F298;
    }
    if (x != lbl_8043F298) {
        return __float_nan[0];
    }
    return __float_huge[0];
}
#pragma pop

#pragma push
#pragma scheduling off
void set_global_draw_flag_bits(s32 arg0, s32 arg1) {
    model_render_flags |= arg1;
}
#pragma pop

void TPlyPhotonChair::restore_state(s32 _w0) { (*(int *)&model_render_flags) = lbl_805D566C; }

typedef char RecoveredGlobal_801426DC_lbl_8050BFF0_size[sizeof(RecoveredGlobal_801426DC_lbl_8050BFF0) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801426DC_lbl_8058D4C0_size[sizeof(RecoveredGlobal_801426DC_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TPlyPhotonChair::copy_vec4_forward(s32 _w0) {
    copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&photon_chair_color_vec4.value);
}

int TPlyPhotonChair__sub_8014270C(s32 _w0) { chunk_polygon_flags_and_mask = lbl_805D5670; chunk_polygon_flags_or_mask = lbl_805D5674; return lbl_805D5670; }
int TPlyPhotonChair__sub_80142720(s32 _w0) { lbl_805D5670 = chunk_polygon_flags_and_mask; lbl_805D5674 = chunk_polygon_flags_or_mask; return chunk_polygon_flags_and_mask; }

typedef char RecoveredGlobal_80142734_lbl_8050BFF0_size[sizeof(RecoveredGlobal_80142734_lbl_8050BFF0) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_80142734_lbl_8058D4C0_size[sizeof(RecoveredGlobal_80142734_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TPlyPhotonChair::copy_vec4_reverse(s32 _w0) {
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_80142734_lbl_8050BFF0 *)&photon_chair_color_vec4).value), (NJS_ARGB *)(&(*(RecoveredGlobal_80142734_lbl_8058D4C0 *)&model_material_color).value));
}

void TPlyPhotonChair::save_state(s32 _w0) { lbl_805D566C = (*(int *)&model_render_flags); }
}
