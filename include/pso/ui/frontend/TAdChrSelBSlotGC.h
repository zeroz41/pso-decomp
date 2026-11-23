#ifndef PSO_UI_FRONTEND_TADCHRSELBSLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELBSLOTGC_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSubPlyItemGC;
class TAdChrSelSlotGC;
class TAdChrSelMovePlateGC;
class TAdPlyChrSelPlateGC;
class TAdChrSelSlotGC;
class TAdChrSelASlotGC;
class TAdDrawLineCtrl;
class TWindowBase;
struct TWindowMessageYesNo;
struct PlayerSlotLabel;

struct TAdChrSelBSlotGC : public TObject {
    TAdChrSelBSlotGC(TObject *parent);
    virtual ~TAdChrSelBSlotGC();
    void clear_all_fields();
    virtual void render();
    virtual void run_task();
    // state, prev_state, state_frames: names inferred from run_task (same layout as TAdChrSelASlotGC)
    s32 state;        // 0x1C
    s32 prev_state;   // 0x20
    s32 state_frames; // 0x24
    void create_children();
    static void render(void *self);
    s32 is_character_transferred(u32 i);
    PlayerSlotLabel *build_slot_entry(s32 index, s32 slot, void *pos);
    void sub_8030E458();
    void set_load_state();
    void init();
    void reset_load_state();
    void reset_slot_state();
    void sub_8030E550();
    void update_load_state();
    void set_state_confirm();
    void set_state(s32 value);
    s32 get_state();
    s32 is_state_closing();
    void enter_state17();
    void sub_8030E620();
    void populate_slot_entries();
    void reset_plate_positions();
    void show_pso12_character_message();
    void show_character_data_corrupt_message();
    void show_no_system_file_message();
    void show_system_file_corrupt_message();
    void show_no_character_data_message();
    void show_character_file_corrupt_message();
    void wait_format_failed_dismiss();
    void check_cancel_and_close();
    void update_slot_state();
    void update_card_select();
    void show_not_formatted_message();
    void update_card_confirm();
    void show_format_prompt();
    void show_card_damaged_message();
    void show_card_incompatible_message();
    void show_unsupported_device_message();
    void close_windows();
    void reset_windows();
    static TAdChrSelBSlotGC *create(void *arg0);
    int get_global_state();
    static TAdChrSelASlotGC *get_global_slot_data();
    TAdChrSelSlotGC *slot_gc; // 0x28
    TAdPlyChrSelPlateGC *plate;                   // 0x2C
    TAdSubPlyItemGC *player_items;
    TAdChrSelMovePlateGC *move_plate;             // 0x34
    TAdDrawLineCtrl *draw_line[2];                // 0x38
    TWindowBase *wait_message[11];                // 0x40  message i shows text 2 * i + 1 while the card load waits on step i
    TWindowMessageYesNo *format_prompt;           // 0x6C  show_format_prompt
    TWindowMessageYesNo *format_confirm;          // 0x70  opened when format_prompt is accepted
    TWindowBase *formatted_message;               // 0x74
    TWindowBase *not_formatted_message;           // 0x78
    TWindowBase *format_failed_message;           // 0x7C
};

LAYOUT_ASSERT(TAdChrSelBSlotGC_size, sizeof(TAdChrSelBSlotGC) == 0x80);
LAYOUT_ASSERT(TAdChrSelBSlotGC_state_offset, offsetof(TAdChrSelBSlotGC, state) == 0x1C);
LAYOUT_ASSERT(TAdChrSelBSlotGC_wait_message_offset, offsetof(TAdChrSelBSlotGC, wait_message) == 0x40);
#endif
