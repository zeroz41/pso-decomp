#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneBalClawBody.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneBalClaw.h"
#include "pso/enemy/TObjEneMe1GiGue.h"

extern "C" {

s32 TObjEneBalClawClaw__sub_8008DC90(void *);
void TObjEneBalClaw__sub_8008D68C(void);
s32 TObjEneMe1GiGue__sub_8008FC0C(void *);
s32 submit_cursor_candidate(void *, int, int, f32, f32);
s32 minimap_render_dot(void *, int, int, int);

void TObjPlayer::update_control_state() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f2;
    u8 *temp_r5;

    TObjEneBalClaw__sub_8008D68C();
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjEneBalClawClaw__sub_8008DC90(arg0);
        TObjEneMe1GiGue__sub_8008FC0C(arg0);
        return;
    }
    if ((*(s32 *)&this->unk_388 & 0x02000000) && (((TObjPlayer *)arg0)->get_flag_0x388_b24() == 0)) {
        ((TObjEneMe1GiGue *)arg0)->update_if_active(2);
    } else {
        ((TObjEneBalClawBody *)arg0)->sub_8008FC10();
    }
    if ((s16) this->mode != (s32) *(s32 *)&this->m_374) {
        if ((s32) this->m_37c != -1) {
            this->m_37c = -1;
            ((TObjEneBalClawBody *)arg0)->sub_8008FF50();
        }
        this->mode = (s16) *(s32 *)&this->m_374;
        this->m_37c = 0;
    }
    ((TObjEneBalClawBody *)arg0)->sub_8008FF50();
    ((TObjEneBalClaw *)arg0)->update_wobble();
    ((TObjEneBalClaw *)arg0)->update_claw_angle();
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    temp_f2 = *(f32 *)&this->m_300;
    *(f32 *)&this->m_300 = (f32) (temp_f2 + (*(f32 *)&this->m_3b4 + *(f32 *)&this->m_3bc));
    temp_f1 = *(f32 *)&this->m_3b4;
    temp_r5 = (unsigned char *) (*(void * *)&this->bodies);
    *(f32 *)((s8 *)temp_r5 + 4) = (f32) (temp_f1 + *(f32 *)&this->m_3bc);
    submit_cursor_candidate((void *)arg0, -1, (int)temp_r5, (f32)temp_f1, (f32)temp_f2);
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

}
