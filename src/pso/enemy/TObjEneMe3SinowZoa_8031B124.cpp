extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);
#include "types.h"
#include "pso/enemy/TObjEneMe3SinowZoa_8031B124.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"

extern s32 __vt__18TObjEneMe3SinowZoa[];
extern void *lbl_805D4120;

void *TObjEneMe3SinowZoa__ct(void *ene_me3_sinow_zoa) {
    __ct__12TObjEneDD_STFP7TObject(ene_me3_sinow_zoa);
    *(s32 **)((s8 *)ene_me3_sinow_zoa + 0x18) = __vt__18TObjEneMe3SinowZoa;
    __ct__19MaterialOpacityFadeFv(((char *)ene_me3_sinow_zoa + 1044));
    *(void * *)&((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->m_name = lbl_805D4120;
    return ene_me3_sinow_zoa;
}
