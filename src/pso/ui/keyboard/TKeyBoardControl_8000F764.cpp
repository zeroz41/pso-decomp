#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 disable_disconnected_ports__16TKeyBoardControlFv(void *);
int clear_split_screen_fog__8TFogCtrlFv(void*);
}
void update_music_sequencer(void);
extern "C" {
void TObjPlayer__sub_80083FB0(void);

extern s32 lbl_805D62B0;

void TKeyBoardControl__sub_8000F764(void) {
    TKeyBoardControl::read_pads();
    disable_disconnected_ports__16TKeyBoardControlFv(&TKeyBoardControl__global_key_state.value);
    TKeyBoardControl::flush_input();
    update_pad_rumble();
    TLobby::reset_state_byte();
}

void TKeyBoardControl::run_tasks() {
    TObjPlayer__sub_80083FB0();
    update_global_sound_frame();
    if ((s32) lbl_805D62B0 != 0) {
        update_music_sequencer();
    }
    keyboard_task_object.run_tasks();
}

int TKeyBoardControl::get_fog_ctrl() { return clear_split_screen_fog__8TFogCtrlFv(this); }

void TKeyBoardControl__sub_8000F7FC(void) {
    end_of_render_root.run_tasks();
}

}
