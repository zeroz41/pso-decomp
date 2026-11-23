#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/text_802A1144.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0064.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInputState.h"
#include <stdio.h>
#include "pso/ui/frontend/TAdGameStartGC.h"
#include <string.h>
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
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
}

s32 is_multiplayer_character_slot_selected(s32 arg0);
extern "C" {
s32 TAdMultiPlyChrSelectGC__count_selected_slots();
s32 TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(s32 arg0);
}

u8 player_number_text_buffer[0x80];
extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
extern s8 lbl_80472880[];
extern s8 lbl_80472888[];
}

struct Ent_802DC8A0 { u8 d[0x50]; };

struct Pair_802DC8A0 { u8 d[8]; };

extern "C" {
extern NJS_POINT2 multi_chr_select_item_rect_table[];
}

extern "C" {
s32 TAdPlyPltAnimCtrlGC__sub_80355148();
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
saddr TAdMultiPlyChrSelectGC__get_last_selected_player(void);
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
void TAdChrSelPlyPlateGC__start_selected_slot_anim(TAdChrSelPlyPlateGC *);
void TAdChrSelPlyPlateGC__select_slot_at_cursor(TAdChrSelPlyPlateGC *);
extern s32 lbl_80472850[];
extern s32 lbl_80472858[];
void clear_slot_body__23TAdSinglePlyChrSelectGCFi(s32 i);
struct MultiPlayChrSelectSlotPositions { s32 value; u8 remaining[0x14]; };

extern MultiPlayChrSelectSlotPositions multi_play_chr_select_slot_positions;
s32 TAdMultiPlyChrSelectGC__is_controller_connected(s32);
}

struct I2_802DF9B4 { s32 a, b; };

struct Blk_802DF9B4 { NJS_POINT2 a, b, c; };

extern "C" {
extern NJS_POINT2 multi_chr_select_widget_layout[];
extern u8 lbl_80472808[];
extern I2_802DF9B4 lbl_80472828[];
extern Blk_802DF9B4 multi_chr_select_layout_table[];
extern NJS_POINT2 lbl_80472848[];
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
    this->state_frames = 0;
    this->last_card_slot = -1;
    this->last_cursor = -1;
    this->guide_state = 2;
    this->swap_slot = 0;
    this->swap_search = 0;
    v = TAdMultiPlyChrSelectGC::get_clamped_cursor();
    this->cursor = v;
    exit_action = 2;
    v = 0;
    this->mode = arg1;
    *(s32 *)&this->m_74 = v;
    lbl_805D68C8 = v;
    *(s32 *)&this->unk_50 = v;
    this->m_54 = 1;
    this->a_slot = reinterpret_cast<TAdChrSelASlotGC *>(v);
    *(s32 *)&this->player_preview = v;
    player_plate = reinterpret_cast<TAdChrSelPlyPlateGC *>(v);
    *(s32 *)&this->game_start = v;
    this->select_cursor = reinterpret_cast<TAdSelectCurGC *>(v);
    this->m_7c = v;
    *(s32 *)&this->unk_80 = v;
    *(s32 *)&this->m_84 = v;
    *(s32 *)&this->unk_88 = v;
    this->m_8c = v;
    *(s32 *)&this->unk_90 = v;
    *(s32 *)&this->yes_no_dialog = v;
    *(s32 *)&this->unk_98 = v;
    this->m_3c = v;
    this->m_40 = v;
    this->m_9c = v;
    if (this->mode == 1) {
        v = 0x1D;
    }
    this->state = v;
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
        temp_r3 = (void *)TAdMultiPlyChrSelectGC__get_last_selected_player();
        TAdMultiPlyChrSelectGC::split_slot_index((saddr)temp_r3, &sp14, &sp10);
        TAdMultiPlyChrSelectGC::init();
        player_plate->set_cursor_column(sp14);
        player_plate->set_active_card_slot(sp10);
        this->m_9c = 1;
        return;
    case 4:
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(TAdMultiPlyChrSelectGC__get_last_selected_player())) == 0) {
            temp_r3 = (void *)TAdMultiPlyChrSelectGC__get_last_selected_player();
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
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    switch (this->mode) {
    case 0:
    case 2:
        new TAdTitleGC(this, 0);
        this->a_slot = TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 1);
        *(s32 *)&this->player_preview = (saddr)get_or_create_player(this, 1, -1, 0);
        break;
    case 1: {
        new TAdTitleGC(this, 8);
        this->a_slot = TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 2);
        this->b_slot = TAdChrSelBSlotGC::create(this);
        I2_802DF9B4 pos = lbl_80472828[0];
        this->select_cursor = new TAdSelectCurGC(this,
            reinterpret_cast<const NJS_POINT2 *>(&pos),
            reinterpret_cast<const NJS_POINT2 *>(lbl_80472808));
        *(s32 *)&this->player_preview = (saddr)get_or_create_player(this, 2, -1, 0);
        break;
    }
    }
    guide = new TAdGuideTxtGC(this);
    guide->set_line(0, "");
    guide->set_line(1, "");
    TAdTitleTexGC *tex = new TAdTitleTexGC(this);
    Blk_802DF9B4 blk = multi_chr_select_layout_table[0];
    fn_802D50B8(tex, &blk.a, &blk.b, &blk.c);
    game_start = new TAdGameStartGC(tl_clipout);
    NJS_POINT2 v = lbl_80472848[0];
    v.x = multi_chr_select_widget_layout[0].x;
    v.y = multi_chr_select_widget_layout[0].y;
    player_plate = TAdChrSelPlyPlateGC__create_singleton(tl_02, (vec2f *)&v);
    TAdMultiPlyChrSelectGC::get_move_effect((saddr)tl_clipout);
}

