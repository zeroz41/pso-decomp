#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/TAdLdQuestPrtGC.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/text_80086E28.h"

extern "C" {
int ansi_fp_abs(int x);
s32 TWindowShortListCtrl__check_controller_button(ControllerInputContext *context, s32 button);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(ControllerInputContext *context, s32 button);
}

// Camera position (0..2) and forward axis (3..5).
extern f32 lbl_804FF5E8[10];
// ARGB tints the button cycles through.
const u32 lbl_80476610[6] = {
    0xFF77FF3F, 0xFF333377, 0xFFB31A77, 0xFFB31A1A, 0xFFFF4D1A, 0xFFB34D00,
};
#pragma readonly_strings on
const char *TAdLdQuestPrtGC__class_name = "TAdLdQuestPrtGC";

void TAdLdQuestPrtGC::render() {
}

void TAdLdQuestPrtGC::run_task() {
    u32 i;
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 4) != 0 ||
        test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state.keyboard, 4) != 0) {
        tint_timer = 0;
        tint_index++;
        if (tint_index >= 6) {
            tint_index = 0;
        }
    }
    s32 stick_x = controller_physical_port_bank.controllers[0].stick_x;
    s32 stick_y = controller_physical_port_bank.controllers[0].stick_y;
    if (get_abs(stick_x) > 0 || get_abs(stick_y) > 0) {
        static f32 scale = 0.02f;
        s32 dx = stick_x * scale;
        s32 dy = stick_y * scale;
        angle_speed[0].x = (s32)(182.04445f * -dx) / 5;
        angle_speed[0].z = (s32)(182.04445f * -dy) / 5;
        angle_speed[1].x = (s32)(182.04445f * (-dx * 2)) / 4;
        angle_speed[1].z = (s32)(182.04445f * (-dy * 2)) / 3;
        angle_speed[2].x = (s32)(182.04445f * -dy) / 2;
        angle_speed[2].z = (s32)(182.04445f * dx) / 6;
        particle_angles[0].x += angle_speed[0].x;
        particle_angles[1].x += angle_speed[1].x;
        particle_angles[2].x += angle_speed[2].x;
        particle_angles[3].x += angle_speed[3].x;
    }
    particle_angles[0].z += angle_speed[0].z;
    particle_angles[1].z += angle_speed[1].z;
    particle_angles[2].z += angle_speed[2].z;
    particle_angles[3].z += angle_speed[3].z;
    for (i = 0; i < 4; i++) {
        if (particles[i] != NULL) {
            particles[i]->set_direction(&particle_angles[i]);
            particles[i]->set_tint_color(lbl_80476610[tint_index]);
        }
    }
    tint_timer++;
    tint_timer = tint_timer > 12 ? 12 : tint_timer;
    frame_count++;
}

TAdLdQuestPrtGC::~TAdLdQuestPrtGC() {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (particles[i] != NULL) {
            particles[i]->queue_destruction();
            particles[i] = NULL;
        }
    }
}

#pragma push
#pragma fp_contract on
TAdLdQuestPrtGC::TAdLdQuestPrtGC(TObject *parent) : TObject(parent) {
    u32 i;
    m_name = TAdLdQuestPrtGC__class_name;
    tint_index = 0;
    tint_timer = 0;
    frame_count = 0;
    for (i = 0; i < 4; i++) {
        tints[i].a = (u8)(lbl_80476610[0] >> 24);
        tints[i].r = (u8)(lbl_80476610[0] >> 16);
        tints[i].g = (u8)(lbl_80476610[0] >> 8);
        tints[i].b = (u8)lbl_80476610[0];
        particle_pos[i].x = lbl_804FF5E8[0] + 100.0f * lbl_804FF5E8[3] - 11.0f;
        particle_pos[i].y = lbl_804FF5E8[1] + 100.0f * lbl_804FF5E8[4];
        particle_pos[i].z = lbl_804FF5E8[2] + 100.0f * lbl_804FF5E8[5];
        particle_angles[i].x = i * 0xAAA;
        particle_angles[i].y = 0;
        particle_angles[i].z = i * 0xAAA;
        particles[i] = (TParticleCtrl *)create_particle_controller_with_angles(&particle_pos[i], &particle_angles[i], 0x1B, 1, 0x800);
    }
    angle_speed[0].x = 0;
    angle_speed[0].z = 91;
    angle_speed[1].x = 0;
    angle_speed[1].z = -91;
    angle_speed[2].x = 0;
    angle_speed[2].z = 182;
    angle_speed[3].x = 0;
    angle_speed[3].z = -91;
}
#pragma pop

int TAdLdQuestPrtGC::get_abs(int value) {
    return ansi_fp_abs(value);
}
