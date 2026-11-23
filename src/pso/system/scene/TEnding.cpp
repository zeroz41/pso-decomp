#include "pso/unk/TScreenFadeOut.h"
#include "pso/system/scene/TEnding.h"
#include "pso/map/FloorArea.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/system/scene/TEndingAB.h"
#include "pso/system/scene/TEndingPic.h"
#include "pso/system/scene/TEndingC_8008D00C.h"
#include "pso/system/scene/TEndingC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"
#include "pso/ui/frontend/TAdEndText.h"

u32 ending_frame_counter;

extern "C" {
s32 get_end_text_font_loaded_flag();
u32 __cvt_fp2unsigned(f32);
int TKeyBoardControl__sub_8000F828(void);
s32 ending_scene_active;
extern const char TEnding__class_name_string[];
const char *TEnding__class_name = TEnding__class_name_string;
}

void TEnding::run_task() {
    switch (phase) {
    case 0: {
        TAdMultiChgGameModeGC::set_default_camera();
        u32 ticks = ending_frame_counter + 1;
        ending_frame_counter = ticks;
        s32 rate = timing_rate;
        if (ticks > (u32)(rate * 140)) {
            new TEndingPicStage(this);
            phase = 1;
            return;
        }
        f32 duration = 2.0f * (f32)rate;
        if (ending_frame_counter > (u32)((rate * 139) - __cvt_fp2unsigned(duration)))
            ring_controller->sub_8001B4A0(duration);
        return;
    }
    case 2:
        break;
    case 1:
        if (get_end_text_font_loaded_flag() != 0) {
            s32 ticks = elapsed_ticks + 1;
            elapsed_ticks = ticks;
            if (ticks > timing_rate * 10) {
                new TScreenFadeOut(tl_fade, destroy_keyboard_objects);
                phase = 2;
            }
        }
        break;
    }
}

TEnding::~TEnding() {
    ending_scene_active = 0;
    TLobby::stop_audio_streams();
}

TEnding::TEnding() : TObject(tl_window) {
    m_name = TEnding__class_name;
    TEnding__sub_8008C9F8();
    TMainTask::cleanup_game_objects();
    set_current_floor_area(1);
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0: timing_rate = 30; break;
    case 1: timing_rate = 25; break;
    }
    new TEndingPic(tl_01);
    new TEndingAB(this);
    new TEndingC(this);
    ending_frame_counter = 0;
    phase = 0;
    elapsed_ticks = 0;
    TAdRicoRingCtrl *ring = new TAdRicoRingCtrl(this);
    ring_controller = ring;
    if (ring_controller != NULL)
        ring_controller->start_fade_all(2.0f * (f32)timing_rate);
    new TAdEndText(this);
}

void TEnding__sub_8008C9F8() {}
