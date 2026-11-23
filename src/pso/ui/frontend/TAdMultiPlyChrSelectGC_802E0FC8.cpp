#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

TAdChrSelPlayerGC::TAdChrSelPlayerGC(TObject *parent, s32 mode, s32 index, s32 slot) : TObjMotion(parent) {
    this->slot = slot;
    formation_index = index;
    init_selection_model(mode);
}

extern "C" {

extern uaddr TAdMultiPlyChrSelectGC__resource_bundle;

TAdChrSelPlayerGC *TAdMultiPlyChrSelectGC::get_or_create_player(TObject *parent, s32 mode, s32 index, s32 slot) {
    if (multi_chr_select_player_slot_table[slot] == NULL) {
        multi_chr_select_player_slot_table[slot] = new TAdChrSelPlayerGC(parent, mode, index, slot);
    }
    return multi_chr_select_player_slot_table[slot];
}

void TAdChrSelPlayerGC__sub_802E10A0(void) {
    if ((u32) TAdMultiPlyChrSelectGC__resource_bundle != 0U) {
        delete (BmlResource *)TAdMultiPlyChrSelectGC__resource_bundle;
        TAdMultiPlyChrSelectGC__resource_bundle = 0U;
    }
}

}
