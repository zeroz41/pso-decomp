#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TPlyCharData.h"
#include "pso/player/TObjPlayer_801BE1C0.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int is_quest_active(void);
int subtract_photon_blast_charge(void*);
int add_photon_blast_chain_charge(void*);
int set__8FlagWordFUl(void*, int);

s32 destroy_char_data__10TObjPlayerFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__12TPlyCharDataFv(arg0 + 0xC, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

void TObjPlayer::get_pos(s32 arg1) {
    this->get_anim_node_position(0x3A, (Vec *)arg1);
}

void TObjPlayer::vfunc_76() { subtract_photon_blast_charge((char*)this + 0x4ac); }

void TObjPlayer::vfunc_77() { add_photon_blast_chain_charge((char*)this + 0x4ac); }

int TObjPlayer__vt77(void) { return 0; }
u8 TObjPlayer::check_camera_mode() {
    return (u8) (is_quest_active() == 1);
}
void TObjPlayer__sub_801BE2C0(void* p, s32 v) { *(s32*)((char*)p + 0x370) = v; }
s32 TObjPlayer__sub_801BE2C8(void* p) { return *(s32*)((char*)p + 0x370); }
int TObjPlayer::is_newman() { return (this->class_flags & CLASS_FLAG_NEWMAN) != 0; }
int TObjPlayer::is_android() { return (this->class_flags & CLASS_FLAG_ANDROID) != 0; }
int TObjPlayer::check_stat_flag_41c() { return set__8FlagWordFUl((char*)this + 0x41c, 32); }
int TObjPlayer::check_flag_at_41c() { return set__8FlagWordFUl((char*)this + 0x41c, 4); }
int TObjPlayer::set_flag_41c_bit1() { return set__8FlagWordFUl((char*)this + 0x41c, 2); }
int TObjPlayer::clamp_stat_41c() { return set__8FlagWordFUl((char*)this + 0x41c, 8); }

}
