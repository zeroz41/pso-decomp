#include "types.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/BmlResource.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

extern "C" { extern char lbl_804728D0[]; }
const char *lbl_805D3F78 = lbl_804728D0;

void TAdChrSelPlayerGC::init_selection_model(s32 window_offset_index) {
    this->m_name = lbl_805D3F78;
    state = 0;
    this->pending_state = 0;
    this->status_index = 0;
    layout_mode = window_offset_index;
    preview_data = NULL;
    *(s32 *)&this->joint_matrices = (saddr)mem_alloc(0xC00);
    TAdPlyStatusGC::get_instance(this, window_offset_index);
    place_model_for_mode(layout_mode);
}

TAdChrSelPlayerGC::TAdChrSelPlayerGC(TObject *parent, s32 mode, s32 index, s32 slot) : TObjMotion(parent) {
    this->slot = slot;
    formation_index = index;
    init_selection_model(mode);
}

extern uaddr multi_ply_chr_select_resource_bundle;

TAdChrSelPlayerGC *TAdMultiPlyChrSelectGC::get_or_create_player(TObject *parent, s32 mode, s32 index, s32 slot) {
    if (multi_chr_select_player_slot_table[slot] == NULL) {
        multi_chr_select_player_slot_table[slot] = new TAdChrSelPlayerGC(parent, mode, index, slot);
    }
    return multi_chr_select_player_slot_table[slot];
}

void TAdChrSelPlayerGC__sub_802E10A0(void) {
    if ((u32) multi_ply_chr_select_resource_bundle != 0U) {
        delete (BmlResource *)multi_ply_chr_select_resource_bundle;
        multi_ply_chr_select_resource_bundle = 0U;
    }
}
