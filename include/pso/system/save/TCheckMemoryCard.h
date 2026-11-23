#ifndef PSO_SYSTEM_SAVE_TCHECKMEMORYCARD_H
#define PSO_SYSTEM_SAVE_TCHECKMEMORYCARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMenu;
struct TWindowMessage;

// Task that keeps checking the memory card in slot A and shows a message window while a check fails.
struct TCheckMemoryCard : public TObject {
    TCheckMemoryCard(TObject *parent, void *arg2, s32 main_ctrl, s32 system_only);
    virtual ~TCheckMemoryCard();
    virtual void render();
    virtual void run_task();

    static TCheckMemoryCard *create_system_file_check(TObject *parent, void *arg2, s32 main_ctrl);
    static TCheckMemoryCard *create(TObject *parent, void *arg2, s32 main_ctrl);

    s32 prompt_was_accepted();
    void enable_prompt();
    void select_main_window_controller();
    s32 is_card_ready();
    static s32 has_no_save_files(s32 chan);
    static s32 has_no_system_file(s32 chan);

    s32 check_player_data();
    s32 check_card();
    void update_card_display(s32 kind, s32 sel, s32 sub_entry, s32 alt_sub_entry);
    void recreate_message_and_menu(u32 text, s32 sel, u32 first_entry, u32 second_entry);
    void create_card_message(s32 kind, s32 sel, s32 sub_entry, s32 alt_sub_entry);
    void create_message_and_menu(u32 text, s32 sel, u32 first_entry, u32 second_entry);
    void close_windows();
    void set_state(s32 new_state);
    void reset();
    void poll_card_status();
    void enter_poll_state();
    void run_message_state();
    void enter_message_state();
    void handle_menu_selection();
    void enter_prompt_state();
    void update_display_state();
    void close_and_update_display();

    s32 system_file_only;            // 0x1C: check_card() looks for the system file only, not for all three save files
    s32 state;                       // 0x20: index into the state table
    s32 busy_count;                  // 0x24: consecutive check_card() calls that found the card busy
    s32 status;                      // 0x28: check_card() result bits; 0 when every check passed
    s32 status_checked;              // 0x2C: the save files of the inserted card were already checked
    TWindowMessage *message_window;  // 0x30
    TWindowMenu *menu_window;        // 0x34
    s32 close_wait;                  // 0x38: set to 7 when a window closes, counted down by run_task
    s32 card_ready;                  // 0x3C: 1 while the poll state sees a card that passes every check
    s32 prompt;                      // 0x40: failed checks go to the menu state instead of the message state
    s32 prompt_accepted;             // 0x44: menu entry 0 was chosen
    void *unk_48;                    // 0x48: second constructor argument, only stored
    s32 use_main_ctrl;               // 0x4C: windows are created under the main window control
    u8 pad_50[0x200];
};

LAYOUT_ASSERT(TCheckMemoryCard_size, sizeof(TCheckMemoryCard) == 0x250);

#include <stddef.h>
LAYOUT_ASSERT(TCheckMemoryCard_system_file_only_offset, offsetof(TCheckMemoryCard, system_file_only) == 0x1C);
LAYOUT_ASSERT(TCheckMemoryCard_state_offset, offsetof(TCheckMemoryCard, state) == 0x20);
LAYOUT_ASSERT(TCheckMemoryCard_busy_count_offset, offsetof(TCheckMemoryCard, busy_count) == 0x24);
LAYOUT_ASSERT(TCheckMemoryCard_status_offset, offsetof(TCheckMemoryCard, status) == 0x28);
LAYOUT_ASSERT(TCheckMemoryCard_status_checked_offset, offsetof(TCheckMemoryCard, status_checked) == 0x2C);
LAYOUT_ASSERT(TCheckMemoryCard_message_window_offset, offsetof(TCheckMemoryCard, message_window) == 0x30);
LAYOUT_ASSERT(TCheckMemoryCard_menu_window_offset, offsetof(TCheckMemoryCard, menu_window) == 0x34);
LAYOUT_ASSERT(TCheckMemoryCard_close_wait_offset, offsetof(TCheckMemoryCard, close_wait) == 0x38);
LAYOUT_ASSERT(TCheckMemoryCard_card_ready_offset, offsetof(TCheckMemoryCard, card_ready) == 0x3C);
LAYOUT_ASSERT(TCheckMemoryCard_prompt_offset, offsetof(TCheckMemoryCard, prompt) == 0x40);
LAYOUT_ASSERT(TCheckMemoryCard_prompt_accepted_offset, offsetof(TCheckMemoryCard, prompt_accepted) == 0x44);
LAYOUT_ASSERT(TCheckMemoryCard_unk_48_offset, offsetof(TCheckMemoryCard, unk_48) == 0x48);
LAYOUT_ASSERT(TCheckMemoryCard_use_main_ctrl_offset, offsetof(TCheckMemoryCard, use_main_ctrl) == 0x4C);

#endif
