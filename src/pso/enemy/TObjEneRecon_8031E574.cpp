#include "types.h"
#include "pso/enemy/TObjEneRecon_8031E574.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneRecon.h"

extern "C" {

s32 __ct__12TObjEneDD_STFP7TObject();
s16 get_entity_id(void *);

extern s32 __vt__12TObjEneRecon[];
extern s32 TObjEneRecon_name_ref;

u8 *TObjEneRecon__ct(u8 *ene_recon, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5, s32 arg6) {
    __ct__12TObjEneDD_STFP7TObject();
    *(s32 **)((s8 *)ene_recon + 0x18) = __vt__12TObjEneRecon;
    __ct__19MaterialOpacityFadeFv((ene_recon + 0x480));
    *(s32 *)((s8 *)ene_recon + 0) = (s32) TObjEneRecon_name_ref;
    *(s16 *)((s8 *)ene_recon + 0x434) = get_entity_id((void *)arg2);
    ((TObjEneDD *)ene_recon)->init_common_from((u8 *)arg2);
    ((TObjEneRecon *)ene_recon)->entity_id = arg3;
    *(s16 *)((s8 *)ene_recon + 0x2C) = arg4;
    VecCopy((Vec *)(ene_recon + 0x38), (const Vec *)(arg5));
    VecCopy((Vec *)(ene_recon + 0x438), (const Vec *)(arg2 + 0x38));
    VecCopy((Vec *)(ene_recon + 0x428), (const Vec *)(arg6));
    ((TObjEneRecon *)ene_recon)->init_state();
    *(f32 *)((s8 *)ene_recon + 0x460) = (f32) (*(f32 *)((s8 *)ene_recon + 0x460) + ((TObjEneRecon *)arg2)->get_field_4d0());
    *(f32 *)((s8 *)ene_recon + 0x468) = (f32) (*(f32 *)((s8 *)ene_recon + 0x468) + ((TObjEneRecon *)arg2)->get_field_4d4());
    *(s32 *)((s8 *)ene_recon + 0x80) = 0;
    return ene_recon;
}

}
