#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdChrSelMovePlateGC.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include <stdio.h>
#include <string.h>
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

static const ChrSelPlateLayout chr_sel_a_slot_plate_layout = { 180.0f, 38.0f, { 0xDD, 0x90, 0x48, 0x00 }, 0 };
// Plate positions of the four entries (slot kind 0)
static const CharacterSlotPosition chr_sel_a_slot_plate_positions[4] = {
    { 131.0f, 182.0f }, { 131.0f, 225.0f }, { 131.0f, 268.0f }, { 131.0f, 311.0f },
};
static const CharacterSlotPosition chr_sel_a_slot_label_pos = { 126.0f, 156.0f };
static const CharacterSlotPosition chr_sel_a_slot_header_pos = { 134.0f, 118.0f };
static const ChrSelPlateLayout chr_sel_a_slot_plate_layout_b = { 180.0f, 38.0f, { 0x36, 0xBC, 0x30, 0x01 }, 0 };
static const CharacterSlotPosition chr_sel_a_slot_left_plate_positions[4] = {
    { 28.0f, 182.0f }, { 28.0f, 225.0f }, { 28.0f, 268.0f }, { 28.0f, 311.0f },
};
static const CharacterSlotPosition chr_sel_a_slot_right_plate_positions[3] = {
    { 234.0f, 182.0f }, { 234.0f, 225.0f }, { 234.0f, 268.0f },
};
static const CharacterSlotPosition chr_sel_a_slot_left_label_pos = { 23.0f, 156.0f };
static const CharacterSlotPosition chr_sel_a_slot_right_label_pos = { 228.0f, 154.0f };
static const CharacterSlotPosition chr_sel_a_slot_left_header_pos = { 35.0f, 118.0f };
// Message window positions passed to copy_vec2
static const CharacterSlotPosition chr_sel_a_slot_message_pos = { 128.0f, 182.0f };
static const CharacterSlotPosition chr_sel_a_slot_left_message_pos = { 24.0f, 182.0f };
static const CharacterSlotPosition chr_sel_b_slot_message_pos = { 431.0f, 182.0f };
const char *TAdChrSelASlotGC__name = "TAdChrSelASlotGC";

struct S_8030C45C { s32 x; s32 y; s32 state; };

TAdChrSelASlotGC *TAdChrSel__global_slot_data;
extern PlayerSlotLabel chr_select_a_slot_entry;
extern char char_select_format_message_buffer[];

void TAdChrSelASlotGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

s32 TAdChrSelASlotGC::is_character_transferred(u32 i) {
    S_8030C45C *e = (S_8030C45C *)TAdSinglePlyChrSelectGC__sub_801FE4BC(i);
    if (e == 0) {
        return 0;
    }
    return e->state == 1 ? 1 : 0;
}

s32 TAdChrSelASlotGC::get_plate_value_for_slot(s32 k) {
    switch (k) {
    case 0:
    case 1:
        return this->plate_a->is_slot_value_ready(2);
    case 2:
        return this->plate_b->is_slot_value_ready(2);
    }
    return 0;
}

PlayerSlotLabel *TAdChrSelASlotGC::build_slot_entry(s32 index, s32 slot, void *pos) {
    S_8030C45C *e = (S_8030C45C *)TAdSinglePlyChrSelectGC__sub_801FE4BC(slot);
    chr_select_a_slot_entry.slot = index;
    chr_select_a_slot_entry.name = reinterpret_cast<const char *>(
        e != NULL ? e->x : get_localized_text_entry(0x16, 0x1C));
    chr_select_a_slot_entry.level = e != NULL ? e->y + 1 : 0;
    copy_vec2(&chr_select_a_slot_entry.position, pos);
    return &chr_select_a_slot_entry;
}