void TAdMultiPlyChrSelectGC::run_task() {
    TAdMultiPlyChrSelectGC *self = this;
    TAdMultiChgGameModeGC::set_default_camera();
    self->m_3c = 1;
    if (self->mode != 1 && TAdMultiPlyChrSelectGC__is_controller_connected(0) == 0) {
        self->m_3c = 0;
        self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xB)));
        self->guide->set_line(1, "");
    } else if (self->mode != 1 && TAdMultiPlyChrSelectGC::count_ready() < 2) {
        self->m_3c = 0;
        self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xC)));
        self->guide->set_line(1, "");
    } else {
        switch (self->mode) {
        case 0:
        case 2:
            if (self->state >= 0xC && self->state < 0x19) {
                if (TAdMultiPlyChrSelectGC__count_selected_slots() > 0) {
                    if (self->m_40 == 0) {
                        if (TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC__get_last_selected_player()) != 0) {
                            self->guide->set_line(0, reinterpret_cast<const char *>(TAdMultiPlyChrSelectGC::format_player_number_text((saddr)self, (s32)(TAdMultiPlyChrSelectGC__get_last_selected_player()))));
                            self->guide->set_line(1, "");
                        } else {
                            self->guide->set_line(0, "");
                            self->guide->set_line(1, "");
                        }
                    } else {
                        self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                        self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
                    }
                } else if (self->m_40 == 0) {
                    self->guide->set_line(0, "");
                    self->guide->set_line(1, "");
                } else {
                    self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                    self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
                }
            } else if (self->state >= 3 && TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC::get_clamped_cursor()) != 0) {
                if (self->m_40 == 0) {
                    self->sub_802DC118(TAdMultiPlyChrSelectGC::get_clamped_cursor());
                } else {
                    self->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xD)));
                    self->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1F, 0xE)));
                }
            } else if (self->m_40 == 0) {
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
    static void (TAdMultiPlyChrSelectGC::*handlers[39])() = {
        &TAdMultiPlyChrSelectGC::update_state_serial,
        &TAdMultiPlyChrSelectGC::sub_802DEDA8,
        &TAdMultiPlyChrSelectGC::update_button_input,
        &TAdMultiPlyChrSelectGC::sub_802DE7D0,
        &TAdMultiPlyChrSelectGC::update_card_confirm,
        &TAdMultiPlyChrSelectGC::update_state_option,
        &TAdMultiPlyChrSelectGC::update_card_select,
        &TAdMultiPlyChrSelectGC::update,
        &TAdMultiPlyChrSelectGC::close_windows,
        &TAdMultiPlyChrSelectGC::open_char_select,
        &TAdMultiPlyChrSelectGC::init_windows,
        &TAdMultiPlyChrSelectGC::reset_to_select,
        &TAdMultiPlyChrSelectGC::sub_802DDD08,
        &TAdMultiPlyChrSelectGC::sub_802DDBA8,
        &TAdMultiPlyChrSelectGC::update_select,
        &TAdMultiPlyChrSelectGC::update_state_wait_card,
        &TAdMultiPlyChrSelectGC::update_card_select_state,
        &TAdMultiPlyChrSelectGC::update_state,
        &TAdMultiPlyChrSelectGC::sub_802DD400,
        &TAdMultiPlyChrSelectGC::handle_confirm_state,
        &TAdMultiPlyChrSelectGC::sub_802DD2B0,
        &TAdMultiPlyChrSelectGC::update_state_move,
        &TAdMultiPlyChrSelectGC::sub_802DD010,
        &TAdMultiPlyChrSelectGC::sub_802DCF68,
        &TAdMultiPlyChrSelectGC::handle_cancel_state,
        &TAdMultiPlyChrSelectGC::update_confirm_start,
        &TAdMultiPlyChrSelectGC::update_idle_timer,
        &TAdMultiPlyChrSelectGC::sub_802DCD14,
        &TAdMultiPlyChrSelectGC::sub_802DCCA4,
        &TAdMultiPlyChrSelectGC::close_and_reset,
        &TAdMultiPlyChrSelectGC::sub_802DCA20,
        &TAdMultiPlyChrSelectGC::sub_802DC8A0,
        &TAdMultiPlyChrSelectGC::update_input_state,
        &TAdMultiPlyChrSelectGC::sub_802DC5CC,
        &TAdMultiPlyChrSelectGC::handle_input,
        &TAdMultiPlyChrSelectGC::sub_802DC440,
        &TAdMultiPlyChrSelectGC::check_cancel_input,
        &TAdMultiPlyChrSelectGC::sub_802DC310,
        &TAdMultiPlyChrSelectGC::request_scene_change,
    };
    self->prev_state = self->state;
    self->cursor = TAdMultiPlyChrSelectGC::get_clamped_cursor();
    (self->*handlers[self->state])();
    if (self->prev_state != self->state) {
        self->state_frames = 0;
    }
}

void TAdMultiPlyChrSelectGC::update_state_serial() {

    if ((u32) *(u32 *)((s8 *)this + 0x90) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x90)))->close();
        *(u32 *)((s8 *)this + 0x90) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x80) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x80)))->close();
        *(u32 *)((s8 *)this + 0x80) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x8C) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x8C)))->close();
        *(u32 *)((s8 *)this + 0x8C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x98)))->close();
        *(u32 *)((s8 *)this + 0x98) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        *(u32 *)((s8 *)this + 0x7C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x74) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x74)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x74) = 0U;
    }
    player_plate->set_state_ready();
    player_plate->reset_cursor_state();
    player_preview->set_field_100(1);
    this->last_card_slot = -1;
    this->state_frames = (this->state_frames + 1);
    if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0)) {
        if ((this->a_slot->get_state() != 0xE) && (this->state_frames > 0xA)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 0x1B;
            return;
        }
        if (TAdMultiPlyChrSelectGC__count_selected_slots() < 1) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 0x1B;
            return;
        }
        goto block_19;
    }
block_19:
    if (this->a_slot->get_state() == 0xE) {
        this->state = 1;
        if ((s32) *(s32 *)((s8 *)this + 0x9C) != 0) {
            *(s32 *)((s8 *)this + 0x9C) = 0;
            if ((u32) multi_chr_select_serial_access_state != get_field_118__22TAdEnterSerialAccessGCFv()) {
                TAdMultiPlyChrSelectGC::reset_slot_selections();
            }
        }
    }
}

