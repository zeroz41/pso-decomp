#include "pso/TAdSelectGameModeGC.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/ui/TAdChrSelPlyPlateGC.h"
#include "pso/ui/TAdSelectGameModeGC_802C4748.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"

TAdSelectGameModeGC::~TAdSelectGameModeGC() {}

#include "types.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TLevelSelect.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_802C47E8_lbl_8050E208 { s32 value; u8 remaining[0x1AC]; };
typedef char RecoveredGlobal_802C47E8_lbl_8050E208_size[sizeof(RecoveredGlobal_802C47E8_lbl_8050E208) == 0x1B0 ? 1 : -1];

struct RecoveredGlobal_802C47E8_lbl_8050E3B8 { s32 value; u8 remaining[0x1AC]; };
typedef char RecoveredGlobal_802C47E8_lbl_8050E3B8_size[sizeof(RecoveredGlobal_802C47E8_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

struct S8_802C4944 { s32 a, b; };

struct S16_802C4944 { S8_802C4944 x[2]; };

struct T12_802C4944 { s32 a, b, c; };

struct S24_802C4944 { T12_802C4944 t[2]; };

extern "C" {
int enable_camera__19TAdSelectGameModeGCFv(void);
s32 free_sub_ctrls__19TAdSelectGameModeGCFv();
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, int, int, int);
extern RecoveredGlobal_802C47E8_lbl_8050E208 controller_input_state;
extern RecoveredGlobal_802C47E8_lbl_8050E3B8 controller_physical_port_bank;
extern s32 TAdSelectGameModeGC__cached_mode_value;
void *__nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *, void *);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void *__ct__14TAdSelectTxtGCFP7TObjectPvPv(void *, void *, void *, int);
void __ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
extern S24_802C4944 select_game_mode_text_layout;
extern S8_802C4944 lbl_80471A44[];
extern S16_802C4944 select_game_mode_button_rect;
extern s32 __vt__19TAdSelectGameModeGC[];
extern void *TAdSelectGameModeGC__name;
extern const f32 lbl_805DE538;
int sync_char_select_state__10TObjPlayerFv(void*);

int fn_802C4748(void* p) { return sync_char_select_state__10TObjPlayerFv(p); }

void TAdSelectGameModeGC::render() {  }

int TAdSelectGameModeGC::call_enable_camera(void* p) { return enable_camera__19TAdSelectGameModeGCFv(); }
void TAdSelectGameModeGC__sub_802C478C(void) {
    s32 mode_data;
    if (get_main_phase() == 0xE) {
        mode_data = TAdSelectGameModeGC::get_mode_data();
        switch (mode_data) {
        case 0:
            ((s32)enable_camera__19TAdSelectGameModeGCFv());
            return;
        case 1:
            ((s32)TAdMultiPlyChrSelectGC__sub_802C6558());
            free_sub_ctrls__19TAdSelectGameModeGCFv();
            return;
        }
    } else {
        enable_camera__19TAdSelectGameModeGCFv();
    }
}
void run_task__19TAdSelectGameModeGCFv(u8 *arg0) {
    s32 mode_data;
    TAdMultiChgGameModeGC::set_default_camera();
    if ((s32) TAdSelectGameModeGC__cached_mode_value != TAdSinglePlyChrSelectGC__sub_801334DC((void *)(*(s32 *)((s8 *)arg0 + 0x1C)))) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x20)))->set_entry_value(1, (int) (get_localized_text_entry(0x15, (s32)(TAdSinglePlyChrSelectGC__sub_801334DC((void *)(*(s32 *)((s8 *)arg0 + 0x1C))) + 1))));
    }
    TAdSelectGameModeGC__cached_mode_value = TAdSinglePlyChrSelectGC__sub_801334DC((void *)(*(s32 *)((s8 *)arg0 + 0x1C)));
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_physical_port_bank.value + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    }
    if (((TAdSinglePlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x1C)))->get_selected_slot() == 1) {
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
u8 *__ct__19TAdSelectGameModeGCFv(u8 *arg0, void *parent) {
    void *p;
    __ct__7TObjectFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TAdSelectGameModeGC;
    *(void * *)&((TAdSelectGameModeGC *)arg0)->m_name = TAdSelectGameModeGC__name;
    TAdSelectGameModeGC__cached_mode_value = 0;
    *(void **)((s8 *)arg0 + 0x1C) = 0;
    *(void **)((s8 *)arg0 + 0x20) = 0;
    if ((p = __nw__7TObjectFUl(0x24)) != 0) {
        __ct__9TAdBackGCFv(p, arg0);
    }
    if ((p = __nw__7TObjectFUl(0x28)) != 0) {
        __ct__12TAdBackTxtGCFv(p, arg0);
    }
    if ((p = __nw__7TObjectFUl(0x24)) != 0) {
        __ct__8TAdRayGCFv(p, arg0);
    }
    if ((p = __nw__7TObjectFUl(0x138)) != 0) {
        __ct__10TAdTitleGCFP7TObjectl(p, arg0, 4);
    }
    if ((p = __nw__7TObjectFUl(0x9C)) != 0) {
        __ct__13TAdTitleTexGCFv(p, arg0);
    }
    {
        S24_802C4944 txt = select_game_mode_text_layout;
        if ((p = __nw__7TObjectFUl(0xE0)) != 0) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, arg0, &txt.t[0], 6);
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != 0) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, arg0, &txt.t[1], 7);
        }
    }
    {
        S8_802C4944 a = lbl_80471A44[0];
        S16_802C4944 b = select_game_mode_button_rect;
        p = __nw__7TObjectFUl(0x708);
        if (p != 0) {
            p = __ct__14TAdSelectCurGCFv(p, arg0, &b, &a);
        }
        *(void **)((s8 *)arg0 + 0x1C) = p;
        ((TLevelSelect *)(*(void **)((s8 *)arg0 + 0x1C)))->add_item_rect(&b.x[0]);
        ((TLevelSelect *)(*(void **)((s8 *)arg0 + 0x1C)))->add_item_rect(&b.x[1]);
    }
    p = __nw__7TObjectFUl(0x44);
    if (p != 0) {
        p = __ct__13TAdGuideTxtGCFv(p, arg0);
    }
    *(void **)((s8 *)arg0 + 0x20) = p;
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x20)))->set_entry_value(0, get_localized_text_entry(0x15, 0));
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x20)))->set_entry_value(1, get_localized_text_entry(0x15, 1));
    create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)arg0, 0xA, (f32)lbl_805DE538);
    return arg0;
}

}
