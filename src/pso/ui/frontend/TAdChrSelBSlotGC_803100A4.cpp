#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"

extern "C" {
s32 are_split_screen_battle_players_tied(void *);
extern s32 TLobby__battle_ctrl_default_value;

void *TAdChrSelBSlotGC::create(void *ad_chr_sel_b_slot_gc) {
    return new TAdChrSelBSlotGC((TObject *)ad_chr_sel_b_slot_gc);
}

    extern int TAdChrSelBSlotGC__global_state;
int TAdChrSelBSlotGC::get_global_state() {  return TAdChrSelBSlotGC__global_state; }

    extern int TAdChrSel__global_slot_data;
int TAdChrSelBSlotGC::get_global_slot_data() {  return TAdChrSel__global_slot_data; }
s32 TLobby::get_battle_ctrl_default() {
    return are_split_screen_battle_players_tied(this) != 0 ? 0 : TLobby__battle_ctrl_default_value;
}

}