void TAdMultiPlyChrSelectGC::sub_802DEDA8() {
    s32 var_r30;
    player_preview->set_index_and_close_status(0);
    if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) && (TAdMultiPlyChrSelectGC__count_selected_slots() < 1)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0x1B;
        return;
    }
    if (this->a_slot->get_state() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    player_plate->reset_cursor_state();
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &TAdMultiPlyChrSelectGC__character_slot_positions.value, 0);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8), 0);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10), 0);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x18), 0);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_play_chr_select_slot_positions.value, 1);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&multi_play_chr_select_slot_positions.value + 8), 1);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&multi_play_chr_select_slot_positions.value + 0x10), 1);
    player_plate->set_cursor_fields(0, 1);
    var_r30 = 0;
    do {
        if (is_multiplayer_character_slot_selected(var_r30) != 0) {
            if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(var_r30)) == 0) {
                TAdMultiPlyChrSelectGC::reset_slot_selections();
            }
        }
        var_r30 += 1;
    } while (var_r30 < 4);
    TAdChrSelPlyPlateGC__show_selected_slot_tags(player_plate);
    this->state = 3;
}

void TAdMultiPlyChrSelectGC::update_button_input() {
    if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) && (TAdMultiPlyChrSelectGC__count_selected_slots() < 1)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0x1B;
        return;
    }
    if (this->a_slot->get_state() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(0) == 0) {
        if (this->guide_state != 0) {
            this->guide_state = 0;
            guide->set_line(0, reinterpret_cast<const char *>((get_localized_text_entry(0x1F, 0xB))));
            guide->set_line(1, "");
        }
    } else if (TAdMultiPlyChrSelectGC::count_ready() < 2) {
        if (this->guide_state != 1) {
            this->guide_state = 1;
            guide->set_line(0, reinterpret_cast<const char *>((get_localized_text_entry(0x1F, 0xC))));
            guide->set_line(1, "");
        }
    } else {
        this->guide_state = 2;
        sub_802DC118(TAdMultiPlyChrSelectGC::get_clamped_cursor());
        this->state = 3;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DE7D0() {
    Stack_802DE7D0 stack;
    s32 temp_r30;
    s32 var_r30;
    s32 var_r3;
    u32 var_r0;
    if ((u32) *(u32 *)((s8 *)this + 0x90) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x90)))->close();
        *(u32 *)((s8 *)this + 0x90) = 0U;
    }
    if ((u32) this->m_8c != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x8C)))->close();
        this->m_8c = 0U;
    }
    if ((u32) this->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        this->m_7c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x98)))->close();
        *(u32 *)((s8 *)this + 0x98) = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x74)))->queue_destruction();
        this->m_74 = 0U;
    }
    if (TAdMultiPlyChrSelectGC__count_selected_slots() > 0) {
        var_r3 = test_pressed_buttons_packed(&controller_physical_port_bank.controllers[TAdMultiPlyChrSelectGC__get_last_selected_player()], 2);
    } else {
        var_r3 = test_pressed_buttons_packed(&controller_physical_port_bank.controllers[((s32)TAdMultiPlyChrSelectGC::get_clamped_cursor())], 2);
    }
    if (var_r3 != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (TAdMultiPlyChrSelectGC__count_selected_slots() > 0) {
            TAdMultiPlyChrSelectGC::split_slot_index(TAdMultiPlyChrSelectGC__get_last_selected_player(), &stack.spC, &stack.sp8);
            TAdMultiPlyChrSelectGC::init();
            player_plate->set_cursor_column(stack.spC);
            player_plate->set_active_card_slot(stack.sp8);
            return;
        }
        if (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) {
            this->state = 0x1B;
        }
    } else {
        var_r30 = 0;
        do {
            if ((is_multiplayer_character_slot_selected(var_r30) != 0) && (TAdMultiPlyChrSelectGC__is_controller_connected(var_r30) == 0)) {
                TAdMultiPlyChrSelectGC__deselect_slot(var_r30);
            }
            var_r30 += 1;
        } while (var_r30 < 4);
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            this->state = 0;
            return;
        }
        temp_r30 = sub_802DC294(player_plate->get_cursor());
        if ((this->last_card_slot != player_plate->get_active_card_slot()) || (this->last_cursor != player_plate->get_cursor())) {
            player_preview->set_field_100(1);
            this->m_40 = 0;
            if (TAdSinglePlyChrSelectGC__sub_801FE4BC(temp_r30) != 0U) {
                load_tables(temp_r30);
                player_preview->set_field_100(2);
                if ((TAdSinglePlyChrSelectGC::check_flag(1) != 0U) && (this->m_3c != 0)) {
                    this->m_40 = 1;
                }
            }
            this->last_card_slot = player_plate->get_active_card_slot();
            this->last_cursor = player_plate->get_cursor();
        }
        if (player_plate->get_selection() != 0) {
            load_tables(temp_r30);
            if (player_plate->get_cursor() == 1) {
                if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(temp_r30) == 0) {
                    play_sound_effect(0x52D01, 0, 0, 0);
                    player_plate->capture_card_index();
                    player_plate->restore_selection();
                    TAdChrSelPlyPlateGC__select_slot_at_cursor(player_plate);
                    if (this->a_slot != NULL) {
                        this->a_slot->queue_destruction();
                        this->a_slot = NULL;
                    }
                    this->state = 9;
                    return;
                }
                this->m_7c = this->create_choice_menu();
                this->state = 5;
                return;
            }
            if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(temp_r30) != 0) {
                if (this->a_slot->is_character_transferred(player_plate->get_active_card_slot()) != 0) {
                    var_r0 = reinterpret_cast<uaddr>(TObject::operator new(0x38));
                    if (var_r0 != 0U) {
                        var_r0 = __ct__9TAdFadeGCFP7TObjectPv(var_r0, tl_fade, 0);
                    }
                    this->m_74 = var_r0;
                    this->m_8c = this->a_slot->open_yes_no_window((saddr)((s32 *)&lbl_80472850), TAdMultiPlyChrSelectGC::get_clamped_cursor());
                    this->state = 7;
                    return;
                }
                play_sound_effect(0x52D01, 0, 0, 0);
                TAdChrSelPlyPlateGC__start_selected_slot_anim(player_plate);
                TAdChrSelPlyPlateGC__select_slot_at_cursor(player_plate);
                this->state = 0x19;
                return;
            }
            *(TWindowMessageYesNo **)((s8 *)this + 0x90) = this->a_slot->open_create_character_prompt((saddr)lbl_80472858);
            this->state = 4;
            return;
        }
        if ((player_plate->get_field_0x530() != 0) && (TAdMultiPlyChrSelectGC__count_selected_slots() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
            this->next_state = 0x1C;
            this->state = 0x1A;
            this->exit_action = 1;
            return;
        }
        if ((TAdMultiPlyChrSelectGC::count_ready() == TAdMultiPlyChrSelectGC__count_selected_slots()) && (is_multiplayer_character_slot_selected(0) != 0) && (TAdMultiPlyChrSelectGC__count_selected_slots() > 1)) {
            this->next_state = 0x1C;
            this->state = 0x1A;
            this->exit_action = 1;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_confirm() {

    if (this->a_slot->get_state() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x90)))->is_cancelled() != 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x90)))->is_child_visible() != 0) {
        switch (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x90)))->get_selected_value()) {
        case 1:
            player_plate->set_state_ready();
            this->state = 3;
            return;
        case 0:
            play_sound_effect(0x52D01, 0, 0, 0);
            TAdChrSelPlyPlateGC__start_selected_slot_anim(player_plate);
            TAdChrSelPlyPlateGC__select_slot_at_cursor(player_plate);
            lbl_805D68C8 = 1;
            if ((u32) *(u32 *)((s8 *)this + 0x90) != 0U) {
                ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x90)))->close();
                *(u32 *)((s8 *)this + 0x90) = 0U;
            }
            this->next_state = 0x1C;
            this->state = 0x1A;
            this->exit_action = 0;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_state_option() {
    s32 selected_menu_value;

    if (this->a_slot->get_state() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->is_cancelled() != 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->is_decided() != 0) {
        selected_menu_value = ((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->get_selected_value();
        switch (selected_menu_value) {
        case 0:
            play_sound_effect(0x52D01, 0, 0, 0);
            TAdChrSelPlyPlateGC__start_selected_slot_anim(player_plate);
            TAdChrSelPlyPlateGC__select_slot_at_cursor(player_plate);
            this->state = 0x19;
            return;
        case 1:
            play_sound_effect(0x52D01, 0, 0, 0);
            player_plate->capture_card_index();
            player_plate->restore_selection();
            TAdChrSelPlyPlateGC__select_slot_at_cursor(player_plate);
            player_plate->set_state_ready();
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xA;
            return;
        case 2:
            ((TWindowMenu *)(*(saddr *)((s8 *)this + 0x7C)))->open();
            *(void **)((s8 *)this + 0x98) = sub_802DBCE8();
            this->state = 6;
            return;
        case 3:
            player_plate->set_state_ready();
            this->state = 3;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_select() {

    if (this->a_slot->get_state() == 1) {
        if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
            *(u32 *)((s8 *)this + 0x7C) = 0U;
        }
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x98)))->is_cancelled() != 0) {
        ((TWindowMenu *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_transition_flag();
        ((TWindowMenu *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_flag_and_release();
        if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x98)))->close();
            *(u32 *)((s8 *)this + 0x98) = 0U;
        }
        this->state = 5;
        return;
    }
    if (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x98)))->is_child_visible() != 0) {
        switch (((TWindowMessageYesNo *)(*(uaddr *)((s8 *)this + 0x98)))->get_selected_value()) {
        case 1:
            ((TWindowMenu *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_transition_flag();
            ((TWindowMenu *)(*(uaddr *)((s8 *)this + 0x7C)))->clear_flag_and_release();
            if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
                ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x98)))->close();
                *(u32 *)((s8 *)this + 0x98) = 0U;
            }
            this->state = 5;
            return;
        case 0:
            if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
                ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x98)))->close();
                *(u32 *)((s8 *)this + 0x98) = 0U;
            }
            clear_slot_body__23TAdSinglePlyChrSelectGCFi(player_plate->get_active_card_slot() + 4);
            this->a_slot->set_state(0xF);
            this->state = 8;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update() {

    if (this->a_slot->get_state() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)((s8 *)this + 0x8C)))->is_cancelled() != 0) {
        player_plate->set_state_ready();
        this->state = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)((s8 *)this + 0x8C)))->is_child_visible() != 0) {
        switch (((TWindowMessageYesNo *)(*(saddr *)((s8 *)this + 0x8C)))->get_selected_value()) {
        case 1:
            player_plate->set_state_ready();
            this->state = 3;
            return;
        case 0:
            clear_entry__23TAdSinglePlyChrSelectGCFi(player_plate->get_active_card_slot());
            this->a_slot->set_state(0xF);
            player_plate->set_state_ready();
            this->state = 8;
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
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x8C)))->close();
        this->m_8c = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x74)))->queue_destruction();
        this->m_74 = 0U;
    }
    if (this->a_slot->get_state() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->state = 0;
        return;
    }
    if (this->a_slot->get_state() == 1) {
        this->state = 0;
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
    player_preview->set_field_100(1);
    *(s32 *)((s8 *)this + 0x50) = 1;
    this->m_54 = 0;
    open_windows();
}

