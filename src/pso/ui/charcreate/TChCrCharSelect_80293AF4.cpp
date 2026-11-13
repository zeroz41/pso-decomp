#include "types.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {

void TObjCMIcon__sub_802994C8(s32 arg0, s32 *arg1);
const s32 lbl_80464E90[2] = {0, 4};
s32 TChCrCharSelect__input_mode;
const s32 lbl_805DD9D8[1] = {4};

void TChCrCharSelect::run_task() {
    reset_proportions();
    static void (TChCrCharSelect::*tbl[3])() = {
        &TChCrCharSelect::handle_cursor_input, &TChCrCharSelect::handle_menu_input,
        &TChCrCharSelect::tick_and_apply_selection,
    };
    (this->*tbl[TChCrCharSelect__input_mode])();
    switch (TChCrCharSelect__input_mode) {
    case 0:
        TObjCMIcon__sub_802994C8(1, (s32 *)lbl_805DD9D8);
        return;
    case 1:
        TObjCMIcon__sub_802994C8(2, (s32 *)lbl_80464E90);
        return;
    case 2:
    default:
        TObjCMIcon::reset_icon_flags();
        return;
    }
}

}
