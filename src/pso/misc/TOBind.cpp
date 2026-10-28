#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOBind.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"

extern "C" {

s32 TOBind__sub_80158608(void *);

extern s32 quest_mission_manager;

void TOBind::sub_8015860C() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 bc;
    *(f32 *)((s8 *)arg0 + 0xB8) = (f32) (*(f32 *)((s8 *)arg0 + 0xB8) + *(f32 *)&this->unk_C0);
    bc = this->m_bc;
    temp_f0 = *(f32 *)((s8 *)arg0 + 0xB8);
    if (bc < temp_f0) {
        *(f32 *)((s8 *)arg0 + 0xB8) = (f32) (temp_f0 - bc);
    }
}

void TOBind::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        TOBind__sub_80158608(this);
        return;
    }
    if ((s32) this->m_b0 != 1) {
        if (TQuestThread::get_register((u8 *)quest_mission_manager, this->m_b4) != 0) {
            this->m_b0 = 1;
            clear_player_status_flag(0, 1);
        }
        sub_8015860C();
    }
}

}