void TAdMultiPlyChrSelectGC::open_windows() {
    game_start->destroy_windows();
    player_plate->set_select_mode(1);
    player_preview->set_index_and_close_status(1);
    this->a_slot = TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 2);
    this->b_slot = TAdChrSelBSlotGC::create(this);
    guide->set_line(0, "");
    guide->set_line(1, "");
    this->state = 0xC;
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
    if (TAdMultiPlyChrSelectGC__count_selected_slots() > 0) {
        if ((is_slot_active__23TAdSinglePlyChrSelectGCFUi(TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(TAdMultiPlyChrSelectGC__get_last_selected_player())) == 0) || (this->m_54 == 0)) {
            TAdMultiPlyChrSelectGC::split_slot_index(TAdMultiPlyChrSelectGC__get_last_selected_player(), &stack.spC, &stack.sp8);
            TAdMultiPlyChrSelectGC::init();
            player_plate->set_cursor_column(stack.spC);
            player_plate->set_active_card_slot(stack.sp8);
        }
    }
    if (this->b_slot != NULL) {
        this->b_slot->queue_destruction();
        this->b_slot = NULL;
    }
    if ((u32) this->m_84 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_84))->close();
        this->m_84 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_88 != 0U) {
        ((TWindowMessageYesNo *)(*(void * *)&this->unk_88))->close();
        *(u32 *)&this->unk_88 = 0U;
    }
    *(s32 *)&this->unk_50 = 0;
    this->a_slot = TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 1);
    player_plate->set_select_mode(0);
    player_plate->set_state_ready();
    if ((((TAdMultiPlyChrSelectGC *)game_start)->get_ready_state() == 0) && (TAdMultiPlyChrSelectGC__count_selected_slots() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
        temp_r31 = TAdMultiPlyChrSelectGC::count_ready();
        temp_r3 = TAdMultiPlyChrSelectGC__count_selected_slots();
        if (temp_r3 != temp_r31) {
            game_start->create_effects();
        }
    }
    this->state = 0;
}