#pragma pool_data off
TWindowBase *TAdChrSelASlotGC::create_format_failed_window(s32 kind) {
    NJS_POINT2 pos;
    TWindowBase *w;
    switch (kind) {
    case 0:
        copy_vec2(&pos, (void *)(this->mode == 2 ? &chr_sel_a_slot_left_message_pos : &chr_sel_a_slot_message_pos));
        break;
    case 1:
        copy_vec2(&pos, (void *)&chr_sel_b_slot_message_pos);
        break;
    }
    w = (TWindowBase *)create_window_menu_default((saddr)&pos, 1);
    ((TWindowMenu *)w)->add_text_entry(get_localized_text_entry(0x16, kind + 0x2B), 0x20, 0);
    ((TWindowMenu *)w)->set_flag_40();
    TQuestThread::set_status_flag_80(w);
    ((TWindowSubComCard *)w)->calc_layout_height(190.0f);
    return w;
}

TWindowBase *TAdChrSelASlotGC::create_not_formatted_window(s32 kind) {
    NJS_POINT2 pos;
    TWindowBase *w;
    switch (kind) {
    case 0:
        copy_vec2(&pos, (void *)(this->mode == 2 ? &chr_sel_a_slot_left_message_pos : &chr_sel_a_slot_message_pos));
        break;
    case 1:
        copy_vec2(&pos, (void *)&chr_sel_b_slot_message_pos);
        break;
    }
    w = (TWindowBase *)create_window_menu_default((saddr)&pos, 1);
    ((TWindowMenu *)w)->add_text_entry(get_localized_text_entry(0x16, kind + 0x29), 0x20, 0);
    ((TWindowMenu *)w)->set_flag_40();
    TQuestThread::set_status_flag_80(w);
    ((TWindowSubComCard *)w)->calc_layout_height(190.0f);
    return w;
}

TWindowBase *TAdChrSelASlotGC::create_formatted_window(s32 kind) {
    NJS_POINT2 pos;
    TWindowBase *w;
    switch (kind) {
    case 0:
        copy_vec2(&pos, (void *)(this->mode == 2 ? &chr_sel_a_slot_left_message_pos : &chr_sel_a_slot_message_pos));
        break;
    case 1:
        copy_vec2(&pos, (void *)&chr_sel_b_slot_message_pos);
        break;
    }
    w = (TWindowBase *)create_window_menu_default((saddr)&pos, 1);
    ((TWindowMenu *)w)->add_text_entry(get_localized_text_entry(0x16, kind + 0x27), 0x20, 0);
    ((TWindowMenu *)w)->set_flag_40();
    TQuestThread::set_status_flag_80(w);
    ((TWindowSubComCard *)w)->calc_layout_height(190.0f);
    return w;
}

TWindowMessageYesNo *TAdChrSelASlotGC::open_confirm_message(s32 kind, s32 client_id) {
    NJS_POINT2 pos;
    TWindowMessageYesNo *w;
    w = TWindowMessageYesNo::create(this, client_id, 0, 0);
    switch (kind) {
    case 0:
        copy_vec2(&pos, (void *)(this->mode == 2 ? &chr_sel_a_slot_left_message_pos : &chr_sel_a_slot_message_pos));
        break;
    case 1:
        copy_vec2(&pos, (void *)&chr_sel_b_slot_message_pos);
        break;
    }
    w->open_yes_no_prompt_with_text(get_localized_text_entry(0x16, kind + 0x25), (saddr)&pos, 190.0f);
    w->set_menu_selected_index(1);
    return w;
}

TWindowMessageYesNo *TAdChrSelASlotGC::create_message_window(s32 kind, s32 client_id) {
    NJS_POINT2 pos;
    TWindowMessageYesNo *w;
    w = TWindowMessageYesNo::create(this, client_id, 0, 0);
    switch (kind) {
    case 0:
        copy_vec2(&pos, (void *)(this->mode == 2 ? &chr_sel_a_slot_left_message_pos : &chr_sel_a_slot_message_pos));
        break;
    case 1:
        copy_vec2(&pos, (void *)&chr_sel_b_slot_message_pos);
        break;
    }
    w->open_yes_no_prompt_with_text(get_localized_text_entry(0x16, kind + 0x23), (saddr)&pos, 190.0f);
    w->set_menu_selected_index(1);
    return w;
}

