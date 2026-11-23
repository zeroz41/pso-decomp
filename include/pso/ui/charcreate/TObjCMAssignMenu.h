#ifndef PSO_UI_CHARCREATE_TOBJCMASSIGNMENU_H
#define PSO_UI_CHARCREATE_TOBJCMASSIGNMENU_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

class TObjCMAssignMenu : public TObject {
public:
    TObjCMAssignMenu(TObject *parent, s32 kind);
    virtual ~TObjCMAssignMenu();
    void draw_assign_sprites();
    virtual void render();
    virtual void run_task();
public:
    void draw_assign_icons();
    void render_assign_slots();
    void calc_grid_layout();
public:
    static TObjCMAssignMenu *create(TObject *parent, s32 kind);

    CharacterAppearanceFields *appearance;
    s32 enabled;
    s32 kind;
    s32 value;
    s32 limit;
    s32 item_count;
    u32 item_mask;
    s32 ticks;
    s32 active;
    f32 fade;
    s32 columns;
    s32 page;
    s32 pages;
    s32 page_columns;
    s32 cursor;
    f32 scroll;
};
LAYOUT_ASSERT(TObjCMAssignMenu_size, sizeof(TObjCMAssignMenu) == 0x5C);

#endif
