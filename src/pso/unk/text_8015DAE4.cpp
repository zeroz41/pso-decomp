#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 is_current_floor_switch_set(int);
s32 minimap_render_gate(void *, u32, u16, s32, s32);
extern s32 switch_doors_force_closed;
void TUnk_804B0BB8::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s32 cc;
    cc = this->m_cc;
    switch (cc) {
    case 1:
        ((TUnk_804B0BB8 *)arg0)->play_door_sound();
        this->m_d0 = (s32) (this->m_d0 | 1);
        return;
    case 2:
        if (is_current_floor_switch_set((int) ((u16) this->m_c8)) == 1) {
            ((TUnk_804B0BB8 *)arg0)->play_door_sound();
            this->m_d0 = (s32) (this->m_d0 | 1);
            return;
        }
        this->m_d0 = (s32) (this->m_d0 & 0xFFFFFFFE);
        return;
    case 3:
        if (is_current_floor_switch_set((int) ((u16) this->m_c8)) == 1) {
            ((TUnk_804B0BB8 *)arg0)->play_door_sound();
            this->m_d0 = (s32) (this->m_d0 | 1);
        }
        break;
    default:
        this->m_d0 = (s32) (this->m_d0 & 0xFFFFFFFE);
        break;
    }
}
void TUnk_804B0BB8::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_20();
        return;
    }
    if ((s32) switch_doors_force_closed != 0) {
        this->m_ac = 0;
        this->m_d0 = (s32) (this->m_d0 & 0xFFFFFFFE);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    } else {
        this->update_door_switch_state();
    }
    switch (this->m_ac) {
    case 0:
        this->play_proximity_sound();
        break;
    case 1:
        this->vfunc_16();
        break;
    case 2:
        this->vfunc_17();
        break;
    case 3:
        this->vfunc_18();
        break;
    }
    if (this->m_d0 & 1) {
        minimap_render_gate((u8 *)&this->position, 0xFF00FF00, this->rotation_y, 0, 0);
    } else {
        minimap_render_gate((u8 *)&this->position, 0xFFFF0000, this->rotation_y, 0, 0);
    }
}

}