TWindowMessageYesNo *TAdChrSelASlotGC::create_format_message_window(s32 pos, s32 client_id) {
    TWindowMessageYesNo *w;
    w = TWindowMessageYesNo::create(this, client_id, 0, 0);
    memset(char_select_format_message_buffer, 0, 0x100);
    sprintf(char_select_format_message_buffer, (const char *)get_localized_text_entry(0x16, 0x1E), 10000);
    w->open_yes_no_prompt_with_text((saddr)char_select_format_message_buffer, pos, 193.0f);
    w->set_menu_selected_index(1);
    return w;
}

#pragma push
#pragma fp_contract on
TWindowMessageYesNo *TAdChrSelASlotGC::open_replace_character_prompt(s32 pos, s32 client_id) {
    TWindowMessageYesNo *w;
    w = TWindowMessageYesNo::create(this, client_id, 0, 0);
    w->open_yes_no_prompt_with_text(get_localized_text_entry(0x16, 0x1D), pos, 193.0f);
    w->set_menu_selected_index(1);
    return w;
}
#pragma pop

TWindowMessageYesNo *TAdChrSelASlotGC::open_yes_no_window(s32 pos, s32 client_id) {
    TWindowMessageYesNo *window;

    play_sound_effect(0x53F06, 0, 0, 0);
    window = TWindowMessageYesNo::create(this, client_id, 0, 0);
    window->open_yes_no_prompt_with_text((s32)(get_localized_text_entry(0x16, 0x1B)), pos, 458.0f);
    window->set_menu_selected_index(1);
    ((TWindowSubComCard *)window)->free_windows();
    return window;
}

TWindowMessageYesNo *TAdChrSelASlotGC::open_create_character_prompt(s32 pos) {
    TWindowMessageYesNo *w;
    w = TWindowMessageYesNo::create(this, TAdMultiPlyChrSelectGC::get_clamped_cursor(), 0, 0);
    w->open_yes_no_prompt_with_text(get_localized_text_entry(0x16, 0x1A), pos, 196.0f);
    w->set_menu_selected_index(1);
    ((TWindowSubComCard *)w)->free_windows();
    return w;
}

TWindowBase *TAdChrSelASlotGC::create_slot_message_window(s32 kind, s32 text) {
    NJS_POINT2 pos;
    TWindowBase *w;
    switch (kind) {
    case 0:
        copy_vec2(&pos, (void *)(this->mode == 2 ? &chr_sel_a_slot_left_message_pos : &chr_sel_a_slot_message_pos));
        break;
    case 1:
        copy_vec2(&pos, (void *)&chr_sel_b_slot_message_pos);
        break;
    }
    w = (TWindowBase *)create_window_menu_default((saddr)&pos, 1);
    ((TWindowMenu *)w)->add_text_entry(get_localized_text_entry(0x16, text), 0x21, 0);
    ((TWindowMenu *)w)->set_flag_40();
    TQuestThread::set_status_flag_80(w);
    ((TWindowSubComCard *)w)->calc_layout_height(190.0f);
    return w;
}
#pragma pool_data reset

void TAdChrSelASlotGC::sub_8030CBD0() {}
void TAdChrSelASlotGC::sub_8030CBD4() {}
void TAdChrSelASlotGC::update_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if ((u32) (TAdPlayerLoadGC::get_load_result(0) + 0x10000) == 0xFF81U) {
            this->state = 0x13;
            return;
        }
        this->state = 0x14;
    }
}
void TAdChrSelASlotGC::set_state() {
    TAdSinglePlyChrSelectGC::write_encrypted_save();
    TAdSinglePlyChrSelectGC__sub_801FDAAC();
    this->state = 0x12;
}
void TAdChrSelASlotGC::check_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        this->state = 1;
    }
}
void TAdChrSelASlotGC::init_selection() {
    TAdSinglePlyChrSelectGC::write_encrypted_save();
    TAdSinglePlyChrSelectGC__sub_801FDAAC();
    this->state = 0x10;
}
void TAdChrSelASlotGC::sub_8030CCE0() {}

