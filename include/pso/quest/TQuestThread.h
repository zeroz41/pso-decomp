#ifndef PSO_QUEST_TQUESTTHREAD_H
#define PSO_QUEST_TQUESTTHREAD_H

#include "types.h"
#include "pso/TObject.h"
#include "pso/quest/QuestVm.h"

class TUnk_804C8678;

class TQuestThread : public TObject {
public:
    QuestVmContext ctx;
    quest_suspend_reason state;

    TQuestThread(TObject *root, s32 label);
    virtual void render();
    virtual ~TQuestThread();
    virtual void run_task();

    static TQuestThread *create(int label);
    static TQuestThread *create_in_root(s32 label);
    static TQuestThread *create_for_floor();
    static void set_floor_handler(s32 floor, s32 label);
    static void clear_floor_handler(s32 floor);
    static void clear_all_floor_handlers();
    static TUnk_804C8678 *create_by_mode();
    static void destroy_quest_obj();
    static void destroy_all_in(TObject *parent);
    static void clear_buffer(void *root);
    static void clear_thread_state();
    static char *get_quest_name();
    static s32 get_register(void *root, int index);
    static void queue_destruction(void *obj);
    static void set_status_flag_80(void *window);
};

class TQuestThreadBoard : public TObject {
public:
    QuestVmContext ctx;
    quest_suspend_reason state;

    TQuestThreadBoard(TObject *root, s32 label);
    virtual void render();
    virtual ~TQuestThreadBoard();
    virtual void run_task();

    static TQuestThreadBoard *create_instance(int label);
    static void destroy_board();
};

class TObjItemNameEntry : public TObject {
public:
    void *m_1c;
    void *m_20;

    TObjItemNameEntry(TObject *parent);
    virtual void render();
    virtual ~TObjItemNameEntry();

    static void *create(void *parent);
    static void set_entered_name(const char *name);
    s32 process_keyboard_input();
};

void handle_6x77_sync_quest_register(u8 *packet);
char *get_offline_quest_filename();
void load_area_dialogue_script();

extern "C" {
void free_menu_object(void *window);
}

#endif
