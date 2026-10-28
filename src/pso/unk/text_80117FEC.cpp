#include "types.h"
#include "pso/item/TItemProShield.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 get_item_index__5TItemFv();
void TItemProShield::sub_80117FEC() {
    u8 *arg0 = (u8 *)this;
    u8 temp_r3;
    temp_r3 = get_item_index__5TItemFv();
    switch (temp_r3) {
    case 34:
    case 35:
        this->m_19c = (s32) (this->m_19c | 1);
        break;
    case 22:
        ((TObjPlayer *)(arg0 + 0x178))->set_flags(0x80);
        break;
    case 49:
        ((TItemEquipBase *)arg0)->set_equip_flag(0x3A);
        ((TObjPlayer *)(arg0 + 0x178))->set_flags(2);
        this->m_19c = (s32) (this->m_19c | 2);
        break;
    case 48:
        ((TItemEquipBase *)arg0)->set_equip_flag(0x28);
        break;
    case 42:
        this->m_19c = (s32) (this->m_19c | 2);
        break;
    case 50:
        ((TItemEquipBase *)arg0)->set_equip_flag(0x3A);
        this->m_19c = (s32) (this->m_19c | 2);
        break;
    }
    if ((temp_r3 == 0x27) || ((temp_r3 >= 0x33U) && (temp_r3 <= 0x39U)) || ((temp_r3 >= 0x53U) && (temp_r3 <= 0x82U)) || (temp_r3 == 0x52)) {
        ((TItemEquipBase *)arg0)->set_equip_flag(0x22);
        this->m_19c = (s32) (this->m_19c | 2);
    }
    switch ((s32) (*(u8 *)(this->m_18c + 0x1A))) {
    case 1:
        this->m_19c = (s32) (this->m_19c | 4);
        return;
    case 3:
        this->m_19c = (s32) (this->m_19c | 8);
    case 2:
    case 0:
        return;
    }
}

}