#pragma pool_data off
void TAdChrSelASlotGC::populate_slot_entries() {
    u32 i;
    u32 j;

    if (this->get_plate_value_for_slot(this->mode) != 0) {
        switch (this->mode) {
        case 0:
            slot_gc->init_slot_entry(0, (void *)&chr_sel_a_slot_label_pos);
            for (i = 0; i < 4; i++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(this->player_items, build_slot_entry(i, i, (void *)&chr_sel_a_slot_plate_positions[i]));
                if (is_character_transferred(i)) {
                    this->move_plate->add_plate_rect(const_cast<CharacterSlotPosition *>(&chr_sel_a_slot_plate_positions[i]));
                }
            }
            break;
        case 1:
            slot_gc->init_slot_entry(0, (void *)&chr_sel_a_slot_left_label_pos);
            slot_gc->init_slot_entry(1, (void *)&chr_sel_a_slot_right_label_pos);
            for (i = 0; i < 4; i++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(this->player_items, build_slot_entry(i, i, (void *)&chr_sel_a_slot_left_plate_positions[i]));
                if (is_character_transferred(i)) {
                    this->move_plate->add_plate_rect(const_cast<CharacterSlotPosition *>(&chr_sel_a_slot_left_plate_positions[i]));
                }
            }
            for (j = 0; j < 3; j++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(this->player_items_b, build_slot_entry(j, j + 4, (void *)&chr_sel_a_slot_right_plate_positions[j]));
            }
            break;
        case 2:
            slot_gc->init_slot_entry(1, (void *)&chr_sel_a_slot_left_label_pos);
            for (j = 0; j < 3; j++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(this->player_items_b, build_slot_entry(j, j + 4, (void *)&chr_sel_a_slot_left_plate_positions[j]));
            }
            break;
        }
        this->state = 0xE;
    }
}

void TAdChrSelASlotGC::push_plate_positions() {
    if (this->player_load->get_slot_index() >= 0xC) {
        switch (this->mode) {
        case 0:
            this->plate_a->push_plate_position(&chr_sel_a_slot_plate_positions[0]);
            this->plate_a->push_plate_position(&chr_sel_a_slot_plate_positions[1]);
            this->plate_a->push_plate_position(&chr_sel_a_slot_plate_positions[2]);
            this->plate_a->push_plate_position(&chr_sel_a_slot_plate_positions[3]);
            break;
        case 1:
            this->plate_a->push_plate_position(&chr_sel_a_slot_left_plate_positions[0]);
            this->plate_a->push_plate_position(&chr_sel_a_slot_left_plate_positions[1]);
            this->plate_a->push_plate_position(&chr_sel_a_slot_left_plate_positions[2]);
            this->plate_a->push_plate_position(&chr_sel_a_slot_left_plate_positions[3]);
            this->plate_b->push_plate_position(&chr_sel_a_slot_right_plate_positions[0]);
            this->plate_b->push_plate_position(&chr_sel_a_slot_right_plate_positions[1]);
            this->plate_b->push_plate_position(&chr_sel_a_slot_right_plate_positions[2]);
            this->draw_line[1] = create_draw_line_ctrl(this, 0x12, 0.0f);
            this->draw_line[2] = create_draw_line_ctrl(this, 0x13, 0.0f);
            break;
        case 2:
            this->plate_b->push_plate_position(&chr_sel_a_slot_left_plate_positions[0]);
            this->plate_b->push_plate_position(&chr_sel_a_slot_left_plate_positions[1]);
            this->plate_b->push_plate_position(&chr_sel_a_slot_left_plate_positions[2]);
            break;
        }
        this->state = 0xD;
    }
}
#pragma pool_data reset

void TAdChrSelASlotGC::update_window_78() {
    if (this->player_load->get_slot_index() > 0xB) {
        if (this->wait_message[9] != NULL) {
            this->wait_message[9]->close();
            this->wait_message[9] = NULL;
        }
        this->state = 0xC;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[9] == NULL)) {
        this->wait_message[9] = create_slot_message_window(0, 0x12);
    }
}

