#include "pso/misc/TEnding.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TEndingPicStage.h"
#include "pso/misc/ParticleRadial.h"
#include "pso/misc/TEndingAB_8008CE08.h"
#include "pso/misc/TEndingC_8008D00C.h"
#include "pso/misc/TMainTask_80104C40.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdRicoRingCtrl.h"

extern "C" {
void TAdRicoRingCtrl__sub_8001B4A0(TAdRicoRingCtrl *, f32);
s32 get_end_text_font_loaded_flag();
u32 __cvt_fp2unsigned(f32);
int TKeyBoardControl__sub_8000F828(void);
u8 *__ct__10TEndingPicFv(u8 *arg0, u8 *arg1);
u8 *TAdRicoRingCtrl__ct(TAdRicoRingCtrl *arg0, s32 arg1);
void __ct__10TAdEndTextFv(void *, TObject *);
extern u32 ending_frame_counter;
extern s32 ending_scene_active;
extern TObject *tl_fade;
extern TObject *tl_window;
extern TObject *tl_01;
extern const char *TEnding__class_name;
extern const f32 lbl_805D9578;
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
        f32 duration = lbl_805D9578 * (f32)rate;
        if (ending_frame_counter > (u32)((rate * 139) - __cvt_fp2unsigned(duration)))
            TAdRicoRingCtrl__sub_8001B4A0(ring_controller, duration);
        return;
    }
    case 2:
        break;
    case 1:
        if (get_end_text_font_loaded_flag() != 0) {
            s32 ticks = elapsed_ticks + 1;
            elapsed_ticks = ticks;
            if (ticks > timing_rate * 10) {
                void *child = TObject::operator new(0x28);
                if (child != NULL)
                    ((THunterGuildSeqOffline *)child)->init(tl_fade, (void *)destroy_keyboard_objects);
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
    cleanup_game_objects__9TMainTaskFv();
    set_current_floor_area(1);
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0: timing_rate = 30; break;
    case 1: timing_rate = 25; break;
    }
    void *picture = TObject::operator new(0xF0);
    if (picture != NULL) __ct__10TEndingPicFv((u8 *)picture, (u8 *)tl_01);
    void *first = TObject::operator new(0xF0);
    if (first != NULL) __ct__9TEndingABFv((u8 *)first, (u8 *)this);
    void *second = TObject::operator new(0x9C);
    if (second != NULL) __ct__8TEndingCFv((u8 *)second, (u8 *)this);
    ending_frame_counter = 0;
    phase = 0;
    elapsed_ticks = 0;
    TAdRicoRingCtrl *ring = (TAdRicoRingCtrl *)TObject::operator new(0x2C);
    if (ring != NULL) ring = (TAdRicoRingCtrl *)TAdRicoRingCtrl__ct((TAdRicoRingCtrl *)((u8 *)ring), (s32)this);
    ring_controller = ring;
    if (ring_controller != NULL)
        ((TAdRicoRingCtrl *)ring_controller)->start_fade_all(lbl_805D9578 * (f32)timing_rate);
    void *text = TObject::operator new(0x197C);
    if (text != NULL) __ct__10TAdEndTextFv(text, this);
}

void TEnding__sub_8008C9F8() {}
