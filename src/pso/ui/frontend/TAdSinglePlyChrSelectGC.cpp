#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdFadeGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_802D3AB8.h"
#include "pso/unk/text_802A1144.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"

const vec2f single_chr_select_item_rect_table[4] = {
    { 131.0f, 182.0f }, { 131.0f, 225.0f }, { 131.0f, 268.0f }, { 131.0f, 311.0f },
};
const vec2f single_chr_select_cursor_size = { 180.0f, 38.0f };
const vec2f single_chr_select_message_pos = { 432.0f, 172.0f };
const vec2f single_chr_select_yes_no_pos = { 91.0f, 160.0f };
const vec2f single_chr_select_menu_pos = { 428.0f, 132.0f };
const vec2f single_chr_select_slot_message_pos = { 428.0f, 132.0f };

struct T_802D4F2C { NJS_POINT2 p[3]; };

const char *TAdSinglePlyChrSelectGC__class_name = "TAdSinglePlyChrSelectGC";
const T_802D4F2C single_chr_select_position_table = { { { 156.0f, 421.0f }, { 299.0f, 421.0f }, { 432.0f, 421.0f } } };

void TAdSinglePlyChrSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

TWindowMenu *TAdSinglePlyChrSelectGC::create_chr_warp(s32 pos) {
    TWindowMenu *menu;

    if (can_pay_fee() != 0) {
        menu = (TWindowMenu *)create_window_menu_default(pos, 4);
        menu->add_text_entry(get_localized_text_entry(0x1E, 1), 6, 0);
        menu->add_text_entry(get_localized_text_entry(0x1E, 2), 6, 1);
        menu->add_text_entry(get_localized_text_entry(0x1E, 3), 6, 2);
        menu->add_text_entry(get_localized_text_entry(0x1E, 4), 6, 3);
    } else {
        menu = (TWindowMenu *)create_window_menu_default(pos, 3);
        menu->add_text_entry(get_localized_text_entry(0x1E, 1), 6, 0);
        menu->add_text_entry(get_localized_text_entry(0x1E, 3), 6, 2);
        menu->add_text_entry(get_localized_text_entry(0x1E, 4), 6, 3);
    }
    menu->calc_window_size();
    align_menu_entry_positions(menu);
    return menu;
}

