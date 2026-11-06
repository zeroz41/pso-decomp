#ifndef PSO_UI_CHARCREATE_TOBJCMASSIGNMENU_H
#define PSO_UI_CHARCREATE_TOBJCMASSIGNMENU_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjCMAssignMenu : public TObject {
public:
    virtual ~TObjCMAssignMenu();
    void sub_80296648();
    virtual void render();
    virtual void run_task();
public:
    void draw_assign_icons();
    void render_assign_slots();
    void calc_grid_layout();
};

#endif
