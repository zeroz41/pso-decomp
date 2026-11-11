#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TEffect.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/render/BlobShadow.h"

struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

extern "C" {
s32 disable_disconnected_ports__16TKeyBoardControlFv(void *);
int clear_split_screen_fog__8TFogCtrlFv(void*);
}
extern RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 TKeyBoardControl__global_key_state;
void update_music_sequencer(void);
extern "C" {
void update_global_sound_frame(void);
void TObjPlayer__sub_80083FB0(void);

extern s32 lbl_805D62B0;

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
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
