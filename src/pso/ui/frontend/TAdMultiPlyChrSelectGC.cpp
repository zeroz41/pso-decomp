#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DBCC4.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DC3D4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DC760.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/text_802A1144.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DCD14.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DD8E0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DE094.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0064.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DEC44.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DEF54.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInputState.h"
#include <stdio.h>
#include <string.h>
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"


extern "C" {
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 create_window_menu_default(void *, int);
extern s32 lbl_804728A8[];
extern s32 lbl_804728A0[];
extern s32 lbl_80472890[];
extern u8 lbl_80472898[];
extern u8 player_number_text_buffer[];
s32 TAdMultiPlyChrSelectGC__sub_802DC294(TAdMultiPlyChrSelectGC *arg0, s32 arg1);
}

s32 is_multiplayer_character_slot_selected(s32 arg0);
extern "C" {
s32 TAdMultiPlyChrSelectGC__sub_802C6558();
s32 TAdMultiPlyChrSelectGC__sub_802C658C(s32 arg0);
}

u8 player_number_text_buffer[0x80];
extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *);
extern s8 lbl_80472880[];
extern s8 lbl_80472888[];
}

struct Ent_802DC8A0 { u8 d[0x50]; };

struct Pair_802DC8A0 { u8 d[8]; };

extern "C" {
extern NJS_POINT2 multi_chr_select_item_rect_table[];
}

struct Obj_802DCCA4 { u8 pad[0x2C]; s32 f2C; };

extern "C" {
void TAdMultiPlyChrSelectGC__sub_802DCCA4(Obj_802DCCA4 *arg0);
s32 TAdPlyPltAnimCtrlGC__sub_80355148();
void create_effects__14TAdGameStartGCFPv(u8 *parent);
}

s32 is_multiplayer_character_slot_selected(s32);
extern "C" {
extern s32 lbl_80472870[];
extern s32 lbl_80472878[];
extern s32 lbl_80472868[];
}

struct Stack_802DDF40 {
    s32 sp8;
    s32 spC;
};

extern "C" {
saddr TAdMultiPlyChrSelectGC__sub_802C6920(void);
s32 is_slot_state_one__16TAdChrSelBSlotGCFlUl(s32, s32);
u32 __ct__9TAdFadeGCFP7TObjectPv(u32, TObject *, s32);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
void load_tables(int a0);
extern s32 lbl_80472860[];
}

struct Stack_802DE7D0 {
    s32 sp8;
    s32 spC;
};

extern "C" {
s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 i);
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
void TAdMultiPlyChrSelectGC__sub_802C561C(TAdChrSelPlyPlateGC *);
void TAdMultiPlyChrSelectGC__sub_802C5688(TAdChrSelPlyPlateGC *);
s32 TAdChrSelASlotGC__sub_8030C3C0(TAdChrSelASlotGC *self, u32 i);
s32 TAdChrSelASlotGC__sub_8030CA84(s32 arg0, s32 arg1);
extern s32 lbl_80472850[];
extern s32 lbl_80472858[];
s32 destroy_windows__14TAdGameStartGCFPv(s32);
void clear_slot_body__23TAdSinglePlyChrSelectGCFi(s32 i);
struct MultiPlayChrSelectSlotPositions { s32 value; u8 remaining[0x14]; };

extern MultiPlayChrSelectSlotPositions multi_play_chr_select_slot_positions;
s32 TAdMultiPlyChrSelectGC__sub_802C6848(s32);
}

struct I2_802DF9B4 { s32 a, b; };

struct Blk_802DF9B4 { NJS_POINT2 a, b, c; };

extern "C" {
u32 __ct__13TAdTitleTexGCFv(void *, void *);
u32 __ct__14TAdGameStartGCFv(void *, TObject *);
extern NJS_POINT2 multi_chr_select_widget_layout[];
extern u8 lbl_80472808[];
extern I2_802DF9B4 lbl_80472828[];
extern Blk_802DF9B4 multi_chr_select_layout_table[];
extern NJS_POINT2 lbl_80472848[];
struct C_802DF114 {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[0x14];
    s32 f3C;
    s32 f40;
    u8 pad44[4];
    s32 f48;
    s32 f4C;
    u8 pad50[0x14];
    uaddr f64;
};

typedef void (C_802DF114::*Pmf_802DF114)();

extern "C" void update_idle_timer__22TAdMultiPlyChrSelectGCFv();
extern "C" void reset_to_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void check_cancel_input__22TAdMultiPlyChrSelectGCFv();
extern "C" void close_and_reset__22TAdMultiPlyChrSelectGCFv();
extern "C" void close_windows__22TAdMultiPlyChrSelectGCFv();
extern "C" void handle_cancel_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void handle_confirm_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void handle_input__22TAdMultiPlyChrSelectGCFv();
extern "C" void init_windows__22TAdMultiPlyChrSelectGCFv();
extern "C" void open_char_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void request_scene_change__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_button_input__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_card_confirm__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_card_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_card_select_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_confirm_start__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_input_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state_move__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state_option__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state_wait_card__22TAdMultiPlyChrSelectGCFv();
void *lbl_804E2B90[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_serial__22TAdMultiPlyChrSelectGCFPv,
};

void *lbl_804E2B9C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DEDA8,
};

void *lbl_804E2BA8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_button_input__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2BB4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DE7D0,
};

void *lbl_804E2BC0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_confirm__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2BCC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_option__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2BD8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_select__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2BE4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update__22TAdMultiPlyChrSelectGCFPv,
};

void *lbl_804E2BF0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&close_windows__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2BFC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&open_char_select__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C08[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&init_windows__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C14[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_to_select__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C20[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DDD08,
};

void *lbl_804E2C2C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DDBA8,
};

void *lbl_804E2C38[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_select__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C44[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_wait_card__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C50[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_select_state__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C5C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C68[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DD400,
};

void *lbl_804E2C74[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&handle_confirm_state__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C80[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DD2B0,
};

void *lbl_804E2C8C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_move__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2C98[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DD010,
};

void *lbl_804E2CA4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCF68,
};

void *lbl_804E2CB0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&handle_cancel_state__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2CBC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_confirm_start__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2CC8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_idle_timer__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2CD4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCD14,
};

void *lbl_804E2CE0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCCA4,
};

void *lbl_804E2CEC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&close_and_reset__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2CF8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCA20,
};

void *lbl_804E2D04[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC8A0,
};

void *lbl_804E2D10[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_input_state__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2D1C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC5CC,
};

void *lbl_804E2D28[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&handle_input__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2D34[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC440,
};

void *lbl_804E2D40[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&check_cancel_input__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2D4C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC310,
};

void *lbl_804E2D58[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&request_scene_change__22TAdMultiPlyChrSelectGCFv,
};

void *lbl_804E2D64[117] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};

s32 lbl_805D68C8;
u32 multi_chr_select_serial_access_state;
TAdMultiPlyChrSelectGC *TAdMultiPlyChrSelectGC__instance;
}

extern "C" { extern char TAdMultiPlyChrSelectGC__class_name_string[]; }
const char *lbl_805D3F68 = TAdMultiPlyChrSelectGC__class_name_string;
extern "C" {
extern s32 multi_ply_chr_select_active_player;
    extern int TAdMultiPlyChrSelectGC__selected_slot;
    extern int TAdMultiPlyChrSelectGC__select_mode;
void TAdChrSelPlyPlateGC::set_select_mode(int mode) { TAdMultiPlyChrSelectGC__select_mode = mode; }

s32 TAdChrSelPlyPlateGC::get_selection() { return unk_4f8; }

TAdChrSelPlyPlateGC *TAdMultiPlyChrSelectGC::get_card_instance() { return ad_chr_sel_ply_plate_instance; }

s32 TAdChrSelPlyPlateGC::get_card_index(s32) { return unk_4e8; }

void TAdChrSelPlyPlateGC::set_active_card_slot(s32 slot) {
    sel[multi_ply_chr_select_active_player][cursor_col] = slot;
}

void TAdChrSelPlyPlateGC::set_selection(s32 selection) { unk_4f8 = selection; }

s32 TAdChrSelPlyPlateGC::get_cursor() { return cursor_col; }

void TAdChrSelPlyPlateGC::set_state_ready() { unk_4fc = 1; }

s32 TAdChrSelPlyPlateGC::get_active_card_slot() {
    return sel[multi_ply_chr_select_active_player][cursor_col];
}

int TAdChrSelPlyPlateGC::get_instance() { return TAdMultiPlyChrSelectGC__selected_slot; }

TAdMultiPlyChrSelectGC *TAdMultiPlyChrSelectGC::get_or_create(TObject *parent, s32 mode) {
    if (TAdMultiPlyChrSelectGC__instance != NULL) {
        return TAdMultiPlyChrSelectGC__instance;
    }
    TAdMultiPlyChrSelectGC *scene = new TAdMultiPlyChrSelectGC(parent, mode);
    TAdMultiPlyChrSelectGC__instance = scene;
    return scene;
}

}

