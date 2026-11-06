#ifndef PSO_UI_TCHCRCHARSELECT_H
#define PSO_UI_TCHCRCHARSELECT_H

#include "pso/TObject.h"
#include "types.h"

class TChCrCharSelect : public TObject {
public:
    virtual ~TChCrCharSelect();
    virtual void run_task();
public:
    static void wrap_slot_index_to_range();
    static void clamp_slot_index_to_range();
    void handle_menu_input();
    static void init_widgets();
    static void *create(void *arg0);
    static void init_and_create();
    static void reset_proportions();
    static int get_selected_index();
    static int get_selected_char();
    static int get_instance();
public:
    void tick_and_apply_selection();
};

extern "C" {
void *__ct__15TChCrCharSelectFv(void *object, void *parent);
}

#endif