extern "C" {
void TAdMultiPlyChrSelectGC::sub_802DDD08() {
    s32 temp_r0;
    if ((u32) *(u32 *)((s8 *)this + 0x88) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x88)))->close();
        *(u32 *)((s8 *)this + 0x88) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x8C) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x8C)))->close();
        *(u32 *)((s8 *)this + 0x8C) = 0U;
    }
    player_preview->set_field_100(1);
    if ((u32) *(u32 *)((s8 *)this + 0x74) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x74)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x74) = 0U;
    }
    this->last_card_slot = -1;
    if (this->b_slot->is_state_closing() == 0) {
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[(player_plate->get_instance())], 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xB;
            return;
        }
    }
    player_plate->clear_slot_entries(2);
    if (this->a_slot->get_state() >= 0xE) {
        player_plate->init_slot_position((saddr)&TAdMultiPlyChrSelectGC__character_slot_positions.value, 0, 1);
        player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8)), 1, 1);
        player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10)), 2, 1);
    } else {
        player_plate->init_slot_position((saddr)&TAdMultiPlyChrSelectGC__character_slot_positions.value, 0, 0);
        player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8)), 1, 0);
        player_plate->init_slot_position((saddr)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10)), 2, 0);
    }
    if (this->b_slot->get_state() == 0x14) {
        this->state = 0xD;
        return;
    }
    if (this->a_slot->get_state() == 1) {
        temp_r0 = this->state_frames + 1;
        this->state_frames = temp_r0;
        if (temp_r0 > 0xA) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            play_sound_effect(0x52F16, 0, 0, 0);
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xB;
        }
    }
}

void TAdMultiPlyChrSelectGC::sub_802DDBA8() {
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[(player_plate->get_instance())], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
        return;
    }
    if (this->b_slot->get_state() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xB;
            return;
        }
        this->state = 0xC;
        return;
    }
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[0], 2);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[1], 2);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[2], 2);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[3], 2);
    this->state = 0xE;
}

void TAdMultiPlyChrSelectGC::update_select() {
    s32 temp_r30;
    s32 instance;
    u32 var_r0;

    if ((u32) *(u32 *)&this->unk_90 != 0U) {
        ((TWindowMessageYesNo *)(*(void * *)&this->unk_90))->close();
        *(u32 *)&this->unk_90 = 0U;
    }
    if ((u32) *(u32 *)&this->m_8c != 0U) {
        ((TWindowMessageYesNo *)(*(void * *)&this->m_8c))->close();
        *(u32 *)&this->m_8c = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        ((TObject *)(*(void * *)&this->m_74))->queue_destruction();
        this->m_74 = 0U;
    }
    instance = player_plate->get_instance();
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[instance], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
        return;
    }
    if (this->b_slot->get_state() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xB;
            return;
        }
        this->state = 0xC;
        return;
    }
    temp_r30 = sub_802DC294(player_plate->get_cursor());
    if (this->last_card_slot != player_plate->get_active_card_slot()) {
        player_preview->set_field_100(1);
        this->m_40 = 0;
        if (TAdSinglePlyChrSelectGC__sub_801FE3E4(temp_r30) != 0U) {
            load_tables(temp_r30);
            player_preview->set_status_value(temp_r30);
            player_preview->set_field_100(2);
            if ((TAdSinglePlyChrSelectGC::check_slot_flags(temp_r30, 1) != 0U) && (this->m_3c != 0)) {
                this->m_40 = 1;
            }
        }
        this->last_card_slot = player_plate->get_active_card_slot();
    }
    if ((s32) *(s32 *)&this->unk_50 != 0) {
        player_preview->set_field_100(1);
        this->state = 0x15;
        return;
    }
    if (player_plate->get_selection() != 0) {
        load_tables(temp_r30);
        if (TAdSinglePlyChrSelectGC__sub_801FE800(temp_r30) != 0) {
            if (this->b_slot->is_character_transferred(temp_r30) == 0) {
                *(void **)&this->unk_88 = create_confirm_window(player_plate->get_instance());
                this->state = 0xF;
                return;
            }
            var_r0 = (uaddr)TObject::operator new(0x38);
            if (var_r0 != 0U) {
                var_r0 = __ct__9TAdFadeGCFP7TObjectPv(var_r0, tl_fade, 0);
            }
            this->m_74 = var_r0;
            *(u32 *)&this->m_8c = this->a_slot->open_yes_no_window((saddr)lbl_80472860, player_plate->get_instance());
            this->state = 0x10;
            return;
        }
        player_plate->set_state_ready();
    }
}

