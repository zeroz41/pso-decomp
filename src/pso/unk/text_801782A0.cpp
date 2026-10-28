#include "types.h"
#include "pso/misc/TOSwitchTimer.h"

extern "C" {
u8 is_current_floor_switch_set(u16 id);
s32 get_current_floor(void);
}

void TOSwitchTimer::sub_801782A0() {
    s32 i;
    u16 *ids;

    this->m_90 = 0;
    this->m_94 = 0;
    this->m_98 = (u32)this->rotation_x;
    if (this->m_98 >= 2) {
        this->m_98 = 1;
    }
    this->m_9c = this->rotation_y;
    if ((s32)this->m_9c > 1) {
        this->m_9c = 0;
    }
    this->m_a0 = this->rotation_z;
    if ((s32)this->m_a0 < 0) {
        this->m_a0 = 0;
    }
    this->m_a4 = (s32)this->m_a0 * 3 / 4;
    this->m_a8 = this->set_params[0];
    if (this->m_a8 < 0x100) {
        this->m_b0 = is_current_floor_switch_set(this->m_a8);
    } else {
        this->m_a8 = 0xFFFF;
        this->m_b0 = 0;
    }
    ids = (u16 *)((u8 *)this + 0xAA);
    for (i = 0; i < 3; i++) {
        *ids = *(u32 *)((u8 *)this + 0x84 + i * 4) >> 16;
        if (*ids >= 0x100) {
            *ids = 0xFFFF;
        }
        ids++;
    }
    this->m_b4 = get_current_floor();
}