void TAdChrSelASlotGC::update_window_7c() {
    if (this->player_load->get_slot_index() > 0xA) {
        if (this->wait_message[10] != NULL) {
            this->wait_message[10]->close();
            this->wait_message[10] = NULL;
        }
        this->state = 0xB;
        return;
    }
    if ((this->state_frames > 0xF) && (this->wait_message[10] == NULL)) {
        this->wait_message[10] = create_slot_message_window(0, 0x14);
    }
}

void TAdChrSelASlotGC::update_window_74() {
    if (this->player_load->get_slot_index() > 8) {
        if (this->wait_message[8] != NULL) {
            this->wait_message[8]->close();
            this->wait_message[8] = NULL;
        }
        this->state = 0xA;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[8] == NULL)) {
        this->wait_message[8] = create_slot_message_window(0, 0x10);
    }
}

void TAdChrSelASlotGC::update_window_70() {
    if (this->player_load->get_slot_index() > 7) {
        if (this->wait_message[7] != NULL) {
            this->wait_message[7]->close();
            this->wait_message[7] = NULL;
        }
        this->state = 9;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[7] == NULL)) {
        this->wait_message[7] = create_slot_message_window(0, 0xE);
    }
}

void TAdChrSelASlotGC::update_window_6c() {
    if (this->player_load->get_slot_index() > 6) {
        if (this->wait_message[6] != NULL) {
            this->wait_message[6]->close();
            this->wait_message[6] = NULL;
        }
        this->state = 8;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[6] == NULL)) {
        this->wait_message[6] = create_slot_message_window(0, 0xC);
    }
}

void TAdChrSelASlotGC::update_slot5() {
    if (this->player_load->get_slot_index() > 5) {
        if (this->wait_message[5] != NULL) {
            this->wait_message[5]->close();
            this->wait_message[5] = NULL;
        }
        this->state = 7;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[5] == NULL)) {
        this->wait_message[5] = create_slot_message_window(0, 0xA);
    }
}

void TAdChrSelASlotGC::update_slot4() {
    if (this->player_load->get_slot_index() > 4) {
        if (this->wait_message[4] != NULL) {
            this->wait_message[4]->close();
            this->wait_message[4] = NULL;
        }
        this->state = 6;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[4] == NULL)) {
        this->wait_message[4] = create_slot_message_window(0, 8);
    }
}

void TAdChrSelASlotGC::update_slot3() {
    if (this->player_load->get_slot_index() > 3) {
        if (this->wait_message[3] != NULL) {
            this->wait_message[3]->close();
            this->wait_message[3] = NULL;
        }
        this->state = 5;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[3] == NULL)) {
        this->wait_message[3] = create_slot_message_window(0, 6);
    }
}

void TAdChrSelASlotGC::update_slot2() {
    if (this->player_load->get_slot_index() > 2) {
        if (this->wait_message[2] != NULL) {
            this->wait_message[2]->close();
            this->wait_message[2] = NULL;
        }
        this->state = 4;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[2] == NULL)) {
        this->wait_message[2] = create_slot_message_window(0, 4);
    }
}

void TAdChrSelASlotGC::update_slot1() {
    if (this->player_load->get_slot_index() > 1) {
        if (this->wait_message[1] != NULL) {
            this->wait_message[1]->close();
            this->wait_message[1] = NULL;
        }
        this->state = 3;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[1] == NULL)) {
        this->wait_message[1] = create_slot_message_window(0, 2);
    }
}

