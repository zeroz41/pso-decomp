#include "types.h"
#include "pso/ui/charcreate/TObjCMIcon.h"

extern "C" {

class TChCrCharSelect {
public:
    void handle_cursor_input();
    void handle_menu_input();
    void tick_and_apply_selection();
};

void reset_proportions__15TChCrCharSelectFv(void);
void TObjCMIcon__sub_802994C8(s32 arg0, s32 *arg1);
const s32 lbl_80464E90[2] = {0, 4};
s32 TChCrCharSelect__input_mode;
const s32 lbl_805DD9D8[1] = {4};

void run_task__15TChCrCharSelectFv(TChCrCharSelect *self) {
    reset_proportions__15TChCrCharSelectFv();
    static void (TChCrCharSelect::*tbl[3])() = {
        &TChCrCharSelect::handle_cursor_input, &TChCrCharSelect::handle_menu_input,
        &TChCrCharSelect::tick_and_apply_selection,
    };
    (self->*tbl[TChCrCharSelect__input_mode])();
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
