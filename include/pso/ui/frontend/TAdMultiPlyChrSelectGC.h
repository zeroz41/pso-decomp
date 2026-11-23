#ifndef PSO_UI_FRONTEND_TADMULTIPLYCHRSELECTGC_H
#define PSO_UI_FRONTEND_TADMULTIPLYCHRSELECTGC_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdChrSelASlotGC;
struct TAdChrSelBSlotGC;
class TAdSelectCurGC;
class TAdFadeGC;
class TAdGuideTxtGC;
class TAdGameStartGC;
struct TAdChrSelPlyPlateGC;
struct TAdChrMoveEffectGC;
class TAdFadeGC;

class TAdChrSelPlayerGC;
struct TWindowMenu;
struct TWindowMessageYesNo;

struct TAdMultiPlyChrSelectGC : public TObject {
    struct SlotGridPosition {
        s32 card_slot;
        s32 cursor_column;
    };
    TAdMultiPlyChrSelectGC(TObject *, s32);
    virtual ~TAdMultiPlyChrSelectGC();
    static TAdChrSelPlayerGC *get_or_create_player(TObject *parent, s32 mode, s32 index, s32 slot);
    void create_widgets();
    void sub_802DC118(s32);
    virtual void render();
    s32 state_frames;   // 0x1C  frames in the current state; run_task zeroes it on a state change
    s32 state;          // 0x20  index into run_task's state handler table
    s32 prev_state;     // 0x24  state before this frame's handler ran
    s32 next_state;     // 0x28  state update_idle_timer moves to once the wait ends
    s32 exit_action;    // 0x2C  what sub_802DCCA4 does on leaving (0 opening movie, 1 start, 2 none)
    s32 last_card_slot; // 0x30  player_plate's active card slot when last checked
    s32 last_cursor;    // 0x34  player_plate's cursor when last checked
    s32 swap_slot;      // 0x38  slot passed to swap_characters (swap_search + 4)
    s32 controllers_ready; // 0x3C  run_task: port 0 connected and at least two players ready
    s32 show_flag_notice;  // 0x40  the slot under the cursor has data flag 1 set (guide lines 0xD/0xE)
    s32 guide_state;    // 0x44  which guide line is shown (0, 1, 2 = ready)
    s32 mode;           // 0x48  constructor mode; switch in handle_event and sub_802DCD14
    s32 cursor;         // 0x4C  get_clamped_cursor() of this frame
    s32 move_requested; // 0x50  "move" was chosen from the choice menu; update_select starts the move
    s32 move_finished;  // 0x54  cleared while a move is pending or found no free slot
    s32 swap_search;    // 0x58  first extra slot (0..2) the swap search starts from
    TAdChrSelPlyPlateGC *player_plate;
    TAdChrSelPlayerGC *player_preview;
    TAdGuideTxtGC *guide;
    void handle_event(s32 select_flag);
    void initialize_selection_state(s32 mode);
    static TAdChrSelPlyPlateGC *get_card_instance();
    static void reset_slot_selection_table();
    static void split_slot_index(s32 slot_index, s32 *out_cursor_column, s32 *out_card_slot);
    static void init();
    static s32 get_status();
    static s32 is_selection_confirmed();
    static s32 count_ready();
    static void remove_selected_slot(s32 slot);
    static void add_selected_slot();
    static s32 get_clamped_cursor();
    static void reset_slot_selections();
    static s32 count_selected_slots();
    static s32 get_multiplayer_character_slot(s32 slot);
    static void deselect_slot(s32 slot);
    static s32 is_controller_connected(s32 port);
    static saddr get_last_selected_player();
    s32 get_field_20();
    static TAdMultiPlyChrSelectGC *get_state();
    static TAdMultiPlyChrSelectGC *get_or_create(TObject *parent, s32 mode);
    static saddr get_selected_slot();
    static int get_global_6700();
    static void render(void *self);
    TWindowMessageYesNo *create_confirm_window(s32 slot);
    TWindowMenu *create_choice_menu();
    void collect_player_slots();
    s32 get_state_result();
    static u8 *format_player_number_text(s32 arg0, s32 arg1);
    void request_scene_change();
    void check_cancel_input();
    void handle_input();
    void update_input_state();
    void close_and_reset();
    void update_idle_timer();
    void update_confirm_start();
    void handle_cancel_state();
    void update_state_move();
    void handle_confirm_state();
    void update_state();
    void update_card_select_state();
    void update_state_wait_card();
    void update_select();
    void reset_to_select();
    void update_button_input();
    void update_state_serial();
    void sub_802DEDA8();
    void sub_802DE7D0();
    void update();
    void sub_802DDD08();
    void sub_802DDBA8();
    void sub_802DD400();
    void sub_802DD2B0();
    void sub_802DD010();
    void sub_802DCF68();
    void sub_802DCD14();
    void sub_802DCCA4();
    void sub_802DCA20();
    void sub_802DC8A0();
    void sub_802DC5CC();
    void sub_802DC440();
    void sub_802DC310();
    s32 sub_802DC294(s32 arg1);
    TWindowMenu *sub_802DBEC4(s32 *desc);
    TWindowMenu *sub_802DBE4C(s32 *desc);
    TWindowMessageYesNo *sub_802DBD64();
    TWindowMessageYesNo *sub_802DBCE8();
    virtual void run_task();
    static TAdChrMoveEffectGC *get_global_state();
    static int get_select_flag();
    static int get_chr_select_state();
    s32 get_ready_state();
    static TAdChrMoveEffectGC *get_move_effect(saddr ad_chr_move_effect_gc);
    static TAdChrSelASlotGC *get_or_create_slot_window(TObject *parent, s32 mode);
    TAdChrSelASlotGC *a_slot;        // 0x68  get_or_create_slot_window
    TAdChrSelBSlotGC *b_slot;        // 0x6C  TAdChrSelBSlotGC::create
    TAdSelectCurGC *select_cursor;   // 0x70
    TAdFadeGC *fade_task;
    TAdGameStartGC *game_start;
    TWindowMenu *choice_menu;                      // 0x7C  create_choice_menu (4 entries)
    TWindowMenu *moving_notice;                    // 0x80  sub_802DBEC4, shown while a character moves
    TWindowMenu *full_notice;                      // 0x84  sub_802DBE4C, shown when no free slot was found
    TWindowMessageYesNo *confirm_window;           // 0x88  create_confirm_window
    TWindowMessageYesNo *yes_no_prompt;            // 0x8C  a_slot->open_yes_no_window for a transferred character
    TWindowMessageYesNo *create_character_prompt;  // 0x90  a_slot->open_create_character_prompt
    TWindowMessageYesNo *yes_no_dialog;            // 0x94  sub_802DBD64, swap search prompt
    TWindowMessageYesNo *delete_prompt;            // 0x98  sub_802DBCE8, choice menu entry 2
    s32 resumed;                                   // 0x9C  set by handle_event when returning to the scene
    static s32 dispatch_draw_command(saddr input, s32 buttons, s32 delay, s32 period);
    void open_windows();
    void init_windows();
    void open_char_select();
    void close_windows();
    void update_card_select();
    void update_state_option();
    void update_card_confirm();
};

extern "C" TAdMultiPlyChrSelectGC *TAdMultiPlyChrSelectGC__instance;

LAYOUT_ASSERT(TAdMultiPlyChrSelectGC_size, sizeof(TAdMultiPlyChrSelectGC) == 0xA0);
LAYOUT_ASSERT(TAdMultiPlyChrSelectGC_player_preview_offset, offsetof(TAdMultiPlyChrSelectGC, player_preview) == 0x60);
LAYOUT_ASSERT(TAdMultiPlyChrSelectGC_unk_68_offset, offsetof(TAdMultiPlyChrSelectGC, a_slot) == 0x68);
LAYOUT_ASSERT(TAdMultiPlyChrSelectGC_m_6c_offset, offsetof(TAdMultiPlyChrSelectGC, b_slot) == 0x6C);

// TAdMultiPlyChrSelectGC__character_slot_positions: layout known from its uses only.
struct TAdMultiPlyChrSelectGCCharacterSlotPositions { s32 value; u8 remaining[0x1C]; };
extern TAdMultiPlyChrSelectGCCharacterSlotPositions TAdMultiPlyChrSelectGC__character_slot_positions;

#endif