void TAdMultiPlyChrSelectGC::update_state_wait_card() {
    s32 active_card_slot;
    s32 card_index;

    if (this->b_slot->get_state() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        player_plate->set_state_ready();
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xB;
            return;
        }
        this->state = 0xC;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(get_card_instance()->get_instance()) == 0) {
        player_plate->set_state_ready();
        this->state = 0xC;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)&this->unk_88))->is_cancelled() != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        player_plate->set_state_ready();
        this->state = 0xC;
        return;
    }
    if (((TWindowMessageYesNo *)(*(saddr *)&this->unk_88))->is_child_visible() != 0) {
        switch (((TWindowMessageYesNo *)(*(saddr *)&this->unk_88))->get_selected_value()) {
        case 1:
            player_plate->set_state_ready();
            this->state = 0xC;
            return;
        case 0:
            active_card_slot = player_plate->get_active_card_slot();
            card_index = player_plate->get_card_index(1);
            if (try_move_char__23TAdSinglePlyChrSelectGCFii(card_index + 4, active_card_slot) != 0) {
                {
                    TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
                    if (effect != NULL) {
                        effect->setup_move_effect_params(active_card_slot + 3, card_index);
                    }
                }
                *(s32 *)&this->unk_80 = sub_802DBEC4(lbl_80472868);
                this->b_slot->set_state(0x15);
                this->state = 0x11;
                return;
            }
            player_plate->set_state_ready();
            this->state = 0xC;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_select_state() {

    if (this->b_slot->get_state() <= 1) {
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if (this->a_slot != NULL) {
                this->a_slot->queue_destruction();
                this->a_slot = NULL;
            }
            this->state = 0xB;
            return;
        }
        this->state = 0xC;
        return;
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(get_card_instance()->get_instance()) == 0) {
        player_plate->set_state_ready();
        this->state = 0xE;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_8c))->is_cancelled() != 0) {
        player_plate->set_state_ready();
        this->state = 0xE;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_8c))->is_child_visible() != 0) {
        switch (((TWindowMessageYesNo *)(this->m_8c))->get_selected_value()) {
        case 1:
            player_plate->set_state_ready();
            this->state = 0xE;
            return;
        case 0:
            clear_slot_entry__23TAdSinglePlyChrSelectGCFi(player_plate->get_active_card_slot());
            this->b_slot->set_state(0x16);
            this->state = 0x14;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_state() {
    if ((u32) *(u32 *)&this->unk_88 != 0U) {
        ((TObject *)(*(void * *)&this->unk_88))->queue_destruction();
        *(u32 *)&this->unk_88 = 0U;
    }
    if (this->b_slot->get_state() <= 1) {
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
        return;
    }
    if (this->b_slot->get_state() == 0x19) {
        this->a_slot->set_state(0xF);
        this->state = 0x13;
        return;
    }
    if (this->b_slot->get_state() == 0x18) {
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
        this->state = 0x12;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DD400() {
    if (this->b_slot->get_state() > 1) {
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[(player_plate->get_instance())], 2) != 0) {
            goto block_2;
        }
    } else {
block_2:
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::handle_confirm_state() {
    if (this->b_slot->get_state() <= 1) {
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->unk_50 = 0;
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
        return;
    }
    if (this->a_slot->get_state() == 1) {
        *(s32 *)&this->unk_50 = 0;
        this->m_54 = 1;
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DD2B0() {
    void *temp_r3;
    temp_r3 = *(void **)((s8 *)this + 0x8C);
    if ((uaddr) temp_r3 != 0U) {
        ((TWindowMessageYesNo *)temp_r3)->close();
        *(u32 *)((s8 *)this + 0x8C) = 0U;
    }
    temp_r3 = *(void **)((s8 *)this + 0x74);
    if ((uaddr) temp_r3 != 0U) {
        ((TObject *)temp_r3)->queue_destruction();
        *(u32 *)((s8 *)this + 0x74) = 0U;
    }
    if (this->b_slot->get_state() == 1) {
        player_plate->set_state_ready();
        this->state = 0xC;
    }
}

void TAdMultiPlyChrSelectGC::update_state_move() {
    u32 iter;
    TAdChrMoveEffectGC *effect;
    s32 instance;
    s32 ret;
    s32 temp_r3;

    if (this->b_slot->get_state() <= 1) {
        this->state = 0xC;
        return;
    }
    instance = player_plate->get_instance();
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[instance], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
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
        temp_r3 = sub_802DC294(player_plate->get_cursor());
        load_tables(temp_r3);
        player_preview->set_status_value(temp_r3);
        player_preview->set_field_100(2);
        *(s32 *)&this->unk_80 = sub_802DBEC4(lbl_80472870);
        this->a_slot->set_state(0x11);
        this->state = 0x16;
        return;
    }
    iter += 1;
    if (iter >= 4U) {
        this->m_54 = 0;
        if ((u32) this->m_84 == 0U) {
            this->m_84 = sub_802DBE4C(lbl_80472878);
        }
        this->state = 0xE;
        return;
    }
    goto loop_7;
}

void TAdMultiPlyChrSelectGC::sub_802DD010() {
    if (this->b_slot->get_state() <= 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
        return;
    }
    if (this->a_slot->get_state() == 0x14) {
        this->state = 0x18;
        this->b_slot->set_state(0x1B);
        return;
    }
    if (this->a_slot->get_state() == 0x13) {
        if ((u32) *(u32 *)((s8 *)this + 0x80) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x80)))->queue_destruction();
            *(u32 *)((s8 *)this + 0x80) = 0U;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        this->state = 0x17;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DCF68() {
    if (this->b_slot->get_state() > 1) {
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[(player_plate->get_instance())], 2) == 0) {
            return;
        }
    }
    {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::handle_cancel_state() {
    if (this->b_slot->get_state() <= 1) {
        if (this->a_slot->get_state() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        player_plate->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
        return;
    }
    if (this->b_slot->get_state() == 0x1D) {
        *(s32 *)&this->unk_50 = 0;
        this->m_54 = 1;
        player_plate->set_state_ready();
        if (this->a_slot != NULL) {
            this->a_slot->queue_destruction();
            this->a_slot = NULL;
        }
        this->state = 0xB;
    }
}

void TAdMultiPlyChrSelectGC::update_confirm_start() {
    s32 temp_r31;
    s32 temp_r3;

    if ((((TAdMultiPlyChrSelectGC *)game_start)->get_ready_state() == 0) && (TAdMultiPlyChrSelectGC__count_selected_slots() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
        temp_r31 = TAdMultiPlyChrSelectGC::count_ready();
        temp_r3 = TAdMultiPlyChrSelectGC__count_selected_slots();
        if (temp_r3 != temp_r31) {
            game_start->create_effects();
        }
    }
    player_plate->set_state_ready();
    this->state = 3;
}

void TAdMultiPlyChrSelectGC::update_idle_timer() {
    s32 temp_r4;
    temp_r4 = this->state_frames + 1;
    this->state_frames = temp_r4;
    if (((f32) temp_r4 > 4.5f) && (TAdMultiPlyChrSelectGC::get_selected_slot() != 0U) && (TAdPlyPltAnimCtrlGC__sub_80355148() == 0)) {
        this->state = this->next_state;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DCD14() {

    TAdMultiPlyChrSelectGC::reset_slot_selections();
    switch (this->mode) {
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

void TAdMultiPlyChrSelectGC::sub_802DCCA4() {
    multi_chr_select_serial_access_state = get_field_118__22TAdEnterSerialAccessGCFv();
    switch (exit_action) {
    case 2:
        break;
    case 0:
        set_opening_movie_purpose(1);
        request_main_phase(3);
        break;
    case 1:
        collect_player_slots();
        TAdMultiChgGameModeGC::begin_transition();
        break;
    }
}

void TAdMultiPlyChrSelectGC::close_and_reset() {
    if ((u32) *(u32 *)&this->unk_80 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_80))->close();
        *(u32 *)&this->unk_80 = 0U;
    }
    if ((u32) this->yes_no_dialog != 0U) {
        ((TWindowMessageYesNo *)(*(void * *)&this->yes_no_dialog))->close();
        this->yes_no_dialog = 0U;
    }
    player_plate->reset_cursor_state();
    if (this->select_cursor != NULL) {
        this->select_cursor->disallow_rendering();
    }
    player_preview->set_field_100(1);
    guide->set_line(0, "");
    guide->set_line(1, "");
    this->last_card_slot = -1;
    if ((this->b_slot->is_state_closing() == 0) && (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->next_state = 0x1B;
        this->state = 0x1A;
        return;
    }
    if ((this->a_slot->get_state() == 0xE) && (this->b_slot->get_state() == 0x14)) {
        this->state = 0x1E;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DCA20() {
    player_preview->set_index_and_close_status(2);
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->next_state = 0x1B;
        this->state = 0x1A;
        return;
    }
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0;
        }
        this->state = 0x1D;
        return;
    }
    player_plate->reset_cursor_state();
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &TAdMultiPlyChrSelectGC__character_slot_positions.value, 1);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8), 1);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10), 1);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[0], 2);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[1], 2);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[2], 2);
    TAdChrSelPlyPlateGC__add_slot_position(player_plate, &multi_chr_select_item_rect_table[3], 2);
    this->state = 0x1F;
}

void TAdMultiPlyChrSelectGC::sub_802DC8A0() {
    u32 i;
    s32 k;
    if (*(u32 *)((s8 *)this + 0x80) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x80)))->close();
        *(u32 *)((s8 *)this + 0x80) = 0U;
    }
    if (*(u32 *)((s8 *)this + 0x84) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x84)))->close();
        *(u32 *)((s8 *)this + 0x84) = 0U;
    }
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[player_plate->get_instance()], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->next_state = 0x1B;
        this->state = 0x1A;
        return;
    }
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0U;
        }
        this->state = 0x1D;
        return;
    }
    for (i = this->swap_search; i < 3; i++) {
        k = i + 4;
        this->swap_slot = k;
        load_tables(k);
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(k) != 0) {
            player_preview->set_field_100(2);
            if (this->select_cursor != NULL) {
                this->select_cursor->allow_rendering();
            }
            this->select_cursor->reset_entries();
            this->select_cursor->append_entry(&((Pair_802DC8A0 *)&TAdMultiPlyChrSelectGC__character_slot_positions)[i]);
            this->select_cursor->lock_navigation();
            this->swap_search = i;
            *(void **)((s8 *)this + 0x94) = sub_802DBD64();
            this->state = 0x20;
            return;
        }
    }
    this->state = 0x26;
}

