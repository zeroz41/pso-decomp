#include "types.h"
#include "pso/ui/charcreate/TChCrTagInformation_802A1FAC.h"
#include "pso/unk/text_803098DC.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"

extern "C" {

extern const f32 lbl_805DDE20;
extern s32 __vt__19TChCrTagInformation[];
extern const f32 lbl_805DDE24;
extern void *TChCrTagInformation__class_name;

void *TChCrTagInformation__ct(TChCrTagInformation *ch_cr_tag_information, TObject *parent, void *arg) {
    __ct__8TChCrTagFP7TObjectPv(ch_cr_tag_information, parent, arg);
    *(s32 **)((s8 *)ch_cr_tag_information + 0x18) = __vt__19TChCrTagInformation;
    *(void * *)&ch_cr_tag_information->m_name = TChCrTagInformation__class_name;
    ch_cr_tag_information->m_28 = lbl_805DDE20;
    *(f32 *)((s8 *)ch_cr_tag_information + 0x2C) = lbl_805DDE24;
    ch_cr_tag_information->m_34 = lbl_805DDE20;
    *(f32 *)((s8 *)ch_cr_tag_information + 0x38) = lbl_805DDE24;
    fn_803098E8();
    return ch_cr_tag_information;
}

}
