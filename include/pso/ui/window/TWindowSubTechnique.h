#ifndef PSO_UI_WINDOW_TWINDOWSUBTECHNIQUE_H
#define PSO_UI_WINDOW_TWINDOWSUBTECHNIQUE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowMessage;

// Main-menu technique list: a category menu, the technique menu of the chosen
// category and a help window describing the technique under the cursor.
struct TWindowSubTechnique : public TObject {
    TWindowSubTechnique(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubTechnique();
    s32 category_changed(); // 1 when category_menu moved to another category
    u8 state;
    u8 pad_1d[0x1];
    s16 help_technique; // technique the help window shows; 0x13 = none
    s16 m_20;
    u8 pad_22[0x2];
    s32 m_24;
    s32 playerIndex;
    s32 current_category;
    TWindowMainMenu *parent_menu;
    TWindowMenu *category_menu;
    TWindowMenu *technique_menu;
    TWindowMessage *help_window;

    static const char *class_name;

    void rebuildTechniqueList(saddr list, s32 category);
    s32 open_menu();
    void update_selected_help(s32 arg1);
    virtual void render();
    virtual void run_task();
    void clear_flag70_bit80();
    static void get_selection(s16 *arg0, s32 *arg1, s32 client);
    static s32 update_selection(s16 *arg0, s32 *arg1, s32 client);
    static void get_current_selection(s16 *arg0, s32 *arg1, s32 client);
    static s32 lookup_technique(s32 arg0, s32 client);
    s32 create_title_window(s32 category);
    static s32 is_technique_available(s32 sub, s32 client);
    static void draw_technique_row(s32 id, s32 client, s32 list);
};

LAYOUT_ASSERT(TWindowSubTechnique_size, sizeof(TWindowSubTechnique) == 0x40);

extern "C" {
saddr get_technique_description_text(s32 arg0);
}

#endif
