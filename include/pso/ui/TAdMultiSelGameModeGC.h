#ifndef PSO_UI_TADMULTISELGAMEMODEGC_H
#define PSO_UI_TADMULTISELGAMEMODEGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdMultiSelGameModeGC : public TObject {
public:
    virtual ~TAdMultiSelGameModeGC();
    virtual void run_task();
public:
    virtual void render();
    static s32 is_mode_entry_enabled(void *self, s32 mode, u32 idx);
    s32 build_mode_menu(s32 arg1);
    void exit_keyboard_mode();
    void update_transition_state();
    void sub_803003A4();
    void sub_80300648();
    void sub_80300764();
    void set_selection_state(s32 v);
};

s32 get_max_difficulty_for_party_level(void);

#endif
