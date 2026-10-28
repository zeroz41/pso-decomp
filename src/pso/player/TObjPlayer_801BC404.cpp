#include "types.h"
#include "pso/player/TObjPlayer_801BC404.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TLevelSelect.h"
#include "pso/misc/TLobby.h"

extern "C" {

s32 check_camera_mode__10TObjPlayerFv();
void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_801BEEE0(void *p, void *q);
void TObjPlayer__sub_801BEF30(void *p, void *q);

s32 TObjPlayer::has_active_camera_event() {
    if (TLobby::get_instance() == 0) {
        if ((check_camera_mode__10TObjPlayerFv() == 0) && (TLevelSelect::get_difficulty_flag_bit(0, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(1, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(2, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(3, 0xB) == 0)) {
            return 0;
        }
        goto block_14;
    }
    if ((TLobby::get_instance() == 1) && (check_camera_mode__10TObjPlayerFv() == 0) && (TLevelSelect::get_difficulty_flag_bit(0, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(1, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(2, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(3, 0x5B) == 0)) {
        return 0;
    }
block_14:
    return 1;
}
void TObjPlayer__sub_801BC504(void) {  }
void TObjPlayer::init_from_data(void* a1) { init_action_provider(); *(short *)&this->entity_id = *(unsigned short*)(a1); *(short*)((char*)this + 0x2e) = *(short*)((char*)a1 + 0x2); *(void* *)&this->actorFlags = *(void**)((char*)a1 + 0x4); ((TObjPlayer *)((char*)this + 0x5c))->copy_xyz((char*)a1 + 0x14); *(short *)&this->mode = *(short*)((char*)a1 + 0x20); *(short *)&this->hp = *(short*)((char*)a1 + 0x22); ((TLobby *)((char*)this + 0xdac))->copy_header_struct((char*)a1 + 0x68); TObjPlayer__sub_801BEF30((void *)((char*)this + 0x828), (void *)((char*)a1 + 0x70)); ((TObjPlayer *)((char*)this + 0x830))->copy_player_record_header((u8 *)((char*)a1 + 0x78)); TObjPlayer__sub_801BEEE0((void *)((char*)this + 0x858), (void *)((char*)a1 + 0x94)); TObjPlayer__sub_801BEEAC((u8 *)((char*)this + 0x730), (u8 *)((char*)a1 + 0x98)); set_floor_index((s32)(*(void**)((char*)a1 + 0xac))); set_floor((s32)(*(void**)((char*)a1 + 0x488))); *(void* *)&this->m_334 = *(void**)((char*)a1 + 0xb0); set_play_time((s32)(*(void**)((char*)a1 + 0x64))); }

}
