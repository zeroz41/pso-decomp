#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TODoorBase.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 is_current_floor_switch_set(int);
s32 minimap_render_gate(void *, u32, u16, s32, s32);
extern s32 switch_doors_force_closed;
void TODoorBase::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s32 cc;
    cc = this->lock_mode;
    switch (cc) {
    case 1:
        ((TODoorBase *)arg0)->play_door_sound();
        this->door_flags = (s32) (this->door_flags | 1);
        return;
    case 2:
        if (is_current_floor_switch_set((int) ((u16) this->switch_id)) == 1) {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags = (s32) (this->door_flags | 1);
            return;
        }
        this->door_flags = (s32) (this->door_flags & 0xFFFFFFFE);
        return;
    case 3:
        if (is_current_floor_switch_set((int) ((u16) this->switch_id)) == 1) {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags = (s32) (this->door_flags | 1);
        }
        break;
    default:
        this->door_flags = (s32) (this->door_flags & 0xFFFFFFFE);
        break;
    }
}
void TODoorBase::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        this->update_demo();
        return;
    }
    if ((s32) switch_doors_force_closed != 0) {
        this->m_ac = 0;
        this->door_flags = (s32) (this->door_flags & 0xFFFFFFFE);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    } else {
        this->update_door_switch_state();
    }
    switch (this->m_ac) {
    case 0:
        this->update_closed();
        break;
    case 1:
        this->update_opening();
        break;
    case 2:
        this->update_open();
        break;
    case 3:
        this->update_closing();
        break;
    }
    if (this->door_flags & 1) {
        minimap_render_gate((u8 *)&this->position, 0xFF00FF00, this->rotation_y, 0, 0);
    } else {
        minimap_render_gate((u8 *)&this->position, 0xFFFF0000, this->rotation_y, 0, 0);
    }
}

}
