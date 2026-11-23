#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/quest/TQuestListOffline.h"
#include "pso/quest/StoryQuestProgress.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_801F3774.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/object/base/TObjBase.h"

OfflineQuestEntry offline_quest_catalog_ep1[28] = {
    {1, 0, 1, 2, 106, 107, 0, "quest04"},
    {2, 3, 4, 5, 102, 103, 0, "quest02"},
    {3, 6, 7, 8, 100, 101, 0, "quest01"},
    {4, 9, 10, 11, 104, 105, 0, "quest03"},
    {5, 12, 13, 14, 108, 109, 0, "quest05"},
    {6, 15, 16, 17, 110, 111, 0, "quest06"},
    {7, 18, 19, 20, 112, 113, 0, "quest07"},
    {8, 21, 22, 23, 114, 115, 0, "quest08"},
    {9, 24, 25, 26, 116, 117, 0, "quest09"},
    {10, 27, 28, 29, 118, 119, 0, "quest10"},
    {11, 30, 31, 32, 120, 121, 0, "quest11"},
    {12, 33, 34, 35, 122, 123, 0, "quest12"},
    {13, 36, 37, 38, 124, 125, 0, "quest13"},
    {14, 39, 40, 41, 126, 127, 0, "quest14"},
    {15, 42, 43, 44, 128, 129, 0, "quest15"},
    {16, 45, 46, 47, 130, 131, 0, "quest16"},
    {17, 48, 49, 50, 132, 133, 0, "quest17"},
    {18, 51, 52, 53, 134, 135, 0, "quest18"},
    {19, 54, 55, 56, 136, 137, 0, "quest19"},
    {20, 57, 58, 59, 138, 139, 0, "quest20"},
    {21, 60, 61, 62, 140, 141, 0, "quest21"},
    {22, 63, 64, 65, 142, 143, 0, "quest22"},
    {23, 66, 67, 68, 144, 145, 0, "quest23"},
    {24, 69, 70, 71, 146, 147, 0, "quest24"},
    {25, 72, 73, 74, 148, 149, 0, "quest25"},
    {26, 75, 76, 77, 159, 160, 0, "quest26"},
    {0, 87, 88, 89, -1, -1, 1, ""},
    {-1, -1, -1, -1, -1, -1, -1, ""},
};

OfflineQuestEntry lbl_804C9C10[5] = {
    {27, 78, 79, 80, -1, 161, 0, "quest27"},
    {28, 81, 82, 83, 162, 163, 0, "quest28"},
    {29, 84, 85, 86, 164, 165, 0, "quest29"},
    {0, 87, 88, 89, -1, -1, 1, ""},
    {-1, -1, -1, -1, -1, -1, -1, ""},
};

const char *TQuestListOffline__class_name = "TQuestListOffline";

void *story_quest_list_resource;

TQuestListOffline::TQuestListOffline(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player)
    : TShopWindowBase(parent) {
    m_name = TQuestListOffline__class_name;
    this->sequence = sequence;
    list_window = NULL;
    confirm_menu = NULL;
    description_window = NULL;
    confirm_window = NULL;
    this->player = player;
    unk_48 = 0;
    shown_index = 0;
    on_cancel = NULL;
    on_accept = NULL;
    on_download = NULL;
    if (TLobby::get_instance() == 0) {
        quests = offline_quest_catalog_ep1;
    } else {
        quests = lbl_804C9C10;
    }
    set_state(0);
}

TQuestListOffline::~TQuestListOffline() {
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
    // The confirm menu's block clears list_window, not confirm_menu.
    if (confirm_menu != NULL) {
        confirm_menu->close();
        list_window = NULL;
    }
    if (description_window != NULL) {
        description_window->close();
        description_window = NULL;
    }
    if (confirm_window != NULL) {
        confirm_window->close();
        confirm_window = NULL;
    }
}

void TQuestListOffline::update_state() {
    switch (state) {
    case 0:
        init_quest_list_window();
        break;
    case 1:
        update_list_navigation();
        break;
    case 2:
        handle_confirm_dialog();
        break;
    case 3:
        if (on_accept) {
            on_accept(sequence);
        }
        queue_destruction();
        break;
    case 5:
        if (on_cancel) {
            on_cancel(sequence);
        }
        queue_destruction();
        break;
    case 4:
        if (on_download) {
            on_download(sequence);
        }
        queue_destruction();
        break;
    case 6:
        break;
    }
}