void TAdSinglePlyChrSelectGC::finish_character_selection_transition() {
    s32 frames;
    if (this->chr_menu != NULL) {
        this->chr_menu->close();
        this->chr_menu = NULL;
    }
    if (this->create_character_prompt != NULL) {
        this->create_character_prompt->close();
        this->create_character_prompt = NULL;
    }
    if (this->meseta_prompt != NULL) {
        this->meseta_prompt->close();
        this->meseta_prompt = NULL;
    }
    if (this->replace_prompt != NULL) {
        this->replace_prompt->close();
        this->replace_prompt = NULL;
    }
    frames = this->state_timer + 1;
    this->state_timer = frames;
    if ((f32) frames > 4.5f) {
        switch (this->menu_choice) {
        case 0:
            if (((s32)TAdSinglePlyChrSelectGC::get_data()) == 0) {
                TAdMultiChgGameModeGC::request_transition();
                return;
            }
            set_queued_main_phase(0xE);
            TAdMultiChgGameModeGC::set_game_mode_changed();
            return;
        case 1:
            request_main_phase(5);
            return;
        case 2: break;
        case 3:
            set_opening_movie_purpose(1);
            request_main_phase(3);
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::close_and_change_scene() {
    s32 frames;
    TWindowMenu *menu;
    TWindowMessageYesNo *prompt;
    menu = this->chr_menu;
    if (menu != NULL) {
        menu->close();
        this->chr_menu = NULL;
    }
    prompt = this->create_character_prompt;
    if (prompt != NULL) {
        prompt->close();
        this->create_character_prompt = NULL;
    }
    frames = this->state_timer + 1;
    this->state_timer = frames;
    if ((f32) frames > 4.5f) {
        switch (TAdSinglePlyChrSelectGC::get_data()) {
        case 0:
            TAdMultiChgGameModeGC::request_scene_change();
            return;
        case 1:
            TAdMultiChgGameModeGC::set_game_mode_state();
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::handle_card_select() {

    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    if (this->replace_prompt->is_child_visible() != 0) {
        switch (this->replace_prompt->get_selected_value()) {
        case 0:
            this->menu_choice = 3;
            this->state = 0xC;
            return;
        case 1:
            this->chr_menu->clear_transition_flag();
            this->cursor->set_selection_state(1);
            this->state = 5;
            return;
        }
    } else if (this->replace_prompt->is_cancelled() != 0) {
        this->chr_menu->clear_transition_flag();
        this->cursor->set_selection_state(1);
        this->state = 5;
    }
}

void TAdSinglePlyChrSelectGC::handle_card_select2() {

    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    if (this->meseta_prompt->is_child_visible() != 0) {
        switch (this->meseta_prompt->get_selected_value()) {
        case 0:
            this->menu_choice = 1;
            this->state = 0xC;
            return;
        case 1:
            this->chr_menu->clear_transition_flag();
            this->cursor->set_selection_state(1);
            this->state = 5;
            return;
        }
    } else if (this->meseta_prompt->is_cancelled() != 0) {
        this->chr_menu->clear_transition_flag();
        this->cursor->set_selection_state(1);
        this->state = 5;
    }
}

void TAdSinglePlyChrSelectGC::update_card_input() {

    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    if (this->create_character_prompt->is_child_visible() != 0) {
        switch (this->create_character_prompt->get_selected_value()) {
        case 0:
            this->menu_choice = 3;
            this->state = 0xC;
            return;
        case 1:
            this->cursor->set_selection_state(1);
            this->state = 5;
            return;
        }
    } else if (this->create_character_prompt->is_cancelled() != 0) {
        this->cursor->set_selection_state(1);
        this->state = 5;
    }
}

void TAdSinglePlyChrSelectGC::update() {

    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    if (this->yes_no_prompt->is_child_visible() != 0) {
        switch (this->yes_no_prompt->get_selected_value()) {
        case 0:
            TAdSinglePlyChrSelectGC::clear_entry(cursor->selection_index());
            this->slot_window->get_state();
            this->slot_window->set_state(0xF);
            this->cursor->set_selection_state(1);
            this->state = 0;
            return;
        case 1:
            this->cursor->set_selection_state(1);
            this->state = 5;
            return;
        }
    } else if (this->yes_no_prompt->is_cancelled() != 0) {
        this->cursor->set_selection_state(1);
        this->state = 5;
    }
}


void TAdSinglePlyChrSelectGC::handle_menu_selection() {
    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    if (this->chr_menu->is_decided() != 0) {
        this->menu_choice = this->chr_menu->get_selected_value();
        switch (this->menu_choice) {
        case 0:
            this->state = 0xC;
            return;
        case 1:
            this->chr_menu->open();
            this->meseta_prompt = this->slot_window->create_format_message_window((saddr)&single_chr_select_message_pos, 0);
            this->state = 9;
            return;
        case 2:
            this->cursor->set_selection_state(1);
            this->state = 5;
            return;
        case 3:
            this->chr_menu->open();
            this->replace_prompt = this->slot_window->open_replace_character_prompt((saddr)&single_chr_select_message_pos, 0);
            this->state = 0xA;
            return;
        }
    } else if (this->chr_menu->is_cancelled() != 0) {
        this->cursor->set_selection_state(1);
        this->state = 5;
    }
}

// pool_data off: each window position is reached with its own lis/addi.
#pragma pool_data off
void TAdSinglePlyChrSelectGC::handle_slot_selection() {
    s32 flag_notice_shown;
    if (this->chr_menu != NULL) {
        ((TWindowBase *)(*(void * *)&this->chr_menu))->close();
        this->chr_menu = NULL;
    }
    if (this->create_character_prompt != NULL) {
        ((TWindowMessageYesNo *)(*(void * *)&this->create_character_prompt))->close();
        this->create_character_prompt = NULL;
    }
    if (this->yes_no_prompt != NULL) {
        ((TWindowMessageYesNo *)(*(void * *)&this->yes_no_prompt))->close();
        this->yes_no_prompt = NULL;
    }
    if (this->replace_prompt != NULL) {
        ((TWindowMessageYesNo *)(*(void * *)&this->replace_prompt))->close();
        this->replace_prompt = NULL;
    }
    if (this->meseta_prompt != NULL) {
        ((TWindowMessageYesNo *)(*(void * *)&this->meseta_prompt))->close();
        this->meseta_prompt = NULL;
    }
    if (this->fade_task != NULL) {
        this->fade_task->queue_destruction();
        this->fade_task = NULL;
    }
    if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0xB;
        return;
    }
    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    flag_notice_shown = 0;
    if (this->last_cursor_index != this->cursor->selection_index()) {
        player->set_field_100(1);
        if (TAdSinglePlyChrSelectGC__sub_801FE4BC(this->cursor->selection_index()) != NULL) {
            load_tables(cursor->selection_index());
            player->set_field_100(2);
            if (TAdSinglePlyChrSelectGC::check_flag(1) != 0U) {
                flag_notice_shown = 1;
                this->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 5)));
                this->guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 6)));
            }
        }
        if (flag_notice_shown == 0) {
            this->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 0)));
            this->guide->set_line(1, "");
        }
        this->last_cursor_index = cursor->selection_index();
    }
    if (cursor->confirmation_result() == 1) {
        load_tables(cursor->selection_index());
        if (TAdSinglePlyChrSelectGC::is_slot_active(cursor->selection_index()) != 0) {
            if (this->slot_window->is_character_transferred((u32)(this->cursor->selection_index())) != 0) {
                this->fade_task = new TAdFadeGC(tl_fade, NULL);
                this->yes_no_prompt = this->slot_window->open_yes_no_window((saddr)&single_chr_select_yes_no_pos, 0);
                this->state = 7;
                return;
            }
            this->chr_menu = create_chr_warp((saddr)&single_chr_select_menu_pos);
            this->state = 6;
            return;
        }
        this->create_character_prompt = this->slot_window->open_create_character_prompt((saddr)&single_chr_select_slot_message_pos);
        this->state = 8;
    }
}