TAdMultiPlyChrSelectGC::TAdMultiPlyChrSelectGC(TObject *arg1, s32 arg2) : TObject(arg1) {
    m_name = lbl_805D3F68;
    this->initialize_selection_state(arg2);
    this->create_widgets();
    this->handle_event(TAdMultiPlyChrSelectGC::get_select_flag());
}

extern "C" {
TAdMultiPlyChrSelectGC::~TAdMultiPlyChrSelectGC() {
    TAdChrMoveEffectGC *global_state;
    u8 *temp_r3_10;
    u8 *temp_r3_11;
    TAdChrSelPlyPlateGC *plate;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *temp_r3_5;
    u8 *temp_r3_6;
    u8 *temp_r3_7;
    u8 *temp_r3_8;
    u8 *temp_r3_9;
    global_state = TAdMultiPlyChrSelectGC::get_global_state();
    if (global_state != NULL) {
        global_state->queue_destruction();
    }
    plate = player_plate;
    if (plate != NULL) {
        plate->queue_destruction();
        player_plate = NULL;
    }
    temp_r3_3 = (u8 *)(*(u8 **)((s8 *)this + 0x78));
    if (temp_r3_3 != NULL) {
        ((TObject *)temp_r3_3)->queue_destruction();
        *(u8 **)((s8 *)this + 0x78) = NULL;
    }
    temp_r3_4 = (u8 *)(*(u8 **)((s8 *)this + 0x88));
    if (temp_r3_4 != NULL) {
        ((TObject *)temp_r3_4)->queue_destruction();
        *(u8 **)((s8 *)this + 0x88) = NULL;
    }
    temp_r3_5 = (u8 *)(*(u8 **)((s8 *)this + 0x8C));
    if (temp_r3_5 != NULL) {
        ((TObject *)temp_r3_5)->queue_destruction();
        *(u8 **)((s8 *)this + 0x8C) = NULL;
    }
    temp_r3_6 = (u8 *)(*(u8 **)((s8 *)this + 0x90));
    if (temp_r3_6 != NULL) {
        ((TObject *)temp_r3_6)->queue_destruction();
        *(u8 **)((s8 *)this + 0x90) = NULL;
    }
    temp_r3_7 = (u8 *)(*(u8 **)((s8 *)this + 0x94));
    if (temp_r3_7 != NULL) {
        ((TObject *)temp_r3_7)->queue_destruction();
        *(u8 **)((s8 *)this + 0x94) = NULL;
    }
    temp_r3_8 = (u8 *)(*(u8 **)((s8 *)this + 0x98));
    if (temp_r3_8 != NULL) {
        ((TObject *)temp_r3_8)->queue_destruction();
        *(u8 **)((s8 *)this + 0x98) = NULL;
    }
    temp_r3_9 = (u8 *)(*(u8 **)((s8 *)this + 0x7C));
    if (temp_r3_9 != NULL) {
        ((TObject *)temp_r3_9)->queue_destruction();
        *(u8 **)((s8 *)this + 0x7C) = NULL;
    }
    temp_r3_10 = (u8 *)(*(u8 **)((s8 *)this + 0x80));
    if (temp_r3_10 != NULL) {
        ((TObject *)temp_r3_10)->queue_destruction();
        *(u8 **)((s8 *)this + 0x80) = NULL;
    }
    temp_r3_11 = (u8 *)(*(u8 **)((s8 *)this + 0x84));
    if (temp_r3_11 != NULL) {
        ((TObject *)temp_r3_11)->queue_destruction();
        *(u8 **)((s8 *)this + 0x84) = NULL;
    }
    if (TAdMultiPlyChrSelectGC__instance != NULL) {
        TAdMultiPlyChrSelectGC__instance = NULL;
    }
}

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma dont_inline on
void TAdMultiPlyChrSelectGC::initialize_selection_state(s32 arg1) {
    s32 v;
    *(s32 *)&this->m_1c = 0;
    *(s32 *)&this->unk_30 = -1;
    this->m_34 = -1;
    *(s32 *)&this->_pad44 = 2;
    *(s32 *)&this->unk_38 = 0;
    *(s32 *)&this->unk_58 = 0;
    v = TAdMultiPlyChrSelectGC::get_clamped_cursor();
    *(s32 *)&this->m_4c = v;
    *(s32 *)&this->m_2c = 2;
    v = 0;
    *(s32 *)&this->m_48 = arg1;
    *(s32 *)&this->m_74 = v;
    lbl_805D68C8 = v;
    *(s32 *)&this->unk_50 = v;
    this->m_54 = 1;
    *(s32 *)&this->unk_68 = v;
    *(s32 *)&this->unk_60 = v;
    player_plate = reinterpret_cast<TAdChrSelPlyPlateGC *>(v);
    *(s32 *)&this->unk_78 = v;
    *(s32 *)&this->unk_70 = v;
    this->m_7c = v;
    *(s32 *)&this->unk_80 = v;
    *(s32 *)&this->m_84 = v;
    *(s32 *)&this->unk_88 = v;
    this->m_8c = v;
    *(s32 *)&this->unk_90 = v;
    *(s32 *)&this->m_94 = v;
    *(s32 *)&this->unk_98 = v;
    *(s32 *)&this->m_3c = v;
    *(s32 *)&this->m_40 = v;
    this->m_9c = v;
    if (*(s32 *)&this->m_48 == 1) {
        v = 0x1D;
    }
    *(s32 *)&this->m_20 = v;
}
#pragma pop

void TAdMultiPlyChrSelectGC::handle_event(s32 arg1) {
    void *temp_r3;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    switch (arg1) {
    case 10:
        temp_r3 = (void *)TAdMultiPlyChrSelectGC__sub_802C6920();
        TAdMultiPlyChrSelectGC::split_slot_index((saddr)temp_r3, &sp14, &sp10);
        TAdMultiPlyChrSelectGC::init();
        player_plate->set_cursor_column(sp14);
        player_plate->set_active_card_slot(sp10);
        this->m_9c = 1;
        return;
    case 4:
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(TAdMultiPlyChrSelectGC__sub_802C658C(TAdMultiPlyChrSelectGC__sub_802C6920())) == 0) {
            temp_r3 = (void *)TAdMultiPlyChrSelectGC__sub_802C6920();
            TAdMultiPlyChrSelectGC::split_slot_index((saddr)temp_r3, &spC, &sp8);
            TAdMultiPlyChrSelectGC::init();
            player_plate->set_cursor_column(spC);
            player_plate->set_active_card_slot(sp8);
        }
        this->m_9c = 1;
        return;
    }
}

void TAdMultiPlyChrSelectGC::create_widgets() {
    uaddr p;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    switch (this->m_48) {
    case 0:
    case 2:
        new TAdTitleGC(this, 0);
        *(s32 *)&this->unk_68 = (saddr)TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 1);
        *(s32 *)&this->unk_60 = (saddr)get_or_create_player(this, 1, -1, 0);
        break;
    case 1: {
        new TAdTitleGC(this, 8);
        *(s32 *)&this->unk_68 = (saddr)TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 2);
        this->m_6c = (saddr)TAdChrSelBSlotGC::create(this);
        I2_802DF9B4 pos = lbl_80472828[0];
        p = reinterpret_cast<uaddr>(new TAdSelectCurGC(this,
            reinterpret_cast<const NJS_POINT2 *>(&pos),
            reinterpret_cast<const NJS_POINT2 *>(lbl_80472808)));
        *(u32 *)&this->unk_70 = p;
        *(s32 *)&this->unk_60 = (saddr)get_or_create_player(this, 2, -1, 0);
        break;
    }
    }
    guide = new TAdGuideTxtGC(this);
    guide->set_line(0, "");
    guide->set_line(1, "");
    p = reinterpret_cast<uaddr>(TObject::operator new(0x9C));
    if (p != 0) {
        p = __ct__13TAdTitleTexGCFv((void *) p, this);
    }
    Blk_802DF9B4 blk = multi_chr_select_layout_table[0];
    fn_802D50B8((void *)p, (void *)&blk.a, (void *)&blk.b, (void *)&blk.c);
    p = (uaddr)TObject::operator new(0xD4);
    if (p != 0) {
        p = __ct__14TAdGameStartGCFv((void *) p, tl_clipout);
    }
    *(u32 *)&this->unk_78 = p;
    NJS_POINT2 v = lbl_80472848[0];
    v.x = multi_chr_select_widget_layout[0].x;
    v.y = multi_chr_select_widget_layout[0].y;
    player_plate = fn_802C6F20(tl_02, (vec2f *)&v);
    TAdMultiPlyChrSelectGC::get_move_effect((saddr)tl_clipout);
}

