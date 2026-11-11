#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/keyboard/TKeyBoardControl_80290CB0.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"

extern "C" {
extern u8 main_menu_scene_active_flag;
s32 set_copy_clear_color_argb(s32, s32, s32);

void TKeyBoardControl::update_main_menu_scene() {
    set_copy_clear_color_argb(0, 0, 0xFF);
    reset_controller_input_state();
    TKeyBoardControl__sub_8000F90C(2);
    TKeyBoardControl__sub_8000F91C(6);
    if ((u8) main_menu_scene_active_flag != 0) {
        TKeyBoardControl__sub_80290D10();
        TKeyBoardControl__sub_8000F92C();
        return;
    }
    init_creation_menu_scene();
    render_tick();
}
void TKeyBoardControl__sub_80290D10(void) { (*(unsigned char *)&main_menu_scene_active_flag) = 0; }

}
