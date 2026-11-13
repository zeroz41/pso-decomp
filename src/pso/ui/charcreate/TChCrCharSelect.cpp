#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/unk/text_802993F0.h"
#include "pso/ui/charcreate/TObjCMIcon_80299488.h"
#include "pso/ui/charcreate/TChCrEffTag.h"

TChCrCharSelect::~TChCrCharSelect() {}

extern "C" {
extern u8 lbl_80464E88[];
extern s32 TChCrCharSelect__name;
extern s32 TChCrCharSelect__selected_char_index;
extern s32 TChCrCharSelect__selected_slot_index;
extern s32 TChCrCharSelect__input_mode;
}

TChCrCharSelect::TChCrCharSelect(TObject *parent) : TObject(parent) {
    m_name = (const char *)TChCrCharSelect__name;
    TChCrEffTag::set_eff_tag(0);
    fn_802993F0();
    if (TChCrCharSelect__selected_char_index == -1 || TChCrCharSelect__selected_slot_index == -1) {
        TChCrCharSelect__selected_char_index = 0;
        TChCrCharSelect__selected_slot_index = 0;
        TChCrCharSelect__input_mode = 0;
    } else {
        TChCrCharSelect__input_mode = 1;
    }
    fn_8029945C(lbl_80464E88);
    init_widgets();
}
