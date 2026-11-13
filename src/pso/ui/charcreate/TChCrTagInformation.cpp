#include "types.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/unk/text_80309890.h"
#include "pso/unk/text_803098DC.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {
s32 get_char_select_class_id();
extern const f32 lbl_805DDE1C;
void __dl__7TObjectFPv(void *);

void TChCrTagInformation::render() { draw_char_info_sprites(); }

void TChCrTagInformation::update_selected_char() {
    s32 c;
    if (m_24 < lbl_805DDE1C) {
        fn_80309890(this, -1);
        return;
    }
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        c = TChCrCharSelect::get_selected_char();
        if (c >= 0) {
            fn_80309890(this, c);
        }
        break;
    default:
        TChCrCharSelect::get_instance();
        fn_80309890(this, get_char_select_class_id() + 3);
        break;
    }
}

void TChCrTagInformation::run_task() { update_fade__8TChCrTagFPv(this); update_selected_char(); }
int TChCrTagInformation__vt4(void) { return 0; }

extern s32 __vt__19TChCrTagInformation[];

TChCrTagInformation *__dt__19TChCrTagInformationFv(TChCrTagInformation *tag, s16 free) {
    if (tag != NULL) {
        *(s32 **)((u8 *)tag + 0x18) = __vt__19TChCrTagInformation;
        fn_803098DC();
        __dt__8TChCrTagFv(tag, 0);
        if (free > 0) {
            __dl__7TObjectFPv(tag);
        }
    }
    return tag;
}

}

extern "C" {

extern const f32 lbl_805DDE20;
extern const f32 lbl_805DDE24;
extern const char *TChCrTagInformation__class_name;

}

TChCrTagInformation::TChCrTagInformation(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = TChCrTagInformation__class_name;
    m_28 = lbl_805DDE20;
    m_2c = lbl_805DDE24;
    m_34 = lbl_805DDE20;
    m_38 = lbl_805DDE24;
    fn_803098E8();
}
