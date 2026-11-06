#include "types.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC_80310050.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__16TAdChrSelBSlotGC[];
extern void *TAdChrSelBSlotGC__name;

void *TAdChrSelBSlotGC__ct(TAdChrSelBSlotGC *ad_chr_sel_b_slot_gc) {
    __ct__7TObjectFP7TObject(ad_chr_sel_b_slot_gc);
    *(s32 **)((s8 *)ad_chr_sel_b_slot_gc + 0x18) = __vt__16TAdChrSelBSlotGC;
    *(void * *)&ad_chr_sel_b_slot_gc->m_name = TAdChrSelBSlotGC__name;
    ad_chr_sel_b_slot_gc->sub_8030FE04();
    ad_chr_sel_b_slot_gc->create_children();
    return ad_chr_sel_b_slot_gc;
}

}
