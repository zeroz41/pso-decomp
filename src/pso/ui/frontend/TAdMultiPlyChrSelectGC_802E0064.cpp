#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0064.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"

extern "C" {

void TAdChrSelPlyPlateGC::set_cursor_column(s32 column) { cursor_col = column; }

    extern int multi_ply_chr_select_active_player;
    extern int TAdMultiPlyChrSelectGC__selected_slot;

void TAdChrSelPlyPlateGC::set_cursor_fields(s32 field_4f4, s32 field_4f0) {
    unk_4f4 = field_4f4;
    unk_4f0 = field_4f0;
}

void TAdChrSelPlyPlateGC::restore_selection() { TAdMultiPlyChrSelectGC__selected_slot = multi_ply_chr_select_active_player; }

void TAdChrSelPlyPlateGC::capture_card_index() { unk_4e8 = get_active_card_slot(); }
s32 TAdChrSelPlyPlateGC::get_field_0x530() { return unk_530; }
void TAdChrSelBSlotGC::set_state(s32 value) { state = value; }
s32 TAdChrSelBSlotGC::get_state() { return state; }

s32 TAdChrSelBSlotGC::is_state_closing() {
    switch (state) {
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
        return 1;
    }
    return 0;
}

TAdChrMoveEffectGC *TAdMultiPlyChrSelectGC::get_global_state() { return lbl_805D6E78; }

    extern int lbl_805D384C;
int TAdMultiPlyChrSelectGC::get_select_flag() {  return lbl_805D384C; }

}
