#ifndef PSO_UI_FRONTEND_TADPLYSTATUSGC_H
#define PSO_UI_FRONTEND_TADPLYSTATUSGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGuideButtonGC.h"

class TWindowBase;
class CharacterPreview;

struct TAdPlyStatusGC : public TObject {
    TAdPlyStatusGC(TObject *parent, s32 window_offset_index);
    virtual ~TAdPlyStatusGC();
    virtual void render();
    virtual void run_task();
    s32 state; // indexes run_task's close/shown/hidden handler table
    s32 prev_state;
    GuideButtonSpec buttons[2];
    TWindowBase *window;
    void set_status_param(CharacterPreview *load_afs);
    static TAdPlyStatusGC *get_index();
    static void set_status_index(int a0, int a1);
    void close_window(s32 index);
    void close_window();
    void update_shown();
    void update_hidden();
    static TAdPlyStatusGC *get_instance(TObject *parent, s32 window_offset_index);
    static TAdGuideButtonGC *get_player_index(); // the guide button, or NULL
    void format_status_strings();
    void set_load_state(s32 arg1);
};

LAYOUT_ASSERT(TAdPlyStatusGC_size, sizeof(TAdPlyStatusGC) == 0x70);

extern "C" TAdPlyStatusGC *ply_status_gc_instance;
#endif
