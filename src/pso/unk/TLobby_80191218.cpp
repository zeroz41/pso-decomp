#include "types.h"
#include "pso/npc/TNpcPlayer_80190E64.h"
#include "pso/unk/TLobby_80191218.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void set_player_quest_control_flag(register s32 r3);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TLobby::create_npc(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB8);
    if (o != NULL) {
        o = TLobby__sub_8019118C((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

    extern int npc_proximity_target_id;
void TLobby__sub_80191264(void) { npc_proximity_target_id = -1; }

void TLobby__sub_80191270(void) { npc_proximity_target_id = -1; }

void set_player_quest_control_flag(register s32 r3) {
    ((TObjPlayer *)r3)->set_state_flags(0x8000);
}

    extern int hashi_versus2_flag;
void TObjHashiVersus2__sub_801912A4(void) { hashi_versus2_flag = 1; }

void TObjHashiVersus2__sub_801912B0(void) { hashi_versus2_flag = 0; }

}