void TAdMultiPlyChrSelectGC::run_task() {
    TAdMultiPlyChrSelectGC *self = this;
    static s8 init;
    TAdMultiChgGameModeGC::set_default_camera();
    self->m_3c = 1;
    if (static_cast<s32>(self->m_48) != 1 && TAdMultiPlyChrSelectGC__sub_802C6848(0) == 0) {
        self->m_3c = 0;
        self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xB)));
        self->guide->set_line(1, "");
    } else if (static_cast<s32>(self->m_48) != 1 && TAdMultiPlyChrSelectGC::count_ready() < 2) {
        self->m_3c = 0;
        self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xC)));
        self->guide->set_line(1, "");
    } else {
        switch (self->m_48) {
        case 0:
        case 2:
            if (static_cast<s32>(self->m_20) >= 0xC && static_cast<s32>(self->m_20) < 0x19) {
                if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
                    if (static_cast<s32>(self->m_40) == 0) {
                        if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC__sub_802C6920()) != 0) {
                            self->guide->set_line(0, reinterpret_cast<const char *>(TAdMultiPlyChrSelectGC::format_player_number_text((saddr)self, (s32)(TAdMultiPlyChrSelectGC__sub_802C6920()))));
                            self->guide->set_line(1, "");
                        } else {
                            self->guide->set_line(0, "");
                            self->guide->set_line(1, "");
                        }
                    } else {
                        self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                        self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
                    }
                } else if (static_cast<s32>(self->m_40) == 0) {
                    self->guide->set_line(0, "");
                    self->guide->set_line(1, "");
                } else {
                    self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                    self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
                }
            } else if (static_cast<s32>(self->m_20) >= 3 && TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) != 0) {
                if (static_cast<s32>(self->m_40) == 0) {
                    self->sub_802DC118(TAdMultiPlyChrSelectGC::get_clamped_cursor());
                } else {
                    self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                    self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
                }
            } else if (static_cast<s32>(self->m_40) == 0) {
                self->guide->set_line(0, "");
                self->guide->set_line(1, "");
            } else {
                self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
            }
            break;
        case 1:
            self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 1)));
            self->guide->set_line(1, "");
            break;
        }
    }
    if (!init) {
        ((Pmf_802DF114 *)lbl_804E2D64)[0] = *(Pmf_802DF114 *)lbl_804E2B90;
        ((Pmf_802DF114 *)lbl_804E2D64)[1] = *(Pmf_802DF114 *)lbl_804E2B9C;
        ((Pmf_802DF114 *)lbl_804E2D64)[2] = *(Pmf_802DF114 *)lbl_804E2BA8;
        ((Pmf_802DF114 *)lbl_804E2D64)[3] = *(Pmf_802DF114 *)lbl_804E2BB4;
        ((Pmf_802DF114 *)lbl_804E2D64)[4] = *(Pmf_802DF114 *)lbl_804E2BC0;
        ((Pmf_802DF114 *)lbl_804E2D64)[5] = *(Pmf_802DF114 *)lbl_804E2BCC;
        ((Pmf_802DF114 *)lbl_804E2D64)[6] = *(Pmf_802DF114 *)lbl_804E2BD8;
        ((Pmf_802DF114 *)lbl_804E2D64)[7] = *(Pmf_802DF114 *)lbl_804E2BE4;
        ((Pmf_802DF114 *)lbl_804E2D64)[8] = *(Pmf_802DF114 *)lbl_804E2BF0;
        ((Pmf_802DF114 *)lbl_804E2D64)[9] = *(Pmf_802DF114 *)lbl_804E2BFC;
        ((Pmf_802DF114 *)lbl_804E2D64)[10] = *(Pmf_802DF114 *)lbl_804E2C08;
        ((Pmf_802DF114 *)lbl_804E2D64)[11] = *(Pmf_802DF114 *)lbl_804E2C14;
        ((Pmf_802DF114 *)lbl_804E2D64)[12] = *(Pmf_802DF114 *)lbl_804E2C20;
        ((Pmf_802DF114 *)lbl_804E2D64)[13] = *(Pmf_802DF114 *)lbl_804E2C2C;
        ((Pmf_802DF114 *)lbl_804E2D64)[14] = *(Pmf_802DF114 *)lbl_804E2C38;
        ((Pmf_802DF114 *)lbl_804E2D64)[15] = *(Pmf_802DF114 *)lbl_804E2C44;
        ((Pmf_802DF114 *)lbl_804E2D64)[16] = *(Pmf_802DF114 *)lbl_804E2C50;
        ((Pmf_802DF114 *)lbl_804E2D64)[17] = *(Pmf_802DF114 *)lbl_804E2C5C;
        ((Pmf_802DF114 *)lbl_804E2D64)[18] = *(Pmf_802DF114 *)lbl_804E2C68;
        ((Pmf_802DF114 *)lbl_804E2D64)[19] = *(Pmf_802DF114 *)lbl_804E2C74;
        ((Pmf_802DF114 *)lbl_804E2D64)[20] = *(Pmf_802DF114 *)lbl_804E2C80;
        ((Pmf_802DF114 *)lbl_804E2D64)[21] = *(Pmf_802DF114 *)lbl_804E2C8C;
        ((Pmf_802DF114 *)lbl_804E2D64)[22] = *(Pmf_802DF114 *)lbl_804E2C98;
        ((Pmf_802DF114 *)lbl_804E2D64)[23] = *(Pmf_802DF114 *)lbl_804E2CA4;
        ((Pmf_802DF114 *)lbl_804E2D64)[24] = *(Pmf_802DF114 *)lbl_804E2CB0;
        ((Pmf_802DF114 *)lbl_804E2D64)[25] = *(Pmf_802DF114 *)lbl_804E2CBC;
        ((Pmf_802DF114 *)lbl_804E2D64)[26] = *(Pmf_802DF114 *)lbl_804E2CC8;
        ((Pmf_802DF114 *)lbl_804E2D64)[27] = *(Pmf_802DF114 *)lbl_804E2CD4;
        ((Pmf_802DF114 *)lbl_804E2D64)[28] = *(Pmf_802DF114 *)lbl_804E2CE0;
        ((Pmf_802DF114 *)lbl_804E2D64)[29] = *(Pmf_802DF114 *)lbl_804E2CEC;
        ((Pmf_802DF114 *)lbl_804E2D64)[30] = *(Pmf_802DF114 *)lbl_804E2CF8;
        ((Pmf_802DF114 *)lbl_804E2D64)[31] = *(Pmf_802DF114 *)lbl_804E2D04;
        ((Pmf_802DF114 *)lbl_804E2D64)[32] = *(Pmf_802DF114 *)lbl_804E2D10;
        ((Pmf_802DF114 *)lbl_804E2D64)[33] = *(Pmf_802DF114 *)lbl_804E2D1C;
        ((Pmf_802DF114 *)lbl_804E2D64)[34] = *(Pmf_802DF114 *)lbl_804E2D28;
        ((Pmf_802DF114 *)lbl_804E2D64)[35] = *(Pmf_802DF114 *)lbl_804E2D34;
        ((Pmf_802DF114 *)lbl_804E2D64)[36] = *(Pmf_802DF114 *)lbl_804E2D40;
        ((Pmf_802DF114 *)lbl_804E2D64)[37] = *(Pmf_802DF114 *)lbl_804E2D4C;
        ((Pmf_802DF114 *)lbl_804E2D64)[38] = *(Pmf_802DF114 *)lbl_804E2D58;
        init = 1;
    }
    self->m_24 = self->m_20;
    self->m_4c = TAdMultiPlyChrSelectGC::get_clamped_cursor();
    (reinterpret_cast<C_802DF114 *>(self)->*((Pmf_802DF114 *)lbl_804E2D64)[self->m_20])();
    if (static_cast<s32>(self->m_24) != static_cast<s32>(self->m_20)) {
        self->m_1c = 0;
    }
}

