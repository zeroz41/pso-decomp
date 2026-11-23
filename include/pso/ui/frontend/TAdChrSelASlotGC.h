#ifndef PSO_UI_FRONTEND_TADCHRSELASLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELASLOTGC_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSubPlyItemGC;
class TAdChrSelMovePlateGC;
class TAdPlyChrSelPlateGC;
class TAdChrSelSlotGC;
class TAdDrawLineCtrl;
class TAdPlayerLoadGC;
class TWindowBase;
struct TWindowMessageYesNo;
struct PlayerSlotLabel;

struct TAdChrSelASlotGC : public TObject {
    TAdChrSelASlotGC(TObject *parent, s32 mode);
    virtual ~TAdChrSelASlotGC();
    virtual void render();
    virtual void run_task();
    s32 state_frames;
    s32 mode;
    s32 state;
    s32 prev_state;
    TAdChrSelSlotGC *slot_gc; // 0x2C
    TAdPlayerLoadGC *player_load;
    static void render(void *self);
    s32 is_character_transferred(u32 i);
    s32 get_plate_value_for_slot(s32 k);
    PlayerSlotLabel *build_slot_entry(s32 index, s32 slot, void *pos);
    TWindowBase *create_format_failed_window(s32 kind);
    TWindowBase *create_not_formatted_window(s32 kind);
    TWindowBase *create_formatted_window(s32 kind);
    TWindowMessageYesNo *open_confirm_message(s32 kind, s32 client_id);
    TWindowMessageYesNo *create_message_window(s32 kind, s32 client_id);
    TWindowMessageYesNo *create_format_message_window(s32 pos, s32 client_id);
    TWindowMessageYesNo *open_replace_character_prompt(s32 pos, s32 client_id);
    TWindowMessageYesNo *open_yes_no_window(s32 pos, s32 client_id);
    TWindowMessageYesNo *open_create_character_prompt(s32 pos);
    TWindowBase *create_slot_message_window(s32 kind, s32 text);
    void sub_8030CBD0();
    void sub_8030CBD4();
    void update_load_state();
    void set_state();
    s32 get_state();
    void set_state(s32 value);
    void check_load_state();
    void init_selection();
    void sub_8030CCE0();
    void populate_slot_entries();
    void push_plate_positions();
    void update_window_78();
    void update_window_7c();
    void update_window_74();
    void update_window_70();
    void update_window_6c();
    void update_slot5();
    void update_slot4();
    void update_slot3();
    void update_slot2();
    void update_slot1();
    void show_no_card_message();
    void close_windows();
    void create_children(s32 arg1);
    void init(s32 arg1);
    void forward_slot_selection(void* a1, void* a2);
    TAdPlyChrSelPlateGC *plate_a;          // 0x34  slot A plate (modes 0 and 1)
    TAdPlyChrSelPlateGC *plate_b;          // 0x38  slot B plate (modes 1 and 2)
    TAdSubPlyItemGC *player_items;
    TAdSubPlyItemGC *player_items_b;       // 0x40
    TAdChrSelMovePlateGC *move_plate;      // 0x44
    TAdDrawLineCtrl *draw_line[3];         // 0x48
    TWindowBase *wait_message[11];         // 0x54  message i shows text 2 * i while the card load waits on step i
};

LAYOUT_ASSERT(TAdChrSelASlotGC_size, sizeof(TAdChrSelASlotGC) == 0x80);
LAYOUT_ASSERT(TAdChrSelASlotGC_state_offset, offsetof(TAdChrSelASlotGC, state) == 0x24);
LAYOUT_ASSERT(TAdChrSelASlotGC_wait_message_offset, offsetof(TAdChrSelASlotGC, wait_message) == 0x54);
#endif
