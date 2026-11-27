#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/object/TObjControl.h"
#include "types.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/quest/QuestFlagCommand.h"
#include "pso/ui/CounterTextLookup.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/system/GameModeQueries.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/challenge/TChallenge4P.h"

extern "C" {
s32 lbl_805D64A8;
s32 lbl_805D64AC;
TQuestListChallenge *quest_list_challenge_active_instance;

extern __declspec(section ".rodata") const QuestListStageEntry quest_list_challenge2_stage_table[5];
extern __declspec(section ".rodata") const QuestListStageEntry quest_list_challenge_stage_table[9];
extern __declspec(section ".rodata") const QuestListStageEntry quest_list_battle_stage_table[8];
extern const char *quest_list_challenge_name;
extern __declspec(section ".rodata") const ChallengeWindowExtentResource quest_list_challenge_window_extent[1];
}

#pragma push
#pragma opt_common_subs off
const char *get_selected_quest_text(void) {
    if (quest_list_challenge_active_instance != NULL) {
        TWindowMenuIconLine *window = quest_list_challenge_active_instance->list_window;
        if (window != NULL) {
            return reinterpret_cast<const char *>(get_quest_list_text(quest_list_challenge_active_instance->text_group,
                quest_list_challenge_active_instance->entries[window->get_cursor_value()].title_text));
        }
    }
    return NULL;
}
#pragma pop