void update_state_serial__22TAdMultiPlyChrSelectGCFPv(void *arg0) {
    s32 temp_r5;

    if ((u32) *(u32 *)((s8 *)arg0 + 0x90) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x90)))->close();
        *(u32 *)((s8 *)arg0 + 0x90) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x80)))->close();
        *(u32 *)((s8 *)arg0 + 0x80) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x8C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x8C)))->close();
        *(u32 *)((s8 *)arg0 + 0x8C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x98) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x98)))->close();
        *(u32 *)((s8 *)arg0 + 0x98) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x7C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x7C)))->close();
        *(u32 *)((s8 *)arg0 + 0x7C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x74) != 0U) {
        ((TObject *)(*(void **)((s8 *)arg0 + 0x74)))->queue_destruction();
        *(u32 *)((s8 *)arg0 + 0x74) = 0U;
    }
    reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
    reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->reset_cursor_state();
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_field_100(1);
    *(s32 *)((s8 *)arg0 + 0x30) = -1;
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x1C) = (temp_r5 + 1);
    if ((TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0)) {
        if ((((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() != 0xE) && ((s32) *(s32 *)((s8 *)arg0 + 0x1C) > 0xA)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x20) = 0x1B;
            return;
        }
        if (TAdMultiPlyChrSelectGC__sub_802C6558() < 1) {
            play_sound_effect(0x52F16, 0, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x20) = 0x1B;
            return;
        }
        goto block_19;
    }
block_19:
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 0xE) {
        *(s32 *)((s8 *)arg0 + 0x20) = 1;
        if ((s32) *(s32 *)((s8 *)arg0 + 0x9C) != 0) {
            *(s32 *)((s8 *)arg0 + 0x9C) = 0;
            if ((u32) multi_chr_select_serial_access_state != get_field_118__22TAdEnterSerialAccessGCFv()) {
                TAdMultiPlyChrSelectGC::reset_slot_selections();
            }
        }
    }
}

void TAdMultiPlyChrSelectGC__sub_802DEDA8(u8 *arg0) {
    s32 var_r30;
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_index_and_close_status(0);
    if ((TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() < 1)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1B;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->reset_cursor_state();
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &TAdMultiPlyChrSelectGC__character_slot_positions.value, 0);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8), 0);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10), 0);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x18), 0);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_play_chr_select_slot_positions.value, 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&multi_play_chr_select_slot_positions.value + 8), 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&multi_play_chr_select_slot_positions.value + 0x10), 1);
    reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_cursor_fields(0, 1);
    var_r30 = 0;
    do {
        if (is_multiplayer_character_slot_selected(var_r30) != 0) {
            if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(TAdMultiPlyChrSelectGC__sub_802C658C(var_r30)) == 0) {
                TAdMultiPlyChrSelectGC::reset_slot_selections();
            }
        }
        var_r30 += 1;
    } while (var_r30 < 4);
    TAdMultiPlyChrSelectGC__sub_802C6660(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate);
    *(s32 *)((s8 *)arg0 + 0x20) = 3;
}

void TAdMultiPlyChrSelectGC::update_button_input() {
    if ((TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() < 1)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)this + 0x20) = 0x1B;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(0) == 0) {
        if ((s32) *(s32 *)((s8 *)this + 0x44) != 0) {
            *(s32 *)((s8 *)this + 0x44) = 0;
            guide->set_line(0, reinterpret_cast<const char *>((get_localized_text_entry(0x1F, 0xB))));
            guide->set_line(1, "");
        }
    } else if (TAdMultiPlyChrSelectGC::count_ready() < 2) {
        if ((s32) *(s32 *)((s8 *)this + 0x44) != 1) {
            *(s32 *)((s8 *)this + 0x44) = 1;
            guide->set_line(0, reinterpret_cast<const char *>((get_localized_text_entry(0x1F, 0xC))));
            guide->set_line(1, "");
        }
    } else {
        *(s32 *)((s8 *)this + 0x44) = 2;
        sub_802DC118(TAdMultiPlyChrSelectGC::get_clamped_cursor());
        *(s32 *)((s8 *)this + 0x20) = 3;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DE7D0(void *ad_multi_ply_chr_select_gc) {
    Stack_802DE7D0 stack;
    s32 temp_r30;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 var_r30;
    s32 var_r3;
    u32 var_r0;
    if ((u32) *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x90) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x90)))->close();
        *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x90) = 0U;
    }
    if ((u32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_8c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x8C)))->close();
        ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_8c = 0U;
    }
    if ((u32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x7C)))->close();
        ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_7c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x98) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x98)))->close();
        *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x98) = 0U;
    }
    if ((u32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_74 != 0U) {
        ((TObject *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x74)))->queue_destruction();
        ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_74 = 0U;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
        temp_r5 = TAdMultiPlyChrSelectGC__sub_802C6920();
        var_r3 = TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2);
    } else {
        temp_r5_2 = ((s32)TAdMultiPlyChrSelectGC::get_clamped_cursor());
        var_r3 = TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5_2], 2);
    }
    if (var_r3 != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
            TAdMultiPlyChrSelectGC::split_slot_index(TAdMultiPlyChrSelectGC__sub_802C6920(), &stack.spC, &stack.sp8);
            TAdMultiPlyChrSelectGC::init();
            static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->set_cursor_column(stack.spC);
            static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->set_active_card_slot(stack.sp8);
            return;
        }
        if (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) {
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x1B;
        }
    } else {
        var_r30 = 0;
        do {
            if ((is_multiplayer_character_slot_selected(var_r30) != 0) && (TAdMultiPlyChrSelectGC__sub_802C6848(var_r30) == 0)) {
                TAdMultiPlyChrSelectGC__sub_802C65C0(var_r30);
            }
            var_r30 += 1;
        } while (var_r30 < 4);
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)ad_multi_ply_chr_select_gc + 0x68)))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0;
            return;
        }
        temp_r30 = TAdMultiPlyChrSelectGC__sub_802DC294((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc, static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_cursor());
        if (((s32) *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x30) != static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_active_card_slot()) || ((s32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_34 != static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_cursor())) {
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)ad_multi_ply_chr_select_gc + 0x60)))->set_field_100(1);
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_40 = 0;
            if (TAdSinglePlyChrSelectGC__sub_801FE4BC(temp_r30) != 0U) {
                load_tables(temp_r30);
                ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)ad_multi_ply_chr_select_gc + 0x60)))->set_field_100(2);
                if ((TAdSinglePlyChrSelectGC::check_flag(1) != 0U) && ((s32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_3c != 0)) {
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_40 = 1;
                }
            }
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x30) = static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_active_card_slot();
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_34 = static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_cursor();
        }
        if (static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_selection() != 0) {
            load_tables(temp_r30);
            if (static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_cursor() == 1) {
                if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(temp_r30) == 0) {
                    play_sound_effect(0x52D01, 0, 0, 0);
                    static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->capture_card_index();
                    static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->restore_selection();
                    TAdMultiPlyChrSelectGC__sub_802C5688(static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate);
                    if ((u32) *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68) != 0U) {
                        ((TObject *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x68)))->queue_destruction();
                        *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68) = 0U;
                    }
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 9;
                    return;
                }
                ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_7c = ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->create_choice_menu();
                ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 5;
                return;
            }
            if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(temp_r30) != 0) {
                if (TAdChrSelASlotGC__sub_8030C3C0((TAdChrSelASlotGC *)(*(uaddr *)((s8 *)ad_multi_ply_chr_select_gc + 0x68)), static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_active_card_slot()) != 0) {
                    var_r0 = reinterpret_cast<uaddr>(TObject::operator new(0x38));
                    if (var_r0 != 0U) {
                        var_r0 = __ct__9TAdFadeGCFP7TObjectPv(var_r0, tl_fade, 0);
                    }
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_74 = var_r0;
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_8c = TAdChrSelASlotGC::open_yes_no_window((s32)(*(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68)), (saddr)((s32 *)&lbl_80472850), (s32)(((s32)TAdMultiPlyChrSelectGC::get_clamped_cursor())));
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 7;
                    return;
                }
                play_sound_effect(0x52D01, 0, 0, 0);
                TAdMultiPlyChrSelectGC__sub_802C561C(static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate);
                TAdMultiPlyChrSelectGC__sub_802C5688(static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate);
                ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x19;
                return;
            }
            *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x90) = TAdChrSelASlotGC__sub_8030CA84(*(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68), (saddr)lbl_80472858);
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 4;
            return;
        }
        if ((static_cast<TAdMultiPlyChrSelectGC *>(ad_multi_ply_chr_select_gc)->player_plate->get_field_0x530() != 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x28) = 0x1C;
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x1A;
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x2C) = 1;
            return;
        }
        if ((TAdMultiPlyChrSelectGC::count_ready() == TAdMultiPlyChrSelectGC__sub_802C6558()) && (is_multiplayer_character_slot_selected(0) != 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1)) {
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x28) = 0x1C;
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x1A;
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x2C) = 1;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_confirm() {

    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowSubComCard *)(*(uaddr *)((s8 *)this + 0x90)))->get_card_data() != 0) {
        player_plate->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x90)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(uaddr *)((s8 *)this + 0x90)))->get_slot_or_neg1()) {
        case 1:
            player_plate->set_state_ready();
            *(s32 *)((s8 *)this + 0x20) = 3;
            return;
        case 0:
            play_sound_effect(0x52D01, 0, 0, 0);
            TAdMultiPlyChrSelectGC__sub_802C561C(player_plate);
            TAdMultiPlyChrSelectGC__sub_802C5688(player_plate);
            lbl_805D68C8 = 1;
            if ((u32) *(u32 *)((s8 *)this + 0x90) != 0U) {
                ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x90)))->close();
                *(u32 *)((s8 *)this + 0x90) = 0U;
            }
            *(s32 *)((s8 *)this + 0x28) = 0x1C;
            *(s32 *)((s8 *)this + 0x20) = 0x1A;
            *(s32 *)((s8 *)this + 0x2C) = 0;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_state_option() {
    s32 selected_menu_value;

    if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->is_cancelled() != 0) {
        player_plate->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->is_decided() != 0) {
        selected_menu_value = ((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->get_selected_value();
        switch (selected_menu_value) {
        case 0:
            play_sound_effect(0x52D01, 0, 0, 0);
            TAdMultiPlyChrSelectGC__sub_802C561C(player_plate);
            TAdMultiPlyChrSelectGC__sub_802C5688(player_plate);
            *(s32 *)((s8 *)this + 0x20) = 0x19;
            return;
        case 1:
            play_sound_effect(0x52D01, 0, 0, 0);
            player_plate->capture_card_index();
            player_plate->restore_selection();
            TAdMultiPlyChrSelectGC__sub_802C5688(player_plate);
            player_plate->set_state_ready();
            if ((u32) *(u32 *)((s8 *)this + 0x68) != 0U) {
                ((TObject *)(*(void **)((s8 *)this + 0x68)))->queue_destruction();
                *(u32 *)((s8 *)this + 0x68) = 0U;
            }
            *(s32 *)((s8 *)this + 0x20) = 0xA;
            return;
        case 2:
            ((TWindowOptionCtrl *)(*(saddr *)((s8 *)this + 0x7C)))->open();
            *(void **)((s8 *)this + 0x98) = TAdMultiPlyChrSelectGC__sub_802DBCE8(this);
            *(s32 *)((s8 *)this + 0x20) = 6;
            return;
        case 3:
            player_plate->set_state_ready();
            *(s32 *)((s8 *)this + 0x20) = 3;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_select() {

    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
            *(u32 *)((s8 *)this + 0x7C) = 0U;
        }
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowSubComCard *)(*(uaddr *)((s8 *)this + 0x98)))->get_card_data() != 0) {
        ((TWindowMenu *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_transition_flag();
        ((TWindowSubComCard *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_flag_and_release();
        if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x98)))->close();
            *(u32 *)((s8 *)this + 0x98) = 0U;
        }
        *(s32 *)((s8 *)this + 0x20) = 5;
        return;
    }
    if (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x98)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(uaddr *)((s8 *)this + 0x98)))->get_slot_or_neg1()) {
        case 1:
            ((TWindowMenu *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_transition_flag();
            ((TWindowSubComCard *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_flag_and_release();
            if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
                ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x98)))->close();
                *(u32 *)((s8 *)this + 0x98) = 0U;
            }
            *(s32 *)((s8 *)this + 0x20) = 5;
            return;
        case 0:
            if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
                ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x98)))->close();
                *(u32 *)((s8 *)this + 0x98) = 0U;
            }
            clear_slot_body__23TAdSinglePlyChrSelectGCFi(player_plate->get_active_card_slot() + 4);
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x68)))->set_cursor_index(0xF);
            *(s32 *)((s8 *)this + 0x20) = 8;
            break;
        }
    }
}

