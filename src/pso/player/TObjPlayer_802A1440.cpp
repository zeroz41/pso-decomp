#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TNpcPlayer_802C3CD0.h"
#include "pso/player/TObjPlayer_802A1440.h"
#include "pso/ui/TAdSelectTxtGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TAdSelectTxtGC.h"
#include "pso/misc/TLobby.h"

struct P_802A1544 { u8 pad0[0x408]; s8 v[0x14]; };

extern "C" {

int clear_player_data_block(void*);
int init_inventory_items__12TPlyCharDataFv(void*);

void TObjPlayer::init_select_txt() { *(int*)(this) = 0; TAdSelectTxtGC__sub_802A16A8((char*)this + 0x4); ((FlagWord *)((char*)this + 0x428))->reset(); ((TObjPlayer *)((char*)this + 0xc))->initialize_player_data(); }

void TObjPlayer::copy_lobby_header(s32 arg1) {
    s32 *arg0 = (s32 *)this;
    ((FlagWord *)((s8 *)arg0 + 0x428))->set(1);
    *arg0 = TAdSelectTxtGC__sub_802A16C0((void *)arg1);
    ((TLobby *)((s8 *)arg0 + 4))->copy_header_struct((void *) ((s8 *)arg1 + 0xDAC));
    export_character_data__10TObjPlayerFPvPv((u8 *)arg1, (u8 *)((s8 *)arg0 + 0xC));
}

void TObjPlayer::initialize_player_data() { *(unsigned char*)((char*)this + 0x3) = 0; *(unsigned char*)((char*)this + 0x2) = 0; *(unsigned char*)((char*)this + 0x1) = 0; *(unsigned char*)(this) = 0; init_inventory_items__12TPlyCharDataFv(this); ((TAdSelectTxtGC *)((char*)this + 0x34c))->reset_state(); clear_player_data_block((char*)this + 0x370); TObjPlayer__sub_802A1588((void*)((char*)this + 0x3c0)); init_item_counts_max(); }

void TObjPlayer::init_item_counts_max() {
    P_802A1544 *arg0 = (P_802A1544 *)this;
    s32 i;
    for (i = 0; i < 0x14; i++) {
        arg0->v[i] = TObjPlayer::get_item_count_max();
    }
}

void TObjPlayer__sub_802A1588(void* p) { ((TObjPlayer *)p)->init_action_config(); ((TObjPlayer *)((char*)p + 0x24))->init_action_config(); }

}
