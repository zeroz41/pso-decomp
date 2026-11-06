#include "types.h"
#include "pso/unk/text_803CC294.h"
#include "pso/item/TItemLoad.h"

extern "C" {

s32 free_texture__9TItemLoadFv();
u32 adxf_open_afs__6TLobbyFii(s32, s32);

u32 TItemLoad::load_data(s32 arg1) {
    u32 temp_r3;
    if ((s32) *(s32 *)&this->m_up == 1) {
        free_texture__9TItemLoadFv();
        *(u32 *)&this->m_flags = adxf_open_afs__6TLobbyFii(*(s32 *)&this->m_prev, arg1);
        temp_r3 = *(u32 *)&this->m_flags;
        if (temp_r3 != 0U) {
            *(s32 *)&this->m_next = TLobby__sub_803CC53C((u8 *)temp_r3);
        }
    }
    return *(u32 *)&this->m_flags;
}

}