void update__22TAdMultiPlyChrSelectGCFPv(void *arg0) {

    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
        *(s32 *)((s8 *)arg0 + 0x20) = 3;
        return;
    }
    if (((TWindowSubComCard *)(*(saddr *)((s8 *)arg0 + 0x8C)))->get_card_data() != 0) {
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
        *(s32 *)((s8 *)arg0 + 0x20) = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)((s8 *)arg0 + 0x8C)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(saddr *)((s8 *)arg0 + 0x8C)))->get_slot_or_neg1()) {
        case 1:
            reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
            *(s32 *)((s8 *)arg0 + 0x20) = 3;
            return;
        case 0:
            clear_entry__23TAdSinglePlyChrSelectGCFi(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->get_active_card_slot());
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->set_cursor_index(0xF);
            reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
            *(s32 *)((s8 *)arg0 + 0x20) = 8;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::close_windows() {
    if ((u32) this->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        this->m_7c = 0U;
    }
    if ((u32) this->m_8c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x8C)))->close();
        this->m_8c = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x74)))->queue_destruction();
        this->m_74 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->m_20 = 0;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        this->m_20 = 0;
    }
}

void TAdMultiPlyChrSelectGC::open_char_select() {
    player_plate->set_cursor_column(2);
    player_plate->set_cursor_fields(2, 2);
    player_plate->set_state_ready();
    open_windows();
}

void TAdMultiPlyChrSelectGC::init_windows() {
    if ((u32) this->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        this->m_7c = 0U;
    }
    player_plate->set_cursor_fields(2, 2);
    player_plate->set_cursor_column((saddr)((void*)(2)));
    player_plate->set_selection(1);
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x60)))->set_field_100(1);
    *(s32 *)((s8 *)this + 0x50) = 1;
    this->m_54 = 0;
    open_windows();
}

void TAdMultiPlyChrSelectGC::open_windows() {
    destroy_windows__14TAdGameStartGCFPv(*(s32 *)((s8 *)this + 0x78));
    player_plate->set_select_mode(1);
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)this + 0x60)))->set_index_and_close_status(1);
    *(s32 *)((s8 *)this + 0x68) = (saddr)TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 2);
    this->m_6c = (saddr)TAdChrSelBSlotGC::create(this);
    guide->set_line(0, "");
    guide->set_line(1, "");
    this->m_20 = 0xC;
}

}

void TAdMultiPlyChrSelectGC::reset_to_select() {
    Stack_802DDF40 stack;
    s32 temp_r31;
    s32 temp_r3;
    {
        TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
        if (effect != NULL) {
            effect->clear_entries();
        }
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
        if ((is_slot_active__23TAdSinglePlyChrSelectGCFUi(TAdMultiPlyChrSelectGC__sub_802C658C(TAdMultiPlyChrSelectGC__sub_802C6920())) == 0) || ((s32) this->m_54 == 0)) {
            TAdMultiPlyChrSelectGC::split_slot_index(TAdMultiPlyChrSelectGC__sub_802C6920(), &stack.spC, &stack.sp8);
            TAdMultiPlyChrSelectGC::init();
            player_plate->set_cursor_column(stack.spC);
            player_plate->set_active_card_slot(stack.sp8);
        }
    }
    if ((u32) *(u32 *)&this->m_6c != 0U) {
        ((TObject *)(*(void * *)&this->m_6c))->queue_destruction();
        *(u32 *)&this->m_6c = 0U;
    }
    if ((u32) this->m_84 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_84))->close();
        this->m_84 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_88 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->unk_88))->close();
        *(u32 *)&this->unk_88 = 0U;
    }
    *(s32 *)&this->unk_50 = 0;
    *(s32 *)&this->unk_68 = (saddr)TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 1);
    player_plate->set_select_mode(0);
    player_plate->set_state_ready();
    if ((((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_78))->get_ready_state() == 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
        temp_r31 = TAdMultiPlyChrSelectGC::count_ready();
        temp_r3 = TAdMultiPlyChrSelectGC__sub_802C6558();
        if (temp_r3 != temp_r31) {
            create_effects__14TAdGameStartGCFPv((u8 *)(*(saddr *)&this->unk_78));
        }
    }
    *(s32 *)&this->m_20 = 0;
}