void TAdChrSelASlotGC::show_no_card_message() {

    if (this->wait_message[1] != NULL) {
        this->wait_message[1]->close();
        this->wait_message[1] = NULL;
    }
    if (this->wait_message[2] != NULL) {
        this->wait_message[2]->close();
        this->wait_message[2] = NULL;
    }
    if (this->wait_message[3] != NULL) {
        this->wait_message[3]->close();
        this->wait_message[3] = NULL;
    }
    if (this->wait_message[4] != NULL) {
        this->wait_message[4]->close();
        this->wait_message[4] = NULL;
    }
    if (this->wait_message[5] != NULL) {
        this->wait_message[5]->close();
        this->wait_message[5] = NULL;
    }
    if (this->wait_message[6] != NULL) {
        this->wait_message[6]->close();
        this->wait_message[6] = NULL;
    }
    if (this->wait_message[7] != NULL) {
        this->wait_message[7]->close();
        this->wait_message[7] = NULL;
    }
    if (this->wait_message[8] != NULL) {
        this->wait_message[8]->close();
        this->wait_message[8] = NULL;
    }
    if (this->wait_message[9] != NULL) {
        this->wait_message[9]->close();
        this->wait_message[9] = NULL;
    }
    if (this->wait_message[10] != NULL) {
        this->wait_message[10]->close();
        this->wait_message[10] = NULL;
    }
    switch (this->mode) {
    case 0:
        this->plate_a->reset_selection_slots();
        this->player_items->sub_802D6D88();
        this->move_plate->clear_entries();
        break;
    case 1:
        this->plate_a->reset_selection_slots();
        this->plate_b->reset_selection_slots();
        this->player_items->sub_802D6D88();
        this->player_items_b->sub_802D6D88();
        this->move_plate->clear_entries();
        if (this->draw_line[1] != NULL) {
            this->draw_line[1]->queue_destruction();
            this->draw_line[1] = NULL;
        }
        if (this->draw_line[2] != NULL) {
            this->draw_line[2]->queue_destruction();
            this->draw_line[2] = NULL;
        }
        break;
    case 2:
        this->plate_b->reset_selection_slots();
        this->player_items_b->sub_802D6D88();
        break;
    }
    slot_gc->sub_802C7498(0);
    slot_gc->sub_802C7498(1);
    slot_gc->sub_802C7498(2);
    if (this->player_load->get_slot_index() > 0) {
        if (this->wait_message[0] != NULL) {
            this->wait_message[0]->close();
            this->wait_message[0] = NULL;
        }
        this->state = 2;
        return;
    }
    if ((this->state_frames > 0xA) && (this->wait_message[0] == NULL)) {
        this->wait_message[0] = create_slot_message_window(0, 0);
    }
}


void TAdChrSelASlotGC::close_windows() {

    slot_gc->reset_all_slots();
    if (this->draw_line[0] != NULL) {
        this->draw_line[0]->queue_destruction();
        this->draw_line[0] = NULL;
    }
    if (this->draw_line[1] != NULL) {
        this->draw_line[1]->queue_destruction();
        this->draw_line[1] = NULL;
    }
    if (this->draw_line[2] != NULL) {
        this->draw_line[2]->queue_destruction();
        this->draw_line[2] = NULL;
    }
    if (this->wait_message[0] != NULL) {
        this->wait_message[0]->close();
        this->wait_message[0] = NULL;
    }
    if (this->wait_message[1] != NULL) {
        this->wait_message[1]->close();
        this->wait_message[1] = NULL;
    }
    if (this->wait_message[2] != NULL) {
        this->wait_message[2]->close();
        this->wait_message[2] = NULL;
    }
    if (this->wait_message[3] != NULL) {
        this->wait_message[3]->close();
        this->wait_message[3] = NULL;
    }
    if (this->wait_message[4] != NULL) {
        this->wait_message[4]->close();
        this->wait_message[4] = NULL;
    }
    if (this->wait_message[5] != NULL) {
        this->wait_message[5]->close();
        this->wait_message[5] = NULL;
    }
    if (this->wait_message[6] != NULL) {
        this->wait_message[6]->close();
        this->wait_message[6] = NULL;
    }
    if (this->wait_message[7] != NULL) {
        this->wait_message[7]->close();
        this->wait_message[7] = NULL;
    }
    if (this->wait_message[8] != NULL) {
        this->wait_message[8]->close();
        this->wait_message[8] = NULL;
    }
    if (this->wait_message[9] != NULL) {
        this->wait_message[9]->close();
        this->wait_message[9] = NULL;
    }
    if (this->wait_message[10] != NULL) {
        this->wait_message[10]->close();
        this->wait_message[10] = NULL;
    }
    switch (this->mode) {
    case 0:
        this->plate_a->reset_selection_slots();
        this->player_items->sub_802D6D88();
        break;
    case 1:
        this->plate_a->reset_selection_slots();
        this->plate_b->reset_selection_slots();
        this->player_items->sub_802D6D88();
        this->player_items_b->sub_802D6D88();
        break;
    case 2:
        this->plate_b->reset_selection_slots();
        this->player_items_b->sub_802D6D88();
        break;
    }
    switch (this->mode) {
    case 0:
        this->draw_line[1] = create_draw_line_ctrl(this, 0xC, 0.0f);
        slot_gc->init_slot(0, (void *)&chr_sel_a_slot_header_pos);
        this->draw_line[0] = create_draw_line_ctrl(this, 0xB, 0.0f);
        break;
    case 1:
        slot_gc->init_slot(0, (void *)&chr_sel_a_slot_header_pos);
        this->draw_line[0] = create_draw_line_ctrl(this, 0xB, 0.0f);
        break;
    case 2:
        slot_gc->init_slot(0, (void *)&chr_sel_a_slot_left_header_pos);
        this->draw_line[0] = create_draw_line_ctrl(this, 0xD, 0.0f);
        this->draw_line[1] = create_draw_line_ctrl(this, 0x14, 0.0f);
        break;
    }
    this->state = 1;
}

