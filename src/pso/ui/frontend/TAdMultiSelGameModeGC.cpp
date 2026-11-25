#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/text_803000C8.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/enemy/dolmolm/TObjEneDolmOlm.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"

saddr multi_sel_rule;
void fn_803000C8(void) {
    if (is_split_screen() != 0) {
        switch (multi_sel_rule) {
        case 1:
            TLobby::set_player_count(1);
            break;
        case 2:
            enable_split_screen_challenge_mode();
            break;
        case 0:
            break;
        }
    }
}


#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"


typedef void (TAdMultiSelGameModeGC::*StateAction)();


struct Float8 { f32 v[8]; };

struct Float2 { f32 v[2]; };

s32 is_multiplayer_character_slot_selected(s32 slot);
saddr multi_sel_episode;

typedef struct Point3 { NJS_POINT2 p[3]; } Point3;

typedef struct Int3 { s32 v[3]; } Int3;


static const TAdSelectTxtLayout multi_sel_text_layouts[7] = {
    { -1, 133.0f, 145.0f }, { -1, 111.0f, 197.0f }, { -1, 89.0f, 250.0f }, { -1, 148.0f, 301.0f },
    { -1, 340.0f, 145.0f }, { -1, 310.0f, 197.0f }, { -1, 280.0f, 250.0f },
};
const char *TAdMultiSelGameModeGC__name = "TAdMultiSelGameModeGC";
extern Point3 multi_sel_game_mode_position;
extern Int3 lbl_80474EEC;
extern Int3 multi_sel_game_mode_arr3;

void TAdMultiSelGameModeGC::render() {  }

s32 TAdMultiSelGameModeGC::is_mode_entry_enabled(s32 menu, u32 idx) {
    switch (menu) {
    case 0:
        return idx < (u32)(get_max_difficulty_for_party_level() + 1) ? 1 : 0;
    case 1:
        return 1;
    case 2:
        if (multi_sel_rule == 1) {
            return idx == 0 ? 1 : 0;
        }
        return 1;
    default:
        return 0;
    }
}

saddr TAdMultiSelGameModeGC::build_mode_menu(s32 menu) {
    Point3 pos = multi_sel_game_mode_position;
    u32 counts[3];
    u32 n;
    TWindowMenu *r;
    u32 i;
    counts[0] = 4;
    counts[1] = 3;
    counts[2] = 2;
    {
    Int3 a = lbl_80474EEC;
    Int3 b = multi_sel_game_mode_arr3;
    n = counts[menu];
    r = create_window_menu_default(&pos.p[menu], n);
    for (i = 0; i < n; i++) {
        if (is_mode_entry_enabled(menu, i) != 0) {
            r->add_text_entry(get_localized_text_entry(0x18, i + b.v[menu]), 6, i + a.v[menu]);
        } else {
            add_gray_text_entry(r, (const char *)(get_localized_text_entry(0x18, i + b.v[menu])), 6, i + a.v[menu]);
        }
        r->update_layout_height(206.0f);
        r->set_selected_index(a.v[menu]);
        align_menu_entry_positions(r);
    }
    return (saddr)r;
    }
}

void TAdMultiSelGameModeGC::exit_keyboard_mode() { TObjEneDolmOlm::reset_count(); request_main_phase(14); }
void TAdMultiSelGameModeGC::update_transition_state() {
    switch (mode) {
    case 0:
        TAdMultiChgGameModeGC::begin_transition();
        return;
    case 1:
        TAdMultiChgGameModeGC::begin_change_game_mode();
        return;
    }
}

void TAdMultiSelGameModeGC::sub_803003A4() {
    switch (cursor->selection_index()) {
    case 0:
        if (menu->is_cancelled() != 0) {
            cursor->set_selection_state(1);
            state = 1;
        } else if (menu->is_decided() != 0) {
            game_difficulty_selection = menu->get_selected_value();
            difficulty_text->reset_slots((TAdSelectTxtLayout *)&multi_sel_text_layouts[4], game_difficulty_selection);
            cursor->set_selection_state(1);
            state = 1;
        }
        break;
    case 1:
        if (menu->is_cancelled() != 0) {
            cursor->set_selection_state(1);
            state = 1;
        } else if (menu->is_decided() != 0) {
            switch (menu->get_selected_value()) {
            case 0:
                multi_sel_rule = 0;
                break;
            case 1:
                multi_sel_rule = 1;
                break;
            case 2:
                multi_sel_rule = 2;
                break;
            }
            rule_text->reset_slots((TAdSelectTxtLayout *)&multi_sel_text_layouts[5], multi_sel_rule + 9);
            if (multi_sel_rule == 1 && multi_sel_episode == 1) {
                multi_sel_episode = 0;
                TAdStorySelectGC::set_state(0);
                episode_text->reset_slots((TAdSelectTxtLayout *)&multi_sel_text_layouts[6], multi_sel_episode + 4);
            }
            if (multi_sel_rule == 2 && game_difficulty_selection != 0) {
                game_difficulty_selection = 0;
                difficulty_text->reset_slots((TAdSelectTxtLayout *)&multi_sel_text_layouts[4], 0);
            }
            cursor->set_selection_state(1);
            state = 1;
        }
        break;
    case 2:
        if (menu->is_cancelled() != 0) {
            cursor->set_selection_state(1);
            state = 1;
        } else if (menu->is_decided() != 0) {
            switch (menu->get_selected_value()) {
            case 0:
                multi_sel_episode = 0;
                TAdStorySelectGC::set_state(0);
                break;
            case 1:
                multi_sel_episode = 1;
                TAdStorySelectGC::set_state(1);
                break;
            }
            episode_text->reset_slots((TAdSelectTxtLayout *)&multi_sel_text_layouts[6], multi_sel_episode + 4);
            cursor->set_selection_state(1);
            state = 1;
        }
        break;
    case 3:
        break;
    }
}

