#include "pso/ui/frontend/TAdPlyPltAnimGC_80356190.h"
#include "pso/player/TObjPlayer_8023E480.h"

    extern unsigned char lbl_80479300[];
    extern unsigned char player_prate_texture_list[];
    extern int player_prate_texture_list_ptr;
void register_player_prate(void) { player_prate_texture_list_ptr = (int)player_prate_texture_list; TLobby__sub_8023E4B4((s32)lbl_80479300, (s32)player_prate_texture_list); }
