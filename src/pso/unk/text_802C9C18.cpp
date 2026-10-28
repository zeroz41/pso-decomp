#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOTrapSeabed01.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/map/CurrentArea.h"

struct Sounds_802C9C18 { s32 a[2]; s32 b[2]; s32 c[2]; s32 d[2]; };

extern "C" {
u16 get_entity_id(void *);
void obj_clear_flag30_20000(void *arg0);
s32 check_player_flag1__6TLobbyFv();
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
s32 play_sound_effect(s32, void *, s32, s32);
extern Sounds_802C9C18 lbl_804720B8;

void TOTrapSeabed01::sub_802C9C18(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Sounds_802C9C18 s = lbl_804720B8;
    switch (get_current_area()) {
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
        *(s32 *)(arg0 + 0x358) = play_sound_effect(s.a[arg1], (u8 *)&this->position, 0, 0);
        break;
    case 0x1C:
    case 0x1D:
        *(s32 *)(arg0 + 0x358) = play_sound_effect(s.b[arg1], (u8 *)&this->position, 0, 0);
        break;
    case 0x22:
        *(s32 *)(arg0 + 0x358) = play_sound_effect(s.c[arg1], (u8 *)&this->position, 0, 0);
        break;
    case 0x23:
        *(s32 *)(arg0 + 0x358) = play_sound_effect(s.d[arg1], (u8 *)&this->position, 0, 0);
        break;
    }
}

#pragma push
#pragma fp_contract on
void TOTrapSeabed01::sub_802C9D38() {
    s32 temp_r3;
    s32 temp_r3_2;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *o = this->target;
        if (o != NULL) {
            temp_r3 = (s32)get_player_by_client_id((get_entity_id(o)));
            if (temp_r3 != 0) {
                if (check_player_flag1__6TLobbyFv() != 0) {
                    TObjPlayer::send_code_45_1(temp_r3);
                }
                obj_clear_flag30_20000((void *)temp_r3);
            }
        }
    } else {
        void *o2 = this->target;
        if ((o2 != NULL) && ((s32) local_client_id == (s32) get_entity_id(o2))) {
        temp_r3_2 = (s32)get_player_by_client_id((local_client_id));
        if ((temp_r3_2 != 0) && (check_player_flag1__6TLobbyFv() != 0)) {
            TObjPlayer::send_code_45_1(temp_r3_2);
        }
        }
    }
}
#pragma pop

}
