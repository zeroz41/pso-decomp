#ifndef PSO_QUEST_TQUESTLISTOFFLINE_H
#define PSO_QUEST_TQUESTLISTOFFLINE_H
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

class TWindowMenuIconLine;
struct TWindowMenu;
struct TWindowMessage;

// One quest of the offline Hunter's Guild list (0x1C bytes). The tables end with a download entry
// (flags bit 0) and a name_text -1 terminator. Field names are inferred from the list code.
struct OfflineQuestEntry {
    s32 quest_no;          // 0x00
    s32 name_text;         // 0x04: get_quest_list_text(0xE, ..) list label; -1 ends the table
    s32 description_text;  // 0x08: description window text while the entry is selected
    s32 confirm_text;      // 0x0C: confirm window text once it is decided
    s16 unlock_flag;       // 0x10: story flag that lists the entry
    s16 clear_flag;        // 0x12: story flag of its completion; -1 lists it unconditionally
    u32 flags;             // 0x14: bit 0 = download entry
    const char *filename;  // 0x18: prepare_offline_quest_filenames
};

// Offline Hunter's Guild quest list, created by THunterGuildSeqOffline::open_quest_list.
class TQuestListOffline : public TShopWindowBase {
public:
    TQuestListOffline(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TQuestListOffline();
    virtual void update_state();
    void close_sub_windows();
    void handle_confirm_dialog();
    void update_list_navigation();
    void init_quest_list_window();

    void (*on_cancel)(TShopWindowBase *);   // 0x28: state 5
    void (*on_accept)(TShopWindowBase *);   // 0x2C: state 3
    void (*on_download)(TShopWindowBase *); // 0x30: state 4
    TShopWindowBase *sequence;            // 0x34: the guild sequence; passed to the callbacks
    TWindowMenu *confirm_menu;            // 0x38: create_yes_no_window
    TWindowMenuIconLine *list_window;     // 0x3C
    TWindowMessage *description_window;   // 0x40
    TWindowMessage *confirm_window;       // 0x44
    s32 unk_48;
    u8 pad_4c[0x4];
    s32 shown_index;                      // 0x50: entry whose description is shown
    OfflineQuestEntry *quests;            // 0x54: offline_quest_catalog_ep1 or lbl_804C9C10
};
LAYOUT_ASSERT(TQuestListOffline_size, sizeof(TQuestListOffline) == 0x58);

extern void *story_quest_list_resource;

#endif
