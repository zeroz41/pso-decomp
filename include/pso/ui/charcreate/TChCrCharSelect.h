#ifndef PSO_UI_CHARCREATE_TCHCRCHARSELECT_H
#define PSO_UI_CHARCREATE_TCHCRCHARSELECT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrCharSelect : public TObject {
public:
    TChCrCharSelect(TObject *parent);
    virtual ~TChCrCharSelect();
    virtual void run_task();
public:
    void wrap_slot_index_to_range();
    void clamp_slot_index_to_range();
    void handle_cursor_input();
    void handle_menu_input();
    void init_widgets();
    static void *create(void *arg0);
    static void init_and_create();
    static void reset_proportions();
    static int get_selected_index();
    static int get_selected_char();
    static int get_instance();
public:
    void tick_and_apply_selection();

    s32 apply_delay;
};

typedef char TChCrCharSelect_size[sizeof(TChCrCharSelect) == 0x20 ? 1 : -1];

#endif
