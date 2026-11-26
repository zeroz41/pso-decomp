#ifndef PSO_QUEST_TQUESTTHREAD_H
#define PSO_QUEST_TQUESTTHREAD_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/QuestVm.h"

struct TWindowMenu;

class TQuestManager;
struct TKeyBoardControl;
struct TWindowMenu;
struct G_SyncQuestRegister_6x77;

class TQuestThread : public TObject {
public:
    QuestVmContext ctx;
    quest_suspend_reason state;

    TQuestThread(TQuestManager *root, s32 label);
    virtual ~TQuestThread();
    virtual void run_task();

    static TQuestThread *create(int label);
    static TQuestThread *create_in_root(s32 label);
    static TQuestThread *create_for_floor();
    static void set_floor_handler(s32 floor, s32 label);
    static void clear_floor_handler(s32 floor);
    static void clear_all_floor_handlers();
    static TQuestManager *create_by_mode();
    static void destroy_quest_obj();
    static void destroy_all_in(TObject *parent);
    static void clear_buffer(TQuestManager *root);
    static void clear_thread_state();
    static const char *get_quest_name();
    static s32 get_register(const TQuestManager *root, int index);
    static void queue_destruction(TObject *obj);
    static void set_status_flag_80(void *window);
};

class TQuestThreadBoard : public TObject {
public:
    QuestVmContext ctx;
    quest_suspend_reason state;

    TQuestThreadBoard(TQuestManager *root, s32 label);
    virtual ~TQuestThreadBoard();
    virtual void run_task();

    static TQuestThreadBoard *create_instance(int label);
    static void destroy_board();
};

// One quest board entry set by the quest opcode set_quest_board_handler:
// the title the board lists and the label TQuestThreadBoard runs.
struct QuestBoardHandler {
    char title[0x20];
    s32 label;
};

extern QuestBoardHandler quest_board_handlers[6];

class TObjItemNameEntry : public TObject {
public:
    TKeyBoardControl *keyboard;  // for the name
    TWindowMenu *prompt_menu;

    TObjItemNameEntry(TObject *parent);
    virtual ~TObjItemNameEntry();

    static TObjItemNameEntry *create(void *parent);
    static void set_entered_name(const char *name);
    s32 process_keyboard_input();
};

void handle_6x77_sync_quest_register(G_SyncQuestRegister_6x77 *cmd);
char *get_offline_quest_filename();
void load_area_dialogue_script();

// The name typed into the item-name entry window, read back by the quest VM.
extern char entered_item_name[0x10];

void clear_quest_floor_handlers(void);

struct ItemNameEntry { s32 text_id; s32 value; };

struct WindowPos { f32 x; f32 y; };

struct ByteBlock_100 { u8 bytes[0x100]; };

#endif
