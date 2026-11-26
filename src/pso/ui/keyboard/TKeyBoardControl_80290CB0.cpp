#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/keyboard/TKeyBoardControl_80290CB0.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/effect/particle/TParticleCtrl.h"

u8 main_menu_scene_active_flag;

void TKeyBoardControl::update_main_menu_scene() {
    set_copy_clear_color_argb(0, 0, 0xFF);
    reset_controller_input_state();
    set_fallback_main_phase(2);
    set_queued_main_phase(6);
    if ((u8) main_menu_scene_active_flag != 0) {
        TKeyBoardControl__sub_80290D10();
        switch_to_fallback_main_phase();
        return;
    }
    init_creation_menu_scene();
    render_tick();
}
void TKeyBoardControl__sub_80290D10(void) { (*(unsigned char *)&main_menu_scene_active_flag) = 0; }