extern "C" {
void TAdMultiPlyChrSelectGC__sub_802DDD08(u8 *arg0) {
    s32 temp_r0;
    s32 temp_r5;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x88) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x88)))->close();
        *(u32 *)((s8 *)arg0 + 0x88) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x8C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x8C)))->close();
        *(u32 *)((s8 *)arg0 + 0x8C) = 0U;
    }
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_field_100(1);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x74) != 0U) {
        ((TObject *)(*(void **)((s8 *)arg0 + 0x74)))->queue_destruction();
        *(u32 *)((s8 *)arg0 + 0x74) = 0U;
    }
    *(s32 *)((s8 *)arg0 + 0x30) = -1;
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->is_state_closing() == 0) {
        temp_r5 = reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->get_instance();
        if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
                ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
                *(u32 *)((s8 *)arg0 + 0x68) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
            return;
        }
    }
    reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->clear_slot_entries(2);
    if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)arg0 + 0x68)))->get_player_index() >= 0xE) {
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->init_slot_position((saddr)&TAdMultiPlyChrSelectGC__character_slot_positions.value, 0, 1);
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8)), 1, 1);
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10)), 2, 1);
    } else {
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->init_slot_position((saddr)&TAdMultiPlyChrSelectGC__character_slot_positions.value, 0, 0);
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8)), 1, 0);
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10)), 2, 0);
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() == 0x14) {
        *(s32 *)((s8 *)arg0 + 0x20) = 0xD;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) + 1;
        *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
        if (temp_r0 > 0xA) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            play_sound_effect(0x52F16, 0, 0, 0);
            if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
                ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
                *(u32 *)((s8 *)arg0 + 0x68) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        }
    }
}

void TAdMultiPlyChrSelectGC__sub_802DDBA8(u8 *arg0) {
    s32 temp_r5;
    temp_r5 = reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->get_instance();
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
                ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
                *(u32 *)((s8 *)arg0 + 0x68) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xC;
        return;
    }
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[0], 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[1], 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[2], 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[3], 2);
    *(s32 *)((s8 *)arg0 + 0x20) = 0xE;
}

void TAdMultiPlyChrSelectGC::update_select() {
    s32 temp_r30;
    s32 temp_r5;
    u32 var_r0;

    if ((u32) *(u32 *)&this->unk_90 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->unk_90))->close();
        *(u32 *)&this->unk_90 = 0U;
    }
    if ((u32) *(u32 *)&this->m_8c != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_8c))->close();
        *(u32 *)&this->m_8c = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        ((TObject *)(*(void * *)&this->m_74))->queue_destruction();
        this->m_74 = 0U;
    }
    temp_r5 = player_plate->get_instance();
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if ((u32) *(u32 *)&this->unk_68 != 0U) {
                ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
                *(u32 *)&this->unk_68 = 0U;
            }
            *(s32 *)&this->m_20 = 0xB;
            return;
        }
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    temp_r30 = TAdMultiPlyChrSelectGC__sub_802DC294(this, player_plate->get_cursor());
    if ((s32) *(s32 *)&this->unk_30 != player_plate->get_active_card_slot()) {
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_field_100(1);
        *(s32 *)&this->m_40 = 0;
        if (TAdSinglePlyChrSelectGC__sub_801FE3E4(temp_r30) != 0U) {
            load_tables(temp_r30);
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_status_value(temp_r30);
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_field_100(2);
            if ((TAdSinglePlyChrSelectGC::check_slot_flags(temp_r30, 1) != 0U) && ((s32) *(s32 *)&this->m_3c != 0)) {
                *(s32 *)&this->m_40 = 1;
            }
        }
        *(s32 *)&this->unk_30 = player_plate->get_active_card_slot();
    }
    if ((s32) *(s32 *)&this->unk_50 != 0) {
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_field_100(1);
        *(s32 *)&this->m_20 = 0x15;
        return;
    }
    if (player_plate->get_selection() != 0) {
        load_tables(temp_r30);
        if (TAdSinglePlyChrSelectGC__sub_801FE800(temp_r30) != 0) {
            if (is_slot_state_one__16TAdChrSelBSlotGCFlUl(this->m_6c, temp_r30) == 0) {
                *(void **)&this->unk_88 = create_confirm_window(player_plate->get_instance());
                *(s32 *)&this->m_20 = 0xF;
                return;
            }
            var_r0 = (uaddr)TObject::operator new(0x38);
            if (var_r0 != 0U) {
                var_r0 = __ct__9TAdFadeGCFP7TObjectPv(var_r0, tl_fade, 0);
            }
            this->m_74 = var_r0;
            *(u32 *)&this->m_8c = TAdChrSelASlotGC::open_yes_no_window((s32)(*(u32 *)&this->unk_68), (saddr)lbl_80472860, player_plate->get_instance());
            *(s32 *)&this->m_20 = 0x10;
            return;
        }
        player_plate->set_state_ready();
    }
}