void TAdMultiPlyChrSelectGC::update_input_state() {

    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) this->yes_no_dialog != 0U) {
            ((TWindowMessageYesNo *)(*(void * *)&this->yes_no_dialog))->close();
            this->yes_no_dialog = 0U;
        }
        this->swap_search++;
        this->state = 0x1F;
        return;
    }
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0;
        }
        if ((u32) this->yes_no_dialog != 0U) {
            ((TWindowMessageYesNo *)(*(void * *)&this->yes_no_dialog))->close();
            this->yes_no_dialog = 0U;
        }
        this->state = 0x1D;
        return;
    }
    if (((TWindowMessageYesNo *)(this->yes_no_dialog))->is_child_visible() != 0) {
        switch (((TWindowMessageYesNo *)(this->yes_no_dialog))->get_selected_value()) {
        case 0:
            this->state = 0x21;
            return;
        case 1:
            if ((u32) this->yes_no_dialog != 0U) {
                ((TWindowMessageYesNo *)(*(void * *)&this->yes_no_dialog))->close();
                this->yes_no_dialog = 0U;
            }
            this->swap_search++;
            this->state = 0x1F;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::sub_802DC5CC() {
    u32 var_r30;
    TAdChrMoveEffectGC *effect;
    if ((u32) *(u32 *)((s8 *)this + 0x94) != 0U) {
        ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x94)))->close();
        *(u32 *)((s8 *)this + 0x94) = 0U;
    }
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->next_state = 0x1B;
        this->state = 0x1A;
        return;
    }
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0;
        }
        this->state = 0x1D;
        return;
    }
    var_r30 = 0U;
loop_9:
    if (swap_characters__23TAdSinglePlyChrSelectGCFii(var_r30, this->swap_slot) != 0) {
        if ((u32) *(u32 *)((s8 *)this + 0x84) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)this + 0x84)))->close();
            *(u32 *)((s8 *)this + 0x84) = 0U;
        }
        effect = TAdMultiPlyChrSelectGC::get_global_state();
        if (effect != NULL) {
            effect->setup_move_effect_params(this->swap_slot - 4, var_r30 + 3);
        }
        load_tables(this->swap_slot);
        player_preview->set_status_value(var_r30);
        *(s32 *)((s8 *)this + 0x80) = sub_802DBEC4((s32*)lbl_80472880);
        player_preview->set_field_100(1);
        this->a_slot->set_state(0x11);
        this->state = 0x23;
        return;
    }
    var_r30 += 1;
    if (var_r30 >= 4U) {
        player_preview->set_field_100(1);
        if ((u32) *(u32 *)((s8 *)this + 0x84) == 0U) {
            *(u32 *)((s8 *)this + 0x84) = sub_802DBE4C((s32*)lbl_80472888);
        }
        this->state = 0x22;
        return;
    }
    goto loop_9;
}