void TAdChrSelASlotGC::run_task() {
    if (this->state < 0 || this->state >= 21) {
        this->state = 1;
    }
    this->prev_state = this->state;
    if (this->player_load->get_slot_index() == 0 && this->state > 1) {
        this->state = 1;
    }
    static void (TAdChrSelASlotGC::*handlers[21])() = {
        &TAdChrSelASlotGC::close_windows,
        &TAdChrSelASlotGC::show_no_card_message,
        &TAdChrSelASlotGC::update_slot1,
        &TAdChrSelASlotGC::update_slot2,
        &TAdChrSelASlotGC::update_slot3,
        &TAdChrSelASlotGC::update_slot4,
        &TAdChrSelASlotGC::update_slot5,
        &TAdChrSelASlotGC::update_window_6c,
        &TAdChrSelASlotGC::update_window_70,
        &TAdChrSelASlotGC::update_window_74,
        &TAdChrSelASlotGC::update_window_7c,
        &TAdChrSelASlotGC::update_window_78,
        &TAdChrSelASlotGC::push_plate_positions,
        &TAdChrSelASlotGC::populate_slot_entries,
        &TAdChrSelASlotGC::sub_8030CCE0,
        &TAdChrSelASlotGC::init_selection,
        &TAdChrSelASlotGC::check_load_state,
        &TAdChrSelASlotGC::set_state,
        &TAdChrSelASlotGC::update_load_state,
        &TAdChrSelASlotGC::sub_8030CBD4,
        &TAdChrSelASlotGC::sub_8030CBD0,
    };
    (this->*handlers[this->state])();
    if (this->state != this->prev_state) {
        this->state_frames = 0;
    }
    this->state_frames++;
}

void TAdChrSelASlotGC::create_children(s32 arg1) {
    slot_gc = new TAdChrSelSlotGC(this);
    switch (arg1) {
    case 0:
        this->player_load = new TAdPlayerLoadGC(this, 0);
        plate_a = new TAdPlyChrSelPlateGC(this, &chr_sel_a_slot_plate_layout);
        this->player_items = new TAdSubPlyItemGC(this);
        this->move_plate = new TAdChrSelMovePlateGC(this);
        return;
    case 1:
        this->player_load = new TAdPlayerLoadGC(this, 1);
        plate_a = new TAdPlyChrSelPlateGC(this, &chr_sel_a_slot_plate_layout);
        plate_b = new TAdPlyChrSelPlateGC(this, &chr_sel_a_slot_plate_layout_b);
        this->player_items = new TAdSubPlyItemGC(this);
        this->player_items_b = new TAdSubPlyItemGC(this);
        this->move_plate = new TAdChrSelMovePlateGC(this);
        return;
    case 2:
        this->player_load = new TAdPlayerLoadGC(this, 1);
        plate_b = new TAdPlyChrSelPlateGC(this, &chr_sel_a_slot_plate_layout_b);
        this->player_items_b = new TAdSubPlyItemGC(this);
        return;
    }
}