void TAdMultiPlyChrSelectGC::update_state_wait_card() {
    s32 temp_r31;
    s32 temp_r3_2;

    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        player_plate->set_state_ready();
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if ((u32) *(u32 *)&this->unk_68 != 0U) {
                ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
                *(u32 *)&this->unk_68 = 0U;
            }
            *(s32 *)&this->m_20 = 0xB;
            return;
        }
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(get_card_instance()->get_instance()) == 0) {
        player_plate->set_state_ready();
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    if (((TWindowSubComCard *)(*(saddr *)&this->unk_88))->get_card_data() != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        player_plate->set_state_ready();
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)&this->unk_88))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(saddr *)&this->unk_88))->get_slot_or_neg1()) {
        case 1:
            player_plate->set_state_ready();
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 0:
            temp_r31 = player_plate->get_active_card_slot();
            temp_r3_2 = player_plate->get_card_index(1);
            if (try_move_char__23TAdSinglePlyChrSelectGCFii(temp_r3_2 + 4, temp_r31) != 0) {
                {
                    TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
                    if (effect != NULL) {
                        effect->setup_move_effect_params(temp_r31 + 3, temp_r3_2);
                    }
                }
                *(s32 *)&this->unk_80 = TAdMultiPlyChrSelectGC__sub_802DBEC4(this, lbl_80472868);
                ((TAdMultiPlyChrSelectGC *)(this->m_6c))->set_field_1c(0x15);
                *(s32 *)&this->m_20 = 0x11;
                return;
            }
            player_plate->set_state_ready();
            *(s32 *)&this->m_20 = 0xC;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_select_state() {

    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if ((u32) *(u32 *)&this->unk_68 != 0U) {
                ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
                *(u32 *)&this->unk_68 = 0U;
            }
            *(s32 *)&this->m_20 = 0xB;
            return;
        }
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(get_card_instance()->get_instance()) == 0) {
        player_plate->set_state_ready();
        *(s32 *)&this->m_20 = 0xE;
        return;
    }
    if (((TWindowSubComCard *)(this->m_8c))->get_card_data() != 0) {
        player_plate->set_state_ready();
        *(s32 *)&this->m_20 = 0xE;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_8c))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(this->m_8c))->get_slot_or_neg1()) {
        case 1:
            player_plate->set_state_ready();
            *(s32 *)&this->m_20 = 0xE;
            return;
        case 0:
            clear_slot_entry__23TAdSinglePlyChrSelectGCFi(player_plate->get_active_card_slot());
            ((TAdMultiPlyChrSelectGC *)(this->m_6c))->set_field_1c(0x16);
            *(s32 *)&this->m_20 = 0x14;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_state() {
    if ((u32) *(u32 *)&this->unk_88 != 0U) {
        ((TObject *)(*(void * *)&this->unk_88))->queue_destruction();
        *(u32 *)&this->unk_88 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x19) {
        ((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->set_cursor_index(0xF);
        *(s32 *)&this->m_20 = 0x13;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x18) {
        if ((u32) *(u32 *)&this->unk_80 != 0U) {
            ((TObject *)(*(void * *)&this->unk_80))->queue_destruction();
            *(u32 *)&this->unk_80 = 0U;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        *(s32 *)&this->m_20 = 0x12;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DD400(u8 *arg0) {
    s32 temp_r5;
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() > 1) {
        temp_r5 = reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->get_instance();
        if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2) != 0) {
            goto block_2;
        }
    } else {
block_2:
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::handle_confirm_state() {
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->unk_50 = 0;
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
        *(s32 *)&this->unk_50 = 0;
        this->m_54 = 1;
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DD2B0(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((s8 *)arg0 + 0x8C);
    if ((uaddr) temp_r3 != 0U) {
        ((TWindowSubComCard *)temp_r3)->close();
        *(u32 *)((s8 *)arg0 + 0x8C) = 0U;
    }
    temp_r3 = *(void **)((s8 *)arg0 + 0x74);
    if ((uaddr) temp_r3 != 0U) {
        ((TObject *)temp_r3)->queue_destruction();
        *(u32 *)((s8 *)arg0 + 0x74) = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() == 1) {
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
        *(s32 *)((s8 *)arg0 + 0x20) = 0xC;
    }
}

void TAdMultiPlyChrSelectGC::update_state_move() {
    u32 iter;
    TAdChrMoveEffectGC *effect;
    s32 temp_r5;
    s32 ret;
    s32 temp_r3;

    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    temp_r5 = player_plate->get_instance();
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    iter = 0;
loop_7:
    ret = player_plate->get_card_index(1);
    if (swap_characters__23TAdSinglePlyChrSelectGCFii(iter, ret + 4) == 1) {
        if ((u32) this->m_84 != 0U) {
            ((TWindowBase *)(*(void * *)&this->m_84))->close();
            this->m_84 = 0U;
        }
        effect = TAdMultiPlyChrSelectGC::get_global_state();
        if (effect != NULL) {
            effect->setup_move_effect_params(ret, iter + 3);
        }
        player_plate->set_active_card_slot(iter);
        player_plate->set_selection(1);
        temp_r3 = TAdMultiPlyChrSelectGC__sub_802DC294(this, player_plate->get_cursor());
        load_tables(temp_r3);
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_status_value(temp_r3);
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_field_100(2);
        *(s32 *)&this->unk_80 = TAdMultiPlyChrSelectGC__sub_802DBEC4(this, lbl_80472870);
        ((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->set_cursor_index(0x11);
        *(s32 *)&this->m_20 = 0x16;
        return;
    }
    iter += 1;
    if (iter >= 4U) {
        this->m_54 = 0;
        if ((u32) this->m_84 == 0U) {
            this->m_84 = TAdMultiPlyChrSelectGC__sub_802DBE4C(this, lbl_80472878);
        }
        *(s32 *)&this->m_20 = 0xE;
        return;
    }
    goto loop_7;
}

void TAdMultiPlyChrSelectGC__sub_802DD010(void *arg0) {
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() <= 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x14) {
        *(s32 *)((s8 *)arg0 + 0x20) = 0x18;
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->set_field_1c(0x1B);
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x13) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            ((TObject *)(*(void **)((s8 *)arg0 + 0x80)))->queue_destruction();
            *(u32 *)((s8 *)arg0 + 0x80) = 0U;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x17;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DCF68(void *arg0) {
    s32 temp_r5;
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() > 1) {
        temp_r5 = reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->get_instance();
        if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[temp_r5], 2) == 0) {
            return;
        }
    }
    {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            ((TObject *)(*(void **)((s8 *)arg0 + 0x68)))->queue_destruction();
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::handle_cancel_state() {
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        if (((TAdMultiPlyChrSelectGC *)(*(uaddr *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x1D) {
        *(s32 *)&this->unk_50 = 0;
        this->m_54 = 1;
        player_plate->set_state_ready();
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            ((TObject *)(*(void * *)&this->unk_68))->queue_destruction();
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::update_confirm_start() {
    s32 temp_r31;
    s32 temp_r3;

    if ((((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_78))->get_ready_state() == 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
        temp_r31 = TAdMultiPlyChrSelectGC::count_ready();
        temp_r3 = TAdMultiPlyChrSelectGC__sub_802C6558();
        if (temp_r3 != temp_r31) {
            create_effects__14TAdGameStartGCFPv((u8 *)(*(saddr *)&this->unk_78));
        }
    }
    player_plate->set_state_ready();
    *(s32 *)&this->m_20 = 3;
}

void TAdMultiPlyChrSelectGC::update_idle_timer() {
    s32 temp_r4;
    temp_r4 = *(s32 *)&this->m_1c + 1;
    *(s32 *)&this->m_1c = temp_r4;
    if (((f32) temp_r4 > 4.5f) && (TAdMultiPlyChrSelectGC::get_selected_slot() != 0U) && (TAdPlyPltAnimCtrlGC__sub_80355148() == 0)) {
        *(s32 *)&this->m_20 = (s32) *(s32 *)&this->unk_28;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DCD14(void *arg0) {

    TAdMultiPlyChrSelectGC::reset_slot_selections();
    switch (*(s32 *)((s8 *)arg0 + 0x48)) {
    case 0:
        if (TAdMultiPlyChrSelectGC::get_chr_select_state() != 0) {
            TAdMultiChgGameModeGC::begin_change_game_mode();
            return;
        }
        TAdMultiChgGameModeGC::set_game_mode_state();
        return;
    case 1:
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    case 2:
        TAdMultiChgGameModeGC::begin_change_game_mode();
        return;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DCCA4(Obj_802DCCA4 *arg0) {
    multi_chr_select_serial_access_state = get_field_118__22TAdEnterSerialAccessGCFv();
    switch (arg0->f2C) {
    case 2:
        break;
    case 0:
        set_opening_movie_purpose(1);
        request_main_phase(3);
        break;
    case 1:
        ((TAdMultiPlyChrSelectGC *)arg0)->collect_player_slots();
        TAdMultiChgGameModeGC::begin_transition();
        break;
    }
}

void TAdMultiPlyChrSelectGC::close_and_reset() {
    if ((u32) *(u32 *)&this->unk_80 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_80))->close();
        *(u32 *)&this->unk_80 = 0U;
    }
    if ((u32) this->m_94 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
        this->m_94 = 0U;
    }
    player_plate->reset_cursor_state();
    if ((u32) *(u32 *)&this->unk_70 != 0U) {
        ((TObject *)(*(void * *)&this->unk_70))->disallow_rendering();
    }
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_60))->set_field_100(1);
    guide->set_line(0, "");
    guide->set_line(1, "");
    *(s32 *)&this->unk_30 = -1;
    if ((((TAdMultiPlyChrSelectGC *)(this->m_6c))->is_state_closing() == 0) && (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->unk_28 = 0x1B;
        *(s32 *)&this->m_20 = 0x1A;
        return;
    }
    if ((((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_68))->get_player_index() == 0xE) && (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x14)) {
        *(s32 *)&this->m_20 = 0x1E;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DCA20(u8 *arg0) {
    ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_index_and_close_status(2);
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->reset_cursor_state();
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &TAdMultiPlyChrSelectGC__character_slot_positions.value, 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8), 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10), 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[0], 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[1], 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[2], 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate, &multi_chr_select_item_rect_table[3], 2);
    *(s32 *)((s8 *)arg0 + 0x20) = 0x1F;
}

void TAdMultiPlyChrSelectGC__sub_802DC8A0(void *arg0) {
    u32 i;
    s32 k;
    if (*(u32 *)((s8 *)arg0 + 0x80) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x80)))->close();
        *(u32 *)((s8 *)arg0 + 0x80) = 0U;
    }
    if (*(u32 *)((s8 *)arg0 + 0x84) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x84)))->close();
        *(u32 *)((s8 *)arg0 + 0x84) = 0U;
    }
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->get_instance()], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(u32 *)((s8 *)arg0 + 0x58) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    for (i = *(u32 *)((s8 *)arg0 + 0x58); i < 3; i++) {
        k = i + 4;
        *(s32 *)((s8 *)arg0 + 0x38) = k;
        load_tables(k);
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(k) != 0) {
            ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_field_100(2);
            if (*(u32 *)((s8 *)arg0 + 0x70) != 0U) {
                ((TObject *)(*(void **)((s8 *)arg0 + 0x70)))->allow_rendering();
            }
            ((TAdSelectCurGC *)(*(uaddr *)((s8 *)arg0 + 0x70)))->reset_entries();
            ((TAdSelectCurGC *)(*(uaddr *)((s8 *)arg0 + 0x70)))->append_entry(&((Pair_802DC8A0 *)&TAdMultiPlyChrSelectGC__character_slot_positions)[i]);
            ((TAdSelectCurGC *)(*(uaddr *)((s8 *)arg0 + 0x70)))->lock_navigation();
            *(u32 *)((s8 *)arg0 + 0x58) = i;
            *(void **)((s8 *)arg0 + 0x94) = TAdMultiPlyChrSelectGC__sub_802DBD64(reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0));
            *(s32 *)((s8 *)arg0 + 0x20) = 0x20;
            return;
        }
    }
    *(s32 *)((s8 *)arg0 + 0x20) = 0x26;
}

void TAdMultiPlyChrSelectGC::update_input_state() {

    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) this->m_94 != 0U) {
            ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
            this->m_94 = 0U;
        }
        *(s32 *)&this->unk_58 = (s32) (*(s32 *)&this->unk_58 + 1);
        *(s32 *)&this->m_20 = 0x1F;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_68))->get_player_index() < 0xE) {
            *(s32 *)&this->unk_58 = 0;
        }
        if ((u32) this->m_94 != 0U) {
            ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
            this->m_94 = 0U;
        }
        *(s32 *)&this->m_20 = 0x1D;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_94))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(this->m_94))->get_slot_or_neg1()) {
        case 0:
            *(s32 *)&this->m_20 = 0x21;
            return;
        case 1:
            if ((u32) this->m_94 != 0U) {
                ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
                this->m_94 = 0U;
            }
            *(s32 *)&this->unk_58 = (s32) (*(s32 *)&this->unk_58 + 1);
            *(s32 *)&this->m_20 = 0x1F;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC__sub_802DC5CC(void *arg0) {
    u32 var_r30;
    TAdChrMoveEffectGC *effect;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x94) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x94)))->close();
        *(u32 *)((s8 *)arg0 + 0x94) = 0U;
    }
    if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    var_r30 = 0U;
