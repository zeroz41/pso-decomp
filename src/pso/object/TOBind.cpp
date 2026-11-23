#include "pso/unk/TUnk_804C8678.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TOBind.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"

extern "C" {

s32 TOBind__sub_80158608(void *);


void TOBind::sub_8015860C() {
    f32 temp_f0;
    f32 bc;
    motion_frame += motion_step;
    bc = this->m_bc;
    temp_f0 = motion_frame;
    if (bc < temp_f0) {
        motion_frame = temp_f0 - bc;
    }
}

void TOBind::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        TOBind__sub_80158608(this);
        return;
    }
    if ((s32) this->m_b0 != 1) {
        if (TQuestThread::get_register(quest_mission_manager, this->index) != 0) {
            this->m_b0 = 1;
            clear_player_status_flag(0, 1);
        }
        sub_8015860C();
    }
}

}
