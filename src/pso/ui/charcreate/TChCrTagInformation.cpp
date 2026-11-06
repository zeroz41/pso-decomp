#include "types.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/unk/text_80309890.h"
#include "pso/unk/text_803098DC.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

struct Tag_802A1E8C {
    u8 pad[0x24];
    f32 f24;
};

extern "C" {
s32 get_char_select_class_id();
extern const f32 lbl_805DDE1C;
void __dl__7TObjectFPv(void *);

void TChCrTagInformation::render() { { (void)(draw_char_info_sprites()); return; } }

void TChCrTagInformation::update_selected_char() {
    Tag_802A1E8C *arg0 = (Tag_802A1E8C *)this;
    s32 c;
    if (arg0->f24 < lbl_805DDE1C) {
        fn_80309890(arg0, -1);
        return;
    }
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        c = TChCrCharSelect::get_selected_char();
        if (c >= 0) {
            fn_80309890(arg0, c);
        }
        break;
    default:
        TChCrCharSelect::get_instance();
        fn_80309890(arg0, get_char_select_class_id() + 3);
        break;
    }
}

void TChCrTagInformation::run_task() { update_fade__8TChCrTagFPv((u8 *)this); update_selected_char(); }
int TChCrTagInformation__vt4(void) { return 0; }

extern s32 __vt__19TChCrTagInformation[];

void *__dt__19TChCrTagInformationFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TChCrTagInformation;
        fn_803098DC();
        __dt__8TChCrTagFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