loop_9:
    if (swap_characters__23TAdSinglePlyChrSelectGCFii(var_r30, *(s32 *)((s8 *)arg0 + 0x38)) != 0) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x84)))->close();
            *(u32 *)((s8 *)arg0 + 0x84) = 0U;
        }
        effect = TAdMultiPlyChrSelectGC::get_global_state();
        if (effect != NULL) {
            effect->setup_move_effect_params(*(s32 *)((s8 *)arg0 + 0x38) - 4, var_r30 + 3);
        }
        load_tables(*(s32 *)((s8 *)arg0 + 0x38));
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_status_value(var_r30);
        *(s32 *)((s8 *)arg0 + 0x80) = TAdMultiPlyChrSelectGC__sub_802DBEC4(arg0, (s32*)lbl_80472880);
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_field_100(1);
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->set_cursor_index(0x11);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x23;
        return;
    }
    var_r30 += 1;
    if (var_r30 >= 4U) {
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x60)))->set_field_100(1);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x84) == 0U) {
            *(u32 *)((s8 *)arg0 + 0x84) = TAdMultiPlyChrSelectGC__sub_802DBE4C(arg0, (s32*)lbl_80472888);
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x22;
        return;
    }
    goto loop_9;
}

void TAdMultiPlyChrSelectGC::handle_input() {
    void *context;

    if ((u32) this->m_94 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
        this->m_94 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)&this->unk_68))->get_player_index() < 0xE) {
            *(s32 *)&this->unk_58 = 0;
        }
        *(s32 *)&this->m_20 = 0x1D;
        return;
    }
    context = &controller_physical_port_bank.controllers[0];
    if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (TWindowShortListCtrl__check_controller_button(context, 2) != 0)) {
        *(s32 *)&this->m_20 = 0x1F;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DC440(void *arg0) {
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x14) {
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->set_field_1c(0x1B);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x25;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x13) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            ((TObject *)(*(void **)((s8 *)arg0 + 0x80)))->queue_destruction();
            *(u32 *)((s8 *)arg0 + 0x80) = 0U;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        reinterpret_cast<TAdMultiPlyChrSelectGC *>(arg0)->player_plate->reset_cursor_state();
        *(s32 *)((s8 *)arg0 + 0x20) = 0x24;
    }
}

void TAdMultiPlyChrSelectGC::check_cancel_input() {
    if ((((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) || (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank.controllers[0], 2) != 0)) {
        TAdPlayerLoadGC::set_state(1);
        *(s32 *)&this->unk_58 = 0;
        this->m_20 = 0x1D;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DC310(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x88) != 0U) {
        ((TObject *)(*(void **)((s8 *)arg0 + 0x88)))->queue_destruction();
        *(u32 *)((s8 *)arg0 + 0x88) = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->get_mode() == 0x1D) {
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x68)))->set_cursor_index(1);
        ((TAdMultiPlyChrSelectGC *)(*(saddr *)((s8 *)arg0 + 0x6C)))->set_field_1c(1);
    }
}

void TAdMultiPlyChrSelectGC::request_scene_change() { TAdMultiChgGameModeGC::request_scene_change(); }

s32 TAdMultiPlyChrSelectGC__sub_802DC294(TAdMultiPlyChrSelectGC *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
    case 2:
        return arg0->player_plate->get_active_card_slot();
    case 1:
        return arg0->player_plate->get_active_card_slot() + 4;
    default:
        return -1;
    }
}

u8 *TAdMultiPlyChrSelectGC::format_player_number_text(s32 arg0, s32 arg1) {
    memset(player_number_text_buffer, 0, 0x80);
    sprintf((char *)player_number_text_buffer, (const char *)get_localized_text_entry(0x1F, 0), arg1 + 1);
    return player_number_text_buffer;
}

void TAdMultiPlyChrSelectGC::sub_802DC118(s32 arg1) {
    if (guide != NULL) {
        switch (arg1) {
        case -1:
            if (TAdMultiPlyChrSelectGC__sub_802C6558() == TAdMultiPlyChrSelectGC::count_ready()) {
                guide->set_line(0, "");
                guide->set_line(1, "");
                return;
            }
            guide->set_line(0, reinterpret_cast<const char *>(TAdMultiPlyChrSelectGC::format_player_number_text((saddr)this, TAdMultiPlyChrSelectGC::get_clamped_cursor())));
            guide->set_line(1, "");
            break;
        default:
            if (TAdMultiPlyChrSelectGC__sub_802C6558() == TAdMultiPlyChrSelectGC::count_ready()) {
                guide->set_line(0, "");
                guide->set_line(1, "");
                return;
            }
            guide->set_line(0, reinterpret_cast<const char *>(TAdMultiPlyChrSelectGC::format_player_number_text((saddr)this, arg1)));
            guide->set_line(1, "");
            break;
        }
    }
}

s32 TAdMultiPlyChrSelectGC::get_state_result() {
    s32 temp_r0;
    s32 var_r4;

    var_r4 = -1;
    temp_r0 = this->m_20;
    switch (temp_r0) {
    case 0:
        var_r4 = 0;
        break;
    case 12:
        var_r4 = player_plate->get_instance();
        break;
    case 29:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

void TAdMultiPlyChrSelectGC::collect_player_slots() {
    CharacterSelectionRequest request;
    u32 i;
    request.count = TAdMultiPlyChrSelectGC__sub_802C6558();
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            request.card_slots[i] = TAdMultiPlyChrSelectGC__sub_802C658C(i);
            request.player_ids[i] = i;
        } else {
            request.card_slots[i] = -1;
            request.player_ids[i] = -1;
        }
    }
    copy_selected_characters(&request);
}

s32 TAdMultiPlyChrSelectGC::create_choice_menu() {
    saddr window_menu;
    window_menu = (saddr)create_window_menu((saddr)lbl_80472890, 4, (TAdMultiPlyChrSelectGC::get_clamped_cursor()));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 2)), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 3)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 4)), 6, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 5)), 6, 3);
    ((TWindowMenu *)window_menu)->update_layout_height(224.0f);
    ((TWindowSubComCardList *)window_menu)->set_selected_index(0);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(window_menu));
    return window_menu;
}

s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *desc) {
  saddr temp_r31;
  temp_r31 = create_window_menu_default((void *)desc, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) get_localized_text_entry(0x1F, 6)), 0x21, 0);
  ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
  TQuestThread::set_status_flag_80((void *)temp_r31);
  ((TWindowSubComCard *)temp_r31)->calc_layout_height(190.0f);
  return temp_r31;
}

s32 TAdMultiPlyChrSelectGC__sub_802DBE4C(void *, s32 *desc) {
  saddr temp_r31;
  temp_r31 = create_window_menu_default((void *)desc, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) get_localized_text_entry(0x1F, 7)), 0x21, 0);
  ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
  TQuestThread::set_status_flag_80((void *)temp_r31);
  ((TWindowSubComCard *)temp_r31)->calc_layout_height(190.0f);
  return temp_r31;
}

void *TAdMultiPlyChrSelectGC::create_confirm_window(s32 slot) {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(this, slot, 0, 0);
    window->open_yes_no_prompt_with_text(get_localized_text_entry(0x1F, 8), (saddr)lbl_80472898, 196.0f);
    window->set_menu_selected_index(1);
    return window;
}

void *TAdMultiPlyChrSelectGC__sub_802DBD64(TAdMultiPlyChrSelectGC *self) {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(self, TAdMultiPlyChrSelectGC::get_clamped_cursor(), 0, 0);
    window->open_yes_no_prompt_with_text(get_localized_text_entry(0x1F, 9), (saddr)lbl_804728A0, 196.0f);
    window->set_menu_selected_index(1);
    return window;
}

void *TAdMultiPlyChrSelectGC__sub_802DBCE8(TAdMultiPlyChrSelectGC *self) {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(self, TAdMultiPlyChrSelectGC::get_clamped_cursor(), 0, 0);
    window->open_yes_no_prompt_with_text(get_localized_text_entry(0x1F, 0xA), (saddr)lbl_804728A8, 209.0f);
    window->set_menu_selected_index(1);
    return window;
}

void TAdMultiPlyChrSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

}