void TAdMultiSelGameModeGC::sub_80300648() {
    selection = cursor->selection_index();
    if (prev_selection != selection) {
        guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x18, selection)));
    }
    if (menu != NULL) {
        menu->queue_destruction();
        menu = NULL;
    }
    if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0 ||
        test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
        state = 3;
    } else if (cursor->confirmation_result() == 1) {
        switch (cursor->selection_index()) {
        case 0:
        case 1:
        case 2:
            menu = (TWindowMenu *)build_mode_menu(cursor->selection_index());
            state = 2;
            break;
        case 3:
            state = 4;
            break;
        }
    }
    prev_selection = selection;
}

void TAdMultiSelGameModeGC::sub_80300764() { state = 1; }

void TAdMultiSelGameModeGC::run_task() {
    TAdMultiChgGameModeGC::set_default_camera();
    static StateAction tbl[5] = {
        &TAdMultiSelGameModeGC::sub_80300764, &TAdMultiSelGameModeGC::sub_80300648,
        &TAdMultiSelGameModeGC::sub_803003A4, &TAdMultiSelGameModeGC::update_transition_state,
        &TAdMultiSelGameModeGC::exit_keyboard_mode,
    };
    (this->*tbl[state])();
}
s32 TAdMultiSelGameModeGC::get_max_difficulty_for_party_level() {
    s32 m;
    s32 i;
    if (multi_sel_rule == 2) {
        return 0;
    }
    m = TObjEneDolmOlm__sub_80300CF0();
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            s32 t = TAdSinglePlyChrSelectGC::get_char_table_entry(i)->m_stats.level + 1;
            if ((u32)t < (u32)m) {
                m = t;
            }
        }
    }
    if (m < 20) {
        return 0;
    }
    if (m < 40) {
        return 1;
    }
    return (m < 80 ? -1 : 0) + 3;
}

TAdMultiSelGameModeGC::~TAdMultiSelGameModeGC() {}

#pragma pool_data off
TAdMultiSelGameModeGC::TAdMultiSelGameModeGC(TObject *parent, s32 mode) : TObject(parent) {
    m_name = TAdMultiSelGameModeGC__name;
    state = 0;
    selection = 3;
    this->mode = mode;
    prev_selection = -1;
    guide = 0;
    cursor = 0;
    difficulty_text = 0;
    rule_text = 0;
    episode_text = 0;
    menu = 0;
    multi_sel_episode = TLobby::get_instance();
    if (multi_sel_rule == 1) {
        multi_sel_episode = 0;
    }
    switch (multi_sel_episode) {
    case 0:
        TAdStorySelectGC::set_state(0);
        break;
    case 1:
        TAdStorySelectGC::set_state(1);
        break;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdRayGC(this);
    new TAdTitleGC(this, 0xE);
    new TAdTitleTexGC(this);
    new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[0], 0x10);
    new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[1], 0x11);
    new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[2], 0x8);
    new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[3], 0xF);
    {
        s32 max = get_max_difficulty_for_party_level();
        game_difficulty_selection = (game_difficulty_selection <= max) ? game_difficulty_selection : 0;
    }
    if (multi_sel_rule == 2) {
        game_difficulty_selection = 0;
    }
    difficulty_text = new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[4], game_difficulty_selection);
    rule_text = new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[5], multi_sel_rule + 9);
    episode_text = new TAdSelectTxtGC(this, (TAdSelectTxtLayout *)&multi_sel_text_layouts[6], multi_sel_episode + 4);
    {
        Float2 cur = { { 442.0f, 28.0f } };
        Float8 pos = { { 144.0f, 146.0f, 114.0f, 198.0f, 84.0f, 250.0f, 54.0f, 302.0f } };
        cursor = new TAdSelectCurGC(this, reinterpret_cast<const NJS_POINT2 *>(&pos), reinterpret_cast<const NJS_POINT2 *>(&cur));
        cursor->append_entry(&pos.v[0]);
        cursor->append_entry(&pos.v[2]);
        cursor->append_entry(&pos.v[4]);
        cursor->append_entry(&pos.v[6]);
    }
    cursor->set_selection_index(selection);
    guide = new TAdGuideTxtGC(this);
    create_draw_line_ctrl(this, 0x10, 0.0f);
}
#pragma pool_data reset

__declspec(section ".rodata") Point3 multi_sel_game_mode_position = { 364.0f, 145.0f, 340.0f, 197.0f, 318.0f, 250.0f };
__declspec(section ".rodata") Int3 lbl_80474EEC = { 0 };
__declspec(section ".rodata") Int3 multi_sel_game_mode_arr3 = { 0x4, 0x8, 0xB };
