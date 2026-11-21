#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"

#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/task/TObject.h"


struct S8_802C4944 { f32 a, b; };

struct S16_802C4944 { S8_802C4944 x[2]; };

struct S24_802C4944 { TAdSelectTxtLayout t[2]; };

const char *TAdSelectGameModeGC__name = "TAdSelectGameModeGC";
const S24_802C4944 select_game_mode_text_layout = {{{-1, 208.0f, 197.0f}, {-1, 178.0f, 249.0f}}};
const S8_802C4944 lbl_80471A44 = {302.0f, 28.0f};
const S16_802C4944 select_game_mode_button_rect = {{{185.0f, 198.0f}, {155.0f, 250.0f}}};

s32 TAdSelectGameModeGC__cached_mode_value;
extern "C" {

s32 free_sub_ctrls__19TAdSelectGameModeGCFv();
s32 play_sound_effect(int, int, int, int);
void __ct__7TObjectFP7TObject(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void __ct__13TAdTitleTexGCFv(void *, void *);
extern s32 __vt__19TAdSelectGameModeGC[];
int sync_char_select_state__10TObjPlayerFv(void*);

int fn_802C4748(void* p) { return sync_char_select_state__10TObjPlayerFv(p); }

void TAdSelectGameModeGC::render() {  }

void TAdSelectGameModeGC::call_enable_camera(void* p) { TAdSelectGameModeGC::enable_camera(); }
void TAdSelectGameModeGC__sub_802C478C(void) {
    s32 mode_data;
    if (get_main_phase() == 0xE) {
        mode_data = TAdSelectGameModeGC::get_mode_data();
        switch (mode_data) {
        case 0:
            TAdSelectGameModeGC::enable_camera();
            return;
        case 1:
            ((s32)TAdMultiPlyChrSelectGC__sub_802C6558());
            free_sub_ctrls__19TAdSelectGameModeGCFv();
            return;
        }
    } else {
        TAdSelectGameModeGC::enable_camera();
    }
}
void run_task__19TAdSelectGameModeGCFv(u8 *arg0) {
    s32 mode_data;
    TAdMultiChgGameModeGC::set_default_camera();
    if ((s32) TAdSelectGameModeGC__cached_mode_value != reinterpret_cast<TAdSelectCurGC *>((*(saddr *)((s8 *)arg0 + 0x1C)))->selection_index()) {
        ((TAdGuideTxtGC *)(*(saddr *)((s8 *)arg0 + 0x20)))->set_line(1, reinterpret_cast<const char *>((get_localized_text_entry(0x15, (s32)(reinterpret_cast<TAdSelectCurGC *>((*(saddr *)((s8 *)arg0 + 0x1C)))->selection_index() + 1)))));
    }
    TAdSelectGameModeGC__cached_mode_value = reinterpret_cast<TAdSelectCurGC *>((*(saddr *)((s8 *)arg0 + 0x1C)))->selection_index();
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_physical_port_bank + 0x20), 2) != 0) || (test_controller_flag_4c_color((void *) ((u8 *)&controller_input_state + 0x160), 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    }
    if (((TAdSelectCurGC *)(*(saddr *)((s8 *)arg0 + 0x1C)))->confirmation_result() == 1) {
        mode_data = TAdSelectGameModeGC::get_mode_data();
        switch (mode_data) {
        case 0:
            TAdMultiChgGameModeGC::set_game_mode();
            return;
        case 1:
            TAdMultiChgGameModeGC::set_change_game_mode();
            break;
        }
    }
}
TAdSelectGameModeGC::~TAdSelectGameModeGC() {}

u8 *__ct__19TAdSelectGameModeGCFv(u8 *arg0, void *parent) {
    void *p;
    __ct__7TObjectFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TAdSelectGameModeGC;
    ((TAdSelectGameModeGC *)arg0)->m_name = TAdSelectGameModeGC__name;
    TAdSelectGameModeGC__cached_mode_value = 0;
    *(void **)((s8 *)arg0 + 0x1C) = 0;
    *(void **)((s8 *)arg0 + 0x20) = 0;
    new TAdBackGC((TObject *)arg0);
    new TAdBackTxtGC((TObject *)arg0);
    if ((p = TObject::operator new(0x24)) != 0) {
        __ct__8TAdRayGCFv(p, arg0);
    }
    if ((p = TObject::operator new(0x138)) != 0) {
        __ct__10TAdTitleGCFP7TObjectl(p, arg0, 4);
    }
    if ((p = TObject::operator new(0x9C)) != 0) {
        __ct__13TAdTitleTexGCFv(p, arg0);
    }
    {
        S24_802C4944 txt = select_game_mode_text_layout;
        new TAdSelectTxtGC((TObject *)arg0, &txt.t[0], 6);
        new TAdSelectTxtGC((TObject *)arg0, &txt.t[1], 7);
    }
    {
        S8_802C4944 a = lbl_80471A44;
        S16_802C4944 b = select_game_mode_button_rect;
        p = new TAdSelectCurGC(reinterpret_cast<TObject *>(arg0),
            reinterpret_cast<const NJS_POINT2 *>(&b),
            reinterpret_cast<const NJS_POINT2 *>(&a));
        *(void **)((s8 *)arg0 + 0x1C) = p;
        ((TAdSelectCurGC *)(*(void **)((s8 *)arg0 + 0x1C)))->append_entry(&b.x[0]);
        ((TAdSelectCurGC *)(*(void **)((s8 *)arg0 + 0x1C)))->append_entry(&b.x[1]);
    }
    p = new TAdGuideTxtGC(reinterpret_cast<TObject *>(arg0));
    *(void **)((s8 *)arg0 + 0x20) = p;
    ((TAdGuideTxtGC *)(*(saddr *)((s8 *)arg0 + 0x20)))->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x15, 0)));
    ((TAdGuideTxtGC *)(*(saddr *)((s8 *)arg0 + 0x20)))->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x15, 1)));
    create_draw_line_ctrl((TObject *)arg0, 0xA, 0.0f);
    return arg0;
}

}
