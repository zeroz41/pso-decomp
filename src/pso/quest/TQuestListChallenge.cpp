#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/object/TObjControl.h"
#include "types.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_801F3774.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 lbl_805D64A8;
s32 lbl_805D64AC;
TQuestListChallenge *TQuestListChallenge__active_instance;
void *__ct__11TObjControlFP7TObject(void *, void *);
u8 *TObjNpcKenkyu__ct(u8 *arg0, s32 arg1, s32 arg2);

struct ChallengeWindowExtent { f32 dimensions[2]; };
struct ChallengeWindowExtentResource { ChallengeWindowExtent extent; u32 reserved; };
extern __declspec(section ".rodata") const QuestListStageEntry TQuestListChallenge__stage_table[5];
extern __declspec(section ".rodata") const QuestListStageEntry quest_list_challenge_stage_table[9];
extern __declspec(section ".rodata") const QuestListStageEntry quest_list_battle_stage_table[8];
extern const char *TQuestListChallenge__name;
extern __declspec(section ".rodata") const ChallengeWindowExtentResource lbl_80450AB4[1];
}

#pragma push
#pragma opt_common_subs off
const char *get_selected_quest_text__19TQuestListChallengeFv(void) {
    if (TQuestListChallenge__active_instance != NULL) {
        TWindowMenuIconLine *window = TQuestListChallenge__active_instance->list_window;
        if (window != NULL) {
            return reinterpret_cast<const char *>(get_quest_list_text(TQuestListChallenge__active_instance->text_group,
                TQuestListChallenge__active_instance->entries[window->get_cursor_value()].title_text));
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

void TQuestListChallenge::sub_80288BE4() {}

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
            goto block_9;
        }
block_9:
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

struct Pair_80288DA4 { s32 a; s32 b; };
static inline TWindowMessage *create_quest_detail_window(const NJS_POINT2 *position, const f32 *size, u32 rows, u16 client) {
    return (TWindowMessage *)TWindowMessage::create((saddr)position, size, rows, client);
}

#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(1)
void TQuestListChallenge::update_selection() {
    s32 sel;
    s32 id;
    s32 text;
    s32 text2;
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
            ChallengeWindowExtent p = lbl_80450AB4[0].extent;
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
    s32 e;

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
        &TQuestListChallenge::sub_80288BE4,
    };
    (this->*tbl[state])();
}

TQuestListChallenge::~TQuestListChallenge() {
    close_windows();
    TQuestListChallenge__active_instance = NULL;
}

TQuestListChallenge::TQuestListChallenge(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player)
    : TShopWindowBase(parent) {
    s32 temp_r3;
    s32 limit;
    m_name = TQuestListChallenge__name;
    if (TQuestListChallenge__active_instance != NULL) {
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
    temp_r3 = get_game_play_mode();
    switch (temp_r3) {
    case 1:
        if (TLobby::get_instance() == 0) {
            entries = quest_list_challenge_stage_table;
        } else {
            entries = TQuestListChallenge__stage_table;
        }
        text_group = 0xF;
        count = TLobby::calc_min_challenge_progress() + 1;
        temp_r3 = TLobby::get_instance();
        limit = 5;
        if (temp_r3 == 0) {
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
    TQuestListChallenge__active_instance = this;
}

void reset_globals__19TQuestListChallengeFv(void) {
    lbl_805D64A8 = 0;
    lbl_805D64AC = 0;
    TQuestListChallenge__active_instance = NULL;
}

void reset_globals2__19TQuestListChallengeFv(void) {
    lbl_805D64A8 = 0;
    lbl_805D64AC = 0;
    TQuestListChallenge__active_instance = NULL;
}

extern "C" const char lbl_804507A8[] = "challenge2_mlt_stg1";
extern "C" const char lbl_804507BC[] = "challenge2_mlt_stg2";
extern "C" const char lbl_804507D0[] = "challenge2_mlt_stg3";
extern "C" const char lbl_804507E4[] = "challenge2_mlt_stg4";
extern "C" const char lbl_804507F8[] = "challenge2_mlt_stg5";
extern "C" const QuestListStageEntry TQuestListChallenge__stage_table[5] = {
    {27, 28, 29, lbl_804507A8},
    {30, 31, 32, lbl_804507BC},
    {33, 34, 35, lbl_804507D0},
    {36, 37, 38, lbl_804507E4},
    {39, 40, 41, lbl_804507F8},
};
extern "C" const char lbl_8045085C[] = "challenge_mlt_stg1";
extern "C" const char lbl_80450870[] = "challenge_mlt_stg2";
extern "C" const char lbl_80450884[] = "challenge_mlt_stg3";
extern "C" const char lbl_80450898[] = "challenge_mlt_stg4";
extern "C" const char lbl_804508AC[] = "challenge_mlt_stg5";
extern "C" const char lbl_804508C0[] = "challenge_mlt_stg6";
extern "C" const char lbl_804508D4[] = "challenge_mlt_stg7";
extern "C" const char lbl_804508E8[] = "challenge_mlt_stg8";
extern "C" const char lbl_804508FC[] = "challenge_mlt_stg9";
extern "C" const QuestListStageEntry quest_list_challenge_stage_table[9] = {
    {0, 1, 2, lbl_8045085C},
    {3, 4, 5, lbl_80450870},
    {6, 7, 8, lbl_80450884},
    {9, 10, 11, lbl_80450898},
    {12, 13, 14, lbl_804508AC},
    {15, 16, 17, lbl_804508C0},
    {18, 19, 20, lbl_804508D4},
    {21, 22, 23, lbl_804508E8},
    {24, 25, 26, lbl_804508FC},
};
extern "C" const char lbl_804509A0[] = "battle_mlt_stg1";
extern "C" const char lbl_804509B0[] = "battle_mlt_stg2";
extern "C" const char lbl_804509C0[] = "battle_mlt_stg3";
extern "C" const char lbl_804509D0[] = "battle_mlt_stg4";
extern "C" const char lbl_804509E0[] = "battle_mlt_stg5";
extern "C" const char lbl_804509F0[] = "battle_mlt_stg6";
extern "C" const char lbl_80450A00[] = "battle_mlt_stg7";
extern "C" const char lbl_80450A10[] = "battle_mlt_stg8";
extern "C" const QuestListStageEntry quest_list_battle_stage_table[8] = {
    {0, 1, 2, lbl_804509A0},
    {3, 4, 5, lbl_804509B0},
    {6, 7, 8, lbl_804509C0},
    {9, 10, 11, lbl_804509D0},
    {12, 13, 14, lbl_804509E0},
    {15, 16, 17, lbl_804509F0},
    {18, 19, 20, lbl_80450A00},
    {21, 22, 23, lbl_80450A10},
};
extern "C" const char TQuestListChallenge__class_name_string[] = "TQuestListChallenge";
extern "C" const char *TQuestListChallenge__name = TQuestListChallenge__class_name_string;

extern "C" const ChallengeWindowExtentResource lbl_80450AB4[1] = {{{{332.0f, 210.0f}}, 0}};
