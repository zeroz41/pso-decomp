#include "pso/player/TUnk_804B1B80.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/object/TObjMapObject.h"

extern "C" {
u8 is_current_floor_switch_set(u16);
extern const f32 lbl_805DB600;
extern const f32 lbl_805DB604;
extern const f32 lbl_805DB608;
}

void TUnk_804B1B80::check_trigger() {
    switch (trigger_mode) {
    case 0:
        break;
    case 1:
        if (((TObjMapObject *)this)->is_any_player_within_radius_xz(lbl_805DB600) == 1) {
            vfunc_14();
        }
        break;
    case 2:
        if (is_current_floor_switch_set(m_cc) == 1) {
            vfunc_14();
        }
        break;
    }
}

void TUnk_804B1B80::update_trigger() {
    switch (trigger_mode) {
    case 0:
        break;
    case 1:
        if (((TObjMapObject *)this)->is_any_player_within_radius_xz(lbl_805DB604) != 1) {
            vfunc_15();
        }
        break;
    case 2:
        if (is_current_floor_switch_set(m_cc) != 1) {
            vfunc_15();
        }
        break;
    }
    play_persistent_sound(0x4004C10F, (s32)this, (u32)&position, 0, 0);
}

void TUnk_804B1B80::run_task() {
    f32 frame;
    f32 end_frame;

    if (TObjPlayer::check_demo_mode() == 1) {
        vfunc_16();
        return;
    }
    switch (m_ac) {
    case 0:
        check_trigger();
        break;
    case 1:
        update_trigger();
        break;
    }
    m_b0 = (f32) (m_b0 + lbl_805DB608);
    end_frame = animation_end_frame;
    frame = m_b0;
    if (end_frame < frame) {
        m_b0 = (f32) (frame - end_frame);
    }
}
