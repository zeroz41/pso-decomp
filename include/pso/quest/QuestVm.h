#ifndef PSO_QUEST_QUEST_VM_H
#define PSO_QUEST_QUEST_VM_H

#include "types.h"

enum quest_suspend_reason {
    QST_RUNNING                = 0,
    QST_SUSPEND_SYNC           = 1,  // yield until next frame
    QST_SUSPEND_RETURN         = 2,  // ret at call depth 0; the thread ends
    QST_SUSPEND_EXIT           = 3,  // the owning quest thread is destroyed
    QST_WAIT_MESSAGE           = 4,  // message window, A to advance
    QST_WAIT_MESSAGE_QB        = 5,  // secondary message window
    QST_SUSPEND_6              = 6,  // never set
    QST_WAIT_LIST              = 7,  // choice window, selection to a register
    QST_WAIT_FADE              = 8,
    QST_WAIT_ITEM_NAME_ENTRY   = 9,
    QST_WAIT_ITEM_NAME_SELECT  = 10,
    QST_WAIT_ITEM_OK           = 11,
    QST_WAIT_ITEM_CHOICE       = 12, // item id to a register, -1 on cancel
};

struct QuestVmContext {
    u8 *code;
    s32 *function_table;
    s32 *registers;
    void *message_window;
    void *list_window;
    u8 result_register;
    s32 unk18;
    s32 call_stack_depth;
    s32 pc;
    s32 unk24;
    s32 unk28;
    s32 message_speaker;
    s32 arg_count;
    s32 args[8];
    s32 call_stack[64];
    u8 unk154;
    u8 unk155;
    u16 unk156;
    u16 unk158;
    void *item_name_entry;
    void *item_name_select;
    void *item_ok_window;
    void *pack_select_window;
    void *pack_select_help_window;
    u16 statistic_arg1;
    u16 statistic_arg2;

    quest_suspend_reason dispatch();
    void copy(QuestVmContext *src);
    void save_globals();
    void load_globals();
};

extern "C" {
// The running thread's bytecode, and the bytecode offset of each label.
extern u8 *qst_code;
extern s32 *qst_function_table;
// Byte offset of the next instruction in qst_code.
extern s32 qst_pc;
extern s32 qst_call_stack[64];
extern s32 qst_call_stack_depth;
// r0-r255 / f0-f255 quest VM register table
extern s32 *qst_registers;
extern s32 qst_args[8];
extern s32 qst_arg_count;
extern quest_suspend_reason qst_suspend_reason;
// register a finished wait writes its result into
extern u8 qst_result_register;

extern void *qst_message_window;
extern void *qst_message_window_qb;
extern s32 qst_message_speaker;
extern void *qst_list_window;
extern void *qst_item_name_entry;
extern void *qst_item_name_select;
extern void *qst_item_ok_window;
extern void *qst_pack_select_window;
extern void *qst_pack_select_help_window;

extern u32 qst_flag_buf;
extern u16 qst_statistic_id;
extern u16 qst_statistic_arg1;
extern u16 qst_statistic_arg2;
}

#endif