#pragma pool_data reset

void TAdSinglePlyChrSelectGC::sub_802D4570() {
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0xB;
        return;
    }
    if (this->slot_window->get_state() == 1) {
        this->state = 0;
        return;
    }
    this->cursor->append_entry((void *)&single_chr_select_item_rect_table[0]);
    this->cursor->append_entry((void *)&single_chr_select_item_rect_table[1]);
    this->cursor->append_entry((void *)&single_chr_select_item_rect_table[2]);
    this->cursor->append_entry((void *)&single_chr_select_item_rect_table[3]);
    this->state = 5;
}

void TAdSinglePlyChrSelectGC::sub_802D4664() {
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0xB;
        return;
    }
    if (this->slot_window->get_state() == 1) {
        if (this->card_load_message != NULL) {
            this->card_load_message->close();
            this->card_load_message = NULL;
        }
        this->state = 0;
        return;
    }
    if (TAdPlayerLoadGC::get_instance() == 0) {
        this->state = 4;
    }
}

void TAdSinglePlyChrSelectGC::sub_802D4730() {
    s32 frames;
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0xB;
        return;
    }
    if (this->slot_window->get_state() == 1) {
        if (this->card_load_message != NULL) {
            this->card_load_message->close();
            this->card_load_message = NULL;
        }
        this->state = 0;
        return;
    }
    if (poll_memcard_result(0) == 0) {
        if (TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename) == 0) {
            if (this->card_load_message != NULL) {
                this->card_load_message->close();
                this->card_load_message = NULL;
            }
            load_guild_card_save();
            this->state = 3;
            return;
        }
        frames = this->state_timer + 1;
        this->state_timer = frames;
        if ((frames > 0xA) && (this->card_load_message == NULL)) {
            this->card_load_message = this->slot_window->create_slot_message_window(0, 0x18);
        }
    }
}
void TAdSinglePlyChrSelectGC::sub_802D486C() {
    s32 frames;
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0xB;
        return;
    }
    if (this->slot_window->get_state() == 1) {
        if (this->card_check_message != NULL) {
            this->card_check_message->close();
            this->card_check_message = NULL;
        }
        this->state = 0;
        return;
    }
    if (poll_memcard_result(0) == 0) {
        if ((u32)TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename) != 0xFFFFFF41U) {
            if (this->card_check_message != NULL) {
                this->card_check_message->close();
                this->card_check_message = NULL;
            }
            this->state = 2;
            return;
        }
        frames = this->state_timer + 1;
        this->state_timer = frames;
        if ((frames > 0xA) && (this->card_check_message == NULL)) {
            this->card_check_message = this->slot_window->create_slot_message_window(0, 0x16);
        }
    }
}


typedef void (TAdSinglePlyChrSelectGC::*Act_802D4B6C)();




