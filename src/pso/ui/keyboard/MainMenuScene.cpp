#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/main_loop.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/keyboard/MainMenuScene.h"

u8 main_menu_scene_active_flag;

void update_main_menu_scene() {
    set_copy_clear_color_argb(0, 0, 0xFF);
    reset_controller_input_state();
    set_fallback_main_phase(2);
    set_queued_main_phase(6);
    if (main_menu_scene_active_flag != 0) {
        clear_main_menu_scene_flag();
        switch_to_fallback_main_phase();
        return;
    }
    init_creation_menu_scene();
    render_tick();
}
void clear_main_menu_scene_flag() { main_menu_scene_active_flag = 0; }

