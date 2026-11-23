#ifndef PSO_UI_FRONTEND_TADMULTISELGAMEMODEGC_H
#define PSO_UI_FRONTEND_TADMULTISELGAMEMODEGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TWindowMenu;
class TAdSelectTxtGC;
class TAdSelectCurGC;
class TAdGuideTxtGC;

class TAdMultiSelGameModeGC : public TObject {
public:
    TAdMultiSelGameModeGC(TObject *parent, s32 mode);
    virtual ~TAdMultiSelGameModeGC();
    virtual void run_task();
public:
    virtual void render();
    s32 is_mode_entry_enabled(s32 menu, u32 idx);
    s32 get_max_difficulty_for_party_level();
    saddr build_mode_menu(s32 menu);
    void exit_keyboard_mode();
    void update_transition_state();
    void sub_803003A4();
    void sub_80300648();
    void sub_80300764();

    s32 state;                        // 0x1C: run_task's step: 0 start, 1 cursor, 2 menu open, 3 leave, 4 exit
    s32 mode;                         // 0x20: the ctor's mode; update_transition_state picks the next scene by it
    s32 selection;                    // 0x24: the cursor's line this frame
    s32 prev_selection;               // 0x28: last frame's; the guide text follows a change
    TWindowMenu *menu;                // 0x2C: the open option menu (build_mode_menu)
    TAdSelectTxtGC *difficulty_text;  // 0x30: shows game_difficulty_selection
    TAdSelectTxtGC *rule_text;        // 0x34: shows TAdMultiSelGameModeGC__data_805D69F0
    TAdSelectTxtGC *episode_text;     // 0x38: shows lbl_805D69F4, the episode handed to TAdStorySelectGC::set_state
    TAdSelectCurGC *cursor;           // 0x3C
    TAdGuideTxtGC *guide;             // 0x40
};

LAYOUT_ASSERT(TAdMultiSelGameModeGC_size, sizeof(TAdMultiSelGameModeGC) == 0x44);

#endif