void TQuestListChallenge::close_windows() {
    if (confirmation != NULL) {
        confirmation->close();
        confirmation = NULL;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
    if (description_window != NULL) {
        description_window->close();
        description_window = NULL;
    }
    if (info_window != NULL) {
        info_window->close();
        info_window = NULL;
    }
}

void TQuestListChallenge::state_stub() {}

void TQuestListChallenge::invoke_callback_and_destroy() {
    void (*callback)(TShopWindowBase *) = on_accept;
    if (callback != NULL) {
        callback(sequence);
    }
    queue_destruction();
}

void TQuestListChallenge::destroy() {
    void (*callback)(TShopWindowBase *) = on_cancel;
    if (callback != NULL) {
        callback(sequence);
    }
    queue_destruction();
}

void TQuestListChallenge::handle_confirm_select() {
    s32 selected_menu_value;

    if (sequence->is_message_ready() != 0) {
        if (confirmation != NULL && confirmation->is_decided() == 1) {
            selected_menu_value = confirmation->get_selected_value();
            if (selected_menu_value == 0) {
                s32 index = list_window->get_cursor_value();
                const QuestListStageEntry *catalog = entries;
                prepare_offline_quest_filenames(catalog[index].filename);
                set_state(3);
                return;
            }
            if (selected_menu_value == 1) {
                close_windows();
                if (sequence != NULL) {
                    sequence->display_guild_message(0x19, 0x80);
                }
                set_state(0);
                return;
            }
        }
        if (confirmation != NULL && confirmation->is_cancelled() == 1) {
            close_windows();
            if (sequence != NULL) {
                sequence->display_guild_message(0x19, 0x80);
            }
            set_state(0);
        }
    }
}

static inline TWindowMenu *create_quest_confirmation_menu(const NJS_POINT2 *position, u16 client, const char *yes_text, const char *no_text) {
    return create_yes_no_window(position, client, yes_text, no_text);
}

static inline TWindowMessage *create_quest_detail_window(const NJS_POINT2 *position, const f32 *size, u32 rows, u16 client) {
    return TWindowMessage::create(position, size, rows, client);
}

#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(1)
void TQuestListChallenge::update_selection() {
    s32 sel;
    s32 id;
    const char *text;
    const char *text2;
    if (sequence->is_message_ready() == 0) {
        return;
    }
    if (list_window != NULL && description_window != NULL) {
        sel = list_window->get_cursor_value();
        if (sel != shown_index) {
            text = get_quest_list_text(text_group, entries[sel].description_text);
            description_window->append_line(text, 0x80);
            shown_index = sel;
            if (info_window != NULL) {
                info_window->close();
                info_window = NULL;
            }
        }
    }
    if (list_window != NULL && list_window->is_cancelled() == 1) {
        set_state(4);
        return;
    }
    if (list_window != NULL && list_window->is_decided() == 1) {
        sel = list_window->get_cursor_value();
        if (info_window == NULL) {
            ChallengeWindowExtent p = quest_list_challenge_window_extent[0].extent;
            id = (u16)player->get_entity_id();
            info_window = create_quest_detail_window(get_window_layout_position(0x2E), p.dimensions, 1, id);
            text2 = get_quest_list_text(text_group, entries[sel].confirm_text);
            info_window->append_line(text2, 0x80);
            info_window->set_depth(37000.0f);
            if (TCameraCtrl::get_camera_id() >= 2) {
                info_window->set_position_xy(0.75f, 0.75f);
            }
        }
        if (confirmation == NULL) {
            id = (u16)player->get_entity_id();
            confirmation = create_quest_confirmation_menu(get_window_layout_position(0x2B), id, NULL, NULL);
            confirmation->set_position_xy(get_scale(), get_scale());
            if (sequence != NULL) {
                sequence->display_guild_message(5, 0x80);
            }
            set_state(2);
        }
    }
}

#pragma pop

void TQuestListChallenge::create_quest_list_window() {
    s32 id;
    s32 i;
    const char *e;

    if (sequence->is_message_ready() != 0 && list_window == NULL) {
        id = player->get_entity_id();
        list_window = create_item_list_window(get_guild_text(0), 0x40, id);
        for (i = 0; i < count; i++) {
            e = get_quest_list_text(text_group, entries[i].title_text);
            list_window->add_list_entry(0x2C, e, i);
        }
        ((TWindowMenuIconLine *)list_window)->calc_content_extent();
        set_state(1);
    }
}

void TQuestListChallenge::update_state() {
    typedef void (TQuestListChallenge::*Handler)();
    static Handler tbl[] = {
        &TQuestListChallenge::create_quest_list_window,
        &TQuestListChallenge::update_selection,
        &TQuestListChallenge::handle_confirm_select,
        &TQuestListChallenge::invoke_callback_and_destroy,
        &TQuestListChallenge::destroy,
        &TQuestListChallenge::state_stub,
    };
    (this->*tbl[state])();
}

TQuestListChallenge::~TQuestListChallenge() {
    close_windows();
    quest_list_challenge_active_instance = NULL;
}

TQuestListChallenge::TQuestListChallenge(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player)
    : TShopWindowBase(parent) {
    s32 mode;
    s32 limit;
    m_name = quest_list_challenge_name;
    if (quest_list_challenge_active_instance != NULL) {
        return;
    }
    on_cancel = NULL;
    on_accept = NULL;
    this->sequence = sequence;
    confirmation = NULL;
    list_window = NULL;
    description_window = NULL;
    info_window = NULL;
    this->player = player;
    unk_44 = 0;
    unk_48 = 0;
    mode = get_game_play_mode();
    switch (mode) {
    case 1:
        if (TLobby::get_instance() == 0) {
            entries = quest_list_challenge_stage_table;
        } else {
            entries = quest_list_challenge2_stage_table;
        }
        text_group = 0xF;
        count = calc_min_challenge_progress() + 1;
        mode = TLobby::get_instance();
        limit = 5;
        if (mode == 0) {
            limit = 9;
        }
        if (count > limit) {
            count = limit;
        }
        break;
    case 2:
        text_group = 0x10;
        entries = quest_list_battle_stage_table;
        count = 8;
        break;
    }
    set_state(0);
    quest_list_challenge_active_instance = this;
}

void TQuestListChallenge::reset_globals() {
    lbl_805D64A8 = 0;
    lbl_805D64AC = 0;
    quest_list_challenge_active_instance = NULL;
}

void reset_globals2(void) {
    lbl_805D64A8 = 0;
    lbl_805D64AC = 0;
    quest_list_challenge_active_instance = NULL;
}

extern "C" const char str_challenge2_mlt_stg1[] = "challenge2_mlt_stg1";
extern "C" const char str_challenge2_mlt_stg2[] = "challenge2_mlt_stg2";
extern "C" const char str_challenge2_mlt_stg3[] = "challenge2_mlt_stg3";
extern "C" const char str_challenge2_mlt_stg4[] = "challenge2_mlt_stg4";
extern "C" const char str_challenge2_mlt_stg5[] = "challenge2_mlt_stg5";
extern "C" const QuestListStageEntry quest_list_challenge2_stage_table[5] = {
    {27, 28, 29, str_challenge2_mlt_stg1},
    {30, 31, 32, str_challenge2_mlt_stg2},
    {33, 34, 35, str_challenge2_mlt_stg3},
    {36, 37, 38, str_challenge2_mlt_stg4},
    {39, 40, 41, str_challenge2_mlt_stg5},
};
extern "C" const char str_challenge_mlt_stg1[] = "challenge_mlt_stg1";
extern "C" const char str_challenge_mlt_stg2[] = "challenge_mlt_stg2";
extern "C" const char str_challenge_mlt_stg3[] = "challenge_mlt_stg3";
extern "C" const char str_challenge_mlt_stg4[] = "challenge_mlt_stg4";
extern "C" const char str_challenge_mlt_stg5[] = "challenge_mlt_stg5";
extern "C" const char str_challenge_mlt_stg6[] = "challenge_mlt_stg6";
extern "C" const char str_challenge_mlt_stg7[] = "challenge_mlt_stg7";
extern "C" const char str_challenge_mlt_stg8[] = "challenge_mlt_stg8";
extern "C" const char str_challenge_mlt_stg9[] = "challenge_mlt_stg9";
extern "C" const QuestListStageEntry quest_list_challenge_stage_table[9] = {
    {0, 1, 2, str_challenge_mlt_stg1},
    {3, 4, 5, str_challenge_mlt_stg2},
    {6, 7, 8, str_challenge_mlt_stg3},
    {9, 10, 11, str_challenge_mlt_stg4},
    {12, 13, 14, str_challenge_mlt_stg5},
    {15, 16, 17, str_challenge_mlt_stg6},
    {18, 19, 20, str_challenge_mlt_stg7},
    {21, 22, 23, str_challenge_mlt_stg8},
    {24, 25, 26, str_challenge_mlt_stg9},
};
extern "C" const char str_battle_mlt_stg1[] = "battle_mlt_stg1";
extern "C" const char str_battle_mlt_stg2[] = "battle_mlt_stg2";
extern "C" const char str_battle_mlt_stg3[] = "battle_mlt_stg3";
extern "C" const char str_battle_mlt_stg4[] = "battle_mlt_stg4";
extern "C" const char str_battle_mlt_stg5[] = "battle_mlt_stg5";
extern "C" const char str_battle_mlt_stg6[] = "battle_mlt_stg6";
extern "C" const char str_battle_mlt_stg7[] = "battle_mlt_stg7";
extern "C" const char str_battle_mlt_stg8[] = "battle_mlt_stg8";
extern "C" const QuestListStageEntry quest_list_battle_stage_table[8] = {
    {0, 1, 2, str_battle_mlt_stg1},
    {3, 4, 5, str_battle_mlt_stg2},
    {6, 7, 8, str_battle_mlt_stg3},
    {9, 10, 11, str_battle_mlt_stg4},
    {12, 13, 14, str_battle_mlt_stg5},
    {15, 16, 17, str_battle_mlt_stg6},
    {18, 19, 20, str_battle_mlt_stg7},
    {21, 22, 23, str_battle_mlt_stg8},
};
extern "C" const char quest_list_challenge_class_name_string[] = "TQuestListChallenge";
extern "C" const char *quest_list_challenge_name = quest_list_challenge_class_name_string;

extern "C" const ChallengeWindowExtentResource quest_list_challenge_window_extent[1] = {{{{332.0f, 210.0f}}, 0}};