void TAdChrSelASlotGC::init(s32 arg1) {
    this->state = 0;
    this->prev_state = 0;
    this->mode = arg1;
    this->state_frames = -1;
    slot_gc = NULL;
    this->player_load = NULL;
    this->plate_a = NULL;
    this->plate_b = NULL;
    this->player_items = NULL;
    this->player_items_b = NULL;
    this->move_plate = NULL;
    this->draw_line[0] = NULL;
    this->draw_line[1] = NULL;
    this->draw_line[2] = NULL;
    this->wait_message[0] = NULL;
    this->wait_message[1] = NULL;
    this->wait_message[2] = NULL;
    this->wait_message[3] = NULL;
    this->wait_message[4] = NULL;
    this->wait_message[5] = NULL;
    this->wait_message[6] = NULL;
    this->wait_message[7] = NULL;
    this->wait_message[8] = NULL;
    this->wait_message[9] = NULL;
    this->wait_message[10] = NULL;
}

TAdChrSelASlotGC::~TAdChrSelASlotGC() {
    if (this->wait_message[0] != NULL) {
        this->wait_message[0]->queue_destruction();
        this->wait_message[0] = NULL;
    }
    if (this->wait_message[1] != NULL) {
        this->wait_message[1]->queue_destruction();
        this->wait_message[1] = NULL;
    }
    if (this->wait_message[2] != NULL) {
        this->wait_message[2]->queue_destruction();
        this->wait_message[2] = NULL;
    }
    if (this->wait_message[3] != NULL) {
        this->wait_message[3]->queue_destruction();
        this->wait_message[3] = NULL;
    }
    if (this->wait_message[4] != NULL) {
        this->wait_message[4]->queue_destruction();
        this->wait_message[4] = NULL;
    }
    if (this->wait_message[5] != NULL) {
        this->wait_message[5]->queue_destruction();
        this->wait_message[5] = NULL;
    }
    if (this->wait_message[6] != NULL) {
        this->wait_message[6]->queue_destruction();
        this->wait_message[6] = NULL;
    }
    if (this->wait_message[7] != NULL) {
        this->wait_message[7]->queue_destruction();
        this->wait_message[7] = NULL;
    }
    if (this->wait_message[8] != NULL) {
        this->wait_message[8]->queue_destruction();
        this->wait_message[8] = NULL;
    }
    if (this->wait_message[9] != NULL) {
        this->wait_message[9]->queue_destruction();
        this->wait_message[9] = NULL;
    }
    if (this->wait_message[10] != NULL) {
        this->wait_message[10]->queue_destruction();
        this->wait_message[10] = NULL;
    }
    if (TAdChrSel__global_slot_data != NULL) {
        TAdChrSel__global_slot_data = NULL;
    }
}
TAdChrSelASlotGC::TAdChrSelASlotGC(TObject *parent, s32 mode) : TObject(parent) {
    m_name = TAdChrSelASlotGC__name;
    init(mode);
    create_children(mode);
}

TAdChrSelASlotGC *TAdMultiPlyChrSelectGC::get_or_create_slot_window(TObject *parent, s32 mode) {
    if (TAdChrSel__global_slot_data != NULL) {
        return TAdChrSel__global_slot_data;
    }
    TAdChrSelASlotGC *slot = new TAdChrSelASlotGC(parent, mode);
    TAdChrSel__global_slot_data = slot;
    return slot;
}

s32 TAdPlayerLoadGC::get_slot_index() { return this->state; }


char char_select_format_message_buffer[0x100];
PlayerSlotLabel chr_select_a_slot_entry;
