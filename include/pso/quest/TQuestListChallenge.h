#ifndef PSO_QUEST_TQUESTLISTCHALLENGE_H
#define PSO_QUEST_TQUESTLISTCHALLENGE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

class TWindowMenuIconLine;
struct TWindowMenu;
struct TWindowMessage;

struct QuestListStageEntry {
    s32 title_text;
    s32 description_text;
    s32 confirm_text;
    const char *filename;
};

struct TQuestListChallenge : public TShopWindowBase {
    TQuestListChallenge(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TQuestListChallenge();
    virtual void update_state();
    void close_windows();
    void create_quest_list_window();
    void update_selection();
    void handle_confirm_select();
    void invoke_callback_and_destroy();
    void destroy();
    void sub_80288BE4();

    void (*on_cancel)(TShopWindowBase *);
    void (*on_accept)(TShopWindowBase *);
    TShopWindowBase *sequence;
    TWindowMenu *confirmation;
    TWindowMenuIconLine *list_window;
    TWindowMessage *description_window;
    TWindowMessage *info_window;
    u32 unk_44;
    u32 unk_48;
    s32 shown_index;
    s32 text_group;
    s32 count;
    const QuestListStageEntry *entries;
};

LAYOUT_ASSERT(QuestListStageEntry_size, sizeof(QuestListStageEntry) == 0x10);
LAYOUT_ASSERT(TQuestListChallenge_size, sizeof(TQuestListChallenge) == 0x5C);
LAYOUT_ASSERT(TQuestListChallenge_state, offsetof(TQuestListChallenge, state) == 0x20);
LAYOUT_ASSERT(TQuestListChallenge_callbacks, offsetof(TQuestListChallenge, on_cancel) == 0x28);
LAYOUT_ASSERT(TQuestListChallenge_windows, offsetof(TQuestListChallenge, confirmation) == 0x34);
LAYOUT_ASSERT(TQuestListChallenge_entries, offsetof(TQuestListChallenge, entries) == 0x58);

extern "C" {
const char *get_selected_quest_text__19TQuestListChallengeFv(void);
void reset_globals2__19TQuestListChallengeFv(void);
void reset_globals__19TQuestListChallengeFv(void);
}

#endif