void TAdSinglePlyChrSelectGC::cleanup() {
    this->cursor->reset_entries();
    player->set_field_100(1);
    this->guide->set_line(0, "");
    this->guide->set_line(1, "");
    this->last_cursor_index = -1;
    if (this->chr_menu != NULL) {
        this->chr_menu->close();
        this->chr_menu = NULL;
    }
    if (this->create_character_prompt != NULL) {
        this->create_character_prompt->close();
        this->create_character_prompt = NULL;
    }
    if (this->yes_no_prompt != NULL) {
        this->yes_no_prompt->close();
        this->yes_no_prompt = NULL;
    }
    if (this->meseta_prompt != NULL) {
        this->meseta_prompt->close();
        this->meseta_prompt = NULL;
    }
    if (this->replace_prompt != NULL) {
        this->replace_prompt->close();
        this->replace_prompt = NULL;
    }
    if (this->card_check_message != NULL) {
        this->card_check_message->close();
        this->card_check_message = NULL;
    }
    if (this->card_load_message != NULL) {
        this->card_load_message->close();
        this->card_load_message = NULL;
    }
    if (this->fade_task != NULL) {
        this->fade_task->queue_destruction();
        this->fade_task = NULL;
    }
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state = 0xB;
        return;
    }
    if (this->slot_window->get_state() == 0xE) {
        this->guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x1E, 0)));
        this->guide->set_line(1, "");
        this->state = 1;
    }
}

void TAdSinglePlyChrSelectGC::run_task() {
    TAdMultiChgGameModeGC::set_default_camera();
    static Act_802D4B6C tbl[13] = {
        &TAdSinglePlyChrSelectGC::cleanup,
        &TAdSinglePlyChrSelectGC::sub_802D486C,
        &TAdSinglePlyChrSelectGC::sub_802D4730,
        &TAdSinglePlyChrSelectGC::sub_802D4664,
        &TAdSinglePlyChrSelectGC::sub_802D4570,
        &TAdSinglePlyChrSelectGC::handle_slot_selection,
        &TAdSinglePlyChrSelectGC::handle_menu_selection,
        &TAdSinglePlyChrSelectGC::update,
        &TAdSinglePlyChrSelectGC::update_card_input,
        &TAdSinglePlyChrSelectGC::handle_card_select2,
        &TAdSinglePlyChrSelectGC::handle_card_select,
        &TAdSinglePlyChrSelectGC::close_and_change_scene,
        &TAdSinglePlyChrSelectGC::finish_character_selection_transition,
    };
    (this->*tbl[state])();
    if (state != prev_state) {
        state_timer = 0;
    }
    prev_state = state;
}

s32 TAdSinglePlyChrSelectGC::can_pay_fee() {
    player_stats stats = TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_stats;
    if (stats.meseta >= 10000) {
        return 1;
    }
    return 0;
}

void TAdSinglePlyChrSelectGC::sub_802D4E08() {
    this->state = 0;
    this->prev_state = this->state;
    this->cursor = NULL;
    this->player = NULL;
    this->fade_task = NULL;
    this->guide = NULL;
    this->chr_menu = NULL;
    this->create_character_prompt = NULL;
    this->yes_no_prompt = NULL;
    this->meseta_prompt = NULL;
    this->replace_prompt = NULL;
    this->card_check_message = NULL;
    this->card_load_message = NULL;
    this->state_timer = -1;
    this->last_cursor_index = -1;
    this->menu_choice = -1;
}

TAdSinglePlyChrSelectGC::~TAdSinglePlyChrSelectGC() {
    if (this->chr_menu != NULL) { this->chr_menu->queue_destruction(); this->chr_menu = NULL; }
    if (this->card_check_message != NULL) { this->card_check_message->queue_destruction(); this->card_check_message = NULL; }
    if (this->card_load_message != NULL) { this->card_load_message->queue_destruction(); this->card_load_message = NULL; }
    if (this->create_character_prompt != NULL) { this->create_character_prompt->queue_destruction(); this->create_character_prompt = NULL; }
    if (this->yes_no_prompt != NULL) { this->yes_no_prompt->queue_destruction(); this->yes_no_prompt = NULL; }
}

// pool_data off: the cursor rects and the title positions are each reached with their own lis/addi.
#pragma pool_data off
TAdSinglePlyChrSelectGC::TAdSinglePlyChrSelectGC(TObject *parent) : TObject(parent) {
    m_name = TAdSinglePlyChrSelectGC__class_name;
    sub_802D4E08();
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdTitleGC(this, 0);
    slot_window = TAdMultiPlyChrSelectGC::get_or_create_slot_window(this, 0);
    player = TAdMultiPlyChrSelectGC::get_or_create_player(this, 0, -1, 0);
    guide = new TAdGuideTxtGC(this);
    cursor = new TAdSelectCurGC(this,
        reinterpret_cast<const NJS_POINT2 *>(single_chr_select_item_rect_table),
        reinterpret_cast<const NJS_POINT2 *>(&single_chr_select_cursor_size));
    TAdTitleTexGC *title_tex = new TAdTitleTexGC(this);
    T_802D4F2C t = single_chr_select_position_table;
    fn_802D50B8(title_tex, &t.p[0], &t.p[1], &t.p[2]);
}
#pragma pool_data reset