void TAdMultiPlyChrSelectGC::handle_input() {
    void *context;

    if ((u32) this->yes_no_dialog != 0U) {
        ((TWindowMessageYesNo *)(*(void * *)&this->yes_no_dialog))->close();
        this->yes_no_dialog = 0U;
    }
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0;
        }
        this->state = 0x1D;
        return;
    }
    context = &controller_physical_port_bank.controllers[0];
    if ((test_pressed_buttons_packed(context, 4) != 0) || (test_pressed_buttons_packed(context, 2) != 0)) {
        this->state = 0x1F;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DC440() {
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        this->state = 0x1D;
        return;
    }
    if (this->a_slot->get_state() == 0x14) {
        this->b_slot->set_state(0x1B);
        this->state = 0x25;
        return;
    }
    if (this->a_slot->get_state() == 0x13) {
        if ((u32) *(u32 *)((s8 *)this + 0x80) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x80)))->queue_destruction();
            *(u32 *)((s8 *)this + 0x80) = 0U;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        player_plate->reset_cursor_state();
        this->state = 0x24;
    }
}

void TAdMultiPlyChrSelectGC::check_cancel_input() {
    if ((this->b_slot->get_state() < 0x14) || (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0)) {
        TAdPlayerLoadGC::set_state(1);
        this->swap_search = 0;
        this->state = 0x1D;
    }
}

void TAdMultiPlyChrSelectGC::sub_802DC310() {
    if ((u32) *(u32 *)((s8 *)this + 0x88) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x88)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x88) = 0U;
    }
    if (this->b_slot->get_state() < 0x14) {
        if (this->a_slot->get_state() < 0xE) {
            this->swap_search = 0;
        }
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        this->state = 0x1D;
        return;
    }
    if (this->b_slot->get_state() == 0x1D) {
        {
            TAdChrMoveEffectGC *effect = TAdMultiPlyChrSelectGC::get_global_state();
            if (effect != NULL) {
                effect->clear_entries();
            }
        }
        this->state = 0x1D;
        this->a_slot->set_state(1);
        this->b_slot->set_state(1);
    }
}

void TAdMultiPlyChrSelectGC::request_scene_change() { TAdMultiChgGameModeGC::request_scene_change(); }

s32 TAdMultiPlyChrSelectGC::sub_802DC294(s32 arg1) {
    switch (arg1) {
    case 0:
    case 2:
        return this->player_plate->get_active_card_slot();
    case 1:
        return this->player_plate->get_active_card_slot() + 4;
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
            if (TAdMultiPlyChrSelectGC__count_selected_slots() == TAdMultiPlyChrSelectGC::count_ready()) {
                guide->set_line(0, "");
                guide->set_line(1, "");
                return;
            }
            guide->set_line(0, reinterpret_cast<const char *>(TAdMultiPlyChrSelectGC::format_player_number_text((saddr)this, TAdMultiPlyChrSelectGC::get_clamped_cursor())));
            guide->set_line(1, "");
            break;
        default:
            if (TAdMultiPlyChrSelectGC__count_selected_slots() == TAdMultiPlyChrSelectGC::count_ready()) {
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
    s32 instance;

    instance = -1;
    switch (this->state) {
    case 0:
        instance = 0;
        break;
    case 12:
        instance = player_plate->get_instance();
        break;
    case 29:
        instance = 0;
        break;
    }
    return instance;
}

void TAdMultiPlyChrSelectGC::collect_player_slots() {
    CharacterSelectionRequest request;
    u32 i;
    request.count = TAdMultiPlyChrSelectGC__count_selected_slots();
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            request.card_slots[i] = TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(i);
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

s32 TAdMultiPlyChrSelectGC::sub_802DBEC4(s32 *desc) {
  saddr window_menu_default;
  window_menu_default = create_window_menu_default((void *)desc, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)((int) get_localized_text_entry(0x1F, 6)), 0x21, 0);
  ((TAdChrSelASlotGC *)window_menu_default)->set_flag_40();
  TQuestThread::set_status_flag_80((void *)window_menu_default);
  ((TWindowSubComCard *)window_menu_default)->calc_layout_height(190.0f);
  return window_menu_default;
}

s32 TAdMultiPlyChrSelectGC::sub_802DBE4C(s32 *desc) {
  saddr window_menu_default;
  window_menu_default = create_window_menu_default((void *)desc, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu_default, (int)((int) get_localized_text_entry(0x1F, 7)), 0x21, 0);
  ((TAdChrSelASlotGC *)window_menu_default)->set_flag_40();
  TQuestThread::set_status_flag_80((void *)window_menu_default);
  ((TWindowSubComCard *)window_menu_default)->calc_layout_height(190.0f);
  return window_menu_default;
}

void *TAdMultiPlyChrSelectGC::create_confirm_window(s32 slot) {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(this, slot, 0, 0);
    window->open_yes_no_prompt_with_text(get_localized_text_entry(0x1F, 8), (saddr)lbl_80472898, 196.0f);
    window->set_menu_selected_index(1);
    return window;
}

void *TAdMultiPlyChrSelectGC::sub_802DBD64() {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(this, TAdMultiPlyChrSelectGC::get_clamped_cursor(), 0, 0);
    window->open_yes_no_prompt_with_text(get_localized_text_entry(0x1F, 9), (saddr)lbl_804728A0, 196.0f);
    window->set_menu_selected_index(1);
    return window;
}

void *TAdMultiPlyChrSelectGC::sub_802DBCE8() {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(this, TAdMultiPlyChrSelectGC::get_clamped_cursor(), 0, 0);
    window->open_yes_no_prompt_with_text(get_localized_text_entry(0x1F, 0xA), (saddr)lbl_804728A8, 209.0f);
    window->set_menu_selected_index(1);
    return window;
}

void TAdMultiPlyChrSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

}