void TQuestListOffline::init_quest_list_window() {
    if (sequence->is_message_ready() == 0) {
        return;
    }
    refresh_story_quest_availability(story_quest_list_resource);
    if (list_window == NULL) {
        s32 title = get_guild_text(0);
        list_window = create_item_list_window(title, 0x40, player->get_entity_id());
        if (are_all_story_quests_complete() == 1) {
            OfflineQuestEntry *quest = quests;
            s32 i = 0;
            while (quest->name_text != -1) {
                if (quest->clear_flag == -1) {
                    list_window->add_list_entry(0x2C, get_quest_list_text(0xE, quest->name_text), i);
                } else if (get_story_flag(quest->unlock_flag) != 0) {
                    list_window->add_list_entry(0x16, get_quest_list_text(0xE, quest->name_text), i);
                }
                i++;
                quest++;
            }
        } else {
            OfflineQuestEntry *quest = quests;
            s32 i = 0;
            while (quest->name_text != -1) {
                if (quest->clear_flag == -1) {
                    list_window->add_list_entry(0x2C, get_quest_list_text(0xE, quest->name_text), i);
                } else if (get_story_flag(quest->unlock_flag) != 0) {
                    if (get_story_flag(quest->clear_flag) != 0) {
                        list_window->add_list_entry(0x18, get_quest_list_text(0xE, quest->name_text), i);
                    } else {
                        list_window->add_list_entry(0x17, get_quest_list_text(0xE, quest->name_text), i);
                    }
                }
                i++;
                quest++;
            }
        }
        list_window->calc_content_extent();
        if (description_window == NULL) {
            f32 size[2] = {228.0f, 184.0f};
            description_window = (TWindowMessage *)TWindowMessage::create((const NJS_POINT2 *)get_window_layout_position(0x2D), (const f32 *)size, 1);
            description_window->append_line(get_quest_list_text(0xE, quests->description_text), 0x80);
            shown_index = 0;
        } else {
            description_window->append_line(get_quest_list_text(0xE, quests->description_text), 0x80);
            shown_index = 0;
        }
    }
    set_state(1);
}

void TQuestListOffline::update_list_navigation() {
    s32 sel;
    if (sequence->is_message_ready() == 0) {
        return;
    }
    if (list_window != NULL && description_window != NULL) {
        sel = list_window->get_cursor_value();
        if (sel != shown_index) {
            s32 text = get_quest_list_text(0xE, quests[sel].description_text);
            description_window->append_line(text, 0x80);
            shown_index = sel;
            if (confirm_window != NULL) {
                confirm_window->close();
                confirm_window = NULL;
            }
        }
    }
    if (list_window != NULL && list_window->is_cancelled() != 0) {
        set_state(5);
        return;
    }
    if (list_window != NULL && list_window->is_decided() != 0) {
        sel = list_window->get_cursor_value();
        if (quests[sel].flags & 1) {
            set_state(4);
            return;
        }
        if (confirm_window == NULL) {
            f32 size[2] = {332.0f, 210.0f};
            confirm_window = (TWindowMessage *)TWindowMessage::create((saddr)get_window_layout_position(0x2E), size, 1, player->get_entity_id());
            s32 text = get_quest_list_text(0xE, quests[sel].confirm_text);
            confirm_window->append_line(text, 0x80);
            confirm_window->set_depth(-13000.0f);
            if (TCameraCtrl::get_camera_id() >= 2) {
                confirm_window->set_position_xy(0.75f, 0.75f);
            }
        }
        if (confirm_menu == NULL) {
            confirm_menu = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), player->get_entity_id(), NULL, NULL);
            confirm_menu->set_position_xy(get_scale(), get_scale());
            if (sequence != NULL) {
                sequence->display_guild_message(5, 1);
            }
            set_state(2);
        }
    }
}

void TQuestListOffline::handle_confirm_dialog() {
    if (sequence->is_message_ready() != 0) {
        if (confirm_menu != NULL && confirm_menu->is_decided() != 0) {
            s32 choice = confirm_menu->get_selected_value();
            if (choice == 0) {
                s32 cursor = list_window->get_cursor_value();
                prepare_offline_quest_filenames(quests[cursor].filename);
                set_state(3);
                return;
            }
            if (choice == 1) {
                close_sub_windows();
                if (sequence != NULL) {
                    sequence->display_guild_message(0x19, 1);
                }
                set_state(0);
                return;
            }
        }
        if (confirm_menu != NULL && confirm_menu->is_cancelled() != 0) {
            close_sub_windows();
            if (sequence != NULL) {
                sequence->display_guild_message(0x19, 1);
            }
            set_state(0);
        }
    }
}

void TQuestListOffline::close_sub_windows() {
    if (confirm_menu != NULL) {
        confirm_menu->close();
        confirm_menu = NULL;
    }
    if (confirm_window != NULL) {
        confirm_window->close();
        confirm_window = NULL;
    }
    if (description_window != NULL) {
        description_window->close();
        description_window = NULL;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
}
